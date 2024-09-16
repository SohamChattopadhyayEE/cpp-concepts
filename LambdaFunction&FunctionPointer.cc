#include <iostream>
#include <vector>
#include <bits/stdc++.h>

void PrintValue(int i){
    std::cout<<"Funciton pointer prints: "<<i<<std::endl;
}

void forEach(const std::vector<int>& values, void(*func)(int)){
    for(int value: values) 
        func(value);
}

int main()
{
    [](int value){
        std::cout
        <<"the value within the lambda function: "
        <<value<<std::endl;
    }(100);
    std::vector<int> values = {1,2,13,3,4,5};
    std::vector<int> v = {1,2,13,3,4,5};
    forEach(values, [](int value){std::cout
            <<"value : "<<value<<std::endl;});
            
    int a = 5;
    [&](int value)
        {std::cout<<"value of sum of a & value is: "
        <<a+value<<std::endl;}(20);
    
    sort(v.begin(), v.end(), [](const int& a, const int& b) -> bool
    {
        return a > b;
    });
    
    for(int value: values) std::cout<<"value: "
                            <<value<<std::endl;
    
    forEach(values, PrintValue);
    return 0;
}
