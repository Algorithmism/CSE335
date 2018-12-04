/**
 * \file HeadTop.cpp
 *
 * \author Mark Maroki
 */

#include "stdafx.h"
#include "HeadTop.h"

using namespace Gdiplus;


/**
 * Copy Constructor
 * \param name 
 * \param filename 
 */
CHeadTop::CHeadTop(const std::wstring & name, const std::wstring & filename):
	CImageDrawable(name, filename)
{
}


/**
 * Destructor
 */
CHeadTop::~CHeadTop()
{
}

/** Transform a point from a location on the bitmap to
*  a location on the screen.
* \param  p Point to transform
* \returns Transformed point
*/
Gdiplus::Point CHeadTop::TransformPoint(Gdiplus::Point p)
{
	// Make p relative to the image center
	p = p - GetCenter();

	// Rotate as needed and offset
	return RotatePoint(p, mPlacedR) + mPlacedPosition;
}

/**
 * Draw the image drawable
 * \param graphics Graphics context to draw on
 */
void CHeadTop::Draw(Gdiplus::Graphics * graphics)
{
	//RtoD means Radians to degrees (180/pi) 
	const double RtoD = 57.295779513;
	CImageDrawable::Draw(graphics);

	Point p = TransformPoint(Point(68, 64));
	Point p2 = TransformPoint(Point(88, 66));
	Pen pen(Color::Black, 2);
	graphics->DrawLine(&pen, p, p2);

	Point p3 = TransformPoint(Point(40, 69));
	Point p4 = TransformPoint(Point(20, 67));
	Pen pen2(Color::Black, 2);
	graphics->DrawLine(&pen2, p3, p4);

	SolidBrush brush(Color(0, 0, 0));
	float wid = 15.0f;
	float hit = 20.0f;

	auto state = graphics->Save();
	graphics->TranslateTransform(p.X+9,p.Y+18);
	graphics->RotateTransform((float)(-mPlacedR * RtoD));
	graphics->FillEllipse(&brush, -wid / 2, -hit / 2, wid, hit);
	graphics->Restore(state);

	auto state2 = graphics->Save();
	graphics->TranslateTransform(p.X-35, p.Y+18);
	graphics->RotateTransform((float)(-mPlacedR * RtoD));
	graphics->FillEllipse(&brush, -wid / 2, -hit / 2, wid, hit);
	graphics->Restore(state2);

	
}
//
//void CHeadTop::EyeBrow(Gdiplus::Graphics * graphic, int len, int thickness, int placementX, float angle, bool rightBrow)
//{
//
//}
//
//void CHeadTop::Eye(Gdiplus::Graphics * graphic, int eyeX)
//{
//
//}

