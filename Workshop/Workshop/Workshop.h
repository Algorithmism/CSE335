
// Workshop.h : main header file for the Workshop application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


/**
 * \brief Workshop App
 * 
 */
class CWorkshopApp : public CWinApp
{
public:
	/** Constructor*/
	CWorkshopApp();


// Overrides
public:
	/** Bool InitInstance
	 *\return BOOl
	 **/
	virtual BOOL InitInstance(); ///<InitInstance
	
	/** Exit Instance 
	 *\return int */
	virtual int ExitInstance(); ///<ExitInstance

// Implementation

public:
	/** On App About */
	afx_msg void OnAppAbout();
	/** Declare the Message Map */
	DECLARE_MESSAGE_MAP()


private:
    Gdiplus::GdiplusStartupInput gdiplusStartupInput; ///<gdiplusStartupInput
    ULONG_PTR gdiplusToken; ///< gdiplusToken
};

extern CWorkshopApp theApp;
