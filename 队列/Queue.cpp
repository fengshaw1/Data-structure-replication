#include <iostream>
#define MaxSize 20
#define ElemType int

using namespace std;

typedef struct
{
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;

void InitQueue(SqQueue &Q)	//��ʼ������ 
{
	Q.front = Q.rear = 0;	//��ʼ����ͷ�Ͷ�βָ�� 
}

bool isEmpty(SqQueue &Q)	//�ж϶����Ƿ�Ϊ�� 
{
	if(Q.front == Q.rear) return true;	//�ӿ�����
	else return false; 
}

bool isFull(SqQueue &Q) 	//�ж϶����Ƿ����� 
{	
	if((Q.rear + 1) % m == Q.front) return true;	//�������� 
	else return false;
}
bool EnQueue(SqQueue &Q, ElemType x)	//��� 
{
	if((Q.rear + 1) % MaxSize == Q.front) return false;	//�������޷�����
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MaxSize;	//��βָ���1��ȡģ 
	return true; 
}

bool DeQueue(SqQueue &Q, ElemType &x)	//���� 
{
	if(Q.rear == Q.front)	return false;	//�ӿ��򱨴�
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;	//��ͷָ���1��ȡģ 
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
	
	cout << "��ͷԪ����:" << frontElem << endl;
	
	if(isEmpty(Q))	cout << "�ӿ�" << endl;
	
	return 0;
} 
