#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct t_list_node {
    int data;    
    struct t_list_node *link;   
} list_node;

int main()
{
    list_node *head=NULL, *cur=NULL;
    
    // Insert
    for (int i=0; i<10; i++){
    	list_node *new_node = new list_node;
    	new_node->data = i+1;
    	new_node->link=NULL;
    	if (head==NULL){
			head=new_node;
    		cur=head;
		}
		else{
    		cur->link=new_node;
    		//cur=new_node;
			cur=cur->link;
    	}
	} // for
	
	//Print  
    for (cur = head; cur != NULL; cur = cur->link){
		cout << cur->data << '\t';
	}
	cout << endl;
	
    // find
    int find_num = 0;
    cout << "What is the nubmer that you look for?: " << endl;
    cin >> find_num;

    for(cur = head; cur != NULL && find_num != cur->data; cur = cur->link);
    if(cur != NULL) cout << "cur->data: " << cur->data << "\tfind_num: " << find_num << endl;
    else cout << "find_num is not here!" << endl; 

    /*
	//Delete
	cur=head; 
	list_node *next;
    while (cur){  // while (curr != NULL){
        next = cur->link;
        cout << "Deleting " << cur->data << endl;
        delete cur; 
        cur = next; 
    }	
    head=NULL;
	cout << "head: " << head << endl;
    */

   return 0;
}


