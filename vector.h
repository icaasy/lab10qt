#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <QString>
#include <QPainter>
#include <QGraphicsScene> // Добавлен для визуализации

class Vector {
private:
    double m_x; // Координата X
    double m_y; // Координата Y

public:
    // Конструкторы
    Vector();
    Vector(double x, double y);

    // Геттеры
    double x() const;
    double y() const;

    // Сеттеры
    void setX(double x);
    void setY(double y);

    // Вычисление длины вектора
    double length() const;

    // Сложение векторов методом треугольника
    Vector operator+(const Vector& other) const;

    // Сложение по правилу параллелограмма (визуальное сложение)
    static Vector addByParallelogramRule(const Vector& a, const Vector& b);

    // Преобразование в строку для отображения
    QString toString() const;

    // Создание вектора по длине и углу
    static Vector fromPolar(double length, double angle);

    // Метод для рисования вектора
    void draw(QPainter *painter) const;

    // Метод для визуализации параллелограмма
    static void visualizeParallelogram(QGraphicsScene *scene, const Vector& a, const Vector& b, const QPen& pen);

    // Метод для визуализации треугольника
    static void visualizeTriangle(QGraphicsScene *scene, const Vector& a, const Vector& b, const QPen& pen);
};

#endif // VECTOR_H
