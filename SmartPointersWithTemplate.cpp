#include <iostream>
template<class T>
class SmartPtr{
    private:
        T *ptr;
    public:
        SmartPtr(T *p = NULL){
            ptr = p;
        }
        
        ~SmartPtr(){delete(ptr);}
        
        T& operator*(){return *ptr;}
};

int main()
{
    SmartPtr<int> int_ptr(new int());
    *int_ptr = 50;
    std::cout<<"Integer pointer: "<<*int_ptr<<std::endl;
    
    SmartPtr<double> double_ptr(new double());
    *double_ptr = 23.65;
    std::cout<<"Double pointer: "<<*double_ptr<<std::endl;
    return 0;
}
