#include "selectsort.h"

void SelectSort(RecordType r[], int length)
{
	int 		i;
	int 		j;
	int 		k;
	int 		n;
	RecordType 	x;
    
	n=length;
	
	for(i=1 ; i<= n-1; ++i)  
	{
		k=i;
		for ( j=i+1 ; j<= n ; ++j) 
		{
			if (r[j].key < r[k].key ) 
				k=j;
		}	
		if ( k!=i) 
		{ 
			x= r[i]; 
			r[i]= r[k];
			r[k]=x;
		}
	}	
}
