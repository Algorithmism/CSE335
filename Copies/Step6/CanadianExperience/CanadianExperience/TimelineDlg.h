/**
 * \file TimelineDlg.h
 *
 * \author Mark Maroki
 *
 * Describes the dialog box class
 */

#pragma once
#include "Timeline.h"

// CTimelineDlg dialog
/**
 * Timeline Dialog Class describing timelinedlg objects
 */
class CTimelineDlg : public CDialog
{
	DECLARE_DYNAMIC(CTimelineDlg)

public:
	///standard constructor
	CTimelineDlg
	(
		CWnd* pParent = nullptr ///<pParent set as nullptr
	);
	virtual ~CTimelineDlg();

	/** Transfer dialog values to the Timeline object
	*/
	void CTimelineDlg::Take()
	{
		mTimeline->SetNumFrames(mNumFrames);
	}


	/**
	 * Pass a timeline object to this dialog box class.
	 * \param timeline The timeline object.
	 */
	void CTimelineDlg::SetTimeline(CTimeline *timeline)
	{
		mTimeline = timeline;
		mNumFrames = mTimeline->GetNumFrames();
	}

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIMELINEDLG };
#endif

protected:
	///Do data exchanging virtual
	virtual void DoDataExchange
	(
		CDataExchange* pDX  ///< CDataExchange * pDX as entry // DDX/DDV support
	);  

	///Declares message map
	DECLARE_MESSAGE_MAP()
private:
	///number of frames
	int mNumFrames;

	/// The timeline we are editing
	CTimeline *mTimeline = nullptr;

	///frame rate
	int mFrameRate;
};
