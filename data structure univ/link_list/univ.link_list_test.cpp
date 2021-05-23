// 연결리스트 수업 인용

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int n = 10;

typedef struct List {
	int data;
	struct List* next;
}list;

typedef struct Link {
	List* head;
	List* current;
	List* before;	
}link;

void Link_set(link* link)
{
	link->head = NULL;
	link->current = NULL;
	link->before = NULL;	
}

void Link_add(link* link, int indata)
{
	list* newlist = (list*)malloc(sizeof(list));
	newlist->data = indata;
	newlist->next = link->head;
	link->head = newlist;
}

int Link_remove(link* link, int indata)
{
	if (link->head == NULL)
	{
		printf(" 연결리스트 없음 \n");
		return 0;
	}
	link->current = link->head;
	while (link->current != NULL)
	{
		if (link->current->data == indata)
		{
			if (link->current == link->head)
			{
				link->head = link->head->next;
			}
			else
			{
				link->before->next = link->current->next;
			}						
			free(link->current);
			return 1;
		}
		else
		{
			link->before = link->current;
			link->current = link->current->next;
		}
	}
	printf(" [ %d ] 는 연결리스트에 존재하지 않음 \n", indata);
	
}

void Link_screen(Link* link)
{
	link->current = link->head;
	printf("연결리스트 : ");
	while (link->current != NULL)
	{
		printf("[ %2d ] ", link->current->data);
		link->current = link->current->next;
	}
	printf("\n");
}

int main(void)
{
	Link* link = (Link*)malloc(sizeof(Link));
	Link_set(link);
	
	printf("입력리스트 : ");
	for (int i = 0; i < n; i++)
	{
		int randdata = rand() % 99 + 1;
		Link_add(link, randdata);
		printf("[ %2d ] ", randdata);
	}
	printf("\n");
	Link_screen(link);
	
	int removedata = 999;
	printf(" 삭제 종료는 0 입력 \n");
	while (removedata != 0)
	{
		printf(" 삭제할 값 입력 --> ");
		scanf_s("%d", &removedata);
		Link_remove(link, removedata);
		Link_screen(link);
	}	
	return 0;
}