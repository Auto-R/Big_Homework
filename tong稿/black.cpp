#include"black.h"

//����blackhead//ɾ���������еĳ�Ա
void deletedatab(Data* dae, int position)
{
	if (position == 0)
		return;
	position -= 2;//������λn-1
	Data* tem, * tem2;
	tem = tem2 = NULL;


	if (position < 0)//�ҵ���һ�������ͷţ�blackhead˳λ����
	{
		tem = blackhead;
		blackhead = blackhead->next;
		free(tem);
		tem = NULL;
		printf("Delete successful1bbb!\n");
		return;
	}

	if (position == (bsize - 2))
	{
		for (int i = 0; i < position; i++)
			dae = dae->next;
		free(dae->next);
		dae->next = NULL;
		blacklast = dae;
		printf("Delete successful2bbb!\n");
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
	printf("Delete successful3bbb!\n");
}

//����head������ϵ��ͨ��������Ӻ�����
void Addblackmembershipbyname(Data* dae, char a[20])
{
	Data* newdae, * tem, * phead;
	phead = tem = newdae = NULL;
	while (dae)
	{
		if (!strcmp(dae->name, a))//������
		{
			newdae = (Data*)malloc(sizeof(Data));
			newdae->next = NULL;
			datacopy(newdae, dae);//��������

			if (!blackhead)//������ͷ
			{
				tem = newdae;
				blackhead = blacklast = newdae;
				phead = newdae;
			}
			else//������β
			{
				tem = fdlast(blackhead);
				tem->next = newdae;
				newdae->next = NULL;
				blacklast = newdae;
				return;
			}
		}
		dae = dae->next;
	}
	if (!phead)
	{
		// ��ô��ھ��
		HWND hnnd = GetHWnd();
		// ʹ�� Windows API �޸Ĵ�������
		MessageBox(hnnd, _T("���޴���"), _T("��ʾ"), MB_OK);
	}
}

//����head��ɾ����Ӧ��ϵ�˵�������������ʱ
void deletewhenadd(Data* dae, char a[20])//������Ϊ����
{
	//��������
	int i = 0;
	while (dae)
	{
		i++;
		if (!strcmp(dae->name, a))
		{
			deletedatac(head, i);
			break;
		}
		dae = dae->next;

	}
}


//����blackhead��ͨ�����ְѺ������ӵ���ϵ��
void Addcontactbyname(Data* dae, char a[20])
{
	Data* newdae, * tem, * phead;
	phead = tem = newdae = NULL;
	while (dae)
	{
		if (!strcmp(dae->name, a))
		{
			newdae = (Data*)malloc(sizeof(Data));
			newdae->next = NULL;

			datacopy(newdae, dae);
			if (!head)
			{
				tem = newdae;
				head = last = newdae;//�Ը�black>0,c=0�����
				phead = newdae;
			}
			else
			{
				tem = fdlast(head);
				tem->next = newdae;
				newdae->next = NULL;
				last = newdae;
				return;
			}
		}
		dae = dae->next;
	}
	if (!phead)
	{
		MessageBox(GetHWnd(), _T("���޴���"), _T("��ʾ"), MB_OKCANCEL);
	}
}

//����blackhead�������ϵ��ʱɾ����������Ӧ�Ķ���
void addwhendelete(Data* dae, char a[20])
{
	int i = 0;
	while (dae)
	{
		i++;
		if (!strcmp(dae->name, a))
		{
			deletedatab(blackhead, i);
			break;
		}
		dae = dae->next;

	}
}