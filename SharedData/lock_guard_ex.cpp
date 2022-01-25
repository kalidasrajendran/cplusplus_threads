#include <iostream>
#include <thread>
#include <string>
#include <chrono> 
#include <mutex>

using namespace std;
using namespace std::literals;

mutex print_mutex;

void print(string str)
{
    try
    {
        /* code */
        print_mutex.lock();
        for (int i = 0; i < 5; i++)
        {        
            cout << str[0] << str[1] << str[2] << endl;   
            throw std::exception();     
        }
        print_mutex.unlock();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "exception caught" << '\n';
        print_mutex.unlock();
    }
    
    
}

void print1(string str)
{
    try
    {
        /* code */
        lock_guard<mutex> lg(print_mutex);
        for (int i = 0; i < 5; i++)
        {        
            cout << str[0] << str[1] << str[2] << endl;  
            this_thread::sleep_for(100ms);
            throw std::exception();      
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "exception caught" << '\n';
    }
    
}

int main()
{
    //thread t1 { print, "123"};
    //thread t2 { print, "456"};
    //thread t3 { print, "789"};
    //t1.join();
    //t2.join();
    //t3.join();

    thread t4 { print1, "123"};
    thread t5 { print1, "456"};
    thread t6 { print1, "789"};
    t4.join();
    t5.join();
    t6.join();
}