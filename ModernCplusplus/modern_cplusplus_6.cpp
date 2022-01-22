#include <iostream>
#include <string>
#include <vector>

using namespace std;



void func(int&& x)
{
    cout << "Rvalue reference " << endl;
}


void vec_func(vector<int> arg)
{
    cout << "Arg vector has: " << arg.size() << " elements" << endl;
}

int main()
{   
    int x = 10;
    int *p_to_i = &x;
    int **p_to_p_to_i = &p_to_i;

    cout << "x: " << x << endl; // 10
    cout << "p_to_i: " << p_to_i << endl; // 0x44a7fff740
    cout << "*p_to_i: " << *p_to_i << endl; // 10

    cout << "p_to_p_to_i: " << p_to_p_to_i << endl; // 0x44a7fff738
    cout << "*p_to_p_to_i: " << *p_to_p_to_i << endl; // 0x44a7fff740
    cout << "**p_to_p_to_i: " << *(*p_to_p_to_i) << endl; // 10

    int y{3};

    func(2);
    //func(y); //error: cannot bind rvalue reference of type 'int&&' to lvalue of type 'int'
    func(std::move(y));

    vector<int> vec(1000000);

    cout << "Before calling vec_func, vector has " << vec.size() << " elements" << endl;
    //vec_func(vec);
    vec_func(std::move(vec));
    cout << "After calling vec_func, vector has " << vec.size() << " elements" << endl;
}

/* result */
//   x: 10
//   p_to_i: 0x71ba3ff824
//   *p_to_i: 10
//   p_to_p_to_i: 0x71ba3ff818
//   *p_to_p_to_i: 0x71ba3ff824
//   **p_to_p_to_i: 10
//   Rvalue reference
//   Rvalue reference
//   Before calling vec_func, vector has 1000000 elements
//   Arg vector has: 1000000 elements
//   After calling vec_func, vector has 0 elements