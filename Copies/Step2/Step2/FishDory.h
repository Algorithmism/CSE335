/**
 * \file FishBeta.h
 *
 * \author Mark Maroki
 *
 * Class the implements a Beta fish
 */


#pragma once

#include <memory>
#include "Item.h"



/**
 * Implements a Dory fish
 */
class CFishDory : public CItem
{
public:
	CFishDory(CAquarium *aquarium);

	/// Default constructor (disabled)
	CFishDory() = delete;

	/// Copy constructor (disabled)
	CFishDory(const CFishDory &) = delete;

	virtual ~CFishDory();

	bool HitTest(int x, int y);


	virtual void Draw(Gdiplus::Graphics *graphics);

private:
	std::unique_ptr<Gdiplus::Bitmap> mFishImage;

};
