#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <chrono>

int GetFutureData(std::promise<int>& result){
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    result.set_value(5);
}


int main(){
    std::promise<int> p;
    std::future f = p.get_future();
    std::thread t(GetFutureData, std::ref(p));

    // Doing some operation while data is being processed in the child thread...
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout<<"main thread waited for 5s ... "<<std::endl;

    // Received processed data from child thread.....
    int val = f.get();
    std::cout<<"Data received from child thread: "<<val<<std::endl;

    /// Data processing takes place in parallel so both the couts take place
    /// in parallel
    
    return 0;
}
