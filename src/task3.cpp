#include "task3.h"

// Базовий клас "Студент"

// Конструктор за замовчуванням
Student::Student() : name(""), age(0), university(""), major(""), course(1), gpa(0.0) {}

// Параметризований конструктор
Student::Student(const std::string& name, int age, const std::string& university, 
        const std::string& major, int course, double gpa)
    : name(name), age(age), university(university), major(major), course(course), gpa(gpa) {}

// Копіюючий конструктор
Student::Student(const Student& other)
    : name(other.name), age(other.age), university(other.university),
      major(other.major), course(other.course), gpa(other.gpa) {}

// Віртуальний деструктор
Student::~Student() {
    std::cout << "Destructor Student called for " << name << std::endl;
}

// Оператор присвоєння
Student& Student::operator=(const Student& other) {
    if (this != &other) {
        name = other.name;
        age = other.age;
        university = other.university;
        major = other.major;
        course = other.course;
        gpa = other.gpa;
    }
    return *this;
}

// Віртуальна функція для виведення інформації
void Student::displayInfo() const {
    std::cout << "Student Information:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "University: " << university << std::endl;
    std::cout << "Major: " << major << std::endl;
    std::cout << "Course: " << course << std::endl;
    std::cout << "GPA: " << gpa << std::endl;
}

// Геттери
std::string Student::getName() const { return name; }
int Student::getAge() const { return age; }
std::string Student::getUniversity() const { return university; }
std::string Student::getMajor() const { return major; }
int Student::getCourse() const { return course; }
double Student::getGPA() const { return gpa; }

// Сеттери
void Student::setName(const std::string& n) { name = n; }
void Student::setAge(int a) { age = a; }
void Student::setUniversity(const std::string& u) { university = u; }
void Student::setMajor(const std::string& m) { major = m; }
void Student::setCourse(int c) { course = c; }
void Student::setGPA(double g) { gpa = g; }

// Перевантаження оператора вводу
std::istream& operator>>(std::istream& is, Student& student) {
    std::cout << "Enter student name: ";
    std::getline(is, student.name);
    std::cout << "Enter student age: ";
    is >> student.age;
    is.ignore(); // Очищуємо буфер
    std::cout << "Enter university: ";
    std::getline(is, student.university);
    std::cout << "Enter major: ";
    std::getline(is, student.major);
    std::cout << "Enter course: ";
    is >> student.course;
    std::cout << "Enter GPA: ";
    is >> student.gpa;
    is.ignore(); // Очищуємо буфер
    return is;
}

// Перевантаження оператора виводу
std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "Student: " << student.name << ", Age: " << student.age 
       << ", University: " << student.university << ", Major: " << student.major
       << ", Course: " << student.course << ", GPA: " << student.gpa;
    return os;
}

// Базовий клас "Батько сімейства"

// Конструктор за замовчуванням
Father::Father() : name(""), age(0), occupation(""), salary(0.0), spouse(""), yearsMarried(0) {}

// Параметризований конструктор
Father::Father(const std::string& name, int age, const std::string& occupation, 
       double salary, const std::string& spouse, int yearsMarried)
    : name(name), age(age), occupation(occupation), salary(salary), 
      spouse(spouse), yearsMarried(yearsMarried) {}

// Копіюючий конструктор
Father::Father(const Father& other)
    : name(other.name), age(other.age), occupation(other.occupation),
      salary(other.salary), children(other.children), spouse(other.spouse),
      yearsMarried(other.yearsMarried) {}

// Оператор присвоєння
Father& Father::operator=(const Father& other) {
    if (this != &other) {
        name = other.name;
        age = other.age;
        occupation = other.occupation;
        salary = other.salary;
        children = other.children;
        spouse = other.spouse;
        yearsMarried = other.yearsMarried;
    }
    return *this;
}

// Віртуальний деструктор
Father::~Father() {
    std::cout << "Destructor Father called for " << name << std::endl;
}

