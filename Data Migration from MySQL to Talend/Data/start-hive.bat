call C:\hadoop-env\hadoop-3.3.0\sbin\start-dfs.cmd
call C:\hadoop-env\hadoop-3.3.0\sbin\start-yarn.cmd
echo Wait until dfs and yarn are done before continuing
pause
start C:\hadoop-env\db-derby-10.14.2.0\bin\StartNetworkServer -h 0.0.0.0
echo Wait until Derby is done before continuing
pause
echo Wait until hive is done then open cygwin
start C:\hadoop-env\apache-hive-3.1.2\bin\hive
echo These are the commands to copy paste in cygwin:
echo export HADOOP_HOME='/cygdrive/c/hadoop-env/hadoop-3.3.0'
echo export PATH=$PATH:$HADOOP_HOME/bin
echo export HIVE_HOME='/cygdrive/c/hadoop-env/apache-hive-3.1.2'
echo export PATH=$PATH:$HIVE_HOME/bin
echo export HADOOP_CLASSPATH=$HADOOP_CLASSPATH:$HIVE_HOME/lib/*.jar
echo $HIVE_HOME/bin/schematool -dbType derby -initSchema
pause
echo $HIVE_HOME/bin/hive --service hiveserver2 start
pause
echo $HIVE_HOME/bin/beeline -u jdbc:hive2://
pause