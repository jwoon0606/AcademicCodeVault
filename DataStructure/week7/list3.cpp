#include <iostream>
using namespace std;

typedef struct t_list_node
{
    int data;
    struct t_list_node *link;
} list_node;

int main()
{
    list_node *head = new list_node;
    head->data = 1;
    head->link = NULL;
    list_node *cur;
    cur = head;

    for (int i = 2; i <= 10; i++)
    {
        cur->link = new list_node;
        cur->link->data = i;
        cur->link->link = NULL;
        cur = cur->link;
    }

    cur = head;
    while (cur)
    {
        cout << cur->data << '\t';
        cur = cur->link;
    }
    cout << endl;

    cur = head;
    list_node *temp;
    while (cur)
    {
        temp = cur->link;
        cout << "delete " << cur->data << endl;
        delete cur;
        cur = temp;
    }
    head = NULL;

    if (head == NULL)
    {
        cout << "head is NULL" << endl;
    }

    return 0;
}