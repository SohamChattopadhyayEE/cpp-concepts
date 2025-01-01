#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cfloat>
#include <set>

using namespace std;
// Copy function: Not related to this illustration
void func(char *p, const char *q){
    while(*p++ = *q++);
}

int main(){
    int* p1 = new int{20};
    cout<<"p1: "<<*p1<<endl;
    delete p1; // Delete p1 once
    char* p3 = new char{'a'};
    delete p1; // Delete p1 for the second time
    // Ambiguous results for p3, since the memory where p3 is pointing to is deleted  
    cout<<"p1: "<<*p1<<" p3: "<<*p3<<endl; 
}
