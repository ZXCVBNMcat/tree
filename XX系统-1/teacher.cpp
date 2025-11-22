#include"teacher.h"
using namespace std;

Teacher::Teacher()
{

}

Teacher::Teacher(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
}
//操作菜单
void Teacher::operMenu()
{
	
	cout << "-------------------------------" << endl;
	cout << "|   欢 迎 登 录 老 师 界 面   |" << endl;
	//cout << "|                             |" << endl;
	//cout << "|    1.考 试 发 布（没做）               |" << endl;
	cout << "|                             |" << endl;
	cout << "|    1.成 绩 查 询            |" << endl;
	cout << "|                             |" << endl;
	cout << "|    0.注 销 登 录            |" << endl;
	cout << "-------------------------------" << endl;
	
}

//学生成绩查询
void Teacher::result()
{
	cout << "-------------------------------" << endl;
	cout << "|欢 迎 登 录 考 试 查 询 界 面|" << endl;
	cout << "|                             |" << endl;
	cout << "|  1.查 询 全 部 成 绩        |" << endl;
	cout << "|                             |" << endl;
	cout << "|  2.姓 名 查 询 成 绩        |" << endl;
	cout << "|                             |" << endl;
	cout << "|  3.学 号 查 询 成 绩        |" << endl;
	cout << "|                             |" << endl;
	cout << "|  0.退 出                    |" << endl;
	cout << "-------------------------------" << endl;
	int select;
	cout << "请输入您的选择" << endl;
	cin >> select;
	if (select > 0 && select < 5)
	{
		ShowResult(select);
	}
	else
	{
		cout << "退出成功" << endl;
		system("pause");
		system("cls");
		return;
	}
	return;
}

void Teacher::ShowResult(int type)
{
	ifstream ifs;
	ifs.open(RESULT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "打开失败" << endl;
		system("pause");
		system("cls");
		return;
	}

	bool t = true;
	string Fname;
	int Fid;
	int Fresult;
	if (type == 2)
	{

		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		while (ifs >> Fid && ifs >> Fname && ifs >> Fresult)
		{
			if (name == Fname)
			{
				t = false;
				cout << "学号:" << Fid << " 姓名:" << Fname << " 成绩:" << Fresult << endl;

			}
		}

		if (t)
		{
			cout << "没有找的对应的成绩" << endl;
		}
		system("pause");
		system("cls");
		return;
	}
	if (type == 1)
	{
		while (ifs >> Fid && ifs >> Fname && ifs >> Fresult)
		{
			t = false;
			cout << "学号:" << Fid << " 姓名:" << Fname << " 成绩:" << Fresult << endl;

		}
		if (t)
		{
			cout << "没有找的对应的成绩" << endl;
		}
		system("pause");
		system("cls");
		return;
	}
	if (type == 3)
	{
		int id;
		cout << "请输入学号" << endl;
		cin >> id;

		while (ifs >> Fid && ifs >> Fname && ifs >> Fresult)
		{
			if (id == Fid)
			{
				t = false;
				cout << "学号:" << Fid << " 姓名:" << Fname << " 成绩:" << Fresult << endl;

			}

		}
		if (t)
		{
			cout << "没有找的对应的成绩" << endl;
		}
		system("pause");
		system("cls");
		return;
	}/*
	if (type == 4)
	{
		while (ifs >> Fid && ifs >> Fname && ifs >> Fresult)
		{
			if (Fid == this->m_Id && Fname == this->m_Name)
			{
				t = false;
				cout << "学号:" << Fid << " 姓名:" << Fname << " 成绩:" << Fresult << endl;

			}

		}
		if (t)
		{
			cout << "没有找的对应的成绩" << endl;
		}
		system("pause");
		system("cls");
		return;
	}*/

	if (t)
	{
		cout << "没有找的对应的成绩" << endl;
	}
	system("pause");
	system("cls");
	return;
}