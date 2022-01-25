#include <iostream>
#include <thread>
#include <string>
#include <chrono> 
#include <mutex>

using namespace std;
using namespace std::literals;

recursive_mutex r_mutex;
mutex n_mutex;

int bad_factorial(int n) {
    if (n <= 1)
    {
        cout << "Returning " << 1 << endl;
        return 1;
    }
    
    lock_guard<recursive_mutex> lg(r_mutex);
    // lock_guard<mutex> lg(n_mutex); program will ot run
    int retval = n * bad_factorial(n - 1);
    cout << "Returning " << retval << endl;
    return retval;
}

int main()
{
    thread t1 { bad_factorial, 10};
    thread t2 { bad_factorial, 11};
    t1.join();
    t2.join();
    return 0;
}

/*----------------------------------------------------------------
// result

Returning 1
Returning 2
Returning 6
Returning 24
Returning 120
Returning 720
Returning 5040
Returning 40320
Returning 362880
Returning 3628800
Returning 1
Returning 2
Returning 6
Returning 24
Returning 120
Returning 720
Returning 5040
Returning 40320
Returning 362880
Returning 3628800
Returning 39916800


*/