 ///
 /// @file    ListNode.cc
 /// @author  LJW
 /// @date    2018-06-30 22:18:02
 ///
 
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

typedef struct ListNode
{
	int data;
	struct ListNode *pnext;
} List, *pNode;

void AddToTail(pNode *pHead, int value)
{
	// pnew 初始化
	//pNode pnew = (pNode)calloc(1, sizeof(List)); // 初始化为0， 头文件stdlib.h
	pNode pnew = new ListNode();
	pnew->data = value;
	pnew->pnext = NULL;

	// 判断，挂载
	if(pHead == NULL)
		*pHead = pnew;
	else
	{
		pNode pnode = *pHead;
		while(pnode->pnext != NULL)
			pnode = pnode->pnext;

		pnode->pnext = pnew;
	}
}


int main()
{
	pNode p = new ListNode();
	pNode p1 = new ListNode();
	pNode p2 = new ListNode();
	p->data = 1;
	p->pnext = p1;
	p1->data = 2;
	p1->pnext = p2;
	p2->data = 3;
	

	AddToTail(&p, 4);
	AddToTail(&p, 5);
	AddToTail(&p, 6);

	while(p)
	{
		cout << p->data << endl;
		p = p->pnext;
	}


}
