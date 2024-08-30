"""Can create an account with his/her name, email, address and account Type(Mainly Two Types: Savings & Cuurent).	    5
Initially, the balance will be 0. An account number will be generated automatically. 									    5
Can deposit and withdraw amount. If the withdrawal amount is more than the current balance, show an error message that “Withdrawal amount exceeded” 										    10
Can check available balance.                                                                   3
Can check transaction history.                                                                  3
Can take a loan from the bank at most two times.                                    4
Can transfer the amount from his account to another user account. if the other account does not exist then show an error message “Account does not exist”.
    """
class User:
    def __init__(self,bank, name, email, address, account_type,account):
        self.name = name
        self.email = email
        self.bank = bank
        self.address = address
        self.account_type = account_type
        self.account_number = account.account_number
        self.account = account
    def create_account(self):
        self.bank.create_account(self.name, self.email, self.address, self.account_type)
    def check_transection_history(self):
        print(self.account.transection_history)
    def deposit_amount(self, amount):
        self.bank.deposit_amount(self,self.accout, amount)
    def withdraw_amount(self, amount):
        self.bank.withdraw_amount(self,self.account, amount)
    def take_loan(self, amount):
        self.bank.take_loan(self,self.account, amount)
    def transferAmount(self, amount, receiverAcc):
        self.bank.transferAmount(self,amount,self.account, receiverAcc)
        

