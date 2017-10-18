#ifndef LINKLIST_H 
#define LINKLIST_H

typedef enum Message{Success, Fail, Fatal, RangError, Uninitial, ImproperPositon} Message;

typedef int ElemType;

// �������ڵ㶨�� 
typedef struct LinkListNode   
{ 
	ElemType				data; // ������ 
	struct LinkListNode	* 	next; // ָ���� 
}LinkListNode, *LinkList;

// ˫�����ڵ㶨�� 
typedef struct DoubleLinkListNode
{
	ElemType					data;  // ������ 
	struct DoubleLinkListNode * prior; // ָ��ǰ�ڵ����һ���ڵ��ָ�� 
 	struct DoubleLinkListNode * next;  // ָ��ǰ�ڵ��ǰһ���ڵ��ָ�� 
}DoubleLinkListNode, *DoubleLinkList;

/**************************************************************************** 
 *          ��ʼ������L                                                     * 
 ****************************************************************************/
void InitialLinkList(LinkList * L); 

/**************************************************************************** 
 *          ��ͷ������һ������L                                             * 
 ****************************************************************************/
int CreateLinkListFromHead(LinkList L, ElemType e[], int len);

/**************************************************************************** 
 *          ��β������һ������L                                             * 
 ****************************************************************************/
int CreateLinkListFromTail(LinkList L, ElemType e[], int len);

/**************************************************************************** 
 *          ��������L                                                       * 
 ****************************************************************************/
void TravelLinkList(LinkList L); 

/**************************************************************************** 
 *          ��������L��ĳ��λ��(pos)�Ľڵ�                                  * 
 ****************************************************************************/
LinkListNode * GetLinkListNode(LinkList L, int pos);

/**************************************************************************** 
 *          ��������L��ĳ���ڵ�ֵΪe�Ľڵ�                                  * 
 ****************************************************************************/
LinkListNode * LocateLinkList(LinkList L, ElemType e);

/**************************************************************************** 
 *          ��������L�еĳ���                                               * 
 ****************************************************************************/
int LinkListLength(LinkList L);

/**************************************************************************** 
 *          ������L��ĳ��λ��(pos)����ֵΪe�ڵ�                             * 
 ****************************************************************************/
int InsertLinkList(LinkList L, int pos, ElemType e);

/**************************************************************************** 
 *          ɾ������L��ĳ��λ��(pos)��ֵΪe�ڵ�                             * 
 ****************************************************************************/
int DeleteLinkList(LinkList L, int pos, ElemType *e);

/**************************************************************************** 
 *          �ϲ�����LA������LB,�����غϲ��������                           * 
 ****************************************************************************/
LinkList MergeLinkList(LinkList LA, LinkList LB);

/**************************************************************************** 
 *          ����һ��ѭ��������                                              * 
 ****************************************************************************/
void CreateCircleLinkList(LinkList L, ElemType e[], int len);

/**************************************************************************** 
 *          ����˫������                                                    * 
 ****************************************************************************/
void CreateDoubleLinkList(DoubleLinkList L, ElemType e[], int len);

/**************************************************************************** 
 *          ��˫��������ĳ��λ�ò���ֵΪe�Ľڵ�                             * 
 ****************************************************************************/
int InsertDoublelinkList(DoubleLinkList L, int pos, ElemType e);

/**************************************************************************** 
 *          ɾ��˫��������ĳ��λ�õĽڵ㣬�ýڵ��ֵΪe                     * 
 ****************************************************************************/
int DeleteDoubleLinkList(DoubleLinkList L, int pos, ElemType *e);
#endif // ! LINKLIST_H