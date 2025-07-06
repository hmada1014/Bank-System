#pragma once
#include <iostream>

using namespace std;

class clsPerson 
{
private:
	string _FristName;
	string _LastName;
	string _Email;
	string _Phone;
public:


	clsPerson(string FirstName , string LastName, string Email ,string Phone )
	{
		_FristName = FirstName;
		_LastName  = LastName;
		_Email = Email;
		_Phone = Phone;
	}

	void SetFristName(string FristName)
	{
		_FristName = FristName;
	}

	string GetFristName()
	{
		return _FristName;
	}
	__declspec(property(get = GetFristName, put = SetFristName))string FirstName;

	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}

	string GetLastName()
	{
		return _LastName;
	}
	__declspec(property(get = GetLastName, put = SetLastName))string LastName;

	string FullName()
	{
		return _FristName + " " + _LastName;
	}

	void SetEmail(string Email)
	{
		_Email = Email;
	}

	string GetEmail()
	{
		return _Email;
	}
	__declspec(property(get = GetEmail, put = SetEmail))string Email;

	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}

	string GetPhone()
	{
		return _Phone;
	}
	__declspec(property(get = GetPhone, put = SetPhone))string Phone;

	
};

