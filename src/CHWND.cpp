#include "CHWND.h"

std::random_device rd;
std::mt19937 gen(rd());

HWND CHWND::GetHWND()
{
	return this->hwnd;
}

DWORD CHWND::GetRandomBiggerDelay(int delay_min, int delay_max)
{
	std::uniform_int_distribution<int> delay(delay_min, delay_max);

	return delay(gen);
}

void CHWND::RandomBiggerDelay() //Will sleep from 2 - 4 minutes
{
	int delay_min = 1;
	int delay_max = 2;

	DWORD s = GetRandomBiggerDelay(delay_min, delay_max);

	printf("delay: %i %s\n", s, s == 1 ? "minute" : "minutes");

	std::this_thread::sleep_for(std::chrono::minutes(s));
}

DWORD CHWND::GetRandomDelay(int delay_min, int delay_max)
{
	std::uniform_int_distribution<int> num(delay_min, delay_max);

	return num(gen);
}

void CHWND::RandomDelay()
{
	int delay_min = 4000;
	int delay_max = 6000;

	DWORD ms = GetRandomDelay(delay_min, delay_max);

	printf("delay: %i ms\n", ms);

	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void CHWND::RandomDelayNoPrintf()
{
	int delay_min = 4000;
	int delay_max = 6000;

	DWORD ms = GetRandomDelay(delay_min, delay_max);

	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void CHWND::SendString(std::string msg)
{
	SendMessage(hwnd, WM_ACTIVATE, WA_ACTIVE, 1);
	for (int i = 0; i < msg.length(); i++)
	{
		SendMessage(this->hwnd, WM_CHAR, msg[i], 0);
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	SendMessage(this->hwnd, WM_KEYDOWN, VK_RETURN, 0);
	SendMessage(this->hwnd, WM_KEYUP, VK_RETURN, 0);

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	RandomDelay();
}

void CHWND::SendStringNoPrintf(std::string msg)
{
	SendMessage(hwnd, WM_ACTIVATE, WA_ACTIVE, 1);
	for (int i = 0; i < msg.length(); i++)
	{
		SendMessage(this->hwnd, WM_CHAR, msg[i], 0);
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	SendMessage(this->hwnd, WM_KEYDOWN, VK_RETURN, 0);
	SendMessage(this->hwnd, WM_KEYUP, VK_RETURN, 0);

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	RandomDelayNoPrintf();
}

void CHWND::SendStringSmallDelay(std::string msg, DWORD delay)
{
	SendMessage(hwnd, WM_ACTIVATE, WA_ACTIVE, 1);
	for (int i = 0; i < msg.length(); i++)
	{
		SendMessage(this->hwnd, WM_CHAR, msg[i], 0);
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	SendMessage(this->hwnd, WM_KEYDOWN, VK_RETURN, 0);
	SendMessage(this->hwnd, WM_KEYUP, VK_RETURN, 0);

	std::this_thread::sleep_for(std::chrono::milliseconds(delay));
}
