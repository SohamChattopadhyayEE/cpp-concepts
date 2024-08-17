#include <iostream>

class Singleton{
    private:
        static Singleton *instancePtr;
        std::string name;
        std::string std;
        Singleton(){}
    
    public:
        // Delete copy constructer
        Singleton(const Singleton &obj) = delete;
        
        static Singleton* GetInstance(){
            if(instancePtr == NULL) {
                instancePtr = new Singleton();
            }
            return instancePtr;
        }
        
        void SetValues(std::string name, std::string std){
            this->name = name;
            this->std = std;
        }
        
        void Print(){
            std::cout<<" name: "<<this->name<<" class: "<<this->std<<std::endl;
        }
};

Singleton* Singleton::instancePtr = NULL;

int main()
{
    Singleton* ptr = Singleton::GetInstance();
    ptr->SetValues("soham", "12");
    ptr->Print();
    
    ptr->SetValues("asif", "11");
    ptr->Print();

    return 0;
}
