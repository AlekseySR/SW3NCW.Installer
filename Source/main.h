#pragma once

#include "resource.h"

class Console
{
public:
	static void HideConsole();
	static void ShowConsole();
	static void SetTextColor(int ColourIndex);
};

class File
{
public:
	static int  FtpGetStatus();
	static int  FileSize(const char* FileName);
	static bool FileExists(const char* FileName);
	static double FtpGetFileSize(char* FileName);
	static void FileQueueSet(wchar_t* DestDir);

private:
	static bool FileDownload(char* FileName);
	static bool FileOpen(char* FileName);
	static int  ShellMoveFiles(const wchar_t* srcPath, const wchar_t* newPath);
};

class Window
{
public:
	static void ChangeLanguage();
	static void EnableButtons(bool Flag);
	static void WindowMenu(HWND hWnd);
	static bool BrowseForFolder();
};

class LOG
{
public:
	// we use 2 same functions with ANSI and UNICODE parameters
	static void InitLog();
	static void ReleaseLog();
	static void LogMessage(const char* message, int ErrorCode, const char* param1, int param2);
	static void LogMessage(const wchar_t* message, int ErrorCode, const wchar_t* param1, int param2);
};

ATOM RegisterMainClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);
BOOL WINAPI CnsHandler(DWORD dwCtrlType);
LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
int CALLBACK BrowsePathProc(HWND hWnd, UINT message, LPARAM lParam, LPARAM pData);