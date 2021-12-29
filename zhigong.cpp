#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ALLMAX 100 //总共统计的职工的人数

typedef struct Node{
	long int born_date, work_date, tele_num;
	char sex, name[ALLMAX], degree[ALLMAX], job[ALLMAX], address[ALLMAX];
	struct Node *next;
}SLNode;

typedef struct{
	long int born_date, work_date, tele_num;
	char name[ALLMAX], sex, degree[ALLMAX], job[ALLMAX], address[ALLMAX];
}DataType;


void ListInitiate(SLNode **head){//链表初始化
	if ((*head = (SLNode *)malloc(sizeof(SLNode))) == NULL)
		exit(1);//动态分配存储空间
	(*head)->next = NULL;
}

SLNode *ListInsert(SLNode *head, DataType x){//职工信息的插入姓名并按照升序排列
	SLNode *p, *q, *s;
	p = head->next;
	if ((q = (SLNode *)malloc(sizeof(SLNode))) == NULL)
		exit(1);//动态分配存储空间
	q->born_date = x.born_date;
	q->work_date = x.work_date;
	q->tele_num = x.tele_num;
	strcpy(q->name, x.name);
	q->sex = x.sex;
	strcpy(q->degree, x.degree);
	strcpy(q->job, x.job);
	strcpy(q->address, x.address);
	if (head->next == NULL){//如果只有链表的头结点，没有其他的结点，直接插入在头结点后面
		head->next = q;
		head->next->next = NULL;
	}
	else{//链表非空
		for (; p; p = p->next){
			if (p->next != NULL){
				if (strcmp(p->name, x.name) < 0 && strcmp(p->next->name, x.name) > 0){//位于两个结点之间
					s = p->next;
					p->next = q;
					q->next = s;
					break;
				}
				//else if(strcmp(p->name,x.name)==0)break;   //如果姓名相同则不插入信息
			}
			else if (strcmp(p->name, x.name) < 0 && p->next == NULL){//链表非空，并且在排序中是最后一个
				p->next = q;
				q->next = NULL;
				break;
			}
			if (strcmp(p->name, x.name) > 0){//位于链表头结点之后的位置
				s = head->next;
				head->next = q;
				q->next = s;
				break;
			}
		}
	}
	return head;
}

void print(SLNode *head){//职工信息的显示
	for (SLNode *p = head->next; p; p = p->next)//输出所有职工的信息
		printf("%s %c %ld %ld %s %s %s %ld\n", p->name, p->sex, p->born_date, p->work_date, p->degree, p->job, p->address, p->tele_num);
}

void printLink(SLNode *head){//职工信息的显示
	printf("职工名单：\n姓名、性别、出生年月、工作年月、学历、职务、住址、电话\n");
	print(head);
}


void put(SLNode *head, FILE *fp){//职工信息的保存
	SLNode *p;
	if ((fp = fopen("Employee.txt", "w")) == NULL){
		printf("无法打开'Employee.txt'!\n");
		exit(0);
	}
	for (p = head->next; p; p = p->next){
		fprintf(fp, "%s %c %ld %ld %s %s %s %ld\n", p->name, p->sex, p->born_date, p->work_date, p->degree, p->job, p->address, p->tele_num);
	}
	if (fclose(fp))
		printf("无法关闭'Employee.txt'!\n"); exit(0);
}


void ListDelete(SLNode *head){//职工信息的删除
	SLNode *p, *s;
	char x[20];
	s = head;
	p = head->next;
	if (head->next == NULL){//链表为空，输出：名单中无职工信息，无须删除！
		printf("名单中无此职工信息，无须删除！\n");
		return;
	}
	printf("请输入要删除职工的姓名：\n"); //输入要删除的人的姓名
	scanf("%s", x);
	for (p; p; p = p->next){//在链表中从头到尾查找输入的人的姓名
		if (strcmp(p->name, x) == 0){	//如果存在，则删除，否则输出：名单中无职工信息，无须删除！
			s->next = p->next;
			free(p);
			printf("删除成功！请继续操作！\n");
			printLink(head);
			break;
		}
		s = p;
	}
	if (p == NULL)
		printf("名单中无此职工信息，无须删除！\n");
}

