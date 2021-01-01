/*
	Created By ShawFrank
	language: C plus plus
	2020/12/21 
*/
#include <iostream>
#include <malloc.h>
#define ElemType int
using namespace std;

typedef struct LNode	//��������ڵ����� 
{
	ElemType data;		//������ 
	struct LNode *next;	//ָ���� 
}LNode, *LinkList;

LinkList List_HeadInsertInit(LinkList &L)	//������������(ͷ�巨)
{
	LNode *s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));	//����ͷ�ڵ� 
	L->next = NULL;			//��ʼ��������
	scanf("%d", &x);
	while(x != 9999)	//���� 9999��ʾ���� 
	{
		s = (LNode *)malloc(sizeof(LNode));	//�����½ڵ�
		s->data = x ;
		s->next = L->next;		//���½ڵ���������� 
		L->next = s;
		scanf("%d", &x);
	} 
	return L;
} 

LinkList List_TailInsertInit(LinkList &L)	//������������(β�巨) 
{
	int x;
	L = (LinkList)malloc(sizeof(LNode));	
	LNode *s, *r = L;	// rΪ��βָ��
	scanf("%d", &x);		//����ڵ�ֵ
	while(x != 9999)	//����9999��ʾ����
	{	
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;	//ָ���µı�β�ڵ� 
		scanf("%d", &x);
	}
	r->next = NULL;	//βָ���ÿ�
	return L; 
}

LNode *LocateElem(LinkList L, ElemType e)	//��ֵ���� 
{
	LNode *p = L->next;
	while(p!=NULL && p->data != e)	//�ӵ�һ���ڵ㿪ʼ����data��Ϊe�Ľڵ� 
		p = p->next;
	return p;			//�ҵ��󷵻�ָ�룬û�ҵ�����NULL 
}

int getLinkListLength(LinkList L)	//��ȡ������ 
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
LNode * GetElem(LinkList L, int i)	//��ǰ���ڵ㺯�� 
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

void InsertNodeByPosition(LinkList &L, int i, ElemType e) 	//��λ�ò���
{
	LNode *s,*p;
	p =  GetElem(L, i);		//�ҵ�i���ڵ��ǰ���ڵ� 
	s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
} 

void DeleteNode(LinkList &L, int i)	//ɾ����i���ڵ����Ľڵ� 
{
	LNode *p, *s;
	p = GetElem(L, i);	//ɾ��֮ǰ���ҵ�ǰ���ڵ� 
	s = p->next;
	p->next = s->next;
	free(s);
}

void Traverse(LinkList L)	//�������� 
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

LNode * Inverse(LNode *L)	//�������� 
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
	/*�����ɾ��ʱ��Ҫ��ͷ����β��Ԫ�ؽ������⴦��*/ 
	//InsertNodeByPosition(L, 1 , 2);		//�ڵ�һ��λ�ò���ڵ�2 
	Traverse(L);
	L = Inverse(L);
	Traverse(L);
//	DeleteNode(L,2);	//ɾ���� 2 ���ڵ� 	 
//	Traverse(L);
	//cout << getLinkListLength(L) << endl;
	return 0;	
} 
