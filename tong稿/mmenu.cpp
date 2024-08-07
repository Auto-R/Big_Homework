#include"include.h"


void contactmenu() //子菜单
{
	int nn = 1;
	int po = 0;
	if ((size % 10) > 0)
		po = size / 10 + 1;
	else 
		po = size / 10;
	while (1)
	{
	if (MouseHit())
	{
	MOUSEMSG msg = GetMouseMsg();
	switch (msg.uMsg)
	{
	case WM_LBUTTONDOWN:
	{
		if (nn>1)
		{
			if ((msg.x > 540 && msg.x < 600) && (msg.y > 680 && msg.y < 720))//上一页
			{
				nn--;
				lastpage(nn);
				form(head,nn, size);
			}
		}
		if (nn<po)
		{
			if ((msg.x > 680 && msg.x < 740) && (msg.y > 680 && msg.y < 720))//下一页
			{
				nn++;
				nextpage(nn, po);
				form(head, nn,size);
			}
		}
		if ((msg.x > 610 && msg.x < 670) && (msg.y > 680 && msg.y < 720))//回到主菜单
		{
			nn = 1;
			windowback();
			return;
		}
	}
	}
	}
	}
}

void menu()//这个是主菜单界面
{
	window();//窗口
	picture();//背景图片
	button();//按钮
	FirstFilereport();//初始化size和bsize
	char aa[20];
	char bb[20];
	filerefresher(aa, bb);
	fileputter(aa, bb);
	char a[20];
	while (1)//button
	{
	if (MouseHit())
	{
	MOUSEMSG msg = GetMouseMsg();
	switch (msg.uMsg)
	{
	case WM_LBUTTONDOWN:
	{
		//
		//click click click
		//
		if ((msg.x > 450 && msg.x < 850 && msg.y>80 && msg.y < 150))//
		{
			int nn = 1;
			int po = 0;
			if ((size % 10) > 0)
				po = size / 10 + 1;
			else
				po = size / 10;
			nextpage(nn,po);//last page 用来绘制初始子菜单
			form(head,nn,size);
			contactmenu();//子菜单逻辑选项由此进，上面的部分用于绘制子菜单界面
		}
		//
		//add add add
		//
		if (msg.x > 450 && msg.x < 850 && msg.y>180 && msg.y < 250)//尾部增加联系人
		{
			Data* tem;
			tem = (Data*)malloc(sizeof(Data));
			if (!convert(tem))//重名
			{
				continue;
			}
			if ((tem->name == "\0") || (tem->occupation == "\0")
				|| (tem->tele == 0) || (tem->e_mail == "\0"))
			{
				MessageBox(GetHWnd(), _T("数据有误"), _T("提示"), MB_OK);
				continue;
			}
			adddatac(tem);
			MessageBox(GetHWnd(), _T("添加成功"), _T("提示"), MB_OK);
		}
		//
		//delete delete delete
		//
		if (msg.x > 450 && msg.x < 850 && msg.y>280 && msg.y < 350)
		{
			InputBox(a, 20, _T("输入需要删除的联系人姓名"));
			int position = nametopo(head, a);
			if (position == 0)//名字输错保护机制
			{
				MessageBox(GetHWnd(), _T("查无此人"), _T("提示"), MB_OK);
				continue;
			}
			deletedatac(head, position);
			MessageBox(GetHWnd(), _T("删除成功"), _T("提示"), MB_OK);
			//readalldata(head);
		}
		//
		//edit edit edit
		//
		if (msg.x > 450 && msg.x < 850 && msg.y>380 && msg.y < 450)
		{
			InputBox(a, 20, _T("输入需要修改的联系人姓名"));
			int position = nametopo(head, a);
			if (position == 0)//名字输错保护机制
			{
				MessageBox(GetHWnd(), _T("查无此人"), _T("提示"), MB_OK);
				continue;
			}
			editdata(head,a);
		}
		//
		//排序
		//
		if (msg.x > 450 && msg.x < 850 && msg.y>480 && msg.y < 550)
		{
			queuedata(head);
			MessageBox(GetHWnd(), _T("排序成功"), _T("提示"), MB_OK);
		}
		//
		//黑名单界面
		//
		if (msg.x > 980 && msg.x < 1250 && msg.y>680 && msg.y < 750)
		{
			int nm = 1;
			int nn = 1;
			int po = 0;
			if ((size % 10) > 0)
				po = size / 10 + 1;
			else
				po = size / 10;
			nextpage(nm,po);
			solidrectangle(100, 640, 370, 690);//heizeng//这2个是黑名单特有的按钮
			solidrectangle(100, 700, 370, 750);//heishan
			outtextxy(100, 640, _T("增加黑名单联系人"));
			outtextxy(100, 700, _T("删除黑名单联系人"));
			form(blackhead, nm,bsize);
			blackmenu();
		}
		//
		//save save save
		//
		if (msg.x > 1000 && msg.x < 1200 && msg.y>80 && msg.y < 150)
		{
			FILE* fpc = fopen("C:\\Users\\kir\\Desktop\\key.txt", "wt");
			output(head,fpc);
			FILE* fpb = fopen("C:\\Users\\kir\\Desktop\\blackmembership.txt", "wt");
			output(blackhead, fpb);
			MessageBox(GetHWnd(), _T("保存成功"), _T("提示"), MB_OK);
			filerefresher(aa, bb);
		}

		///
		///search search search
		/// 
		if (msg.x > 450 && msg.x < 850 && msg.y>580 && msg.y < 650)
		{
			if (size == 0)
			{
				MessageBox(GetHWnd(), _T("?????没有查找到可用对象?????"), _T("提示"), MB_OK);
				continue;
			}
			char temp[20];
			int jud = MessageBox(GetHWnd(), _T("是否用姓名搜索？选否则进入电话搜索"), _T("提示"), MB_YESNO);
			searchdata/*mode*/(head, jud);
		}
		//
		//out
		//
		if (msg.x > 450 && msg.x < 850 && msg.y>680 && msg.y < 750)
		{
			if (MessageBox(GetHWnd(), _T("你确定退出吗？"), _T("提示"), MB_OKCANCEL) == 1)
				exit(0);
		}	
	//
	//投放缓冲区数据区
	//
		windowback();
		bufferputter();
		fileputter(aa, bb);
		//投放缓冲区数据区
	}
	}
	}
	}
}

