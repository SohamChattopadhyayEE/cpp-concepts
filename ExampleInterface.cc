// Online C++ compiler to run C++ program online
#include <iostream>
class Shape{
    public:
        virtual int GetArea() = 0;  
};
class Rectangle: public Shape{
    int x;
    int y;
    public:
        Rectangle(int length, int breadth){
            x = length;
            y = breadth;
        }
        int GetArea() {
            return x*y;
        }
};

class Circle: public Shape{
    int r;
    public:
        Circle(int radius){
            r = radius;
        }
        int GetArea(){
            return 3 * r * r;
        }
};

int main() {
    Shape *rectangle, *circle;
    rectangle = new Rectangle(5, 6);
    std::cout<<"Area of a rectangle: "<<rectangle->GetArea()<<std::endl;
    circle = new Circle(2);
    std::cout<<"Area of a circle: "<<circle->GetArea()<<std::endl;
    return 0;
}
