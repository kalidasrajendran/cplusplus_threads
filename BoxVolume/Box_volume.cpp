#include <iostream>

#include "BoxClass.h"

using namespace std;

/* function template */
int getvolume();

int main()
{   
    getvolume();
}

int getvolume()  
{
    Box Box1;        // Declare Box1 of type Box
    Box Box2;        // Declare Box2 of type Box
    double volume = 0.0;

    // box 1 specification
    Box1.height = 5.0; 
    Box1.length = 6.0; 
    Box1.breadth = 7.0;

    // box 2 specification
    Box2.height = 10.0;
    Box2.length = 12.0;
    Box2.breadth = 13.0;

    int number;
    number = 10 + 20;
    cout << "number is: " << number << endl;
    cout << "good bye!" << endl;
    
    // volume of box 1
    volume = Box1.height * Box1.length * Box1.breadth;
    cout << "Volume of Box1 : " << volume <<endl;
    cout << "Volume of Box1 use getvolume function: " << Box1.getVolume() <<endl;
    
    // volume of box 2
    volume = Box2.height * Box2.length * Box2.breadth;
    cout << "Volume of Box2 : " << volume <<endl;

    /* compile multiple files */
    // g++ -g3 HelloWorld.cpp person.cpp -o b.exe
    // g++ -g3 *\.cpp" -o b.exe
    // g++ -g $(find D:\1_Learning\C_C++\Programs\HelloWorld -type f -iregex ".*\.cpp") -o b.exe

    return 0;
}
