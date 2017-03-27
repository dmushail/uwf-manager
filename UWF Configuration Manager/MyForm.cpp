#include "MyForm.h"
#include <string>
#include <windows.h>


using namespace Microsoft::Win32;
using namespace System;
using namespace System::Windows::Forms;


// MSDN ExitWindowsEx Example modifieed to restart users PC.
BOOL MySystemRestart()
{
	HANDLE hToken;
	TOKEN_PRIVILEGES tkp;

	// Get a token for this process. 
	if (!OpenProcessToken(GetCurrentProcess(),
		TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
		return(FALSE);

	// Get the LUID for the shutdown privilege. 
	LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME,
		&tkp.Privileges[0].Luid);

	tkp.PrivilegeCount = 1;  // one privilege to set    
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	// Get the shutdown privilege for this process. 
	AdjustTokenPrivileges(hToken, FALSE, &tkp, 0,
		(PTOKEN_PRIVILEGES)NULL, 0);

	if (GetLastError() != ERROR_SUCCESS)
		return FALSE;

	// Shut down the system and force all applications to close. 
	if (!ExitWindowsEx(EWX_REBOOT | EWX_FORCE, 0))
		return FALSE;

	return TRUE;
}


// Hashing algorith from http://stackoverflow.com/questions/98153/whats-the-best-hashing-algorithm-to-use-on-a-stl-string-when-using-hash-map
unsigned int hash(const char* s, unsigned int seed /*= 0*/)
{
	unsigned int hash = seed;
	while (*s)
	{
		hash = hash * 101 + *s++;
	}
	return hash;
}


//Retrieves hashed key from registry.
int getKey()
{
	HKEY hKey;

	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\UnifiedGUI\\Static\\"), 0, KEY_READ | KEY_WOW64_64KEY, &hKey) != ERROR_SUCCESS)
	{
		MessageBox::Show("Unable to open configuration key!", "UWF Manager", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return 1;
	}

	int val;
	DWORD value_length = sizeof(DWORD);
	RegQueryValueEx(hKey, TEXT("UnifiedWriteFilterConfig"), NULL, NULL, (LPBYTE)&val, &value_length);

	RegCloseKey(hKey);
	return val;
}


//Changes password hash stored in registry to match new password.
int changeKey(int nPass)
{
	HKEY hKey;

	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\UnifiedGUI\\Static\\"), 0, KEY_ALL_ACCESS | KEY_WOW64_64KEY, &hKey) != ERROR_SUCCESS)
	{
		MessageBox::Show("Unable to open configuration key!", "UWF Manager", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return 1;
	}
	
	if (RegSetValueEx(hKey, L"UnifiedWriteFilterConfig", 0, REG_DWORD, (LPBYTE)&nPass, sizeof(DWORD)) != ERROR_SUCCESS)
	{
		MessageBox::Show("Failed to update password!", "UWF Manager", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return 1;
	}
	return 0;
}


//Gets UWF Status from Registry
void getUWF(int& c, int& n)
{
	int current;
	int next;
	HKEY hKey; 
	DWORD value_length = sizeof(DWORD);

	if (RegOpenKey(HKEY_LOCAL_MACHINE, TEXT("SYSTEM\\ControlSet001\\Services\\uwfvol\\Parameters\\Static\\"), &hKey) != ERROR_SUCCESS)
	{
		MessageBox::Show("Unable to open registry key!", "UWF Manager", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	RegQueryValueEx(hKey, TEXT("CurrentSettings"), NULL, NULL, (LPBYTE)&current, &value_length);
	RegQueryValueEx(hKey, TEXT("UpdatedSettings"), NULL, NULL, (LPBYTE)&next, &value_length);

	c = current;
	n = next;

	RegCloseKey(hKey);
}


//Enable/Disable Unified Write Filter via UWFMGR (Requires Reboot)
int setUWF(int set)
{
	SHELLEXECUTEINFO ShExecInfo = { 0 };
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = L"C:\\Windows\\System32\\uwfmgr.exe";
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SWP_HIDEWINDOW;
	ShExecInfo.hInstApp = NULL;

	PVOID OldValue = NULL;
	Wow64DisableWow64FsRedirection(&OldValue);

	if (set == 1)
	{
		ShExecInfo.lpParameters = L"filter enable";
	}

	else if (set == 0)
	{
		ShExecInfo.lpParameters = L"filter disable";
	}
	
	if (ShellExecuteEx(&ShExecInfo))
	{
		WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
		if (MessageBox::Show("The computer must be restarted for changes to take effect. Would you like to restart now?", "UWF Manager", MessageBoxButtons::YesNo, MessageBoxIcon::Information) == DialogResult::Yes)
		{
			MySystemRestart();
			return 0;
		}

		else
		{
			HKEY hKey;
			if (RegOpenKey(HKEY_LOCAL_MACHINE, TEXT("SYSTEM\\ControlSet001\\Services\\uwfvol\\Parameters\\Static\\"), &hKey) != ERROR_SUCCESS)
			{
				MessageBox::Show("Unable to open registry key!", "UWF Manager", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			if (RegSetValueEx(hKey, TEXT("UpdatedSettings"), 0, REG_DWORD, (LPBYTE)&set, sizeof(DWORD)) != ERROR_SUCCESS)
			{
				MessageBox::Show("Failed to update status!", "UWF Manager", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return 1;
			}
			return 0;
		}
	}

	else
	{
		MessageBox::Show("Unable to configure the write filter!", "UWF Manager", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return 1;
	}
}



[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	UWFConfigurationManager::MyForm form;
	Application::Run(%form);
}