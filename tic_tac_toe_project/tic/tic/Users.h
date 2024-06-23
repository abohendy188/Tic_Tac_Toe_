#pragma once
using namespace System;

public ref class User {

public:
	String^ Username;
	String^ Password;
	int Wins;
	int Loss;
	int Tie;
	void IncrementWins()
	{
		Wins++;
	}
	void IncrementTie()
	{
		Tie++;
	}
	void IncrementLoss()
	{
		Loss++;
	}
};