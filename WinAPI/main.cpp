#include<Windows.h>
#include"resource.h"

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
	MessageBox(NULL, "������ ���!", "Hello", MB_YESNOCANCEL | MB_ICONINFORMATION | MB_HELP | MB_DEFBUTTON3 | MB_SYSTEMMODAL);
	//NULL - ������������ ����, NULL ������ �����������
	//"������ ���!" - ���������
	//"Hello" - ��������� ����
	//MB_OK - �����, ������������ ����� ������ � ������ ����
	//����� - ��� ����, ������������ ��� ��������, � ��� ���.  
#endif // MESSAGE_BOX

	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, 0);

	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:	//������������ ��� ������� ����, � ����� ��������� �������� ����
		break;
	case WM_COMMAND:	//������������ ��������� ������� �� ������ � �.�.
		switch (LOWORD(wParam))
		{
		case IDOK:		MessageBox(hwnd, "���� ������ ������ OK", "Info", MB_OK | MB_ICONINFORMATION); break;
		case IDCANCEL:	EndDialog(hwnd, 0); break;
		}
		break;
	case WM_CLOSE:EndDialog(hwnd, 0);
	}
	return FALSE;
}