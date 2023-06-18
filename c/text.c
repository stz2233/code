#include<stdio.h>
#include<malloc.h>
#include <string.h>
#include<stdlib.h>

typedef struct student
{
	//学号
	char id[30];
	//名字
	char name[20];
	//性别
	char gender[5];
	//班级
	char cla[20];
	//出生日期
	char date[20];
	//联系方式
	char call[11];
	//家庭住址
	char adress[50];
	//成绩
	float score[3];
	//总分
	float allscore;
	//平均分
	float mean;
	
	// 类的地址
	struct student * next;
	
} Node;
void sort(Node *head);
//初始化6个
Node * InitList() {

	FILE* pf = fopen("student_information.txt", "r");
	Node*head,*t,*s;
	Node p;
	if (pf == NULL)
	{
		printf("读取文件失败");
		return head;
	}
	head = (Node*)malloc(sizeof(Node));
	t = head;
	
	while (fscanf(pf, " %s %s %s %s %s %s %s %f %f %f\n", p.id, p.name, p.gender, p.cla, p.date, p.call, p.adress,&p.score[0],&p.score[1],&p.score[2],p.allscore,p.mean) != EOF)
	{
		s = (Node*)malloc(sizeof(Node));
		*s = p;
		// 尾插法
		t->next = s;
		t = s;
		t->next = NULL;
	}
	return head;
}
//插入
void CreatTail(Node *head) {
	Node * r, * newNode;
	r = head;
	char id[30];
	int tag = 1;
	printf("输入学生id:");
	scanf("%s", id);
	getchar();
	while(r){
		if(id==r->id){
			printf("该学生已存在.\n");
			tag = 0;
		}
		else{
			r = r->next;
		}
		if(tag==0){
			char a;
			printf("是否重新插入学生信息y/n");
			scanf("%c", &a);
			getchar();
			if (a=='y')
			{
				printf("请重新输入学生id:");
				scanf("%s", id);
				getchar();
				tag = 1;
				r = NULL;
			}
			else{
				printf("退出学生信息插入.\n");
				break;
			}
			
		}
	}
	if(r==NULL){
	newNode = (Node *)malloc(sizeof(Node));
	r = head;
	newNode->next = r->next; // 将head下一个变量的地址赋予newNode
	r->next = newNode;//head的下一个变量的地址为newNode

	strcpy(newNode->id, id);
	printf("输入学生名字：");
	scanf("%s", newNode->name);
	printf("输入学生性别：");
	scanf("%s", newNode->gender);
	printf("输入学生班级：");
	scanf("%s", newNode->cla);
	printf("输入学生出生日期：");
	scanf("%s", newNode->date);
	printf("输入学生联系方式：");
	scanf("%s", newNode->call);
	printf("输入学生家庭地址：");
	scanf("%s", newNode->adress);
	printf("输入学生高数成绩：");
	scanf("%f", &newNode->score[0]);
	printf("输入学生英语成绩：");
	scanf("%f", &newNode->score[1]);
	printf("输入学生名字C语言成绩:");
	scanf("%f", &newNode->score[2]);
	newNode->allscore = newNode->score[0] + newNode->score[1] + newNode->score[2];
	newNode->mean = newNode->allscore / 3;
	}
	getchar();
}
//注销链表
void DestoryList(Node *head) {
	Node *p = head->next;
	Node *q = p;

	FILE* pfWrite = fopen("student_information.txt", "w");
	if (pfWrite == NULL)
	{
		return;
	}

	while (p != NULL)
	{
		fprintf(pfWrite, " %s %s %s %s %s %s %s %f %f %f %f %f\n", p->id, p->name, p->gender, p->cla, p->date,p->call, p->adress,p->score[0],p->score[1],p->score[2],p->allscore,p->mean);
		p = p->next;
	}
	p = head->next;
	while (p) {
		p = p->next;
		free(q);
		q = p;
	}
	head->next = NULL;
	printf("abb");
}
//全部链表的输出
void allprint(Node *head) {
	// Node *p,*q;
	// FILE *t=NULL;
	
	sort(head);
	Node *p = head->next;

	
	//按学号排序
	printf("按学号排序\n");
	printf("学号\t名字\t性别\t班级\t出生日期\t联系方式\t家庭地址\n");
	while (p) {
		printf("%s\t", p->id);
        printf("%s\t", p->name);
        printf("%s\t", p->gender);
        printf("%s\t", p->cla);
        printf("%s\t", p->date);
        printf("%s\t\t", p->call);
        printf("%s\t", p->adress);
		printf("%.2f\t", p->score[0]);
		printf("%.2f\t", p->score[1]);
		printf("%.2f\t", p->score[2]);
		printf("%.2f\t", p->allscore);
		printf("%.2f\n", p->mean);
		p = p->next;
	}
}

//排序
void sort (Node *head){
	Node *p,*q;
	int a1, a2;
	for (p = head->next; p != NULL; p = p->next)
	{
		for (q = p; q != NULL;	q=q->next)
		{
			a1=atoi(p->id);
			a2=atoi(q->id);

			if (a1>a2)
			{
				Node t = *p;
				*p = *q;
				*q = t;

				t.next = p->next;
				p->next = q->next;
				q->next = t.next;
			}
		}
	}
}

