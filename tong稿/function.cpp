#include"include.h"

 int blacksize = 0;
 int size=0;
 int bsize = 0;
 Data* head=NULL;
 Data* last=NULL;
 Data* blackhead = NULL;
 Data* blacklast = NULL;

//��ȡ���ݡ���������
void readalldata(Data* dae)
{
	int i = 0;
	i++;
	if ((dae == NULL) && (i == 1))
			printf("������");
		
	while(dae)
	{
		printf(" % 10s	%10s %11lld %10s\n", dae->name
			, dae->occupation,dae->tele, dae->e_mail);
		dae = dae->next;
	}
	

}


















