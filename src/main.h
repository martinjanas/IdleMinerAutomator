#pragma once

#include <Windows.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

#include "CHWND.h"

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

namespace _main
{
	static const char* buy_option[] = {
	";up p a",
	";up b a"
	};

	static const char* quiz_options[] = {
		"a", "b", "c", "d"
	};

	void focus(HWND hwnd)
	{
		printf("focus() starting.\n");
		while (hwnd)
		{
			SendMessage(hwnd, WM_ACTIVATE, WA_ACTIVE, 1);
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}

	void quiz(HWND hwnd, CHWND* _hwnd)
	{
		printf("quiz() starting.\n");
		char buf[256];

		while (hwnd)
		{
			_hwnd->SendStringSmallDelay(";quiz");
			sprintf_s(buf, "%s", quiz_options[rand() % ARRAYSIZE(quiz_options)]);
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			_hwnd->SendStringNoPrintf(buf);

			std::this_thread::sleep_for(std::chrono::milliseconds(305000)); //7 minutes
		}
	}

	void rage(HWND hwnd, CHWND* _hwnd)
	{
		printf("rage() starting.\n");

		while (hwnd)
		{
			_hwnd->SendStringNoPrintf(";rage");
			std::this_thread::sleep_for(std::chrono::milliseconds(390000)); //6 minutes and 30 seconds
		}
	}

	void wings(HWND hwnd, CHWND* _hwnd)
	{
		printf("wings() starting.\n");

		while (hwnd)
		{
			_hwnd->SendStringNoPrintf(";wings");
			std::this_thread::sleep_for(std::chrono::milliseconds(390000)); //6 minutes and 30 seconds
		}
	}

	void fish(HWND hwnd, CHWND* _hwnd)
	{
		printf("fish() starting.\n");

		while (hwnd)
		{
			_hwnd->SendStringNoPrintf(";f");
			std::this_thread::sleep_for(std::chrono::milliseconds(305000)); //5 minutes and 5 seconds
		}
	}

	void hunt(HWND hwnd, CHWND* _hwnd)
	{
		printf("hunt() starting.\n");

		while (hwnd)
		{
			_hwnd->SendStringNoPrintf(";h");
			std::this_thread::sleep_for(std::chrono::milliseconds(305000)); //5 minutes and 5 seconds
		}
	}

	void hourly(HWND hwnd, CHWND* _hwnd)
	{
		printf("hourly() starting.\n");

		while (hwnd)
		{
			_hwnd->SendStringNoPrintf(";ca");
			std::this_thread::sleep_for(std::chrono::milliseconds(3605000)); //60 minutes and 5 seconds
		}
	}

	void main_function(HWND hwnd, CHWND* _hwnd)
	{
		printf("_main_thread() starting.\n");
		char buf[256];

		if (!hwnd)
		{
			printf("Window was not found!\nExiting...");
			std::this_thread::sleep_for(std::chrono::seconds(2));
			exit(-1);
		}

		while (hwnd)
		{
			_hwnd->SendString(";s");
			sprintf_s(buf, "%s", buy_option[rand() % 2]);
			_hwnd->SendString(";s");
			_hwnd->SendString(buf);
			_hwnd->RandomBiggerDelay();
			_hwnd->SendString(";level");
			_hwnd->SendString(";rebirth");
			_hwnd->SendString(";s");
		}
	}
}