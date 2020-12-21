#include <iostream>
#define MaxSize 50
#define ElemType int
using namespace std;

typedef struct 
{
	ElemType data[MaxSize];	//���ջ��Ԫ�� 
	int top;	//ջ��ָ�� 
}SqStack;

void InitStack(SqStack &S)	//��ʼ�� 
{
	S.top = -1;	//��ʼ��ջ��ָ��	
}

bool StackEmpty(SqStack S)	//�ж�ջ�Ƿ�Ϊ�� 
{
	if(S.top == -1)		//ջ�� 
		return true;
	else				//���� 
		return false;	
}

bool Push(SqStack &S, ElemType x)	//��ջ 
{
	if(S.top == MaxSize - 1)	//ջ�� 
		return false;
	S.data[++S.top] = x;	//ָ���ȼ�1������ջ 
	return true;
}

bool Pop(SqStack &S, ElemType &x)	//��ջ 
{
	if(S.top == -1)		//ջ��
		return false;
	x = S.data[S.top --];	//�ȳ�ջ��ָ���ټ�һ
	return true; 
}

bool GetTop(SqStack S, ElemType &x)	//��ȡջ��Ԫ�� 
{
	if(S.top == -1)	//ջ��
		return false;
	x = S.data[S.top];	//��¼ջ��Ԫ��
	return true; 
}
int main()
{
	SqStack S;
	InitStack(S);
	int x;
	int TopElem;
	Push(S, 1);
	Push(S, 2);
	Pop(S, x);
	GetTop(S, TopElem);
	printf("%d", TopElem);
	return 0;
}
