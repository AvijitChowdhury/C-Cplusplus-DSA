import mysql.connector

dbname = 'python_test_db'
mydbconnection = mysql.connector.connect(
    
    user = 'root',
    password = '1903045',
    host='127.0.0.1',
    database = dbname,
    auth_plugin='mysql_native_password'
)

mycursor = mydbconnection.cursor()

sqlquery = """
CREATE TABLE Student
(
    Roll VARCHAR(10) primary key,
    Name VARCHAR(30));
"""
mycursor.execute(sqlquery)