#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <vector>
#include "vector.h"
#include "smartpointer.h" // Добавляем заголовочный файл SmartPointer

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_cleanButton_clicked();
    void on_triangleMethodButton_clicked();
    void on_parallelogramMethodButton_clicked();

private:
    Ui::MainWindow *ui;
    SmartPointer<QGraphicsScene> scene; // Используем SmartPointer для управления QGraphicsScene
    QList<Vector> vectors;
    std::vector<std::pair<double, double>> vectorAngles; // Список длин и углов для векторов

    Vector getRandomVector() const; // Метод для получения случайного вектора
    Vector getInputVector() const; // Метод для получения вектора из полей ввода
};

#endif // MAINWINDOW_H
