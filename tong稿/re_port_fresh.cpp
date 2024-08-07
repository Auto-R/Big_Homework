#include"include.h"

//缓冲区状态获取
int bufferreport(struct dat* dae)
{
	int n = 0;
	if ((dae == head) && (head != NULL))
	{
		n = nametopo(dae, last->name);
	}
	else if ((dae == blackhead) && (blackhead != NULL))
		n = nametopo(dae, blacklast->name);
	else
		return 0;
	return n;
}

//缓冲区状态展示
void bufferputter(void)
{
	int n1 = bufferreport(head);
	int n2 = bufferreport(blackhead);
	size = n1;
	bsize = n2;
	char cc[20];
	char dd[20];
	setbkmode(TRANSPARENT);
	itoa(n1, cc, 10);
	itoa(n2, dd, 10);
	outtextxy(50, 150, _T("联系人缓冲区人数:"));
	outtextxy(320, 150, cc);
	outtextxy(50, 200, _T("黑名单缓冲区人数:"));
	outtextxy(320, 200, dd);
}

//文件状态更新
void filerefresher(char aa[20], char bb[20])
{
	int fnc = size;
	int fnb = bsize;
	itoa(fnc, aa, 10);
	itoa(fnb, bb, 10);
}

//文件状态展示
void fileputter(char aa[20], char bb[20])
{
	outtextxy(50, 50, _T("联系人文件区人数:"));//检查并输出
	outtextxy(320, 50, aa);
	outtextxy(50, 100, _T("黑名单文件区人数:"));
	outtextxy(320, 100, bb);
}

//黑名单更改实时更新
int blackrefresherformenu(int nm)
{
	int po = 0;
	if ((bsize % 10) > 0)
		po = bsize / 10 + 1;
	else
		po = bsize / 10;
	if (nm > po)
		nm = po;
	cleardevice();//清空窗口，生成子页面
	picture();
	setbkmode(TRANSPARENT);//用背景颜色填充
	setfillcolor(WHITE);//按钮颜色为白色
	fillrectangle(610, 680, 670, 720);
	settextstyle(20, 0, _T("楷体"));//文字的形式是楷体
	outtextxy(610, 680, _T("主菜单"));
	if (nm != 1)//逻辑判断单元
	{
		fillrectangle(540, 680, 600, 720);
		outtextxy(540, 680, _T("上一页"));
	}
	if (nm < po)
	{
		fillrectangle(680, 680, 740, 720);
		outtextxy(680, 680, _T("下一页"));
	}
	solidrectangle(100, 640, 370, 690);//heizeng
	solidrectangle(100, 700, 370, 750);//heishan
	outtextxy(100, 640, _T("增加黑名单联系人"));
	outtextxy(100, 700, _T("删除黑名单联系人"));
	form(blackhead, nm, bsize);
	return po;
}

//文件初始状态获取并读入缓冲区
void FirstFilereport(void)
{
	FILE* fpc = fopen("../key.txt", "rt");
	size = Filestatecheck(fpc);//读完之后会自动关闭
	if (size)
	{
		FILE* fpc = fopen("../key.txt", "rt");
		head = input(fpc);//input函数将会关闭文件
		last = fdlast(head);
	}
	//上文测试完毕；；读入联系人文件并初始化

	FILE* fpb = fopen("../blackmembership.txt", "rt");
	bsize = Filestatecheck(fpb);//读完之后会自动关闭
	if (bsize)
	{
		FILE* fpb = fopen("../blackmembership.txt", "rt");
		blackhead = input(fpb);//input函数将会关闭文件
		//readalldata(blackhead);
		blacklast = fdlast(blackhead);
	}
	//上文测试完毕；；读入黑名单文件并初始化
}

#if 0

int Filestatecheckb(FILE* fp)
{
	if (!fp)
	{
		return 0;
	}

	Data* dae, * phead, * tem;
	dae = phead = tem = NULL;
	int n = 0;
	getc(fp);//检测文件末尾
	if (feof(fp))
		return 0;//	
	rewind(fp);
	while (!feof(fp))
	{
		dae = (Data*)malloc(sizeof(Data));
		fscanf(fp, "%s	%s	%lld	%s", dae->name
			, dae->occupation, &dae->tele, dae->e_mail);
		if (!n)
		{
			phead = dae;
		}
		tem = dae;
		tem = tem->next;
		free(dae);
		n++;

	}
	fclose(fp);
	if (n != 0)
		blackhead = phead;//有数据留链头
	return n;
}
#endif
//文件状态获取
int Filestatecheck(FILE* fp)//拿来数数的
{
	if (!fp)
	{
		MessageBox(GetHWnd(), _T("文件打开失败"), _T("提示"), MB_OK);
		return 0;
	}

	Data* dae ,* tem;
	dae  = tem = NULL;
	int n = 0;
	getc(fp);//检测文件末尾
	if (feof(fp))
		return 0;//	
	rewind(fp);
	while (!feof(fp))
	{
		dae = (Data*)malloc(sizeof(Data));
		fscanf(fp, "%s	%s	%lld	%s", dae->name
			, dae->occupation, &dae->tele, dae->e_mail);
		tem = dae;
		tem = tem->next;
		free(dae);
		n++;

	}
	fclose(fp);
	return n;
}



