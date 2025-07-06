#pragma once

#include <iostream>
#include <iomanip>
#include "clsBankClient.h";
#include "clsScreen.h"


class clsFindClientScreen :protected clsScreen
{
private:

    static void  _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }


public:

    static void ShowFindclientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;
        }


        _DrawScreenHeader("Find Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Client Accoun Number :";
        AccountNumber = clsInputValidate::ReadString();

      /*  while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Account Number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }*/

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        if (!Client.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Not Found :-(\n";

        }
        _PrintClient(Client);
    }

};
