// 2 way - tree
/*
* // 전위 후위 방식 채택
* 재귀함수 사용
tree -> left // 전위 좌측부터
tree -> right // 후위 우측부터
위를 재귀함수로 data 가 NULL 일때까지 진행 후 리턴
*/

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>

#define line printf("\n────────────────LINE────────────────\n");

#define Max_size 9
#define Temp 20

typedef struct tree { // 데이터 + 좌측링크 + 우측링크
	int data;
	struct tree* left;
	struct tree* right;
}t;

tree* maketree(int data)
{
	// 트리 동적할당으로 만듬 / 데이터만 가지고 좌측 우측 링크는 NULL초기화
	tree* newtree = (tree*)malloc(sizeof(tree));
	newtree->left = NULL;
	newtree->right = NULL;
	newtree->data = data;

	return newtree;
}

void display(int temp[Temp])
{
	int level = 1;
	int index = 0;

	int i = 1;
	int levelmax = 0;

	printf("Temp = %3d\n", Temp);

	while (i < Temp)
	{
		while (i <= pow(2, level) - 1)
			i++;
		level++;
	}
	levelmax = level-1;
	printf("%d", levelmax);

	i = 1, level = 1;
	while (i < Temp)
	{		
		for (int j = Temp-level*2; j >= 0; j--)
		{
			printf("　");
		}
		while (i <= pow(2, level) - 1)
		{
			for (int j = levelmax; j > 0; j--)
			{
				printf("  ");
			}		
			if (i < Temp)
			{				
				
				printf("[%d]", temp[i]);		
			}
			i++;
		}
		printf("\n");
		level++;
		levelmax--;
	}
}

void preorder(tree* bt) // 전위
{
	if (bt == NULL)
		return;
	printf(" %d -> ", bt->data);
	preorder(bt->left);
	preorder(bt->right);
}

void inorder(tree* bt) // 중위
{
	if (bt == NULL)
		return;
	
	inorder(bt->left);
	printf(" %d -> ", bt->data);
	inorder(bt->right);
}

void postorder(tree* bt) // 후위
{
	if (bt == NULL)
		return;	
	postorder(bt->left);
	postorder(bt->right);
	printf(" %d -> ", bt->data);
}

int main(void)
{
	line;
	tree* tree[Max_size], *root, *current;
	int temp[Temp] = { 0, 1 };
	int i = 0;

	for (i = 0; i < Max_size; i++)
	{
		tree[i] = maketree(i + 1);
	}

	root = tree[0];	

	for (i = 1; i < Max_size; i++)
	{
		int flag = 1, count = 1;
		current = root;	
		
		while (flag) // flag 의 값 변경전까지 무한반복 위 Max가 9임으로 최대 9
		{
			switch (rand()%2)
			{
			case 0:
				if (current->left == NULL)
				{
					current->left = tree[i];
					flag = 0;
					count = count * 2 - 1;
					temp[count] = tree[i]->data;
				}
				else
				{
					current = current->left;
					count = count * 2;
				}
					break;

			case 1:
				if (current->right == NULL)
				{
					current->right = tree[i];
					flag = 0;
					count = count * 2 + 1;
					temp[count] = tree[i]->data;
				}
				else
				{
					current = current->right;
					count = count * 2 + 1;
				}
				break;
			
			default:
				break;
			}
		}
	}

	display(temp);
	preorder(root);
	line;
	display(temp);
	inorder(root);
	line;
	display(temp);
	postorder(root);

	line;
	return 0;
}