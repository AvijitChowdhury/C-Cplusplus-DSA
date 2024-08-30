"""
Create a banking management system where-

User⇒                                                                                          
Can create an account with his/her name, email, address and account Type(Mainly Two Types: Savings & Cuurent).	    
Initially, the balance will be 0. An account number will be generated automatically. 									  
Can deposit and withdraw amount. If the withdrawal amount is more than the current balance, show an error message that “Withdrawal amount exceeded” 										    10
Can check available balance.                                                                  
Can check transaction history.                                                                  
Can take a loan from the bank at most two times.                                   
Can transfer the amount from his account to another user account. if the other account does not exist then show an error message “Account does not exist”.                                                                                                10
Note - User can only withdraw and transfer money from his account if he has money in his account.
If a user is unable to withdraw the amount of money he has deposited in the bank, he will get a message that the bank is bankrupt.

Admin⇒                                                                                                                              
Can create an account                                                                  
Can delete any user account                                                           
Can see all user accounts list                                                     
Can check the total available balance of the bank.                          
Can check the total loan amount.                                                   
Can on or off the loan feature of the bank.                                 

Now make a replica system so that an user and an admin can do the above tasks.    
"""
import random
from User import User
class BankManagement:
    def __init__(self, name) -> None:
        self.name = name
        self.accounts = {}
        self.users = []
        self.admins = []
        self.total_balance = 0
        self.total_loan = 0
        self.loan_feature = False
    def add_User(self, user):
        self.users.append(user)
    def add_Admin(self, admin):
        self.admins.append(admin)
    def generate_account_number(self):
        return random.randint(100000,999999) 
    def create_account(self, name, email, address, account_type, admin=False):
        account = Account(name, email, address, account_type)
        account_number = self.generate_account_number()
        self.accounts.append(account)
        #adding user object to the user dictionary
        for user in self.users:
            if user.name == name:
                user.account_number = account_number
                user.account = account
        print(f'Account created successfully. Account Number: {account_number}')
    def delete_account(self,user, admin=False):
        if not admin:
            print('You are not authorized to perform this operation')
            return
        account_number = user.account_number
        for account in self.accounts:
            if account.account_number == account_number:
                self.accounts.remove(account)
        for user in self.users:
            if user.account_number == account_number:
                self.users.remove(user)
        print('Account deleted successfully')
    def transfer_amount(self, amount, senderAcc,receiverAcc):
        senderAccNum = senderAcc
        receiverAccNum = receiverAcc 
        if not receiverAccNum:
            print('Account does not exist')
            return
        if senderAcc.balance < amount:
            print('Insufficient balance')
            return
        senderAcc.balance -= amount
        #updating transection history
        for account in self.accounts.values():
            if account.account_number == senderAccNum:
                account.transaction_history.append(f'{amount} transfered to {receiverAcc.name}')
        receiverAcc.balance += amount
        for account in self.accounts.values():
            if account.account_number == receiverAccNum:
                account.transaction_history.append(f'{amount} received from {senderAcc.name}')
        self.total_balance += amount
        print('Amount transfered successfully')
    def deposit_amount(self, userAcc, amount):
        account = userAcc
        account.balance += amount
        account.transaction_history.append(f'{amount} deposited')
        self.total_balance += amount
        print('Amount deposited successfully')
    def withdraw_amount(self, userAcc, amount):
        account = userAcc
        if account.balance < amount:
            print('Withdrawal amount exceeded')
            return
        account.balance -= amount
        self.total_balance -= amount
        account.transection_history.append(f'{amount} withdrawn')
        print('Amount withdrawn successfully')
    def take_loan(self, userAcc, amount):
        account = userAcc
        if account.loan_count >= 2:
            print('You can not take more loan')
            return
        else: 
            account.loan += amount
            account.loan_count += 1
            self.total_loan += amount
            print('Loan taken successfully')
    
    def check_total_balance(self):
        return self.total_balance
    def check_total_loan(self):
        return self.total_loan
    def on_off_loan_feature(self,admin):
        if not admin:
            print('You are not authorized to perform this operation')
            return
        self.loan_feature = not self.loan_feature
        print(f'Loan feature is {"on" if self.loan_feature else "off"}')
    
    def check_transection_history(self,user):
        print(user.account.transection_history)    
        
class Account:
    def __init__(self,name , email, address, account_type) ->None:
        self.name = name
        self.email = email
        self.address = address
        self.account_type = account_type
        self.balance = 0
        self.account_number = self.generate_account_number()
        self.transaction_history = []
        self.loan = 0
        self.loan_count = 0
    def generate_account_number(self):
        return random.randint(100000,999999) 