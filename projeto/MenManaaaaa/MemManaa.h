#pragma once
#include <Windows.h>
#include <vector>

class MemMan
{
public:
	MemMan();
	~MemMan();
	template <class val>
	val readMem(uintptr_t addr)
	{
		val x;
		ReadProcessMemory(handle, (LPBYTE*)addr, &x, sizeof(x), NULL);
		return x;
	}
	template <class val>
	val writeMem(uintptr_t addr, val x)
	{
		WriteProcessMemory(handle, (LPBYTE*)addr, &x, sizeof(x), NULL);
		return x;
	}

	
	uintptr_t getAddress(uintptr_t, std::vector<uintptr_t>);
	
private:
	HANDLE handle;

	uintptr_t getProcess(const char* proc);

	uintptr_t getModule(uintptr_t procId, const char* modName);

};