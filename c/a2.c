#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 50
int n = 0, f = 1;

struct STU {
    char num[100];   
    char name[100];   
    char sex[10];   
    int classroom;    
    char birth[100];   
	char phonenumber[100];
	char address[100];
}stu[N];

void initialpage();
void insert();


int main()
{
    int number;
    while (f)
    {
        initialpage();
        printf("请输入功能对应编号：");
        scanf("%d", &number);
        switch (number)
        {
        case 1:insert(); break;    
        //case 2:search(); break;    
        
        default:printf("输入有误！");
        }
    }
}

void initialpage()   
{
    printf("\n");
    printf("*****************************************************\n");
    printf("*                 学生信息管理系统                  *\n");
    printf("*****************************************************\n");
    printf("********************系统功能菜单*********************\n");
    printf("-----------------------     -------------------------\n");
    printf("*****************************************************\n");
    printf("**    1、插入学生信息   *     2、查询学生信息      **\n");
    printf("*****************************************************\n");
    printf("**    3、修改学生信息   *     4、浏览学生信息      **\n");
    printf("*****************************************************\n");
    printf("**    5、删除当前信息   *     6、退出系统          **\n");
    printf("*****************************************************\n");
    printf("-----------------------     -------------------------\n");
}

void insert()//插入学生信息
{
    int m, t, i = n, j;
    printf("请输入待添加的学生人数：\n");
    scanf("%d", &m);
    if (m > 0)
    {
        do
        {
            t = 1;
            while (t!= 0)
            {
                t = 0;
                printf("请输入第%d位学生的学号：\n", i + 1);
                getchar();
                gets(stu[i].num);
                for (j = 0; j < i; j++)
                {
                    if (strcmp(stu[i].num, stu[j].num) == 0)
                    {
                        printf("该学号已存在，请重新输入！\n");
                        t = 1;
                        break;
                    }
                }
            }
            printf("请输入第%d位学生姓名：\n", i + 1);
            gets(stu[i].name);
            printf("请输入第%d位学生性别：\n", i + 1);
            gets(stu[i].sex);
            printf("请输入第%d位学生班级：\n", i + 1);
            scanf("%d", &stu[i].classroom);
            i++;
		}while (i = m + n);
        n = m+n;
        printf("添加完成！");
        system("pause");
    }
}

