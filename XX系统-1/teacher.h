#pragma once
#include"Identity.h"
#include<fstream>
#include"globaFlie.h"
using namespace std;

class Teacher:public Identity
{
public:

	Teacher();

	Teacher(int id, string name, string pwd);
	//操作菜单
	virtual void operMenu();

	void result();

	void ShowResult(int type);

	//发布考试不会

	int m_Id;
	string m_Name;
	string m_Pwd;
private:

};