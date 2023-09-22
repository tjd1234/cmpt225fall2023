// loops.cpp

#include <iostream>
#include <string>

using namespace std;

void loop1(int N)
{
    int num_called = 0;
    for (int i = 0; i < N; i++)
    {
        num_called++;
    }
    cout << "loop1 num_called: " << num_called << "\n";
}

void loop2(int N)
{
    int num_called = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            num_called++;
        }
    }
    cout << "loop2 num_called: " << num_called << "\n";
}

void loop3(int N)
{
    int num_called = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            num_called++;
        }
    }
    cout << "loop3 num_called: " << num_called << "\n";
}

void loop4(int N)
{
    int num_called = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j % 2 == 0)
                num_called++;
        }
    }
    cout << "loop4 num_called: " << num_called << "\n";
}

void loop5(int N)
{
    int num_called = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N / 2; j++)
        {
            num_called++;
        }
    }
    cout << "loop5 num_called: " << num_called << "\n";
}

void loop6(int N)
{
    int num_called = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            num_called++;
        }
    }
    cout << "loop6 num_called: " << num_called << "\n";
}

void loop7(int N)
{
    int num_called = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                num_called++;
            }
        }
    }
    cout << "loop7 num_called: " << num_called << "\n";
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " N\n";
        return 1;
    }
    const int N = atoi(argv[1]);
    loop1(N);
    loop2(N);
    loop3(N);
    loop4(N);
    loop5(N);
    loop6(N);
    cout << "N = " << N << "\n";
}
