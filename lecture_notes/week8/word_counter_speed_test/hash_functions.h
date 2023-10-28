// hash_functions.h

#pragma once

#include <string>

using namespace std;

typedef unsigned int uint;

uint hash(const string &s)
{
    uint h = 7;
    for (char c : s)
    {
        h = h * 31 + c;
    }
    return h;
}
