#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct A
{
    int *int_ptr;
    // constructor
    A()
    { 
        cout << "constructor called" << endl;  
        int_ptr = new int;
    }

    // copy constructor
    A (const A &a1)
    {
        cout << "copy constructor called" << endl;
        this->int_ptr = new int;
    }

    // move constructor
    A (A && a1)
    {
        cout << "move constructor called" << endl;
        this->int_ptr = a1.int_ptr;
        a1.int_ptr = nullptr;
    }

    ~A()
    {
        cout << "destructor called" << endl; 
    }
};

int main()
{   
    vector<A> v1;

    v1.push_back(A());

    return 0;
}

/* result */
// constructor called
// move constructor called
// destructor called
// destructor called