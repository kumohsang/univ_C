/*
1. 연결리스트 안보고 타이핑해서 만들기
2. 새로운 입력은 헤드를 가르키게 작업
*/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct _List {
	int data;
	struct _List* next;
}list;

typedef struct _Link {
	_List* head;
	_List* now;
	_List* back;
}link;

void indata(link* cl, int data)
{	
	list* newlist = (list*)malloc(sizeof(list));
	newlist->data = data;
	newlist->next = cl->head;
	cl->head = newlist;
}

void screendata(link* cl)
{
	if (cl->head != NULL)
	{
		printf("연결리스트 ---> ");
		cl->now = cl->head;
		while (cl->now != NULL)
		{
			printf("[%d] ", cl->now->data);
			cl->now = cl->now->next;
		}
		printf("\n\n");
	}
	else
	{
		printf("[출력불가] 연결리스트 없음\n");
	}
}

int removedata(link* cl, int redata)
{
	if (cl->head == NULL)
	{
		printf("[삭제불가] 연결리스트 없음\n");
		return 0;
	}
	else
	{
		if (cl->head->data == redata)
		{
			cl->back = cl->head;
			cl->now = cl->head;
			cl->now = cl->now->next;
			cl->head = cl->now;
			printf("[%d]가 삭제되었습니다\n", cl->back->data);
			free(cl->back);			
			return 1;
		}
		else
		{			
			cl->back = cl->head;
			cl->now = cl->head;			
			while (cl->now!= NULL)
			{				
				if (cl->now->data == redata)
				{					
					cl->back->next = cl->now->next;
					printf("[%d]가 삭제되었습니다\n",cl->now->data);
					free(cl->now);					
					return 1;
				}
				else
				{
					cl->back = cl->now;
					cl->now = cl->now->next;
				}				
			}			
			printf("[%d]값이 리스트에 없음\n", redata);
			return 0;						
		}
	}
}

int main(void)
{
	link* cl = (link*)malloc(sizeof(link));
	
	cl->head = NULL;
	cl->now = NULL;
	cl->back = NULL;	

	indata(cl, 12);	
	indata(cl, 13);	
	indata(cl, 14);
	screendata(cl);
	removedata(cl, 11);	
	removedata(cl, 12);	
	removedata(cl, 13);	
	removedata(cl, 14);	
	removedata(cl, 15);	
	screendata(cl);
	
	int n;
	printf("\n\n입력시 종료");
	scanf_s("%d", &n);

	return 0;
}