/*
	Created by ShawFrank
	lanuage: C plus plus
	2020/12/27
*/
//插入排序
//时间复杂度，最好O(N), 最坏O(N^2) 
#include <iostream>
#define ElemType int
using namespace std;

const int M = 50;
int n,P,i;
int a[M];

void Insertion_Sort(ElemType A[], int N)
{
	int tmp; 
	for( P = 1; P < N ; P ++)
	{
		tmp = A[P];
		for(i = P; i>0 && A[i - 1] > tmp ; i --)
			A[i] = A[i - 1];
		A[i] = tmp;	
	}
}
int main()
{
	int a[] = {2,0,6,7,8,-1,-2};
	Insertion_Sort(a, 7);
	for(int j = 0 ; j < 7 ; j ++)
		cout << a[j] << " ";
	return 0;
}
