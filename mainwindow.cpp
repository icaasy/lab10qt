#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <ctime>
#include <QGraphicsLineItem> // Добавлен заголовочный файл для QGraphicsLineItem

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene(this)) // Инициализируем SmartPointer
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene.get()); // Используем метод get() для получения сырого указателя

    // Инициализация списка длин и углов для векторов
    vectorAngles = {
        {50, 30},
        {70, 45},
        {90, 60},
        {110, 90},
        {130, 120}
    };

    // Инициализация генератора случайных чисел
    std::srand(std::time(0));
}

MainWindow::~MainWindow() {
    delete ui;
}

Vector MainWindow::getInputVector() const {
    bool okX, okY;
    double x = ui->xInput->text().toDouble(&okX);
    double y = ui->yInput->text().toDouble(&okY);
    if (okX && okY) {
        return Vector(x, y);
    } else {
        return Vector(0, 0); // Возвращаем нулевой вектор в случае ошибки
    }
}

void MainWindow::on_addButton_clicked() {
    // Добавить вектор из полей ввода
    Vector newVector = getInputVector();
    vectors.append(newVector);
    QPen pen(Qt::black);
    pen.setWidth(2); // Устанавливаем ширину линии
    scene->addLine(0, 0, newVector.x(), newVector.y(), pen);
}

void MainWindow::on_cleanButton_clicked() {
    // Очистить все векторы
    scene->clear();
    vectors.clear();
}

void MainWindow::on_triangleMethodButton_clicked() {
    // Сложение векторов методом треугольника
    if (vectors.size() >= 2) {
        Vector a = vectors.at(vectors.size() - 1);
        Vector b = vectors.at(vectors.size() - 2);
        QPen pen(Qt::black);
        pen.setWidth(2); // Устанавливаем ширину линии
        Vector::visualizeTriangle(scene.get(), a, b, pen); // Используем метод get() для получения сырого указателя
    }
}

void MainWindow::on_parallelogramMethodButton_clicked() {
    // Сложение векторов методом параллелограмма
    if (vectors.size() >= 2) {
        Vector a = vectors.at(vectors.size() - 1);
        Vector b = vectors.at(vectors.size() - 2);
        QPen pen(Qt::black);
        pen.setWidth(2); // Устанавливаем ширину линии
        Vector::visualizeParallelogram(scene.get(), a, b, pen); // Используем метод get() для получения сырого указателя
    }
}
