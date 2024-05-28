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
    Shape* ptr;
    Rectangle rectangle(5, 6);
    ptr = &rectangle;
    std::cout<<"Area of a rectangle: "<<ptr->GetArea()<<std::endl;
    Circle circle(2);
    ptr = &circle;
    std::cout<<"Area of a circle: "<<ptr->GetArea()<<std::endl;
    return 0;
}
