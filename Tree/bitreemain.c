#include "bitree.h"

int main(int argc, char *argv[])
{
	BiTree 	bt;
	int 	lc1;
	int 	lc2;
	int 	ptd1;
	int 	ptd2;
	int		pos;
	
	pos = 0;
	DataType key[RANGE] = {1, 2, 4, ENDIDENTIFIER, ENDIDENTIFIER, 5, 
						   ENDIDENTIFIER, ENDIDENTIFIER, 3, 6, ENDIDENTIFIER,
						   ENDIDENTIFIER, ENDIDENTIFIER};
	
	printf("按先序建立二叉树，输入[%d表示叶子节点]:\n\
 %d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n", 
	       ENDIDENTIFIER, 1, 2, 4, ENDIDENTIFIER, ENDIDENTIFIER, 5, 
		   ENDIDENTIFIER, ENDIDENTIFIER, 3, 6, ENDIDENTIFIER, ENDIDENTIFIER,
		   ENDIDENTIFIER);
	CreateBiTree(&bt, key, &pos);
	
	printf("先序遍历:\n");
	PreOrder(bt);
	
	printf("\n中序遍历:\n");
	InOrder(bt);
	
	printf("\n后序遍历:\n");
	PostOrder(bt);
	
	printf("\n前序叶子节点遍历:\n");
	PreOrderLeaves(bt);
	
	printf("\n中序非递归遍历:\n");
	InOrderNonRecursion(bt);
	
	printf("\n后序非递归遍历:\n");
	PostOrderNonRecursion(bt); 
	
	printf("\n按竖向树状打印的二叉树:\n");
	PrintTree(bt, 1);
		
	printf("\n层次遍历二叉树:\n");
	LayerOrder(bt); 
	
	lc1 = 0;
	LeafCount(bt, &lc1); 
	printf("\n叶子节点个数:%d\n", lc1);
    lc2 = LeafCountNonRecursion(bt); 
    printf("叶子节点个数(非递归):%d\n", lc2);
    
	ptd1 = PostTreeDepth(bt);
 	printf("树深度(后序):%d\n", ptd1);
 	ptd2 = 1;
    PreTreeDepth(bt, &ptd2, 1);   
	printf("树深度(前序):%d\n", ptd2);
	
	return 0;
}

