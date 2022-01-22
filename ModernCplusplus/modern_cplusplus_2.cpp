#include <iostream>
#include <string>
#include <vector>

using namespace std;

void func(int i)
{
    cout << "func(int) is called" << endl;
}

void func(int *i)
{
    cout << "func(int *) is called" << endl;
}

int main()
{   
    //func(NULL); error will occur because NULL is ambiguous
    func(nullptr); // runs without error; assumes it is an pointer
}

/* result */
// func(int *) is called