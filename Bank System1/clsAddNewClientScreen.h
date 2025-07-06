#pragma once

#include <iostream>
#include <iomanip>
#include "clsBankClient.h";
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsAddNewClientScreen :protected clsScreen
{
private:

    static void   _PrintClient(clsBankClient Client)
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
    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter Frist Name : ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter Last Name  : ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email      : ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone      : ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password   : ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Balance    : ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();

    }

public:


    static void ShowAddNewClientScree()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return;
        }

        string AccountNumber = "";

        _DrawScreenHeader("Add New Client Screen");


        cout << "\nPlease Enter Client Accoun Number :";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Account Number is Exist, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient AddNewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(AddNewClient);

        clsBankClient::enSaveResults SaveMode;

        SaveMode = AddNewClient.Save();

        switch (SaveMode)
        {
        case clsBankClient::enSaveResults::svSucceeded:

            cout << "\n\nAccuoun Added Successfully :)\n";
            _PrintClient(AddNewClient);
            break;
        case clsBankClient::enSaveResults::svFaildEmptyObject:

            cout << "\n\nError Account was not saved becoause it's Empty \n";
            break;

        case clsBankClient::enSaveResults::svFaildAccountNumberExists:

            cout << "sorry Account Number is Exist ";
            break;
        }

    }
};

