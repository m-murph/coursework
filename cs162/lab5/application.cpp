#include <iostream>
#include "rectangle.h"
#include "square.h"
#include "shape.h"
#include "circle.h"
using namespace std;




int main(){
    /*
    Shape s1("unknown shape", "brown");
    Rectangle r1(22.3, 11.7, "rectangle", "orange");
    Circle c1(7.4, "Circle", "pink");
    Square q1(1.8, "square", "red");

    cout << s1.getName() << " with color " << s1.getColor() << " has area " << s1.area() << "\n" << endl;
    cout << r1.getName() << " with color " << r1.getColor() << " has: width, length " << r1.getWidth() << ", " << r1.getHeight() << " and has area " << r1.area() << "\n" << endl;
    cout << c1.getName() << " with color " << c1.getColor() << " has radius " << c1.getRadius() <<  " and has area "  << c1.area() << "\n" << endl;
    cout << q1.getName() << " with color " << q1.getColor() << " has side length " << q1.getWidth() <<  " and has area "  << q1.area() << "\n" << endl;
    */

   Shape** array_of_shapes = new Shape*[3];
   Rectangle* rect = new Rectangle(27.2, 11.1, "rectangle", "polka dot");
   Circle* c = new Circle(7.3, "circle", "silver");
   Square* sq = new Square(4.4, "square", "orange");

   array_of_shapes[0] = rect;
   array_of_shapes[1] = c;
   array_of_shapes[2] = sq;

   for (int i = 0; i<3; i++){
        cout << array_of_shapes[i]->getName() << " has area " << array_of_shapes[i]->area() << endl;
   }

   Circle myCircle(3.2, "c", "green");
   Square mySquare(1, "squ", "sand prange");
   if (myCircle > mySquare){
        cout << "the circle has a larger area" << endl;
   }

    for (int i = 0; i<3; i++){
        delete array_of_shapes[i];
    }
    delete[] array_of_shapes;

    cout << "hi" << endl;

    return 0;
}