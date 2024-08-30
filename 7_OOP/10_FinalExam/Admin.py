"""

Admin⇒                                                                                                                              40 Marks
Can create an account                                                                        5
Can delete any user account                                                              5
Can see all user accounts list                                                            10
Can check the total available balance of the bank.                            5
Can check the total loan amount.                                                       5
Can on or off the loan feature of the bank.                                        10

"""
class Admin:
    def __init__(self, name, email, address):
        self.name = name
        self.email = email
        self.address = address
    def create_account(self, bank, name, email, address, account_type):
        bank.create_account(name, email, address, account_type, admin=True)
    def delete_account(self, bank, user):
        bank.delete_account(user, admin=True)
    def see_all_user_accounts(self, bank):
        for user in bank.users:
            print(f'Name: {user.name}, Email: {user.email}, Address: {user.address}, Account Number: {user.account_number}')
    def check_total_balance(self, bank):
        print(f'Total Balance: {bank.total_balance}')
    def check_total_loan(self, bank):
        print(f'Total Loan: {bank.total_loan}')
    def on_off_loan_feature(self, bank):
        bank.loan_feature = not bank.loan_feature
        print(f'Loan feature is {"On" if bank.loan_feature else "Off"}')
    def check_transection_history(self,user):
        print(user.account.transection_history)