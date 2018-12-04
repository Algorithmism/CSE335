/**
 * \file HeadTop.h
 *
 * \author Mark Maroki
 *
 * 
 */

#pragma once

#include "ImageDrawable.h"

/**
 * HeadTop Class
 */
class CHeadTop : public CImageDrawable
{
public:


	/**Copy constructor */
	CHeadTop(const std::wstring & name, const std::wstring & filename);

	/**Virtual Destructor */
	virtual ~CHeadTop();

	Gdiplus::Point TransformPoint(Gdiplus::Point p);

	virtual void Draw(Gdiplus::Graphics * graphics) override;

	/** Checks if moveable
	* \returns true by default */
	virtual bool IsMovable() override { return true; }
	
	/** Eyebrow function
	* \param graphic, len, thickness, placementX, angle, rightBrow */
	void EyeBrow(Gdiplus::Graphics *graphic, int len, int thickness, int placementX, float angle, bool rightBrow);
	
	/** Checks if moveable
	* \param graphic, eyeX */
	void CHeadTop::Eye(Gdiplus::Graphics *graphic, int eyeX);

//Getters and Setters



private:
	///eyebrow height
	int mBrowHeight;
	///eye height
	int mEyeHeight;
	///Right Brow thickness
	int mBrowThickness;
	///angle of right eyebrow
	float angle;


};

