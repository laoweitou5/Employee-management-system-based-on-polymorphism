#include"Employee.h"

//���캯��
Employee::Employee(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->DeptId = did;
}

//��ʾ������Ϣ
void Employee::ShowInfo()
{
	cout << "ְ�����Ϊ��" << this->m_Id << endl;
	cout << "ְ������Ϊ��" << this->m_Name << endl;
	cout << "���ű��Ϊ��" << this->DeptName() << endl;
	cout << "��λְ��Ϊ����ɾ�����������" << endl;
}

//��ȡ��λ����
string Employee::DeptName()
{
	return "Ա��";
}
