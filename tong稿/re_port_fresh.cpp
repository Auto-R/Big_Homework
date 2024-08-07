#include"include.h"

//������״̬��ȡ
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

//������״̬չʾ
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
	outtextxy(50, 150, _T("��ϵ�˻���������:"));
	outtextxy(320, 150, cc);
	outtextxy(50, 200, _T("����������������:"));
	outtextxy(320, 200, dd);
}

//�ļ�״̬����
void filerefresher(char aa[20], char bb[20])
{
	int fnc = size;
	int fnb = bsize;
	itoa(fnc, aa, 10);
	itoa(fnb, bb, 10);
}

//�ļ�״̬չʾ
void fileputter(char aa[20], char bb[20])
{
	outtextxy(50, 50, _T("��ϵ���ļ�������:"));//��鲢���
	outtextxy(320, 50, aa);
	outtextxy(50, 100, _T("�������ļ�������:"));
	outtextxy(320, 100, bb);
}

//����������ʵʱ����
int blackrefresherformenu(int nm)
{
	int po = 0;
	if ((bsize % 10) > 0)
		po = bsize / 10 + 1;
	else
		po = bsize / 10;
	if (nm > po)
		nm = po;
	cleardevice();//��մ��ڣ�������ҳ��
	picture();
	setbkmode(TRANSPARENT);//�ñ�����ɫ���
	setfillcolor(WHITE);//��ť��ɫΪ��ɫ
	fillrectangle(610, 680, 670, 720);
	settextstyle(20, 0, _T("����"));//���ֵ���ʽ�ǿ���
	outtextxy(610, 680, _T("���˵�"));
	if (nm != 1)//�߼��жϵ�Ԫ
	{
		fillrectangle(540, 680, 600, 720);
		outtextxy(540, 680, _T("��һҳ"));
	}
	if (nm < po)
	{
		fillrectangle(680, 680, 740, 720);
		outtextxy(680, 680, _T("��һҳ"));
	}
	solidrectangle(100, 640, 370, 690);//heizeng
	solidrectangle(100, 700, 370, 750);//heishan
	outtextxy(100, 640, _T("���Ӻ�������ϵ��"));
	outtextxy(100, 700, _T("ɾ����������ϵ��"));
	form(blackhead, nm, bsize);
	return po;
}

//�ļ���ʼ״̬��ȡ�����뻺����
void FirstFilereport(void)
{
	FILE* fpc = fopen("../key.txt", "rt");
	size = Filestatecheck(fpc);//����֮����Զ��ر�
	if (size)
	{
		FILE* fpc = fopen("../key.txt", "rt");
		head = input(fpc);//input��������ر��ļ�
		last = fdlast(head);
	}
	//���Ĳ�����ϣ���������ϵ���ļ�����ʼ��

	FILE* fpb = fopen("../blackmembership.txt", "rt");
	bsize = Filestatecheck(fpb);//����֮����Զ��ر�
	if (bsize)
	{
		FILE* fpb = fopen("../blackmembership.txt", "rt");
		blackhead = input(fpb);//input��������ر��ļ�
		//readalldata(blackhead);
		blacklast = fdlast(blackhead);
	}
	//���Ĳ�����ϣ�������������ļ�����ʼ��
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
	getc(fp);//����ļ�ĩβ
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
		blackhead = phead;//����������ͷ
	return n;
}
#endif
//�ļ�״̬��ȡ
int Filestatecheck(FILE* fp)//����������
{
	if (!fp)
	{
		MessageBox(GetHWnd(), _T("�ļ���ʧ��"), _T("��ʾ"), MB_OK);
		return 0;
	}

	Data* dae ,* tem;
	dae  = tem = NULL;
	int n = 0;
	getc(fp);//����ļ�ĩβ
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



