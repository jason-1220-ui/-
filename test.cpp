#define _CRT_SECURE_NO_WARNINGS
# include<stdio.h>
# include<stdlib.h>
# define QueueMaxSize 20	/* ����������鳤�� */
# define StackMaxSize 10 /* ����ջ���鳤�� */
typedef char ElemType;
struct BTreeNode {
	ElemType data;
	struct BTreeNode * left;
	struct BTreeNode * right;
}BTreeNode;
void InitBTree(struct BTreeNode** BT) {
	/* ��ʼ������������������ָ���ÿ� */
	*BT = NULL;
}
void CreateBTree(struct BTreeNode ** BT, char * a) {/* ���� a ������Ķ�����������ַ���������Ӧ�Ĵ洢�ṹ */
	struct BTreeNode * p = NULL;
	/*���� s ������Ϊ�洢�����ָ���ջʹ��	*/
	struct BTreeNode * s[StackMaxSize];
	/*����top��Ϊsջ��ջ��ָ�룬��ֵΪ-1����ʾ��ջ*/
	int top = -1;
	/*�� k ��Ϊ����������������������ı�ǣ� k=1 ������������ k=2 ���������� */ int k;
	/*��iɨ������a�д洢�Ķ�����������ַ�������ֵΪ 0*/
	int i = 0;
	/*������ָ����Ϊ�գ����ӿ�����ʼ���������� */
	*BT = NULL;
	/*ÿѭ��һ�δ���һ���ַ���ֱ��ɨ�赽�ַ�������	\0Ϊֹ */
	while (a[i]) {
		switch (a[i]) {
		case ' ': /* �Կո����κδ��� */
			break;
		case '(':
			if (top == StackMaxSize - 1) {
				printf(" ջ�ռ�̫С�������� StackMaxSize!\n");
				exit(1);
			}
			top++;
			s[top] = p;
			k = 1;
			break;
		case ')':
			if (top == -1) {
				printf(" ������������ַ����� !\n");
				exit(1);
			}
			top--;
			break;
		case ',':
			k = 2;
			break;
		default:
			p = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
			p->data = a[i];
			p->left = p->right = NULL;
			if (*BT == NULL)
				*BT = p;
			else {
				if (k == 1)
					s[top]->left = p;
				else
					s[top]->right = p;
			}
		} /*switch end*/
		/* Ϊɨ����һ���ַ����޸� i ֵ*/
		i++;
	}
}
void PrintBTree(struct BTreeNode * BT) {
	/* ����������Ĺ�����ʾ */
	/* ��Ϊ��ʱ��Ȼ�����ݹ飬����ִ�����²���	*/
	if (BT == NULL) {
		/* ���������ֵ */
		printf("%c", BT->data);
		/* ����������� */
		if (BT->left != NULL || BT->right != NULL) {
			printf("(");	/* ��������� */
			PrintBTree(BT->left); /* ��������� */
			if (BT->right != NULL)
				PrintBTree(BT->right); /* ��������� */ printf(")"); /* ��������� */
		}
	}
}
void Preorder(struct BTreeNode * BT) {
	if (BT != NULL) {
		printf("%c", BT->data); /* ���ʸ���� */
		Preorder(BT->left); /* ǰ����������� */
		Preorder(BT->right); /* ǰ����������� */
	}
}
void Inorder(struct BTreeNode * BT) {
	if (BT != NULL) {
		Inorder(BT->left); /* ������������� */
		printf("%c", BT->data); /* ���ʸ���� */
		Inorder(BT->right); /* ������������� */
	}
}
void Postorder(struct BTreeNode * BT) {
	if (BT != NULL) {
		Postorder(BT->left); /* ������������� */
		Postorder(BT->right); /* ������������� */
		printf("%c", BT->data); /* ���ʸ���� */
	}
}
void Levelorder(struct BTreeNode * BT) {/* ��������� BT ָ����ָ��Ķ����� */
	struct BTreeNode * p;
	/* ���������ʹ�õ�����ռ䣬Ԫ������Ϊָ�����ָ������	*/
	struct BTreeNode* q[QueueMaxSize];
	/*�������ָ��Ͷ�βָ�룬��ʼ����	0 ��ʾ�ն� */
	int front = 0, rear = 0;
	/* ������ָ����� */
	if (BT != NULL) {
		rear = (rear + 1) % QueueMaxSize;
		q[rear] = BT;
	}
	/* �����зǿ�ʱִ��ѭ�� */
	while (front != rear) {
		/* ʹ����ָ��ָ�����Ԫ�� */
		front = (front + 1) % QueueMaxSize;
		/* ɾ������Ԫ�أ��������Ԫ����ָ����ֵ */
		p = q[front];
		printf("%c", p->data);
		/* �����������ӣ�������ָ������� */
		if (p->left != NULL) {
			rear = (rear + 1) % QueueMaxSize;
			q[rear] = p->left;
		}
		if (p->right != NULL) {
			rear = (rear + 1) % QueueMaxSize;
			q[rear] = p->right;
		}
	}
}
int BTreeDepth(struct BTreeNode * BT) {/*����ָ��ָ���һ�Ŷ����������*/
	if (BT == NULL)
		return 0; /* ���ڿ��������� 0 �������ݹ� */
	else {/* ��������������� */
		int dep1 = BTreeDepth(BT->left);
		/* ��������������� */
		int dep2 = BTreeDepth(BT->right);
		/* ����������� */
		if (dep1 > dep2)
			return dep1 + 1;
		else
			return dep2 + 1;
	}
}

