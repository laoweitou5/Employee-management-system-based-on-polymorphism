#include "Workmanager.h"
#include<iostream>


//Workmanager的构造函数
Workmanager::Workmanager()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(Filename, ios::in);

		if (!ifs.is_open())
		{
			cout << "文件不存在" << endl;
			//初始化数据
			this->m_EmpNum = 0;
			this->m_EmpArray = NULL;
			this->m_FileisEmpty = true;
			ifs.close();
			return;
		}
	//2.文件存在，数据为空
		char ch;
		ifs >> ch;
		if (ifs.eof())
		{
			cout << "文件为空" << endl;
			//初始化数据
			this->m_EmpNum = 0;
			this->m_EmpArray = NULL;
			this->m_FileisEmpty = true;
			ifs.close();
			return;
		}

	//3.文件存在，数据不为空
		int num = this->Get_EmpNum();
		cout << "职工人员数量为：" << num<<endl;
		this->m_EmpNum = num;
	//开辟空间
		this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中的数据存放到数组中
		this->Init_Emp();
}

//Workmanager的添加职工函数实现
void Workmanager::Add_Emp()
{
	cout << "请输入想要添加的职工数量：" << endl;
	int user_choice = 0;
	cin >> user_choice;
	if (user_choice > 0)
	{
		//实现添加职员操作
		//计算新空间的大小
		int newsize = this->m_EmpNum + user_choice;
		//开辟新空间
		Worker** newspace=new Worker* [this->m_EmpNum+user_choice];
		if (this->m_EmpArray != NULL)
		{
			//将原数据拷贝到新空间
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}
			//添加新职工
		for (int i = 0; i < user_choice; i++)
		{
			int id;
			string name;
			int did;
			cout << "第" << i + 1 << "个新职工的职员编号为：" << endl;
			cin >> id;
			cout << "第" << i + 1 << "个新职工的姓名为：" << endl;
			cin >> name;
			cout << "第" << i + 1 << "个新职工的部门编号为：" << endl;
			cout << "1.普通职员" << endl;
			cout << "2.经理" << endl;
			cout << "3.总裁" << endl;
			cin >> did;
			Worker* worker = NULL;
			switch (did)
			{
				//添加一个普通职员的信息
			case 1:
				worker = new Employee(id, name, 1);
				break;
				//添加一个经理的信息
			case 2:
				worker = new Menager(id, name, 2);
				break;
				//添加一个总裁的信息
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				cout << "输入错误,请重新输入。" << endl;
				break;
			}
			newspace[this->m_EmpNum + i] = worker;

			
		}

		//释放原有空间
		delete[] this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newspace;

		//更新职员人数
		this->m_EmpNum = newsize;

		//更新职工为空的标志
		this->m_FileisEmpty = false;

		//提示添加成功
		cout << user_choice << "人添加成功" << endl;
		this->save();
	}
	else
	{
		cout << "输入有误，请重新输入。" << endl;
	}
	system("pause");
	system("cls");
}

void Workmanager::save()
{
	ofstream ofs;
	ofs.open(Filename, ios::out);//写文件
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " " 
			<< this->m_EmpArray[i]->m_Name << " " 
			<< this->m_EmpArray[i]->DeptId << endl;
	}
	//关闭文件
	ofs.close();
	
}

//统计文件中的人数
int Workmanager::Get_EmpNum()
{
	int id;
	string name;
	int did;
	int num = 0;
	ifstream ifs;
	ifs.open(Filename, ios::in);//读文件
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
		if (did == 1)//说明是一个员工
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)//说明是一个经理
		{
			worker = new Menager(id, name, did);
		}
		else//说明是一个总裁
		{
			worker = new Boss(id, name, did);
		}
		this->m_EmpArray[Index] = worker;
		Index++;
	}
	//关闭文件
	ifs.close();
}


//展示职工信息
void Workmanager::Show_Emp()
{
	if (this->m_FileisEmpty)
	{
		cout << "文件为空或者文件不存在" << endl;
	}
	else
	{
		//利用多态显示成员信息
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->ShowInfo();
		}
	}
	//清屏操作
	system("pause");
	system("cls");
}

//删除离职职工
void Workmanager::Delete_Emp()
{
	if (this->m_FileisEmpty)
	{
		cout << "文件不存在或者数据为空！" << endl;
	}
	else
	{
		int id;
		//提示用户删除想要删除的职工的职工编号
		cout << "请输入您想要删除的职工的职工编号：" << endl;
		cin >> id;
		//判断用户输入的职工编号是否存在
		int index = this->IsExist(id);
		//用户输入的职工编号存在
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//更新数组中记录人员数量
			this->m_EmpNum--;
			//将数据同步到文本文件中
			this->save();
			cout << "删除成功!" << endl;
		}
		//用户输入的职工编号不存在
		else
		{
			cout << "您输入的职工编号不存在，请重新输入" << endl;
		}
		system("pause");
		system("cls");
	}
}

//判断职工是否存在
int Workmanager::IsExist(int id)
{
	int index = -1;
	//id存在
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
		}
	}
	return index;
}

