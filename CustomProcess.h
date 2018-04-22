#include <iostream>
#include <windows.h>
#include <tlhelp32.h>

#pragma once

using namespace System;
using namespace System::IO;

ref class CustomProcess
{
public:
	CustomProcess(System::String^ processName, DWORD processID);
	bool injectDLL(System::String^ DLL_PATH);
	static array<CustomProcess^>^ getProcessList();

	System::String^ ToString() override;

private:
	System::String^ _name;
	DWORD _id;

	typedef HINSTANCE (*fpLoadLibrary)(char*);

	value struct NtCreateThreadExBuffer {
		ULONG Size;
		ULONG Unknown1;
		ULONG Unknown2;
		PULONG Unknown3;
		ULONG Unknown4;
		ULONG Unknown5;
		ULONG Unknown6;
		PULONG Unknown7;
		ULONG Unknown8;
	};

	typedef NTSTATUS(WINAPI *LPFUN_NtCreateThreadEx) (
		OUT PHANDLE hThread,
		IN ACCESS_MASK DesiredAccess,
		IN LPVOID ObjectAttributes,
		IN HANDLE ProcessHandle,
		IN LPTHREAD_START_ROUTINE lpStartAddress,
		IN LPVOID lpParameter,
		IN BOOL CreateSuspended,
		IN ULONG StackZeroBits,
		IN ULONG SizeOfStackCommit,
		IN ULONG SizeOfStackReserve,
		OUT LPVOID lpBytesBuffer
		);
	
	void collectGarbage(HANDLE hProcess, HANDLE hRemote, char* ch);
	void copyString(System::String^ str, char* dest);

	HANDLE ntCreateRemoteThreadEx(HANDLE hHandle, LPVOID loadLibAddr, LPVOID dllPathAddr);


};

