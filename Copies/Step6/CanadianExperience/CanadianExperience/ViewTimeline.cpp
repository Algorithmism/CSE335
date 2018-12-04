/**
 * \file ViewTimeline.cpp
 *
 * \author Mark Maroki
 */


#include "stdafx.h"
#include <sstream>
#include "CanadianExperience.h"
#include "ViewTimeline.h"
#include "DoubleBufferDC.h"
#include "Picture.h"
#include "MainFrm.h"
#include "Timeline.h"
#include "Actor.h"

using namespace std;
using namespace Gdiplus;


IMPLEMENT_DYNCREATE(CViewTimeline, CScrollView)


/// The window height in pixels
const int WindowHeight = 60;

/// The spacing from the top of the 
/// window to the top of the tick marks in pixels
const int BorderTop = 20;

/// Space to the left of the scale in pixels
const int BorderLeft = 10;

/// Space to the right of the scale in pixels
const int BorderRight = 10;

/// The spacing between ticks on the timeline in pixels
const int TickSpacing = 3;

/// The length of a short tick mark in pixels
const int TickShort = 10;

/// The length of a long tick mark in pixels
const int TickLong = 20;

///The length of a tick space to adjust for formatting
const int TickMoveSpace = 10;



/** Constructor */
CViewTimeline::CViewTimeline()
{
	mPointer = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/pointer-down.png"));
	assert(mPointer->GetLastStatus() == Ok);
}

/** Destructor */
CViewTimeline::~CViewTimeline()
{
}




/** Handle the initial update for this window */
void CViewTimeline::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

    int sbHeight = GetSystemMetrics(SM_CXHSCROLL);
    CSize sizeTotal(200, Height - sbHeight - 20);
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/** Draw this window 
 * \param pDC Device context */
void CViewTimeline::OnDraw(CDC* pDC)
{
	// Get the timeline
	CTimeline *timeline = GetPicture()->GetTimeline();

	// Set the scroll system correctly
	CSize totalSize(timeline->GetNumFrames() * TickSpacing + BorderRight + BorderLeft, WindowHeight);
	SetScrollSizes(MM_TEXT, totalSize);

    CDoubleBufferDC dbDC(pDC);

    Graphics graphics(dbDC.m_hDC);    // Create GDI+ graphics context
	CRect rect;
	GetClientRect(&rect);
	int hit = rect.Height();
	int wid = rect.Width();

	Pen pen(Color(0, 128, 0), 1);
	graphics.DrawRectangle(&pen, 10, 10, 200, 60);

	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 16);
///SPECIAL THANK YOU TO THE TAs THAT HELPED ME WITH THIS PORTION!!
	for (int i = 0; i < timeline->GetNumFrames(); i++) 
	{
		// Convert the tick number to seconds in a string
		std::wstringstream str;
		str << i / timeline->GetFrameRate();
		std::wstring wstr = str.str();

		RectF size;
		PointF origin(0.0f, 0.0f);
		graphics.MeasureString(wstr.c_str(), wstr.size(),
			&font, origin, &size);
	
		bool onSecond = (i % timeline->GetFrameRate()) == 0;

		if (onSecond)
		{
			SolidBrush brush(Color(0, 0, 0));
			graphics.DrawString(wstr.c_str(), -1, &font,  
				PointF(BorderLeft + TickSpacing* i-4, hit - ( TickMoveSpace + 15 + TickLong)),
				&brush);    // The brush to draw the text with
			///draws large dashes (Special thank you to the TAs that helped me with this task)
			graphics.DrawLine(&pen, BorderLeft + TickSpacing*i, hit  - (TickLong + TickMoveSpace), TickSpacing*i + BorderLeft, hit - TickMoveSpace);
		}
		else
		{
			///draws small ticks
			graphics.DrawLine(&pen, BorderLeft + TickSpacing*i, hit - TickShort-TickMoveSpace  , BorderLeft + TickSpacing*i, hit - TickMoveSpace);
		}
	

	}
	///draws/sets the pointer
	graphics.DrawImage(mPointer.get(), BorderLeft + (TickSpacing * timeline -> GetCurrentTime()*timeline -> GetFrameRate()) - 4, hit - TickLong - TickMoveSpace, mPointer->GetWidth(), mPointer->GetHeight());
}