//输出个别类
void print(Node *p){
	printf("学号\t名字\t性别\t班级\t出生日期\t联系方式\t家庭地址\n");
	printf("%s\t", p->id);
    printf("%s\t", p->name);
    printf("%s\t ", p->gender);
    printf("%s\t ", p->cla);
    printf("%s\t ", p->date);
    printf("%s\t\t ", p->call);
    printf("%s\n ", p->adress);


}
//寻找
void find(Node *head){
	Node *Id, *r;
	r = head;
	Id = r->next;
	
	int a = 0;
	int b;
	printf("按学号查询输入1;按姓名查询输入2;按联系方式查询输入3;输入其他退出查询\n");
	scanf("%d", &b);
	switch (b)
	{
		
		case 1:{
			char id[30];
			printf("输入学生id:");
			scanf("%s", id);
			getchar();
			while (1)
			{

				if(strcmp(id,Id->id)==0){
					printf("已找到输出学生信息\n");
					print(Id);break;
				}
				else if(Id->next==NULL){
					printf("查无该学生\n");
					break;
				}
				else{
					Id = Id->next;
				}
			}
			break;
		}
		case 2:{
			char name[15];
			printf("输入学生姓名:");
			scanf("%s", name);
			getchar();
			while (1)
			{

				if(strcmp(name,Id->name)==0){
					printf("已找到输出学生信息\n");
					print(Id);break;
				}
				else if(Id->next==NULL){
					printf("查无该学生\n");
					break;
				}
				else{
					Id = Id->next;
				}
			}
			break;
		}
		case 3:{
			char call[15];
			printf("输入学生电话:");
			scanf("%s", call);
			getchar();
			while (1)
			{

				if(strcmp(call,Id->call)==0){
					printf("已找到输出学生信息\n");
					print(Id);break;
				}
				else if(Id->next==NULL){
					printf("查无该学生\n");
					break;
				}
				else{
					Id = Id->next;
				}
			}
		}
			default: printf("已退出查询"),getchar();
			break;
		}
}
//修改
void revamp(Node *head){


	Node *Id, *r;
	r = head;
	Id = r->next;
	char id[30];
	char i=0;
		printf("输入学生id:");
		scanf("%s", id);
		getchar();
		while (i)
		{
			if(strcmp(id,Id->id)==0){
					printf("修改姓名按1;修改联系方式按2;修改家庭住址按3;退出修改按0:");
					
					i=getchar();
					switch (i)
					{
					case '1':{
						printf("旧的姓名为%s;\n新的姓名为:", Id->name);
						scanf("%s",Id->name);break;
					}
					case '2':{
						printf("旧的联系方式为%s;\n新的联系方式为:", Id->call);
						scanf("%s",Id->call);break;
					}
					case '3':{
						printf("旧的家庭地址为%s;\n新的家庭地址为:", Id->adress);
						scanf("%s",Id->adress);break;
					}
					default:
						break;
					}
					break;
			}
			else if(Id->next==NULL){
				printf("查无该学生\n");
				break;
			}
			Id = Id->next;
				
	}
	printf("已退出修改模式\n");
	getchar();
}
//删除
void remove(Node *head){
	Node *p, *r;
	r = head;
	p = r->next;
	char id[30];
	char i=0;
	char name1[20];
	printf("已进入删除模式\n");
	printf("按学号查询输入1;按姓名查询输入2;输入其他退出查询\n");
	i = getchar();
	switch (i)
	{
	case '1':{
		printf("请输入要删除的学生学号:");
		scanf("%s", id);
		getchar();
		while (1)
		{

				if(strcmp(id,p->id)==0){
					printf("已找到学生信息\n");
					r->next = p->next;
					free(p);
					break;
				}
				else if(p->next==NULL){
					printf("查无该学生\n");
					break;
				}
				else{
					r = p;
					p = r->next;
				}
			}
		break;
	}
	case '2':{
		printf("请输入要删除的学生姓名:");
		scanf("%s", name1);
		getchar();
		while (1)
		{

				if(name1==p->name){
					printf("已找到学生信息\n");
					r->next = p->next;
					free(p);
					break;
				}
				else if(p->next==NULL){
					printf("查无该学生\n");
					break;
				}
				else{
					r = p;
					p = r->next;
				}
			}
		break;
	}	
	default:
		break;
	}


	getchar();
}


int main()
{
    Node *head=InitList();
    //CreatTail(head);
	//char str=0;
	for (int i = 0; i < 100;i++)
	{
		char str;
		
		printf("输入1插入学生信息,\n输入2,查询学生信息\n输入3,修改学生信息\n输入4,输出全部学生资料\n输入5,删除学生信息\n输入其他,退出系统\n");
		
		scanf("%c", &str);
		getchar();
		
		if (str=='1'){
			CreatTail(head);continue;
		}
		else if (str=='2'){
			find(head);continue;
		}
		else if (str=='3'){
			revamp(head);continue;
		}
		else if (str=='4'){
			allprint(head);continue;
		}
		else if (str=='5'){
			remove(head);continue;
		}
		else if(str=='0'){
			printf("结束\n");
			break;
		}
		//printf("%c",str);
	}
	DestoryList(head);
	free(head);
	return 0;
 } 