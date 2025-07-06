#pragma once

#include <iostream>
#include <iomanip>
#include "clsBankClient.h";
#include "clsScreen.h"

class clsUpdateClientScreen :protected clsScreen
{
private :
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

  static  void _ReadClientInfo(clsBankClient& Client)
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

    static void ShowUpdateClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;
        }


        _DrawScreenHeader("Update Client Screen");


        string AccountNumber = "";

        cout << "\nPlease Enter Client Accoun Number :";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Account Number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        _PrintClient(Client1);

        char Answer;

        cout << "Are you sure you want to update this client y/n ? ";
        cin >> Answer;
        while (!(toupper(Answer) == 'Y' || toupper(Answer) == 'N'))
        {
            cout << "Wrong choice choose y or n ? ";
            cin >> Answer;
        }
        

        if ( toupper(Answer) == 'Y')
        {
            cout << "\n\nUpdate Client Info:";
            cout << "\n__________________________\n";

            _ReadClientInfo(Client1);


            clsBankClient::enSaveResults SaveMode;
            SaveMode = Client1.Save();

            switch (SaveMode)
            {
            case clsBankClient::enSaveResults::svSucceeded:

                cout << "\n\nAccuoun Updated Successfully :)\n";
                _PrintClient(Client1);

                break;
            case clsBankClient::enSaveResults::svFaildEmptyObject:

                cout << "\n\nError Account was not saved becoause it's Empty \n";
                break;

            }
        }



    }
};

