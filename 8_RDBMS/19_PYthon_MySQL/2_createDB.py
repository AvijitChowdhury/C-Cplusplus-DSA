import mysql.connector

mydbconnection = mysql.connector.connect(
    
    user = 'root',
    password = '1903045',
    host='127.0.0.1',
    auth_plugin='mysql_native_password'
)

dbname = 'python_test_db'
mycursor = mydbconnection.cursor()

sqlquery = "CREATE DATABASE " + dbname

mycursor.execute(sqlquery)