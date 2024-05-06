#include <iostream>
using namespace std;

typedef struct t_list_node
{
    string data;
    struct t_list_node *link;
} list_node;

int main()
{
    list_node *head = new list_node;
    head->data = "cat";

    head->link = new list_node;
    head->link->data = "bat";
    head->link->link = NULL;
    // cout << head->link->data << endl;    // for test

    list_node *node = new list_node;
    node->data = "vat";
    node->link = head->link;
    head->link = node;

    cout << "head->link->data: " << head->link->data << endl;             // "vat"
    cout << "head->link->link->data: " << head->link->link->data << endl; // "bat"
}