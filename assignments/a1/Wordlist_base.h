// Wordlist_base.h

#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Wordlist_base
{
    //
    // Pre-condition:
    //    none
    // Post-condition:
    //    Virtual destructor: de-allocate all memory allocated by the class.
    // Performance:
    //    It's worst-case running time should be proportional to the length of
    //    the list (or better).
    //
    virtual ~Wordlist_base() {}

    //
    // Pre-condition:
    //    none
    // Post-condition:
    //    Returns true if this list is frozen, false otherwise. A frozen list
    //    cannot be modified.
    // Performance:
    //    It's worst-case running time should be constant (i.e. the same no
    //    matter how long the list is).
    //
    virtual bool is_frozen() const = 0;

    //
    // Pre-condition:
    //    none
    // Post-condition:
    //    Returns true if w is in the word list, false otherwise.
    // Performance:
    //    It's worst-case running time should be proportional to the length of
    //    the list (or better).
    //
    virtual bool contains(const string &w) const = 0;

    //
    // Pre-condition:
    //    none
    // Post-condition:
    //    Returns the total number of nodes in the list.
    // Performance:
    //    It's worst-case running time should be constant (i.e. the same no
    //    matter how long the list is).
    //
    virtual int length() const = 0;

    //
    // Pre-condition:
    //    length() > 0
    // Post-condition:
    //    Returns a copy of the first word of the list.
    // Performance:
    //    It's worst-case running time should be constant (i.e. the same no
    //    matter how long the list is).
    //
    string first_word() const     {
        if (length() == 0)
        {
            throw runtime_error("first_word: empty list has no first word");
        }
        return get_word(0);
    }

    //
    // Pre-condition:
    //    length() > 0
    // Post-condition:
    //    Returns a copy of the  word of the list.
    // Performance:
    //    It's worst-case running time should be proportional to the length of
    //    the list (or better).
    //
    string last_word() const
    {
        if (length() == 0)
        {
            throw runtime_error("last_word:empty list has no last word");
        }
        return get_word(length() - 1);
    }

    //
    // Pre-condition:
    //    0 <= index < length()
    // Post-condition:
    //    Returns a copy of the word at the given index.
    // Performance:
    //    It's worst-case running time should be proportional to the length of
    //    the list (or better).
    //
    virtual string get_word(int index) const = 0;

    //
    // Pre-condition:
    //    !is_frozen()
    // Post-condition:
    //    If w is not in the list already, adds w to the end of the list.
    //    If w is already in the list, does nothing.
    // Performance:
    //    It's worst-case running time should be proportional to the length of
    //    the list (or better).
    //
    virtual void add_word(const string &w) = 0;

    //
    // Pre-condition:
    //    !is_frozen()
    // Post-condition:
    //    Removes all occurrences of w from the word list. If w is not in the
    //    list, then does nothing.
    // Performance:
    //    It's worst-case running time should be proportional to the length of
    //    the list (or better).
    //
    virtual void remove_word(const string &w) = 0;

    //
    // Pre-condition:
    //    none
    // Post-condition:
    //    Freezes the word list.
    //
    //    Then returns a vector of pointers to each word in the word list,
    //    sorted in alphabetical order.
    //
    //    Does not modify the word list.
    //
    // Performance:
    //    It's worst-case running time should be proportional to the square of
    //    the length of the list (or better).
    //
    virtual vector<string *> get_sorted_index() = 0;
}; // struct Wordlist_base
