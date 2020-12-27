#include <iostream>
#include <algorithm>
#define ElemType int
using namespace std;
const int M = 50;
int a[M];
int flag;
void Bubble_Sort(ElemType A[], int N)
{
	for(int P = N - 1; P >= 0 ; P --)
	{
		flag = 0;	//加标志位，减少有序时多余的排序 
		for(int i = 0;i < P ; i ++)	/*一趟冒泡*/ 
		{
			if(A[i] > A[i + 1]) 
				swap(A[i],A[i+1]);
				flag = 1;	/*标示发生了交换*/ 
		}	
		if(flag == 0) break; /*全程没有交换则之间退出*/ 
	} 
} 
int main()
{
	int a[] = {1,5,6,7,4,3,9,-1,10};
	Bubble_Sort(a,9); 
	for(int i = 0 ; i < 9 ; i ++)
		cout << a[i] << " ";
	return 0;
}
