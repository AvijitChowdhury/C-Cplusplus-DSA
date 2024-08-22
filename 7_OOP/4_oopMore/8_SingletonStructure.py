

class Singleton:
    __instance = None
    def __init__(self) -> None:
        if Singleton.__instance is None:
            Singleton.__instance = self
        else:    
            raise Exception('This class is a singleton.Already have an instance, use that one by calling get_instance method')
                    
    @staticmethod
    def get_instance():
        if Singleton.__instance is None:
            Singleton()
            
        return Singleton.__instance

first = Singleton.get_instance()

second = Singleton.get_instance()

third = Singleton.get_instance()
print(first)
print(second)
print(third)