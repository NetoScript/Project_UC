//#pragma once
//#include <Windows.h>
//#include <vector>
//
//class MemMan
//{
//public:
//	MemMan();
//	~MemMan();
//	float viewMatrix[16];
//	template <class val>
//	val readMem(uintptr_t addr)
//	{
//		val x;
//		ReadProcessMemory(handle, (BYTE*)addr, &x, sizeof(x), NULL);
//		return x;
//	}
//	
//	template <class val>
//	val readMem(uintptr_t addr, std::vector<int> offsets)
//	{
//		val ptr = 0;
//
//		for (int i = 0; i < offsets.size() - 1; i++)
//		{
//			ReadProcessMemory(handle, (BYTE*)addr, &addr, sizeof(addr), NULL);
//			// std::cout << std::hex << addr << std::endl;
//			addr += offsets[i];
//		}
//		
//		addr += offsets[offsets.size() - 1];
//
//		ReadProcessMemory(handle, (BYTE*)addr, &ptr, sizeof(ptr), NULL);
//
//		return ptr;
//	}
//	template <class val>
//	val ViewMOffreadMem(uintptr_t addr, std::vector<int> offsets,float ViewMritrixP)
//	{
//		
//
//		for (int i = 0; i < offsets.size() - 1; i++)
//		{
//			ReadProcessMemory(handle, (BYTE*)addr, &addr, sizeof(addr), NULL);
//			// std::cout << std::hex << addr << std::endl;
//			addr += offsets[i];
//		}
//
//		addr += offsets[offsets.size() - 1];
//
//		ReadProcessMemory(handle, (BYTE*)addr, &ViewMritrixP, sizeof(ViewMritrixP), NULL);
//
//		return ViewMritrixP;
//	}
//
//
//	template <class val>
//	val writeMem(uintptr_t addr, val x)
//	{
//		WriteProcessMemory(handle, (BYTE*)addr, &x, sizeof(x), NULL);
//		return x;
//	}
//
//	uintptr_t getProcess(const wchar_t*);
//	uintptr_t getModule(uintptr_t, const wchar_t*);
//	uintptr_t getAddress(uintptr_t, std::vector<uintptr_t>);
//	
//private:
//	HANDLE handle;
//
//};
//
//
//uintptr_t FindDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets)
//{
//	uintptr_t addr = ptr;
//	for (unsigned int i = 0; i < offsets.size(); ++i)
//	{
//
//		ReadProcessMemory(hProc, (BYTE*)addr, &addr, sizeof(addr), 0);
//
//		addr += offsets[i];
//	}
//	return addr;
//}