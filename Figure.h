/*Разработать абстрактный класс «Геометрическая Фигура» с методами «Площадь Фигуры» и «Периметр Фигуры».
Разработать классы-наследники: Треугольник, Квадрат, Ромб, Прямоугольник, Параллелограмм, Трапеция, Круг, Эллипс.
Реализовать конструкторы, которые однозначно определяют объекты данных классов.
*/

#include <iostream>
#include <math.h>
using namespace std;

class Figure {
public:
    virtual double getSquare () = 0;
    virtual double getPerimeter () = 0;
    virtual void FigureInfo () = 0;
    static const double PI;
};

class Triangle : public Figure
{
private:
    double ab, bc, ca;   // стороны треугольника
    double angle;        // любой угол треугольника в градусах

public:
    Triangle () {}
    Triangle (double ab, double bc, double ca, double angle)
    {
        this->ab = ab;
        this->bc = bc;
        this->ca = ca;
        this->angle = angle;
    }

    double getPerimeter () override
    {
        return ab + bc + ca;
    }

    double getSquare () override
    {
        return (ab * bc * sin(angle * (PI / 180)))/2;
    }

    void FigureInfo ()
    {
        cout << "Type: Triangle" << endl;
        cout << "Square: " << getSquare() << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
    }
};

class Square : public Figure
{
private:
    double side;   // сторона квадрата

public:
    Square () {}
    Square (double side)
    {
        this->side = side;
    }

    double getPerimeter () override
    {
        return side * 4;
    }

    double getSquare () override
    {
        return side * side;
    }

    void FigureInfo ()
    {
        cout << "Type: Square" << endl;
        cout << "Square: " << getSquare() << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
    }
};

class Rhombus : public Figure
{
private:
    double side;   // сторона ромба
    double angle;  // любой угол ромба в градусах

public:
    Rhombus () {}
    Rhombus (double side, double angle)
    {
        this->side = side;
        this->angle = angle;
    }

    double getPerimeter () override
    {
        return side * 4;
    }

    double getSquare () override
    {
        return side * (side * sin(angle * (PI / 180)));   // side * sin(angle) - это высота ромба
    }

    void FigureInfo ()
    {
        cout << "Type: Rhombus" << endl;
        cout << "Square: " << getSquare() << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
    }
};

class Rectangle : public Square  // наследование от класса Квадрат, который в свою очередь наследуется от абстрактного класса
{
private:
    double width;       // ширина прямоугольника
    double length;      // длина прямоугольника

public:
    Rectangle () {}
    Rectangle (double length, double width)
    {
        this->length = length;
        this->width = width;
    }

    double getPerimeter () override
    {
        return (length + width) * 2;
    }

    double getSquare () override
    {
        return length * width;
    }

    void FigureInfo ()
    {
        cout << "Type: Rectangle" << endl;
        cout << "Square: " << getSquare() << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
    }
};

class Parallelogram : public Rhombus  // наследование от класса Ромб, который в свою очередь наследуется от абстрактного класса
{
private:
    double width;       // одна сторона параллелограмма
    double length;      // вторая сторона параллелограмма
    double angle;       // острый угол между сторон параллелограмма

public:
    Parallelogram () {}
    Parallelogram (double length, double width, double angle)
    {
        this->length = length;
        this->width = width;
        this->angle = angle;
    }

    double getPerimeter () override
    {
        return (length + width) * 2;
    }

    double getSquare () override
    {
        return length * (width * sin(angle * (PI / 180)));   // side * sin(angle) - это высота параллелограмма
    }

    void FigureInfo ()
    {
        cout << "Type: Parallelogram" << endl;
        cout << "Square: " << getSquare() << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
    }
};

class Trapeze : public Figure
{
private:
    double big_side;         // большее основание трапеции
    double other_side;       // наклонная сторона трапеции
    double angle;            // угол между основанием и боковой наклонной стороной трапеции

public:
    Trapeze () {}
    Trapeze (double big_side, double other_side, double angle)
    {
        this->big_side = big_side;
        this->other_side = other_side;
        this->angle = angle;
    }

    double getPerimeter () override
    {
        return big_side + (big_side - (other_side * cos(angle * (PI / 180)))*2) + (other_side * 2);
    }

    double getSquare () override
    {
        return ((big_side + (big_side - (other_side * cos(angle * (PI / 180)))*2)) * other_side * sin(angle * (PI / 180))) / 2;
    }

    void FigureInfo ()
    {
        cout << "Type: Trapeze" << endl;
        cout << "Square: " << getSquare() << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
    }
};

class Circle : public Figure
{
private:
    double radius;

public:
    Circle () {}
    Circle (double radius)
    {
        this->radius = radius;
    }

    double getPerimeter () override
    {
        return radius * 2 * PI;
    }

    double getSquare () override
    {
        return radius * radius * PI;
    }

    void FigureInfo ()
    {
        cout << "Type: Circle" << endl;
        cout << "Square: " << getSquare() << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
    }
};

class Ellipse : public Figure
{
private:
    double small_axis;  // малая ось
    double big_axis;    // большая ось

public:
    Ellipse () {}
    Ellipse (double big_axis, double small_axis)
    {
        this->big_axis = big_axis;
        this->small_axis = small_axis;
    }

    double getPerimeter () override
    {
        return PI * 2 * sqrt((big_axis * big_axis  +  small_axis * small_axis) /8 );
    }

    double getSquare () override
    {
        return big_axis * small_axis * PI / 4;
    }

    void FigureInfo ()
    {
        cout << "Type: Ellipse" << endl;
        cout << "Square: " << getSquare() << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
    }
};




const double Figure :: PI = 3.141592;
