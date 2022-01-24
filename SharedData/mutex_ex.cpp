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
    print_mutex.lock();
    for (int i = 0; i < 5; i++)
    {        
        cout << str[0] << str[1] << str[2] << endl;        
    }
    print_mutex.unlock();
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