void ListModify(SLNode *head){//职工信息的修改
	DataType x;
	SLNode *p;
	p = head->next;
	if (p == NULL){
		printf("职工名单无职工信息，无须修改！\n");
		return;
	}
	printf("请输入要修改的职工姓名：\n");
	scanf("%s", x.name);
	for (; p; p = p->next){
		if (strcmp(x.name, p->name) == 0){//查找到了该职工的信息
			printf("依次写入该职工的新信息：\n");
			printf("请输入职工信息：\n姓名、性别、出生年月、工作年月、学历、职务、住址、电话\n");
			scanf("%s %c %ld %ld %s %s %s %ld", p->name, &p->sex, &p->born_date, &p->work_date, p->degree, p->job, p->address, &p->tele_num);
			printf("修改成功！请继续操作！\n");
			break;
		}
	}
	if (p == NULL)
		printf("此职工不存在，无法修改其信息！\n");

}



void Listfind(SLNode head){//职工信息的查找
	int i, j;
	SLNode *p;
	DataType x;
	if (head.next == NULL){//链表为空
		printf("名单中无职工信息，查询失败！\n");
		return;
	}
	//返回主菜单
	printf("\n");
	printf("\t******************************************************************\n");
	printf("\t*                        职工信息查询操作                        *\n");
	printf("\t*                                                                *\n");
	printf("\t*  0.退出查询系统，回到主菜单\t\t     1.对姓名进行查询\t*\n\t*  2.对出生年月进行查询      \t\t     3.对学历进行查询\t*\n\t*  4.对工作年月进行查询      \t\t     5.对职务进行查询\t*\n\t*  6.对住址进行查询      \t\t     7.对电话进行查询\t*\n");
	printf("\t******************************************************************\n");
	while (1){
		printf("请输入您要选择的操作：");
		scanf("%d", &i);
		if (i == 0)//输入0，退出查询系统，回到主菜单
			break;
		else if (i == 1) {//输入1，对姓名进行查询
			p = head.next;
			printf("请输入姓名：");
			scanf("%s", x.name);
			j = 0;
			for (p; p; p = p->next) {
				if (strcmp(p->name, x.name) == 0) {//如果存在这个人，那么j自加
					++j;
					printf("\n姓名、性别、出生年月、工作年月、学历、职务、住址、电话\n");
					printf("%s %c %ld %ld %s %s %s %ld\n", p->name, p->sex, p->born_date, p->work_date, p->degree, p->job, p->address, p->tele_num);
				}
			}
			if (j == 0)//表示没有找到输入的信息
				printf("职工名单中不存在此人！\n");
			else printf("查询成功！继续操作！\n");
		}
		else if (i == 2) {//输入2，对出生年月进行查询
			p = head.next;
			printf("请输入出生年月：");
			scanf("%ld", &x.born_date);
			j = 0;
			for (p; p; p = p->next) {
				if (p->born_date == x.born_date) {//输入的出生年月在链表中存在
					++j;//如果存在这个人，那么j自加
					printf("\n姓名、性别、出生年月、工作年月、学历、职务、住址、电话\n");
					printf("%s %c %ld %ld %s %s %s %ld\n", p->name, p->sex, p->born_date, p->work_date, p->degree, p->job, p->address, p->tele_num);
				}
			}
			if (j == 0)//表示没有找到输入的信息
				printf("职工名单中没有这个时间出生的！\n");
			else printf("查询成功！请继续操作！\n");
		}
		else if (i == 4) {//输入4，对工作年月进行查询
			p = head.next;
			printf("请输入工作年月：");
			scanf("%ld", &x.work_date);
			j = 0;
			for (p; p; p = p->next) {
				if (p->work_date == x.work_date) {
					++j;//如果存在这个人，那么j自加
					printf("\n姓名、性别、出生年月、工作年月、学历、职务、住址、电话\n");
					printf("%s %c %ld %ld %s %s %s %ld\n", p->name, p->sex, p->born_date, p->work_date, p->degree, p->job, p->address, p->tele_num);
				}
			}
			if (j == 0)//表示没有找到输入的信息
				printf("职工名单中没有这个时间工作的！\n");
			else printf("查询成功！请继续操作！\n");
		}
		else if (i == 3) {//输入3，对学历进行查询
			p = head.next;
			printf("请输入学历：");
			scanf("%s", x.degree);
			j = 0;
			for (p; p; p = p->next) {
				if (strcmp(p->degree, x.degree) == 0) {
					++j;//如果存在这个人，那么j自加
					printf("\n姓名、性别、出生年月、工作年月、学历、职务、住址、电话\n");
					printf("%s %c %ld %ld %s %s %s %ld\n", p->name, p->sex, p->born_date, p->work_date, p->degree, p->job, p->address, p->tele_num);
				}
			}
			if (j == 0)//表示没有找到输入的信息
				printf("职工名单中没有这种学历的！\n");
			else printf("查询成功！请继续操作！\n");
		}
		else if (i == 5) {//输入5，对职务进行查询
			p = head.next;
			printf("请输入职务：");
			scanf("%s", x.job);
			j = 0;
			for (p; p; p = p->next) {
				if (strcmp(p->job, x.job) == 0) {
					++j;//如果存在这个人，那么j自加
					printf("\n姓名、性别、出生年月、工作年月、学历、职务、住址、电话\n");
					printf("%s %c %ld %ld %s %s %s %ld\n", p->name, p->sex, p->born_date, p->work_date, p->degree, p->job, p->address, p->tele_num);
				}
			}
			if (j == 0)//表示没有找到输入的信息
				printf("职工名单中没有这种职务的！\n");
			else printf("查询成功！请继续操作！\n");
		}
		else if (i == 6) {//输入6，对住址进行查询
			p = head.next;
			printf("请输入住址：");
			scanf("%s", x.address);
			j = 0;
			for (p; p; p = p->next) {
				if (strcmp(p->address, x.address) == 0) {
					++j;//如果存在这个人，那么j自加
					printf("\n姓名、性别、出生年月、工作年月、学历、职务、住址、电话\n");
					printf("%s %c %ld %ld %s %s %s %ld\n", p->name, p->sex, p->born_date, p->work_date, p->degree, p->job, p->address, p->tele_num);
				}
			}
			if (j == 0)//表示没有找到输入的信息
				printf("职工名单中没有住这的！\n");
			else printf("查询成功！请继续操作！\n");
		}
		else if (i == 7) {//输入7，对电话号码进行查询
			p = head.next;
			printf("请输入电话：");
			scanf("%ld", &x.tele_num);
			j = 0;
			for (p; p; p = p->next) {
				if (p->tele_num == x.tele_num) {
					++j;//如果存在这个人，那么j自加
					printf("\n姓名、性别、出生年月、工作年月、学历、职务、住址、电话\n");
					printf("%s %c %ld %ld %s %s %s %ld\n", p->name, p->sex, p->born_date, p->work_date, p->degree, p->job, p->address, p->tele_num);
				}
			}
			if (j == 0)//表示没有找到输入的信息
				printf("职工名单中没人用这个号码！\n");
			else printf("查询成功！请继续操作！\n");
		}
		else if (i != 0 && i != 1 && i != 2 && i != 3 && i != 4 && i != 5 && i != 6 && i != 7)//输入任意不是上述数字的，那么久显示输入错误
			printf("输入出错！请再次输入！\n");
		printf("\n");
		printf("\t******************************************************************\n");
		printf("\t*                        职工信息查询系统                        *\n");
		printf("\t*                                                                *\n");
		printf("\t*  0.退出查询系统，回到主菜单\t\t     1.对姓名进行查询\t*\n\t*  2.对出生年月进行查询      \t\t     3.对学历进行查询\t*\n\t*  4.对工作年月进行查询      \t\t     5.对职务进行查询\t*\n\t*  6.对住址进行查询      \t\t     7.对电话进行查询\t*\n");
		printf("\t******************************************************************\n");

		//printf("0.退出查询系统，回到主菜单\n1.对姓名进行查询\n2.对出生年月进行查询\n3.对工作年月进行查询\n4.对学历进行查询\n5.对职务进行查询\n6.对住址进行查询\n7.对电话号码进行查询\n");
	}
}



