#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include <string>

class clsWithDrawScreen :protected clsScreen
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

    static string _ReadAccountNumber()
    {
        string AccountNumber;
        cout << "\nPlease enter AccountNumber ? ";
        cin >> AccountNumber;

        return AccountNumber;
    }


public:

    static void ShowWithDrawScreen()
    {
        system("cls");
        _DrawScreenHeader("WithDraw Screen");

        string AccounNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccounNumber))
        {
            cout << "\nClient With [" << AccounNumber << "] does not exist.\n";
            AccounNumber = _ReadAccountNumber();
        }
        clsBankClient Client = clsBankClient::Find(AccounNumber);
        _PrintClient(Client);

        double Amount = 0;
        cout << "\nPlease Enter Withdraw amount ?";
        Amount = clsInputValidate::ReadDblNumber();

        //while (Amount >= Client.AccountBalance)
        //{
        //    cout << "\nAmount bigger than Balance ,Please Enter Withdraw amount ?";
        //    Amount = clsInputValidate::ReadDblNumber();
        //}

        char Answar;
        cout << "\nAre sure you want to perform this Transaction ? ";
        cin >> Answar;


        if (toupper(Answar) == 'Y')
        {
            if ( Client.Withdraw(Amount) )
            {
                cout << "\nAmount Deposited Successfully.";
                cout << "\nNew Balance Is : " << Client.AccountBalance;
            }
            else
            {
                cout << "\nCannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmount to withdraw is:"<<Amount;
                cout << "\nYour Balance is:"<<Client.AccountBalance;
            }

        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }


    }
};


