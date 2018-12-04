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

	///override IsMoveable function to return true
	virtual bool IsMovable() override { return true; }
	
	///Function for eyebrows
	void EyeBrow(Gdiplus::Graphics *graphic, int len, int thickness, int placementX, float angle, bool rightBrow);

	///function for the eyes
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

