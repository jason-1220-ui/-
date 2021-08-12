#define _CRT_SECURE_NO_WARNINGS

#include"Seqlist.h"

int main(int argc,char *argv[]) {
	Seqlist mylist;
	SeqlistInit(&mylist, 8);

	ElemType item, key, value;
	int pos;
	int select = 1;
	while (select) {
		printf("===================================\n");
		printf("[1]push_back       [2]push_front   \n");
		printf("[3]show_list       [0]quit_system  \n");
		printf("[4]pop_back        [5]pop_front    \n");
		printf("[6]insert_pos      [7]insert_val   \n");
		printf("[8]erase_pos       [9]erase_val    \n");
		printf("[10]find_pos       [11]find_val    \n");
		printf("[12]sort           [13]reverse     \n");
		printf("[14]length         [15]capacity    \n");
		printf("[16]clear          [17]destory     \n");
		printf("===================================\n");
		printf("请输入您的选择：");
		scanf("%d", &select);
		if (select == 0) {
			break;
		}
		switch (select) {
		case 1:
			printf("请输入您要插入的数据(以-1作为结束标记)：");
			while (scanf("%d", &item), item != -1) {
				SeqlistPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("请输入您要插入的数据(以-1作为结束标记)：");
			while (scanf("%d", &item), item != -1) {
				SeqlistPushFront(&mylist, item);
			}
			break;
		case 3:
			SeqlistShow(&mylist);
			break;
		case 4:
			SeqlistPopBack(&mylist);
			break;
		case 5:
			SeqlistPopFront(&mylist);
			break;
		case 6:
			printf("请输入要插入的元素：");
			scanf("%d", &item);
			printf("请输入插入的位置：");
			scanf("%d", &pos);
			SeqlistInsertPos(&mylist, item, pos);
			break;
		case 7:
			printf("请输入要插入的值:");
			scanf("%d", &item);
			SeqlistInsertVal(&mylist, item);
			break;
		case 8:
			printf("请输入要删除的位置：");
			scanf("%d", &pos);
			SeqlistErasePos(&mylist, pos);
			break;
		case 9:
			printf("请输入要删除的值：");
			scanf("%d", &key);
			SeqlistEraseVal(&mylist, key);
			break;
		case 10:
			printf("请输入要查找的位置:>");
			scanf("%d", &pos);
			value = SeqlistFindPos(&mylist, pos);
			printf("在%d位置的值为:> %d\n", pos, value);
			break;
			break;
		case 11:
			printf("请输入要查找的值:");
			scanf("%d", &key);
			pos = SeqlistFindVal(&mylist, key);
			if (pos == -1)
				printf("要查找的%d数据不存在.\n", key);
			else
				printf("要查找的数据%d在 %d位置.\n", key, pos);
			break;
		case 12:
			SeqlistSort(&mylist);
			break;
		case 13:
			SeqlistReverse(&mylist);
			break;
		case 14:
			printf("顺序表的长度为：%d\n", SeqlistLength(&mylist));
			break;
		case 15:
			printf("顺序表的容量为: %d\n", SeqlistCapacity(&mylist));
			break;
		case 16:
			SeqlistClear(&mylist);
			break;
		case 17:
			SeqlistDestory(&mylist);
			break;
		default:
			break;
		}
	}
	printf("goodbye!\n");
	return 0;
}