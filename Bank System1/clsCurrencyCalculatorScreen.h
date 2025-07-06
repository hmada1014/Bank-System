#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>

class clsCurrencyCalculatorScreen :protected clsScreen
{
private:
	static void _PrintCurrencyCard(clsCurrency Currency, string Massege)
	{
		cout << "\n"<<Massege<<"\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n_____________________________\n";

	}

	static clsCurrency _GetCurrency(string Massege)
	{
		cout << Massege;
		string Currency = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(Currency))
		{
			cout << "\n\aWrong Currency Code, Please Enter Currency1 Code:\n";
			Currency = clsInputValidate::ReadString();
		}

		clsCurrency CurrencyCode = clsCurrency::FindByCode(Currency);

		return CurrencyCode;
	}

	static float _ReadAmount()
	{
		cout << "\nEnter Amount To Exchange :";

		return  clsInputValidate::ReadFloatNumber();
	}

	static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{

		_PrintCurrencyCard(Currency1, "Convert From ");

		float AmountInUSD = Currency1.ConvertToUSD(Amount);


		
			cout << Amount << " " << Currency1.CurrencyCode()
				 << " = " << AmountInUSD << " USD";

			if (Currency2.CurrencyCode() == "USD")
			{
				return;
			}
			
			cout << "\n\nConverting from USD to:\n\n";

			cout << "\n";

			_PrintCurrencyCard(Currency2, " To ");


			float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

			cout << "\n";

			cout << Amount << " " << Currency1.CurrencyCode()
				<< " = " << AmountInCurrency2 << " " << Currency2.CurrencyCode();
	}


public:

	static void ShowCurrencyCalculatorScreen()
	{
		char answar = 'Y';

		while (toupper(answar) == 'Y')
		{
		
		system("cls");
		_DrawScreenHeader("Calclator Currency Screen");

		clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code :\n");
		clsCurrency CurrencyTo   = _GetCurrency("\nPlease Enter Currency2 Code :\n");
		float AmountExchange     = _ReadAmount();

		_PrintCalculationsResults(AmountExchange, CurrencyFrom, CurrencyTo);

		cout << "\n\nDo you want to perform another Calculation? y/n ?";
		cin >> answar;

		} 

	}

};

