/**
 * \file Fish.cpp
 *
 * Attributes and functionality for fish 
 * \author Mark Maroki
 */

#include "stdafx.h"
#include "Fish.h"
#include "XmlNode.h"

using namespace xmlnode;

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 50;
/// Maximum speed in the Y direction in
/// in pixels per second
const double MaxSpeedY = 50;
/// Minimum speed in the X direction
/// in pixels per second
const double MinSpeedX = 1;
/// Minimum speed in the Y direction
/// in pixels per second
const double MinSpeedY = 1;


/// Distance of 25 pixels from end of background
const int BackgroundDistance = 10;
/// Beginning of the aquarium for the x coordinate
const double AquariumOrigin = 0;

/**
 * Constructor
 * \param aquarium The aquarium we are in
 * \param filename Filename for the image we use
 */
CFish::CFish(CAquarium *aquarium, const std::wstring &filename) :
	CItem(aquarium, filename)
{
	mSpeedX = ((double)rand() / RAND_MAX) * MaxSpeedX;
	mSpeedY = ((double)rand() / RAND_MAX) * MaxSpeedY;

}

/**
 * Handle updates in time of our fish
 *
 * This is called before we draw and allows us to
 * move our fish. We add our speed times the amount
 * of time that has elapsed.
 * \param elapsed Time elapsed since the class call
 */
void CFish::Update(double elapsed)
{
	SetLocation(GetX() + mSpeedX * elapsed,
		GetY() + mSpeedY * elapsed);

	if (mSpeedX > 0 && GetX() >= (GetAquarium()->GetWidth()) + (BackgroundDistance - (GetWidth())))
	{
		mSpeedX = -mSpeedX;
		SetMirror(mSpeedX < 0);
	}

	else if (mSpeedX < 0 && GetX() <= (AquariumOrigin + BackgroundDistance + (GetWidth())))
	{
		mSpeedX = -mSpeedX;
		SetMirror(mSpeedX < 0);
	}
	//Thanks again to the TAs who helped lead me to this result
	if (mSpeedY > 0 && GetY() >= (GetAquarium()->GetHeight()) - (BackgroundDistance + (GetWidth())))
	{
		mSpeedY = -mSpeedY;
	}

	else if (mSpeedY < 0 && GetY() <= (AquariumOrigin + BackgroundDistance + (GetHeight())))
	{
		mSpeedY = -mSpeedY;
	}
}

/**
* Save this item to an XML node
* \param node The node we are going to be a child of
* \return xmlnode ptr
*/
std::shared_ptr<xmlnode::CXmlNode>
CFish::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CItem::XmlSave(node);

	itemNode->SetAttribute(L"speedX", mSpeedX);
	itemNode->SetAttribute(L"speedY", mSpeedY);
	SetMirror(false);

	return itemNode;
}

/**
* Load the attributes for an item node.
*
* This is the  base class version that loads the attributes
* common to all items. Override this to load custom attributes
* for specific items.
*
* \param node The Xml node we are loading the item from
*/
void CFish::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	CItem::XmlLoad(node);
	mSpeedX = node->GetAttributeDoubleValue(L"speedX", mSpeedX);
	mSpeedY = node->GetAttributeDoubleValue(L"speedY", mSpeedY);
	SetMirror(false);
}

/**
* Changes fish speed based on minimum and maximum speeds set.
* \param SpeedX, SpeedY
*/
void CFish::ChangeSpeed(int SpeedX, int SpeedY)
{
	mSpeedX = MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX);
	mSpeedY = MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY);
}

