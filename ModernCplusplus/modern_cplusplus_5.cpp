#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_even(int n) 
{ 
    return (n % 2 == 0);
}

int main()
{   
    vector<int> v{1,2,3,4,5,6,7,8};

    cout << "Elements of vector" << endl;

    for (auto it : v)
        cout << it << " "; 
    cout << endl;

    // count_if is part of algorithm header
    auto n_even = count_if(v.begin(), v.end(), is_even);
    cout << "even count: " << n_even << endl;

    // lambda expressions 
    auto lambda_even = count_if(v.begin(), v.end(), 
        [] (int n)
        {
            return (n % 2 == 0);
        });
    cout << "lambda even count: " << lambda_even << endl;

    int radix{3};

    auto by_three = count_if(v.begin(), v.end(), 
        [radix] (int n)
        {
            return (n % radix == 0);
        });
    cout << "divisible by 3 count: " << by_three << endl;

    return 0;
}

/* result */
//  Elements of vector
//  1 2 3 4 5 6 7 8
//  even count: 4
//  lambda even count: 4
//  divisible by 3 count: 2