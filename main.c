#include "DCList.h"
int main(int argc, char *argv[])
{
	/*ListNode *pHead = ListCreate();
	ListInit(pHead);
	ListPushBack(pHead, 4);
	ListPrint(pHead);*/
	//˳���
	//SeqList mylist;
	//SeqListInit(&mylist, 8);

	//������
	//List mylist;
	//ListInit(&mylist);

	//��ѭ������
	//SCList mylist;
	//SCListInit(&mylist);

	//˫ѭ������
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
		printf("��ѡ��:>");
		scanf("%d", &select);
		if (select == 0)
			break;

		switch (select){
		case 1:
			printf("������Ҫ���������<��-1����>:>");
			while (scanf("%d", &item), item != -1)
			{
				ListPushBack(pHead, item);
			}
			break;
		case 2:
			printf("������Ҫ���������<��-1����>:>");
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
			printf("������Ҫ�����λ��:>");
			scanf("%d", &pos);
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &x);
			ListNode* pos = ListFind(pHead, x);
			ListInsert(pos, x);
			break;
		case 7:
			printf("������Ҫɾ����λ��:>");
			scanf("%d", &p);
			ListNode *p = ListFind(pHead, 5);
			ListErase(p);
			break;
		case 8:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			p = ListFind(pHead, key);
			if (p == NULL)
				printf("Ҫ���ҵ�%d���ݲ�����.\n", key);
			else
				printf("%d�����ѱ����ҵ�.\n", key);
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