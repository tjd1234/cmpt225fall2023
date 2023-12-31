// singly_linked_list1.cpp

#include <cassert>
#include <iostream>

using namespace std;

string quote(string s)
{
    return "\"" + s + "\"";
}

struct Node
{
    string data;
    Node *next;
};

//
// head always points the the first node in the list.
// If head == nullptr, the list is empty.
//
Node *head = nullptr;

//
// returns true if the list is empty
//
bool empty()
{
    return head == nullptr;
}

//
// returns the number of items in the list
//
int size()
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
// prints the contents of the list to cout
//
void print()
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
// insert a new string at the front of the list
//
void push_front(const string &s)
{
    Node *n = new Node{s, head};
    head = n;
}

//
// remove the string at the front of the list and return it
//
string pop_front()
{
    assert(!empty());

    string s = head->data;
    Node *p = head;
    head = head->next;
    delete p;
    return s;
}

//
// removes all nodes from the list
//
void clear()
{
    while (!empty())
    {
        pop_front();
    }
}

int main()
{
    assert(size() == 0);

    // make a new node
    Node *n1 = new Node{"hello", nullptr};

    // make head point to it
    head = n1;
    assert(size() == 1);

    // print the data in the first node
    cout << "head->data = " << quote(head->data) << endl;

    // make another new node
    Node *n2 = new Node{"world", head}; // <-- different!
    head = n2;
    assert(size() == 2);

    // print the data in the first node
    cout << "head->data = " << quote(head->data) << endl;

    // print the data in the second node
    cout << "head->next->data = " << quote(head->next->data) << endl;

    print();

    //
    // de-allocate all memory allocated with new
    //
    // clear();
    // delete n1;
    // delete n2;
}
