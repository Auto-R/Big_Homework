#ifndef __FUNCTION_H
#define __FUNCTION_H


typedef  struct dat {
	//依次向下为，姓名，职业，电话号码，邮箱，下一个结点
	char name[20];
	char occupation[20];
	long long int tele;
	char e_mail[20];
	struct dat* next;
}Data;

extern Data* blackhead;
extern Data* blacklast;
extern Data* head;
extern Data* last;
extern int size;
extern int bsize;

void readalldata(struct dat* dae);
#endif

