""" A replica system so that an user and an admin can do the above tasks.           
    """
import random
from User import User
from Admin import Admin
from Bank import BankManagement, Account

#creating user object

ReplicaBank = BankManagement('Replica Bank')
User1 = User('User1', 'Avijit Chowdhury', 'abhichy30@gmail.com','South California, USA', 'Savings')
Admin_1 = Admin('Admin1', 'Avijit Chowdhury', 'abhichy30@gmail.com','South California, USA')
#Enabling all feature that are available in the bank that users and admins can do
print('Welcome to Replica Bank')
print('1. Create Account')
print('2. Delete Account')
print('3. See all user accounts')
print('4. Check total balance')
print('5. Check total loan')
print('6. On/Off loan feature')
print('7. Checking transection history')
print('8. Exit')
while True:
    choice = int(input('Enter your choice: '))
    if choice == 1:
        name = input('Enter your name: ')
        email = input('Enter your email: ')
        address = input('Enter your address: ')
        account_type = input('Enter your account type: ')
        Admin_1.create_account(ReplicaBank, name, email, address, account_type)
    elif choice == 2:
        user = input('Enter the name of the user: ')
        for user in ReplicaBank.users:
            if user.name == user:
                Admin_1.delete_account(ReplicaBank, user)
    elif choice == 3:
        Admin_1.see_all_user_accounts(ReplicaBank)
    elif choice == 4:
        Admin_1.check_total_balance(ReplicaBank)
    elif choice == 5:
        Admin_1.check_total_loan(ReplicaBank)
    elif choice == 6:
        Admin_1.on_off_loan_feature(ReplicaBank)
    elif choice == 7:
        Admin_1.check_transection_history(User1)
    elif choice == 8:
        break
    else:
        print('Invalid choice')

