#include<iostream>
#include<stdlib.h>
using namespace std;
#define null 0
typedef char ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;
int ListLength(LinkList L);
ElemType GetElem(LinkList L,int i);
void InsertList(LinkList &L,ElemType x,int i);
void DisplayList(LinkList L);
LinkList LA;
void main()
{
	LA=NULL;
	ElemType cs;
	int len=0;
	InsertList(LA,'a',1);
	InsertList(LA,'B',2);
	InsertList(LA,'C',2);
	cs=GetElem(LA,3);
	len=ListLength(LA);
	DisplayList(LA);
}

int ListLength(LinkList L)
{
	int n=0;
	struct LNode *q=L;
	if(L=NULL)
		cout<<"链表为空"<<endl;
	while(q!=null)
	{
		q=q->next;
		n=n+1;
	}
	return n;
}

ElemType GetElem(LinkList L,int i)
{
	int j=1;
	struct LNode *q=L;
	while(j<i&&q!=null)
	{
		j++;
		q=q->next;
	}
	if(q!=null)
		return (q->data);
	else
		cout<<"this position is not correct!"<<endl;
	return 0;
}

int LocateElem(LinkList L,ElemType x)
{
	int n=0;
	struct LNode *q=L;
	while(q!=null&&q->data!=x)
	{
		q=q->next;
		n++;
	}
	if(q==null)
		return(-1);
	else
		return (n+1);
}


void InsertList(LinkList &L,ElemType x,int i)
{
	int j=1;
	struct LNode *s,*q;
	s=new LNode;
	s->data=x;
	q=L;
	if(i==1)
	{
		s->next=q;
		L=s;
	}
	else
	{
		while (j<i-1&&q->next!=null)
		{
			j++;
			q=q->next;
		}
		if(j==i-1)
		{
			s->next=q->next;
			q->next=s;

		}
		else
			cout<<"This [osotion is not correct!"<<endl;
	}
}

int DeleteElem(LinkList &L,int i)
{
	int j=1;
	struct LNode *q=L,*t;
	if(i==1)
	{
		t=L;
		L=t->next;
	}
	else
	{
		while(j<i-1&&q->next!=null)
		{
			j++;
			q=q->next;
		}
		if(q->next!=null && j==i-1)
		{
			t=q->next;
			q->next=t->next;
		}
		else
			cout<<"This position is not correct!"<<endl;
	}
	if(t)
		delete t;
	return 0;
}

void DisplayList(LinkList L)
{
	struct LNode *q;
	q=L;
	cout<<"链表元素:  ";
	if(q==null)
		cout<<"链表为空"<<endl;
	else if(q->next==NULL)
		cout<<q->data<<"  ";
	else
	{
		while(q->next!=null)
		{
			cout<<q->data<<"  ";
			q=q->next;
		}
		cout<<q->data<<"  ";

	}
	cout<<endl;
}
