#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
typedef struct student
{

	char id[30];
	//学号
	char name[20];
	//名字
	char gender[5];
	//性别
	char cla[20];
	//班级
	char date[20];
	//出生日期
	char call[11];
	//联系方式
	char adress[50];
	//家庭住址
	struct student * next;
	//类的地址
} Node;
//初始化6个
Node * InitList() {

	Node * head = (Node * )malloc(sizeof(Node));
	Node * head1 = (Node * )malloc(sizeof(Node));
	Node * head2 = (Node * )malloc(sizeof(Node));
	Node * head3 = (Node * )malloc(sizeof(Node));
	Node * head4 = (Node * )malloc(sizeof(Node));
	// Node * head5 = (Node * )malloc(sizeof(Node));
	// Node * head6 = (Node * )malloc(sizeof(Node));
	//创建第一个链表

	
    strcpy(head1->id, "2316");
	strcpy(head1->name, "张三");
	strcpy(head1->gender, "男");
	strcpy(head1->cla, "计科6班");
	strcpy(head1->date, "2000.4.1");
	strcpy(head1->call, "10087");
	strcpy(head1->adress, "广东省");

	//head2->id = 2323;
	strcpy(head2->name, "李四");
	strcpy(head2->gender, "男");
	strcpy(head2->cla, "计科6班");
	strcpy(head2->date, "2000.5.1");
	strcpy(head2->call, "10086");
	strcpy(head2->adress, "广西省");

	//head3->id=2321;
	strcpy(head3->name, "王五");
	strcpy(head3->gender, "男");
	strcpy(head3->cla, "计科1班");
	strcpy(head3->date, "2000.3.1");
	strcpy(head3->call, "10023");
	strcpy(head3->adress, "广东省");

	//head4->id=2312;
	strcpy(head4->name, "张六");
	strcpy(head4->gender, "男");
	strcpy(head4->cla, "计科6班");
	strcpy(head4->date, "2000.4.1");
	strcpy(head4->call, "10087");
	strcpy(head4->adress, "广东省");

    head->next = head1;
    head1->next = head2;
    head2->next = head3;
    head3->next = head4;
    head4->next = NULL;

    

	
	return head;
}
void DestoryList(Node *head) {
	Node *p = head->next;
	Node *q = p;
	while (p) {
		p = p->next;
		free(q);
		q = p;
	}
	head->next = NULL;
	printf("abb");
}
int main(){
    Node *head = InitList();
    Node *p;
    p = head->next;
    
    FILE *pf = fopen("file.txt", "w");
    if (pf == NULL)
    {
        perror("error opening file");
        return 1;
    }
    fputs(p->id,pf);
    fputs(p->name, pf);
    fclose(pf);
    DestoryList(head);
    return 0;
}