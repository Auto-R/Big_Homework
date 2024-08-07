#include"include.h"
void button() {
	setbkmode(TRANSPARENT);//用背景颜色填充
	setfillcolor(WHITE);//按钮颜色为白色
	//按钮的坐标大小
	solidrectangle(980, 80, 1250, 150);
	solidrectangle(450, 80, 850, 150);
	solidrectangle(450, 180, 850, 250);
	solidrectangle(450, 280, 850, 350);
	solidrectangle(450, 380, 850, 450);
	solidrectangle(450, 480, 850, 550);
	solidrectangle(980, 680, 1250, 750);
	solidrectangle(450, 580, 850, 650);
	solidrectangle(450, 680, 850, 750);
	//输出文字
	settextcolor(BLACK);//文字颜色为黑色
	settextstyle(45, 0, _T("楷体"));//文字的形式是楷体
	outtextxy(1000, 100, _T("保存到文件"));
	outtextxy(590, 100, _T("联系人"));
	outtextxy(550, 200, _T("增加联系人"));
	outtextxy(550, 300, _T("删除联系人"));
	outtextxy(550, 400, _T("修改联系人"));
	outtextxy(550, 500, _T("联系人排序"));
	outtextxy(550, 600, _T("查找联系人"));
	outtextxy(1050, 700, _T("黑名单"));
	outtextxy(550, 700, _T("退出"));
	settextstyle(30, 0, _T("楷体"));//文字的形式是楷体
	
}

//通用上一页或第一页
void lastpage(int nn)//last or first page drawer
{
	cleardevice();//清空窗口，生成子页面
	picture();
	setbkmode(TRANSPARENT);//用背景颜色填充
	setfillcolor(WHITE);//按钮颜色为白色
	fillrectangle(610, 680, 670, 720);
	fillrectangle(680, 680, 740, 720);
	settextstyle(20, 0, _T("楷体"));//文字的形式是楷体
	outtextxy(610, 680, _T("主菜单"));
	outtextxy(680, 680, _T("下一页"));
	if (nn != 1)//逻辑判断单元
	{
		fillrectangle(540, 680, 600, 720);
		outtextxy(540, 680, _T("上一页"));
	}
	
}

//通用下一页
void nextpage(int nn,int po)//next page for click
{
	cleardevice();//清空窗口，生成子页面
	picture();
	setbkmode(TRANSPARENT);//用背景颜色填充
	setfillcolor(WHITE);//按钮颜色为白色
	
	fillrectangle(610, 680, 670, 720);
	settextstyle(20, 0, _T("楷体"));//文字的形式是楷体
	outtextxy(610, 680, _T("主菜单"));
	if (nn != 1)
	{
		fillrectangle(540, 680, 600, 720);
		outtextxy(540, 680, _T("上一页"));
	}
	if (nn != po)//逻辑判断单元
	{
		fillrectangle(680, 680, 740, 720);
		outtextxy(680, 680, _T("下一页"));
	}
}