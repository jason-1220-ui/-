#include "DCList.h"
int main(int argc, char *argv[])
{
	/*ListNode *pHead = ListCreate();
	ListInit(pHead);
	ListPushBack(pHead, 4);
	ListPrint(pHead);*/
	//顺序表
	//SeqList mylist;
	//SeqListInit(&mylist, 8);

	//单链表
	//List mylist;
	//ListInit(&mylist);

	//单循环链表
	//SCList mylist;
	//SCListInit(&mylist);

	//双循环链表
	//DCList mylist;
	//ListInit(&mylist);

	LTDataType item, value, key,x;
	ListNode *p = NULL;
	ListNode *pHead = ListCreate();
	ListInit(pHead);
	int pos;
	int select = 1;
	while (select)
	{
		printf("********************************************\n");
		printf("* [1] push_back           [2] push_front   *\n");
		printf("* [3] show_list           [0] quit_system  *\n");
		printf("* [4] pop_back            [5] pop_front    *\n");
		printf("* [6] insert_val          [7] erase_pos    *\n");
		printf("* [8] find_val            [9] destroy      *\n");
		printf("********************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if (select == 0)
			break;

		switch (select){
		case 1:
			printf("请输入要插入的数据<以-1结束>:>");
			while (scanf("%d", &item), item != -1)
			{
				ListPushBack(pHead, item);
			}
			break;
		case 2:
			printf("请输入要插入的数据<以-1结束>:>");
			while (scanf("%d", &item), item != -1)
			{
				ListPushFront(pHead, item);
			}
			break;
		case 3:
			ListPrint(pHead);
			break;
		case 4:
			ListPopBack(pHead);
			break;
		case 5:
			ListPopFront(pHead);
			break;
		case 6:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的值:>");
			scanf("%d", &x);
			ListNode* pos = ListFind(pHead, x);
			ListInsert(pos, x);
			break;
		case 7:
			printf("请输入要删除的位置:>");
			scanf("%d", &p);
			ListNode *p = ListFind(pHead, 5);
			ListErase(p);
			break;
		case 8:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			p = ListFind(pHead, key);
			if (p == NULL)
				printf("要查找的%d数据不存在.\n", key);
			else
				printf("%d数据已被查找到.\n", key);
			break;
		case 9:
			ListDestory(pHead);
			break;
		default:
			break;
		}
	}
	printf("GoodBye.\n");
	return 0;
}