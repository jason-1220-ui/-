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
		printf("����������ѡ��");
		scanf("%d", &select);
		if (select == 0) {
			break;
		}
		switch (select) {
		case 1:
			printf("��������Ҫ���������(��-1��Ϊ�������)��");
			while (scanf("%d", &item), item != -1) {
				SeqlistPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("��������Ҫ���������(��-1��Ϊ�������)��");
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
			printf("������Ҫ�����Ԫ�أ�");
			scanf("%d", &item);
			printf("����������λ�ã�");
			scanf("%d", &pos);
			SeqlistInsertPos(&mylist, item, pos);
			break;
		case 7:
			printf("������Ҫ�����ֵ:");
			scanf("%d", &item);
			SeqlistInsertVal(&mylist, item);
			break;
		case 8:
			printf("������Ҫɾ����λ�ã�");
			scanf("%d", &pos);
			SeqlistErasePos(&mylist, pos);
			break;
		case 9:
			printf("������Ҫɾ����ֵ��");
			scanf("%d", &key);
			SeqlistEraseVal(&mylist, key);
			break;
		case 10:
			printf("������Ҫ���ҵ�λ��:>");
			scanf("%d", &pos);
			value = SeqlistFindPos(&mylist, pos);
			printf("��%dλ�õ�ֵΪ:> %d\n", pos, value);
			break;
			break;
		case 11:
			printf("������Ҫ���ҵ�ֵ:");
			scanf("%d", &key);
			pos = SeqlistFindVal(&mylist, key);
			if (pos == -1)
				printf("Ҫ���ҵ�%d���ݲ�����.\n", key);
			else
				printf("Ҫ���ҵ�����%d�� %dλ��.\n", key, pos);
			break;
		case 12:
			SeqlistSort(&mylist);
			break;
		case 13:
			SeqlistReverse(&mylist);
			break;
		case 14:
			printf("˳���ĳ���Ϊ��%d\n", SeqlistLength(&mylist));
			break;
		case 15:
			printf("˳��������Ϊ: %d\n", SeqlistCapacity(&mylist));
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