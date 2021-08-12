#ifndef _SEQ_LIST_H_
#define _SEQ_LIET_H_
#endif //_SEQ_LIST_H_

#include"Common.h"
#define INC_SIZE 3

//数据结构的定义
typedef struct Seqlist {
	ElemType *base;
	size_t   capacity;
	size_t   size;
}Seqlist;

//函数声明
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

//函数实现
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

void SeqlistInit(Seqlist *pst, size_t capacity) {//顺序表初始化
	pst->capacity = capacity;
	pst->base = (ElemType*)malloc(sizeof(ElemType)* pst->capacity);
	assert(pst->base != NULL);
	memset(pst->base, 0, sizeof(ElemType)*pst->capacity);
	pst->size = 0;
}

void SeqlistPushBack(Seqlist *pst, ElemType v) {//顺序表后插
	//检查容量
	if (pst->size >= pst->capacity) {
		printf("顺序表容量不足，%d不能插入\n", v);
		return;
	}
	pst->base[pst->size++] = v;
}

void SeqlistPushFront(Seqlist *pst, ElemType v) {//顺序表前插
	//检查容量
	if (pst->size >= pst->capacity) {
		printf("顺序表容量不足，%d不能插入\n", v);
		return;
	}
	//移动数据
	for (int i = pst->size; i > 0; i--) {
		pst->base[i] = pst->base[i - 1];
	}
	//插入数据
	pst->base[0] = v;
	pst->size++;
}

void SeqlistShow(Seqlist *pst) {//打印顺序表
	for (int i = 0; i < pst->size; i++) {
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}

void SeqlistPopBack(Seqlist *pst) {//顺序表后删
	if (pst->size == 0) {
		printf("顺序表已空！不能进行删除！\n");
		return;
	}
	pst->size--;
}

void SeqlistPopFront(Seqlist *pst) {//顺序表前删
	if (pst->size == 0) {
		printf("顺序表已空！不能进行删除！\n");
		return;
	}
	for (int i = 0; i < pst->size - 1; i++) {
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}

void SeqlistInsertPos(Seqlist *pst, ElemType v, int pos) {//顺序表在pos位置插入v
	//检查容量
	if (pst->size >= pst->capacity) {
		printf("顺序表容量不足，%d不能插入！\n", v);
		return;
	}
	//检查位置
	if (pos<0 || pos>pst->size) {
		printf("插入位置非法，%d不能插入！\n", v);
		return;
	}
	//插入数据
	for (int i = pst->size; i > pos; i--) {
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[pos] = v;
	pst->size++;
}

void SeqlistInsertVal(Seqlist *pst, ElemType v) {//顺序表插入值
	//寻找插入位置
	int pos = 0;
	while (pos<pst->size &&  v>pst->base[pos])
		pos++;
	//插入数据
	SeqlistInsertPos(pst, pos, v);
}

void SeqlistErasePos(Seqlist *pst, int pos) {//顺序表删除pos位置的值
	//检查位置
	if (pos < 0 || pos >= pst->size){
		printf("删除的位置非法，不能删除数据.\n");
		return;
	}
	//删除数据
	for (int i = pos; i < pst->size - 1; ++i) {
		pst->base[i] = pst->base[i + 1];
		pst->size--;
	}
}

void SeqlistEraseVal(Seqlist *pst, ElemType key) {//顺序表删除值
	//查找关键值
	int pos = SeqlistFindVal(pst, key);
	if (pos == -1){
		printf("要删除的数据不存在.\n");
		return;
	}
	//删除数据
	SeqlistErasePos(pst, pos);
}

ElemType SeqlistFindPos(Seqlist *pst, int pos){//根据位置查找
	//检查位置
	assert(pos >= 0 && pos < pst->size);
	return pst->base[pos];
}

int SeqlistFindVal(Seqlist *pst, ElemType key) {//根据值查找
	for (int i = 0; i < pst->size; ++i){
		if (key == pst->base[i])
			return i;
	}
	return -1;
}

void SeqlistSort(Seqlist *pst){//顺序表排序
	for (int i = 0; i < pst->size - 1; ++i){
		bool is_swap = false;
		for (int j = 0; j < pst->size - i - 1; ++j){
			if (pst->base[j] > pst->base[j + 1]){
				Swap(&(pst->base[j]), &(pst->base[j + 1]));
				is_swap = true;
			}
		}
		if (!is_swap) {//没有交换过数据
			break;
		}
	}
}

void SeqlistReverse(Seqlist *pst){//顺序表逆置
	int left = 0;
	int right = pst->size - 1;
	while (left < right){
		Swap(&(pst->base[left]), &(pst->base[right]));
		left++;
		right--;
	}
}

size_t SeqlistLength(Seqlist *pst) {//顺序表长度
	return pst->size;
}

size_t SeqlistCapacity(Seqlist *pst){//顺序表容量
	return pst->capacity;
}

void SeqlistClear(Seqlist *pst){//顺序表清除
	pst->size = 0;
}

void SeqlistDestory(Seqlist *pst) {//顺序表摧毁
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->size = 0;
}