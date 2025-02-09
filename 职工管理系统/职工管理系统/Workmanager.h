#pragma once//防止头文件重复包含
#include<iostream>
#include"Worker.h"
#include"Employee.h"
#include"Menager.h"
#include"Boss.h"
#include<fstream>
#define Filename "empfile.txt"
using namespace std;

class Workmanager
{
public:
	//构造函数
	Workmanager();
	
	//展示菜单
	void Show_menu();

	//退出接口
	void Exitsystem();

	//添加职工
	void Add_Emp();

	//析构函数
	~Workmanager();

	//保存文件
	void save();

	//初始化员工
	void Init_Emp();

	//统计文件中的人数
	int Get_EmpNum();

	//展示职工信息
	void Show_Emp();

	//删除离职职工
	void Delete_Emp();
	
	//判断职工是否存在
	int IsExist(int id);

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//清空数据
	void Clean_File();

	//排序职工
	void Sort_Emp();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//判断文件是否为空
	bool m_FileisEmpty;
};