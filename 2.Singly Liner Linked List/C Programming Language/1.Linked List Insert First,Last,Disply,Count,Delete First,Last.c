#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsetFirst(PPNODE Head,int no)
{
	PNODE newn=NULL;
	
	//Step 1:allocate the memory
	newn=(PNODE)malloc(sizeof(NODE));
	
	//Step 2:Intalise the node
	newn->data=no;
	newn->next=NULL;
	
	//Step 3:Insert node
	if(*Head==NULL)//LL is Empty
	{
		*Head=newn;
	}
	else //LL Contains at Lest one node
	{
		newn->next=*Head;
		*Head=newn;
	}
}

void InsertLast(PPNODE Head,int no)
{
	PNODE newn=NULL;
	PNODE temp=*Head;
	//Step 1:allocate the memory
	newn=(PNODE)malloc(sizeof(NODE));
	
	//Step 2:Intalise the node
	newn->data=no;
	newn->next=NULL;
	
	//Step 3:Insert node
	if(*Head==NULL)//LL is Empty
	{
		*Head=newn;
	}
	else //LL Contains at Lest one node
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
	}
	
}

void Display(PNODE Head)
{
	while(Head !=NULL)
	{
		printf("%d\t",Head->data);
		Head=Head->next;
	}
}

int Count(PNODE Head)
{
	int iCnt=0;
	while(Head !=NULL)
	{
		iCnt++;
		Head=Head->next;
	}
	return iCnt;
}

void DeleteFirst(PPNODE Head)
{
	PNODE temp=*Head;
	if(*Head!=NULL)  //if LL contains atleast one node
	{
		*Head=(*Head)->next;
		free (temp);
	}
}

void DeleteLast(PPNODE Head)
{
	PNODE temp=*Head;
	if(*Head==NULL)  //LL is empty
	{
		return;
	}
	else if((*Head)->next==NULL)  //LL contain one node
	{
		free(*Head);
		*Head=NULL;
	}
	else  //LL Contain More than one
	{
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		free(temp->next);
		temp->next=NULL;
	}
}
int main()
{
	PNODE First=NULL;
	int iRet=0;
	
	InsetFirst(&First,51);//InsetFirst(50,51)
	InsetFirst(&First,21);//InsetFirst(50,21)
	InsetFirst(&First,11);//InsetFirst(50,11)
	
	InsertLast(&First,111);
	
	Display(First);  //Display(100);
	
	iRet=Count(First);
	printf("\nNumber of Elements are %d\n",iRet);
	
	DeleteFirst(&First);
	Display(First);
	Count(First);
	
	iRet=Count(First);
	printf("\nNumber of Elements are %d\n",iRet);
	DeleteLast(&First);
	Display(First);
	Count(First);
	
	return 0;
}
/*
	void InsetFirst(PPNODE Head,int no)
	void InsertLast(PPNODE Head,int no)
	void InsertAtPos(PPNODE Head,int no,int pos)
	void DeleteFirst(PPNODE Head)
	void DeleteLast(PPNODE Head)
	void DeleteAtPos(PPNODE Head,int Pos)
	
	void Display(PNODE Head)
	int Count(PNODE Head)

*/
