/**
 * \file TileFans.cpp
 *
 *	This file creates tiles for Fans.
 *
 * \author Mark Maroki
 */



#include "stdafx.h"
#include "TileFans.h"


using namespace std;
using namespace Gdiplus;

const wstring ImagesDirectory(L"images/");
const wstring FirstImage(L"grass.png");
const wstring HandsDown(L"umguy1.png");
const wstring HandsUp(L"umguy2.png");

/** Constructor
* \param city The city this is a member of
*/
CTileFans::CTileFans(CCity *city) : CTile(city)
{
	SetImage(FirstImage);
	
	LoadImagee(mHandsDown, HandsDown);
	LoadImagee(mHandsUp, HandsUp);
}


/**
*  Destructor
*/
CTileFans::~CTileFans()
{
}

/**  Save this item to an XML node
* \param node The node we are going to be a child of
* \returns Allocated node
*/
std::shared_ptr<xmlnode::CXmlNode> CTileFans::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CTile::XmlSave(node);

	itemNode->SetAttribute(L"type", L"Fans");
	itemNode->SetAttribute(L"file", GetFile());

	return itemNode;
}


/**
* brief Load the attributes for an item node.
* \param node The Xml node we are loading the item from
*/
void CTileFans::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	CTile::XmlLoad(node);
	SetImage(node->GetAttributeValue(L"file", L""));
}

/**
 * Draws the image of the UM guy
 * \param graphics 
 */
void CTileFans::Draw(Gdiplus::Graphics * graphics)
{
	CTile::Draw(graphics);

	if (mState == Down)
	{
		int wid = mHandsDown->GetWidth();
		int hit = mHandsDown->GetHeight();
		graphics->DrawImage(mHandsDown.get(),
			(int)(GetX() - OffsetLeft), (int)(GetY() + OffsetDown - hit),
			wid, hit);
	
	}
	else if (mState == Up )
	{
		int wid = mHandsUp->GetWidth();
		int hit = mHandsUp->GetHeight();

		graphics->DrawImage(mHandsUp.get(),
			(int)(GetX() - OffsetLeft), (int)(GetY() + OffsetDown - hit),
			wid, hit);
	}
}

/**
 * Sets state to down
 */
void CTileFans::upState()
{
	mState = Up;
}

/**
 * Sets State to Down
 */
void CTileFans::downState()
{
	mState = Down;
}
/**
* Load an image into a bitmap
* \param image Image pointer to load
* \param name Filename to load from
*/
void CTileFans::LoadImagee(std::unique_ptr<Gdiplus::Bitmap> &image, std::wstring name)
{
	wstring filename = ImagesDirectory + name;
	image = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (image->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}

/**
 * Updates the tiles based on Owen's website code
 * \param elapsed 
 */
void CTileFans::Update(double elapsed)
{
	CTile::Update(elapsed);

	// when the Surrender Cobra is running...
	// mSpeedX is a constant pixels per second running speed...
	mRunX += mSpeedX * elapsed;
}
