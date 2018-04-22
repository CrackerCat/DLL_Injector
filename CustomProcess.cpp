#include "CustomProcess.h"
//Process list maximum size
#define ARRAY_SIZE	300


/**
 * 2 parameters constructor:
 * Process Name and a Process ID
 */
CustomProcess::CustomProcess(System::String^ processName, DWORD processID)
{
	this->_name = processName;
	this->_id = processID;
}

//Inject a given DLL to the process
bool CustomProcess::injectDLL(System::String^ DLL_PATH)
{
	//Handle to the process
	HANDLE hProcess;

	//Handle to the remote thread we'll create
	HANDLE hRemote;

	LPVOID paramAddr;
	// Instance to kernel32.dll - to get the LoadLibraryA function from
	HINSTANCE hDLL = LoadLibraryW(L"KERNEL32");

	//Function pointer to the "LoadLibraryA" function at the kernel32.dll
	fpLoadLibrary loadLibraryAddr = (fpLoadLibrary)GetProcAddress(hDLL, "LoadLibraryA");


	hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, this->_id);
	if (hProcess == nullptr)
		return false;
	
	paramAddr = VirtualAllocEx(hProcess, 0, DLL_PATH->Length + 1, MEM_COMMIT, PAGE_READWRITE);

	if (paramAddr == nullptr)
		CustomProcess::collectGarbage(hProcess, nullptr, nullptr);
	
	//WriteProcessMemory doesn't accepts System::String^ object, so let's convert it to char array
	char* ch = new char[DLL_PATH->Length + 1];
	copyString(DLL_PATH, ch);

	BOOL written = WriteProcessMemory(hProcess, paramAddr, ch, DLL_PATH->Length, NULL);

	if (!written)
	{
		CustomProcess::collectGarbage(hProcess, nullptr, ch);
		return false;
	}

	
	try
	{
		hRemote = CreateRemoteThread(hProcess, 0, 0, (LPTHREAD_START_ROUTINE)loadLibraryAddr, paramAddr, 0, 0);
		if (!hRemote)
			if (!(hRemote = ntCreateRemoteThreadEx(hProcess, (LPTHREAD_START_ROUTINE)loadLibraryAddr, paramAddr)))
			{
				CustomProcess::collectGarbage(hProcess, nullptr, ch);
				return false;
			}
	}
	catch (Exception^ e)
	{
		delete e;
		CustomProcess::collectGarbage(hProcess, hRemote, ch);
		return false;
	}
	CustomProcess::collectGarbage(hProcess, hRemote, ch);

	return true;

}


//Closing Handles and get rid of the memory we allocated for the injectDLL function
void CustomProcess::collectGarbage(HANDLE hProcess, HANDLE hRemote, char* ch)
{
	if (hProcess != nullptr)
		CloseHandle(hProcess);
	if (hRemote != nullptr)
		CloseHandle(hRemote);
	if (ch != nullptr)
		delete ch;
}


/**
 * This function gets a System::String^ Object as a source and a char array as a destination,
 * and copies the chars in the string to the char array
 */
void CustomProcess::copyString(System::String^ str, char* dest)
{
	for (int i = 0; i < str->Length; i++)
		dest[i] = static_cast<char>(str[i]);
}

/**
 * Undocumented DLL Injection function
 */
HANDLE CustomProcess::ntCreateRemoteThreadEx(HANDLE hHandle, LPVOID loadLibAddr, LPVOID dllPathAddr) {

	HANDLE hRemoteThread = NULL;

	LPVOID ntCreateThreadExAddr = NULL;
	DWORD temp1 = 0;
	DWORD temp2 = 0;
	NtCreateThreadExBuffer ntbuffer;
	ntCreateThreadExAddr = GetProcAddress(GetModuleHandle(TEXT("ntdll.dll")), "NtCreateThreadEx");

	// The address of ntCreateThreadEx function is valid (not NULL)
	if (ntCreateThreadExAddr) {

		ntbuffer.Size = sizeof(NtCreateThreadExBuffer);
		ntbuffer.Unknown1 = 0x10003;
		ntbuffer.Unknown2 = 0x8;
		ntbuffer.Unknown3 = &temp2;
		ntbuffer.Unknown4 = 0;
		ntbuffer.Unknown5 = 0x10004;
		ntbuffer.Unknown6 = 4;
		ntbuffer.Unknown7 = &temp1;
		ntbuffer.Unknown8 = 0;

		LPFUN_NtCreateThreadEx funNtCreateThreadEx = (LPFUN_NtCreateThreadEx)ntCreateThreadExAddr;
		NTSTATUS status = funNtCreateThreadEx(
			&hRemoteThread,
			0x1FFFFF,
			NULL,
			hHandle,
			(LPTHREAD_START_ROUTINE)loadLibAddr,
			dllPathAddr,
			FALSE,
			NULL,
			NULL,
			NULL,
			&ntbuffer
			);

		if (hRemoteThread == NULL) 
		{
			// NtCreateRemoteThreadEx Failed!
			return NULL;
		}
		else 
		{
			//NtCreateRemoteThreadEx Succeeded!
			return hRemoteThread;
		}
	}
	return NULL;

}




//Returns description of the Process in this format: "[Process Name] <-> [Process ID]"
System::String^ CustomProcess::ToString()
{
	System::String^ str = this->_name + " <-> " + this->_id;
	return str;
}


//Generates a list of all the running processes in the system
array<CustomProcess^>^ CustomProcess::getProcessList()
{
	array<CustomProcess ^> ^ process_list = gcnew array<CustomProcess ^>(ARRAY_SIZE);
	PROCESSENTRY32 pe32 = { sizeof(PROCESSENTRY32) };
	HANDLE hProcessSnap;
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	int i = 0;
	if (Process32First(hProcessSnap, &pe32))
	{
		do
		{
			process_list[i] = gcnew CustomProcess(gcnew System::String(pe32.szExeFile), pe32.th32ProcessID);
			i++;
		} while (Process32Next(hProcessSnap, &pe32));
	}
	CloseHandle(hProcessSnap);
	return process_list;
}
