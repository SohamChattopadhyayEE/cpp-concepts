#include <iostream>
#include <string>

void func(int i){
    std::cout<<"within func"<<std::endl;
    switch(i){
        case 0:
            int x = 5;
            std::cout<<"x is initiated"<<std::endl;
            break;
        case 1:
            x += 1;
            std::cout<<x<<std::endl;
            break;
        default:
            return;
    }
}

int main(){
    int i = 0;
    func(0);
    func(1);
}
