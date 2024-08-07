#include"contact.h"

#if 0
//实现插入功能,dae请输入为head
void insertdatac(Data* dae, int position)
{
	//该函数外部需要isit辅助
	//提示输出1-size的数字

	position -= 2;//辅助定位n-1
	Data* tem, * tem2;
	tem = ((Data*)malloc(sizeof(Data)));
	tem->next = NULL;

	//readsingledata(ade)
#if 1//测试用

	scanf("%s", tem->name);
	getchar();
	scanf("%s", tem->occupation);
	getchar();
	scanf("%d", &(tem->tele));
	getchar();
	scanf("%s", tem->e_mail);
	getchar();
#endif


	if (position < 0)//插入第一个时
	{
		tem->next = dae;
		head = tem;
		size += 1;//更新size
		return;
	}

	//正常插入
	for (int i = 0; i < position; i++)//找到n-1
	{
		dae = dae->next;
	}
	tem2 = dae->next;//取出n+1
	dae->next = tem;//接上n和n-1
	tem->next = tem2;//接上n和n+1
	last = fdlast(head);//更新尾链
	size += 1;//更新size
	printf("insert successful!\n");
}

//输入head
#endif
//删除功能
void deletedatac(struct dat* dae, int position)
{
	if (position == 0)
		return;
	position -= 2;//辅助定位n-1
	Data* tem, * tem2;
	tem = tem2 = NULL;


	if (position < 0)//找到第一个并且释放，head顺位后移
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
		for (int i = 0; i < position; i++)//找到n-1
			dae = dae->next;
		free(dae->next);
		dae->next = NULL;
		last = dae;
		printf("Delete successful2!\n");
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
	printf("Delete successful3!\n");
}
//输入head

//实现链尾添加功能
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
	last = last->next;//更新链尾
	last->next = NULL;
	size++;
}//输入要添加的结构体

//搜索功能
void searchdata(struct dat* dae, int jud)
{
	//封装在一起
	if (jud == 6)
	{
		char strs[20] = { 0 };
		char strt[20] = { 0 };
		InputBox(strs, 20, _T("输入需要查找的联系人姓名"));
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
		while (shead)//回收空间
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
		InputBox(strs, 20, _T("输入需要查找的联系人电话"));
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
		while (shead)//回收空间
		{
			Data* tem = shead->next;
			free(shead);
			shead = tem;
		}
	}
	return;
}

//排序功能
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

//编辑功能
void editdata(struct dat* dae, char a[20])
{
	while (dae)
	{
		if (!(strcmp(dae->name, a)))//修改应是精确搜索
		{
			Data* tem = (Data*)malloc(sizeof(Data));
			InputBox(a, 50, _T("请输入联系人备注"), _T("编辑界面"));
			strcpy_s(tem->occupation, a);
			InputBox(a, 50, _T("请输入联系人电话号码"), _T("编辑界面"));
			tem->tele = atoll(a);
			InputBox(a, 50, _T("请输入联系人邮箱"), _T("编辑界面"));
			strcpy_s(tem->e_mail, a);
			tem->next = NULL;
			if ((tem->occupation == "\0") || (tem->tele == 0)
				|| (tem->e_mail == "\0"))
			{
				//	// 获得窗口句柄
				//	HWND hnnd = GetHWnd();
				//	// 使用 Windows API 修改窗口名称
				//	MessageBox(hnnd, _T("数据有误"), _T("提示"), MB_OK);
				MessageBox(GetHWnd(), _T("数据有误"), _T("提示"), MB_OK);
				free(tem);
				break;
			}
			strcpy_s(dae->occupation, tem->occupation);
			dae->tele = tem->tele;//确认无误后将数据更改保存
			strcpy_s(dae->e_mail, tem->e_mail);
			free(tem);
			return;
		}
		else
			dae = dae->next;
	}
}

//添加转编辑功能
int convert(struct dat* next)
{
	char a[20];
	long long int b;
	InputBox(a, 50, _T("输入联系人姓名"));
	if (nametopo(head, a))
	{
		HWND hnnd = GetHWnd();
		int p = MessageBox(hnnd, _T("列表已存在该联系人，是否进入编辑模式？"), _T("提示"), MB_OKCANCEL || IDOK || IDCANCEL);
		if (p == 1)
			editdata(head, a);
		else;
		return 0;
	}
	strcpy_s(next->name, a);
	InputBox(a, 50, _T("请输入联系人备注"), _T("添加"));
	strcpy_s(next->occupation, a);
	InputBox(a, 50, _T("请输入联系人电话号码"), _T("添加"));
	next->tele = atoll(a);
	InputBox(a, 50, _T("请输入联系人邮箱"), _T("添加"));
	strcpy_s(next->e_mail, a);
	return 1;
}