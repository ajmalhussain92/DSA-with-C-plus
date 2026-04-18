#include<iostream>
using namespace std;

class node
{
public:

    int data;
    node *next;

    node()
    {
        next = NULL;
    }
};

class LinkedList
{
    node *head;

public :
    LinkedList()
    {
        head = NULL;
    }

    void print()
    {
        if(head == NULL)
            cout<<"List is Empty";
        else
        {
            node *temp = head;
            while(temp != NULL)
            {
                cout<<temp->data<<" -> ";
                temp = temp->next;
            }
        }
    }

    void insert_at_beg(int value)
    {
        node *temp = new node();
        temp->data = value;
        temp->next = head;
        head = temp;
    }

    void insert_at_end(int value)
    {

    }
    void insert_in_middle(int value, int position)
    {

    }
};


int main()
{
    LinkedList ll;
    ll.insert_at_beg(10);
    ll.insert_at_beg(20);
    ll.insert_at_beg(30);
    ll.insert_at_beg(40);
    ll.insert_at_beg(100);
    ll.print();

    return 0;
}
