#pragma once

#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"



class clsClientListScreen :protected clsScreen
{

private:
	
    static void _PrintClientRecordLine(clsBankClient Client)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(22) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(22) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }

public:

    static void ShowClientsList()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pListClients))
        {
            return;
        }

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "     Client List Screen";
        string SubTitle = "(" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(22) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(22) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        float TotalBalance = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else
        {
            for (clsBankClient Client : vClients)
            {

                _PrintClientRecordLine(Client);
                TotalBalance += Client.AccountBalance;
                cout << endl;
            }

            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_____________________________________________\n" << endl;


            cout << setw(34) << left << "" << "Total Balances is : " << TotalBalance << endl;
            cout << setw(34) << left << "" << "( " << clsUtil::NumberToText(TotalBalance) << " )\n";
        }
    }


};

