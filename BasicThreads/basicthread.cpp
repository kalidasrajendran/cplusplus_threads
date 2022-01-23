#include <iostream>
#include <thread>
#include <string>
#include <chrono> 

using namespace std;
using namespace std::literals;

void func()
{
    cout << "Hello thread!" << endl;
}

void func_str(string data)
{
    cout << "Hallo: " << data << endl;
}

void func_passreferences(string& data)
{
    data = "mike";
}

void func_r_value_references(string&& data)
{
    cout << "ownership of \"" << data << "\" transferred to thread" << endl;
}

class greet
{
    public:
        void hello()
        {
            cout << "Member function of class greet" << endl;
        }
};

int main()
{
    // func();

    thread t{ func };
    cout << "Doing dome work..." << endl;
    t.join();

    thread t2{ func_str, "kalidas" };
    t2.join();

    string s1{"john"};
    cout << "old name: " << s1 << endl;
    thread t3{ func_passreferences, std::ref(s1) };
    t3.join();
    cout << "new name: " << s1 << endl;

    string s2{"kalidas"};
    thread t4{ func_r_value_references, std::move(s2) };
    t4.join();
    cout << "string is now " << s2 << endl;

    greet g1;

    thread t5{ &greet::hello, &g1 };
    t5.join();

    thread t6{ []() { cout << "hello lambda" << endl;}};
    t6.join();

    string s7{"john"};
    cout << "lambda function old name: " << s7 << endl;
    thread t7{ [&s7]() { s7 = "mike";} };

    // std::this_thread::sleep_for(50ms);
    std::this_thread::sleep_for(5s);

    t7.join();
    cout << "lambda function new name: " << s7 << endl;

    return 0;
}


