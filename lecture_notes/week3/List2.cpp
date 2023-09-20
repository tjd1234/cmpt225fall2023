// List2.cpp

#include "List_base.h"
#include <cassert>
#include <iostream>

using namespace std;

string quote(string s)
{
    return "\"" + s + "\"";
}

//
// The List class inherits from List_base, and therefore must implement all of
// its methods.
//

class List : public List_base
{
    // private

    struct Node
    {
        string data;
        Node *next;
    };

    //
    // head always points the the first node in the list.
    // nullptr means the list is empty.
    //
    Node *head = nullptr;

public:
    // Default constructor, i.e. a constructor that takes no inputs It is empty
    // because we've already initialized head to nullptr above in the private
    // part.
    List() {}

    //
    // Returns true if the list is empty, and false otherwise.
    //
    bool empty() const
    {
        return head == nullptr;
    }

    //
    // Returns the number of node in the list.
    //
    int size() const
    {
        int count = 0;
        Node *p = head;
        while (p != nullptr)
        {
            count++;
            p = p->next;
        }
        return count;
    }

    //
    // Prints the contents of the list to cout.
    //
    void print() const
    {
        cout << "List: ";
        Node *p = head;
        while (p != nullptr)
        {
            cout << quote(p->data) << " ";
            p = p->next;
        }
        cout << endl;
    }

    //
    // Inserts a new string at the front of the list.
    //
    void push_front(const string &s)
    {
        head = new Node{s, head};
    }

    //
    // Removes the first node from the list and returns a copy of its string.
    //
    // If the list is empty, it crashes due to the assert failing.
    //
    string pop_front()
    {
        assert(!empty()); // causes a crash if !empty() is false
        string s = head->data;
        Node *p = head;
        head = head->next;
        delete p;
        return s;
    }

    //
    // Return a copy the string in the first node in the list. The list is not
    // modified.
    //
    // If the list is empty, it crashes due to the assert failing.
    //
    string peek_front() const
    {
        assert(!empty()); // causes a crash if !empty() is false
        return head->data;
    }

    //
    // Remove all nodes from the list.
    //
    // Note: clear() is inherited from List_base and we don't need to write it
    // again here. Try commenting this out and you'll see the main program still
    // works.
    //
    // void clear()
    // {
    //     while (!empty())
    //     {
    //         pop_front();
    //     }
    // }

    //
    // Destructor: delete all the nodes on the list.
    //
    // Automatically called when the List object goes out of scope, or it is
    // deleted.
    //
    ~List()
    {
        clear();
        cout << "List destructor called" << endl;
    }

    //
    // get(int i) is an example of a method that is not in the List_base class.
    //
    // Returns a copy of the string in the node at the given index. The first
    // node is index 0, the second is index 1, etc.
    //
    // If the index i is not a valid range, it crashes due to the assert
    // failing.
    //
    // Note that the time it takes for get(i) to run is proportional to i. The
    // bigger i is, the further down the list the loop must traverse. In
    // contrast, get the ith element of an array takes the same amount of time
    // no matter what i is.
    //
    string get(int i) const
    {
        // 0 <= i && i < size() must be true, otherwise the assert crashes the
        // program
        assert(0 <= i && i < size());

        //
        // p starts at the first node, and count is 0. We move p i nodes through
        // the list
        //
        Node *p = head;
        int count = 0;

        while (count < i)
        {
            p = p->next;
            count++;
        }
        // goal: p is pointing to the node with index i

        return p->data;
    }

}; // List

//
// Test if two lists are equal, i.e. they are the same length and have the same
// elements in the same order.
//
// Note that this is a function, not a method.
//
bool operator==(const List &lst1, const List &lst2)
{
    if (lst1.size() != lst2.size())
    {
        return false;
    }

    for (int i = 0; i < lst1.size(); i++)
    {
        if (lst1.get(i) != lst2.get(i))
        {
            return false;
        }
    }

    return true;
}

//
// Test if two lists are not equal.
//
// Note that this is a function, not a method.
//
bool operator!=(const List &lst1, const List &lst2)
{
    return !(lst1 == lst2);
}

//
// assert is used to help automatically test the correctness of List.
//
int main()
{
    List lst1;
    assert(lst1 == lst1);
    lst1.push_front("ant");
    assert(lst1.size() == 1);
    assert(!lst1.empty());

    lst1.push_front("beetle");
    assert(lst1.size() == 2);
    assert(!lst1.empty());

    lst1.push_front("caterpillar");
    assert(lst1.size() == 3);
    assert(!lst1.empty());

    assert(lst1 == lst1);
    lst1.print();

    cout << "The first string is: " << lst1.peek_front() << endl;
    lst1.pop_front();
    assert(lst1.size() == 2);
    lst1.print();
    cout << "The first string is: " << lst1.peek_front() << endl;

    List lst2;
    assert(lst2.empty());
    assert(lst2.size() == 0);

    assert(lst1 != lst2);
    lst1.clear();
    assert(lst1.empty());
    assert(lst1.size() == 0);
    assert(lst1 == lst2);

    lst2.push_front("sun");
    lst2.push_front("moon");
    assert(lst2.size() == 2);
    assert(lst2.get(0) == "moon");
    assert(lst2.get(1) == "sun");

    cout << "There are " << lst2.size() << " strings in lst2" << endl;

    for (int i = 0; i < lst2.size(); i++)
    {
        cout << "lst2.get(" << i << "): " << quote(lst2.get(i)) << endl;
    }

} // main
