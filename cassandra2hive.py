import os
import sys
from pyspark.shell import spark
from pyspark.sql import SparkSession
from pyspark import SparkConf
from os.path import abspath 
from datetime import datetime

# initializing pyspark for cassandra
os.environ['PYSPARK_DRIVER_PYTHON'] = sys.executable
os.environ['PYSPARK_PYTHON'] = sys.executable
spark = SparkSession.builder.getOrCreate()
warehouse_location = abspath('spark-warehouse')

# initializing pyspark for hive
hive_conf = SparkConf()
hive_conf.set("spark.jars", "C:\hadoop-env\db-derby-10.14.2.0\lib\derbyclient.jar")

# making definitions for getting cctv counts per minute and hour
def extractHours(hours):
    return hours[:2]

def extractMinutes(mins):
    return mins[3:5]

def toDate(col):
    return datetime.strptime(col, '%m/%d/%Y')

# reading cassandra table using pyspark and getting the dataframe
df_cass = spark.read \
    .format("org.apache.spark.sql.cassandra") \
    .options(table="group23_project_table", keyspace="group23_project") \
    .load()

# changing the dataframe using pandas
df_pandas = df_cass.toPandas()
df_pandas['date_saved'] = df_pandas["date_saved"].apply(toDate)
df_minhours = df_pandas[["date_saved", "time_saved", "bike", "bus", "car", "jeepney", "others", "truck", "tryke", "total"]]
df_minhours['hour'] = df_minhours['time_saved'].apply(extractHours)
df_minhours['min'] = df_minhours['time_saved'].apply(extractMinutes)

# combine the columns, hours, and mins
df_combine = df_minhours.groupby(['date_saved', 'hour', 'min']).agg(
    total=('total', sum),
    bike_total=('bike', sum),
    bus_total=("bus", sum),
    car_total=("car", sum),
    jeepney_total=("jeepney", sum),
    others_total=("others", sum),
    truck_total=("truck", sum),
    tryke_total=("tryke", sum)
).reset_index()
df_counts = spark.createDataFrame(df_combine)
df_counts.printSchema()

# saving the dataframe into a table in hive
df_counts.write.mode("overwrite").saveAsTable("solepito_counts.sumry")
df_cass.write.mode("overwrite").saveAsTable("solepito_counts.cass")
