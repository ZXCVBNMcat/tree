#include<iostream>
#include<fstream>
#include"Identity.h"
#include"globaFlie.h"
#include"manager.h"
#include"stundent.h"
#include"teacher.h"
using namespace std;
void loginIn(string fileName, int type);
void test();
void Stundentm(Identity*& stundent);
void ManagerMune(Identity*& manager);
void TeacherMune(Identity*& teacher);
void ManagerMune(Identity*& manager)
{
	
	while (true)
	{
		manager->operMenu();

		Manager* man = (Manager*)manager;
		cout << "请输入您的选择" << endl;
		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1:
			man->addPerson();
			break;
		case 2:
			system("cls");
			man->showPerson();
			break;
		case 0:
			delete(manager);
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "输入有误,请重新输入" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
void Stundentm(Identity*& stundent)
{

	while (true)
	{
		stundent->operMenu();
		Stundent* man = (Stundent*)stundent;
		cout << "请输入您的选择" << endl;
		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1:
			system("pause");
			system("cls");
			man->exam();
			break;
		case 2:
			system("pause");
			system("cls");
			man->result();
			break;
		case 0:
			delete(stundent);
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "输入有误,请重新输入" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void TeacherMune(Identity*& teacher)
{
	switch(true)
	{
		teacher->operMenu();

		Teacher* man = (Teacher*)teacher;

		int select;

		cout << "输入您的选择" << endl;

		cin >> select;

		if (select == 1)
		{
			system("cls");
			man->result();
		}
		else
		{
			cout << "退出成功" << endl;
			system("pause");
			system("cls");
			delete(teacher);
			return;
		}
	}
}

void loginIn(string fileName, int type)
{

	Identity* person = NULL;
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "打开失败" << endl;
		system("pause");
		system("cls");
		return;
	}
	string name;
	string pwd;
	int id = 0;
	if (type == 1)
	{
		cout << "请输入学号：";
		cin >> id;
	}
	if (type == 2)
	{
		cout << "请输入职工号：";
		cin >> id;
	}
	cout << "请输入用户名：";
	cin >> name;
	cout << "请输入密码：";
	cin >> pwd;
	if (type == 1)
	{
		int Fid;
		string Fname;
		string Fpwd;
		while (ifs>>Fid&&ifs >> Fname && ifs >> Fpwd)
		{
			//cout << Fname << " " << Fpwd << endl;
			if (Fid = id&&Fname == name && Fpwd == pwd)
			{
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				person = new Stundent(id,name, pwd);
				Stundentm(person);
				return;
			}
		}
	}

	if (type == 2)
	{
		int Fid;
		string Fname;
		string Fpwd;
		while (ifs >> Fid && ifs >> Fname && ifs >> Fpwd)
		{
			//cout << Fname << " " << Fpwd << endl;
			if (Fid = id && Fname == name && Fpwd == pwd)
			{
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				ManagerMune(person);
				return;
			}
		}
	}

	if (type == 3)
	{
		string Fname;
		string Fpwd;
		while (ifs >> Fname && ifs >> Fpwd)
		{
			//cout << Fname << " " << Fpwd << endl;
			if (Fname == name && Fpwd == pwd)
			{
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				ManagerMune(person);
				return;
			}
		}
	}
	cout << "账户或密码错误" << endl;
	system("pause");
	system("cls");
	delete(person);
	return;
}
//主界面
void test()
{
	while (true)
	{
		cout << "----------------------------------------" << endl;
		cout << "|                                      |" << endl;
		cout << "|     欢  迎  登  录  X  X  系  统     |" << endl;
		cout << "|                                      |" << endl;
		cout << "|    1.学 生 登 录                     |" << endl;
		cout << "|                                      |" << endl;
		cout << "|    2.老 师 登 录                     |" << endl;
		cout << "|                                      |" << endl;
		cout << "|    3.管 理 员 登 录                  |" << endl;
		cout << "|                                      |" << endl;
		cout << "|    0.退 出 系 统                     |" << endl;
		cout << "|                                      |" << endl;
		cout << "----------------------------------------" << endl;
		cout << "请输入您的选择" << endl;
		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1: 
			//学生登录
			loginIn(STUNDENT_FILE, 1);
			break;
		case 2:
			//老师登录
			loginIn(TEACHER_FILE, 2);
			break;
		case 3:
			loginIn(ADMIN_FILE, 3);
			//管理员操作
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "输入错误请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

int main()
{

	//ofstream ofs;
	//ofs.open(TEACHER_FILE, ios::out | ios::app);
	//ofs << "老王" << " " << "123" << endl;
	//ofs << "老六" <<" " << "123456" << endl;
	//ofs.close();
	test();

	return 0;
}
