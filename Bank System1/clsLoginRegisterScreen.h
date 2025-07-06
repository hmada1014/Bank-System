#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"
#include "clsDate.h"
#include <string>

class clsLoginRegisterScreen :protected clsScreen
{
private:
	/*
	//struct MyStruct
	//{
	//	string DateTime;
	//	string UserNam;
	//	string Password;
	//	string Permissiotn;
	//};

	//static MyStruct _ConvertLinetoRecord(string Line, string Seperator = "#//#")
	//{
	//	vector<string> vUserData;
	//	vUserData = clsString::Split(Line, Seperator);

	//	MyStruct Record;
	//	Record.DateTime = vUserData[0];
	//	Record.UserNam = vUserData[1];
	//	Record.Password = vUserData[2];
	//	Record.Permissiotn = vUserData[3];

	//	return Record;

	//}

	//static  vector <MyStruct> _LoadLoginRegisterFromFile()
	//{
	//	vector <MyStruct> LoginRegister;

	//	fstream MyFile;

	//	MyFile.open("LoginRegister.txt", ios::in);

	//	if (MyFile.is_open())
	//	{
	//		string Line;
	//		while (getline(MyFile, Line))
	//		{
	//			MyStruct Record = _ConvertLinetoRecord(Line);

	//			LoginRegister.push_back(Record);
	//		}

	//		MyFile.close();
	//	}

	//	return LoginRegister;

	//}

	//static vector <MyStruct> _GetLoginRegister()
	//{
	//	return _LoadLoginRegisterFromFile();
	//}*/
	

	static void _DrawHeaderLoginRegister()
	{
		cout << "\n";
		cout << "\t\t_______________________________________________________________________________________________";
		cout << "\n\n\t\t";
		cout << "| " << left << "" << setw(25) << "Date/Time";
		cout << "| " << left << "" << setw(20) << "UserName ";
		cout << "| " << left << "" << setw(25) << "Password";
		cout << "| " << left << "" << setw(25) << "Permissions" << endl;
		cout << "\t\t_______________________________________________________________________________________________";
		
	}
	
	static void _DrawLoginRegister(clsUser::stLoginRegisterRecord Record)
	{
		cout << "\n\t\t";
		cout << "| "  << left << setw(25)  << Record.DateTime;
		cout << "| "  << left << setw(20)  << Record.UserName;
		cout << "| "  << left << setw(25)  << Record.Password;
		cout << "| "  << left << setw(25) << Record.Permissions;

	}

public:

	static void ShowLoginRegister()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
		{
			return;
		}
		vector <clsUser::stLoginRegisterRecord> vLoginRegister = clsUser::GetLoginRegisterList() ;

		string Titel    = "Login Register Screen";
		string SubTitel ="  "+ to_string(vLoginRegister.size()) + " Record(s).";

		_DrawScreenHeader(Titel,SubTitel);

		_DrawHeaderLoginRegister();

		if (vLoginRegister.size() == 0)
		{
			cout << "\t\t\t\tNo Login Register Available In the System!";
		}
		else
		{

			for (clsUser::stLoginRegisterRecord& u : vLoginRegister)
			{
				_DrawLoginRegister(u);
			}
			cout << "\n\t\t_______________________________________________________________________________________________\n";

		}


	}

};

