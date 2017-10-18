#include "bitree.h"
#include <stdio.h>
#include <malloc.h>
#include <conio.h>

void CreateBiTree(BiTree *bt, DataType dts[], int * pos)
{
    if( ENDIDENTIFIER == dts[*pos])
	{
		*bt=NULL;
		(*pos)++;
    }
	else 
	{
		*bt=(BiNode *)malloc(sizeof(BiNode)); //����һ���½��
        (*bt)->data = dts[*pos];
		(*pos)++;
        CreateBiTree(&((*bt)->lchild), dts, pos); //����������
        CreateBiTree(&((*bt)->rchild), dts, pos); //����������
	}
}

void visit(DataType dt)
{
	printf("%4d\t", dt);
}

void PreOrder(BiTree root) 
{
	if (root!=NULL)
	{
		visit(root ->data);       // ���ʸ����
		PreOrder(root ->lchild);  // �������������
		PreOrder(root ->rchild);  // �������������
	}
}

void InOrder(BiTree root)  
{
	if (root!=NULL)
	{
		InOrder(root ->lchild);   // �������������
		visit(root ->data);       // ���ʸ����
		InOrder(root ->rchild);   // �������������
	}
}

void PostOrder(BiTree root)  
{
	if(root!=NULL)
	{
		PostOrder(root ->lchild); // �������������
		PostOrder(root ->rchild); // �������������
		visit(root ->data);       // ���ʸ����
	}
}

void PreOrderLeaves(BiTree root) 
{
	if (root!=NULL)
	{
		if (root->lchild==NULL && root->rchild==NULL)
			visit(root->data);         //  ���Ҷ�ӽ�� 
		PreOrderLeaves(root->lchild);  //  ������������� 
		PreOrderLeaves(root->rchild);  //  ������������� 
	}
}

int LeafCount(BiTree root, int * sum)
{   
	if(root!=NULL)
	{
		if ((root->lchild==NULL) && (root->rchild==NULL))
			(*sum)++;
		LeafCount(root->lchild, sum);
		LeafCount(root->rchild, sum);
	}
	return 0;
}

int LeafCountNonRecursion(BiTree root)
{
	int sum;
	sum = 0;
	if(root==NULL)
	{
		sum = 0;
	}
	else 
	{
		if((root->lchild==NULL)&&(root->rchild==NULL))
		{
			sum =1;
		}
		else                           //  Ҷ����Ϊ����������Ҷ����Ŀ֮�� 
		{
			sum =LeafCountNonRecursion(root->lchild)+
			LeafCountNonRecursion(root->rchild);
		}
	}
	
	return sum;
}

int PostTreeDepth(BiTree bt)           
{
	int hl;
	int hr;
	int max;
	
	if(bt!=NULL)
	{
		hl=PostTreeDepth(bt->lchild);  // ������������� 
		hr=PostTreeDepth(bt->rchild);  // ������������� 
		max = hl > hr ? hl : hr;       // �õ�����������Ƚϴ���
		return(max+1);                 // ����������� 
	}
	else return(0);                    // ����ǿ������򷵻�0 
}

int PreTreeDepth(BiTree bt, int * h, int cur)
{
    if(bt!=NULL)
    {
        if( *h < cur)   
		{
			*h = cur;
		}
        PreTreeDepth(bt->lchild, h, cur+1);  // ���������� 
        PreTreeDepth(bt->rchild, h, cur+1);  // ���������� 
     }
     return 0;
}

void PrintTree(BiTree bt,int nLayer)        
{   int i;
	if(bt == NULL) return;
	PrintTree(bt->rchild,nLayer+1);
	for(i=0;i<nLayer;i++)
		printf("  ");
	printf("%d\n",bt->data);
	PrintTree(bt->lchild,nLayer+1);
}

