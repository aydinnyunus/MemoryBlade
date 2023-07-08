#include "memory.h"

#include <thread>
#include <iostream>
#include <string>
#include <Psapi.h>
#include <vector>


void changeMoney(Memory mem, int desired) {
	const auto base_address = mem.GetModuleAddress("mb_warband.exe");
	int ecx = mem.Read<int>(base_address + 0x4eb300);
	std::cout << ecx << std::endl;

	int eax = mem.Read<int>(ecx + 0x6e0);
	ecx = mem.Read<int>(ecx + 0x140f0);
	int money = mem.Read<int>(ecx + 0x5d0);
	mem.Write<int>(ecx + 0x5d0, desired);
}

void changeSkills(Memory mem, int desired) {

	const auto base_address = mem.GetModuleAddress("mb_warband.exe");
	int edx = mem.Read<int>(base_address + 0x4eb300);
	edx = mem.Read<int>(edx + 0x140f0);
	mem.Write<int>(edx + 0x270, desired);
	mem.Write<int>(edx + 0x274, desired);
	mem.Write<int>(edx + 0x278, desired);
	mem.Write<int>(edx + 0x27c, desired);
}

int main()
{


	const auto mem = Memory("mb_warband.exe");
	std::cout << "mount and blade warband found!" << std::endl;
	//changeMoney(mem, 1337);
	//changeSkills(mem, 50);
	


	
	
}