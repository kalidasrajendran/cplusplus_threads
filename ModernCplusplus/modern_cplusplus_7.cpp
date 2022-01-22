#include <iostream>
#include <string>
#include <vector>

using namespace std;

void func(const int& x) 
{
    cout << "L value reference " << endl;
}

void func(int&& x) 
{
    cout << "R value reference " << endl;
}

int main()
{   

    int y = 2;

    cout << "Argument y: ";
    func(y);

    cout << "Argument move(y): ";
    func(std::move(y));

    cout << "Argument 2: ";
    func(2);


}

/* result */
//  Argument y: L value reference 
//  Argument move(y): R value reference
//  Argument 2: R value reference