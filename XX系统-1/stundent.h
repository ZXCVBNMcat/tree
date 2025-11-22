#pragma once
#include"Identity.h"
#include"time.h"
#include<fstream>
#include"globaFlie.h"
using namespace std;

class Stundent:public Identity
{
public:

	Stundent();

	Stundent(int id, string name, string pwd);

	//²Ù×÷²Ëµ¥
	virtual void operMenu();

	//¿¼ÊÔ
	void exam();

	void result();

	void ShowResult(int type);

	int m_Id;
	string m_Name;
	string m_Pwd;
private:

};