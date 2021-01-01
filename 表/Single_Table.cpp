/*
	Created By ShawFrank
	language: C plus plus
	2020/12/21 
*/
#include <iostream>
#include <malloc.h>
#define ElemType int
using namespace std;

typedef struct LNode	//定义链表节点类型 
{
	ElemType data;		//数据域 
	struct LNode *next;	//指针域 
}LNode, *LinkList;

LinkList List_HeadInsertInit(LinkList &L)	//逆向建立单链表(头插法)
{
	LNode *s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));	//创建头节点 
	L->next = NULL;			//初始化空链表
	scanf("%d", &x);
	while(x != 9999)	//输入 9999表示结束 
	{
		s = (LNode *)malloc(sizeof(LNode));	//创建新节点
		s->data = x ;
		s->next = L->next;		//将新节点插入链表中 
		L->next = s;
		scanf("%d", &x);
	} 
	return L;
} 

LinkList List_TailInsertInit(LinkList &L)	//正向建立单链表(尾插法) 
{
	int x;
	L = (LinkList)malloc(sizeof(LNode));	
	LNode *s, *r = L;	// r为表尾指针
	scanf("%d", &x);		//输入节点值
	while(x != 9999)	//输入9999表示结束
	{	
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;	//指向新的表尾节点 
		scanf("%d", &x);
	}
	r->next = NULL;	//尾指针置空
	return L; 
}

LNode *LocateElem(LinkList L, ElemType e)	//按值查找 
{
	LNode *p = L->next;
	while(p!=NULL && p->data != e)	//从第一个节点开始查找data域为e的节点 
		p = p->next;
	return p;			//找到后返回指针，没找到返回NULL 
}

int getLinkListLength(LinkList L)	//获取表长函数 
{
	LNode *p;
	p = L->next;
	int ret = 0 ;
	while(p)
	{
		p = p->next;
		ret ++;
	}
	return ret;
} 
LNode * GetElem(LinkList L, int i)	//找前驱节点函数 
{
	LNode *p;
	p = L;
	int ret = 1;
	while(ret!=i)
	{
		p = p->next;
		ret ++;
	}
	return p;
} 

void InsertNodeByPosition(LinkList &L, int i, ElemType e) 	//按位置插入
{
	LNode *s,*p;
	p =  GetElem(L, i);		//找第i个节点的前驱节点 
	s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
} 

void DeleteNode(LinkList &L, int i)	//删除第i个节点后面的节点 
{
	LNode *p, *s;
	p = GetElem(L, i);	//删除之前先找到前驱节点 
	s = p->next;
	p->next = s->next;
	free(s);
}

void Traverse(LinkList L)	//遍历函数 
{
	LNode *p, *head;
	head = L;
	p = head->next;
	while(p)
	{
		cout << p->data << "-->";
		p = p->next;
	}
	puts("\n");
}

LNode * Inverse(LNode *L)	//链表逆置 
{
	LNode *p, *q;
	p = L->next;
	L->next = NULL;
	while (p != NULL)
	{
		q = p;
		p = p->next;
 
		q->next = L->next;
		L->next = q;
	}
	return L;
}

int main()
{
	LinkList L;
	LNode *p;
	L = List_TailInsertInit(L);
	/*插入和删除时都要对头部和尾部元素进行特殊处理*/ 
	//InsertNodeByPosition(L, 1 , 2);		//在第一个位置插入节点2 
	Traverse(L);
	L = Inverse(L);
	Traverse(L);
//	DeleteNode(L,2);	//删除第 2 个节点 	 
//	Traverse(L);
	//cout << getLinkListLength(L) << endl;
	return 0;	
} 
