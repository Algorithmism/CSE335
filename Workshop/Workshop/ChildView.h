
// ChildView.h : interface of the CChildView class
//


#pragma once


// CChildView window

/**
 * ChildView Derived from CWnd
 */
class CChildView : public CWnd
{
// Construction
public:
	/** Constructor */
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	/** On Paint*/
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

