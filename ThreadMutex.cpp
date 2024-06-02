#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int counter = 0;
void increment(){
    for(int i=0; i<50; i++){
        mtx.lock();
        counter++;
        std::cout<<"incrment: "<<counter<<std::endl;
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void decrement(){
    for(int i=0; i<50; i++){
        mtx.lock();
        counter--;
        std::cout<<"decrement: "<<counter<<std::endl;
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

int main() {
    std::thread thread1(increment);
    std::thread thread2(decrement);
	
	thread1.join();
	thread2.join();
	return 0;
}
