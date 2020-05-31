#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Node{
	
	int data;
	struct Node* next;
};


struct Node* createNode(int data){

	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	if(node){
	
		node->data = data;
		node->next = NULL;
		return node;
	}

	cout << "malloc failed" << endl;	
	return NULL;
}

int InsertAtFront(struct Node** head, int data){

	struct Node* node = createNode(data);
        if(node == NULL){

                cout << "Failed to create a new node" << endl;
                return 1;
        }


	if(*head == NULL){

                cout << "node is " << node << endl;
                *head = node;
                return 0;
        }	

	node->next = *head;
	*head = node;

	return 0;

}


int appendToList(struct Node** head, int data){

	cout << "Data is " << data << endl;
	//Create a node
	//
	//
	struct Node* node = createNode(data);
	if(node == NULL){

		cout << "Failed to create a new node" << endl;
		return 1;
	}

	
	if(*head == NULL){
		
		cout << "node is " << node << endl;
		*head = node;
		return 0;
	}

	struct Node* tempptr = *head;
	while(tempptr->next != NULL)
	{
		tempptr =  tempptr->next;
	}
	
	tempptr->next = node;
	return 0;
}

int appendOpti(struct Node** head, struct Node** tail, int data){


	struct Node* node = createNode(data);
        if(node == NULL){

                cout << "Failed to create a new node" << endl;
                return 1;
        }

        cout << "node is " << node << endl;

        if(*head == NULL){

                *head = node;
		*tail = *head;
                return 0;
        }

	(*tail)->next = node;
	*tail = (*tail)->next; 

	return 0;
}

int printList(struct Node* head){

	if(head == NULL){

		cout << "List is empty" << endl;
		return 0;

	}

	struct Node* tempptr = head;
        while(tempptr)
        {
		cout << "tempptr is " << tempptr << " and data is " << tempptr->data << endl;
		tempptr = tempptr->next;

	}
	return 0;

}

int deleteLL(struct Node** head){

	struct Node* temp = *head;
	struct Node* nxt = NULL;

	while(temp){
		nxt = temp->next;	
		free(temp);
		temp = nxt;
	}

	*head = NULL;
	return 1;	
}

int deleteNodeinLL(struct Node** head, int data){

	if(head == NULL){
		cout << "Empty LL" << endl;
		return -1;
	}

	cout << "Head is "<< *head << endl;
	struct Node* temp = *head;
	
	if(temp->data == data)
	{
		*head = temp->next;
		cout << "New head is " << *head << endl;
		temp->next = NULL;
		free(temp);
		return 0;
	}

	while((temp->next)->data != data)
	{
		temp = temp->next;
	}
	
	printf("deleting node %d\n", (temp->next)->data);
	struct Node* save = temp->next->next;
	free(temp->next);
	temp -> next = save;

	return 0;
	
}

int main(){

	struct Node* head = NULL;
	struct Node* tail = NULL;
	int num = 0;
	printf("Total number of elements: \n");
	scanf("%d",&num);
	printf("Enter the element to add to LL: \n");
	int data = -1;	

	for(int i = 0; i < num; i++){
			
		scanf("%d",&data);	
		//InsertAtFront(&head, data);
		//appendToList(&head, data);
		appendOpti(&head, &tail, data);
	}

	printf("Printing the LL: ");
	printList(head);

	//printf("Deleting LL\n");
	//deleteLL(&head);


	printf("Enter node to delete: \n");
	scanf("%d",&data);
	deleteNodeinLL(&head, data);

	printf("Calling print again\n");
	printList(head);

	return 0;

}
