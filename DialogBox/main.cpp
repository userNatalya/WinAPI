#include<Windows.h>
#include"resource.h"
CONST CHAR g_sz_DEFAULT_LOGIN_MESSAGE[] = "??????? ??? ????????????:";
//g-?????????? ??????? ?????????,sz-??????
BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

/*
----------------------
LP - Long Pointer
STR - String
LPSTR - Long pointer to string
----------------------
*/

//#define MESSAGE_BOX

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{

#ifdef MESSAGE_BOX
	MessageBox(NULL, "?????? ???!", "Hello", MB_YESNOCANCEL | MB_ICONINFORMATION | MB_HELP | MB_DEFBUTTON3 | MB_SYSTEMMODAL);
	//NULL - ???????????? ????, NULL ?????? ???????????
	//"?????? ???!" - ?????????
	//"Hello" - ????????? ????
	//MB_OK - ?????, ???????????? ????? ?????? ? ?????? ????
	//????? - ??? ????, ???????????? ??? ????????, ? ??? ???.  
#endif // MESSAGE_BOX

	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, 0);

	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:	//???????????? ??? ??????? ????, ? ????? ????????? ???????? ????
	{
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hwnd, WM_SETICON, 0, (LPARAM)hIcon);

		HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
		SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)g_sz_DEFAULT_LOGIN_MESSAGE);
	}
	break;
	case WM_COMMAND:	//???????????? ????????? ??????? ?? ?????? ? ?.?.
	{
		CONST INT SIZE = 256;
		CHAR sz_buffer[SIZE] = {};
		HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
		HWND hEditPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD);
		switch (LOWORD(wParam))
		{
		case IDC_EDIT_LOGIN:
			if (HIWORD(wParam) == EN_SETFOCUS)
			{
				SendMessage(hEditLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
				if (strcmp(sz_buffer, g_sz_DEFAULT_LOGIN_MESSAGE) == 0)
					SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)"");
			}
			if (HIWORD(wParam) == EN_KILLFOCUS)
			{

				SendMessage(hEditLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
				if (strcmp(sz_buffer, "") == 0)
					SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)g_sz_DEFAULT_LOGIN_MESSAGE);
			}
			break;
		case IDC_BUTTON_Copy:
		{
			SendMessage(hEditLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
			SendMessage(hEditPassword, WM_SETTEXT, 0, (LPARAM)sz_buffer);
		}
		break;
		case IDOK:		MessageBox(hwnd, "???? ?????? ?????? OK", "Info", MB_OK | MB_ICONINFORMATION); break;
		case IDCANCEL:	EndDialog(hwnd, 0); break;
		}
	}
		break;
	case WM_CLOSE:EndDialog(hwnd, 0);
	}

	return FALSE;
}