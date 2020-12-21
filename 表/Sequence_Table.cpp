#include <iostream>
#define MaxSize 50	//最大容量 
#define ElemType int
using namespace std;
typedef struct
{
	ElemType data[MaxSize];	//顺序表中的元素 
	int length;		//顺序表的长度 
}SqList;	//顺序表类型定义 

SqList InitList()	//顺序表初始化 
{
	SqList L;
	L.length = 0;
	return L;
}

bool ListInsert(SqList &L, int i, ElemType e)  //元素插入 
{
	if(i < 1 || i > L.length + 1)	//特判 
		return false;
	if(L.length >= MaxSize)
		return false;
	
	for(int j = L.length; j >= i ; j --)	//将第 i 个元素及之后的元素后移 
		L.data[j] = L.data[j - 1];
		
	L.data[i - 1] = e;	//在位置 i 处放入元素 e 
	L.length ++;	//线性表长度加1 
	
	return true;
}

bool ListDelete(SqList &L, int i, ElemType &e)
{
	if(i < 1 || i > L.length)	//特判 
		return false;
	e = L.data[i - 1];	//将被删除的元素赋值给e
	for(int j  = i ; j < L.length; j ++)	//将第 i 个位置的元素前移 
		L.data[j - 1] = L.data[j];
	
	L.length --; 	// 线性表长度减1 
	return true;
}

int LocateElem(SqList L, ElemType e)	//按值查找 
{
	int i ;
	for(int i = 0; i < L.length ; i ++)
		if(L.data[i] == e)
			return i + 1;	//下标为i的元素值为e, 返回其位置 i + 1 
	
	return -1; 	//查找失败 
}

int LocatePosition(SqList L, int i)		//按位置查找
{
	for(int j = 0 ; j < L.length ; j ++)
		if(j == i - 1)	
			return L.data[j];	//查找成功返回值 
	
	return -1;	//查找失败 
} 
void Traverse(SqList &L)	//遍历 
{
	for(int i = 0 ; i < L.length ; i ++)
		cout << L.data[i] << " ";
	cout << endl; 
}

bool isEmpty(SqList &L)		//判断表是否为空 
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
	
	ListInsert(L, 1, 1); 	// 1 号位置插入值为 1 
	ListInsert(L, 1, 2); 
	Traverse(L);
	ListDelete(L, 1, deleteItem);
	Traverse(L);
	printf("被删除的元素是:%d\n", deleteItem);
	findItem = LocatePosition(L, 1);
	printf("查找到的元素是:%d\n", findItem);
	return 0;
} 
