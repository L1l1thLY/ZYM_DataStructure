#include "inssort.h"

void InsertSort(RecordType r[], int length)
{ 
	int i;
	int j;
	for(i = 2;  i <= length; i++) 
	{
		r[0]=r[i];                   // ���������¼��ŵ�������r[0]��
		j=i-1;	         
		while (r[0].key< r[j].key )  // Ѱ�Ҳ���λ�� 
		{
			r[j+1]= r[j]; 
			j=j-1;
		}
		r[j+1]=r[0];		         // ���������¼���뵽�������������
	}
}
