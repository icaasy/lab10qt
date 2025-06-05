#include "vector.h"
#include <cmath>

Vector::Vector() : m_x(0), m_y(0) {}
Vector::Vector(double x, double y) : m_x(x), m_y(y) {}

double Vector::x() const { return m_x; }
double Vector::y() const { return m_y; }

void Vector::setX(double x) { m_x = x; }
void Vector::setY(double y) { m_y = y; }

double Vector::length() const {
    return std::sqrt(m_x * m_x + m_y * m_y);
}

Vector Vector::operator+(const Vector& other) const {
    return Vector(m_x + other.m_x, m_y + other.m_y);
}

Vector Vector::addByParallelogramRule(const Vector& a, const Vector& b) {
    return a + b;
}

// Преобразование в строку для отображения
QString Vector::toString() const {
    return QString("(%1, %2)").arg(m_x).arg(m_y);
}

Vector Vector::fromPolar(double length, double angle) {
    double radians = angle * M_PI / 180.0; // Перевод угла в радианы
    double x = length * std::cos(radians);
    double y = length * std::sin(radians);
    return Vector(x, y);
}

void Vector::draw(QPainter *painter) const {
    painter->setPen(Qt::black);
    painter->drawLine(0, 0, m_x, m_y);
}

// Метод для визуализации параллелограмма
void Vector::visualizeParallelogram(QGraphicsScene *scene, const Vector& a, const Vector& b, const QPen& pen) {
    Vector result = a + b;
    scene->addLine(0, 0, a.x(), a.y(), pen);
    scene->addLine(a.x(), a.y(), result.x(), result.y(), pen);
    scene->addLine(0, 0, b.x(), b.y(), pen);
    scene->addLine(b.x(), b.y(), result.x(), result.y(), pen);
    scene->addLine(0, 0, result.x(), result.y(), pen);
}

// Метод для визуализации треугольника
void Vector::visualizeTriangle(QGraphicsScene *scene, const Vector& a, const Vector& b, const QPen& pen) {
    Vector result = a + b;
    scene->addLine(0, 0, a.x(), a.y(), pen);
    scene->addLine(a.x(), a.y(), result.x(), result.y(), pen);
    scene->addLine(result.x(), result.y(), 0, 0, pen);
}
