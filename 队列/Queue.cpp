#include <iostream>
#define MaxSize 20
#define ElemType int

using namespace std;

typedef struct
{
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;

void InitQueue(SqQueue &Q)	//初始化函数 
{
	Q.front = Q.rear = 0;	//初始化队头和队尾指针 
}

bool isEmpty(SqQueue &Q)	//判断队列是否为空 
{
	if(Q.front == Q.rear) return true;	//队空条件
	else return false; 
}

bool isFull(SqQueue &Q) 	//判断队列是否满了 
{	
	if((Q.rear + 1) % m == Q.front) return true;	//队满条件 
	else return false;
}
bool EnQueue(SqQueue &Q, ElemType x)	//入队 
{
	if((Q.rear + 1) % MaxSize == Q.front) return false;	//队满，无法插入
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MaxSize;	//队尾指针加1再取模 
	return true; 
}

bool DeQueue(SqQueue &Q, ElemType &x)	//出队 
{
	if(Q.rear == Q.front)	return false;	//队空则报错
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;	//队头指针加1再取模 
	return true;	
} 

int main()
{
	SqQueue Q;
	int frontElem;
	InitQueue(Q);
	EnQueue(Q, 1);
	EnQueue(Q, 2);
	DeQueue(Q, frontElem);
	DeQueue(Q, frontElem);
	
	cout << "队头元素是:" << frontElem << endl;
	
	if(isEmpty(Q))	cout << "队空" << endl;
	
	return 0;
} 
