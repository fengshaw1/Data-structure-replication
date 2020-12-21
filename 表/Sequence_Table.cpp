#include <iostream>
#define MaxSize 50	//������� 
#define ElemType int
using namespace std;
typedef struct
{
	ElemType data[MaxSize];	//˳����е�Ԫ�� 
	int length;		//˳���ĳ��� 
}SqList;	//˳������Ͷ��� 

SqList InitList()	//˳����ʼ�� 
{
	SqList L;
	L.length = 0;
	return L;
}

bool ListInsert(SqList &L, int i, ElemType e)  //Ԫ�ز��� 
{
	if(i < 1 || i > L.length + 1)	//���� 
		return false;
	if(L.length >= MaxSize)
		return false;
	
	for(int j = L.length; j >= i ; j --)	//���� i ��Ԫ�ؼ�֮���Ԫ�غ��� 
		L.data[j] = L.data[j - 1];
		
	L.data[i - 1] = e;	//��λ�� i ������Ԫ�� e 
	L.length ++;	//���Ա��ȼ�1 
	
	return true;
}

bool ListDelete(SqList &L, int i, ElemType &e)
{
	if(i < 1 || i > L.length)	//���� 
		return false;
	e = L.data[i - 1];	//����ɾ����Ԫ�ظ�ֵ��e
	for(int j  = i ; j < L.length; j ++)	//���� i ��λ�õ�Ԫ��ǰ�� 
		L.data[j - 1] = L.data[j];
	
	L.length --; 	// ���Ա��ȼ�1 
	return true;
}

int LocateElem(SqList L, ElemType e)	//��ֵ���� 
{
	int i ;
	for(int i = 0; i < L.length ; i ++)
		if(L.data[i] == e)
			return i + 1;	//�±�Ϊi��Ԫ��ֵΪe, ������λ�� i + 1 
	
	return -1; 	//����ʧ�� 
}

int LocatePosition(SqList L, int i)		//��λ�ò���
{
	for(int j = 0 ; j < L.length ; j ++)
		if(j == i - 1)	
			return L.data[j];	//���ҳɹ�����ֵ 
	
	return -1;	//����ʧ�� 
} 
void Traverse(SqList &L)	//���� 
{
	for(int i = 0 ; i < L.length ; i ++)
		cout << L.data[i] << " ";
	cout << endl; 
}

bool isEmpty(SqList &L)		//�жϱ��Ƿ�Ϊ�� 
{
	if(L.length == 0)
		return true;
	
	return false;
}
int main()
{
	SqList L;
	int deleteItem, findItem; 
	L = InitList();
	
	ListInsert(L, 1, 1); 	// 1 ��λ�ò���ֵΪ 1 
	ListInsert(L, 1, 2); 
	Traverse(L);
	ListDelete(L, 1, deleteItem);
	Traverse(L);
	printf("��ɾ����Ԫ����:%d\n", deleteItem);
	findItem = LocatePosition(L, 1);
	printf("���ҵ���Ԫ����:%d\n", findItem);
	return 0;
} 
