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
	
	printf("��������������������[%d��ʾҶ�ӽڵ�]:\n\
 %d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n", 
	       ENDIDENTIFIER, 1, 2, 4, ENDIDENTIFIER, ENDIDENTIFIER, 5, 
		   ENDIDENTIFIER, ENDIDENTIFIER, 3, 6, ENDIDENTIFIER, ENDIDENTIFIER,
		   ENDIDENTIFIER);
	CreateBiTree(&bt, key, &pos);
	
	printf("�������:\n");
	PreOrder(bt);
	
	printf("\n�������:\n");
	InOrder(bt);
	
	printf("\n�������:\n");
	PostOrder(bt);
	
	printf("\nǰ��Ҷ�ӽڵ����:\n");
	PreOrderLeaves(bt);
	
	printf("\n����ǵݹ����:\n");
	InOrderNonRecursion(bt);
	
	printf("\n����ǵݹ����:\n");
	PostOrderNonRecursion(bt); 
	
	printf("\n��������״��ӡ�Ķ�����:\n");
	PrintTree(bt, 1);
		
	printf("\n��α���������:\n");
	LayerOrder(bt); 
	
	lc1 = 0;
	LeafCount(bt, &lc1); 
	printf("\nҶ�ӽڵ����:%d\n", lc1);
    lc2 = LeafCountNonRecursion(bt); 
    printf("Ҷ�ӽڵ����(�ǵݹ�):%d\n", lc2);
    
	ptd1 = PostTreeDepth(bt);
 	printf("�����(����):%d\n", ptd1);
 	ptd2 = 1;
    PreTreeDepth(bt, &ptd2, 1);   
	printf("�����(ǰ��):%d\n", ptd2);
	
	return 0;
}

