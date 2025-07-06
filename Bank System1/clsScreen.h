#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsScreen.h"
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"


using namespace std;

class clsScreen
{
protected:

    static void _DrawScreenHeader(string Titele, string SubTitele = "")
    {
        cout << "\t\t\t\t\t________________________________________________";
        cout << "\n\n\t\t\t\t\t\t" << Titele;
        if (SubTitele != "")
        {
            cout << "\n\n\t\t\t\t\t\t\t " << SubTitele;
        }
        cout << "\n\n\t\t\t\t\t________________________________________________" << endl;


        cout << "\n";
        _DrawScreenUser();
        _DrawscreenDate();

    };

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (CurrentUser.CheckAccessPermission(Permission))
        {
            return true;
        }
        else
        {
            cout << "\n\t\t\t\t\t________________________________________________";
            cout << "\n\n\t\t\t\t\t       Access Denied! Contact Your Admin.\n";
            cout << "\n\t\t\t\t\t________________________________________________\n";
            return false;
        }

       
    }

    static void _DrawScreenUser()
    {
        cout << setw(40) << left << "" << "User: " << CurrentUser.GetUserName() << endl;
    }

    static void _DrawscreenDate()
    {
        string Date = clsDate::DateToString(clsDate::GetSystemDate());
        cout << setw(40) << left << "" << "Date: " << clsDate::DateToString(clsDate()) << endl;
    }
};

