#include"contact.h"

#if 0
//ʵ�ֲ��빦��,dae������Ϊhead
void insertdatac(Data* dae, int position)
{
	//�ú����ⲿ��Ҫisit����
	//��ʾ���1-size������

	position -= 2;//������λn-1
	Data* tem, * tem2;
	tem = ((Data*)malloc(sizeof(Data)));
	tem->next = NULL;

	//readsingledata(ade)
#if 1//������

	scanf("%s", tem->name);
	getchar();
	scanf("%s", tem->occupation);
	getchar();
	scanf("%d", &(tem->tele));
	getchar();
	scanf("%s", tem->e_mail);
	getchar();
#endif


	if (position < 0)//�����һ��ʱ
	{
		tem->next = dae;
		head = tem;
		size += 1;//����size
		return;
	}

	//��������
	for (int i = 0; i < position; i++)//�ҵ�n-1
	{
		dae = dae->next;
	}
	tem2 = dae->next;//ȡ��n+1
	dae->next = tem;//����n��n-1
	tem->next = tem2;//����n��n+1
	last = fdlast(head);//����β��
	size += 1;//����size
	printf("insert successful!\n");
}

//����head
#endif
//ɾ������
void deletedatac(struct dat* dae, int position)
{
	if (position == 0)
		return;
	position -= 2;//������λn-1
	Data* tem, * tem2;
	tem = tem2 = NULL;


	if (position < 0)//�ҵ���һ�������ͷţ�head˳λ����
	{
		tem = head;
		head = head->next;
		free(tem);
		tem = NULL;
		printf("Delete successful1!\n");
		return;
	}

	if (position == (size - 2))
	{
		for (int i = 0; i < position; i++)//�ҵ�n-1
			dae = dae->next;
		free(dae->next);
		dae->next = NULL;
		last = dae;
		printf("Delete successful2!\n");
		return;
	}
	//ʣ�µ����
	for (int i = 0; i < position; i++)//�ҵ�n-1
	{
		dae = dae->next;
	}
	tem2 = dae->next;
	tem = tem2;//ȡ��n
	tem2 = tem2->next;//ȡ��n+1
	dae->next = tem2;//����n+1��n-1
	free(tem);//�ͷ�n������û�ж���������next����û�и�ֵNULL�Ĳ���
	printf("Delete successful3!\n");
}
//����head

//ʵ����β��ӹ���
void adddatac(struct dat* dae)
{
	if (!size)
	{
		head = last = dae;
		last->next = NULL;
		size++;
		return;
	}
	last->next = dae;
	last = last->next;//������β
	last->next = NULL;
	size++;
}//����Ҫ��ӵĽṹ��

//��������
void searchdata(struct dat* dae, int jud)
{
	//��װ��һ��
	if (jud == 6)
	{
		char strs[20] = { 0 };
		char strt[20] = { 0 };
		InputBox(strs, 20, _T("������Ҫ���ҵ���ϵ������"));
		int ns, ssize;
		ns = ssize = 0;
		Data* shead, * slast, * tem, * tem2;
		shead = slast = tem2 = tem = NULL;
		while (dae)
		{
			strcpy(strt, dae->name);
			if (strstr(strt, strs))
			{
				tem = (Data*)malloc(sizeof(Data));
				tem->next = NULL;
				datacopy(tem, dae);
				if (!shead)
				{
					tem2 = tem;
					shead = tem2;
				}
				else
				{
					tem2->next = tem;
					tem2 = tem2->next;
				}
			}
			dae = dae->next;
		}
		slast = fdlast(shead);
		ssize = nametopo(shead, slast->name);
		ns = 1;
		int po = 0;
		if ((ssize % 10) > 0)
			po = ssize / 10 + 1;
		else
			po = ssize / 10;
		nextpage(ns,po);
		form(shead, ns, ssize);
		searchmenu( shead, ssize);
		while (shead)//���տռ�
		{
			Data* tem = shead->next;
			free(shead);
			shead = tem;
		}
	}
	if (jud == 7)
	{
		char strs[20];//source
		char strt[20];//target
		InputBox(strs, 20, _T("������Ҫ���ҵ���ϵ�˵绰"));
		int ns, ssize;
		ns = ssize = 0;
		Data* shead, * slast, * tem, * tem2;
		shead = slast = tem2 = tem = NULL;
		while (dae)
		{
			sprintf(strt, "%lld", dae->tele);
			if (strstr(strt, strs))
			{
				tem = (Data*)malloc(sizeof(Data));
				tem->next = NULL;
				datacopy(tem, dae);
				if (!shead)
				{
					tem2 = tem;
					shead = tem2;
				}
				else
				{
					tem2->next = tem;
					tem2 = tem2->next;
				}
			}
			dae = dae->next;
		}
		slast = fdlast(shead);
		ssize = nametopo(shead, slast->name);
		ns = 1;
		int po = 0;
		if ((ssize % 10) > 0)
			po = ssize / 10 + 1;
		else
			po = ssize / 10;
		nextpage(ns,po);
		form(shead, ns, ssize);
		searchmenu( shead, ssize);
		while (shead)//���տռ�
		{
			Data* tem = shead->next;
			free(shead);
			shead = tem;
		}
	}
	return;
}

