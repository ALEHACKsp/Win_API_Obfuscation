#include "pch.h"
#include <iostream>
#include "hash_work.h"

int main()
{
	HANDLE hFile = hash_CreateFileA("log.txt", GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE == hFile) {
		std::cout << "Error open file!\n";
		while (1);
	}
}