// hello_world.cpp

#include "cmpt_error.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello! How old are you? ";
    int age = 0;

    cin >> age;

    if (age <= 0)
    {
        cmpt::error("invalid age");
    }

    cout << "That is pretty old!\n";
}
