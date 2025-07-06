#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsString.h"
#include "clsUtil.h"
#include "clsMainScreen.h"
#include "clsUser.h"
#include "clsLoginScreen.h"
#include <ctime>
#include "clsCurrency.h"
#include "clsPerson.h"


// افصل اليواي عن الاوبجيكت
void _ReadClientInfo(clsBankClient& Client)
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

void UpdateClient()
{
	string AccountNumber = "";

	cout << "\nPlease Enter Client Accoun Number :";
	AccountNumber = clsInputValidate::ReadString();

	while (!clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "Account Number is not found, choose another one: ";
		AccountNumber = clsInputValidate::ReadString();
	}

	clsBankClient Client1 = clsBankClient::Find(AccountNumber);
	/* Client1.Print();*/

	cout << "\n\nUpdate Client Info:";
	cout << "\n__________________________\n";

	_ReadClientInfo(Client1);


	clsBankClient::enSaveResults SaveMode;
	SaveMode = Client1.Save();

	switch (SaveMode)
	{
	case clsBankClient::enSaveResults::svSucceeded:

		cout << "\n\nAccuoun Updated Successfully :)\n";
		/*  Client1.Print();*/
		break;
	case clsBankClient::enSaveResults::svFaildEmptyObject:

		cout << "\n\nError Account was not saved becoause it's Empty \n";
		break;

	}



}

void ShowAddNewClientScree()
{
	string AccountNumber = "";

	cout << "\nPlease Enter Client Accoun Number :";
	AccountNumber = clsInputValidate::ReadString();

	while (clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "Account Number is Exist, choose another one: ";
		AccountNumber = clsInputValidate::ReadString();
	}

	clsBankClient ShowAddNewClientScree = clsBankClient::GetAddNewClientObject(AccountNumber);

	_ReadClientInfo(ShowAddNewClientScree);

	clsBankClient::enSaveResults SaveMode;

	SaveMode = ShowAddNewClientScree.Save();

	switch (SaveMode)
	{
	case clsBankClient::enSaveResults::svSucceeded:

		cout << "\n\nAccuoun Updated Successfully :)\n";
		/*    ShowAddNewClientScree.Print();*/
		break;
	case clsBankClient::enSaveResults::svFaildEmptyObject:

		cout << "\n\nError Account was not saved becoause it's Empty \n";
		break;

	case clsBankClient::enSaveResults::svFaildAccountNumberExists:

		cout << "sorry Account Number is Exist ";
		break;
	}

}

void ShowDeleteClientScreen()
{
	string AccountNumber = "";

	cout << "\nPlease Enter Client Accoun Number :";
	AccountNumber = clsInputValidate::ReadString();

	while (!clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "Account Number is not found, choose another one: ";
		AccountNumber = clsInputValidate::ReadString();
	}

	clsBankClient Client1 = clsBankClient::Find(AccountNumber);
	//Client1.Print();

	char Answar = 'N';
	cout << "\nAre you sure you want to delete this client y/n? ";
	cin >> Answar;

	if (toupper(Answar) == 'Y')
	{


		if (Client1.Delete())
		{
			cout << "\nClient Deleted Successfully :-)\n";

			/*Client1.Print();*/
		}
		else
		{
			cout << "\nError Client Was not Deleted\n";
		}


	}

}

void _PrintClientRecordLine(clsBankClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber();
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.FullName();
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintClientBalances(clsBankClient Client)
{
	cout << "| " << left << setw(15) << Client.AccountNumber();
	cout << "| " << left << setw(40) << Client.FullName();
	cout << "| " << left << setw(15) << Client.AccountBalance;

}

void ShowClientsList()
{
	vector <clsBankClient> vClients = clsBankClient::GetClientsList();

	cout << "\n" << clsUtil::Tabs(5) << "Client List(" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	if (vClients.size() == 0)
		cout << clsUtil::Tabs(4) << "No Clients Available In the System!";
	else

		for (clsBankClient Client : vClients)
		{

			_PrintClientRecordLine(Client);
			cout << endl;
		}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}

void ShowClientBalances()
{

	vector <clsBankClient> vClient = clsBankClient::GetClientsList();

	cout << "\n";
	cout << clsUtil::Tabs(5);
	cout << "Balances List (" << vClient.size() << ") Clien(s)\n";


	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	double eTotalBalances = clsBankClient::GetTotalBalances();

	if (vClient.size() == 0)
		cout << clsUtil::Tabs(4) << "No Clients Available In the System!";
	else
		for (clsBankClient& Client : vClient)
		{

			PrintClientBalances(Client);
			cout << endl;

		}
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << clsUtil::Tabs(4) << "Total Balances = " << eTotalBalances << endl;
	cout << clsUtil::Tabs(4) << "( " << clsUtil::NumberToText(eTotalBalances) << " )\n";
}


static void _PrintCurrency(clsCurrency Currency)
{
	cout << "\nCurrency Card:\n";
	cout << "_____________________________\n";
	cout << "\nCountry    : " << Currency.Country();
	cout << "\nCode       : " << Currency.CurrencyCode();
	cout << "\nName       : " << Currency.CurrencyName();
	cout << "\nRate(1$) = : " << Currency.Rate();

	cout << "\n_____________________________\n";

}


int main()
{

	// clsMainScreen::ShowMainMenue();

	   while (true)
	   {
	       if (!clsLoginScreen::ShowLoginScreen())
	       {
	           break;
	       }
	   }






	system("pause>0");

	return 0;
}