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
	//测试代码
	/*Worker* worker01 = NULL;
	worker01 = new Menager(1, "tdsaf", 1);
	worker01->ShowInfo();*/


	//实例化管理者对象
	Workmanager wm;

	//choice用于接收用户的选择
	int choice = 0;

	while (true)
	{
		//调用展示菜单的成员函数
		wm.Show_menu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		//退出管理系统
		case 0:
			wm.Exitsystem();
			break;
		//增加职工信息
		case 1:
			wm.Add_Emp();
			break;
		//显示职工信息
		case 2:
			wm.Show_Emp();
			break;
		//删除离职职工
		case 3:
			wm.Delete_Emp();
			break;
		//修改职工信息
		case 4:
			wm.Mod_Emp();
			break;
		//查找职工信息
		case 5:
			wm.Find_Emp();
			break;
		//按照编号排序
		case 6:
			wm.Sort_Emp();
			break;
		//清空所有文档
		case 7:
			wm.Clean_File();
			break;
		default://清空屏幕
			system("cls");

		}
	}

	return 0;
}