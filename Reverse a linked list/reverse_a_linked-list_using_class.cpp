#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stack>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};

void Creation(node *&head, int x)
{
    node *newnode = new node(x);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void printList(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
}

// this is the required reverse function
node *reverse(node *&head)
{
    node *temp = head;
    node *prev = NULL;
    node *next = NULL;
    while (temp != NULL)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;

    return head; // return new starting node after reverse the list
}

int main()
{
    // dynamically,i have created
    node *head = NULL;
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cout << "Enter the value of " << i + 1 << " node: ";
        cin >> val;
        Creation(head, val);
    }
    cout << "Our linked list: ";
    printList(head);
    cout << endl
         << endl;

    cout << "Linked list after reverse: ";
    head = reverse(head);
    printList(head);

  

    return 0;
}