void blackmenu()
{
	int nm = 1;
	char a[20];
	int po = 0;
	if ((bsize % 10) > 0)
		po = bsize / 10 + 1;
	else
		po = bsize / 10;
	while (1)
	{
	if (MouseHit())
	{
	MOUSEMSG msg = GetMouseMsg();
	switch (msg.uMsg)
	{
	case WM_LBUTTONDOWN:
	{
		if (nm > 1)
		{
			if ((msg.x > 540 && msg.x < 600) && (msg.y > 680 && msg.y < 720))//上一页
			{
				nm--;
				lastpage(nm);
				solidrectangle(100, 640, 370, 690);//heizeng
				solidrectangle(100, 700, 370, 750);//heishan
				outtextxy(100, 640, _T("增加黑名单联系人"));
				outtextxy(100, 700, _T("删除黑名单联系人"));
				form(blackhead, nm, bsize);
			}
		}
		if (nm < po)
		{
			if ((msg.x > 680 && msg.x < 740) && (msg.y > 680 && msg.y < 720))//下一页
			{
				nm++;
				nextpage(nm, po);
				solidrectangle(100, 640, 370, 690);//heizeng
				solidrectangle(100, 700, 370, 750);//heishan
				outtextxy(100, 640, _T("增加黑名单联系人"));
				outtextxy(100, 700, _T("删除黑名单联系人"));
				form(blackhead, nm, bsize);
			}
		}
		if (msg.x > 100 && msg.x < 370 && msg.y>640 && msg.y < 690)
		{
			char z[20];
			InputBox(z, 50, _T("请输入加入黑名单联系人姓名"));
			int position = nametopo(head, z);
			if (position == 0)								//名字输错保护机制
			{
				MessageBox(GetHWnd(), _T("查无此人"), _T("提示"), MB_OK);
				continue;
			}
			Addblackmembershipbyname(head, z);
			deletewhenadd(head, z);
			if (!strcmp(blacklast->name, z))				//末尾检测
			{
				MessageBox(GetHWnd(), _T("加入成功"), _T("提示"), MB_OK);
				bsize += 1;
				size -= 1;
				po = blackrefresherformenu(nm);
			}
			else
			{
				MessageBox(GetHWnd(), _T("加入失败"), _T("提示"), MB_OK);
			}
		}
		if (msg.x > 100 && msg.x < 370 && msg.y>700 && msg.y < 750)
		{
			char z[20];
			InputBox(z, 50, _T("请输入删除黑名单联系人姓名"));
			int position = nametopo(blackhead, z);
			if (position == 0)//名字输错保护机制
			{
				MessageBox(GetHWnd(), _T("查无此人"), _T("提示"), MB_OK);
				continue;
			}
			Addcontactbyname(blackhead, z);
			addwhendelete(blackhead, z);
			if (!strcmp(last->name, z))				//末尾检测
			{
				MessageBox(GetHWnd(), _T("删除成功"), _T("提示"), MB_OK);
				bsize -= 1;
				size += 1;
				po = blackrefresherformenu(nm);
			}
			else
			{
				MessageBox(GetHWnd(), _T("删除失败"), _T("提示"), MB_OK);
			}
		}
		if ((msg.x > 610 && msg.x < 670) && (msg.y > 680 && msg.y < 720))
		{
			nm = 1;
			windowback();
			return;
		}

	}
	}
	}
	}
}

void searchmenu(struct dat* shead, int ssize)
{
	int ns = 1;
	char a[20];
	int po = 0;
	if ((ssize % 10) > 0)
		po = ssize / 10 + 1;
	else
		po = ssize / 10;
	printf("this is %d", po);
	while (1)
	{
	if (MouseHit())
	{
	MOUSEMSG msg = GetMouseMsg();
	switch (msg.uMsg)
	{
	case WM_LBUTTONDOWN:
	{
		if (ns > 1)
		{
			if ((msg.x > 540 && msg.x < 600) && (msg.y > 680 && msg.y < 720))//上一页
			{
				ns--;
				lastpage(ns);
				form(shead, ns, ssize);
			}
		}
		if (ns < po)
		{
			if ((msg.x > 680 && msg.x < 740) && (msg.y > 680 && msg.y < 720))//下一页
			{
				ns++;
				nextpage(ns, po);
				form(shead, ns, ssize);
			}
		}

		if ((msg.x > 610 && msg.x < 670) && (msg.y > 680 && msg.y < 720))
		{
			ns = 1;
			windowback();
			return;
		}
	}
	}
	}
	}
}