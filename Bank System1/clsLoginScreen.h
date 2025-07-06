#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"
#include "clsDate.h"
#include <string>


class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login()
    {
        bool LoginFaild = false;
        short FaildLoginCount = 0;

        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                FaildLoginCount++;

                cout << "\n\t\t\t\t\tInvlaid Username/Password!";
                cout << "\a\a\n\t\t\t\t\tYou have " << (3 - FaildLoginCount)
                    << " Trial(s) to login.\n\n";
            }

            if (FaildLoginCount == 3)
            {
                cout << "\a\n\t\t\t\t\tYour are Locked after 3 faild trails \n\n";
                return false;
            }

            cout << "\n\t\t\t\t\tEnter Username? ";
            cin >> Username;

            cout << "\n\t\t\t\t\tEnter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

  
        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:


    static bool ShowLoginScreen()
    {
         system("cls");
        _DrawScreenHeader(" Login Screen");
        return _Login();

    }

};

