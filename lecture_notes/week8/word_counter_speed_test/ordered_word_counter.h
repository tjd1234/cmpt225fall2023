// ordered_word_counter.h

//
// Slower than unordered_word_counter.h, maybe because of the add method which
// uses "swap" to insert the new word in the correct position. It might be
// faster to copy all the elements and then insert the new word in the correct
// position.
//

//
// Using add_copy with double swap.
//
// ❯ ./word_counter_speed_test big_shakespeare.txt
// Testing Ordered_word_counter: ordered array of pairs, no hashing ... 
//     file           : big_shakespeare.txt
//     # unique words : 67800
//     # collisions   : 0
//     table size     : 200000
//     elapsed seconds: 11.8412s

//
// Using add_copy with single swap.
//
// ❯ ./word_counter_speed_test big_shakespeare.txt
// Testing Ordered_word_counter: ordered array of pairs, no hashing ... 
//     file           : big_shakespeare.txt
//     # unique words : 67800
//     # collisions   : 0
//     table size     : 200000
//     elapsed seconds: 11.8335s

//
// Using add_swap with single swap.
//
// ❯ ./word_counter_speed_test big_shakespeare.txt
// Testing Ordered_word_counter: ordered array of pairs, no hashing ... 
//     file           : big_shakespeare.txt
//     # unique words : 67800
//     # collisions   : 0
//     table size     : 200000
//     elapsed seconds: 13.56s

//
// Using add_swap with double swap.
//
// ❯ ./word_counter_speed_test big_shakespeare.txt
// Testing Ordered_word_counter: ordered array of pairs, no hashing ... 
//     file           : big_shakespeare.txt
//     # unique words : 67800
//     # collisions   : 0
//     table size     : 200000
//     elapsed seconds: 8.3489s

#include "word_counter_base.h"
#include <cassert>

using namespace std;

class Ordered_word_counter : public Word_counter_base
{
    struct Node
    {
        string key;
        int value;
    };

    Node *arr = new Node[TABLE_SIZE];
    int sz = 0;

    //
    // Using binary search, returns the index of s in the array, or -1 if s is
    // not in the array.
    //
    int get_index(const string &s) const
    {
        int begin = 0; // first index of range
        int end = sz;  // one past last index of range

        while (begin < end)
        {
            int mid = (begin + end) / 2;
            if (s == arr[mid].key)
            {
                return mid;
            }
            else if (s < arr[mid].key)
            {
                end = mid;
            }
            else
            {
                begin = mid + 1;
            }
        }
        return -1; // s not found
    }

public:
    //
    // Base classes should always have a virtual destructor so that inheriting
    // classes can implement their own destructor.
    //
    ~Ordered_word_counter()
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
        return "Ordered_word_counter: ordered array of pairs, no hashing";
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
        add_copy(key, num_collisions);
    }

    void add_swap(const string &key, uint &num_collisions)
    {
        num_collisions = 0;
        int i = get_index(key);
        if (i == -1)
        { // append new value to end
            // Add the new word to the end of the array, and then repeatedly
            // swap the new word with the word to its left until the new word is
            // in the correct position.
            arr[sz].key = key;
            arr[sz].value = 1;
            int i = sz;
            while (i > 0 && arr[i - 1].key > arr[i].key)
            {
                // swap(arr[i - 1], arr[i]);
                //
                // may be faster to do two swaps instead of one swap as above
                swap(arr[i - 1].key, arr[i].key);
                swap(arr[i - 1].value, arr[i].value);

                i--;
            }
            sz++;
        }
        else
        { // overwrite old value
            arr[i].value++;
        }
    }

    void add_copy(const string &key, uint &num_collisions)
    {
        num_collisions = 0;
        int i = get_index(key);
        if (i == -1)
        { // append new value to end
            // Starting at the end of the array, repeatedly copy one element
            // from the until a value <= key is found. Then copy the new word
            // into the empty location.
            int i = sz;
            while (i > 0 && arr[i - 1].key > key)
            {
                // arr[i] = arr[i - 1];
                //
                // may be faster to do two swaps instead of one swap as above
                arr[i].key = arr[i - 1].key;
                arr[i].value = arr[i - 1].value;

                i--;
            }
            arr[i].key = key;
            arr[i].value = 1;

            sz++;
        }
        else
        { // increment existing value
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

}; // class Ordered_word_counter
