/*
	Created by ShawFrank
	language: C plus plus
	2020/12/29
*/
//��ѡ������   ʱ�临�Ӷ�O(n^2)  
#include <iostream>
#define ElemType int  

using namespace std;

int i, j, min_index;

void Select_Sort(ElemType A[], int n)
{
	for(i = 0; i < n - 1; i ++)	//n - 1�� 
	{
		min_index = i;
		for(j = i + 1; j < n ;j ++)	//ѡ����СԪ�� 
		{
			if(A[j] < A[min_index]) min_index = j;	//����λ�� 
		}
		if(min_index != i) swap(A[i],A[min_index]);
	}
}

int main()
{
	int a[]= {1,2,-1,0,3,8,9};
	Select_Sort(a, 7);
	for(int i = 0 ; i < 7 ; i ++)
		cout << a[i] << " "; 
	return 0;
}
