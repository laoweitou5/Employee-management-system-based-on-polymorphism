#pragma once
#include<iostream>
#include<string>
#include"Worker.h"
using namespace std;

class Employee :public Worker
{
public:
	//���캯��
	Employee(int id,string name,int did);
	//��ʾ������Ϣ
	void ShowInfo();
	//��ȡ��λ����
	string DeptName();
};
