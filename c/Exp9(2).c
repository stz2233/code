#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 50
int n =0, f =1;

void initialpage();
void insert();
void search();
void modify();
void riffle();
void cancel();
void conserve();
//void exit();

struct STU {
    char num[100];   
    char name[100];   
    char sex[10];   
    int classroom;    
    char birth[100];   
	char phonenumber[100];
	char address[100];
	float score[2];
	float All;
	float Average;
}stu[N];



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
        case 1:insert();break; 
		case 2:search();break;
		case 3:modify();break;
        case 4:riffle();break;
		case 5:cancel();break;
        case 6:conserve();break;
		case 7:exit(0); break; 
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
    printf("**    5、删除当前信息   *     6、保存学生信息      **\n");
    printf("********************7、退出系统**********************\n");
    printf("-----------------------     -------------------------\n");
}

void insert()//插入学生信息
{
    int m,t,i=0,j;
    printf("请输入待添加的学生人数：\n");
    scanf("%d", &m);
    if (m > 0)
    {
        do
        {
            t=1;
            while (t!=0)
            {
                t=0;
                printf("请输入第%d位学生的学号：\n",i+1);
                getchar();
                gets(stu[i].num);
                for (j=0;j<i;j++)
                {
                    if (strcmp(stu[i].num, stu[j].num)==0)
                    {
                        printf("该学号已存在，请重新输入！\n");
                        t=1;
                        break;
                    }
                }
            }
            printf("请输入第%d位学生的姓名：\n",i+1);
            gets(stu[i].name);
            printf("请输入第%d位学生的性别：\n",i+1);
            gets(stu[i].sex);
            printf("请输入第%d位学生的班级：\n",i+1);
            scanf("%d", &stu[i].classroom);
			getchar();
			printf("请输入第%d位学生的出生日期：\n",i+1);
			gets(stu[i].birth);
			printf("请输入第%d位学生的联系方式：\n",i+1);
			gets(stu[i].phonenumber);
			printf("请输入第%d位学生的家庭住址：\n",i+1);
			gets(stu[i].address);
			printf("请输入第%d位学生C语言成绩：\n", i + 1);
            scanf("%f", &stu[i].score[0]);
			printf("请输入第%d位学生高等数学成绩：\n", i + 1);
            scanf("%f", &stu[i].score[1]);
            
			stu[i].All=stu[i].score[0]+stu[i].score[1];    //输完数据后自动计算总成绩与平均成绩 
            stu[i].Average=(stu[i].score[0]+stu[i].score[1])/2;
            i++;
		}while (i<m+n);
        n = m+n;
        printf("添加完成！");
        system("pause");
    }
}

