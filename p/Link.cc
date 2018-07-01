 ///
 /// @file    Link.cc
 /// @author  LJW
 /// @date    2018-06-28 16:08:05
 ///
 
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;


typedef struct listNode
{

	int data;
	struct listNode *next;
} list, *pNode;

int main()
{

	pNode node = NULL; 
	node = (pNode)malloc(sizeof(list));
	if(node == NULL)
		cout << "malloc failed" << endl;
	memset(node, 0, sizeof(list));
	node->data = 100;
	node->next = NULL;
	cout << node->data << endl;
	free(node);
	return 0;

}
