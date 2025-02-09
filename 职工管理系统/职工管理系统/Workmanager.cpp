#include "Workmanager.h"
#include<iostream>


//Workmanager�Ĺ��캯��
Workmanager::Workmanager()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(Filename, ios::in);

		if (!ifs.is_open())
		{
			cout << "�ļ�������" << endl;
			//��ʼ������
			this->m_EmpNum = 0;
			this->m_EmpArray = NULL;
			this->m_FileisEmpty = true;
			ifs.close();
			return;
		}
	//2.�ļ����ڣ�����Ϊ��
		char ch;
		ifs >> ch;
		if (ifs.eof())
		{
			cout << "�ļ�Ϊ��" << endl;
			//��ʼ������
			this->m_EmpNum = 0;
			this->m_EmpArray = NULL;
			this->m_FileisEmpty = true;
			ifs.close();
			return;
		}

	//3.�ļ����ڣ����ݲ�Ϊ��
		int num = this->Get_EmpNum();
		cout << "ְ����Ա����Ϊ��" << num<<endl;
		this->m_EmpNum = num;
	//���ٿռ�
		this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ��е����ݴ�ŵ�������
		this->Init_Emp();
}

//Workmanager�����ְ������ʵ��
void Workmanager::Add_Emp()
{
	cout << "��������Ҫ��ӵ�ְ��������" << endl;
	int user_choice = 0;
	cin >> user_choice;
	if (user_choice > 0)
	{
		//ʵ�����ְԱ����
		//�����¿ռ�Ĵ�С
		int newsize = this->m_EmpNum + user_choice;
		//�����¿ռ�
		Worker** newspace=new Worker* [this->m_EmpNum+user_choice];
		if (this->m_EmpArray != NULL)
		{
			//��ԭ���ݿ������¿ռ�
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}
			//�����ְ��
		for (int i = 0; i < user_choice; i++)
		{
			int id;
			string name;
			int did;
			cout << "��" << i + 1 << "����ְ����ְԱ���Ϊ��" << endl;
			cin >> id;
			cout << "��" << i + 1 << "����ְ��������Ϊ��" << endl;
			cin >> name;
			cout << "��" << i + 1 << "����ְ���Ĳ��ű��Ϊ��" << endl;
			cout << "1.��ְͨԱ" << endl;
			cout << "2.����" << endl;
			cout << "3.�ܲ�" << endl;
			cin >> did;
			Worker* worker = NULL;
			switch (did)
			{
				//���һ����ְͨԱ����Ϣ
			case 1:
				worker = new Employee(id, name, 1);
				break;
				//���һ���������Ϣ
			case 2:
				worker = new Menager(id, name, 2);
				break;
				//���һ���ܲõ���Ϣ
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				cout << "�������,���������롣" << endl;
				break;
			}
			newspace[this->m_EmpNum + i] = worker;

			
		}

		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newspace;

		//����ְԱ����
		this->m_EmpNum = newsize;

		//����ְ��Ϊ�յı�־
		this->m_FileisEmpty = false;

		//��ʾ��ӳɹ�
		cout << user_choice << "����ӳɹ�" << endl;
		this->save();
	}
	else
	{
		cout << "�����������������롣" << endl;
	}
	system("pause");
	system("cls");
}

void Workmanager::save()
{
	ofstream ofs;
	ofs.open(Filename, ios::out);//д�ļ�
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " " 
			<< this->m_EmpArray[i]->m_Name << " " 
			<< this->m_EmpArray[i]->DeptId << endl;
	}
	//�ر��ļ�
	ofs.close();
	
}

//ͳ���ļ��е�����
int Workmanager::Get_EmpNum()
{
	int id;
	string name;
	int did;
	int num = 0;
	ifstream ifs;
	ifs.open(Filename, ios::in);//���ļ�
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;
}

