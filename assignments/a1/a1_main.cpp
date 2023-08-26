// a1_main.cpp

//
// You can change this file in any way you like.
//
// Thoroughly test your Wordlist class to make sure it is correct.
//

#include "Wordlist_sol.h"
#include "test.h"

void read_from_terminal()
{
    Wordlist lst;
    string w;
    while (cin >> w)
    {
        lst.add_word(w);
    }

    // print the words in sorted order
    vector<string *> index = lst.get_sorted_index();
    for (int i = 0; i < index.size(); i++)
    {
        cout << (i + 1) << ". " << *index[i] << endl;
    }
}

void test_Wordlist()
{
    Test("test_Wordlist");

    Wordlist lst;
    assert(!lst.is_frozen());
    assert(lst.length() == 0);
    assert(!lst.contains("hello"));

    //
    // Add more test cases here. Use assert or if-statements to automatically
    // check the correctness of your code.
    //

} // test_Wordlist

int main()
{
    // test_Wordlist();
    // read_from_terminal();
}
