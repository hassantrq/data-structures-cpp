#include <iostream>
using namespace std;

struct node{
	int data;
	node *next, *prev; //prev pointer for previous node	
};

class DoublyLinkedList{
	public:
		node *head, *curr, *tail;
		//tail pointer to keep address of last node in list
		
		DoublyLinkedList(){
			head=NULL;
			tail=NULL;
			curr=NULL;
		}
		
		void insertAtStart(int data){
			node *newnode;
			newnode = new node;
			newnode -> data = data;
			newnode -> next = NULL;
			newnode -> prev = NULL;
			
			if (head == NULL){
				head = newnode;
				tail = newnode;
			}
			else{
				newnode -> next = head;
				head -> prev = newnode;
				head = newnode;
			}
		}
		
		void insertAtEnd(int data){
			node *newnode;
			newnode = new node;
			newnode -> data = data;
			newnode -> next = NULL;
			newnode -> prev = NULL;
			
			if (head == NULL){
				head = newnode;
				tail = newnode;
			}
			else{
				// one way
//				curr=head;
//				while(curr->next != NULL){
//					curr=curr->next;
//				}
//				
//				curr->next = newnode;
//				newnode->prev = curr;
//				tail = newnode;

				//2nd way
				newnode -> prev = tail;
				tail -> next = newnode;
				tail = newnode;
				 
			}
		}
		
		void insertAtPosition(int data, int pos){
			node *newnode;
			newnode = new node;
			newnode -> data = data;
			newnode -> next = NULL;
			newnode -> prev = NULL;
			
			curr=head;
			int i=1;
			
			while(curr->next != NULL && i != pos){
				curr=curr->next;
				i+=1;
			}
			
			newnode -> next = curr -> next;
			curr -> next -> prev = newnode;
			curr -> next = newnode;
			newnode -> prev = curr;
		}
		
		void deleteAtStart(){
			node *temp;
			
			temp = head;
			head = head -> next;
			
			head -> prev = NULL;
			temp -> next = NULL;
			
			delete temp;
			
		}

		void deleteAtEnd(){
			node *temp;
			
			temp = tail;
			tail = tail -> prev;
			
			tail -> next = NULL;
			temp -> prev = NULL;
			
			delete temp;
			
		}
		
		void deleteAtPosition(int pos){
			node *temp;
			
			curr=head;
			int i=1;
			
			while(curr -> next != NULL && i != pos){
				curr=curr->next;
				i+=1;
			}

			temp = curr->next;
			curr -> next = curr->next->next;
			curr->next -> prev = curr;
			temp -> next = NULL;
			temp -> prev = NULL;
			
			delete temp;
		}
	
		void displayForward(){
			curr=head;
			while(curr){
				cout<<curr->data<<" -> ";
				curr=curr->next;
			}
			cout<<"NULL";
		}
		
		void displayReverse(){
			curr=tail;
			while(curr){
				cout<<curr->data<<" -> ";
				curr=curr->prev;
			}
			cout<<"NULL";
		}


};


int main(){
	DoublyLinkedList obj;
	obj.insertAtStart(5); //5 -> NULL
	obj.insertAtStart(4); //4 -> 5 -> NULL
	obj.insertAtStart(3); // 3 -> 4 -> 5 -> NULL


	obj.insertAtEnd(6); // 3 -> 4 -> 5 -> 6 -> NULL
	obj.insertAtEnd(7); // 3 -> 4 -> 5 -> 6 -> 7 -> NULL
	obj.insertAtEnd(8); // 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> NULL
	
	obj.insertAtPosition(888, 3); // 3 -> 4 -> 5 -> 888 -> 6 -> 7 -> 8 -> NULL

	obj.displayForward();
	cout<<"\nAfter Delete At Position 3: \n";	
	obj.deleteAtPosition(3);
	obj.displayForward();

	cout<<"\nAfter Delete At Start \n";	
	obj.deleteAtStart();
	obj.displayForward();	

	cout<<"\nAfter Delete At End\n";	
	obj.deleteAtEnd();
	obj.displayForward();

}









