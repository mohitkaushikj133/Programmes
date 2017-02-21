#include <iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

void insert(node* &head, int data){
	node* temp = new node;
	temp->data = data;
	temp->next = head;
	head = temp;
}

void rotate(node* &head, int times){
	if(!head)
		return;
	node* fast = head;
	node* slow = head;
	for(int i = 0; i < times; i++)
		fast = fast->next;
	while(fast->next){
		slow = slow->next;
		fast = fast->next;
	}
	fast->next = head;
	head = slow->next;
	slow->next = NULL;
}

void print(node* head){
	while(head){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

int main(){
	node* head = NULL;
	insert(head, 2);
	insert(head, 5);
	insert(head, 6);
	insert(head, 23);
	insert(head, 9);
	print(head);
	rotate(head, 3);
	print(head);
	return 0;
}