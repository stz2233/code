#include<stdio.h>
#include<malloc.h>
typedef struct student {
	char id[30];
	char name[20];
	char gender[5];
	char class[20];
	char date[20];
	char call[11];
	char adress[50];
	struct studen* next;
}Link;
Link Head()//³õÊ¼»¯ 
{
	Link* head=(Link*)malloc(sizeof(Link));
	head->next=NULL;
	return head;
	
}
void CreatTail(int n){
	Link* date,* end;
}



int main()
{
	
	return 0;
 } 
