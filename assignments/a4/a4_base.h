// a4_base.h

#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//
// For conveniently printing vectors using <<.
//
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    int n = v.size();
    os << "{";
    for (int i = 0; i < n; i++)
    {
        os << v[i];
        if (i < n - 1)
        {
            os << ", ";
        }
    }
    os << "}";
    return os;
}

//
// Sort_stats stores statistics about one run of a sorting routine.
//

// "ulong" is easier to type than "unsigned long"
typedef unsigned long ulong;

struct Sort_stats
{
    string sort_name;
    size_t vector_size = 0;
    ulong num_comparisons = 0;
    double cpu_running_time_sec = 0.0;

    //
    // Returns results formatted as a CSV line.
    // CSV = comma separated values
    //
    string to_csv() const
    {
        return sort_name + ", " + to_string(vector_size) + ", " + to_string(num_comparisons) + ", " + to_string(cpu_running_time_sec);
    }
}; // struct Sort_stats

//
// For conveniently printing Sort_stats objects using <<.
//
ostream &operator<<(ostream &os, const Sort_stats &ss)
{
    os << "Sort_stats{" << ss.sort_name
       << ", size=" << ss.vector_size
       << ", num_comparisons=" << ss.num_comparisons
       << ", cpu_running_time_sec=" << ss.cpu_running_time_sec
       << "}";
    return os;
}

//
// Pre-condition:
//    none
// Post-condition:
//    Returns true if v[0] <= v[1] <= ... <= v[n-1], and false otherwise.
//    Returns true if v is empty, i.e. an empty vector is considered sorted.
//
template <typename T>
bool is_sorted(vector<T> &v);

//
// Pre-condition:
//    n >= 0
//    min <= max
// Post-condition:
//    Returns a vector of n randomly chosen ints, each <= max and >= min.
//
vector<int> rand_vec(int n, int min, int max);

//////////////////////////////////////////////////////////////////////////////////
//
// Sorting algorithm headers.
//
// Each algorithm implements the named algorithm as described in the
// textbook/notes (iquick sort is described in the assignment), and returns a
// Sort_stats object containing statistics about the run.
//
// All the sorting functions have the same pre-conditions and post-conditions:
//
//    Pre-condition:
//       none
//    Post-condition:
//       v is permuted so that v[0] <= v[1] <= ... <= v[n-1]
//
//////////////////////////////////////////////////////////////////////////////////

template <typename T>
Sort_stats bubble_sort(vector<T> &v);

template <typename T>
Sort_stats insertion_sort(vector<T> &v);

template <typename T>
Sort_stats selection_sort(vector<T> &v);

//
// Important requirement: Shellsort must use this sequence of gaps: n/2, n/4,
// n/8, ..., 1.
//
// Do not use any other gap sequence!
//
// This sequence of gaps does *not* result in the most efficient version of
// shellsort (it is worst-case quadratic), but it does make it easier to compare
// it to the other algorithms.
//
template <typename T>
Sort_stats shell_sort(vector<T> &v);

template <typename T>
Sort_stats merge_sort(vector<T> &v);

template <typename T>
Sort_stats quick_sort(vector<T> &v);

//
// See description in assignment.
//
template <typename T>
Sort_stats iquick_sort(vector<T> &v);

//
// See description in assignment.
//
template <typename T>
Sort_stats priority_queue_sort(vector<T> &v);