/** Erase the background
 *
 * This is disabled to eliminate flicker
 * \param pDC Device context 
 * \return FALSE */
BOOL CViewTimeline::OnEraseBkgnd(CDC* pDC)
{
    return FALSE;
}

 /** Handle a press of the keyframe set button on the toolbar
 */
 void CViewTimeline::OnEditSetkeyframe()
 {
	 for (auto actor : *GetPicture())
	 {
		 actor->SetKeyframe();
	 }
 }
 /** 
 * Handles deletion of key frames
 */
 void CViewTimeline::OnEditDeletekeyframe()
 {
 }
 
 /**
  * Force an update of this window when the picture changes.
  */
 void CViewTimeline::UpdateObserver()
 {
	 Invalidate();
	 UpdateWindow();
 }

 // Doxygen sometimes gets confused by these message 
 // maps, since they look like functions. I've found
 // it helps to move them to the end of the file.
 BEGIN_MESSAGE_MAP(CViewTimeline, CScrollView)
	 ON_WM_CREATE()
	 ON_WM_ERASEBKGND()
	 ON_COMMAND(ID_EDIT_SETKEYFRAME, &CViewTimeline::OnEditSetkeyframe)
	 ON_COMMAND(ID_EDIT_DELETEKEYFRAME, &CViewTimeline::OnEditDeletekeyframe)
//	 ON_WM_MOUSEMOVE()
	 ON_WM_LBUTTONDOWN()
	 ON_WM_MOUSEMOVE()
 END_MESSAGE_MAP()



/**
 * Left click check to see if the point works \
   based on value given for current time
 * \param nFlags 
 * \param point 
 */
 void CViewTimeline::OnLButtonDown(UINT nFlags, CPoint point)
 {
	 // Convert mouse coordinates to logical coordinates
	 CClientDC dc(this);
	 OnPrepareDC(&dc);
	 dc.DPtoLP(&point);

	 int x = point.x;

	 // Get the timeline
	 CTimeline *timeline = GetPicture()->GetTimeline();
	 int pointerX = (int)(timeline->GetCurrentTime() *
		 timeline->GetFrameRate() * TickSpacing + BorderLeft);

	 mMovingPointer = x >= pointerX - (int)mPointer->GetWidth() / 2 &&
		 x <= pointerX + (int)mPointer->GetWidth() / 2;

	 __super::OnLButtonDown(nFlags, point);
 }


 void CViewTimeline::OnMouseMove(UINT nFlags, CPoint point)
 {
	 // Convert mouse coordinates to logical coordinates
	 CClientDC dc(this);
	 OnPrepareDC(&dc);
	 dc.DPtoLP(&point);


	 int x = point.x;

	 // Get the timeline
	 CTimeline *timeline = GetPicture()->GetTimeline();

	 float pointerX = ((float)x - (float)BorderLeft) / ((float)TickSpacing * (float)timeline->GetFrameRate());

	 mMovingPointer = x >= pointerX - (int)mPointer->GetWidth() / 2 &&
		 x <= pointerX + (int)mPointer->GetWidth() / 2;
	
	 ///THANK you TAs for helping me with this
	 if ((GetKeyState(VK_LBUTTON) & (int)256) != 0)
	 {
		 if (pointerX >= 0 && pointerX < timeline->GetDuration())
		 {
			 mPicture->SetAnimationTime(pointerX);
		 }

		 if (pointerX < 0)
		 {
			 pointerX = 0.0;
		 }

		 if (pointerX > timeline->GetDuration())
		 {
			 pointerX = (timeline->GetDuration());
		 }
	 }

	 __super::OnMouseMove(nFlags, point);
 }
