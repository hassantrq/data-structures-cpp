#include <iostream>
using namespace std;

//node
struct node{
	int data; //data part
	node *next;	//pointer to the next node
};

class linkedList{
	public:
		node *head, *curr;
		
		linkedList(){
			//default constructor
			head=NULL;
			curr=NULL;
		}
		
		void insertAtStart(int data){
			node *newnode;
			newnode = new node;
			newnode->data = data;
			
			newnode->next = head;
			head = newnode;
		}
		
		void insertAtEnd(int data){
			node *newnode;
			newnode = new node;
			newnode -> data = data;
			newnode -> next = NULL;
			
			//first reach at the end by running curr from head to the last node
			//last node points to NULL. This will be the stop condition
			curr=head;
			while(curr->next != NULL){
				curr=curr->next;
			}
			
			curr->next = newnode;
		}

		void insertAtPosition(int data, int pos){
			//this is for inserting node at specific position
			//or in other words, inserting in the middle positions
			//position will be given by the user as parameter named 'pos'
			
			node *newnode;
			newnode = new node;
			newnode -> data = data;
			newnode -> next = NULL;
			
			int i=1; //to work as counter and stop if matched with position given
			curr=head;
			
			while(i != pos && curr->next != NULL){
				curr=curr->next;
				i += 1;
			}
			
			newnode -> next = curr -> next;
			curr -> next = newnode;
		}
		
		void deleteAtStart(){
			node *temp;
			
			temp = head;
			head = head->next;
			
			temp->next = NULL;
			delete temp;
		}
		
		void deleteAtEnd(){
			node *temp;
			
			curr=head;
			while(curr->next->next != NULL){
				curr=curr->next;
			}
			temp=curr->next;
			curr->next = NULL;
			
			delete temp;
		}
		
		void deleteAtPosition(int pos){
			node *temp;
			
			int i=1;
			curr=head;
			
			while(curr->next != NULL && i != pos){
				curr=curr->next;
				i += 1;
			}
			
			temp = curr->next;
			curr->next = curr->next->next;

			temp->next = NULL;
			delete temp;
		}
		
		void display(){
			curr=head;
			while(curr){
				cout<<curr->data<<"->";
				curr=curr->next;
			}
			cout<<"NULL";
		}
};

int main(){
	linkedList obj;
	obj.insertAtStart(4); // 4 -> NULL
	obj.insertAtStart(3); // 3 -> 4 -> NULL
	obj.insertAtStart(2); // 2 -> 3 -> 4 -> NULL

	obj.insertAtEnd(5); // 2 -> 3 -> 4 -> 5 -> NULL
	obj.insertAtEnd(6); // 2 -> 3 -> 4 -> 5 -> 6 -> NULL

	obj.insertAtPosition(80, 3); // 2 -> 3 -> 4 -> 80 -> 5 -> 6 -> NULL
	
	obj.deleteAtStart(); // 3 -> 4 -> 80 -> 5 -> 6 -> NULL
	obj.deleteAtEnd(); // 3 -> 4 -> 80 -> 5 -> NULL
	obj.deleteAtPosition(2); // 3 -> 4 -> 5 -> NULL

	obj.display(); //traverses and outputs all nodes' data
}