//修改职工
void Workmanager::Mod_Emp()
{
	//判断文件是否为空
	if (!this->m_FileisEmpty)//文件不为空
	{
		int id = 0;
		cout << "请输入您想要修改的职工编号：" << endl;
		cin >> id;
		int ret = this->IsExist(id);
		//判断用户输入的职工编号是否有误
		if (ret != -1)//用户输入的职工编号正确
		{
			string name = " ";
			int did = 0;
			delete this->m_EmpArray[ret];
			cout << "请输入您修改的职工编号：" << endl;
			cin >> id;
			cout << "请输入您修改的姓名：" << endl;
			cin >> name;
			cout << "请输入您修改的部门编号：" << endl;
			cout << "1.员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.总裁" << endl;
			cin >> did;
			Worker* worker = NULL;
			switch (did)
			{
			case 1://想要修改的新对象为员工
				worker = new Employee(id, name, did);
				break;
			case 2://想要修改的新对象为经理
				worker = new Menager(id, name, did);
				break;
			case 3://想要修改的新对象为总裁
				worker = new Boss(id, name, did);
				break;
			default:
				break;
			}
			//更新数据到数组中
			this->m_EmpArray[ret] = worker;
			cout << "更改成功了" << endl;
			//将更新的数据写入文本文件中
			this->save();
		}
		else//用户输入的职工编号有误
		{
			cout << "输入的职工编号有误，请重新输入" << endl;
		}
	}
	else//文件为空
	{
		cout << "数据为空或者文件不存在" << endl;
	}
	system("pause");
	system("cls");
}

//查找职工
void Workmanager::Find_Emp()
{
	//判断文件是否存在
	if (!this->m_FileisEmpty)//文件存在
	{
		int choice = 0;
		cout << "1.按职员编号查找" << endl;
		cout << "2.按名字查找" << endl;
		cout << "请输入您想查找的方式：" << endl;
		switch (choice)
		{
		case 1://按职员编号查找
		{
			int id = 0;
			cout << "请输入您要找的职员编号：" << endl;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret == -1)//查找失败
			{
				cout << "查无此人！" << endl;
			}
			else//查找成功
			{
				cout << "查找成功，职工信息如下：" << endl;
				this->m_EmpArray[ret]->ShowInfo();
			}
			break;
		}
		case 2://按名字查找
		{
			string name;
			bool flag = false;
			cout << "请输入您想要查找的职员姓名：" << endl;
			cin >> name;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，职工信息如下：" << endl;
					this->m_EmpArray[i]->ShowInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查找失败，查无此人" << endl;
			}

			break;
		}
		default:
			cout << "查找失败，输入方式有误，请重新输入" << endl;
			break;
		}
	}
	else//文件不存在或数据为空
	{
		cout << "文件不存在或数据为空" << endl;
	}
	//清屏操作
	system("pause");
	system("cls");
}

//排序职工
void Workmanager::Sort_Emp()
{
	if (this->m_FileisEmpty)//文件不存在或者数据为空
	{
		cout << "文件不存在或者数据为空" << endl;
		system("pause");
		system("cls");
	}
	else//文件存在且有数据
	{
		int choice = 0;
		cout << "请选择您的排序方式：" << endl;
		cout << "1.按照职工编号升序排列" << endl;
		cout << "2.按照职工编号降序排列" << endl;
		cin >> choice;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int MinOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (choice == 1)//升序
				{
					if (this->m_EmpArray[MinOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						MinOrMax = j;
					}
				}
				else//降序
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
		cout << "排序成功，排序后的结果为：" << endl;
		this->save();//排序后的文件保存到文本文件中
		this->Show_Emp();//展示排完的职员信息
	}
}

//清空数据
void Workmanager::Clean_File()
{
	cout << "确定清空吗?" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	int choice = 0;
	cin >> choice;
	if (choice == 1)//确定清空
	{
		//清空文件
		ofstream ofs(Filename, ios::trunc);//删除文件后重新创建
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				//删除堆区的每个职工对象
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
				//删除堆区的数组指针
				delete[] this->m_EmpArray;
				this->m_EmpArray = NULL;
				this->m_EmpNum = 0;
				this->m_FileisEmpty = true;
			}
			cout << "清空成功" << endl;
		}
		system("pause");
		system("cls");
	}
	else//返回
	{
		system("pause");
		system("cls");
	}
}

//Workmanager的展示菜单函数的实现
void Workmanager::Show_menu()
{
	cout << "**************************************************" << endl;
	cout << "************* 欢迎使用职工管理系统！ *************" << endl;
	cout << "**************    0.退出管理系统    **************" << endl;
	cout << "**************    1.增加职工信息    **************" << endl;
	cout << "**************    2.显示职工信息    **************" << endl;
	cout << "**************    3.删除离职职工    **************" << endl;
	cout << "**************    4.修改职工信息    **************" << endl;
	cout << "**************    5.查找职工信息    **************" << endl;
	cout << "**************    6.按照编号排序    **************" << endl;
	cout << "**************    7.清空所有文档    **************" << endl;
	cout << "**************************************************" << endl;
	cout << endl;
}

//Workmanager的退出函数实现
void Workmanager::Exitsystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//退出程序
}

//Workmanager的析构函数
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