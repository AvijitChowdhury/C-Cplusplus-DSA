#encapsulation is the process of restricting access to certain parts of an object
#encapsulation is achieved by using access specifiers
#public, protected, private
#public: can be accessed from anywhere
#protected: can be accessed within the class and its subclass
#private: can only be accessed within the class
class Bank:
    def __init__(self, holder_name, initial_deposit)->None:
        self.holder_name = holder_name #public attribute
        self.__branch = 'Patherghata' #protected attribute
        self.__balance = initial_deposit #private
    def deposit(self, amount)->None:
        self.__balance += amount
    def get_balance(self)->float:
        return self.__balance
    def withdraw(self, amount):
        if amount < self.__balance:
            self.__balance =self.__balance - amount
            return self.amount 
        else:
            return 'Insufficient balance'
#creating an object of Bank class``
    
    
rafsun = Bank('Rafsun', 1000)
print(rafsun.get_balance())
rafsun.holder_name = 'Rafsun Jany'
print(rafsun.holder_name)
rafsun.__branch = 'Kazir Dewri'
print(rafsun.__branch)
print(rafsun.get_balance())
rafsun.deposit(500)
print(rafsun.get_balance())
print(rafsun.withdraw(2000))
#accessing private attributes from outside the class
#using name mangling technique to access private attributes
#object._class__attribute
print(dir(rafsun))
print(rafsun._Bank__balance)