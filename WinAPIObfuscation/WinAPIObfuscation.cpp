#include "pch.h"
#include <iostream>
#include "hash_work.h"

using namespace std;

inline void log()
{
}

template <typename First, typename ...Rest>
void log(First&& message, Rest&& ...rest)
{
	std::cout << std::forward<First>(message) << std::endl;
	log(std::forward<Rest>(rest)...);
}


int main()
{
	// CreateFileA
	HANDLE hFile = hash_CreateFileA("log.txt", GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile) {
		log("[OK] CreateFileA");
	}
	else if (hFile == INVALID_HANDLE_VALUE) {
		log("[FAIL] CreateFileA");
	}

	// VirtualAlloc/VirtualFree/VirtualProtect
	LPVOID p = nullptr;

	p = hash_VirtualAlloc(nullptr, 4000, MEM_RESERVE, PAGE_READWRITE);

	// TODO: make example with return true
	bool vp = hash_VirtualProtect(p, 0, PAGE_EXECUTE_READWRITE, 0); // return false

	if (p != nullptr)
	{
		log("[OK] VirtualAlloc");
		if (hash_VirtualFree(p, 0, MEM_RELEASE)){
			log("[OK] VirtualFree");
		}
		else{
			log("[FAIL] VirtualFree");
		}
	} else {
		log("[FAIL] VirtualAlloc");
	}
	// -----------------------

	// VirtualAllocEx
	LPVOID p1 = nullptr;
	// TODO: VirtualAllocEx not work
	p1 = hash_VirtualAllocEx(GetCurrentProcess(), nullptr, 4000, MEM_RESERVE, PAGE_READWRITE);
	if (p1 != nullptr)
	{
		log("[OK] VirtualAllocEx");
	}
	else {
		log("[FAIL] VirtualAllocEx");
	}
	// -----------------------

	system("pause");

	return 1;
}