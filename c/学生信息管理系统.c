#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node//定义一个学生基本信息结构体，别名是STU 
{
char xuehao[20];
char name[20];
char sex[10];
char banji[20];
char birthday[20];
char number[20];
char site[20];
char grade[60];
struct Node *next;
}NODE; 
NODE *List;//链表表头 
//函数的声明
void insert();
void inquiry();
void revise();
void glance();
void cut();
void sort();
void increase();
void outcome();
int readFile(NODE *l); 
int main()//主函数 
{ 
    readFile(List);//打开文件，将文件内容存储到链表中 
    int a;
	printf("\t\t\t\t***********************************************\n");
	printf("\t\t\t\t请选择你需要的功能：\n");
	printf("\t\t\t\t1.插入学生基本信息\t2.查询学生信息\n"); 
	printf("\t\t\t\t3.修改学生基本信息\t4.浏览学生信息\n");
	printf("\t\t\t\t5.删除学生基本信息\t6.排序学生信息\n");
	printf("\t\t\t\t7.增加学生成绩信息\t8.输出成绩学生信息\n");
	printf("\t\t\t\t***********************************************\n");
	scanf("%d",&a);
	switch(a)
	{
		case 1://插入学生信息 
			insert(List);
			break;
		case 2://查询学生信息
			inquiry();
			break;
		case 3://修改学生基本信息
			revise(); 
			break;
		case 4://浏览学生信息
			glance(&List);
			break;
		case 5://删除学生基本信息
			cut();
			break;
		case 6://排序学生信息
			sort();
			break;
		case 7://增加学生成绩信息
			increase();
			break;
		case 8://输出成绩学生信息
			outcome(&List);
			break;	
		default :
		    printf("输入错误\n");
		    break;				
	}
	system("cls");
	return 0;
}
int readFile(NODE *l)
{
	NODE st;
	NODE *s;
	NODE *t=l;
	FILE *fp=fopen("D:\\xuesheng.txt","r");
    if(fp==NULL)
    {
    	printf("文件打开失败\n");
    	return 0;
	}
	else 
	{
	  while(fscanf(fp,"%s %s %s %s %s %s %s %s",st.xuehao,st.name,st.sex,st.banji,st.birthday,st.number,st.site,st.grade)!=EOF)	
	  {s=(NODE*)malloc(sizeof(NODE));//尾插法 
	  *s=st;
	  t->next=s;
	  t=s;
	  t->next=NULL;
      }
	}
	return 1;
} 
void insert(NODE *l)//头插法插入学生信息 
{
	system("cls");
	NODE *st=(NODE*)malloc(sizeof(NODE));
	NODE *h=l;
	NODE *s=l;
	char num[20];
	printf("请输入你想插入的学生的学号：\n");
	scanf("%s",num);
	while(s!=NULL)
	{
		if(strcmp(num,s->xuehao)==0)
		{
			printf("该学生已经存在\n");
			break;
		}
		else
		{
			s=s->next;
		}
	}
	system("cls");
	st->next=h->next;
	h->next=st;	
	printf("请输入学生的学号：");
    scanf("%s",st->xuehao);
    printf("请输入学生的姓名：");
    scanf("%s",st->name);
    printf("请输入学生的性别：");
    scanf("%s",st->sex);
    printf("请输入学生的班级：");
    scanf("%s",st->banji);
    printf("请输入学生的出生日期：");
    scanf("%s",st->birthday);
    printf("请输入学生的联系方式：");
    scanf("%s",st->number);
    printf("请输入学生的家庭住址：");
    scanf("%s",st->site);
    printf("请输入学生的成绩(例如：数学90 语文90)：");
    scanf("%s",st->grade);
    printf("学生信息插入成功"); 	
}
void inquiry()
{
	printf("查询学生信息\n");
}
void revise()
{
	printf("修改学生信息\n");
}
void glance(NODE *l)
{
	NODE *p=l->next;
	if(p!=NULL)
	{
		while(p!=NULL)
		{
		printf("%s %s %s %s %s %s %s %s\n",p->xuehao,p->name,p->sex,p->banji,p->birthday,p->number,p->site,p->grade);	
		}
	}
	printf("浏览学生信息\n");
}
void cut()
{
	printf("删除学生信息\n");
}
void sort()
{
	printf("排序学生信息\n");
}
void increase()
{
	printf("增加学生成绩信息\n");
	
}
void outcome()
{
	printf("输出学生成绩信息\n");
}


