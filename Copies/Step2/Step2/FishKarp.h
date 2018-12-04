/**
 * \file FishKarp.h
 *
 * \author Mark Maroki
 *
 * Class the implements a Karp fish
 */

#pragma once

#include <memory>

#include "Item.h"


 /**
  * Implements a Karp fish
  */
class CFishKarp : public CItem
{
public:
	CFishKarp(CAquarium *aquarium);

	/// Default constructor (disabled)
	CFishKarp() = delete;

	/// Copy constructor (disabled)
	CFishKarp(const CFishKarp &) = delete;

	virtual ~CFishKarp();

	bool HitTest(int x, int y);


	virtual void SetLocation(double x, double y);

	virtual void Draw(Gdiplus::Graphics *graphics);

private:
	std::unique_ptr<Gdiplus::Bitmap> mFishImage;

};
