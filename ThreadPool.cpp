
#include <iostream>
#include <thread>
#include <condition_variable>
#include <functional>
#include <queue>
#include <vector>
// #include <unique_lock>

class ThreadPool{
    public:
        ThreadPool(int num_threads = std::thread::hardware_concurrency()){
            for(int i=0; i<num_threads; i++){
                // Push a new thread which to the thread-pool "threads_"
                // which will pop a task from the queue and execute the same. 
                threads_.emplace_back(
                    // The function which will continuously check if there 
                    // is any task enqueued in the queue "tasks_"
                    [this]{
                        while(true){
                            std::function<void()> task;

                            // Lock the popping from the queue using mutex
                            std::unique_lock<std::mutex> locker(mtx_);

                            // Wait till a task comes or the pool is stopped
                            cv_.wait(locker, [this]{
                                return !tasks_.empty() || stop_thread_; 
                            });

                            // If there is no tasks to perform and thread needs to be stopped
                            // then just return from the thread.
                            if(stop_thread_ && tasks_.empty())
                                return;
                            
                            // POP the task enqueued in the tasks_ queue
                            // std::function cannot be copied and can only be moved. Hence use std::move
                            task = std::move(tasks_.front());
                            tasks_.pop();

                            // perform the task
                            task();
                        }
                    }
                );
            }
        }
        ~ThreadPool(){
            // Stop all threads
            std::unique_lock<std::mutex> locker(mtx_);
            stop_thread_ = true;

            // activate all threads such that they all return cleanly
            cv_.notify_all();

            for(auto &thread: threads_)
                thread.join();

        }
        void enqueueTask(std::function<void()> func){
            std::unique_lock<std::mutex> locker(mtx_);
            tasks_.emplace(func);
            cv_.notify_one();
        }
    
    private:
        std::vector<std::thread> threads_;
        std::queue<std::function<void()>> tasks_;
        std::condition_variable cv_;
        std::mutex mtx_;
        bool stop_thread_ = false;   
};

int main()
{
    ThreadPool pool(4);

    // Enqueue tasks for execution
    for (int i = 0; i < 5; ++i) {
        pool.enqueueTask([i] {
            std::cout << "Task " << i << " is running on thread "
                 << std::this_thread::get_id() << std::endl;
            // Simulate some work
            std::this_thread::sleep_for(
                std::chrono::milliseconds(100));
        });
    }

    return 0;
}
