#include"include.h"

// 找到最后一个，可以用来计数
Data* fdlast(struct dat* dae) 
{
	if (dae == NULL)
	{
		return NULL;
	}
	while (dae->next)
		dae = dae->next;
	return dae;
}

//把2中的数据给1
void datacopy(struct dat* temp1, struct dat* temp2)
{
	strcpy(temp1->name, temp2->name);
	strcpy(temp1->occupation, temp2->occupation);
	temp1->tele = temp2->tele;
	strcpy(temp1->e_mail, temp2->e_mail);
}

//********************************************//
//名字：nametopo				类型：int			  //
//参数：dae是目标链表，也就是head 或者 blakchead	  //
//	   trg是被查找的名字						  //
//功能：找到该名字对应的位置						  //
//********************************************//
int nametopo(struct dat* dae, char trg[20])
{
	int i = 0;
	while (dae)
	{
		i++;
		if (!strcmp(dae->name, trg))
			return i;
		dae = dae->next;
	}
	return 0;
}

//把缓冲区的数据输给文件
void output(struct dat* dae, FILE* fp)//记得自己先打开文件
{
	if (!dae)
	{
		fclose(fp);
		return;
	}
	while (dae->next)//提前读一个
	{
		fprintf(fp, "%s	%s	%lld	%s\n", dae->name
			, dae->occupation, dae->tele, dae->e_mail);
		dae = dae->next;
	}
	fprintf(fp, "%s	%s	%lld	%s", dae->name
		, dae->occupation, dae->tele, dae->e_mail);//防止最后一行输入\n导致数据错误
	fclose(fp);
}

//把文件的内容读至缓冲区
struct dat* input(FILE* fp)//记得自己先打开文件//从文件输入
{

	Data* dae, * tem, * phead;
	dae = tem = phead = NULL;
	while (!feof(fp))
	{
		dae = (Data*)malloc(sizeof(Data));
		fscanf(fp, "%s	%s	%lld	%s", dae->name
			, dae->occupation, &dae->tele, dae->e_mail);

		if (!phead)
		{
			phead = dae;
			tem = dae;
		}
		else
		{
			tem->next = dae;
			tem = tem->next;
		}
	}
	fclose(fp);

	tem->next = NULL;

	return phead;
}