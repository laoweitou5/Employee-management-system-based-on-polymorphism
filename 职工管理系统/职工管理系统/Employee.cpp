#include"Employee.h"

//构造函数
Employee::Employee(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->DeptId = did;
}

//显示个人信息
void Employee::ShowInfo()
{
	cout << "职工编号为：" << this->m_Id << endl;
	cout << "职工姓名为：" << this->m_Name << endl;
	cout << "部门编号为：" << this->DeptName() << endl;
	cout << "岗位职责为：完成经理交代的任务" << endl;
}

//获取岗位名称
string Employee::DeptName()
{
	return "员工";
}
