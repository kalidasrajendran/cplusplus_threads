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
    for (int i = 0; i < 5; i++)
    { 
        try
        {
            /* code */
            unique_lock<mutex> lk(print_mutex);
                   
            cout << str[0] << str[1] << str[2] << endl;              
            throw std::exception(); 
            lk.unlock();
            std::this_thread::sleep_for(10ms);               
        }
        catch(const std::exception& e)
        {
            //std::cerr << e.what() << "exception caught" << '\n';
        }
    }
    
}

int main()
{
    thread t1 { print, "123"};
    thread t2 { print, "456"};
    thread t3 { print, "789"};
    t1.join();
    t2.join();
    t3.join();
}