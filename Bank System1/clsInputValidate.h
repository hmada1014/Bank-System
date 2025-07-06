#pragma once
#include <iostream>
#include "clsUtil.h"
#include "clsDate.h"


using namespace std;


class clsInputValidate
{

public:

	static bool IsNumberBetween(short NumberBetween, short From, short To)
	{
		return ((NumberBetween >= From) && (NumberBetween <= To));
	}

	static bool IsNumberBetween(int NumberBetween, int From, int To)
	{
		return ((NumberBetween >= From) && (NumberBetween <= To));
	}

	static bool IsNumberBetween(float NumberBetween, float From, float To)
	{
		return ((NumberBetween >= From) && (NumberBetween <= To));
	}

	static bool IsNumberBetween(double NumberBetween, double From, double To)
	{
		return ((NumberBetween >= From) && (NumberBetween <= To));
	}

	//static bool IsNumberBetween(clsDate NumberBetween, clsDate From, clsDate To)
	//{
	//	return (clsDate::IsDate1BeforeDate2(NumberBetween, To) && clsDate::IsDate1AfterDate2(NumberBetween, From));
	//}

	static bool    IsNumberBetween(clsDate Number, clsDate From, clsDate To)
	{
		// Number:(11/20/2023) > From:(20/11/2023)  //Number:(11/20/2023) == From:(20/11/2023)
		if (clsDate::IsDate1AfterDate2(Number, From) || clsDate::IsDate1EqualDate2(Number, From)
			&&
			// Number:(11/20/2023) < To:(31/12/2023)  //Number:(11/20/2023) == To:(31/12/2023)
			clsDate::IsDate1BeforeDate2(Number, To) || clsDate::IsDate1EqualDate2(Number, To))
		{
			return true;
		}

		// Number:(11/20/2023) < To:(31/12/2023)  //Number:(11/20/2023) == To:(31/12/2023)
		if (clsDate::IsDate1AfterDate2(Number, To) || clsDate::IsDate1EqualDate2(Number, To)
			&&
			// Number:(11/20/2023) > From:(20/11/2023)  //Number:(11/20/2023) == From:(20/11/2023)
			clsDate::IsDate1BeforeDate2(Number, From) || clsDate::IsDate1EqualDate2(Number, From))
		{
			return true;
		}

		return false;
	}

	static int     ReadIntNumber(string ErrorMassege = "Invalid input; please re - enter.")
	{
		{
			int Number = 1;
			bool valid = false;
			do
			{
				cin >> Number;
				if (cin.good())
				{
					//everything went well, we'll get out of the loop and return the value
					valid = true;
				}
				else
				{
					//something went wrong, we reset the buffer's state to good
					cin.clear();
					//and empty it
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << ErrorMassege << endl;
				}
			} while (!valid);

			return (Number);
		}
	}

	static float   ReadFloatNumber(string ErrorMassege = "Invalid input; please re - enter.")
	{
		{
			float Number = 1;
			bool valid = false;
			do
			{
				cin >> Number;
				if (cin.good())
				{
					//everything went well, we'll get out of the loop and return the value
					valid = true;
				}
				else
				{
					//something went wrong, we reset the buffer's state to good
					cin.clear();
					//and empty it
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << ErrorMassege << endl;
				}
			} while (!valid);

			return (Number);
		}
	}

	static double  ReadDblNumber(string ErrorMassege = "Invalid input; please re - enter.")
	{

		double Number = 1;
		while (!(cin >> Number))
		{
			//something went wrong, we reset the buffer's state to good
			cin.clear();
			//and empty it
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMassege << endl;
		}

		return (Number);

	}

	static string  ReadString()
	{
		string S1 = "";
		getline(cin >> ws, S1);
		return S1;
	}

	static short   ReadShortNumberBetween(short From, short To, string Massege)
	{

		short Number = 1;
		bool Valid = false;
		Number = ReadIntNumber();
		do
		{
			if (Number >= From && Number <= To)
			{
				Valid = true;
			}
			else
			{
				cout << Massege;
				Number = ReadIntNumber();
			}
		} while (!Valid);
		return Number;

	}

	static int     ReadIntNumberBetween(int From, int To, string Massege)
	{

		int Number = 1;
		bool Valid = false;
		Number = ReadIntNumber();
		do
		{
			if (Number >= From && Number <= To)
			{
				Valid = true;
			}
			else
			{
				cout << Massege;
				Number = ReadIntNumber();
			}
		} while (!Valid);
		return Number;

	}

	static float   ReadFloatNumberBetween(float From, float To, string Massege)
	{

		int Number = 1;
		bool Valid = false;
		Number = ReadIntNumber();
		do
		{
			if (Number >= From && Number <= To)
			{
				Valid = true;
			}
			else
			{
				cout << Massege;
				Number = ReadIntNumber();
			}
		} while (!Valid);
		return Number;

	}

	static double  ReadDblNumberBetween(double From, double To, string Massege)
	{
		double Number = 1;
		bool Valid = false;
		Number = ReadDblNumber();
		do
		{
			if (Number >= From && Number <= To)
			{
				Valid = true;
			}
			else
			{
				cout << setw(40) << left << "" << Massege;
				Number = ReadDblNumber();
			}
		} while (!Valid);
		return Number;

	}

	static bool    IsValideDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}


};

