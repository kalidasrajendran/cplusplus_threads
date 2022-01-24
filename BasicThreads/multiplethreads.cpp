#include <iostream>
#include <thread>
#include <string>
#include <chrono> 

using namespace std;

void hello(int num) 
{
    this_thread::sleep_for(std::chrono::seconds(num));
    cout << "Hello " << num << endl;
}

int main()
{
    thread t1 { hello, 1};
    thread t2 { hello, 2};
    thread t3 { hello, 3};

    t1.join();
    t2.join();
    t3.join();

    return 0;
}

/*
result: 
Hello Hello 3Hello 2
1

with sleep_for

Hello 1
Hello 2
Hello 3

*/