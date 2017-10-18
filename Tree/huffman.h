#ifndef HUFFMAN_H
#define HUFFMAN_H

#define  N 20
#define  M (2*N-1)

typedef char * HuffmanCode;

typedef struct HuffmanNode
{
	unsigned int weight; // 用来存放各个结点的权值
	unsigned int parent;
	unsigned int lchild;
	unsigned int rchild; 
}HuffmanNode, * HuffmanTree;
 
/*****************************************************************************
 *      选择两个权值最小的节点                                               *
 *****************************************************************************/
void select(HuffmanTree * ht, int pos, int * s1, int * s2);

/*****************************************************************************
 *     构造哈夫曼树                                                          *
 *****************************************************************************/
void CreateHuffmanTree(HuffmanTree * ht , int * w, int n);

/*****************************************************************************
 *     打印哈夫曼树的权值                                                    *
 *****************************************************************************/
void OutputHuffman(HuffmanTree HT, int m);

/*****************************************************************************
 *     从叶子结点到根，逆向求每个叶子结点对应的哈夫曼编码                    *
 *****************************************************************************/
void CreateHuffmanCode(HuffmanTree * ht, HuffmanCode * hc, int n);

#endif
