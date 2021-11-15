#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

int main()
{
	PNODE First=NULL;
	
	//call by value
	fun(First);      //fun(100)         
	//Display(),Count()
	
	//call by address
	gun(&First);    //gun(50)           
	//InsetFirst(),InsetLast(),InsertAtPos(),DeleteFirst(),DeleteLast(),DeleteAtPos()
	
	return 0;
}
