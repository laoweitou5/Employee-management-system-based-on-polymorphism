#pragma once//��ֹͷ�ļ��ظ�����
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
	//���캯��
	Workmanager();
	
	//չʾ�˵�
	void Show_menu();

	//�˳��ӿ�
	void Exitsystem();

	//���ְ��
	void Add_Emp();

	//��������
	~Workmanager();

	//�����ļ�
	void save();

	//��ʼ��Ա��
	void Init_Emp();

	//ͳ���ļ��е�����
	int Get_EmpNum();

	//չʾְ����Ϣ
	void Show_Emp();

	//ɾ����ְְ��
	void Delete_Emp();
	
	//�ж�ְ���Ƿ����
	int IsExist(int id);

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//�������
	void Clean_File();

	//����ְ��
	void Sort_Emp();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileisEmpty;
};