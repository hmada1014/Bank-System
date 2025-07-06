#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsFindUserScreen :protected clsScreen
{
private:

	static void _PrintUser(clsUser User)
	{
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";
	}

public:

    static void ShowUserFindScreen()
    {
        _DrawScreenHeader("Find User");

        string UserName = "";

        cout << "Plaese Enter User Name :";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "User is not found , choose another one :";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);

        clsUser::enSaveResults SaveMode;

        SaveMode = User.Save();

        switch (SaveMode)
        {
        case clsUser::svFaildEmptyObject:

            cout << "\nUser Not Found :-(\n";
            _PrintUser(User);

            break;
        case clsUser::svSucceeded:

            cout << "\nUser Found :-)\n";
            _PrintUser(User);

            break;
        case clsUser::svFaildUserExists:
            cout << "\nError User was not saved because UserName is used!\n";

            break;
        }

    }
};

