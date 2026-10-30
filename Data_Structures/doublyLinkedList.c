#include <stdio.h>
#include <stdlib.h>
struct node {
	struct node *prev;
	int data;
	struct node *next;
};
struct node *createDLL(struct node *);
void displayDLL(struct node *);
struct node *insertAtBeg(struct node *, int);
struct node *insertAtEnd(struct node *, int);
struct node *insertAtPos(struct node *, int, int);
struct node *deleteFirst(struct node *);
struct node *deleteLast(struct node *);
struct node *deletePos(struct node *, int);
struct node *reverse(struct node *);
int main(){
	int value, choice, position;
	struct node *head = NULL;
	head = (struct node *)malloc(sizeof(struct node));
	if(head == NULL){
		printf("No memory available!\n");
		exit(1);
	}

	printf("Enter a value: ");
	scanf("%d", &value);
	head->prev = NULL;
	head->data = value;
	head->next = NULL;

	head = deleteFirst(head);
	head = insertAtBeg(head, 7);
	head = insertAtEnd(head, 9);
	head = insertAtPos(head, 3, 3);
	/*
	head = insertAtEnd(head, 3);
	head = insertAtPos(head, 5, 5);
	*/
	displayDLL(head);

	//head = deletePos(head, 4);
	//displayDLL(head);
	head = reverse(head);
	displayDLL(head);

	return 0;

}

void displayDLL(struct node *start){
	if(start == NULL){
		printf("Doubly linked list is empty\n");
		return;
	}

	struct node *p = start;
	while(p != NULL){
		printf("%d ", p->data);
		p=p->next;
	}
	printf("\n");
}

struct node *insertAtBeg(struct node *start, int value){
	if(start == NULL){
		start = (struct node *)malloc(sizeof(struct node));
		start->prev = NULL;
		start->data = value;
		start->next = NULL;
		return start;
	}
	else{
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		if(temp == NULL){
			printf("No space available");
			return start;
		}

		temp->prev = NULL;
		temp->data = value;
		temp->next = start;
		start->prev = temp;
		start = temp;
	}
	return start;
}

struct node *insertAtEnd(struct node *start, int value){
	if(start == NULL){
		start->prev = NULL;
		start->data = value;
		start->next = NULL;
		return start;
	}
	else{
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		if(temp == NULL){
			printf("No space available");
			return start;
		}
		struct node *p = start;
		while(p->next != NULL){
			p=p->next;
		}

		temp->next = NULL;
		temp->data = value;
		temp->prev = p;
		p->next = temp;
	}
	return start;
}

struct node *insertAtPos(struct node *start, int value, int pos){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	if(temp == NULL){
		printf("No space available");
		return start;
	}
	if(pos == 1){
		start = insertAtBeg(start, value);
		return start;
	}
	struct node *help = NULL, *p = start;
	int i;
	for(i = 1; i<pos-1 && p != NULL; i++){
		p=p->next;
	}
	if(p == NULL || pos <= 0){
		printf("Invalid position to insert\n");
		return start;
	}
	temp->prev = p;
	temp->data = value;
	temp->next = help;
	if(p->next == NULL){
		p->next = temp;
	}
	else{
		help = p->next;
		help->prev = temp;
		p->next = temp;
	}
	return start;
	
	
}

struct node *deleteFirst(struct node *start){
	if(start == NULL){
		printf("The linked list is already empty!\n");
		return start;
	}
	if(start->next == NULL){
		free(start);
		start = NULL;
		return start;
	}

	start=start->next;
	free(start->prev);
	start->prev = NULL;
	return start;
}

struct node *deleteLast(struct node *start){
	if(start == NULL){
		printf("List is already empty!\n");
       		return start;
	}
	if(start->next == NULL){
		free(start);
		start = NULL;
		return start;
	}	

	struct node *p = start;
	while(p->next != NULL){
		p=p->next;
	}
	p->prev->next = NULL;
	free(p);
	p = NULL;
	return start;
}

struct node *deletePos(struct node *start, int pos){
	if(start == NULL){
		printf("List is already empty!\n");
		return start;
	}

	if(start->next == NULL){
		free(start);
		start = NULL;
		return start;
	}

	if(pos == 1){
		start = deleteFirst(start);
		return start;
	}

	int i;
	struct node *p = start;
	for(i = 1; i<pos && p != NULL; i++){
		p=p->next;
	}

	if(p == NULL || pos <= 0){
		printf("Position to be deleted not found\n");
		return start;
	}
	if(p->next == NULL){
		start = deleteLast(start);
		return start;
	}
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
	p = NULL;
	return start;
}

struct node *reverse(struct node *start){
	if(start == NULL || start->next == NULL){
		return start;
	}

	struct node *ptr = start, *temp = NULL;
	while(ptr != NULL){
		temp = ptr->prev;
		ptr->prev = ptr->next;
		ptr->next = temp;
		ptr=ptr->prev;
	}
	start = temp->prev;
	return start;
}


			



