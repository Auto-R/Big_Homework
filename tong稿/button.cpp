#include"include.h"
void button() {
	setbkmode(TRANSPARENT);//�ñ�����ɫ���
	setfillcolor(WHITE);//��ť��ɫΪ��ɫ
	//��ť�������С
	solidrectangle(980, 80, 1250, 150);
	solidrectangle(450, 80, 850, 150);
	solidrectangle(450, 180, 850, 250);
	solidrectangle(450, 280, 850, 350);
	solidrectangle(450, 380, 850, 450);
	solidrectangle(450, 480, 850, 550);
	solidrectangle(980, 680, 1250, 750);
	solidrectangle(450, 580, 850, 650);
	solidrectangle(450, 680, 850, 750);
	//�������
	settextcolor(BLACK);//������ɫΪ��ɫ
	settextstyle(45, 0, _T("����"));//���ֵ���ʽ�ǿ���
	outtextxy(1000, 100, _T("���浽�ļ�"));
	outtextxy(590, 100, _T("��ϵ��"));
	outtextxy(550, 200, _T("������ϵ��"));
	outtextxy(550, 300, _T("ɾ����ϵ��"));
	outtextxy(550, 400, _T("�޸���ϵ��"));
	outtextxy(550, 500, _T("��ϵ������"));
	outtextxy(550, 600, _T("������ϵ��"));
	outtextxy(1050, 700, _T("������"));
	outtextxy(550, 700, _T("�˳�"));
	settextstyle(30, 0, _T("����"));//���ֵ���ʽ�ǿ���
	
}

//ͨ����һҳ���һҳ
void lastpage(int nn)//last or first page drawer
{
	cleardevice();//��մ��ڣ�������ҳ��
	picture();
	setbkmode(TRANSPARENT);//�ñ�����ɫ���
	setfillcolor(WHITE);//��ť��ɫΪ��ɫ
	fillrectangle(610, 680, 670, 720);
	fillrectangle(680, 680, 740, 720);
	settextstyle(20, 0, _T("����"));//���ֵ���ʽ�ǿ���
	outtextxy(610, 680, _T("���˵�"));
	outtextxy(680, 680, _T("��һҳ"));
	if (nn != 1)//�߼��жϵ�Ԫ
	{
		fillrectangle(540, 680, 600, 720);
		outtextxy(540, 680, _T("��һҳ"));
	}
	
}

//ͨ����һҳ
void nextpage(int nn,int po)//next page for click
{
	cleardevice();//��մ��ڣ�������ҳ��
	picture();
	setbkmode(TRANSPARENT);//�ñ�����ɫ���
	setfillcolor(WHITE);//��ť��ɫΪ��ɫ
	
	fillrectangle(610, 680, 670, 720);
	settextstyle(20, 0, _T("����"));//���ֵ���ʽ�ǿ���
	outtextxy(610, 680, _T("���˵�"));
	if (nn != 1)
	{
		fillrectangle(540, 680, 600, 720);
		outtextxy(540, 680, _T("��һҳ"));
	}
	if (nn != po)//�߼��жϵ�Ԫ
	{
		fillrectangle(680, 680, 740, 720);
		outtextxy(680, 680, _T("��һҳ"));
	}
}