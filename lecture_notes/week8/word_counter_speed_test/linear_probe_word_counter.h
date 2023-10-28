// linear_probe_word_counter.h

// ❯ ./word_counter_speed_test tiny_shakespeare.txt
// Testing Linear_probe_word_counter: hashing with linear probing ... 
//     file           : tiny_shakespeare.txt
//     # unique words : 25670
//     # collisions   : 4454
//     table size     : 200000
//     elapsed seconds: 0.018768s

// ❯ ./word_counter_speed_test big_shakespeare.txt
// Testing Linear_probe_word_counter: hashing with linear probing ... 
//     file           : big_shakespeare.txt
//     # unique words : 67800
//     # collisions   : 65493
//     table size     : 200000
//     elapsed seconds: 0.08067s

#include "hash_functions.h"
#include "word_counter_base.h"
#include <cassert>
#include <vector>

using namespace std;

class Linear_probe_word_counter : public Word_counter_base
{
    struct Node
    {
        string key;
        int count;
        bool empty = true;
    };

    Node *arr = new Node[TABLE_SIZE];
    int sz = 0;

    //
    // Returns index of key using linear probing. If key is not in the table,
    // returns the index of where it would be.
    //
    // Assumes the table is not full.
    //
    int get_index(const string &key, uint &num_collisions) const
    {
        assert(num_words() < TABLE_SIZE);
        uint h = ::hash(key);
        int i = h % TABLE_SIZE;
        for (;;)
        {
            if (arr[i].empty)
            {
                return i;
            }
            else if (arr[i].key == key)
            {
                return i;
            }
            num_collisions++;
            i = (i + 1) % TABLE_SIZE;
        }
    }

public:
    ~Linear_probe_word_counter()
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
        return "Linear_probe_word_counter: hashing with linear probing";
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
    //    returns number of items in the map
    //
    int num_words() const
    {
        return sz;
    }

    //
    // Pre-condition:
    //    none
    // Post-condition:
    //    If key is already in the counter, increment its count. Otherwise, add
    //    key with a count of 0.
    //
    void add(const string &key, uint &num_collisions)
    {
        int i = get_index(key, num_collisions);
        if (arr[i].empty)
        { // add a new word
            arr[i] = Node{key, 1, false};
            sz++;
        }
        else
        { // update count of existing word
            arr[i].count++;
        }
    }

    //
    // Pre-condition:
    //    none
    // Post-condition:
    //    returns the number of times key as added
    //
    int get_count(const string &key, uint &num_collisions) const
    {
        int i = get_index(key, num_collisions);
        if (arr[i].empty)
        {
            return 0;
        }
        else
        {
            return arr[i].count;
        }
    }

}; // class Linear_probe_word_counter
