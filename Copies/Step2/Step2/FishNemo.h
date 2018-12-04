/**
 * \file FishNemo.h
 *
 * \author Charles B. Owen
 *
 * Class the implements a Nemo fish
 */

#pragma once

#include <memory>

#include "Item.h"


 /**
  * Implements a Nemo fish
  */
class CFishNemo : public CItem
{
public:
	CFishNemo(CAquarium *aquarium);

	/// Default constructor (disabled)
	CFishNemo() = delete;

	/// Copy constructor (disabled)
	CFishNemo(const CFishNemo &) = delete;

	virtual ~CFishNemo();

	bool HitTest(int x, int y);


	virtual void Draw(Gdiplus::Graphics *graphics);

private:
	std::unique_ptr<Gdiplus::Bitmap> mFishImage;

};
