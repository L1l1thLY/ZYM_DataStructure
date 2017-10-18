#ifndef AVLTREE_H
#define AVLTREE_H

typedef int KeyType;

typedef struct AVLTNode
{
	KeyType  			key ;  // �ؼ��ֵ�ֵ
	int 				bf;
	struct AVLTNode *	lchild; // ��ָ�� 
	struct AVLTNode *	rchild; // ��ָ��
}AVLTNode, *AVLTree;

/*****************************************************************************
 *    ��ƽ��������в���ڵ�                                                 * 
 *****************************************************************************/
void InsertAVLtree(AVLTree avlt, KeyType K);

/*****************************************************************************
 *    ����ƽ�������                                                         * 
 *****************************************************************************/
void CreateAVLTree(AVLTree * bst, int len, KeyType key[]);

/*****************************************************************************
 *    �������ƽ�������                        							 * 
 *****************************************************************************/
void PreOrderAVLTree(AVLTree root);

#endif // END AVLTREE_H

