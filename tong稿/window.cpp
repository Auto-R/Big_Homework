#include"include.h"
void window() 
{
	initgraph(1280, 780);
}	// ������ͼ���ڣ���СΪ 1280x780 ���� 

//�ص����˵�
void windowback()
{
	cleardevice();
	picture();
	button();
}

//�����Ӳ����
void form(struct dat* dae, int nn, int psize)
{
	setlinecolor(BLACK);//���Ʊ��
	//����
	line(100, 20, 1180, 20);
	line(100, 70, 1180, 70);
	line(100, 120, 1180, 120);
	line(100, 170, 1180, 170);
	line(100, 220, 1180, 220);
	line(100, 270, 1180, 270);
	line(100, 320, 1180, 320);
	line(100, 370, 1180, 370);
	line(100, 420, 1180, 420);
	line(100, 470, 1180, 470);
	line(100, 520, 1180, 520);
	line(100, 570, 1180, 570);
	//����
	line(100, 20, 100, 570);
	line(370, 20, 370, 570);
	line(640, 20, 640, 570);
	line(910, 20, 910, 570);
	line(1180, 20, 1180, 570);
	settextstyle(20, 0, _T("����"));//���ֵ���ʽ�ǿ���
	outtextxy(120, 40, _T("����"));
	outtextxy(390, 40, _T("�绰"));
	outtextxy(660, 40, _T("��ע"));
	outtextxy(930, 40, _T("����"));
	int n = 0;
	int i = 80;
	//�������
	while ((n < psize) && (dae != NULL))
	{
		//if (n >= (nn * 10 ))
		//	break;
		if (n >= ((nn - 1) * 10) && (n < nn * 10))
		{
			outtextxy(110, i, dae->name);
			char a[20] = { 0 };
			sprintf(a, "%lld", dae->tele);
			outtextxy(380, i, a);
			outtextxy(660, i, dae->occupation);
			outtextxy(940, i, dae->e_mail);
			i += 50;
		}
		dae = dae->next;
		n++;
	}

}

//���ͼƬ
void picture()
{
	IMAGE img;//����һ������
	cleardevice();//�������
	loadimage(&img, _T("./11.jpg"));//����ͼƬ
	putimage(0, 0, &img);//�����꣨0��0�������±���ͼƬ
}
