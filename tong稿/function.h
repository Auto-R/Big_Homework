#ifndef __FUNCTION_H
#define __FUNCTION_H


typedef  struct dat {
	//��������Ϊ��������ְҵ���绰���룬���䣬��һ�����
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

