#include <stdio.h>
#include <stdlib.h>

struct val{
	int  num;
	struct val *next;
};

void free_list(struct val *v)
{
	struct val *tmp=NULL;
	while(v != NULL)
	{
		tmp = v->next;
		free(v);
		v = tmp;
	}
}
struct val *addList(struct val *newNum, struct val *head)
{
	if(newNum != NULL)
	{
		newNum->next = head;
		head = newNum;	
	}
	return head;
}

struct val *sortList(struct val *head)
{
	struct val *first = head;
	struct val *second = head->next;
	
	int change = 0;												//change to 1 if values swap, otherwise, list is solved

	while(first != NULL && second != NULL)
	{
		if(first->num > second->num)
		{
			int tmp = second->num;
			second->num = first->num;
			first->num = tmp;
			
			change = 1;
		}
		first = second;
		second = second->next;
	}
	
	if(change != 0)											//no change means list is sorted
		sortList(head);
	
	return 0;
}
struct val *printList(struct val *head, int size)
{
	int i;
	if(head != NULL)
	{
		for(i = 0; i < size; i++)
		{
			printf("%d ",head->num);
			head = head->next;
		}
	}
	return 0;
}


int main(int argc, char *argv[])
{
	int size = argc -1;
	int i,num;
	int autoPop = 10000;
	
	struct val *head = NULL;
	
	if(argc != 1)
	{
		for(i = 0; i < size; i++)									//Add all inputs into a linked list
		{
			num = atoi(argv[i+1]);
		
			struct val *newNum = (struct val *)malloc(sizeof(struct val));		//make struct and add the values to list
			newNum->num = num;
			head = addList(newNum,head);
		}
		
		printf("Input: ");
		printList(head,size);
	}
	else
	{
		
		for(i = 0; i < autoPop; i++)
		{
			
			num = rand() % 100 +1;
			struct val *newNum = (struct val *)malloc(sizeof(struct val));
			newNum->num = num;
			head = addList(newNum,head);
		}
		
		printf("Input: ");
		printList(head,autoPop);
	}
	

	sortList(head);
	printf("\n-------------------------------------------------\n");
	printf("Sorted: ");
	
	if(argc != 1)
		printList(head,size);
	else
		printList(head,autoPop);
	
	free_list(head);
	
	return 0;
}