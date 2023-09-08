// linked_list_example.cpp

//
// Make a singly-linked list data structure that looks like this:
//
//  head --> "cat" --> "dog" --> "bird" --> nullptr
//

#include <iostream>
#include <string>

using namespace std;

//
// Step 1: Represent the Nodes of the List as a struct (class)
//
// Each item on the linked list stores a string and a pointer to the next item.
// We'll call these items "nodes", and represent them with a struct.
//
// Remember:
// - A struct is like a class, but with everything public by default.
// - A struct defines a type, just like int, double, string, etc. So we can make
//   values/variables of type Node, and also pointers to values of type Node.
// - To create a new Node, we'll use {}-notation:
//
//   Node* n = new Node{"cat", nullptr};
//

struct Node
{
    string data;
    Node *next;
};

//
// Step 2: Make a head pointer.
//
// We need to remember where the list starts. The head pointer always points to
// the first node on the list. If head == nullptr, then the list is empty.
//

Node *head = nullptr;

int main()
{
    //
    // Step 3: Make the "bird" node.
    //
    // Since it is the last item on the list, it's next pointer is nullptr.
    //
    head = new Node{"bird", nullptr};

    //
    // Step 4: Make the "dog" node, and connect it into the list like this:
    // - make it's next pointer point to the "bird" node
    // - make the head pointer point to the "dog" node
    //
    // Be careful! This step is simple but subtle! Make sure you understand it.
    //
    head = new Node{"dog", head};

    //
    // Step 5: Make the "cat" node, and connect it into the list like this:
    // - make it's next pointer point to the "dog" node
    // - make the head pointer point to the "cat" node
    //
    // Note how similar this statement is to the previous one that added "dog".
    //
    head = new Node{"cat", head};

    //
    // Step 6: Print the list one node at a time.
    //
    cout << head->data << endl;             // cat
    cout << head->next->data << endl;       // dog
    cout << head->next->next->data << endl; // bird

    //
    // At this point, if you run the program it prints cat, dog, bird. If you
    // run it with valgrind, you'll get an error reporting a memory leak:
    //
    //  > valgrind ./linked_list_example
    //
    // Remember: whenever you allocate memory using new, there must be a
    // corresponding call to delete to de-allocate. Forgetting to call delete is
    // known as a "memory leak".
    //

    //
    // Step 7a: Delete each node of the list, starting at the tail.
    //
    // The easiest way to delete the nodes in this particular example is to
    // delete them in reverse order from tail to head.
    //
    // delete head->next->next; // delete bird
    // delete head->next;       // delete dog
    // delete head;             // delete cat

    //
    // Step 7b: delete the list, head to tail order
    //
    // Here we delete the elements starting at the head and going to the tail.
    // While this is not as simple, it is the more common method of deletion in
    // practice because we don't need to know how long the list is. It only
    // requires the head pointer.
    //
    //    Node *p = head;    // p points to the Node we want to delete
    //    head = head->next; // make head point to the next Node
    //    delete p;          // delete the cat Node
    //
    //    p = head;          // p points to the Node we want to delete
    //    head = head->next; // make head point to the next Node
    //    delete p;          // delete the dog Node
    //
    //    p = head;          // p points to the Node we want to delete
    //    head = head->next; // make head point to the next Node
    //    delete p;          // delete the bird Node
    //

    //
    // Step 7c: Delete the list, in head to tail order, using a loop
    //
    // This is the same as 7b, but using a loop instead of writing the same
    // code three times. As long as head is not nullptr, we delete the first
    // node on the list using the same approach as in 7b.
    //
    //    while (head != nullptr)
    //    {
    //        Node *p = head;    // p points to the Node we want to delete
    //        head = head->next; // make head point to the next Node
    //        delete p;          // delete the bird Node
    //    }

} // main
