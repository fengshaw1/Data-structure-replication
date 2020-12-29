/*
	Created by ShawFrank
	language: C plus plus
	2020/12/29
*/
//简单选择排序   时间复杂度O(n^2)  
#include <iostream>
#define ElemType int  

using namespace std;

int i, j, min_index;

void Select_Sort(ElemType A[], int n)
{
	for(i = 0; i < n - 1; i ++)	//n - 1躺 
	{
		min_index = i;
		for(j = i + 1; j < n ;j ++)	//选择最小元素 
		{
			if(A[j] < A[min_index]) min_index = j;	//更新位置 
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
