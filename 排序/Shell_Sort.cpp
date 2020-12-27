/*
	Created by ShawFrank
	lanuage: C plus plus
	2020/12/27
*/
//希尔排序
//时间复杂度，接近O(N^2) 
#include <iostream>
#define ElemType int
using namespace std;

const int M = 50;
int n,P,i,D;
int a[M];

void Shell_Sort(ElemType A[], int N)
{
	int tmp; 
	for(D = N / 2; D > 0 ; D /= 2)	/* 希尔增量序列 */
	for( P = D; P < N ; P ++)	/* 插入排序 */ 
	{
		tmp = A[P];
		for(i = P; i>=D && A[i - D] > tmp ; i -=D)
			A[i] = A[i - D];
		A[i] = tmp;	
	}
}
int main()
{
	int a[] = {2,0,6,7,8,-1,-2};
	Shell_Sort(a, 7);
	for(int j = 0 ; j < 7 ; j ++)
		cout << a[j] << " ";
	return 0;
}
