#pragma once
#ifdef _GUI

class TServerInfoDisplayer
{

public:

	TServerInfoDisplayer();
	virtual ~TServerInfoDisplayer();

	void Run(HWND hWnd);
	void InitGDIObject();
	void DelGDIObject();
	void PaintAllInfo(HWND hWnd, int iTopLeftX, int iTopLeftY);

private:

	HFONT m_hFont;	// 1C
	//HBRUSH m_hNormalBrush;	// 20
	//HBRUSH m_hAbnormalBrush;	// 24
};

extern TServerInfoDisplayer g_ServerInfoDisplayer;
extern int g_Queue[16];
#endif
