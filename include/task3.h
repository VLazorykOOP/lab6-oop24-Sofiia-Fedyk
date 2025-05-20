#ifndef TASK3_H
#define TASK3_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Базовий клас "Студент"
class Student {
protected:
    std::string name;
    int age;
    std::string university;
    std::string major;
    int course;
    double gpa;

public:
    // Конструктор за замовчуванням
    Student();
    
    // Параметризований конструктор
    Student(const std::string& name, int age, const std::string& university, 
            const std::string& major, int course, double gpa);
    
    // Копіюючий конструктор
    Student(const Student& other);
    
    // Віртуальний деструктор
    virtual ~Student();
    
    // Віртуальна функція для виведення інформації
    virtual void displayInfo() const;
    
    // Геттери
    std::string getName() const;
    int getAge() const;
    std::string getUniversity() const;
    std::string getMajor() const;
    int getCourse() const;
    double getGPA() const;
    
    // Сеттери
    void setName(const std::string& n);
    void setAge(int a);
    void setUniversity(const std::string& u);
    void setMajor(const std::string& m);
    void setCourse(int c);
    void setGPA(double g);
    
    // Перевантаження оператора присвоєння
    Student& operator=(const Student& other);
    
    // Оголошення дружніх операторів
    friend std::istream& operator>>(std::istream& is, Student& student);
    friend std::ostream& operator<<(std::ostream& os, const Student& student);
};

// Базовий клас "Батько сімейства"
class Father {
protected:
    std::string name;
    int age;
    std::string occupation;
    double salary;
    std::vector<std::string> children;
    std::string spouse;
    int yearsMarried;

public:
    // Конструктор за замовчуванням
    Father();
    
    // Параметризований конструктор
    Father(const std::string& name, int age, const std::string& occupation, 
           double salary, const std::string& spouse, int yearsMarried);
    
    // Копіюючий конструктор
    Father(const Father& other);
    
    // Віртуальний деструктор
    virtual ~Father();
    
    // Віртуальна функція для виведення інформації
    virtual void displayInfo() const;
    
    // Геттери
    std::string getName() const;
    int getAge() const;
    std::string getOccupation() const;
    double getSalary() const;
    std::vector<std::string> getChildren() const;
    std::string getSpouse() const;
    int getYearsMarried() const;
    
    // Сеттери
    void setName(const std::string& n);
    void setAge(int a);
    void setOccupation(const std::string& o);
    void setSalary(double s);
    void setSpouse(const std::string& s);
    void setYearsMarried(int y);
    
    // Оператор присвоєння
    Father& operator=(const Father& other);
    
    // Методи для роботи з дітьми
    void addChild(const std::string& child);
    void removeChild(const std::string& child);
    
    // Оголошення дружніх операторів
    friend std::istream& operator>>(std::istream& is, Father& father);
    friend std::ostream& operator<<(std::ostream& os, const Father& father);
};

// Похідний клас з множинним спадкуванням
class StudentFather : public Student, public Father {
private:
    bool isWorkingPartTime;
    std::string workSchedule;
    double timeManagementScore;

public:
    // Конструктор за замовчуванням
    StudentFather();
    
    // Параметризований конструктор
    StudentFather(const std::string& studentName, int studentAge, const std::string& university,
                  const std::string& major, int course, double gpa,
                  const std::string& fatherName, int fatherAge, const std::string& occupation,
                  double salary, const std::string& spouse, int yearsMarried,
                  bool isWorkingPartTime, const std::string& workSchedule, double timeManagementScore);
    
    // Копіюючий конструктор
    StudentFather(const StudentFather& other);
    
    // Оператор присвоювання
    StudentFather& operator=(const StudentFather& other);
    
    // Віртуальний деструктор
    virtual ~StudentFather();
    
    // Перевизначена функція для виведення повної інформації
    void displayInfo() const override;
    
    // Специфічні методи для StudentFather
    void setWorkStatus(bool working, const std::string& schedule = "");
    void setTimeManagementScore(double score);
    
    // Геттери для специфічних полів
    bool getWorkStatus() const;
    std::string getWorkSchedule() const;
    double getTimeManagementScore() const;
    
    // Розв'язання неоднозначності для загальних полів
    std::string getFullName() const;
    int getFullAge() const;
    
    // Оголошення дружніх операторів
    friend std::istream& operator>>(std::istream& is, StudentFather& sf);
    friend std::ostream& operator<<(std::ostream& os, const StudentFather& sf);
};

// Функції для демонстрації
void demonstrateStudentFatherHierarchy();
void demonstrateStudentFatherIO();

#endif // TASK3_H