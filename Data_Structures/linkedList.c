#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *link;
};

void displayLL(struct node *);
void searchLL(struct node *, int);
void countLL(struct node *);
struct node *insertAtFirst(struct node *, int);
struct node *insertAtLast(struct node *, int);
struct node *insertBefore(struct node *, int, int);
struct node *insertAfter(struct node *, int, int);
struct node *insertAtPos(struct node *, int, int);
struct node *deleteNode(struct node *, int);
struct node *reverse(struct node *);
struct node *sortLL(struct node *);
struct node *insertAtMid(struct node *, int);
struct node *deleteFirst(struct node *);
struct node *deleteLast(struct node *);
struct node *deletePos(struct node *, int);
struct node *deleteLL(struct node *);
struct node *reverseLL(struct node *);

int main(int argc, char *argv[]){
	int n = argc - 1;
	struct node *head = NULL;
	int choice, data, pos;
	if(argc == 1){
		printf("\nNo arguments were passed to main\n");
		printf("\nYou can either pass values in command line argumenst or,\n");
		printf("To create a new Linked List\n");
	}
	else{
		head = (struct node *)malloc(sizeof(struct node));
		if(head == NULL){
			printf("Not enough space available to create linked list!\n");
			exit(1);
		}
		int i = 1;
		head->data = atoi(argv[i++]);
		head->link = NULL; 
		for(i; i<=n; i++){
			head = insertAtLast(head, atoi(argv[i]));
		}
	}

	while(1){
		printf("\nLinked List Operations:-\n");
		printf("Press 1: To Create Linked List\n");
		printf("Press 2: To display elements of Linked List\n");
		printf("Press 3: To Search for a element i Linked List\n");
		printf("Press 4: To count the numbers of elements in Linked List\n");
		printf("Press 5: To insert a node a beginning\n");
		printf("Press 6: To insert a node at the end\n");
		printf("Press 7: To insert a node before an element\n");
		printf("Press 8: To insert a node after an element\n");
		printf("Press 9: To insert a node at a particular position\n");
		printf("Press 10: Sort the linked list\n");
		printf("Press 11: To insert a node at middle position\n");
		printf("Press 12: To delete the first node\n");
		printf("Press 13: To delete the last node\n");
		printf("Press 14: To delete a particular position\n");
		printf("Press 15: To delete entire linked list\n");
		printf("Press 16: To reverse the linked list\n");
		printf("Press 17: To exit the program!\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		printf("\n");
		switch(choice){
			case 1:
				if(head != NULL){
					printf("A linked list already exists!\n");
					displayLL(head);
					printf("Do you wants to keep it or delete it.\n");
					printf("Press 1 to keep or Press 0 to delete: ");
					int option;
					scanf("%d", &option);
					if(option == 0){
						head = deleteLL(head);
						break;
					}
					else if(option == 1){
						break;
					}
					else{
						printf("Invalid Choice!\n");
						break;
					}
					
				}
				printf("Enter a value to add to linked list: ");
				scanf("%d", &data);
				head = insertAtFirst(head, data);
				int choice = 1;
				while(choice){
					printf("Do you want to continue adding elements(Press 1:Yes or Press 0:No): ");
					scanf("%d", &choice);
					if(choice == 1){
						printf("Enter value to add to list: ");
						scanf("%d", &data);
						head = insertAtLast(head, data);
					}
					else if(choice == 0){
						break;
						}
					else{
						printf("Invalid choice, please enter a valid option!\n");
						break;
					}
				}
				break;
			case 2:
				displayLL(head);
				break;
			case 3:
				printf("Enter an element to search: ");
				scanf("%d", &data);
				searchLL(head, data);
				break;
			case 4: 
				countLL(head);
				break;
			case 5:
				printf("Enter a value: ");
				scanf("%d", &data);	
				head = insertAtFirst(head, data);
				break;
			case 6:
				printf("Enter a value: ");
				scanf("%d", &data);
				head = insertAtLast(head, data);
				break;
			case 7:
				printf("Enter a value: ");
				scanf("%d", &data);
				printf("Enter the element before which the value will be added: ");
				scanf("%d", &pos);
				head = insertBefore(head, data, pos);
				break;
			case 8:
				printf("Enter a value: ");
				scanf("%d", &data);
				printf("Enter the element after which the value to be added: ");
				scanf("%d", &pos);
				head = insertAfter(head, data, pos);
				break;
			case 9: 
				printf("Enter a value: ");
				scanf("%d", &data);
				printf("Enter a postion where the value to be added: ");
				scanf("%d", &pos);
				head = insertAtPos(head, data, pos);
				break;
			case 10:
				printf("After sorting:-\n");
			       	head = sortLL(head);	
				displayLL(head);
				break;	
			case 11: 
				printf("Enter a value: ");
				scanf("%d", &data);
				head = insertAtMid(head, data);
				break;	
			case 12:
				head = deleteFirst(head);
				break;
			case 13:
				head = deleteLast(head);
				break;
			case 14:
				printf("Enter a position to delete: ");
				scanf("%d", &pos);
				head = deletePos(head, pos);
				break;
			case 15:
				head = deleteLL(head);
				break;
			case 16:
				printf("After reversing:-\n");
				head = reverseLL(head);
				displayLL(head);
				break;
			case 17:
				displayLL(head);
				printf("Program exitted!\n");
				exit(1);
				
			default:
				printf("Invalid Choice!\n");
			}
	}

	return 0;
}


// FUNCTION TO TRAVERSE & DISPLAY DATA OF LINKED LIST
void displayLL(struct node *start){
	if(start == NULL){
		printf("The Linked List is Currently empty!\n");
		return;
	}
	struct node *p;
	p = start;
	printf("Current List: ");
	while(p != NULL){
		printf("%d->", p->data);
		p = p->link;
	}
	printf("NULL\n");
}

// FUNCTION TO COUNT NUMBER OF ELEMENTS OF LINKED LIST
void countLL(struct node *start){
	int count = 0;
	struct node *p;
	p = start;
	while(p != NULL){
		p=p->link;
		count++;
	}

	printf("Current Number of elements in linked list are %d\n", count);
}

// FUNCTION TO SEARCH FOR AN ELEMENT IN LINKED LIST
void searchLL(struct node *start, int ele){
	if(start == NULL){
		printf("Currently the linked list is empty first insert a element\n");
		return;
	}
	struct node *p;
	int pos = 1;
	p = start;
	while(p != NULL){
		if(p->data == ele){
			printf("Element %d found at position: %d\n", ele, pos);
			return ;
		}
		p=p->link;
		pos++;
	}
	printf("Element %d was not found in linked list\n", ele);
	return ;
}

// FUNCTION TO INSERT NODE AT FIRST/BEGINNING OF THE LINKED LIST
struct node *insertAtFirst(struct node *start, int value){
	struct node *help = (struct node *)malloc(sizeof(struct node));
	if(help == NULL){
		printf("No space available in memory to insert node at the beginning!");
		return start;
	}

	help->data = value;
	help->link = start;
	start = help;
	return start;
}

// FUNCTION TO INSERT NODE AT LAST/ENDING OF THE LINKED LIST
struct node *insertAtLast(struct node *start, int value){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	if(temp == NULL){
		printf("no space available, couldn't insert node at end!");
		return start;
	}

	if(start == NULL){
		temp->data = value;	
		temp->link = NULL;
		start = temp;
		return start;
	}
	struct node *p;
	p = start;
	while(p->link != NULL)
		p=p->link;
	temp->data = value;
	p->link = temp;
	temp->link = NULL;
	return start;
}

// FUNCTION TO INSERT NODE AFTER A PARTICULAR NODE i.e. DATA OF THE GIVEN NODE
struct node *insertAfter(struct node *start, int value, int ele){
	if(start == NULL){
		printf("Linked list is already empty!, enter some elements first\n");
		return start;
	}
	struct node *p, *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	if(temp == NULL){
		printf("Not enough space available to insert node after %d\n", ele);
		return start;
	}
	p = start;
	while(p != NULL){
		if(p->data == ele){
			temp->data = value;
			temp->link = p->link;
			p->link = temp;
			return start;
		}
		p=p->link;
	}
	printf("Node with value %d was not found!\n", ele);
	return start;
}

// FUNCTION TO INSERT A NODE BEFORE A PARTICULAR NODE(before at a given element)
struct node *insertBefore(struct node *start, int value, int ele){
	if(start == NULL){
		printf("The Linked List is currently empty\n");
		return start;
	}
	struct node *p, *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	if(temp == NULL){
		printf("No memory available to insert a node before %d\n", ele);
		return start;
	}
	if(ele == start->data){
		temp->data = value;
		temp->link = start;
		start = temp;
		return start;
	}
	p = start;
	while(p->link != NULL){
		if(p->link->data == ele){
			temp->data = value;
			temp->link = p->link;
			p->link = temp;
			return start;
		}
		p=p->link;
	}
	printf("Node with value %d is not present\n", ele);
	return start;
}

// FUNCTION TO INSERT NODE AT ANY GIVE POSITION
struct node *insertAtPos(struct node *start, int value, int pos){
	struct node *p, *temp;
	int i = 1;
	p = start;
	if(pos < 0){
		printf("Invalid postion!, can't be negative\n");
		return start;
	}
	for(i ; i<pos-1 && p != NULL; i++)
		p=p->link;

	if(p == NULL){
		printf("Given position is invalid for the current linked list\n");
	}
	else{
		temp = (struct node *)malloc(sizeof(struct node));
		if(temp == NULL){
			printf("Insufficient space for inserting a node at position %d\n", pos);
			return start;
		}
		temp->data = value;
		if(pos == 1){
			temp->link = start;
			start = temp;
			return start;
		}
		temp->link = p->link;
		p->link = temp;
	}
	return start;
}

// FUNCTION TO SORT THE ELEMENT OF LINKED LIST
struct node *sortLL(struct node *start){
	if(start == NULL){
		printf("Empty Linked List!");
		return start;
	}
	if(start->link == NULL){
		return start;
	}

	struct node *p = start;
	while(p != NULL){
		struct node *p2 = p->link;
		while(p2 != NULL){
			if(p->data > p2->data){
				int temp = p->data;
		      		p->data = p2->data;
				p2->data = temp;
			}
			p2=p2->link;
		}
		p=p->link;
		
	}
	return start;
}

// FUNCTION TO INSERT NODE AT THE MIDDLE OF THE LINKED LSIT
struct node *insertAtMid(struct node *start, int value){
	if(start == NULL){
		printf("Empty list Couldn't get middle!\n");
		return start;
	}
	struct node *p = start;
	int count = 0, mid, i;
	while(p != NULL){
		p=p->link;
		count++;
	}
	if(count % 2 == 0){
		mid = count / 2;
	}else
		mid = (count + 1) / 2;
	p = start;
	for(i = 1; i<mid-1; i++){
		p=p->link;
	}
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	if(temp == NULL){
		printf("Couldn't allocat memory to insert node at mid");
		return start;
	}
	temp->data = value;
	temp->link = p->link;
	p->link = temp;

	return start;
}

// FUNCTION TO DELETE THE FIRST NODE
struct node *deleteFirst(struct node *start){
	if(start == NULL){
		printf("The linked list is empty, no first node to delete\n");
		return start;
	}
	struct node *temp = start;
	start = start->link;
	free(temp);
	return start;
}

// FUNCTION TO DELETE THE LAST NODE
struct node *deleteLast(struct node *start){
	if(start == NULL){
		printf("The list is current empty, no last node to delete!\n");
		return start;
	}
	if(start->link == NULL){
		free(start);
		start = NULL;
		return start;
	}
	struct node *p = start;
	struct node *temp = start;
	while(temp->link != NULL){
		p = temp;
		temp=temp->link;
	}
	p->link = NULL;
	free(temp);
	temp = NULL;
	return start;
}

// FUNCTION TO DELETE A PARTICULAR NODE 
struct node *deletePos(struct node *start, int pos){
	if(start == NULL){
		printf("The linked list is empty!, can't perform deletion\n");
		return start;
	}
	if(pos <= 0){
		printf("Invalid position!, position begins from 1\n");
		return start;
	}
	if(pos == 1){
		if(start->link == NULL){
			free(start);
			return start;
		}
		struct node *temp = start;
		start = start->link;
		free(temp);
		return start;
	}

	struct node *p = start;
	struct node *temp = start;
	int i = 1;
	for(i; i<pos && temp != NULL; i++){
		p = temp;
		temp=temp->link;
	}
	if(temp == NULL){
		printf("Couldn't find postion %d, invalid position of node\n", pos);
		return start;
	}

	p->link = temp->link;
	free(temp);
	temp = NULL;
	return start;
}

// FUNCTION TO DELETE WHOLE LINKED LIST
struct node *deleteLL(struct node *start){
	if(start == NULL){
		printf("The list is already empty!, can't perform delete operation\n");
		return start;
	}

	if(start->link == NULL){
		free(start);
		start = NULL;
		return start;
	}

	struct node *temp = start;
	while(temp != NULL){
		temp = temp->link;
		free(start);
		start = temp;
	}
	if(start == NULL)
		printf("Linked list deleted successfully!\n");
	else
		printf("Couldn't delete the linked list!\n");
	return start;
}

// FUNCTION TO REVERSE A LINKED LIST
struct node *reverseLL(struct node *start){
	if(start == NULL){
		printf("The list is empty, can't perform reverse operation!\n");
		return start;
	}
	if(start->link == NULL){
		return start;
	}
	struct node *prev = NULL, *next;
	while(start != NULL){
		next = start->link;
		start->link = prev;
		prev = start;
		start = next;
	}
	start = prev;
	return start;
}










