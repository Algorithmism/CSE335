/**
 * \file PolyDrawable.cpp
 *
 * \author Mark Maroki
 *
 * Implements polydrawable class
 */



#include "stdafx.h"
#include <vector>

#include "PolyDrawable.h"

using namespace Gdiplus;
using namespace std;

/**
 * Constructor
 * \param name The drawable name
 */
CPolyDrawable::CPolyDrawable(const std::wstring &name) : CDrawable(name)
{



}


/**
 * Destructor
 */
CPolyDrawable::~CPolyDrawable()
{



}

/** Test to see if we hit this object with a mouse click
 * \param pos Click position
 * \returns true it hit
 */
bool CPolyDrawable::HitTest(Gdiplus::Point pos)
{
	// Transform the points
	vector<Point> points;
	for (auto point : mPoints)
	{
		points.push_back(RotatePoint(point, mPlacedR) + mPlacedPosition);
	}

	GraphicsPath path;
	path.AddPolygon(&points[0], (int)points.size());
	return path.IsVisible(pos) ? true : false;
}

/** Draw our polygon.
 * \param  graphics The graphics context to draw on
 */
void CPolyDrawable::Draw(Gdiplus::Graphics *graphics)
{
	SolidBrush brush(mColor);

	// Transform the points
	vector<Point> points;
	for (auto point : mPoints)
	{
		points.push_back(RotatePoint(point, mPlacedR) + mPlacedPosition);
	}

	graphics->FillPolygon(&brush, &points[0], (int)points.size());
}

void CPolyDrawable::AddPoint(Gdiplus::Point point)
{
	mPoints.push_back(point);
}
