class Student:
    def __init__(self,name, current_class, id)->None:
        self.name = name
        self.id = id
        self.current_class = current_class
    
    def __repr__(self)-> str:
        return f'{self.name} is a student of class {self.current_class} and his/her id is {self.id}'

class Teacher:
    def __init__(self,name, subject, id)->None:
        self.name = name
        self.id = id
        self.subject = subject
    def __repr__(self)-> str:
        return f'{self.name} is a teacher of {self.subject} and his/her id is {self.id}'

class School:
    def __init__(self,name)-> None:
        self.name = name
        self.students = []
        self.teachers = []

    def add_teacher(self, teacher, subject):
        id = len(self.teachers) + 101
        teacher  = Teacher(teacher,subject, id)
        self.teachers.append(teacher)
    def enroll(self ,name , fee):
        if fee > 6500:
            return 'not enough fee'
        else:
            id = len(self.students)+1
            student = Student(name, 'C', id)
            self.students.append(student)
            return f'{name} is enrolled with id: {id}, extra money {fee-6500} will be refunded'
    def __repr__(self)-> str:
        print('welcome to', self.name)
        print('-------Our Teachers-------')
        for teacher in self.teachers:
            print(teacher)
        print('-------Our Students-------')
        for student in self.students:
            print(student)
        return 'All done for now'

# alia = Student('Alia Bhatt', '10', 101)
# ranbee = Teacher('Ranbir Kapoor', 'Math', 201)

# print(alia)
# print(ranbee)
phitron  = School('Phitron')
phitron.enroll('alia',5200)
phitron.enroll('rani',8000)
phitron.enroll('aishwaraiya',7000)
phitron.enroll('vaijaan',900000)

phitron.add_teacher('tom cruise','Algo')
phitron.add_teacher('David J Malan','CS50')
phitron.add_teacher('Elon Musk','SpaceX')

print(phitron)