void Listpaixu(SLNode *head)//职工信息的排序
{
	int i, n = 0, m, flag = 1;
	SLNode *p, *q, *s;
	if (head->next == NULL) {//职工链表为空
		printf("名单中无职工信息，无法排序！\n\n");
		return;
	}
	//	printf("输入出错！请再次输入！\n\n");
	printf("\t\t~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~\n");
	printf("\t\t~.~             职工信息排序操作            ~.~\n");
	printf("\t\t~.~                                         ~.~\n");
	printf("\t\t~.~\t0.退出排序系统，回到主菜单          ~.~\n\t\t~.~\t1.对性别进行排序                    ~.~\n\t\t~.~\t2.对出生年月进行排序                ~.~\n\t\t~.~\t3.对工作年月进行排序                ~.~\n\t\t~.~\t4.对姓名进行排序                    ~.~\n");
	printf("\t\t~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~\n");
	while (1)
	{
		printf("请输入您要选择的操作：");
		scanf("%d", &i);
		if (i == 0)//输入0，退出排序系统，回到主菜单
			break;
		else if (i == 1) {//输入1，对性别进行排序
			n = 0, m, flag = 1;
			for (p = head; NULL != p; p = p->next)//统计职工人数
				n++;
			for (m = 1; flag&&m <= n; m++)
			{
				flag = 0;
				for (q = head->next, p = head, s = p; q; s = p, p = q, q = q->next)
				{
					if (p->sex > q->sex)//p为当前节点，p的性别>p的后继节点的性别
					{
						if (head == p)//p为头结点
						{
							head->next = q->next;
							head = q;
							q->next = p;//交换节点信息
							q = head->next;
							p = head;
						}
						else
						{
							p->next = q->next;
							q->next = p;
							s->next = q;
							p = q;
							q = p->next;
						}
						flag = 1;
					}
				}
			}
			printf("排好序的信息如下：\n");
			printLink(head);//输出所有节点的信息
			return;
		}
		else if (i == 2) {//输入2，对出生年月进行排序
			n = 0, m, flag = 1;
			for (p = head; NULL != p; p = p->next)//统计职工人数
				n++;
			for (m = 1; flag&&m <= n; n++)//循环
			{
				flag = 0;
				for (q = head->next, p = head, s = p; q; s = p, p = q, q = q->next)
				{
					if (p->born_date > q->born_date)//对出生年月进行排序
					{
						if (head == p)
						{
							head->next = q->next;
							head = q;
							q->next = p;
							q = head->next;
							p = head;
						}
						else
						{
							p->next = q->next;
							q->next = p;
							s->next = q;
							p = q;
							q = p->next;
						}
						flag = 1;
					}
				}
			}
			printf("排好序的信息如下：\n");
			printLink(head);
			return;
		}
		else if (i == 3) {//输入3，按工作时间进行排序
			n = 0, m, flag = 1;
			for (p = head; NULL != p; p = p->next)
				n++;
			for (m = 1; flag&&m <= n; n++)
			{
				flag = 0;
				for (q = head->next, p = head, s = p; q; s = p, p = q, q = q->next) {
					if (p->work_date > q->work_date) {
						if (head == p) {
							head->next = q->next;
							head = q;
							q->next = p;
							q = head->next;
							p = head;
						}
						else {
							p->next = q->next;
							q->next = p;
							s->next = q;
							p = q;
							q = p->next;
						}
						flag = 1;
					}
				}
			}
			printf("排好序的信息如下：\n");
			printLink(head);
			return;
		}
		else if (i == 4)
		{
			n = 0, m, flag = 1;
			for (p = head; NULL != p; p = p->next)
				n++;
			for (m = 1; flag&&m <= n; n++)
			{
				flag = 0;
				for (q = head->next, p = head, s = p; q; s = p, p = q, q = q->next) {
					if (p->name[0] > q->name[0]) {
						if (head == p) {
							head->next = q->next;
							head = q;
							q->next = p;
							q = head->next;
							p = head;
						}
						else {
							p->next = q->next;
							q->next = p;
							s->next = q;
							p = q;
							q = p->next;
						}
						flag = 1;
					}
				}
			}
			printf("排好序的信息如下：\n");
			printLink(head);
			return;
		}

		else if (i != 0 && i != 1 && i != 2 && i != 3 && i != 4)
			printf("输入出错！请再次输入！\n\n");
		printf("\t\t~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~\n");
		printf("\t\t~.~             职工信息排序系统            ~.~\n");
		printf("\t\t~.~                                         ~.~\n");
		printf("\t\t~.~\t0.退出排序系统，回到主菜单          ~.~\n\t\t~.~\t1.对性别进行排序                    ~.~\n\t\t~.~\t2.对出生年月进行排序                ~.~\n\t\t~.~\t3.对工作年月进行排序                ~.~\n\t\t~.~\t4.显示全部职工信息                  ~.~\n");
		printf("\t\t~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~\n");


		//printf("0.退出排序系统，回到主菜单\n1.对性别进行排序\n2.对出生年月进行排序\n3.对工作年月进行排序\n");

	}
}

