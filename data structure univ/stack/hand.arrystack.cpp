#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define line printf("\n\n-------------------- LINE --------------------\n");
#define size 9

int main(void)
{
	int top = -1;	
	int arr[size] = {};
	line;
	printf("%10s","push : ");
	for (int i = 0; i < size; i++)
	{
		if (top < size)
		{
			top++;
			arr[top] = rand() % 9 + 1;
			printf(" %d ->", arr[top]);
		}
	}
	line;
	printf("%10s", "screen : ");
	for (int i = top; i >=0; i--)
	{
		printf(" %d ->", arr[i]);
	}

	line;
	printf("%10s","pop : ");
	for (int i = size; i >= 0; i--)
	{
		if (top != -1)
		{
			printf(" %d ->", arr[top]);
			top--;
		}
	}
	line;
	return 0;
}