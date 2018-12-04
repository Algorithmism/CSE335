/**
 * \file Item.h
 *
 * \author Mark Maroki
 *
 * Base class for any item in our aquarium.
 */

#pragma once

#include <string>
#include <memory>
#include "XmlNode.h"
#include "Aquarium.h"

using namespace xmlnode;
class CAquarium;

/**
 * Base class for any item in our aquarium.
 */
class CItem
{
public:
	/// Default constructor (disabled)
	CItem() = delete;

	/// Copy constructor (disabled)
	CItem(const CItem &) = delete;

	virtual ~CItem();

	/// Get the pointer to the CAquarium object
	/// \return Pointer to CAquarium object
	CAquarium *GetAquarium() { return mAquarium; }
	
	/** The X location of the item
	 * \returns X location in pixels */
	double GetX() const { return mX; }

	/** The Y location of the item
	* \returns Y location in pixels */
	double GetY() const { return mY; }

	/** Set the item location
	 * \param x X location
	 * \param y Y location */
	void SetLocation(double x, double y) { mX = x; mY = y; }

	virtual void Draw(Gdiplus::Graphics *graphics);

	virtual bool HitTest(int x, int y);
	/// Handle updates for animation
	/// \param elapsed The time since the last update
	virtual void Update(double elapsed) {}

	/** Gets the height of the image
	* \returns height in pixels */
	int GetHeight() const { return mItemImage->GetHeight(); }
	
	/** Gets the width of the image
	* \returns width in pixels */
	int GetWidth() const { return mItemImage->GetWidth(); }


	/// Set the mirror status
	/// \param m New mirror flag
	void SetMirror(bool m) { mMirror = m; }

	///made virtual similar to other examples in the step assignment
	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node);

	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

protected:
	CItem(CAquarium *aquarium, const std::wstring &filename);

private:
	/// The aquarium this item is contained in
	CAquarium   *mAquarium;

	// Item location in the aquarium
	double   mX = 0;     ///< X location for the center of the item
	
	double   mY = 0;     ///< Y location for the center of the item
	
	bool mMirror = false;   ///< True mirrors the item image
	
	/// The image of this fish
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;

};