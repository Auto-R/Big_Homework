#include"include.h"

// �ҵ����һ����������������
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

//��2�е����ݸ�1
void datacopy(struct dat* temp1, struct dat* temp2)
{
	strcpy(temp1->name, temp2->name);
	strcpy(temp1->occupation, temp2->occupation);
	temp1->tele = temp2->tele;
	strcpy(temp1->e_mail, temp2->e_mail);
}

//********************************************//
//���֣�nametopo				���ͣ�int			  //
//������dae��Ŀ������Ҳ����head ���� blakchead	  //
//	   trg�Ǳ����ҵ�����						  //
//���ܣ��ҵ������ֶ�Ӧ��λ��						  //
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

//�ѻ���������������ļ�
void output(struct dat* dae, FILE* fp)//�ǵ��Լ��ȴ��ļ�
{
	if (!dae)
	{
		fclose(fp);
		return;
	}
	while (dae->next)//��ǰ��һ��
	{
		fprintf(fp, "%s	%s	%lld	%s\n", dae->name
			, dae->occupation, dae->tele, dae->e_mail);
		dae = dae->next;
	}
	fprintf(fp, "%s	%s	%lld	%s", dae->name
		, dae->occupation, dae->tele, dae->e_mail);//��ֹ���һ������\n�������ݴ���
	fclose(fp);
}

//���ļ������ݶ���������
struct dat* input(FILE* fp)//�ǵ��Լ��ȴ��ļ�//���ļ�����
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