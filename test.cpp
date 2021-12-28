#define _CRT_SECURE_NO_WARNINGS
# include<stdio.h>
# include<stdlib.h>
# define QueueMaxSize 20	/* 定义队列数组长度 */
# define StackMaxSize 10 /* 定义栈数组长度 */
typedef char ElemType;
struct BTreeNode {
	ElemType data;
	struct BTreeNode * left;
	struct BTreeNode * right;
}BTreeNode;
void InitBTree(struct BTreeNode** BT) {
	/* 初始化二叉树，即把树根指针置空 */
	*BT = NULL;
}
void CreateBTree(struct BTreeNode ** BT, char * a) {/* 根据 a 所定义的二叉树广义表字符串建立对应的存储结构 */
	struct BTreeNode * p = NULL;
	/*定义 s 数组作为存储根结点指针的栈使用	*/
	struct BTreeNode * s[StackMaxSize];
	/*定义top作为s栈的栈顶指针，初值为-1，表示空栈*/
	int top = -1;
	/*用 k 作为处理结点的左子树和右子树的标记， k=1 处理左子树， k=2 处理右子树 */ int k;
	/*用i扫描数组a中存储的二叉树广义表字符串，初值为 0*/
	int i = 0;
	/*把树根指针置为空，即从空树开始建立二叉树 */
	*BT = NULL;
	/*每循环一次处理一个字符，直到扫描到字符串结束	\0为止 */
	while (a[i]) {
		switch (a[i]) {
		case ' ': /* 对空格不做任何处理 */
			break;
		case '(':
			if (top == StackMaxSize - 1) {
				printf(" 栈空间太小，需增加 StackMaxSize!\n");
				exit(1);
			}
			top++;
			s[top] = p;
			k = 1;
			break;
		case ')':
			if (top == -1) {
				printf(" 二叉树广义表字符串错 !\n");
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
		/* 为扫描下一个字符串修改 i 值*/
		i++;
	}
}
void PrintBTree(struct BTreeNode * BT) {
	/* 输出二叉数的广义表表示 */
	/* 数为空时自然结束递归，否则执行如下操作	*/
	if (BT == NULL) {
		/* 输出根结点的值 */
		printf("%c", BT->data);
		/* 输出左、右子树 */
		if (BT->left != NULL || BT->right != NULL) {
			printf("(");	/* 输出左括号 */
			PrintBTree(BT->left); /* 输出左子树 */
			if (BT->right != NULL)
				PrintBTree(BT->right); /* 输出右子树 */ printf(")"); /* 输出右括号 */
		}
	}
}
void Preorder(struct BTreeNode * BT) {
	if (BT != NULL) {
		printf("%c", BT->data); /* 访问根结点 */
		Preorder(BT->left); /* 前序遍历左子树 */
		Preorder(BT->right); /* 前序遍历右子树 */
	}
}
void Inorder(struct BTreeNode * BT) {
	if (BT != NULL) {
		Inorder(BT->left); /* 中序遍历左子树 */
		printf("%c", BT->data); /* 访问根结点 */
		Inorder(BT->right); /* 中序遍历右子树 */
	}
}
void Postorder(struct BTreeNode * BT) {
	if (BT != NULL) {
		Postorder(BT->left); /* 后序遍历左子树 */
		Postorder(BT->right); /* 后序遍历右子树 */
		printf("%c", BT->data); /* 访问根结点 */
	}
}
void Levelorder(struct BTreeNode * BT) {/* 按层遍历由 BT 指针所指向的二叉树 */
	struct BTreeNode * p;
	/* 定义队列所使用的数组空间，元素类型为指向结点的指针类型	*/
	struct BTreeNode* q[QueueMaxSize];
	/*定义队首指针和队尾指针，初始均置	0 表示空队 */
	int front = 0, rear = 0;
	/* 将树根指针进队 */
	if (BT != NULL) {
		rear = (rear + 1) % QueueMaxSize;
		q[rear] = BT;
	}
	/* 当队列非空时执行循环 */
	while (front != rear) {
		/* 使队首指针指向队首元素 */
		front = (front + 1) % QueueMaxSize;
		/* 删除队首元素，输出队首元素所指结点的值 */
		p = q[front];
		printf("%c", p->data);
		/* 若结点存在左孩子，则左孩子指针结点进队 */
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
int BTreeDepth(struct BTreeNode * BT) {/*求由指针指向的一颗二叉树的深度*/
	if (BT == NULL)
		return 0; /* 对于空树，返回 0 并结束递归 */
	else {/* 计算左子树的深度 */
		int dep1 = BTreeDepth(BT->left);
		/* 计算右子树的深度 */
		int dep2 = BTreeDepth(BT->right);
		/* 返回树的深度 */
		if (dep1 > dep2)
			return dep1 + 1;
		else
			return dep2 + 1;
	}
}

void Wrong() {// 错误提示 
	printf("\n=====> 按键错误 !\n");
	getchar();//保留错误信息的显示
}
int main() {
	/*定义指向二叉树节点的操作，并用指针作为树根指针	*/
	struct BTreeNode * bt;
	/*定义一个用于存放二叉树广义表的字符数组	*/
	char b[50];
	/*定义 ElemType 类型的对象 X 和指针对象 px*/ ElemType x, *px;
	/*初始化二叉树，即置树根	bt 为空 */
	InitBTree(&bt);
	/*从键盘向字符数组	b 输入二叉树广义表标识的字符串 */
	printf(" 输入二叉树广义表字符串 :\n");
	printf(" 输入格式为 :a(c(m,d(s,z)),e(t(h,k),b(i))\n"); scanf("%s", b);
	/*建立以 bt 作为树根指针的二叉树的链接存储结构 */
	CreateBTree(&bt, b);
	printf("\n 请在下列序号中选择一个并输入***************\n");
	printf("1、重新定义二叉树                             \n");
	printf("2、前序遍历二叉树                             \n");
	printf("3、中序遍历二叉树                             \n");
	printf("4、后序遍历二叉树                             \n");
	printf("5、广度优先遍历二叉树                         \n");
	printf("6、二叉树深度                                 \n");
	printf("0、退出                                       \n");
	printf("**********************************************\n");
	while (1) {// 界面的显示实现
		int p ;
		scanf("%d", &p);
		switch (p) {
		case 0:
			printf("===> 谢谢使用 !\n");
			getchar();
			break;
		case 1:
			printf("请重新输入二叉树广义表字符串 :\n");
			printf("输入格式为 :a(c(m,d(s,z)),e(t(h,k),b(i))\n"); scanf("%s", b);
			/*建立以 bt 作为树根指针的二叉树的链接存储结构*/
			CreateBTree(&bt, b);
			printf("\n");
			getchar();
			break;
		case 2:
			/* 以广义表形式输入二叉树 */
			PrintBTree(bt);
			printf("\n");
			/*前序遍历以 bt 为树根指针的二叉树 */ printf(" 前序 : ");
			Preorder(bt);
			printf("\n");
			getchar();
			break;
		case 3:
			/* 以广义表形式输入二叉树 */
			PrintBTree(bt); printf("\n");
			/*中序遍历以 bt 为树根指针的二叉树 */ printf(" 中序: ");
			Inorder(bt); printf("\n"); getchar(); break;
		case 4:
			/* 以广义表形式输入二叉树 */ PrintBTree(bt);
			printf("\n");
			/*后序遍历以 bt 为树根指针的二叉树 */ printf(" 后序 : ");
			Postorder(bt); printf("\n"); getchar(); break;
		case 5:
			/* 以广义表形式输入二叉树 */ PrintBTree(bt);
			printf("\n");
			/*接层遍历以 bt 为树根指针的二叉树 */ printf(" 广度优先 : ");
			Levelorder(bt);
			printf("\n");
			getchar();
			break;
		case 6:
			/* 以广义表形式输入二叉树 */ PrintBTree(bt);
			printf("\n");
			/*求出以 bt 为树根指针的二叉树的深度 */ printf(" 二叉树的深度 : "); printf("%d\n", BTreeDepth(bt));
			getchar();
			break;
		default:
			Wrong();
			printf("\n 请按任意键继续 ...");
			getchar();
			break;
		}
	}
}
