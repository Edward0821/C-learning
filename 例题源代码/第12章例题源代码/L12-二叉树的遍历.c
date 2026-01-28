#include <stdio.h>
#include <stdlib.h>
#define N 20
//二叉树节点信息
typedef struct BiTNode
{
	int            data;
	struct BiTNode *lchild;//左子树
	struct BiTNode *rchild;//右子树
}BI_TREE;
BI_TREE *CreatTree(int *a, int n);
int  PreOrderTraverse(BI_TREE *root, void (*visit)(int));
int MidOrderTraverse(BI_TREE *root, void (*visit)(int));
int PostOrderTraverse(BI_TREE *root, void (*visit)(int));
void PrintNode(int node);
int main(void)
{
	int a[N] = {1, 2, 3, 4, 5, 6, 7};
	int n = 7;
	BI_TREE *root = NULL;
	root = CreatTree(a, n);
	PreOrderTraverse(root, PrintNode);
	printf("\n");
	MidOrderTraverse(root, PrintNode);
	printf("\n");
	PostOrderTraverse(root, PrintNode);
	printf("\n");
	return 0;
}
//函数功能：二叉树创建
BI_TREE *CreatTree(int *a, int n)
{
	int i;
	BI_TREE *pNode[N] = {0};
	for (i=0; i<n; ++i)
	{
		pNode[i] = (BI_TREE *)malloc(sizeof(BI_TREE));
		if (pNode[i] == NULL)
		{
			printf("No enough memory to allocate!\n");
			exit(1);
		}
		pNode[i]->lchild = NULL;
		pNode[i]->rchild = NULL;
		pNode[i]->data = a[i];
	}
	for (i=0; i<n/2; ++i)
	{
		pNode[i]->lchild = pNode[2*(i+1)-1];
		pNode[i]->rchild = pNode[2*(i+1)+1-1];
	}
	return pNode[0];
}
//函数功能：二叉树先序遍历
int  PreOrderTraverse(BI_TREE *root, void (*visit)(int))
{
	if (root == NULL)
	{
		return 1;
	}
	(*visit)(root->data);
	if (PreOrderTraverse(root->lchild, visit))
	{
		if (PreOrderTraverse(root->rchild, visit))
		{
			return 1;
		}
	}
	return 0;
}
//函数功能：二叉树中序遍历
int MidOrderTraverse(BI_TREE *root, void (*visit)(int))
{
	if (root == NULL)
	{
		return 1;
	}
	if (MidOrderTraverse(root->lchild, visit))
	{
		(*visit)(root->data);
		if (MidOrderTraverse(root->rchild, visit))
		{
			return 1;
		}
	}
	return 0;
}
//函数功能：二叉树后序遍历
int PostOrderTraverse(BI_TREE *root, void (*visit)(int))
{
	if (root == NULL)
	{
		return 1;
	}
	if (PostOrderTraverse(root->lchild, visit))
	{
		if (PostOrderTraverse(root->rchild, visit))
		{
			(*visit)(root->data);
			return 1;
		}
	}
	return 0;
}
//函数功能：打印节点信息
void PrintNode(int node)
{
	printf("%3d", node);
}
