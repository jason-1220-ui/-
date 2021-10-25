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

//��������
void ListInit(DCList *pHead);
ListNode* BuyListNode(LTDataType x);
ListNode* ListCreate();//�������������ͷ�ڵ�
void ListPrint(ListNode* pHead);//˫�������ӡ
void ListDestory(ListNode* pHead);//˫����������
void ListPushBack(ListNode* pHead, LTDataType x);//˫������β��
void ListPopBack(ListNode* pHead);//˫������βɾ
void ListPushFront(ListNode* pHead, LTDataType x);//˫������ͷ��
void ListPopFront(ListNode* pHead);//˫������ͷɾ
ListNode* ListFind(ListNode* pHead, LTDataType x);//˫���������
void ListInsert(ListNode* pos, LTDataType x);//˫��������pos��ǰ�����
void ListErase(ListNode* pos);//˫������ɾ��posλ�õĽڵ�

//����ʵ��
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
ListNode* ListCreate() {//�������������ͷ�ڵ�
	ListNode *pHead = (ListNode*)malloc(sizeof(ListNode));
	assert(pHead != NULL);
	pHead->_next = pHead;
	pHead->_prev = pHead;
	return pHead;
}
void ListPrint(ListNode* pHead) {//˫�������ӡ
	ListNode *p = pHead->_next;
	while (p != pHead) {
		printf("%d->", p->_data);
		p = p->_next;
	}
	printf("Over.\n");
}
void ListPushBack(ListNode* pHead, LTDataType x) {//˫������β��
	ListNode *s = BuyListNode(x);
	ListNode *p = pHead->_prev;
	p->_next = s;
	s->_prev = p;
	s->_next = pHead;
	pHead->_prev = s;
}
void ListPopBack(ListNode* pHead) {//˫����βɾ
	assert(pHead);
	ListNode *p = pHead->_next;
	if (p == pHead) 
		return;
	p = pHead->_prev;
	p->_next->_prev = p->_prev;
	p->_prev->_next = p->_next;
	free(p);
}
void ListPushFront(ListNode* pHead, LTDataType x) {//˫������ͷ��
	ListNode *s = BuyListNode(x);
	s->_next = pHead->_next;
	s->_prev = pHead;
	s->_prev->_next = s;
	s->_next->_prev = s;
}
void ListPopFront(ListNode* pHead) {//˫������ͷɾ
	assert(pHead);
	ListNode *p = pHead->_next;
	if (p == pHead) 
		return;
	pHead->_next = p->_next;
	p->_next->_prev = pHead;
	free(p);
}
ListNode* ListFind(ListNode* pHead, LTDataType x) {//˫���������
	ListNode *p = pHead->_next;
	while (p != pHead && p->_data != x) {
		p = p->_next;
	}
	if (p == pHead) {
		return NULL;
	}
	return p;
}
void ListInsert(ListNode* pos, LTDataType x) {//˫��������pos��ǰ�����
	assert(pos);
	ListNode *s = BuyListNode(x);
	ListNode *p = pos->_prev;
	p->_next = s;
	s->_prev = p;
	s->_next = pos;
	pos->_prev = s;
}
void ListErase(ListNode* pos) {//˫������ɾ��posλ�õĽڵ�
	assert(pos);
	ListNode *p = pos->_prev;
	ListNode *n = pos->_next;
	p->_next = n;
	n->_prev = p;
	free(pos);
}
void ListDestory(ListNode* pHead) {//˫����������
	ListNode* p = pHead->_next;
	while (p != pHead){
		ListNode* next = p->_next;
		free(p);
		p = next;
	}
	free(pHead);
}