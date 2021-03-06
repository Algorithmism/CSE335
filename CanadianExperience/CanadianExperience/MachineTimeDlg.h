#pragma once

#include "MachineAdapter.h"

// CMachineTimeDlg dialog

/**
 * Machine Time Dialog 
 */
class CMachineTimeDlg : public CDialog
{
	DECLARE_DYNAMIC(CMachineTimeDlg)

public:
	CMachineTimeDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CMachineTimeDlg();

	void SetAdapter(CMachineAdapter * pointer);
	void Take();


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int mStartFrame; ///< mStartFrame
	int mEndFrame; ///< mEndFrame
private:
	CMachineAdapter *mAdapter = nullptr; ///< *mAdapter
};