void Wrong() {// ������ʾ 
	printf("\n=====> �������� !\n");
	getchar();//����������Ϣ����ʾ
}
int main() {
	/*����ָ��������ڵ�Ĳ���������ָ����Ϊ����ָ��	*/
	struct BTreeNode * bt;
	/*����һ�����ڴ�Ŷ������������ַ�����	*/
	char b[50];
	/*���� ElemType ���͵Ķ��� X ��ָ����� px*/ ElemType x, *px;
	/*��ʼ������������������	bt Ϊ�� */
	InitBTree(&bt);
	/*�Ӽ������ַ�����	b ���������������ʶ���ַ��� */
	printf(" ���������������ַ��� :\n");
	printf(" �����ʽΪ :a(c(m,d(s,z)),e(t(h,k),b(i))\n"); scanf("%s", b);
	/*������ bt ��Ϊ����ָ��Ķ����������Ӵ洢�ṹ */
	CreateBTree(&bt, b);
	printf("\n �������������ѡ��һ��������***************\n");
	printf("1�����¶��������                             \n");
	printf("2��ǰ�����������                             \n");
	printf("3���������������                             \n");
	printf("4���������������                             \n");
	printf("5��������ȱ���������                         \n");
	printf("6�����������                                 \n");
	printf("0���˳�                                       \n");
	printf("**********************************************\n");
	while (1) {// �������ʾʵ��
		int p ;
		scanf("%d", &p);
		switch (p) {
		case 0:
			printf("===> ллʹ�� !\n");
			getchar();
			break;
		case 1:
			printf("���������������������ַ��� :\n");
			printf("�����ʽΪ :a(c(m,d(s,z)),e(t(h,k),b(i))\n"); scanf("%s", b);
			/*������ bt ��Ϊ����ָ��Ķ����������Ӵ洢�ṹ*/
			CreateBTree(&bt, b);
			printf("\n");
			getchar();
			break;
		case 2:
			/* �Թ������ʽ��������� */
			PrintBTree(bt);
			printf("\n");
			/*ǰ������� bt Ϊ����ָ��Ķ����� */ printf(" ǰ�� : ");
			Preorder(bt);
			printf("\n");
			getchar();
			break;
		case 3:
			/* �Թ������ʽ��������� */
			PrintBTree(bt); printf("\n");
			/*��������� bt Ϊ����ָ��Ķ����� */ printf(" ����: ");
			Inorder(bt); printf("\n"); getchar(); break;
		case 4:
			/* �Թ������ʽ��������� */ PrintBTree(bt);
			printf("\n");
			/*��������� bt Ϊ����ָ��Ķ����� */ printf(" ���� : ");
			Postorder(bt); printf("\n"); getchar(); break;
		case 5:
			/* �Թ������ʽ��������� */ PrintBTree(bt);
			printf("\n");
			/*�Ӳ������ bt Ϊ����ָ��Ķ����� */ printf(" ������� : ");
			Levelorder(bt);
			printf("\n");
			getchar();
			break;
		case 6:
			/* �Թ������ʽ��������� */ PrintBTree(bt);
			printf("\n");
			/*����� bt Ϊ����ָ��Ķ���������� */ printf(" ����������� : "); printf("%d\n", BTreeDepth(bt));
			getchar();
			break;
		default:
			Wrong();
			printf("\n �밴��������� ...");
			getchar();
			break;
		}
	}
}
