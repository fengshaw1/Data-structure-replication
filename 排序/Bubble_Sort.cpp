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
		flag = 0;	//�ӱ�־λ����������ʱ��������� 
		for(int i = 0;i < P ; i ++)	/*һ��ð��*/ 
		{
			if(A[i] > A[i + 1]) 
				swap(A[i],A[i+1]);
				flag = 1;	/*��ʾ�����˽���*/ 
		}	
		if(flag == 0) break; /*ȫ��û�н�����֮���˳�*/ 
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