// Віртуальна функція для виведення інформації
void Father::displayInfo() const {
    std::cout << "Father Information:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Occupation: " << occupation << std::endl;
    std::cout << "Salary: $" << salary << std::endl;
    std::cout << "Spouse: " << spouse << std::endl;
    std::cout << "Years married: " << yearsMarried << std::endl;
    std::cout << "Children: ";
    if (children.empty()) {
        std::cout << "None";
    } else {
        for (size_t i = 0; i < children.size(); ++i) {
            std::cout << children[i];
            if (i < children.size() - 1) std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

// Геттери
std::string Father::getName() const { return name; }
int Father::getAge() const { return age; }
std::string Father::getOccupation() const { return occupation; }
double Father::getSalary() const { return salary; }
std::vector<std::string> Father::getChildren() const { return children; }
std::string Father::getSpouse() const { return spouse; }
int Father::getYearsMarried() const { return yearsMarried; }

// Сеттери
void Father::setName(const std::string& n) { name = n; }
void Father::setAge(int a) { age = a; }
void Father::setOccupation(const std::string& o) { occupation = o; }
void Father::setSalary(double s) { salary = s; }
void Father::setSpouse(const std::string& s) { spouse = s; }
void Father::setYearsMarried(int y) { yearsMarried = y; }

// Методи для роботи з дітьми
void Father::addChild(const std::string& child) {
    children.push_back(child);
}

void Father::removeChild(const std::string& child) {
    auto it = std::find(children.begin(), children.end(), child);
    if (it != children.end()) {
        children.erase(it);
    }
}

// Перевантаження оператора вводу
std::istream& operator>>(std::istream& is, Father& father) {
    std::cout << "Enter father name: ";
    std::getline(is, father.name);
    std::cout << "Enter father age: ";
    is >> father.age;
    is.ignore(); // Очищуємо буфер
    std::cout << "Enter occupation: ";
    std::getline(is, father.occupation);
    std::cout << "Enter salary: ";
    is >> father.salary;
    is.ignore(); // Очищуємо буфер
    std::cout << "Enter spouse name: ";
    std::getline(is, father.spouse);
    std::cout << "Enter years married: ";
    is >> father.yearsMarried;
    is.ignore(); // Очищуємо буфер
    
    int childCount;
    std::cout << "Enter number of children: ";
    is >> childCount;
    is.ignore(); // Очищуємо буфер
    
    father.children.clear();
    for (int i = 0; i < childCount; ++i) {
        std::string child;
        std::cout << "Enter child " << (i + 1) << " name: ";
        std::getline(is, child);
        father.children.push_back(child);
    }
    
    return is;
}

// Перевантаження оператора виводу
std::ostream& operator<<(std::ostream& os, const Father& father) {
    os << "Father: " << father.name << ", Age: " << father.age 
       << ", Occupation: " << father.occupation << ", Salary: $" << father.salary
       << ", Spouse: " << father.spouse << ", Children: " << father.children.size();
    return os;
}

// Похідний клас з множинним спадкуванням

// Конструктор за замовчуванням
StudentFather::StudentFather() : Student(), Father(), isWorkingPartTime(false), 
                 workSchedule("Flexible"), timeManagementScore(5.0) {}

// Параметризований конструктор
StudentFather::StudentFather(const std::string& studentName, int studentAge, const std::string& university,
              const std::string& major, int course, double gpa,
              const std::string& fatherName, int fatherAge, const std::string& occupation,
              double salary, const std::string& spouse, int yearsMarried,
              bool isWorkingPartTime, const std::string& workSchedule, double timeManagementScore)
    : Student(studentName, studentAge, university, major, course, gpa),
      Father(fatherName, fatherAge, occupation, salary, spouse, yearsMarried),
      isWorkingPartTime(isWorkingPartTime), workSchedule(workSchedule), 
      timeManagementScore(timeManagementScore) {
    // Розв'язання конфлікту імен - використовуємо ім'я студента як основне
    Father::name = studentName;
    Father::age = studentAge;
}

// Копіюючий конструктор
StudentFather::StudentFather(const StudentFather& other)
    : Student(other), Father(other),
      isWorkingPartTime(other.isWorkingPartTime),
      workSchedule(other.workSchedule),
      timeManagementScore(other.timeManagementScore) {}

// Оператор присвоювання
StudentFather& StudentFather::operator=(const StudentFather& other) {
    if (this != &other) {
        Student::operator=(other);
        Father::operator=(other);
        isWorkingPartTime = other.isWorkingPartTime;
        workSchedule = other.workSchedule;
        timeManagementScore = other.timeManagementScore;
    }
    return *this;
}

// Віртуальний деструктор
StudentFather::~StudentFather() {
    std::cout << "Destructor StudentFather called for " << Student::name << std::endl;
}

// Перевизначена функція для виведення повної інформації
void StudentFather::displayInfo() const {
    std::cout << "=== STUDENT-FATHER INFORMATION ===" << std::endl;
    std::cout << "Personal Details:" << std::endl;
    std::cout << "Name: " << Student::name << std::endl;
    std::cout << "Age: " << Student::age << std::endl;
    
    std::cout << "\nStudent Information:" << std::endl;
    std::cout << "University: " << university << std::endl;
    std::cout << "Major: " << major << std::endl;
    std::cout << "Course: " << course << std::endl;
    std::cout << "GPA: " << gpa << std::endl;
    
    std::cout << "\nFamily Information:" << std::endl;
    std::cout << "Occupation: " << occupation << std::endl;
    std::cout << "Salary: $" << salary << std::endl;
    std::cout << "Spouse: " << spouse << std::endl;
    std::cout << "Years married: " << yearsMarried << std::endl;
    std::cout << "Children: ";
    if (children.empty()) {
        std::cout << "None";
    } else {
        for (size_t i = 0; i < children.size(); ++i) {
            std::cout << children[i];
            if (i < children.size() - 1) std::cout << ", ";
        }
    }
    std::cout << std::endl;
    
    std::cout << "\nWork-Study Balance:" << std::endl;
    std::cout << "Working part-time: " << (isWorkingPartTime ? "Yes" : "No") << std::endl;
    std::cout << "Work schedule: " << workSchedule << std::endl;
    std::cout << "Time management score: " << timeManagementScore << "/10" << std::endl;
    std::cout << "===================================" << std::endl;
}

// Специфічні методи для StudentFather
void StudentFather::setWorkStatus(bool working, const std::string& schedule) {
    isWorkingPartTime = working;
    if (!schedule.empty()) {
        workSchedule = schedule;
    }
}

void StudentFather::setTimeManagementScore(double score) {
    if (score >= 0 && score <= 10) {
        timeManagementScore = score;
    }
}

// Геттери для специфічних полів
bool StudentFather::getWorkStatus() const { return isWorkingPartTime; }
std::string StudentFather::getWorkSchedule() const { return workSchedule; }
double StudentFather::getTimeManagementScore() const { return timeManagementScore; }

// Розв'язання неоднозначності для загальних полів
std::string StudentFather::getFullName() const { return Student::name; }
int StudentFather::getFullAge() const { return Student::age; }

// Перевантаження оператора введення
std::istream& operator>>(std::istream& is, StudentFather& sf) {
    std::cout << "=== Enter Student-Father Information ===" << std::endl;
    
    // Вводимо інформацію про студента
    std::cout << "Enter name: ";
    std::getline(is, sf.Student::name);
    sf.Father::name = sf.Student::name; // Синхронізуємо імена
    
    std::cout << "Enter age: ";
    is >> sf.Student::age;
    sf.Father::age = sf.Student::age; // Синхронізуємо вік
    is.ignore();
    
    std::cout << "Enter university: ";
    std::getline(is, sf.university);
    std::cout << "Enter major: ";
    std::getline(is, sf.major);
    std::cout << "Enter course: ";
    is >> sf.course;
    std::cout << "Enter GPA: ";
    is >> sf.gpa;
    is.ignore();
    
    // Вводимо інформацію про батька
    std::cout << "Enter occupation: ";
    std::getline(is, sf.occupation);
    std::cout << "Enter salary: ";
    is >> sf.salary;
    is.ignore();
    std::cout << "Enter spouse name: ";
    std::getline(is, sf.spouse);
    std::cout << "Enter years married: ";
    is >> sf.yearsMarried;
    is.ignore();
    
    int childCount;
    std::cout << "Enter number of children: ";
    is >> childCount;
    is.ignore();
    
    sf.children.clear();
    for (int i = 0; i < childCount; ++i) {
        std::string child;
        std::cout << "Enter child " << (i + 1) << " name: ";
        std::getline(is, child);
        sf.children.push_back(child);
    }
    
    // Вводимо специфічну інформацію
    std::cout << "Is working part-time? (1 for yes, 0 for no): ";
    is >> sf.isWorkingPartTime;
    is.ignore();
    
    std::cout << "Enter work schedule: ";
    std::getline(is, sf.workSchedule);
    
    std::cout << "Enter time management score (0-10): ";
    is >> sf.timeManagementScore;
    is.ignore();
    
    return is;
}

// Перевантаження оператора виведення
std::ostream& operator<<(std::ostream& os, const StudentFather& sf) {
    os << "StudentFather: " << sf.Student::name << ", Age: " << sf.Student::age
       << ", University: " << sf.university << ", Major: " << sf.major
       << ", Occupation: " << sf.occupation << ", Children: " << sf.children.size()
       << ", Part-time: " << (sf.isWorkingPartTime ? "Yes" : "No");
    return os;
}

// Функція для демонстрації роботи ієрархії Student-Father
void demonstrateStudentFatherHierarchy() {
    std::cout << "=== TASK 3.1: Student-Father Hierarchy Demo ===" << std::endl;
    
    // Створюємо об'єкт Student
    Student student("Олексій Петренко", 20, "КПІ", "Інформатика", 3, 8.5);
    std::cout << "\nStudent object created:" << std::endl;
    std::cout << student << std::endl;
    student.displayInfo();
    
    // Створюємо об'єкт Father
    Father father("Петро Петренко", 45, "Інженер", 50000, "Марія Петренко", 15);
    father.addChild("Олена");
    father.addChild("Андрій");
    std::cout << "\nFather object created:" << std::endl;
    std::cout << father << std::endl;
    father.displayInfo();
    
    // Створюємо об'єкт StudentFather
    StudentFather studentFather("Ігор Іваненко", 28, "НТУ", "Економіка", 2, 7.8,
                               "Ігор Іваненко", 28, "Менеджер", 35000, "Тетяна Іваненко", 5,
                               true, "Вечірня зміна", 8.5);
    studentFather.addChild("Максим");
    
    std::cout << "\nStudentFather object created:" << std::endl;
    std::cout << studentFather << std::endl;
    studentFather.displayInfo();
    
    // Демонстрація поліморфізму
    std::cout << "\n=== Polymorphism Demo ===" << std::endl;
    Student* students[] = {&student, &studentFather};
    
    for (int i = 0; i < 2; ++i) {
        std::cout << "\nCalling displayInfo() via Student pointer:" << std::endl;
        students[i]->displayInfo();
    }
    
    // Демонстрація множинного спадкування
    std::cout << "\n=== Multiple Inheritance Demo ===" << std::endl;
    std::cout << "StudentFather as Student: " << static_cast<Student&>(studentFather) << std::endl;
    std::cout << "StudentFather as Father: " << static_cast<Father&>(studentFather) << std::endl;
    
    // Приклад з конфліктом імен
    std::cout << "\n=== Name Conflict Resolution ===" << std::endl;
    std::cout << "Student name: " << studentFather.Student::getName() << std::endl;
    std::cout << "Father name: " << studentFather.Father::getName() << std::endl;
    std::cout << "Full name (Student): " << studentFather.getFullName() << std::endl;
    
    std::cout << "\n=== Task 3.1 finished ===" << std::endl;
}

// Функція для демонстрації введення/виведення
void demonstrateStudentFatherIO() {
    std::cout << "\n=== Input/Output Demonstration ===" << std::endl;
    
    StudentFather sf;
    std::cout << "Enter information for a new StudentFather:" << std::endl;
    std::cin >> sf;
    
    std::cout << "\nYou entered:" << std::endl;
    std::cout << sf << std::endl;
    
    std::cout << "\nFull information:" << std::endl;
    sf.displayInfo();
}