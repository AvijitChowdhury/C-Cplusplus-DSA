import mysql.connector

mydb = mysql.connector.connect(
    
    user = 'root',
    password = '1903045',
    host='127.0.0.1',
    auth_plugin='mysql_native_password'
)
print(mydb)