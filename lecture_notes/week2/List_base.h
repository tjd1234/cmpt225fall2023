// List_base.h

//
// An example of how to use an abstract base class to implement a list abstract
// data type (ADT).
//

#pragma once

#include <string>

using namespace std;

//
// List_base is an abstract base class representing an abstract data type (ADT)
// of a list.
//
// Its methods are:
//
// - virtual, so that classes that inherit from List_base can implement their
//   own versions of its methods
// - abstract, meaning they have no implementation; in C++ this is indicated by
//   putting "= 0" at the end of the method declaration
//
class List_base
{
public:
    //
    // Pre-condition:
    //    none
    // Post-condition:
    //    Returns true if the list is empty, and false otherwise.
    virtual bool empty() const = 0;

    //
    // Pre-condition:
    //    none
    // Post-condition:
    //    Returns the number of nodes in the list.
    virtual int size() const = 0;

    //
    // Pre-condition:
    //    none
    // Post-condition:
    //    Prints the contents of the list to cout.
    //
    virtual void print() const = 0;

    //
    // Pre-condition:
    //    none
    // Post-condition:
    //    A new node is created with data a copy of s, and inserted at the front
    //    of the list.
    //
    virtual void push_front(const string &s) = 0;

    //
    // Pre-condition:
    //    The list is not empty.
    // Post-condition:
    //    The first node is removed from the list, and a copy of its value is
    //    returned.
    //
    virtual string pop_front() = 0;

    //
    // Pre-condition:
    //    The list is not empty.
    // Post-condition:
    //    A copy of the string in the first node in the list is returned.
    //
    virtual string peek_front() const = 0;

    //
    // Remove all nodes from the list.
    //
    // This particular method can be efficiently written in terms of the other
    // methods in this class, so we give it a body.
    //
    // Since it is virtual, an inheriting class can, if it chooses, to over-ride
    // this implementation and provide its own.
    //
    // Pre-condition:
    //    none
    // Post-condition:
    //    The list is empty.
    // Note:
    //    Can be efficiently written in terms of the other methods in this
    //    class, so we give it a body.
    //
    //    Since it is virtual, an inheriting class can, if it chooses, to
    //    over-ride this implementation and provide its own.
    //
    virtual void clear()
    {
        while (!empty())
        {
            pop_front();
        }
    }

    //
    // destructor
    //
    // Pre-condition:
    //    none
    // Post-condition:
    //    All nodes in the list are deleted.
    // Note:
    //    Destructors are called automatically when its object is deleted.
    //
    //    In C++, a base class should always declare a virtual destructor.
    //    Otherwise, you can have problems calling the right destructor in
    //    inheriting classes.
    //
    virtual ~List_base() { }

}; // class List_base
