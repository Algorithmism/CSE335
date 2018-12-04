/**
 * \file PictureObserver.h
 *
 * \author Mark Maroki
 *
 * Observer base class for a picture.
 *
 * This class implements the base class functionality for
 * an observer in the observer pattern.
 */

#pragma once
#include <memory>

using namespace std;

///forward reference(s)
class CPicture;

/**
 * Class that implements the Picture Observer
 */
class CPictureObserver
{
public:
	///virtual destructor
	virtual ~CPictureObserver();

	void SetPicture(std::shared_ptr<CPicture> picture);
	
	/// Copy Constructor (Disabled)
	CPictureObserver(const CPictureObserver &) = delete;
	
	/// Assignment Operator (Disabled)
	void operator=(const CPictureObserver &) = delete;

	/// This function is called to update any observers
	virtual void UpdateObserver() = 0;

	/** Getter for Picture
	* \returns shared_ptr<CPicture> */
	std::shared_ptr<CPicture> GetPicture() { return mPicture; }

protected:
	///constructor made abstract by making it private
	CPictureObserver();

	/// Picture we are observing
	std::shared_ptr<CPicture> mPicture;

};

