/**
 * \file ImageDrawable.h
 *
 *
 *
 * \author Mark Maroki
 */

#pragma once
#include "Drawable.h"

#include <memory>
#include <string>

using namespace std;
using namespace Gdiplus;

/**
 * Drwable
 */
class CImageDrawable : public CDrawable
{

public:

	/**Copy constructor */
	CImageDrawable(const std::wstring & name, const std::wstring & filename);

	/** Virtual destructor*/
	virtual ~CImageDrawable();
	///sdfdsf
	void Draw(Gdiplus::Graphics * graphics);
	///asdfadsf
	bool HitTest(Gdiplus::Point pos);

	/** \brief Default constructor disabled */
	CImageDrawable() = delete;
	/** \brief Copy constructor disabled */
	CImageDrawable(const CImageDrawable &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CImageDrawable &) = delete;
	
	/** Set to center
	* \param point 
	* \returns mCenter */
	void SetCenter(Gdiplus::Point point) { mCenter = point; }
	/** Gets the center
	* \returns mCenter */
	Gdiplus::Point GetCenter() { return mCenter; }

protected:
	/// The image for this drawable
	std::unique_ptr<Gdiplus::Bitmap> mImage;
private:
	/// The center for this drawable
	Gdiplus::Point mCenter = Gdiplus::Point(0,0);

};