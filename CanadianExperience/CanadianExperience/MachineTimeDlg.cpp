/**
 * \file MachineTimeDlg.cpp
 *
 * \author Mark Maroki
 */

// MachineTimeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CanadianExperience.h"
#include "MachineTimeDlg.h"
#include "afxdialogex.h"
#include "MachineAdapter.h"


// CMachineTimeDlg dialog

IMPLEMENT_DYNAMIC(CMachineTimeDlg, CDialog)

/**
 * constructor
 * \param pParent 
 */
CMachineTimeDlg::CMachineTimeDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, mStartFrame(0)
	, mEndFrame(0)
{

}

/**
 * destructor
 */
CMachineTimeDlg::~CMachineTimeDlg()
{
}

/**
 * \brief SetAdapter
 * \param pointer 
 */
void CMachineTimeDlg::SetAdapter(CMachineAdapter * pointer)
{
	mAdapter = pointer; ///<pointer
	mStartFrame = mAdapter->GetStartFrame();
	mEndFrame = mAdapter->GetEndFrame();
}

/**
 * Take
 */
void CMachineTimeDlg::Take()
{
	mAdapter->SetStartFrame(mStartFrame); ///< Set the start frame
	mAdapter->SetEndFrame(mEndFrame); ///<set the end frame
}

/**
 * Do the data exchanging
 * \param pDX 
 */
void CMachineTimeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mStartFrame);
	DDV_MinMaxInt(pDX, mStartFrame, 0, 900);
	DDX_Text(pDX, IDC_EDIT2, mEndFrame);
	DDV_MinMaxInt(pDX, mEndFrame, 0, 900);
}


BEGIN_MESSAGE_MAP(CMachineTimeDlg, CDialog)
END_MESSAGE_MAP()