void search()    //查询学生信息
{
    int number,t,i;
    char s1[100];
    printf("*****************************\n");
    printf("**-------1.按学号查询------**\n");
    printf("**-------2.按姓名查询------**\n");
    printf("**-------3.退出本菜单------**\n");
    printf("*****************************\n");
    while (1)
    {
        t=0;
        printf("请输入要执行的操作序号：\n");
        scanf("%d", &number);
        switch (number)
        {
        case 1:
            printf("请输入需要查找学生的学号：\n");
            scanf("%s",s1);
            for (i=0;i<n;i++)
            {
                if (strcmp(stu[i].num, s1) == 0)
                {
                    t=1;
                    printf("学号：%s\t姓名：%s\t性别：%s\t班级：%d\t出生日期：%s\t联系方式：%s\t家庭住址：%s\tC语言成绩：%.2f\t高等数学成绩：%.2f\t总分：%.2f\t平均分：%.2f\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].classroom, stu[i].birth, stu[i].phonenumber, stu[i].address,stu[i].score[1],stu[i].score[2],stu[i].All,stu[i].Average);
				}
            }break;
        case 2:
            printf("请输入需要查找学生的姓名：\n");
            scanf("%s",s1);
            for (i=0;i<n;i++)
            {
                if (strcmp(stu[i].name, s1) == 0)
                {
                    t=1;
                    printf("学号：%s\t姓名：%s\t性别：%s\t班级：%d\t出生日期：%s\t联系方式：%s\t家庭住址：%s\tC语言成绩：%.2f\t高等数学成绩：%.2f\t总分：%.2f\t平均分：%.2f\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].classroom, stu[i].birth, stu[i].phonenumber, stu[i].address,stu[i].score[1],stu[i].score[2],stu[i].All,stu[i].Average);
				}
			}break;
        case 3:return;
        default:printf("请输入正确的数字！\n");
        }
        if (t==0)
            printf("找不到该学生，请重新输入！\n");
    }
}


void modify()    //修改学生信息
{
    int classroom,i,num;
    char number[100],name[100],sex[10],birth[100],phonenumber[100],address[100];
    char s1[100];
	float score1,score2;
    printf("请输入需要修改的学生学号：\n");
    getchar();
    gets(s1);
        for (i = 0; i < n; i++)
        {
            if (strcmp(s1, stu[i].num) == 0)
            {
                
                printf("***************************************************\n");
                printf("*----1.修改学号--------  -  -----2.修改姓名-------*\n");
                printf("*----3.修改性别--------  -  -----4.修改班级-------*\n");
                printf("*----5.修改出生日期----  -  -----6.修改联系方式---*\n");
                printf("*----7.修改家庭地址----  -  -----8.修改C语言成绩--*\n");
				printf("*----9.修改高数成绩----  -  -----10.返回主菜单----*\n");
                printf("***************************************************\n\n");
                printf("请输入菜单编号：\n");
                scanf("%d", &num);
                switch (num)
                {
                case 1:
                    printf("请输入新学号：\n");
                    getchar();
                    gets(number);
                    strcpy(stu[i].num, number);
                    break;
                case 2:
                    printf("请输入姓名：\n");
                    getchar();
                    gets(name);
                    strcpy(stu[i].name, name);
                    break;
                case 3:
                    printf("请输入性别：\n");
                    getchar();
                    gets(sex);
                    strcpy(stu[i].sex, sex);
                    break;
                case 4:
                    printf("请输入班级：\n");
                    scanf("%d", &classroom);
                    stu[i].classroom=classroom;
                    break;
                case 5:
                    printf("请输入出生日期：\n");
                    getchar();
                    gets(birth);
                    strcpy(stu[i].birth, birth);
                    break;
                case 6:
                    printf("请输入联系方式：\n");
                    getchar();
                    gets(phonenumber);
                    strcpy(stu[i].phonenumber, phonenumber);
                    break;
				case 7:
					printf("请输入家庭住址：\n");
					getchar();
                    gets(address);
                    strcpy(stu[i].address, address);
				case 8:
                    printf("请输入C语言成绩：\n");
                    scanf("%f", &score1);
                    stu[i].score[2]= score1;
                    break;
				case 9:
			    	printf("请输入高数成绩：\n");
                    scanf("%f", &score2);
                    stu[i].score[1] = score2;
                    break;
			
                case 10:return;

                default:printf("请输入1--8之间的数字！\n");
                }
                if (num > 0 && num < 9)
                    printf("修改成功！\n");
                break;
            }
        
         if (strcmp(s1, stu[i].num) != 0)
        {
            printf("未找到该学生，请重新输入学生学号：\n");
            gets(s1);
        }
		}
    system("pause");
}

void riffle()    //浏览当前信息
{
    int i;
    if (n == 0)
        printf("您好，现在暂无学生信息，请先添加学生信息！\n");
    else
    {
        printf("现在共有%d名学生\n", n);
        for (i = 0; i < n; i++)
        {
            printf("学号：%s\t姓名：%s\t性别：%s\t班级：%d\t出生日期：%s\t联系方式：%s\t家庭住址：%s\tC语言成绩：%.2f\t高等数学成绩：%.2f\t总分：%.2f\t平均分：%.2f\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].classroom, stu[i].birth, stu[i].phonenumber, stu[i].address,stu[i].score[1],stu[i].score[2],stu[i].All,stu[i].Average);
				}
    }
    system("pause");
}

void cancel()   //删除信息
{
    int t, i, j;
    char s1[100];
    printf("请输入要删除学生的学号：\n");
    getchar();
    gets(s1);
    t = 0;
    for (i = 0; i < n; i++)
    {
        if (strcmp(stu[i].num, s1) == 0)
        {
            t = 1;
            for (j = i; j < n - 1; j++)
            {
                stu[j] = stu[j + 1];
            }
        }
        if (t == 1) break;
    }
    if (t == 0) printf("未找到该学生！\n");
    if (t == 1)
    {
        printf("删除成功！\n");
        n--;
    }
    system("pause");
}



void conserve()   //保存学生信息
{
    FILE* pFile;
    char filename[100];
    int i;
    printf("请输入要保存的文件名：\n");
    scanf("%s", filename);
    if ((pFile = fopen(filename, "w")) == NULL)
    {
        printf("打开文件失败！\n");
        exit(0);
    }
    for (i = 0; i < n; i++)
    {
        if (fwrite(&stu[i], sizeof(struct STU), 1, pFile) != 1)
            printf("保存失败！\n");
    }
    printf("保存成功！\n");
    fclose(pFile);
    system("pause");
}