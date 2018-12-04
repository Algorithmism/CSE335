/**
 * \file Actor.h
 *
 * \author Mark R. Maroki
 *
 * Class for actors in our drawings
 */

#pragma once

#include <string>
#include <memory>
#include <vector>
#include "Drawable.h"

class CPicture;

 /**
 * Class for actors in our drawings.
 *
 * An actor is some graphical object that consists of
 * one or more parts. Actors can be animated.
 */
class CActor
{
public:
	/**Constructor*/
	CActor(const std::wstring &name);

	/** Default constructor disabled */
	CActor() = delete;
	/** Copy constructor disabled */
	CActor(const CActor &) = delete;
	/** Assignment operator disabled */
	void operator=(const CActor &) = delete;

	virtual ~CActor();

	void SetRoot(std::shared_ptr<CDrawable> root);
	void Draw(Gdiplus::Graphics *graphics);
	std::shared_ptr<CDrawable> HitTest(Gdiplus::Point pos);
	void AddDrawable(std::shared_ptr<CDrawable> drawable);

	/** Sets the picture
	 * \returns picture */
	void SetPicture(CPicture * picture);

	virtual void SetKeyframe();

	virtual void GetKeyframe();

	/** Get the actor name
	 * \returns Actor name */
	std::wstring GetName() const { return mName; }

	/** The actor position
	* \returns The actor position as a point */
	Gdiplus::Point GetPosition() const { return mPosition; }

	/** The actor position
	* \param pos The new actor position */
	void SetPosition(Gdiplus::Point pos) { mPosition = pos; }


	/** Actor is enabled
	* \returns enabled status */
	bool IsEnabled() const { return mEnabled; }

	/** Set Actor Enabled
	* \param enabled New enabled status */
	void SetEnabled(bool enabled) { mEnabled = enabled; }

	/** Actor is clickable
	* \returns true if actor is clickable */
	bool IsClickable() const { return mClickable; }

	/** Actor clickable
	* \param clickable New clickable status */
	void SetClickable(bool clickable) { mClickable = clickable; }


	/** Gets Actor Picture
	* \returns mPicture */
	CPicture* GetPicture() { return mPicture; }

private:
	///mem var for actor name
	std::wstring mName;
	
	///mem var to get bool if enabled or not
	bool mEnabled = true;
	
	///gets position point
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);
	
	///checks if clickable
	bool mClickable = true;

	/// The root drawable
	std::shared_ptr<CDrawable> mRoot;

	/// The drawables in drawing order
	std::vector<std::shared_ptr<CDrawable>> mDrawablesInOrder;

	///mPicture member variable
	CPicture *mPicture = nullptr;

};