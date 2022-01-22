#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{   
    int x{7};              // x = 7;
    string s{"Let us begin modern c++"}; // s = "Let us begin modern c++"
    cout << "X = " << x << endl;
    cout << "S = " << s << endl;

    // Narrowing convrsions are not allowed
    int y = 7.7;
    //int y{7.7}; // y = gives a error message;
    cout << "Y = " << y << endl;

    vector <int> v{1,2,3,4,5,6,7};
    string hello{'h', 'e', 'l', 'l', 'o'}; // initialize string with individual characters

    cout << "v = ";
    for (vector <int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "hello = " << hello << endl;
}
/* result */
//  X = 7
//  S = Let us begin modern c++
//  Y = 7
//  v = 1 2 3 4 5 6 7
//  hello = hello