int main()
{
	DataType x;
	SLNode *head;
	int i, n;
	FILE *fp = NULL;
	ListInitiate(&head);//初始化链表
	printf("\n");
	printf("*******************************************************************************\n");
	printf("************************    欢迎使用职工管理系统    ***************************\n");
	printf("*******************************************************************************\n");


	printf("请输入要录入的职工人数n：");//输入要录入的职工人数
	scanf("%d", &n);
	if (n == 0)
		goto aa;
	else {
		printf("请输入职工信息：\n姓名、性别、出生年月、工作年月、学历、职务、住址、电话\n");
		for (i = 0; i < n; i++)//职工信息的输入
		{
			scanf("%s %s %ld %ld %s %s %s %ld", x.name, &x.sex, &x.born_date, &x.work_date, x.degree, x.job, x.address, &x.tele_num);
			head = ListInsert(head, x);
		}
		goto aa;
		printLink(head);
		put(head, fp);
	}

aa:	printf("\n");
	printf("\t★☆☆★☆☆★☆☆★★☆☆★☆☆★☆☆★★☆☆★☆☆★☆☆★☆☆★\n");
	printf("\t☆                          * 主菜单 *                          ☆\n");
	printf("\t★                          **********                          ★\n");
	printf("\t☆                                                              ☆\n");
	printf("\t★  \t0.结束管理系统\t\t\t1.新增职工信息\t\t★\n\t☆  \t2.删除职工信息\t\t\t3.查询职工信息\t\t☆\n\t★  \t4.修改职工信息\t\t\t5.职工信息排序\t\t★\n");
	printf("\t☆                                                              ☆\n");
	printf("\t★☆☆★☆☆★☆☆★★☆☆★☆☆★☆☆★★☆☆★☆☆★☆☆★☆☆★\n");


	while (1)
	{
		printf("请输入您要选择的操作：");
		scanf("%d", &i);
		if (i == 0)//输入0，结束系统
		{
			printf("\t\t您已经成功退出职工管理系统,谢谢使用!\n");
			break;
		}
		else if (i == 1)//输入1，新增一名职工
		{
			printf("请输入职工信息：\n姓名、性别、出生年月、工作年月、学历、职务、住址、电话\n");
			scanf("%s %c %ld %ld %s %s %s %ld", x.name, &x.sex, &x.born_date, &x.work_date, x.degree, x.job, x.address, &x.tele_num);
			head = ListInsert(head, x);
			printf("新增成功！请继续操作！\n");
			printLink(head);
			put(head, fp);//保存在文件中
		}
		else if (i == 2)//输入2，删除一名职工
		{
			ListDelete(head);
			if ((fp = fopen("Employee.txt", "w")) == NULL)
			{
				printf("无法打开'职工名单.txt'!\n");
				exit(0);
			}
			put(head, fp);//保存在文件中
			if (fclose(fp))
				printf("无法关闭'Employee.txt'!\n"); exit(0);
		}
		else if (i == 3)//输入3，查找一名职工
			Listfind(*head);
		else if (i == 4)//输入4，修改职工信息
		{
			ListModify(head);
			if ((fp = fopen("Employee.txt", "w")) == NULL)
			{
				printf("无法打开'Employee.txt'!\n");
				exit(0);
			}
			put(head, fp);//保存在文件中
			if (fclose(fp))
				printf("无法关闭'Employee.txt'!\n"); exit(0);
		}
		else if (i == 5)//输入5，对职工信息进行排序
		{
			SLNode *p = head;
			Listpaixu(p);
		}
		//如果出入的不是上述任何一种情况就输出：输入出错
		else printf("输入出错！请再次输入！\n");
		printf("\n");
		printf("\t★☆☆★☆☆★☆☆★★☆☆★☆☆★☆☆★★☆☆★☆☆★☆☆★☆☆★\n");
		printf("\t☆                          * 主菜单 *                          ☆\n");
		printf("\t★                          **********                          ★\n");
		printf("\t☆                                                              ☆\n");
		printf("\t★  0.结束管理系统\t\t\t\t1.新增职工信息\t★\n\t☆  2.删除职工信息\t\t\t\t3.查询职工信息\t☆\n\t★  4.修改职工信息\t\t\t\t5.职工信息排序\t★\n");
		printf("\t☆                                                              ☆\n");
		printf("\t★☆☆★☆☆★☆☆★★☆☆★☆☆★☆☆★★☆☆★☆☆★☆☆★☆☆★\n");
	}
}

