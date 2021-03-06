#ifndef SEQSTACK_H
#define SEQSTACK_H 

#define STACKSIZE	50

typedef char SeqStackElementType; 

// ˳��ջ�ṹ�嶨�� 
typedef struct SeqStackNode
{
	SeqStackElementType	elem[STACKSIZE]; // �������ջ��Ԫ�ص�һά����
	int					top;          	  // �������ջ��Ԫ�ص��±꣬
	                                      // topΪ-1��ʾ��ջ
}SeqStack;

/*****************************************************************************
 *             ˳��ջ��ʼ��                                                  *    
 *****************************************************************************/
void InitialSeqStack(SeqStack * S);

/*****************************************************************************
 *             �ж�˳��ջ�Ƿ�Ϊ��                                            *
 *****************************************************************************/
int IsSeqStackEmpty(SeqStack * S);

/*****************************************************************************
 *             �ж�˳��ջ�Ƿ�����                                            *
 *****************************************************************************/
int IsSeqStackFull(SeqStack * S); 

/*****************************************************************************
 *             ˳��ջѹջ                                                    *
 *****************************************************************************/ 
int SeqStackPush(SeqStack * S,SeqStackElementType x);

/*****************************************************************************
 *             ˳��ջ��ջ                                                    *
 *****************************************************************************/ 
int SeqStackPop(SeqStack * S,SeqStackElementType * x);

/*****************************************************************************
 *             ˳��ջȡ��ջ��Ԫ��                                            *
 *****************************************************************************/
int GetSeqStackTop(SeqStack * S,SeqStackElementType * x);

/*****************************************************************************
 *             �������ŵ����ƥ��                                            *
 *****************************************************************************/
int Match(char cstart, char cend);

#endif // END SEQSTACK_H 
