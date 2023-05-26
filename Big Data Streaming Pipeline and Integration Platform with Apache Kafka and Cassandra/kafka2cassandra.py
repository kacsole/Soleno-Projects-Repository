from __future__ import print_function
from kafka import KafkaConsumer # access Kafka
from cassandra.cluster import Cluster # access Cassandra

consumer = KafkaConsumer(
    'counts', # topic in Kakfa
    bootstrap_servers = ['127.0.0.1:9092'],
    auto_offset_reset = 'latest',
    enable_auto_commit = True
)

cluster = Cluster(['127.0.0.1'], port = 9042)
session = cluster.connect('group23_project') # keyspace/group

columns = ['timeuuid_id', 'lgu_code', 'sensor_id', 'date_saved', 'time_saved', 'total', 'car', 'bus', 'truck', 'jeepney', 'bike', 'tryke', 'others']

# start the loop
for message in consumer:
    # separate each values
    message = message.value
    message = message.replace("{", "")
    message = message.replace("}", "")
    message = message.replace('"', "")
    message = message.split(", ")

    timeuuid_id = message[6].split(': ')[1]
    lgu_code = message[5].split(': ')[1]
    sensor_id = message[0].split(': ')[1]
    date_saved = message[11].split(': ')[1]
    time_saved = message[1].split(': ')[1]
    total = message[12].split(': ')[1]
    car = message[2].split(': ')[1]
    bus = message[10].split(': ')[1]
    truck = message[8].split(': ')[1]
    jeepney = message[4].split(': ')[1]
    bike = message[7].split(': ')[1]
    tryke = message[9].split(': ')[1]
    others = message[3].split(': ')[1]

    # Inserting the values into the Cassandra table
    session.execute("INSERT INTO group23_project_table(timeuuid_id, lgu_code, sensor_id, date_saved, time_saved, total, car, bus, truck, jeepney, bike, tryke, others) VALUES('{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}');".format(timeuuid_id, lgu_code, sensor_id, date_saved, time_saved, total, car, bus, truck, jeepney, bike, tryke, others))

    # Data has been inserted into the table
    print('Inserted...')