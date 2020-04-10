/*Разработать абстрактный класс «Геометрическая Фигура» с методами «Площадь Фигуры» и «Периметр Фигуры».
Разработать классы-наследники: Треугольник, Квадрат, Ромб, Прямоугольник, Параллелограмм, Трапеция, Круг, Эллипс.
Реализовать конструкторы, которые однозначно определяют объекты данных классов.
*/

#include <iostream>
#include "Figure.h"
using namespace std;

int main() {
    Triangle triangle (3, 3, 4.2425, 90);
    triangle.FigureInfo();
    cout << endl;

    Square square (5);
    square.FigureInfo();
    cout << endl;

    Rhombus rhombus (5,60);
    rhombus.FigureInfo();
    cout << endl;

    Rectangle rectangle (5, 10);
    rectangle.FigureInfo();
    cout << endl;

    Parallelogram parallelogram(3,5,30);
    parallelogram.FigureInfo();
    cout << endl;

    Trapeze trapeze (6,4,60);
    trapeze.FigureInfo();
    cout << endl;

    Circle circle(5);
    circle.FigureInfo();
    cout << endl;

    Ellipse ellipse(5,3);
    ellipse.FigureInfo();
    cout << endl;

}

