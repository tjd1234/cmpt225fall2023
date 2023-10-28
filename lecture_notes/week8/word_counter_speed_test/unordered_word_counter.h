// unordered_word_counter.h

// ❯ time ./word_counter_speed_test < tiny_shakespeare.txt
// Unordered_word_counter: array of pairs, no hashing:
//    # unique words: 25670
//    # collisions  : 0
//
// ________________________________________________________
// Executed in    1.38 secs   fish           external
//    usr time  1352.47 millis  313.00 micros  1352.16 millis
//    sys time    0.56 millis  555.00 micros    0.00 millis

// ❯ time ./word_counter_speed_test < big_shakespeare.txt
// Unordered_word_counter: array of pairs, no hashing:
//    # unique words: 67800
//    # collisions  : 0
//
// ________________________________________________________
// Executed in   12.22 secs   fish           external
//    usr time   11.96 secs    0.00 micros   11.96 secs
//    sys time    0.03 secs  812.00 micros    0.03 secs

#include "word_counter_base.h"

using namespace std;

class Unordered_word_counter : public Word_counter_base
{
    struct Node
    {
        string key;
        int value;
    };

    Node *arr = new Node[TABLE_SIZE];
    int sz = 0;

    //
    // Returns the index of s in the array, or -1 if s is not in the array.
    //
    int get_index(const string &s) const
    {
        for (int i = 0; i < sz; i++)
        {
            if (arr[i].key == s)
            {
                return i;
            }
        }
        return -1;
    }

public:
    //
    // Base classes should always have a virtual destructor so that inheriting
    // classes can implement their own destructor.
    //
    ~Unordered_word_counter()
    {
        delete[] arr;
    }

    //
    // Pre-condition:
    //    none
    // Post-condition:
    //    Returns the name of the implementation for this counter.
    //
    string name() const
    {
        return "Unordered_word_counter: unordered array of pairs, no hashing";
    }

    //
    // Pre-condition:
    //    none
    // Post-condition:
    //    Returns the maximum number of words that can be added to this counter.
    //
    int table_size() const
    {
        return TABLE_SIZE;
    }

    //
    // Pre-condition:
    //    none
    // Post-condition:
    //    Returns number of words in this counter. If a word has been added more
    //    than once, it is only counted once.
    //
    int num_words() const
    {
        return sz;
    }

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
    void add(const string &key, uint &num_collisions)
    {
        num_collisions = 0;
        int i = get_index(key);  // linear time
        if (i == -1)
        { // append new value to end
            arr[sz] = Node{key, 1};
            sz++;
        }
        else
        { // overwrite old value
            arr[i].value++;
        }
    }

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
    int get_count(const string &key, uint &num_collisions) const
    {
        num_collisions = 0;
        int i = get_index(key);
        if (i == -1)
        {
            return 0;
        }
        else
        {
            return arr[i].value;
        }
    }

}; // class Unordered_word_counter
