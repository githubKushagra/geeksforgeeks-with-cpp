#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};

void Creation(Node *&head, int x)
{
    Node *newnode = new Node(x);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// function to remove duplicates nodes
Node *removeDuplicate(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *temp1 = head;
    while (temp1 != nullptr)
    {
        Node *temp2 = temp1;
        while (temp2->next != nullptr)
        {
            if (temp2->next->data == temp1->data)
            {
                temp2->next = temp2->next->next;
            }
            else
            {
                temp2 = temp2->next;
            }
        }
        temp1 = temp1->next;
    }
    return head;
}

void printList(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
}


int main()
{
    Node *head = NULL;
    int n;
    cout << "enter the number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        Creation(head, val);
    }
    cout << "Our linked list before removing duplicates nodes: ";
    printList(head);
    head = removeDuplicate(head);
    cout << endl;
    cout << "Our linked list after removing duplicates nodes: ";
    printList(head);
  

    return 0;
}
