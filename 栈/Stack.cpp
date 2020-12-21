#include <iostream>
#define MaxSize 50
#define ElemType int
using namespace std;

typedef struct 
{
	ElemType data[MaxSize];	//存放栈中元素 
	int top;	//栈顶指针 
}SqStack;

void InitStack(SqStack &S)	//初始化 
{
	S.top = -1;	//初始化栈顶指针	
}

bool StackEmpty(SqStack S)	//判断栈是否为空 
{
	if(S.top == -1)		//栈空 
		return true;
	else				//不空 
		return false;	
}

bool Push(SqStack &S, ElemType x)	//进栈 
{
	if(S.top == MaxSize - 1)	//栈满 
		return false;
	S.data[++S.top] = x;	//指针先加1，再入栈 
	return true;
}

bool Pop(SqStack &S, ElemType &x)	//出栈 
{
	if(S.top == -1)		//栈空
		return false;
	x = S.data[S.top --];	//先出栈，指针再减一
	return true; 
}

bool GetTop(SqStack S, ElemType &x)	//读取栈顶元素 
{
	if(S.top == -1)	//栈空
		return false;
	x = S.data[S.top];	//记录栈顶元素
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
