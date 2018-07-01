 ///
 /// @file    printListFromTailToHead.cc
 /// @author  LJW
 /// @date    2018-06-30 23:18:18
 ///
 
#include <iostream>
#include <stack>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

typedef struct ListNode
{
	int data;
	struct ListNode *pnext;
} List, *pNode;

class Solution
{
public:
	void printListFromTailToHead(ListNode *pHead)
	{
		if(pHead == NULL)
			return ;
		std::stack<ListNode *> nodes;
		ListNode *pnode = pHead;
		while(pnode)
		{
			nodes.push(pnode);
//			cout << nodes.top()->data << " ";
			pnode = pnode->pnext;
		}

		while(!nodes.empty())
		{
		//	cout << nodes.size() << endl;
			pnode = nodes.top();
			cout << pnode->data << " ";
			nodes.pop();
		}
	}
	
	void printList(ListNode *head)
	{
		if(head)
		{
			if(head->pnext)
			{
				printList(head->pnext);
			}
			cout << head->data << endl;
		}
	}
};

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
	ListNode *p = new ListNode();  
	AddToTail(&p, 1);
	AddToTail(&p, 2);
	AddToTail(&p, 3);
	AddToTail(&p, 4);
	AddToTail(&p, 5);
//	while(p)
//	{
//		cout << p->data << " ";
//		p = p->pnext;
//	}

	Solution s;
	s.printList(p);
}
