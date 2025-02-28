/* Include iostream library */
#include <iostream>
/* Using cout from standard library so that we can
write cout instead of std::cout every single time */
using std::cout;

int main()
{
    cout << "Hey Sherry" << std::endl;

    return 0;
}


/* Build and Debugging notes */
/* To build: g++ file.cpp or ... > Terminal > Run Task
   To Execute: ./file.exe 
   To build and debug: Fn F5
   To compile .cpp with debugging symbols: g++ -g file.cpp
   To run gdb on the o/p: gdb a.out*/