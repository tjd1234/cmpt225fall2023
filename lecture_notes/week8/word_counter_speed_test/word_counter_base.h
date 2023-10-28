// word_counter_base.cpp

#pragma once

#include <string>

using namespace std;

//
// Max table size
//
const int TABLE_SIZE = 200003; // 200003 is a prime number

typedef unsigned int uint;

class Word_counter_base
{
public:
    //
    // Base classes should always have a virtual destructor so that inheriting
    // classes can implement their own destructor.
    //
    virtual ~Word_counter_base() {}

    //
    // Pre-condition:
    //    none
    // Post-condition:
    //    Returns the name of this counter and a very brief description of the
    //    implementation (it should fit easily in a single line).
    //
    virtual string name() const = 0;

    //
    // Pre-condition:
    //    none
    // Post-condition:
    //    Returns the maximum number of words that can be added to this counter.
    //
    virtual int table_size() const = 0;

    //
    // Pre-condition:
    //    none
    // Post-condition:
    //    Returns number of words in this counter. If a word has been added more
    //    than once, it is only counted once.
    //
    virtual int num_words() const = 0;

    //
    // Pre-condition:
    //    none
    // Post-condition:
    //    If word is already in the counter, increment its count. Otherwise, add
    //    the word with a count of 0.
    //
    //    num_collisions is incremented by the number of collisions that occur
    //    when adding the word. For non-hash implementations this value doesn't
    //    mean anything can be any value.
    //
    virtual void add(const string &word, uint& num_collisions) = 0;

    //
    // Pre-condition:
    //    none
    // Post-condition:
    //    Returns the number of times word as been added.
    //
    //    num_collisions is incremented by the number of collisions that occur
    //    when adding the word. For non-hash implementations this value doesn't
    //    mean anything can be any value.
    //
    virtual int get_count(const string &word, uint& num_collisions) const = 0;

}; // class Word_counter_base
