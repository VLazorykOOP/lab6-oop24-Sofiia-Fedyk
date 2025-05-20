#include "task2.h"
using namespace std;

// Похідний клас Прямокутник
Rectangle::Rectangle(double w, double h) : width(w), height(h) {
    if (w <= 0 || h <= 0) {
        throw invalid_argument("Розміри прямокутника повинні бути додатними");
    }
}

double Rectangle::area() const {
    return width * height;
}

void Rectangle::print() const {
    cout << "Прямокутник: ширина = " << width 
         << ", висота = " << height 
         << ", площа = " << area() << endl;
}

// Похідний клас Коло
Circle::Circle(double r) : radius(r) {
    if (r <= 0) {
        throw invalid_argument("Радіус кола повинен бути додатним");
    }
}

double Circle::area() const {
    return M_PI * radius * radius;
}

void Circle::print() const {
    cout << "Коло: радіус = " << radius 
         << ", площа = " << area() << endl;
}

// Похідний клас Прямокутний трикутник
RightTriangle::RightTriangle(double b, double h) : base(b), height(h) {
    if (b <= 0 || h <= 0) {
        throw invalid_argument("Катети трикутника повинні бути додатними");
    }
}

double RightTriangle::area() const {
    return 0.5 * base * height;
}

void RightTriangle::print() const {
    cout << "Прямокутний трикутник: основа = " << base 
         << ", висота = " << height 
         << ", площа = " << area() << endl;
}

// Похідний клас Трапеція
Trapezoid::Trapezoid(double b1, double b2, double h) : base1(b1), base2(b2), height(h) {
    if (b1 <= 0 || b2 <= 0 || h <= 0) {
        throw invalid_argument("Основи та висота трапеції повинні бути додатними");
    }
}

double Trapezoid::area() const {
    return 0.5 * (base1 + base2) * height;
}

void Trapezoid::print() const {
    cout << "Трапеція: основа1 = " << base1 
         << ", основа2 = " << base2 
         << ", висота = " << height 
         << ", площа = " << area() << endl;
}

// Функція для демонстрації роботи з абстрактним класом
void demonstrateFigures() {
    cout << "=== Демонстрація роботи з абстрактним класом Фігура ===" << endl << endl;
    
    try {
        // Створення масиву вказівників на абстрактний клас
        vector<unique_ptr<Figure>> figures;
        
        // Додавання об'єктів різних похідних класів
        figures.push_back(make_unique<Rectangle>(5.0, 3.0));
        figures.push_back(make_unique<Circle>(4.0));
        figures.push_back(make_unique<RightTriangle>(6.0, 8.0));
        figures.push_back(make_unique<Trapezoid>(10.0, 6.0, 4.0));
        
        // Виведення інформації про кожну фігуру
        cout << "Інформація про фігури:" << endl;
        for (const auto& figure : figures) {
            figure->print();
        }
        
        // Обчислення загальної площі всіх фігур
        double totalArea = 0.0;
        for (const auto& figure : figures) {
            totalArea += figure->area();
        }
        
        cout << endl << "Загальна площа всіх фігур: " << totalArea << endl;
        
        // Демонстрація поліморфізму
        cout << endl << "=== Демонстрація поліморфізму ===" << endl;
        
        // Створення окремих об'єктів
        Rectangle rect(7.0, 2.0);
        Circle circle(3.5);
        
        // Використання вказівників на базовий клас
        Figure* figPtr1 = &rect;
        Figure* figPtr2 = &circle;
        
        cout << "Через вказівник на базовий клас:" << endl;
        figPtr1->print();
        figPtr2->print();
        
        cout << "Площі через вказівники: " 
             << figPtr1->area() << " та " << figPtr2->area() << endl;
             
    } catch (const exception& e) {
        cerr << "Помилка: " << e.what() << endl;
    }
}