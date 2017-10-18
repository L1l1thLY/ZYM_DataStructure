#ifndef AVLTREE_H
#define AVLTREE_H

typedef int KeyType;

typedef struct AVLTNode
{
	KeyType  			key ;  // 关键字的值
	int 				bf;
	struct AVLTNode *	lchild; // 左指针 
	struct AVLTNode *	rchild; // 右指针
}AVLTNode, *AVLTree;

/*****************************************************************************
 *    向平衡二叉树中插入节点                                                 * 
 *****************************************************************************/
void InsertAVLtree(AVLTree avlt, KeyType K);

/*****************************************************************************
 *    创建平衡二叉树                                                         * 
 *****************************************************************************/
void CreateAVLTree(AVLTree * bst, int len, KeyType key[]);

/*****************************************************************************
 *    先序遍历平衡二叉树                        							 * 
 *****************************************************************************/
void PreOrderAVLTree(AVLTree root);

#endif // END AVLTREE_H

