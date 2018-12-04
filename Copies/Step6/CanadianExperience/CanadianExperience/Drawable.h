/**
 * \file Drawable.h
 *
 * Class for actors in our drawings.
 * An actor is some graphical object that consists of 
 * one or more parts. Actors can be animated.
 *
 * \author Mark Maroki
 * Abstract base class for drawable elements of our picture
 * 
 */


#pragma once

#include <memory>
#include <string>
#include <vector>
#include "AnimChannelAngle.h"

class CActor;
class CAnimChannelAngle;
class CTimeline;

/**
 * Abstract base class for drawable elements of our picture
 */
class CDrawable
{
public:
	//virtual destructor
	virtual ~CDrawable();

	/** Default constructor disabled */
	CDrawable() = delete;

	/** Copy constructor disabled */
	CDrawable(const CDrawable &) = delete;

	/** Assignment operator disabled */
	void operator=(const CDrawable &) = delete;

	void SetActor(CActor *actor);
	/** Check to draw
	* \param graphics
	* \returns 0 to make it virtual*/
	virtual void Draw ( Gdiplus::Graphics *graphics) = 0;

	void Place(Gdiplus::Point offset, double rotate);
	void AddChild(std::shared_ptr<CDrawable> child);
	
	/** Checks if moveable
	* \param pos
	* \returns 0 to make it virtual*/
	virtual bool HitTest( Gdiplus::Point pos ) = 0;

	/** Checks if moveable
	* \returns false by default*/
	virtual bool IsMovable() { return false; }
	void Move(Gdiplus::Point delta);

	/** Set the drawable position
	 * \param pos The new drawable position*/
	void SetPosition(Gdiplus::Point pos) { mPosition = pos; }

	/** Get the drawable position
	 * \returns The drawable position*/
	Gdiplus::Point GetPosition() const { return mPosition; }

	/** Set the rotation angle in radians
	* \param r The new rotation angle in radians*/
	void SetRotation(double r) { mRotation = r; }

	/** Get the rotation angle in radians
	* \returns The rotation angle in radians*/
	double GetRotation() const { return mRotation; }

	/** Get the drawable name
	* \returns The drawable name */
	std::wstring GetName() const { return mName; }

	/** Gets the parent
	* \returns parent mem var */
	CDrawable* GetParent() { return mParent; }

	/** Sets the parent
	* \param parent is the parent*/
	void SetParent(CDrawable *parent) { mParent = parent; }
	
	/** Sets Timeline 
	* \param timeline is the timeline from CTimeline*/
	virtual void SetTimeline(CTimeline * timeline);
	
	/** Sets Keframe  */
	virtual void SetKeyframe();

	/** Gets Keyframe */
	virtual void GetKeyframe();

	/** The angle animation channel
	 * \returns Pointer to animation channel */
	CAnimChannelAngle *GetAngleChannel() { return &mChannel; }


protected:

	///CDrawable 
	CDrawable(const std::wstring &name);
	
	///RotatePoint 
	Gdiplus::Point RotatePoint(Gdiplus::Point point, double angle);

	/// The actual postion in the drawing
	Gdiplus::Point mPlacedPosition = Gdiplus::Point(0, 0);

	/// The actual rotation in the drawing
	double mPlacedR = 0;

private:
	/// The drawable name
	std::wstring mName;

	/// The position of this drawable relative to its parent
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);

	/// The rotation of this drawable relative to its parent
	double mRotation = 0;

	/// The actor 
	CActor *mActor = nullptr;
	///The parent
	CDrawable *mParent = nullptr;

	/// The children in children order
	std::vector<std::shared_ptr<CDrawable>> mChildren;

	/// The animation channel for animating the angle of this drawable
	CAnimChannelAngle mChannel;

};

