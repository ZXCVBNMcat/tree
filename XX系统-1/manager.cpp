#include"manager.h"
using namespace std;

void printfManager();

Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initVector();
}
//操作菜单
void Manager::operMenu()
{
	cout << "-------------------------------" << endl;
	cout << "|  欢 迎 登 录 管 理 员 界 面 |" << endl;
	cout << "|                             |" << endl;
	cout << "|    1.添 加 账 号            |" << endl;
	cout << "|                             |" << endl;
	cout << "|    2.查 看 账 号            |" << endl;
	cout << "|                             |" << endl;
	cout << "|    0.注 销 登 录            |" << endl;
	cout << "-------------------------------" << endl;
}


//添加账号
void Manager::addPerson()
{
	cout << "  请输入你添加账号的类型：" << endl;
	cout << "1.学生" << endl;
	cout << "2.老师" << endl;

	string fileName;
	string tip;
	ofstream ofs;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		fileName = STUNDENT_FILE;
		tip = "学号";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "职工编号";
	}


	int id;
	string name;
	string pwd;
	cout << "请输入" << tip << endl;
	cin >> id;
	cout << "请输入姓名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (ifs.is_open())
	{
		int Fid;
		string Fname;
		while (ifs >> Fid && ifs >> Fname)//要用vector的，但懒得改了 
		{
			if (Fid == id || Fname == name)
			{
				cout << tip << "或姓名重复" << endl;
				system("pause");
				system("cls");
				ifs.close();
				return;
			}
		}
	}
	ifs.close();

	ofs.open(fileName, ios::out | ios::app);
	ofs << id << " " << name << " " << pwd << endl;
	cout << "添加成功" << endl;
	this->initVector();
	ofs.close();
	system("pause");
	system("cls");
	return;
}

//查看账号
void Manager::showPerson()
{
	showpersonMenu();
	cout << "请输入要查看的类型" << endl;
	int select = 0;
	cin >> select;
	switch (select)
	{
	case 1:
		system("pause");
		system("cls");
		showPerson(1);
		break;
	case 2:
		system("pause");
		system("cls");
		showPerson(2);
		break;
	case 3:
		system("pause");
		system("cls");
		showPerson(3);
		break;
	case 4:
		system("pause");
		system("cls");
		showPerson(4);
		break;
	case 0:
		cout << "退出成功" << endl;
		system("pause");
		system("cls");
		return;
	default:
		cout << "输入有误" << endl;
		system("pause");
		system("cls");
		return;
	}
	
}

void printfManager()
{
	ifstream ifs;
	ifs.open(ADMIN_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "打开失败" << endl;
		system("pause");
		system("cls");
		ifs.close();
		return;
	}
	string name;
	string pwd;
	while (ifs >> name && ifs >> pwd)
	{
		cout << "管理员  |" << "姓名:" << name << " 密码" << pwd << endl;
	}
	ifs.close();
	return;
}

void Manager::showPerson(int type)
{
	if (type == 1)
	{
		for (vector<Stundent>::iterator it = Vstu.begin(); it < Vstu.end(); it++)
		{
			cout << "学生    |" << "学号:" << (*it).m_Id << " 姓名:" << (*it).m_Name << " 密码:" << (*it).m_Pwd << endl;
		}
	}
	if (type == 2)
	{
		for (vector<Stundent>::iterator it = Vstu.begin(); it < Vstu.end(); it++)
		{
			cout << "老师    |" << "职工编号:" << (*it).m_Id << " 姓名:" << (*it).m_Name << " 密码:" << (*it).m_Pwd << endl;

		}
	}
	if (type == 3)
	{
		printfManager();
		system("pause");
		system("cls");
		return;
	}
	if (type == 4)
	{
		printfManager();
		//cout << "老师    |" << endl;
		for (vector<Teacher>::iterator it = Vtea.begin(); it < Vtea.end(); it++)
		{
			cout << "老师    |" << "职工编号:" << (*it).m_Id << " 姓名:" << (*it).m_Name << " 密码:" << (*it).m_Pwd << endl;
		}
		//cout << "学生    |" << endl;
		for (vector<Stundent>::iterator it = Vstu.begin(); it < Vstu.end(); it++)
		{
			cout << "学生    |" << "学号:" << (*it).m_Id << " 姓名:" << (*it).m_Name << " 密码:" << (*it).m_Pwd << endl;
		}
	}
	system("pause");
	system("cls");
	return;
}
//3 admin 123
void Manager::showpersonMenu()
{
	cout << "-------------------------------" << endl;
	cout << "|   选 择 要 查 看 的 类 型   |" << endl;
	cout << "|                             |" << endl;
	cout << "|    1.学 生                  |" << endl;
	cout << "|                             |" << endl;
	cout << "|    2.老 师                  |" << endl;
	cout << "|                             |" << endl;
	cout << "|    3.管 理 员               |" << endl;
	cout << "|                             |" << endl;
	cout << "|    4.其 他                  |" << endl;
	cout << "|                             |" << endl;
	cout << "|    0.退 出                  |" << endl;
	cout << "-------------------------------" << endl;
}

void Manager::initVector()
{
	Vtea.clear();
	Vstu.clear(); // 3 admin 123
	ifstream ifs;
	ifs.open(STUNDENT_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Stundent S;
	while (ifs >> S.m_Id && ifs >> S.m_Name && ifs >> S.m_Pwd)
	{
		Vstu.push_back(S);
		//cout << 1 << endl;

	}
	//cout << "当前学生的数量" << Vstu.size() << endl;
	ifs.close();
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	Teacher T;
	while (ifs >> T.m_Id && ifs >> T.m_Name && ifs >> T.m_Pwd)
	{
		Vtea.push_back(T);
	}
	//cout << "当前老师的数量" << Vtea.size() << endl;
	ifs.close();
	return;
}