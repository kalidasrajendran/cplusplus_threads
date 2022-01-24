#include <iostream>
#include <thread>
#include <string>
#include <chrono> 

using namespace std;
using namespace std::literals;

void print(string str)
{
    for (int i = 0; i < 5; i++)
    {
        cout << str[0] << str[1] << str[2] << endl;
        std::this_thread::sleep_for(50ms);
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