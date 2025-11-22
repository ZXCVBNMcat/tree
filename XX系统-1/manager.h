#pragma once
#include"globaFlie.h"
#include"Identity.h"
#include"stundent.h"
#include"teacher.h"
#include<vector>
#include<fstream>
class Manager:public Identity
{
public:

	Manager();

	Manager(string name, string pwd);

	//操作菜单
	virtual void operMenu();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	void showpersonMenu();

	void showPerson(int type);

	//初始化
	void initVector();

	vector<Stundent> Vstu;
	vector<Teacher> Vtea;
	string m_Name;
	string m_Pwd;
private:

};