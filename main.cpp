/*
    Main.cpp
    Joel Goodman, 2020
*/

#include <iostream>

#include "ScopeTimer.hpp"


auto factorial(const int& n)
{
    if(n < 1)
        return 0;
    else if(n == 1)
        return n;
    else
        return n * factorial(n - 1);
}


int main()
{
    using std::cout;

    {
        ScopeTimer st(ScopeTimer::Increment::Nanoseconds, "foo");
        const int n = 10;
        cout << n << "! = " << factorial(n) << '\n';
    }

}

