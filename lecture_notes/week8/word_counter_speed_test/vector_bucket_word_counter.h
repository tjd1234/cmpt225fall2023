// vector_bucket_word_counter.h

// ❯ ./word_counter_speed_test tiny_shakespeare.txt
// Testing Vector_bucket_word_counter: array of vector buckets, hashing ... 
//     file           : tiny_shakespeare.txt
//     # unique words : 25670
//     # collisions   : 3741
//     table size     : 200000
//     elapsed seconds: 0.020132s

// ❯ ./word_counter_speed_test big_shakespeare.txt
// Testing Vector_bucket_word_counter: array of vector buckets, hashing ... 
//     file           : big_shakespeare.txt
//     # unique words : 67800
//     # collisions   : 36801
//     table size     : 200000
//     elapsed seconds: 0.094953s

#include "hash_functions.h"
#include "word_counter_base.h"
#include <cassert>
#include <vector>

using namespace std;

class Vector_bucket_word_counter : public Word_counter_base
{
    struct Node
    {
        string key;
        int value;
    };

    struct Bucket
    {
        vector<Node> values;
    };

    Bucket *arr = new Bucket[TABLE_SIZE];
    int sz = 0;

    //
    // Returns index of key in bucket b, -1 otherwise.
    //
    int search_bucket(int b, const string &key, uint &collision_count) const
    {
        assert(b >= 0 && b < TABLE_SIZE);
        vector<Node> &values = arr[b].values;
        for (int i = 0; i < values.size(); i++)
        {
            if (values[i].key == key)
            {
                return i;
            }
            collision_count++;
        }
        return -1;
    }

public:
    ~Vector_bucket_word_counter()
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
        return "Vector_bucket_word_counter: array of vector buckets, hashing";
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
    void add(const string &key, uint &collision_count)
    {
        uint h = ::hash(key);
        int b = h % TABLE_SIZE; // index of bucket
        int i = search_bucket(b, key, collision_count);
        if (i == -1)
        {
            arr[b].values.push_back({key, 1});
            sz++;
        }
        else
        {
            arr[b].values[i].value++;
        }
    }

    //
    // Pre-condition:
    //    contains(key) is true
    // Post-condition:
    //    returns a copy of the value associated with the given key
    //
    int get_count(const string &key, uint &collision_count) const
    {
        uint h = ::hash(key);
        int b = h % TABLE_SIZE; // index of bucket
        int i = search_bucket(b, key, collision_count);
        if (i == -1)
        {
            return 0;
        }
        else
        {
            return arr[b].values[i].value;
        }
    }

}; // class Vector_bucket_word_counter
