#include <windows.h>
#include <iostream>


BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
	const char* targetTitle = (const char*)lParam;
	char title[9000];
	GetWindowTextA(hwnd, title, sizeof(title));

	if (strstr(title, targetTitle) != NULL) {
		// Bring the window to the front
		SetForegroundWindow(hwnd);

		// Stop enumeration
		return FALSE; 
	}

	// Continue enumeration
	return TRUE; 
}

int main(int argc, char** argv) {

	if (argc != 2) {
		printf("provide a string that will be searched in window titles\n");
	}

	const char* target_title_substring = argv[1];

	// Enumerate all top-level windows
	EnumWindows(EnumWindowsProc, (LPARAM)target_title_substring);

	return 0;
}
