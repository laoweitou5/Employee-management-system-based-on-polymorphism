#include"Menager.h"

//���캯��
Menager::Menager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->DeptId = did;
}

//��ʾ������Ϣ
void Menager::ShowInfo()
{
	cout << "ְ�����Ϊ��" << this->m_Id << endl;
	cout << "ְ������Ϊ��" << this->m_Name << endl;
	cout << "���ű��Ϊ��" << this->DeptName() << endl;
	cout << "��λְ��Ϊ������ϰ�������·��������ͨԱ��" << endl;
}

//��ȡ��λ����
string Menager::DeptName()
{
	return "����";
}