#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main()
{   
    vector<int> v{1,2,3,4,5,6,7,8};

    for (auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;

    for (auto it : v) 
        cout << it << " ";    
    cout << endl;
    
    for (auto &it : v) 
        it *= 2;

    for (auto it : v) 
        cout << it << " ";    
    cout << endl;

}