/**
 * \file ViewTimeline.h
 *
 * \author Mark Maroki
 *
 * View window for the animation timeline
 */

#pragma once

#include "PictureObserver.h"

class CMainFrame;
class CPicture;

/** View window for the animation timeline */
class CViewTimeline : public CScrollView, public CPictureObserver
{
	DECLARE_DYNCREATE(CViewTimeline)

public:

    static const int Height = 90;      ///< Height to make this window

	/**
	 * Set the mainFrame pointer
	 * \param mainFrame Pointer to the CMainFrame window
	 */
	void SetMainFrame(CMainFrame *mainFrame) { mMainFrame = mainFrame; }

protected:
	CViewTimeline();           /// protected constructor used by dynamic creation
	virtual ~CViewTimeline(); /// destructor


protected:

	virtual void OnDraw(CDC* pDC);      ///< overridden to draw this view
	virtual void OnInitialUpdate();     ///< first time after construct
	
	///Declares message map
	DECLARE_MESSAGE_MAP()

public:
	///erases background
    afx_msg BOOL OnEraseBkgnd(CDC* pDC); ///< CDC *pDC is an entry for deletion of frame
	/// setss key frame on edit
    afx_msg void OnEditSetkeyframe();
	///deletes key frame
    afx_msg void OnEditDeletekeyframe();

	virtual void UpdateObserver() override;
///private
private:
	/// The main frame window that uses this view
	CMainFrame  *mMainFrame = nullptr;

	/// Flag to indicate we are moving the pointer
	bool      mMovingPointer = false;

	/// Bitmap image for the pointer
	std::unique_ptr<Gdiplus::Bitmap> mPointer;
public:
	//afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	
	///checks if mouse left is clicked
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	///checks for mouse movement param nFlags for flagging and param point gets the point
	afx_msg void OnMouseMove
	(
		UINT nFlags, ///</ nFlags sets flags
		CPoint point  ///</ while Cpoint point gets the point 
	);	
};


