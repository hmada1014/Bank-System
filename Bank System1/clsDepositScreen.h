#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsBankClient.h"
#include <string>




class clsDepositScreen :protected clsScreen
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

	static void ShowDepositScreen()
	{
        system("cls");
        _DrawScreenHeader("Deposit Screen");

        string AccounNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccounNumber))
        {
            cout << "\nClient With ["<<AccounNumber<<"] does not exist.\n";
            AccounNumber = _ReadAccountNumber();
        }
        clsBankClient Client = clsBankClient::Find(AccounNumber);
        _PrintClient(Client);

        double Amount = 0;
        cout << "\nPlease Enter dopsit amount ?";
        Amount = clsInputValidate::ReadDblNumber();

        char Answar;
        cout << "\nAre sure you want to perform this Transaction ? ";
        cin >> Answar;
       
        
        if (toupper(Answar) == 'Y')
        {
            if (Client.Deposit(Amount))
            {
                cout << "\nAmount Deposited Successfully.\n";
                cout << "New Balance Is : " << Client.AccountBalance;
            }
            else
            {
                cout << "\nOperation was cancelled.\n";
            }

        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
        

	}
};

