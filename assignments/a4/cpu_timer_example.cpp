// cpu_timer_example.cpp

//
// Example of how to measure CPU time using clock().
//

#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    //
    // Simple way to measure CPU time used.
    //
    clock_t start_time = clock();

    string result;
    string s = "this is a test, this is only a test";
    for (int i = 0; i < 10000000; i++)
    {
        result += s + s;
    }

    clock_t end_time = clock();
    double elapsed_cpu_sec = double(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "Elapsed CPU time: " << elapsed_cpu_sec << " seconds" << endl;
}