void Workmanager::Init_Emp()
{
	ifstream ifs;
	int id;
	string name;
	int did;
	int Index=0;
	ifs.open(Filename, ios::in);
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;
		if (did == 1)//˵����һ��Ա��
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)//˵����һ������
		{
			worker = new Menager(id, name, did);
		}
		else//˵����һ���ܲ�
		{
			worker = new Boss(id, name, did);
		}
		this->m_EmpArray[Index] = worker;
		Index++;
	}
	//�ر��ļ�
	ifs.close();
}


//չʾְ����Ϣ
void Workmanager::Show_Emp()
{
	if (this->m_FileisEmpty)
	{
		cout << "�ļ�Ϊ�ջ����ļ�������" << endl;
	}
	else
	{
		//���ö�̬��ʾ��Ա��Ϣ
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->ShowInfo();
		}
	}
	//��������
	system("pause");
	system("cls");
}

//ɾ����ְְ��
void Workmanager::Delete_Emp()
{
	if (this->m_FileisEmpty)
	{
		cout << "�ļ������ڻ�������Ϊ�գ�" << endl;
	}
	else
	{
		int id;
		//��ʾ�û�ɾ����Ҫɾ����ְ����ְ�����
		cout << "����������Ҫɾ����ְ����ְ����ţ�" << endl;
		cin >> id;
		//�ж��û������ְ������Ƿ����
		int index = this->IsExist(id);
		//�û������ְ����Ŵ���
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//���������м�¼��Ա����
			this->m_EmpNum--;
			//������ͬ�����ı��ļ���
			this->save();
			cout << "ɾ���ɹ�!" << endl;
		}
		//�û������ְ����Ų�����
		else
		{
			cout << "�������ְ����Ų����ڣ�����������" << endl;
		}
		system("pause");
		system("cls");
	}
}

//�ж�ְ���Ƿ����
int Workmanager::IsExist(int id)
{
	int index = -1;
	//id����
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
		}
	}
	return index;
}

//�޸�ְ��
void Workmanager::Mod_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (!this->m_FileisEmpty)//�ļ���Ϊ��
	{
		int id = 0;
		cout << "����������Ҫ�޸ĵ�ְ����ţ�" << endl;
		cin >> id;
		int ret = this->IsExist(id);
		//�ж��û������ְ������Ƿ�����
		if (ret != -1)//�û������ְ�������ȷ
		{
			string name = " ";
			int did = 0;
			delete this->m_EmpArray[ret];
			cout << "���������޸ĵ�ְ����ţ�" << endl;
			cin >> id;
			cout << "���������޸ĵ�������" << endl;
			cin >> name;
			cout << "���������޸ĵĲ��ű�ţ�" << endl;
			cout << "1.Ա��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ܲ�" << endl;
			cin >> did;
			Worker* worker = NULL;
			switch (did)
			{
			case 1://��Ҫ�޸ĵ��¶���ΪԱ��
				worker = new Employee(id, name, did);
				break;
			case 2://��Ҫ�޸ĵ��¶���Ϊ����
				worker = new Menager(id, name, did);
				break;
			case 3://��Ҫ�޸ĵ��¶���Ϊ�ܲ�
				worker = new Boss(id, name, did);
				break;
			default:
				break;
			}
			//�������ݵ�������
			this->m_EmpArray[ret] = worker;
			cout << "���ĳɹ���" << endl;
			//�����µ�����д���ı��ļ���
			this->save();
		}
		else//�û������ְ���������
		{
			cout << "�����ְ�������������������" << endl;
		}
	}
	else//�ļ�Ϊ��
	{
		cout << "����Ϊ�ջ����ļ�������" << endl;
	}
	system("pause");
	system("cls");
}

