#include"include.h"

 int blacksize = 0;
 int size=0;
 int bsize = 0;
 Data* head=NULL;
 Data* last=NULL;
 Data* blackhead = NULL;
 Data* blacklast = NULL;

//读取数据——测试用
void readalldata(Data* dae)
{
	int i = 0;
	i++;
	if ((dae == NULL) && (i == 1))
			printf("戳啦！");
		
	while(dae)
	{
		printf(" % 10s	%10s %11lld %10s\n", dae->name
			, dae->occupation,dae->tele, dae->e_mail);
		dae = dae->next;
	}
	

}


















