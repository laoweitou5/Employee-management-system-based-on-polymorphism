#include"Boss.h"

//���캯��
Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->DeptId = did;
}

//��ʾ������Ϣ
void Boss::ShowInfo()
{
	cout << "ְ�����Ϊ��" << this->m_Id << endl;
	cout << "ְ������Ϊ��" << this->m_Name << endl;
	cout << "���ű��Ϊ��" << this->DeptName() << endl;
	cout << "��λְ��Ϊ������˾��������" << endl;
}

//��ȡ��λ����
string Boss::DeptName()
{
	return "�ܲ�";
}