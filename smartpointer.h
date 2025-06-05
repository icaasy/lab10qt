#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include <QGraphicsScene> // Добавляем заголовочный файл для QGraphicsScene

template <typename T>
class SmartPointer {
private:
    T* m_ptr; // Указатель на управляемый объект

public:
    // Конструктор
    explicit SmartPointer(T* ptr = nullptr);

    // Деструктор
    ~SmartPointer();

    // Перегрузка оператора разыменования
    T& operator*() const;

    // Перегрузка оператора доступа к членам
    T* operator->() const;

    // Метод для получения сырого указателя
    T* get() const;
};

#endif // SMARTPOINTER_H
