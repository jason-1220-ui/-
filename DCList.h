#ifndef _SCLIST_H_
#define _SCLIST_H_

#include "Common.h"
#endif //_SCLIST_H_

typedef int LTDataType;
typedef struct ListNode{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;
typedef struct DCList{
	ListNode *pHead;
}DCList;

//函数声明
void ListInit(DCList *pHead);
ListNode* BuyListNode(LTDataType x);
ListNode* ListCreate();//创建返回链表的头节点
void ListPrint(ListNode* pHead);//双向链表打印
void ListDestory(ListNode* pHead);//双向链表销毁
void ListPushBack(ListNode* pHead, LTDataType x);//双向链表尾插
void ListPopBack(ListNode* pHead);//双向链表尾删
void ListPushFront(ListNode* pHead, LTDataType x);//双向链表头插
void ListPopFront(ListNode* pHead);//双向链表头删
ListNode* ListFind(ListNode* pHead, LTDataType x);//双向链表查找
void ListInsert(ListNode* pos, LTDataType x);//双向链表在pos的前面插入
void ListErase(ListNode* pos);//双向链表删除pos位置的节点

//函数实现
ListNode* BuyListNode(LTDataType x) {
	ListNode *s = (ListNode*)malloc(sizeof(ListNode));
	assert(s != NULL);
	s->_data = x;
	s->_next = s;
	s->_prev = s;
	return s;
}
void ListInit(DCList *pHead){
	pHead = NULL;
}
ListNode* ListCreate() {//创建返回链表的头节点
	ListNode *pHead = (ListNode*)malloc(sizeof(ListNode));
	assert(pHead != NULL);
	pHead->_next = pHead;
	pHead->_prev = pHead;
	return pHead;
}
void ListPrint(ListNode* pHead) {//双向链表打印
	ListNode *p = pHead->_next;
	while (p != pHead) {
		printf("%d->", p->_data);
		p = p->_next;
	}
	printf("Over.\n");
}
void ListPushBack(ListNode* pHead, LTDataType x) {//双向链表尾插
	ListNode *s = BuyListNode(x);
	ListNode *p = pHead->_prev;
	p->_next = s;
	s->_prev = p;
	s->_next = pHead;
	pHead->_prev = s;
}
void ListPopBack(ListNode* pHead) {//双链表尾删
	assert(pHead);
	ListNode *p = pHead->_next;
	if (p == pHead) 
		return;
	p = pHead->_prev;
	p->_next->_prev = p->_prev;
	p->_prev->_next = p->_next;
	free(p);
}
void ListPushFront(ListNode* pHead, LTDataType x) {//双向链表头插
	ListNode *s = BuyListNode(x);
	s->_next = pHead->_next;
	s->_prev = pHead;
	s->_prev->_next = s;
	s->_next->_prev = s;
}
void ListPopFront(ListNode* pHead) {//双向链表头删
	assert(pHead);
	ListNode *p = pHead->_next;
	if (p == pHead) 
		return;
	pHead->_next = p->_next;
	p->_next->_prev = pHead;
	free(p);
}
ListNode* ListFind(ListNode* pHead, LTDataType x) {//双向链表查找
	ListNode *p = pHead->_next;
	while (p != pHead && p->_data != x) {
		p = p->_next;
	}
	if (p == pHead) {
		return NULL;
	}
	return p;
}
void ListInsert(ListNode* pos, LTDataType x) {//双向链表在pos的前面插入
	assert(pos);
	ListNode *s = BuyListNode(x);
	ListNode *p = pos->_prev;
	p->_next = s;
	s->_prev = p;
	s->_next = pos;
	pos->_prev = s;
}
void ListErase(ListNode* pos) {//双向链表删除pos位置的节点
	assert(pos);
	ListNode *p = pos->_prev;
	ListNode *n = pos->_next;
	p->_next = n;
	n->_prev = p;
	free(pos);
}
void ListDestory(ListNode* pHead) {//双向链表销毁
	ListNode* p = pHead->_next;
	while (p != pHead){
		ListNode* next = p->_next;
		free(p);
		p = next;
	}
	free(pHead);
}