#ifndef _SEQ_LIST_H_
#define _SEQ_LIET_H_
#endif //_SEQ_LIST_H_

#include"Common.h"
#define INC_SIZE 3

//���ݽṹ�Ķ���
typedef struct Seqlist {
	ElemType *base;
	size_t   capacity;
	size_t   size;
}Seqlist;

//��������
bool _Inc(Seqlist *pst);
bool _IsFull(Seqlist *pst);
bool _IsEmpty(Seqlist *pst);
void SeqlistInit(Seqlist *pst, size_t capacity);
void SeqlistPushBack(Seqlist *pst, ElemType v);
void SeqlistPushFront(Seqlist *pst, ElemType v);
void SeqlistShow(Seqlist *pst);
void SeqlistPopBack(Seqlist *pst);
void SeqlistPopFront(Seqlist *pst);
void SeqlistInsertPos(Seqlist *pst, ElemType v, int pos);
void SeqlistInsertVal(Seqlist *pst, ElemType v);
void SeqlistErasePos(Seqlist *pst, int pos);
void SeqlistEraseVal(Seqlist *pst, ElemType v);
ElemType SeqlistFindPos(Seqlist *pst, int pos);
int SeqlistFindVal(Seqlist *pst, ElemType key);

void SeqlistSort(Seqlist *pst);
void SeqlistReverse(Seqlist *pst);

size_t SeqlistLength(Seqlist *pst);
size_t SeqlistCapacity(Seqlist *pst);
void SeqlistClear(Seqlist *pst);
void SeqlistDestory(Seqlist *pst);

//����ʵ��
bool _Inc(Seqlist *pst){
	pst->base = (ElemType *)realloc(pst->base, sizeof(ElemType) * (pst->capacity + INC_SIZE));
	if (pst->base == NULL)
		return false;
	pst->capacity += INC_SIZE;
	return true;
}
bool _IsFull(Seqlist *pst)
{
	return pst->size >= pst->capacity;
}
bool _IsEmpty(Seqlist *pst)
{
	return pst->size == 0;
}

void SeqlistInit(Seqlist *pst, size_t capacity) {//˳����ʼ��
	pst->capacity = capacity;
	pst->base = (ElemType*)malloc(sizeof(ElemType)* pst->capacity);
	assert(pst->base != NULL);
	memset(pst->base, 0, sizeof(ElemType)*pst->capacity);
	pst->size = 0;
}

void SeqlistPushBack(Seqlist *pst, ElemType v) {//˳�����
	//�������
	if (pst->size >= pst->capacity) {
		printf("˳����������㣬%d���ܲ���\n", v);
		return;
	}
	pst->base[pst->size++] = v;
}

void SeqlistPushFront(Seqlist *pst, ElemType v) {//˳���ǰ��
	//�������
	if (pst->size >= pst->capacity) {
		printf("˳����������㣬%d���ܲ���\n", v);
		return;
	}
	//�ƶ�����
	for (int i = pst->size; i > 0; i--) {
		pst->base[i] = pst->base[i - 1];
	}
	//��������
	pst->base[0] = v;
	pst->size++;
}

void SeqlistShow(Seqlist *pst) {//��ӡ˳���
	for (int i = 0; i < pst->size; i++) {
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}

void SeqlistPopBack(Seqlist *pst) {//˳����ɾ
	if (pst->size == 0) {
		printf("˳����ѿգ����ܽ���ɾ����\n");
		return;
	}
	pst->size--;
}

void SeqlistPopFront(Seqlist *pst) {//˳���ǰɾ
	if (pst->size == 0) {
		printf("˳����ѿգ����ܽ���ɾ����\n");
		return;
	}
	for (int i = 0; i < pst->size - 1; i++) {
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}

void SeqlistInsertPos(Seqlist *pst, ElemType v, int pos) {//˳�����posλ�ò���v
	//�������
	if (pst->size >= pst->capacity) {
		printf("˳����������㣬%d���ܲ��룡\n", v);
		return;
	}
	//���λ��
	if (pos<0 || pos>pst->size) {
		printf("����λ�÷Ƿ���%d���ܲ��룡\n", v);
		return;
	}
	//��������
	for (int i = pst->size; i > pos; i--) {
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[pos] = v;
	pst->size++;
}

void SeqlistInsertVal(Seqlist *pst, ElemType v) {//˳������ֵ
	//Ѱ�Ҳ���λ��
	int pos = 0;
	while (pos<pst->size &&  v>pst->base[pos])
		pos++;
	//��������
	SeqlistInsertPos(pst, pos, v);
}

void SeqlistErasePos(Seqlist *pst, int pos) {//˳���ɾ��posλ�õ�ֵ
	//���λ��
	if (pos < 0 || pos >= pst->size){
		printf("ɾ����λ�÷Ƿ�������ɾ������.\n");
		return;
	}
	//ɾ������
	for (int i = pos; i < pst->size - 1; ++i) {
		pst->base[i] = pst->base[i + 1];
		pst->size--;
	}
}

void SeqlistEraseVal(Seqlist *pst, ElemType key) {//˳���ɾ��ֵ
	//���ҹؼ�ֵ
	int pos = SeqlistFindVal(pst, key);
	if (pos == -1){
		printf("Ҫɾ�������ݲ�����.\n");
		return;
	}
	//ɾ������
	SeqlistErasePos(pst, pos);
}

ElemType SeqlistFindPos(Seqlist *pst, int pos){//����λ�ò���
	//���λ��
	assert(pos >= 0 && pos < pst->size);
	return pst->base[pos];
}

int SeqlistFindVal(Seqlist *pst, ElemType key) {//����ֵ����
	for (int i = 0; i < pst->size; ++i){
		if (key == pst->base[i])
			return i;
	}
	return -1;
}

void SeqlistSort(Seqlist *pst){//˳�������
	for (int i = 0; i < pst->size - 1; ++i){
		bool is_swap = false;
		for (int j = 0; j < pst->size - i - 1; ++j){
			if (pst->base[j] > pst->base[j + 1]){
				Swap(&(pst->base[j]), &(pst->base[j + 1]));
				is_swap = true;
			}
		}
		if (!is_swap) {//û�н���������
			break;
		}
	}
}

void SeqlistReverse(Seqlist *pst){//˳�������
	int left = 0;
	int right = pst->size - 1;
	while (left < right){
		Swap(&(pst->base[left]), &(pst->base[right]));
		left++;
		right--;
	}
}

size_t SeqlistLength(Seqlist *pst) {//˳�����
	return pst->size;
}

size_t SeqlistCapacity(Seqlist *pst){//˳�������
	return pst->capacity;
}

void SeqlistClear(Seqlist *pst){//˳������
	pst->size = 0;
}

void SeqlistDestory(Seqlist *pst) {//˳���ݻ�
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->size = 0;
}