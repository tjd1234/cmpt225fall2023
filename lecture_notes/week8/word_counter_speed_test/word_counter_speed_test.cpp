// word_counter_speed_test.cpp

#include "linear_probe_word_counter.h"
#include "ordered_word_counter.h"
#include "quadratic_probe_word_counter.h"
#include "unordered_word_counter.h"
#include "vector_bucket_word_counter.h"
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    uint collisions = 0;
    // Unordered_word_counter wc;
    // Ordered_word_counter wc;
    // Vector_bucket_word_counter wc;
    Linear_probe_word_counter wc;
    // Quadratic_probe_word_counter wc;

    cout << "Testing " << wc.name() << " ... " << endl;

    //
    // open text file
    //
    const string filename = argv[1];
    ifstream infile(filename);
    if (!infile)
    {
        cerr << "Could not open \"" << filename << "\"." << endl;
        return 1;
    }

    cout << "    file           : " << filename << endl;

    //
    // add words
    //
    clock_t start_time = clock();

    string word;
    while (infile >> word)
    {
        wc.add(word, collisions);
    }

    //
    // check for all existing words
    //
    infile.seekg(ios::beg); // go back to start of infile
    while (infile >> word)
    {
        if (wc.get_count(word, collisions) == 0)
        {
            cout << "Error: \"" << word << "\" not found" << endl;
            return 1;
        }
        //
        // "8824" is a string we know is not in any of the input files, and so
        // appending it to a word makes a string we know won't be found.
        //
        if (wc.get_count(word + "8824", collisions) > 0)
        {
            cout << "Error: \"" << word << "\" found (should not be there)" << endl;
            return 1;
        }
    }

    clock_t end_time = clock();
    double elapsed_cpu_sec = double(end_time - start_time) / CLOCKS_PER_SEC;

    //
    // print results
    //
    cout << "    # unique words : " << wc.num_words() << endl;
    cout << "    # collisions   : " << collisions << endl;
    cout << "    table size     : " << wc.table_size() << endl;
    cout << "    elapsed seconds: " << elapsed_cpu_sec << "s" << endl;
} // main
