#pragma once
#include<iostream>
#include<string>
using namespace std;

//身份抽象的类
class Identity
{
public:



	//操作菜单
	virtual void operMenu() = 0;

	string m_Name;
	string m_Pwd;
private:

};
