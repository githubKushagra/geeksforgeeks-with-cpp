#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;


// insert in a sorted list - so i have first sorted it and then insert it.
// linked-list using class

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        this->data = x;
        next = nullptr;
    }
};
Node *head = nullptr;

// creating a linked-list
void creation(Node *&head, int val)
{
    Node *newnode = new Node(val);
    if (head == nullptr)
    {
        head = newnode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// print linked-list
void displayList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
}

// sort linked-list
void sortList(Node *head)
{
    Node *i, *j;
    for (i = head; i != nullptr; i = i->next)
    {
        for (j = i->next; j != nullptr; j = j->next)
        {
            if (i->data > j->data)
            {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// insert new_node in a linked-list
Node *insertNewNode(Node *head, int val)
{
    Node *newnode = new Node(val);
    if (head != nullptr && head->data >= val)
    {
        newnode->next = head;
        head = newnode;
        return head;
    }
    Node *temp = head;
    while (temp->next != nullptr && temp->next->data < val)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;

    return head;
}


int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        creation(head, val);
    }


    cout << "Linked-list before adding new node and sorting the nodes: ";
    displayList(head);
    cout << endl;


    sortList(head);
    cout << "Linked-list after sorting the nodes but before adding new node: ";
    displayList(head);
    cout << endl;


    int val;
    cout << "Enter the value of new node: ";
    cin >> val;
    head = insertNewNode(head, val);
    cout << "Linked-list after sorting the nodes and adding new node: ";
    displayList(head);
    cout << endl;

  
    return 0;
}
