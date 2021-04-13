#pragma once
#include <Windows.h>
#include <iostream>
#include <random>
#include <thread>
#include <chrono>

/*
*		This is my program for sending strings and keyboard strokes into specific windows, nothing fancy.
*
*				Please, dont use it on Discord to spam servers, you might get banned!
*
*		This program was created, because I was bored and wanted to automatize Idle Miner bot on Discord.
*
*											  MartiNJ409
*
*/

class CHWND
{
public:

	CHWND(HWND _hwnd)
	{
		this->hwnd = _hwnd;
	}

	HWND GetHWND();
	DWORD GetRandomBiggerDelay(int delay_min, int delay_max);
	void RandomBiggerDelay();
	DWORD GetRandomDelay(int delay_min, int delay_max);
	void RandomDelay();
	void RandomDelayNoPrintf();
	void SendString(std::string msg);
	void SendStringNoPrintf(std::string msg);
	void SendStringSmallDelay(std::string msg, DWORD delay = 1000);

private:
	HWND hwnd = nullptr;
};

