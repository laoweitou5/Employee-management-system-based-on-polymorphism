#include<iostream>
#include<string>
#include<fstream>
#include"Workmanager.h"
#include"Worker.h"
#include"Employee.h"
#include"Menager.h"
#include"Boss.h"
using namespace std;

int main()
{
	//���Դ���
	/*Worker* worker01 = NULL;
	worker01 = new Menager(1, "tdsaf", 1);
	worker01->ShowInfo();*/


	//ʵ���������߶���
	Workmanager wm;

	//choice���ڽ����û���ѡ��
	int choice = 0;

	while (true)
	{
		//����չʾ�˵��ĳ�Ա����
		wm.Show_menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		//�˳�����ϵͳ
		case 0:
			wm.Exitsystem();
			break;
		//����ְ����Ϣ
		case 1:
			wm.Add_Emp();
			break;
		//��ʾְ����Ϣ
		case 2:
			wm.Show_Emp();
			break;
		//ɾ����ְְ��
		case 3:
			wm.Delete_Emp();
			break;
		//�޸�ְ����Ϣ
		case 4:
			wm.Mod_Emp();
			break;
		//����ְ����Ϣ
		case 5:
			wm.Find_Emp();
			break;
		//���ձ������
		case 6:
			wm.Sort_Emp();
			break;
		//��������ĵ�
		case 7:
			wm.Clean_File();
			break;
		default://�����Ļ
			system("cls");

		}
	}

	return 0;
}