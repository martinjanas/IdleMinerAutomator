#include "main.h"

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


std::random_device rdevice;
std::mt19937 generator(rdevice());

DWORD GetRandomBiggerDelay(int delay_min, int delay_max)
{
	std::uniform_int_distribution<int> delay(delay_min, delay_max);

	return delay(generator);
}

void RandomBiggerDelay() //Will sleep from 15 - 25 seconds
{
	int delay_min = 15;
	int delay_max = 25;

	DWORD s = GetRandomBiggerDelay(delay_min, delay_max);

	printf("delay: %i %s\n", s, s == 1 ? "second" : "seconds");

	std::this_thread::sleep_for(std::chrono::seconds(s));
}

int main()
{
	HWND hwnd = FindWindowA(NULL, "#hello - Discord");
	CHWND* _hwnd = new CHWND(hwnd);

	std::thread focus_thread(&_main::focus, hwnd);
	Sleep(7000);
	std::thread quiz_thread(&_main::quiz, hwnd, _hwnd);
	RandomBiggerDelay();
	std::thread rage_thread(&_main::rage, hwnd, _hwnd);
	Sleep(7000);
	std::thread wings_thread(&_main::wings, hwnd, _hwnd);
	RandomBiggerDelay();
	std::thread fish_thread(&_main::fish, hwnd, _hwnd);
	Sleep(7000);
	std::thread hunt_thread(&_main::hunt, hwnd, _hwnd);
	RandomBiggerDelay();
	std::thread hourly_thread(&_main::hourly, hwnd, _hwnd);
	Sleep(7000);
	std::thread main_thread(&_main::main_function, hwnd, _hwnd);

	focus_thread.join();
	quiz_thread.join();
	rage_thread.join();
	wings_thread.join();
	fish_thread.join();
	hunt_thread.join();
	hourly_thread.join();
	main_thread.join();

	delete _hwnd;
}