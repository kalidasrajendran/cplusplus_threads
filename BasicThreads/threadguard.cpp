#include <iostream>
#include <thread>
#include <string>
#include <chrono> 

using namespace std;
using namespace std::literals;


class thread_guard
{
    std::thread t;

    public:
        // constructor (std::thread is move-only)
        explicit thread_guard(std::thread&& t) : t(std::move(t)) {}

        // destructor
        ~thread_guard()
        {
            if (t.joinable()) // join thread if necessary
            {
                t.join();
            }
        }

        // delete copy constructor and copy assignment operator
        thread_guard(const thread_guard&) = delete;
        thread_guard& operator=(const thread_guard&) = delete;

        // provide move constructor and move assignment operator 
        thread_guard(thread_guard&&) noexcept = default;
        thread_guard& operator=(thread_guard&&) noexcept = default;
};

int main()
{
    std::thread t;
    thread_guard tg(std::move(t));

    // this program is a fail safe method to use thread and join the thread
    // when exception are involved it is necessary to join the thred in catch section
    // to avoid this threadguard is used

    return 0;
}


