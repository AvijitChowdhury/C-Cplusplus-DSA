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
    UPDATE Student
    SET Name = 'Avijit'
    WHERE Name = 'Falcon'
"""
mycursor.execute(sqlquery)
mydbconnection.commit()

sqlquery1 = "select * from Student"
mycursor.execute(sqlquery1)
result = mycursor.fetchall()
for i in result:
    print(i)
# Output: ('1', 'Falcon')