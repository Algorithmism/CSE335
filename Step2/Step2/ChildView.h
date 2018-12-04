/**
 * \file Childview.h
 *
 * \author Mark Maroki
 *
 * Class that implements child window the program draws in.
 *
 * The window is a child of the main frame, which holds
 * the window, the menu bar, and the status bar.
 *
 */


#pragma once
#include "Aquarium.h"

 /**
 * The child window our program draws in.
 */
class CChildView : public CWnd
{
// Construction
public:
	CChildView();
	virtual ~CChildView();
	afx_msg void OnAddfishBetafish();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
private:
	/// An object that describes our aquarium
	CAquarium  mAquarium;
	/// Any item we are currently dragging
	std::shared_ptr<CItem> mGrabbedItem;
	/// True until the first time we draw
	bool mFirstDraw = true;
	long long mLastTime;    ///< Last time we read the timer
	double mTimeFreq;       ///< Rate the timer updates

protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnAddfishDoryfish();
	afx_msg void OnAddfishNemofish();
	afx_msg void OnAddfishKillerkarp();
	afx_msg void OnAdddecorDecorcastle();
	afx_msg void OnFileSaveas();
	afx_msg void OnFileOpen32780();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

