// #include "inssort.h"
// #include "binsort.h"
// #include "shellinsert.h"
// #include "bubblesort.h"
// #include "qksort.h"
// #include "selectsort.h"
// #include "heapsort.h"
// #include "merge.h"
 #include "radixsort.h"

#include <stdio.h>

/*****************************************************************************
*                   ����ʵ�ֵ�9������                                        * 
*                                                                            * 
* Description: main��������ʵ��9�������㷨�Ĳ��ԣ�ͨ��ȡ��ͷ�ļ�����ǰ��ע�� * 
* ��ʵ�ֶ�Ӧ�ķ����Ĳ��ԣ�ÿ��ֻ��ȡ��һ��ע�ͣ����򽫻���ִ���           * 
*                                                                            * 
******************************************************************************/

int main(int argc, char *argv[])
{

#ifdef INSSORT_H
	int 		i;
	int 		j;
	RecordType 	r[20];
	int 		len;

	printf("������������¼�ĳ���:");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		printf("�������%d����¼Ԫ��:",i);
		fflush(stdin);
		scanf("%d",&j);
		r[i].key = j;
	}
	printf("ԭʼ���ݣ�"); 
	for(i=1;i<=len;i++)
	{
		printf("%d\t",r[i].key);
	}	
	printf("\n");

	InsertSort(r,len);
	printf("�������ݣ�"); 
	for(i=1;i<=len;i++)
		printf("%d\t",r[i].key);
	printf("\n");
#endif

#ifdef BINSORT_H
	int 		i;
	int 		j;
	RecordType 	r[20];
	int 		len;

	printf("������������¼�ĳ���:");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		printf("�������%d����¼Ԫ��:",i);
		fflush(stdin);
		scanf("%d",&j);
		r[i].key = j;
	}
	printf("ԭʼ���ݣ�"); 
	for(i=1;i<=len;i++)
	{
		printf("%d\t",r[i].key);
	}	
	printf("\n");
	
	BinarySort(r,len);
	printf("�������ݣ�"); 
	for(i=1;i<=len;i++)
		printf("%d\t",r[i].key);
	printf("\n");
#endif

#ifdef SHELLINSERT_H
	int 		i;
	int 		j;
	RecordType 	r[20];
	int 		len;
	int 		delta[3]={4,2,1};
	
	printf("������������¼�ĳ���:");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		printf("�������%d����¼Ԫ��:",i);
		fflush(stdin);
		scanf("%d",&j);
		r[i].key = j;
	}
	printf("ԭʼ���ݣ�"); 
	for(i=1;i<=len;i++)
	{
		printf("%d\t",r[i].key);
	}	
	printf("\n");
	
	ShellSort(r,len,delta,3);
	printf("�������ݣ�"); 
	for(i=1;i<=len;i++)
		printf("%d\t",r[i].key);
	printf("\n");
#endif

#ifdef BUBBLESORT_H
	int 		i;
	int 		j;
	RecordType 	r[20];
	int 		len;
	
	printf("������������¼�ĳ���:");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		printf("�������%d����¼Ԫ��:",i);
		fflush(stdin);
		scanf("%d",&j);
		r[i].key = j;
	}
	printf("ԭʼ���ݣ�"); 
	for(i=1;i<=len;i++)
	{
		printf("%d\t",r[i].key);
	}	
	printf("\n");
	
	BubbleSort(r,len);
	printf("�������ݣ�"); 
	for(i=1;i<=len;i++)
		printf("%d\t",r[i].key);
	printf("\n");
#endif

#ifdef QKSORT_H
	int 		i;
	int 		j;
	RecordType 	r[20];
	int 		len;
	
	printf("������������¼�ĳ���:");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		printf("�������%d����¼Ԫ��:",i);
		fflush(stdin);
		scanf("%d",&j);
		r[i].key = j;
	}
	printf("ԭʼ���ݣ�"); 
	for(i=1;i<=len;i++)
	{
		printf("%d\t",r[i].key);
	}	
	printf("\n");
	QuickSort(r,1,len);
	printf("�������ݣ�"); 
	for(i=1;i<=len;i++)
		printf("%d\t",r[i].key);
	printf("\n");
#endif

#ifdef SELECTSORT_H
	int 		i;
	int 		j;
	RecordType 	r[20];
	int 		len;
	
	printf("������������¼�ĳ���:");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		printf("�������%d����¼Ԫ��:",i);
		fflush(stdin);
		scanf("%d",&j);
		r[i].key = j;
	}
	printf("ԭʼ���ݣ�"); 
	for(i=1;i<=len;i++)
	{
		printf("%d\t",r[i].key);
	}	
	printf("\n");
	
	SelectSort(r,len);
	printf("�������ݣ�"); 
	for(i=1;i<=len;i++)
		printf("%d\t",r[i].key);
	printf("\n");
#endif

#ifdef HEAPSORT_H
    int 		i;
	int 		j;
	RecordType 	r[20];
	int 		len;
	
	printf("������������¼�ĳ���:");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		printf("�������%d����¼Ԫ��:",i);
		fflush(stdin);
		scanf("%d",&j);
		r[i].key = j;
	}
	printf("ԭʼ���ݣ�"); 
	for(i=1;i<=len;i++)
	{
		printf("%d\t",r[i].key);
	}	
	printf("\n");
	
	HeapSort(r,len);
	printf("�������ݣ�"); 
	for(i=1;i<=len;i++)
		printf("%d\t",r[i].key);
	printf("\n");
#endif

#ifdef MERGE_H
	int 		i;
	int 		j;
	RecordType 	r[20];
	int 		len;
	
	printf("������������¼�ĳ���:");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		printf("�������%d����¼Ԫ��:",i);
		fflush(stdin);
		scanf("%d",&j);
		r[i].key = j;
	}
	printf("ԭʼ���ݣ�"); 
	for(i=1;i<=len;i++)
	{
		printf("%d\t",r[i].key);
	}	
	printf("\n");
	MergeSort(r,len);
	printf("�������ݣ�"); 
	for(i=1;i<=len;i++)
		printf("%d\t",r[i].key);
	printf("\n");
#endif

#ifdef RADIXSORT_H
	int 				i;
	int 				j;
	RadixRecordTypeNode r[20];
	int 				len;
	int 				p;
	
	printf("������������¼�ĳ���:");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		printf("�������%d����¼Ԫ��:",i);
		fflush(stdin);
		scanf("%d",&j);
		r[i].key[0] = j / 100;
		r[i].key[1] = (j- 100*r[i].key[0]) / 10;
		r[i].key[2] = (j- 100*r[i].key[0]- 10*r[i].key[1]);
	}
	printf("ԭʼ���ݣ�"); 
	for(i=1;i<=len;i++)
	{
		printf("%d\t",r[i].key[0]*100+r[i].key[1]*10+r[i].key[2]);
	}	
	printf("\n");
	
	RadixSort(r,len); 
	printf("�������ݣ�"); 
	p = r[0].next;
	while(p!=0)
	{
		printf("%d\t",r[p].key[0]*100+r[p].key[1]*10+r[p].key[2]);
		p = r[p].next;
	}
	printf("\n");
#endif
	
	return 0;
}