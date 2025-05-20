#ifndef TASK2_H
#define TASK2_H

#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

// Абстрактний базовий клас Фігура
class Figure {
public:
    // Чиста віртуальна функція для обчислення площі
    virtual double area() const = 0;
    
    // Віртуальна функція для виведення інформації про фігуру
    virtual void print() const = 0;
    
    // Віртуальний деструктор
    virtual ~Figure() = default;
};

// Похідний клас Прямокутник
class Rectangle : public Figure {
private:
    double width, height;
    
public:
    Rectangle(double w, double h);
    
    double area() const override;
    void print() const override;
};

// Похідний клас Коло
class Circle : public Figure {
private:
    double radius;
    
public:
    Circle(double r);
    
    double area() const override;
    void print() const override;
};

// Похідний клас Прямокутний трикутник
class RightTriangle : public Figure {
private:
    double base, height;
    
public:
    RightTriangle(double b, double h);
    
    double area() const override;
    void print() const override;
};

// Похідний клас Трапеція
class Trapezoid : public Figure {
private:
    double base1, base2, height;
    
public:
    Trapezoid(double b1, double b2, double h);
    
    double area() const override;
    void print() const override;
};

// Функція для демонстрації роботи з абстрактним класом
void demonstrateFigures();

#endif // TASK2_H