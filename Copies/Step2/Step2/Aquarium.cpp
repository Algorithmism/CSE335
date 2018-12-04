/**
 * \file Aquarium.cpp
 *
 * \author Mark Maroki
 */

#include "stdafx.h"
#include <string>
#include <memory>
#include <algorithm>
#include "Aquarium.h"
#include "Item.h"
#include "FishBeta.h"
#include "FishDory.h"

using namespace std;
using namespace Gdiplus;

/**
 * Constructor
 */
CAquarium::CAquarium()
{
	mBackground = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/background1.png"));
	if (mBackground->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/background1.png");
	}
}


/**
 * Destructor
 */
CAquarium::~CAquarium()
{
}

/** Draw the aquarium
* \param graphics The GDI+ graphics context to draw on
*/
void CAquarium::OnDraw(Gdiplus::Graphics *graphics)
{
	graphics->DrawImage(mBackground.get(), 0, 0,
		mBackground->GetWidth(), mBackground->GetHeight());

	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 16);

	SolidBrush green(Color(0, 64, 0));
	graphics->DrawString(L"Under the Sea!", -1, &font, PointF(2, 2), &green);

	for (auto item : mItems)
	{
		item->Draw(graphics);
	}
}

/**
 * Add an item to the aquarium
 * \param item New item to add
 */
void CAquarium::Add(std::shared_ptr<CItem> item)
{
	mItems.push_back(item);
}

/** Test an x,y click location to see if it clicked
* on some item in the aquarium.
* \param x X location
* \param y Y location
* \returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<CItem> CAquarium::HitTest(int x, int y)
{
	for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
	{
		if ((*i)->HitTest(x, y))
		{
			return *i;
		}
	}

	return  nullptr;
}

/**
 * Function to push to front of list
 * \param item 
 */
void CAquarium::PushToFront(std::shared_ptr<CItem> item)
{
	auto loc = find(begin(mItems), end(mItems), item);
	if (loc != end(mItems))
	{
		mItems.erase(loc);
		mItems.push_back(item);
	}
}


/**
 * We are passed a pointer to a fish that eats. We check to see
 * if there are any fish it is currently over. If so, eat them!
 * \param item Item we are testing
 * \returns true if a fish is eaten
 */
bool CAquarium::Killing(CItem *eater)
{
	for (auto other : mItems)
	{
		// Do not compare to ourselves
		if (other.get() == eater) {
			continue;
		}

		if (other->HitTest((int)eater->GetX(), (int)eater->GetY()))
		{
			auto loc = find(begin(mItems), end(mItems), other);
			if (loc != end(mItems))
			{
				mItems.erase(loc);
			}

			return true;
		}

	}
	return false;
}