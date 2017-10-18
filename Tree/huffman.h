#ifndef HUFFMAN_H
#define HUFFMAN_H

#define  N 20
#define  M (2*N-1)

typedef char * HuffmanCode;

typedef struct HuffmanNode
{
	unsigned int weight; // ������Ÿ�������Ȩֵ
	unsigned int parent;
	unsigned int lchild;
	unsigned int rchild; 
}HuffmanNode, * HuffmanTree;
 
/*****************************************************************************
 *      ѡ������Ȩֵ��С�Ľڵ�                                               *
 *****************************************************************************/
void select(HuffmanTree * ht, int pos, int * s1, int * s2);

/*****************************************************************************
 *     �����������                                                          *
 *****************************************************************************/
void CreateHuffmanTree(HuffmanTree * ht , int * w, int n);

/*****************************************************************************
 *     ��ӡ����������Ȩֵ                                                    *
 *****************************************************************************/
void OutputHuffman(HuffmanTree HT, int m);

/*****************************************************************************
 *     ��Ҷ�ӽ�㵽����������ÿ��Ҷ�ӽ���Ӧ�Ĺ���������                    *
 *****************************************************************************/
void CreateHuffmanCode(HuffmanTree * ht, HuffmanCode * hc, int n);

#endif
