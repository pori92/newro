#include "winapi.h"
#include "clogproc.h"
#include <stdio.h>
#include "LogToFile.h"
#include "core.h"

#ifdef _GUI

#define LOG_TEXT_LINE 28
#define LOG_TEXT_LENGTH 120

CLogToFile 	gCLogToFile;

char LogText[LOG_TEXT_LINE][LOG_TEXT_LENGTH];
void LogTextAdd(BYTE type, char* msg, int len);

HFONT hFont;
int m_cline;

short LogTextLength[LOG_TEXT_LINE];
BYTE LogTextViewType[LOG_TEXT_LINE];

void loginit()
{
	int n;
	for (n=0;n<LOG_TEXT_LINE;n++)
	{
		memset(&LogText[n],0, sizeof(LogText[0]));
		LogTextLength[n]=0;
		LogTextViewType[n]=0;
	}

	hFont = CreateFontA(16, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
		CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, VARIABLE_PITCH, TEXT("Arial"));

	switch (SERVER_TYPE)
	{
	case ATHENA_SERVER_LOGIN:
		gCLogToFile.Init("Login", ".\\Logs", 1);
		break;
	case ATHENA_SERVER_CHAR:
		gCLogToFile.Init("Char", ".\\Logs", 1);
		break;
	case ATHENA_SERVER_MAP:
		gCLogToFile.Init("Map", ".\\Logs", 1);
		break;
	}
}

void LogAdd(BYTE Color, char* szLog)
{
	char szBufferOut[550] = { 0 };

	SYSTEMTIME tinfo;
	GetLocalTime(&tinfo);

	sprintf_s(szBufferOut, 549, "[%02d-%02d-%02d %02d:%02d:%02d] %s",
		tinfo.wYear,
		tinfo.wMonth,
		tinfo.wDay,
		tinfo.wHour,
		tinfo.wMinute,
		tinfo.wSecond,
		szLog);

	LogTextAdd(Color, szBufferOut, strlen(szBufferOut));
	gCLogToFile.Output2(szBufferOut);
}

void LogAdd2(BYTE Color, char* szLog, ...)
{
	char szBuffer[512]="";
	char szBufferOut[550]="";
	va_list pArguments;
	
	va_start(pArguments, szLog);
	vsprintf(szBuffer, szLog, pArguments);
	va_end(pArguments);
	SYSTEMTIME tinfo;
	GetLocalTime(&tinfo);

	sprintf_s(szBufferOut, 550, "[%02d-%02d-%02d %02d:%02d:%02d] %s",
		tinfo.wYear,
		tinfo.wMonth,
		tinfo.wDay,
		tinfo.wHour,
		tinfo.wMinute,
		tinfo.wSecond,
		szBuffer);

	LogTextAdd(Color, szBufferOut, strlen(szBufferOut));
	gCLogToFile.Output2(szBufferOut);
}

void LogTextAdd(BYTE type, char* msg, int len)
{
	if (len>LOG_TEXT_LENGTH-1)
	{
		len=LOG_TEXT_LENGTH-1;
	}
	m_cline++;
	if (m_cline>LOG_TEXT_LINE-1)
	{
		m_cline=0;
	}
	LogText[m_cline][0]=0;
	memcpy(&LogText[m_cline], msg, len);
	LogText[m_cline][1+len]=0;
	LogText[m_cline][len]=0;
	LogTextLength[m_cline]=len;
	LogTextViewType[m_cline]=type;
}

void LogTextPaint(HWND hWnd)
{
	HDC hdc;
	int total;
	int n;
	
	hdc=GetDC(hWnd);
	total= LOG_TEXT_LINE;

	n=m_cline;

	while(total-- != 0)
	{
		switch (LogTextViewType[n] )
		{
		case HRED:
			SetTextColor(hdc, RGB(255, 0, 0) );	
			break;
		case MGREEN:
			SetTextColor(hdc, RGB(51, 255, 51));
			break;
		case HBLUE:
			SetTextColor(hdc, RGB(0, 255, 255));
			break;
		case MRED:
			SetTextColor(hdc, RGB(200, 0, 0));
			break;
		case MBLUE:
			SetTextColor(hdc, RGB(0, 100, 100));
			break;
		case UKN:
			SetTextColor(hdc, RGB(255, 178, 102));
			break;
		case HBLACK:
			SetTextColor(hdc, RGB(0xee, 0xee, 0xee));
			break;
		default:
			SetTextColor(hdc, RGB(0xee, 0xee, 0xee));
			break;
		}

		SetBkMode(hdc, TRANSPARENT);
		SelectObject(hdc,hFont);

		if (strlen(LogText[n])>1)
		{
			TextOut( hdc, 0, total*15 + 100, LogText[n], strlen(LogText[n])); 
		}
		n--;
		if (n<0)
		{
			n=LOG_TEXT_LINE-1;
		}
		//SetBkMode(hdc, TRANSPARENT);

	}
	ReleaseDC(hWnd, hdc);
}

void MsgBox(char *szlog, ...)
{
	char szBuffer[512]="";
	va_list pArguments;
	va_start(pArguments, szlog);
	vsprintf(szBuffer, szlog, pArguments);
	va_end(pArguments);
	MessageBox(NULL, szBuffer, "error", MB_OK|MB_APPLMODAL);
}

#endif