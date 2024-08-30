from School import School
from School import Classroom, Subject
from Persons import Student, Teacher


def main():
    school = School('Adam Jee', 'UTTARA')
    
    eight = Classroom('eight')
    school.add_classroom(eight)
    nine = Classroom('nine')
    school.add_classroom(nine)
    ten = Classroom('ten')
    school.add_classroom(ten)
    
    #adding students
    abul = Student('Abir Khan',eight)
    school.student_admission(abul, )#as classroom named as eight so it will be added to eight twicely
    babul = Student('Babul Khan', eight)
    school.student_admission(babul)
    cabul = Student('Cabul Khan', eight)
    school.student_admission(cabul)
    
    #subjects
    
    physics_teacher = Teacher('Shahjahan Tapon Rana')
    physics = Subject('physics',physics_teacher)
    eight.add_subject(physics)
    
    chemistry_teacher = Teacher('Haradon Nag')
    chemistry = Subject('chemistry',chemistry_teacher)
    eight.add_subject(chemistry)
    
    math_teacher = Teacher('Asim Kumar Saha')
    math = Subject('physics',math_teacher)
    eight.add_subject(math)
    
    eight.take_semister_final()
    
    print(school)
    
if __name__ == '__main__':
    main()