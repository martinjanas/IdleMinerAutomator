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

int main()
{
	HWND hwnd = FindWindowA(NULL, "#hello - Discord");
	CHWND* _hwnd = new CHWND(hwnd);

	std::thread focus_thread(&_main::focus, hwnd);
	Sleep(2000);
	std::thread quiz_thread(&_main::quiz, hwnd, _hwnd);
	Sleep(7000);
	std::thread rage_thread(&_main::rage, hwnd, _hwnd);
	Sleep(7000);
	std::thread wings_thread(&_main::wings, hwnd, _hwnd);
	Sleep(7000);
	std::thread fish_thread(&_main::fish, hwnd, _hwnd);
	Sleep(7000);
	std::thread hunt_thread(&_main::hunt, hwnd, _hwnd);
	Sleep(7000);
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