void InOrderNonRecursion(BiTree root)     
{
	int		top; 
	BiTree	p;
	BiTree	s[STACKSIZE];
	int		m;
	
	top = 0;
	m = STACKSIZE-1;
	p = root;
	
	do
	{
		while(p!=NULL)
		{ 
			if (top>m) return;
			top=top+1;  
			s[top]=p;
			p=p->lchild;
		}                    // ���������� 
		if(top!=0)
		{ 
			p=s[top];
			top=top-1;
			visit(p->data);  // ���ʸ���� 
			p=p->rchild;     // ���������� 
		}   
	}
	while(p!=NULL || top!=0);
}

void PostOrderNonRecursion(BiTree root)
{
	BiNode * 	p;
	BiNode * 	q;
	BiNode ** 	s;
	int 		top;
	
	top = 0;
	q = NULL;
	p = root;
	s = (BiNode **)malloc(sizeof(BiNode *) * NUM); // NUMΪԤ����ĳ��� 
	while(p!=NULL || top!=0)
	{
		while(p!=NULL)
		{
			top++; 
			s[top]=p; 
			p=p->lchild; 
		}
		if(top>0) 
		{
			p=s[top];
			if((p->rchild==NULL) ||(p->rchild==q)) // ���Һ��ӣ����Һ����ѱ����� 
			{
			    visit(p->data);        // ���ʸ����
				q=p;                   // ���浽q��Ϊ��һ���Ѵ�����ǰ�� 
				top--;
				p=NULL;
			} 
			else
			{
				p=p->rchild;
			}
		}
	}
	free(s);
}

int LayerOrder(BiTree bt)
{ 
	SeqQueue 	*Q;
	BiTree  	p;
	
	Message msgsuccess, msgfail;
	
	msgsuccess = Success;
	msgfail = Fail;
	
	Q=(SeqQueue *)malloc(sizeof(SeqQueue));
	
	InitQueue(Q);                 // ��ʼ���ն���Q
	if(bt == NULL)
	{
		return msgfail;           // ��������btΪ���������������
	}
	EnterQueue(Q, bt);            // ��������bt�ǿգ�������bt��ӿ�ʼ��α���
	while(!IsEmpty(Q))            // �����зǿգ������Ϊ��������������
	{ 
		DeleteQueue(Q, &p);       // ��ͷԪ�س��Ӳ����� 
		visit(p->data);
		if(p->lchild )  
		{
			EnterQueue(Q, p->lchild); // ��p�����ӷǿգ������ 
		}
		if(p->rchild ) 
		{
			EnterQueue(Q, p->rchild); // ��p���Һ��ӷǿգ������ 
		}
	}
	
	return msgsuccess;
}


















void InitQueue(SeqQueue *Q)
{  
	Q->front = Q->rear = 0;
}

int EnterQueue(SeqQueue *Q, QueueElementType x)
{  
	if((Q->rear+1)%MAXSIZE==Q->front)
	{
		return Fail;
	}
	Q->element[Q->rear]=x;
	Q->rear=(Q->rear+1)%MAXSIZE;
	
	return Success; 
}

int DeleteQueue(SeqQueue *Q, QueueElementType *x)
{ 
	if(Q->front==Q->rear) 
	{
		return Fail;
	}
	*x = Q->element[Q->front];
	Q->front = (Q->front+1) % MAXSIZE;
	
	return Success;
}

int GetHead(SeqQueue *Q, QueueElementType *x)
{ 
	if(Q->front==Q->rear) 
	{
		return Fail;
	}
	*x=Q->element[Q->front];
	
	return Success;
}

int IsEmpty(SeqQueue *Q)
{ 
	if(Q->front==Q->rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void InitStack(SeqStack * S)
{
    S->top = -1;
}

int IsStackEmpty(SeqStack * S)
{
	return(S->top==-1? 1 : 0);
}

int IsFull(SeqStack * S)
{
	return(S->top==STACKSIZE-1? 1 : 0);
}

int Push(SeqStack * S,StackElementType x)
{
	if(S->top==STACKSIZE-1)  
	{
		return Fail;
	}	
	S->top++;
	S->elem[S->top] = x;
	
	return Success;
}

int Pop(SeqStack * S,StackElementType * x)
{  
	if(S->top == -1)  
	{
		return Fail;
	}
	else
	{
  		*x = S->elem[S->top];
		S->top--;
  		return Success;
	}
}
