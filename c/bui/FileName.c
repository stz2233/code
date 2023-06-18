#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int i = 0;
int main();
void print1();
print2(int i);
project1(int i);
void fanhui();
void choosesecond1();
void choosesecond2();
void choosesecond3();
void chance1();
void chance11(int pppp);
void chance111(char xiugaima, int pppp);
void delete1();
struct class
{
	int numbering;
	char incomepay[100];
	char admin[100];
	char reason[100];
	int much;
	int people;
	int yuer;
	char beizhu[100];
	char time[100];
}num[100];
int main()
{
	int choosefirst, choosesecond,p = 0;
	printf("      欢迎来到班费收支管理系统      \n");
	printf("--------------操作选项--------------\n");
	printf("1.录入班费信息\n");
	printf("2.浏览所有班费信息\n");
	printf("3.查询班费信息\n");
	printf("4.修改班费信息\n");
	printf("5.删除班费信息\n");
	printf("6.退出系统\n");
	printf("------------------------------------\n");
	printf("请按数字键选择要执行的操作：");
	(void)scanf("%d", &choosefirst);
	if (choosefirst == 1)
	{
		project1(i);
		i++;
		fanhui();
	};
	if (choosefirst == 2)
	{
		system("cls");
		print1();
		for (p; p <i ; p++)
		{
			print2(p);
		};
		fanhui();
	};
	if (choosefirst == 3)
	{
		system("cls");
		printf("--------------操作选项--------------\n");
		printf("1.按照班费编码进行查询\n");
		printf("2.按照班费时间范围进行查询\n");
		printf("3.按照经办人进行查询\n");
		printf("------------------------------------\n");
		printf("请按数字键选择要执行的操作：");
		(void)scanf("%d", &choosesecond);
		if (choosesecond == 1)
		{
			choosesecond1();
			fanhui();
		};
		if (choosesecond == 2)
		{
			choosesecond2();
			fanhui();
		};
		if (choosesecond == 3)
		{
			choosesecond3();
			fanhui();
		};
	};
	if (choosefirst == 4)
	{
		system("cls");
		printf("--------------操作选项--------------\n");
		printf("输入需要修改的班费编码：");
		chance1();
	}
	if (choosefirst == 5)
	{
		system("cls");
		printf("--------------操作选项--------------\n");
		printf("输入需要删除的班费编码：");
		delete1();
	}
	if (choosefirst == 6)
	{
		return 0;
	}
	return 0;
};
void print1()
{
	printf("------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("班费编码	收入还是支出	  经办人          原因         金额（每位同学）      人数       余额（自动生成）    备注      时间\n");

};//打印输出班级编码等
print2(int i)
{
	printf("%8d%20s%12s%15s%18d%15d%12d%20s%12s\n", num[i].numbering, num[i].incomepay, num[i].admin, num[i].reason, num[i].much, num[i].people, num[i].yuer, num[i].beizhu, num[i].time);
};
project1(int i)
{
	system("cls");
	printf("班费收支编号：");
	(void)scanf("%d", &num[i].numbering);
	printf("收入还是输出：");
	(void)scanf("%s", &num[i].incomepay);
	printf("经办人：");
	(void)scanf("%s", &num[i].admin);
	printf("原因：");
	(void)scanf("%s", &num[i].reason);
	printf("金额(每位同学)：");
	(void)scanf("%d", &num[i].much);
	printf("人数：");
	(void)scanf("%d", &num[i].people);
	num[i].yuer = (num[i].much) * (num[i].people);
	printf("余额(自动生成)：%d\n", num[i].yuer);
	printf("备注：");
	(void)scanf("%s", &num[i].beizhu);
	printf("时间:");
	(void)scanf("%s", &num[i].time);
	print1();
	print2(i);
};
void fanhui()
{
	int yeah;
	printf("------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("是否返回菜单？(是则输入1，不是则输入2):");
	(void)scanf("%d", &yeah);
	if (yeah == 1)
	{
		system("cls");
		main();
	};
};
void choosesecond1()
{
	int pp = 0, flag = 0, banfeiID;
	system("cls");
	printf("--------------操作选项--------------\n");
	printf("输入需要查询的班费编码：\n");
	(void)scanf("%d", &banfeiID);
	for (pp; pp < i; pp++)
	{
		if (banfeiID == num[pp].numbering)
		{
			flag = 1;
			print1();
			print2(pp);
		}
		break;
	};
	if (flag == 0)
	{
		printf("------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("您所要查找的信息不存在。");
	};
};
void choosesecond2()
{
	char time1, time2;
	system("cls");
	printf("--------------操作选项--------------\n");
	printf("输入需要查询的开始时间：\n");
	(void)scanf("%s", &time1);
	printf("输入需要查询的结束时间：\n");
	(void)scanf("%s", &time2);

};
void choosesecond3()
{
	int ppp=0,flag=0,p1=0;
	char admin1[100];
	system("cls");
	printf("--------------操作选项--------------\n");
	printf("输入需要查询的经办人名称：\n");
	(void)scanf("%s", admin1);
	for (ppp; ppp < i; ppp++)
	{

		if (strcmp(admin1, num[ppp].admin) == 0)
		{
			if (p1 ==0)
			{
				print1();
				p1++;
			};
			flag = 1;
			print2(ppp);
		}
	};
	if (flag == 0)
	{
		printf("------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("您所要查找的信息不存在。\n");
	};
};
void chance1()
{
	int a,pppp = 0;
	(void)scanf("%d", &a);
	for (pppp; pppp < i; pppp++)
	{
		if (a == num[pppp].numbering)
		{
			print1(); 
			print2(pppp);
			chance11(pppp);
		}
	};
		
};
void chance11(int pppp)
{
	int c;
	char xiugaima;
	printf("------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("---------请选择要修改的项目---------\n");
	printf("--------------操作选项--------------\n");
	printf("1.班费编码\n");
	printf("2.收入还是支出\n");
	printf("3.经办人\n");
	printf("4.原因\n");
	printf("5.金额\n");
	printf("6.人数\n");
	printf("7.备注\n");
	printf("8.时间\n");
	printf("------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("输入选择:");
	(void)scanf("%d", &c);
	switch (c)
	{
	case 1:
		printf("--------------操作选项--------------\n");
		printf("请输入新的班费编码：");
		(void)scanf("%d", &num[pppp].numbering);
		printf("是否修改其他字段(Y/N):");
		(void)scanf("%c", &xiugaima);
		chance111(xiugaima, pppp);
		break;
	case 2:
		printf("--------------操作选项--------------\n");
		printf("请输入是收入还是支出：");
		(void)scanf("%s", &num[pppp].incomepay);
		printf("是否修改其他字段(Y/N):");
		(void)scanf("%c", &xiugaima);
		chance111(xiugaima, pppp);
		break;
	case 3:
		printf("--------------操作选项--------------\n");
		printf("请输入新的经办人：");
		(void)scanf("%s", &num[pppp].admin);
		printf("是否修改其他字段(Y/N):");
		(void)scanf("%c", &xiugaima);
		chance111(xiugaima, pppp);
		break;
	case 4:
		printf("--------------操作选项--------------\n");
		printf("请输入新的原因：");
		(void)scanf("%s", &num[pppp].reason);
		printf("是否修改其他字段(Y/N):");
		(void)scanf("%c", &xiugaima);
		chance111(xiugaima, pppp);
		break;
	case 5:
		printf("--------------操作选项--------------\n");
		printf("请输入新的金额：");
		(void)scanf("%d", &num[pppp].much);
		printf("是否修改其他字段(Y/N):");
		(void)scanf("%c", &xiugaima);
		chance111(xiugaima, pppp);
		break;
	case 6:
		printf("--------------操作选项--------------\n");
		printf("请输入新的人数：");
		(void)scanf("%d", &num[pppp].people);
		printf("是否修改其他字段(Y/N):");
		(void)scanf("%c", &xiugaima);
		chance111(xiugaima, pppp);
		break;
	case 7:
		printf("--------------操作选项--------------\n");
		printf("请输入新的备注：");
		(void)scanf("%s", &num[pppp].beizhu);
		printf("是否修改其他字段(Y/N):");
		(void)scanf("%c", &xiugaima);
		chance111(xiugaima, pppp);
		break;
	case 8:
		printf("--------------操作选项--------------\n");
		printf("请输入新的时间：");
		(void)scanf("%s", &num[pppp].time);
		printf("是否修改其他字段(Y/N):");
		(void)scanf("%c", &xiugaima);
		chance111(xiugaima, pppp);
		break;
	};
};
void chance111(char xiugaima, int pppp)
{
	if (xiugaima == 'Y')
	{
		chance11(pppp);
	}
	else if (xiugaima == 'N')
	{
		print1();
		print2(pppp);
		fanhui();
	};
}
void delete1()
{
	int bianma, p2 = 0, pp2=0,q;
	char del;
	(void)scanf("%d", &bianma);
	for (p2; p2 < i; p2++)
	{
		if (bianma == num[p2].numbering)
		{
			printf("------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("查询到以下信息:\n");
			print2(p2);
			printf("是否删除该信息(Y/N):");
			(void)scanf("%c",&del);
			if (del == 'Y')
			{
				for(q=p2;q<i-1;q++)
				{
					num[q] = num[q + 1];
				}
				p2--;
				i--;
				printf("---------------------------------");
				printf("删除成功！");
			}
			else if (del == 'N')
			{
				fanhui();
			}
		}
	};


}



