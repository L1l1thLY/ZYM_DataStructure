#include "hash.h"

int hash(KeyType k)
{
	int h;
	h = k % M;
	return h;
}

int HashSearch(HashTable ht, KeyType K)
{
	int h0;
	int i;
	int hi;
	
	h0=hash(K);
	if(ht[h0].key== 0 ) 
	{
		return (-1);
	}	
	else 
	{
		if (ht[h0].key==K) 
		{
			return (h0);
		}	
		else   // 用线性探测再散列解决冲突
		{ 
			for (i=1; i<=M-1;  i++)
			{
				hi=(h0+i) % M;
				if  (ht[hi].key==0) 
				{
					return (-1);
				}	
				else
				{
					if (ht[hi].key==K) 
					{
						return (hi);
					}	
				}	
			}
			return (-1);
		}
	}		
}

void InitialHashTable(HashTable ht, int len, KeyType key[])
{
	int 	i;
	int 	j;
	int 	hj;
	int		h;
	
	for(i=0; i<len; i++)
	{
		
		h = hash(key[i]);
		if (ht[h].key == 0)
		{
			ht[h].key = key[i];
		}	
		else
		{ 
			for (j=1; j<=M-1; j++)
			{
				hj=(j + h) % M;
				if  (ht[hj].key==0) 
				{
					ht[hj].key = key[i];
					j = M;
				}
			}
		}
	}
} 

void TravelHashTable(HashTable ht)
{
	int i;
    for( i = 0; i < M; i++)
    {
    	printf("%4d\t", ht[i].key);
    }
	printf("\n");
}
