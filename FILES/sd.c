#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int data;
	struct stack *next;
};
struct stack *next=NULL;
struct stack *start=NULL;

void push_stack_link_list(struct stack* ptr);
 void pop_stack_link_list();
 void peep_stack_link_list();
 void insert();




int main()
{
	int ch;
	printf("\nPROGRAM TO IMPLEMENT STACK AND CREATE FUNCTION FOR push_link_list() POP() AND PEEP()");
	a:
	printf("\n1\tPUSH()\t\t3\tPEEP()\n2\tPOP()\t\t4\tEXIT");
	b:
	printf("\nEnter operation number to apply on STACK>>\t");
	scanf("%d",&ch);
	switch(ch)																									/*START OF SWITCH STATEMENT*/
	{
		case 1: insert();break;
		case 2:	pop_stack_link_list();break;
		case 3:	peep_stack_link_list();break;
		case 4:	exit(0);break;
		default:printf("\nWRONG OPERATION");goto a;
	}																												/*END OF SWITCH STATEMENT*/
	if((ch>=1)&&(ch<=3))																							/*IF STATEMENT*/
	{
		goto b;
	}
}

void insert()
{
	int element;
	struct stack *ptr;
	printf("\nEnter number you want to enter in stack>>\t");			
	scanf("%d",&element);
	ptr=(struct stack*)malloc(sizeof(struct stack));
	ptr->data=element;
	ptr->next=NULL;
	push_stack_link_list(ptr);
}
	
	
	void push_stack_link_list(struct stack* ptr)															/*FUNCTION TO PUSH() IN STACK USING LINKED LIST*/
{
	
	if(start==NULL)													/*IF STATEMENT*/
	{
		start=ptr;
	}
	else
	{
		ptr->next=start;
		start=ptr;
	}
	 
}

void pop_stack_link_list()																/*FUNCTION TO POP() IN STACK USING LINKED LIST*/				
{
	struct stack *ptr;
	if(start==NULL)														/*IF STATEMENT*/
	{
		printf("\nUNDERFLOW");
	}
	else if(start->next==NULL)
	{
		ptr=start;
		start=NULL;
		printf("\nThe deleted element is>>\t%d",ptr->data);
		free(ptr);

	}
	else
	{
		ptr=start;
		start=start->next;
		printf("\nThe deleted element is>>\t%d",ptr->data);
		free(ptr);
	}
}
void peep_stack_link_list()																	/*FUNCTION TO PEEP() IN STACK USING LINKED LIST*/
{
	struct stack *ptr;
	if(start==NULL)															/*IF STATEMENT*/
	{
		printf("\nUNDERFLOW");
		
	}
	else
	{
		ptr=start;
		printf("\n The top element in stack is>>\t%d",ptr->data);
	}
}
