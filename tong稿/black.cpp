#include"black.h"

//输入blackhead//删除黑名单中的成员
void deletedatab(Data* dae, int position)
{
	if (position == 0)
		return;
	position -= 2;//辅助定位n-1
	Data* tem, * tem2;
	tem = tem2 = NULL;


	if (position < 0)//找到第一个并且释放，blackhead顺位后移
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
	//剩下的情况
	for (int i = 0; i < position; i++)//找到n-1
	{
		dae = dae->next;
	}
	tem2 = dae->next;
	tem = tem2;//取出n
	tem2 = tem2->next;//取出n+1
	dae->next = tem2;//接上n+1和n-1
	free(tem);//释放n，由于没有多出无意义的next，故没有赋值NULL的操作
	printf("Delete successful3bbb!\n");
}

//输入head，从联系人通过名字添加黑名单
void Addblackmembershipbyname(Data* dae, char a[20])
{
	Data* newdae, * tem, * phead;
	phead = tem = newdae = NULL;
	while (dae)
	{
		if (!strcmp(dae->name, a))//对名字
		{
			newdae = (Data*)malloc(sizeof(Data));
			newdae->next = NULL;
			datacopy(newdae, dae);//复制数据

			if (!blackhead)//存下链头
			{
				tem = newdae;
				blackhead = blacklast = newdae;
				phead = newdae;
			}
			else//更改链尾
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
		// 获得窗口句柄
		HWND hnnd = GetHWnd();
		// 使用 Windows API 修改窗口名称
		MessageBox(hnnd, _T("查无此人"), _T("提示"), MB_OK);
	}
}

//输入head，删掉对应联系人当往黑名单加入时
void deletewhenadd(Data* dae, char a[20])//以姓名为导向
{
	//输入姓名
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


//输入blackhead，通过名字把黑名单加到联系人
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
				head = last = newdae;//对付black>0,c=0的情况
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
		MessageBox(GetHWnd(), _T("查无此人"), _T("提示"), MB_OKCANCEL);
	}
}

//输入blackhead，添加联系人时删除黑名单对应的对象
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