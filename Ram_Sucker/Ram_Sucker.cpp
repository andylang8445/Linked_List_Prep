#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define MAX 5

typedef struct {
	int score;
	char name[30];
	bool head = false;
	node* prev = NULL;
	node* next = NULL;
}node;

typedef struct {
	int count;
	node* head;
}linkedList;

void Init(linkedList *Lptr)
{
	Lptr->count = 0;
	Lptr->head = NULL;
}
void PoP(linkedList* Lptr)
{
	if (Lptr->count <= MAX)
	{
		return;
	}
	node* Temp = (node*)malloc(sizeof(node));
	Temp = Lptr->head;
	while (Temp->next->next != NULL)
	{
		Temp = Temp->next;
	}
	free(Temp->next);
	Temp->next = NULL;
	Lptr->count--;
}
void add(linkedList* Lptr, int data, char name[])
{
	Lptr->count++;
	node* Temp;//Searching pointer
	node* Nptr;//New pointer
	Temp = (node*)malloc(sizeof(node));
	Nptr = (node*)malloc(sizeof(node));
	Nptr->score = data;
	strcpy(Nptr->name, name);

	Temp = Lptr->head;
	while (Temp->next != NULL)
	{
		
		if (Temp->score < Nptr->score)//If the list is full
		{
			if (Temp->head)
			{
				Nptr->next = Temp;
				Lptr->head = Nptr;
				Nptr->head = true;
				Temp->head = false;

				Temp->prev = Nptr;
			}
			else
			{
				Nptr->next = Temp;
				Temp->prev->next = Nptr;

				Nptr->prev = Temp->prev;
				Temp->prev = Nptr;
			}
		}
		else if (Lptr->count < MAX)//If the list is not full
		{
			if(Temp->score<Nptr->score)
			{
				Nptr->next = Temp;
				Temp->prev->next = Nptr;

				Nptr->prev = Temp->prev;
				Temp->prev = Nptr;

				if (Temp->head)
				{
					Lptr->head = Nptr;
					Nptr->head = true;
					Temp->head = false;
				}
			}
			else
			{
				Temp->next = Nptr;
				Nptr->prev = Temp;
			}
		}
		Temp = Temp->next;
		PoP(Lptr);
	}
}


int main()
{
	linkedList* rank;
	Init(rank);
	
}