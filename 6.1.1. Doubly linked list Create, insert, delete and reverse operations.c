#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node* prev;
struct node* next;
};

typedef struct node *NODE;
NODE head = NULL;

NODE createNodeInCLL(){
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}



void insert(int value){
	NODE newNode=createNodeInCLL();
	newNode->data = value;
	if(head == NULL){
		head = newNode;
	}
	else{
		NODE temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp -> next = newNode;
		newNode->prev = temp;
	}
}

void remov(int value){
	if(head == NULL){
		printf("List is empty\n");
		return;
	}
	NODE temp = head;
	while(temp != NULL && temp->data != value){
		temp = temp->next;
	}
	if(temp==NULL){
		printf("%d not found\n", value);
		return;
	}
	if(temp->prev != NULL)
		temp->prev->next = temp->next;
	else
		head = temp->next;
	if(temp->next != NULL)
		temp->next->prev = temp->prev;
	free(temp);
}

void display(){
	NODE temp = head;
	if(temp == NULL){
		printf("List is empty\n");
		return;
	}
	while(temp!=NULL){
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void reverse(){
	NODE temp = NULL;
	NODE current = head;

	if(head == NULL) return;

	while(current != NULL){
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}

	if(temp != NULL){
		head = temp->prev;
	}
}




int main() {
    int n, ch;
    do {
        printf("Operations on doubly linked list\n");
        printf("1.Insert\n2.Remove\n3.Display\n4.Reverse\n0.Exit\n");
        printf("Enter Choice 0-4: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter number: ");
                scanf("%d", &n);
                insert(n);
                break;
            case 2:
                printf("Enter number to delete: ");
                scanf("%d", &n);
                remov(n);
                break;
            case 3:
                display();
                break;
            case 4:
                reverse();
                printf("List reversed\n");
                break;
        }
    } while (ch != 0);
    return 0;
}