 ///
 /// @file    ReverseList.cc
 /// @author  LJW
 /// @date    2018-06-18 21:31:43
 ///
 
#include <iostream>
using std::cout;
using std::endl;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x)
	: val(x)
	, next(NULL)
	{}
};

class Solution
{

public:
	ListNode *ReverseList(ListNode *pHead)
	{
		if(NULL == pHead) return NULL;

		// head 当前节点  prev 为前一个节点， next保存head->next
		ListNode *prev = NULL;
		ListNode *next = NULL;
		for(ListNode *head = pHead; head;)
		{
			next = head->next; // 保存当前节点下一个
			head->next = prev; // 反转节点
			prev = head; // 向后移动
			head = next;
		}
		return prev;
	}
};

int main()
{
	return 0;
}