//������
void queuedata(struct dat* dae)
{
	Data* tem, * tem2;
	tem = tem2 = NULL;
	tem2 = dae;
	tem = (Data*)malloc(sizeof(Data));
	for (int i = size; i > 0; i--)
	{
		dae = tem2;
		for (int j = 0; j < i - 1; j++)
		{
			if (strcmp(dae->name, ((dae->next)->name)) > 0)
			{
				datacopy(tem, dae);
				datacopy(dae, dae->next);
				datacopy(dae->next, tem);
			}
			dae = dae->next;
		}
	}
}

//�༭����
void editdata(struct dat* dae, char a[20])
{
	while (dae)
	{
		if (!(strcmp(dae->name, a)))//�޸�Ӧ�Ǿ�ȷ����
		{
			Data* tem = (Data*)malloc(sizeof(Data));
			InputBox(a, 50, _T("��������ϵ�˱�ע"), _T("�༭����"));
			strcpy_s(tem->occupation, a);
			InputBox(a, 50, _T("��������ϵ�˵绰����"), _T("�༭����"));
			tem->tele = atoll(a);
			InputBox(a, 50, _T("��������ϵ������"), _T("�༭����"));
			strcpy_s(tem->e_mail, a);
			tem->next = NULL;
			if ((tem->occupation == "\0") || (tem->tele == 0)
				|| (tem->e_mail == "\0"))
			{
				//	// ��ô��ھ��
				//	HWND hnnd = GetHWnd();
				//	// ʹ�� Windows API �޸Ĵ�������
				//	MessageBox(hnnd, _T("��������"), _T("��ʾ"), MB_OK);
				MessageBox(GetHWnd(), _T("��������"), _T("��ʾ"), MB_OK);
				free(tem);
				break;
			}
			strcpy_s(dae->occupation, tem->occupation);
			dae->tele = tem->tele;//ȷ����������ݸ��ı���
			strcpy_s(dae->e_mail, tem->e_mail);
			free(tem);
			return;
		}
		else
			dae = dae->next;
	}
}

//���ת�༭����
int convert(struct dat* next)
{
	char a[20];
	long long int b;
	InputBox(a, 50, _T("������ϵ������"));
	if (nametopo(head, a))
	{
		HWND hnnd = GetHWnd();
		int p = MessageBox(hnnd, _T("�б��Ѵ��ڸ���ϵ�ˣ��Ƿ����༭ģʽ��"), _T("��ʾ"), MB_OKCANCEL || IDOK || IDCANCEL);
		if (p == 1)
			editdata(head, a);
		else;
		return 0;
	}
	strcpy_s(next->name, a);
	InputBox(a, 50, _T("��������ϵ�˱�ע"), _T("���"));
	strcpy_s(next->occupation, a);
	InputBox(a, 50, _T("��������ϵ�˵绰����"), _T("���"));
	next->tele = atoll(a);
	InputBox(a, 50, _T("��������ϵ������"), _T("���"));
	strcpy_s(next->e_mail, a);
	return 1;
}