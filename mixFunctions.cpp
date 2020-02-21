#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

//print function
void print(struct Node*node){
	printf("\n--------------------------------\n");
	while(node!=NULL){
		printf("%d ",  node->data);
		node = node->next;
	}
}

//insert to the beginning
void push(struct Node**head_ref,int new_data){
	struct Node*new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

//insert to the middle
void insertAfter(struct Node*prev_node,int new_data){
	if(prev_node==NULL){
		printf("Cannot be null !!!");
		return;
	}

	struct Node*new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

//insert to the end
void append(struct Node**head_ref,int new_data){
	struct Node* last = *head_ref;
	struct Node*new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = NULL;

	if(*head_ref==NULL){
		*head_ref = new_node;
		return;
	}

	while(last->next!=NULL){
		last = last->next;
	}

	last->next = new_node;
	return;
}

//get a value from the user and delete it
void deleteByKey(struct Node**head_ref,int key){
	struct Node*temp = *head_ref, *prev;

	if(temp!=NULL && temp->data==key){
		*head_ref = temp->next;
		free(temp);
		return;
	}

	while(temp!=NULL && temp->data!=key){
		prev = temp;
		temp = temp->next;
	}

	if(temp==NULL){
		printf("Target cannot found !");
		return;
	}

	prev->next = temp->next;
	free(temp);
	return;
}

//delete the index of the value that user specified
void deleteByPosition(struct Node **head_ref, int position){
    if (*head_ref == NULL)
       return;

   	struct Node* temp = *head_ref;
    if (position == 0){
       	*head_ref = temp->next;
        return;
    }

    for (int i=0; temp!=NULL && i<position-1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
        return;

    struct Node *next = temp->next->next;

    free(temp->next);

    temp->next = next;
}

//find length (iterative)
int getCountIterative(struct Node*head){
	struct Node*iter = head;
	int count = 0;
	while(iter!=NULL){
		count++;
		iter = iter->next;
	}
	return count;
}

//find length (recursive)
int getCountRecursive(struct Node*head){
	if(head==NULL)
		return 0;

	return 1 + getCountRecursive(head->next);
}

//swap nodes
void swapNodes(struct Node**head_ref,int x,int y){
	if(x==y)
		return;

	struct Node*prevX = NULL, *currX = *head_ref;

	while(currX && currX->data !=x){
		prevX = currX;
		currX = currX->next;
	}

	struct Node*prevY = NULL, *currY = *head_ref;

	while(currY && currY->data!=y){
		prevY = currY;
		currY = currY->next;
	}

	if(currY==NULL || currX==NULL)
		return;

	if(prevX!=NULL){
		prevX->next = currY;
	}
	else{
		*head_ref = currY;
	}

	if(prevY!=NULL){
		prevY->next = currX;
	}
	else{
		*head_ref = currX;
	}

	struct Node*temp = currX->next;
	currX->next = currY->next;
	currY->next = temp;
}

//list reverse
void reverse(struct Node**head_ref){
	struct Node*prev = NULL;
	struct Node*current = *head_ref;
	struct Node*next = NULL;

	while(current!=NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

//list as a group
struct Node *reverseGroupSize(struct Node*head,int k){
	struct Node*current = head;
	struct Node*next = NULL;
	struct Node*prev = NULL;
	int count=0;

	while(current!=NULL && count < k){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}
	if(next != NULL)
		head->next=reverseGroupSize(next,k);

	return prev;
}

//rotate
void rotate(struct Node**head_ref,int k){
	struct Node*current = *head_ref;
	if(k==0)
		return;

	int count=1;
	while(count < k && current!= NULL){
		current = current->next;
		count++;
	}

	if(current==NULL)
		return;

	struct Node*kth=current;
	while(current->next!=NULL){
		current = current->next;
	}

	current->next = *head_ref;
	*head_ref = kth->next;
	kth->next = NULL;
}

//merge two sorted linked lists
struct Node* SortedMerge(struct Node* a, struct Node* b){
	struct Node* result = NULL;

	if (a == NULL)
		return(b);
	else if (b==NULL)
		return(a);

	/* Pick either a or b, and recur */
	if (a->data <= b->data){
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else{
		result = b;
		result->next = SortedMerge(a, b->next);
	}

	return(result);
}

/*void detectLoop(struct Node*,struct Node*){
	int detectAndRemoveLoop(struct Node*list){
		struct Node* slowp,*fastp;

		while(slowp && fastp &&fastp->next){
			slowp = slowp->next;
			fastp = fastp->next->next;
		}

		if(slowp==fastp){
			removeLoop(slowp,list);
			return 1;
		}
		return 0;
	}
}*/

//main function does not have full test senarios to test every function
//it is suggested that you should create your own test scnerios each at a time for every function
int main(){
  printf("Memo'nun kod dunyasi");
	struct Node*head = NULL;
	push(&head,40);
	push(&head,30);
	push(&head,20);
	push(&head,10);
	append(&head,50);
	append(&head,60);
	append(&head,70);
	append(&head,80);
	append(&head,90);
	//insertAfter(head->next->next,300);
	print(head);
    //deleteByKey(&head,300);
	print(head);
    //deleteByPosition(&head,4);
	print(head);
    //printf("\nlength iterative: %d ",getCountIterative(head));
    //printf("\n length recursive: %d ",getCountRecursive(head));
    //swapNodes(&head,10,50);
	print(head);
    //swapNodes(&head,80,30);
	print(head);
    //reverse(&head);
	print(head);
	head = reverseGroupSize(head,3);
	print(head);
  	rotate(&head,4);
	print(head);
}