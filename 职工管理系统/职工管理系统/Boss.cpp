#include"Boss.h"

//构造函数
Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->DeptId = did;
}

//显示个人信息
void Boss::ShowInfo()
{
	cout << "职工编号为：" << this->m_Id << endl;
	cout << "职工姓名为：" << this->m_Name << endl;
	cout << "部门编号为：" << this->DeptName() << endl;
	cout << "岗位职责为：管理公司所有事务" << endl;
}

//获取岗位名称
string Boss::DeptName()
{
	return "总裁";
}