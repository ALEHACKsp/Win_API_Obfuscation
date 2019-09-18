#pragma once
#include <consoleapi2.h>
#include <cstdio>
#include <synchapi.h>
#include <winbase.h>

inline void log()
{
}

template <typename First, typename ...Rest>
void log(First&& message, Rest&& ...rest)
{
	std::cout << std::forward<First>(message) << std::endl;
	log(std::forward<Rest>(rest)...);
}

HANDLE event;

typedef int (WINAPI* ShellAboutProc)(HWND, LPCSTR, LPCSTR, HICON);