//����ְ��
void Workmanager::Find_Emp()
{
	//�ж��ļ��Ƿ����
	if (!this->m_FileisEmpty)//�ļ�����
	{
		int choice = 0;
		cout << "1.��ְԱ��Ų���" << endl;
		cout << "2.�����ֲ���" << endl;
		cout << "������������ҵķ�ʽ��" << endl;
		switch (choice)
		{
		case 1://��ְԱ��Ų���
		{
			int id = 0;
			cout << "��������Ҫ�ҵ�ְԱ��ţ�" << endl;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret == -1)//����ʧ��
			{
				cout << "���޴��ˣ�" << endl;
			}
			else//���ҳɹ�
			{
				cout << "���ҳɹ���ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->ShowInfo();
			}
			break;
		}
		case 2://�����ֲ���
		{
			string name;
			bool flag = false;
			cout << "����������Ҫ���ҵ�ְԱ������" << endl;
			cin >> name;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ����Ϣ���£�" << endl;
					this->m_EmpArray[i]->ShowInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}

			break;
		}
		default:
			cout << "����ʧ�ܣ����뷽ʽ��������������" << endl;
			break;
		}
	}
	else//�ļ������ڻ�����Ϊ��
	{
		cout << "�ļ������ڻ�����Ϊ��" << endl;
	}
	//��������
	system("pause");
	system("cls");
}

//����ְ��
void Workmanager::Sort_Emp()
{
	if (this->m_FileisEmpty)//�ļ������ڻ�������Ϊ��
	{
		cout << "�ļ������ڻ�������Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else//�ļ�������������
	{
		int choice = 0;
		cout << "��ѡ����������ʽ��" << endl;
		cout << "1.����ְ�������������" << endl;
		cout << "2.����ְ����Ž�������" << endl;
		cin >> choice;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int MinOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (choice == 1)//����
				{
					if (this->m_EmpArray[MinOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						MinOrMax = j;
					}
				}
				else//����
				{
					if (this->m_EmpArray[MinOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						MinOrMax = j;
					}
				}
				if (i != MinOrMax)
				{
					Worker* temp = this->m_EmpArray[i];
					this->m_EmpArray[i] = this->m_EmpArray[MinOrMax];
					this->m_EmpArray[MinOrMax] = temp;
				}
			}
		}
		cout << "����ɹ��������Ľ��Ϊ��" << endl;
		this->save();//�������ļ����浽�ı��ļ���
		this->Show_Emp();//չʾ�����ְԱ��Ϣ
	}
}

//�������
void Workmanager::Clean_File()
{
	cout << "ȷ�������?" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	int choice = 0;
	cin >> choice;
	if (choice == 1)//ȷ�����
	{
		//����ļ�
		ofstream ofs(Filename, ios::trunc);//ɾ���ļ������´���
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				//ɾ��������ÿ��ְ������
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
				//ɾ������������ָ��
				delete[] this->m_EmpArray;
				this->m_EmpArray = NULL;
				this->m_EmpNum = 0;
				this->m_FileisEmpty = true;
			}
			cout << "��ճɹ�" << endl;
		}
		system("pause");
		system("cls");
	}
	else//����
	{
		system("pause");
		system("cls");
	}
}

//Workmanager��չʾ�˵�������ʵ��
void Workmanager::Show_menu()
{
	cout << "**************************************************" << endl;
	cout << "************* ��ӭʹ��ְ������ϵͳ�� *************" << endl;
	cout << "**************    0.�˳�����ϵͳ    **************" << endl;
	cout << "**************    1.����ְ����Ϣ    **************" << endl;
	cout << "**************    2.��ʾְ����Ϣ    **************" << endl;
	cout << "**************    3.ɾ����ְְ��    **************" << endl;
	cout << "**************    4.�޸�ְ����Ϣ    **************" << endl;
	cout << "**************    5.����ְ����Ϣ    **************" << endl;
	cout << "**************    6.���ձ������    **************" << endl;
	cout << "**************    7.��������ĵ�    **************" << endl;
	cout << "**************************************************" << endl;
	cout << endl;
}

//Workmanager���˳�����ʵ��
void Workmanager::Exitsystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);//�˳�����
}

//Workmanager����������
Workmanager::~Workmanager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i]!= NULL)
			{
				delete this->m_EmpArray[i];
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
		}
	}
}