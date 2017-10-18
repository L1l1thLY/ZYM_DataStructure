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
		*bt=(BiNode *)malloc(sizeof(BiNode)); //生成一个新结点
        (*bt)->data = dts[*pos];
		(*pos)++;
        CreateBiTree(&((*bt)->lchild), dts, pos); //生成左子树
        CreateBiTree(&((*bt)->rchild), dts, pos); //生成右子树
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
		visit(root ->data);       // 访问根结点
		PreOrder(root ->lchild);  // 先序遍历左子树
		PreOrder(root ->rchild);  // 先序遍历右子树
	}
}

void InOrder(BiTree root)  
{
	if (root!=NULL)
	{
		InOrder(root ->lchild);   // 中序遍历左子树
		visit(root ->data);       // 访问根结点
		InOrder(root ->rchild);   // 中序遍历右子树
	}
}

void PostOrder(BiTree root)  
{
	if(root!=NULL)
	{
		PostOrder(root ->lchild); // 后序遍历左子树
		PostOrder(root ->rchild); // 后序遍历右子树
		visit(root ->data);       // 访问根结点
	}
}

void PreOrderLeaves(BiTree root) 
{
	if (root!=NULL)
	{
		if (root->lchild==NULL && root->rchild==NULL)
			visit(root->data);         //  输出叶子结点 
		PreOrderLeaves(root->lchild);  //  先序遍历左子树 
		PreOrderLeaves(root->rchild);  //  先序遍历右子树 
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
		else                           //  叶子数为左右子树的叶子数目之和 
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
		hl=PostTreeDepth(bt->lchild);  // 求左子树的深度 
		hr=PostTreeDepth(bt->rchild);  // 求右子树的深度 
		max = hl > hr ? hl : hr;       // 得到左、右子树深度较大者
		return(max+1);                 // 返回树的深度 
	}
	else return(0);                    // 如果是空树，则返回0 
}

int PreTreeDepth(BiTree bt, int * h, int cur)
{
    if(bt!=NULL)
    {
        if( *h < cur)   
		{
			*h = cur;
		}
        PreTreeDepth(bt->lchild, h, cur+1);  // 遍历左子树 
        PreTreeDepth(bt->rchild, h, cur+1);  // 遍历右子树 
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
		}                    // 遍历左子树 
		if(top!=0)
		{ 
			p=s[top];
			top=top-1;
			visit(p->data);  // 访问根结点 
			p=p->rchild;     // 遍历右子树 
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
	s = (BiNode **)malloc(sizeof(BiNode *) * NUM); // NUM为预定义的常数 
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
			if((p->rchild==NULL) ||(p->rchild==q)) // 无右孩子，或右孩子已遍历过 
			{
			    visit(p->data);        // 访问根结点
				q=p;                   // 保存到q，为下一次已处理结点前驱 
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
	
	InitQueue(Q);                 // 初始化空队列Q
	if(bt == NULL)
	{
		return msgfail;           // 若二叉树bt为空树，则结束遍历
	}
	EnterQueue(Q, bt);            // 若二叉树bt非空，则根结点bt入队开始层次遍历
	while(!IsEmpty(Q))            // 若队列非空，则遍历为结束，继续进行
	{ 
		DeleteQueue(Q, &p);       // 队头元素出队并访问 
		visit(p->data);
		if(p->lchild )  
		{
			EnterQueue(Q, p->lchild); // 若p的左孩子非空，则进队 
		}
		if(p->rchild ) 
		{
			EnterQueue(Q, p->rchild); // 若p的右孩子非空，则进队 
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
