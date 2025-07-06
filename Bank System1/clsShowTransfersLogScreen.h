#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsShowTransfersLogScreen :protected clsScreen
{
private:


	static void _PrintTransferLogRecord(clsBankClient::stTrnsferLogRecord Record)
	{
		cout << "\n";
		cout << "\t| " << left << "" << setw(25) << Record.DateTime;
		cout << "| " << left << "" << setw(10) << Record.SourceAccountNumber;
		cout << "| " << left << "" << setw(10) << Record.DestinationAccountNumber;
		cout << "| " << left << "" << setw(10) << Record.Amount;
		cout << "| " << left << "" << setw(13) << Record.srcBalanceAfter;
		cout << "| " << left << "" << setw(13) << Record.destBalanceAfter;
		cout << "| " << left << "" << setw(13) << Record.UserName;

	}

	static void _PrintTransferLogHeader()
	{
		cout << "\n\t_________________________________________________________";
		cout << "________________________________________________\n\n";
		cout << "\t| " << left << "" << setw(25) << "Data/Time";
		cout << "| " << left << "" << setw(10) << "s.Acct";
		cout << "| " << left << "" << setw(10) << "d.Acct";
		cout << "| " << left << "" << setw(10) << "Amount";
		cout << "| " << left << "" << setw(13) << "s.Balance";
		cout << "| " << left << "" << setw(13) << "d.Balance";
		cout << "| " << left << "" << setw(13) << "User";
		cout << "\n\t_________________________________________________________";
		cout << "________________________________________________\n";

	}
public:

	static void ShowTransferLogScreen()
	{
		vector <clsBankClient::stTrnsferLogRecord> vTransferLog = clsBankClient::GetTransfersLogList();

		string Titel = "Transfer Log List Screen ";
		string SubTitel = "(" + to_string(vTransferLog.size()) +") Record(s).";


		_DrawScreenHeader(Titel,SubTitel);

		_PrintTransferLogHeader();
		
		if (vTransferLog.size() <= 0)
		{
			cout << "\t\t\t\tNo Transfer Log Available.";
		}
		else
		{
			for (clsBankClient::stTrnsferLogRecord& T : vTransferLog)
			{
			
				_PrintTransferLogRecord(T);
			}

			cout << "\n\t_________________________________________________________";
			cout << "________________________________________________\n";
		}
	}
};

