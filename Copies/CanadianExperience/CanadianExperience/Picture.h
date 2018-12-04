/**
 * \file Picture.h
 *
 * \author Mark Maroki
 *
 * The picture we are drawing.
 *
 * There will be one picture object that contains all of
 * our actors, which then contains the drawables.
 */

#pragma once

#include <vector>
#include <memory>
class CPictureObserver;
class CActor;

/**
 * Implements the CPicture Class
 */
class CPicture
{
public:
	CPicture();
	virtual ~CPicture();

	/// Copy Constructor (Disabled)
	CPicture(const CPicture &) = delete;
	
	/// Assignment Operator (Disabled)
	void operator=(const CPicture &) = delete;
	
	/** The picture size
	* \returns Size */
	Gdiplus::Size GetSize() { return mSize; }

	/** The picture size
	* \param size The new picture size */
	void SetSize(Gdiplus::Size size) { mSize = size; }
	
	///Add observer to the project for the observers
	void AddObserver(CPictureObserver *observer);
	
	///remove observer from the project
	void RemoveObserver(CPictureObserver *observer);
	
	///Updates the observers
	void UpdateObservers();
	
	///Draws Observers
	void Draw(Gdiplus::Graphics *graphics);
	///Add Actor (for the mem var using shared ptr below)
	void AddActor(std::shared_ptr<CActor> picture);

	/**
	 * Implements iterator for actors
	 */
	class AIterator
	{
	public:
		/**
		 * Constructor
		 * Ideas for this constructor came from the webiste below. 
		 * Source: https://www.cs.helsinki.fi/u/tpkarkka/alglib/k06/lectures/iterators.html#ranges
		 * Section: Ranges: Example: Simple List
		 */
		AIterator(CPicture *picture, int position) : mPicture(picture), mPosition(position) {}

		/**
		 * Operator Overloading Method
		 * Checks if vectors (lists) are not equal
		 * const at end makes it a constant method
		 * \param &other constant vec to reference.
		 * Thank you TAs for giving me the idea to use this
		 * Implementation learned from: https://www.youtube.com/watch?v=2qJhR8cn_Pc
		 */
		bool operator!=(const AIterator& other) const
		{
			//make copies to prevent seg faults/memory issues/accidents
			int posCopy = mPosition;
			int otherCopy = other.mPosition;
			//check copies
			bool checker = posCopy != otherCopy;
			if (checker)
			{
				return checker;
			}
			else
			{
				//returns bool status whether or not position is same
				return posCopy != otherCopy;
			}
		}
		
		/** Gets the value of Actor's position 
		 * \returns the position value at mPosition
		 */
		std::shared_ptr<CActor> operator *() const{ return mPicture->mActors[mPosition]; }
		
		//increments the iterator and returns the iterator's reference
		const AIterator& operator++() { mPosition++; return *this; }

	private:
		CPicture *mPicture;
		int mPosition;

	};

	/** Define beginning and end of iterator
	* Implementation idea came from the following source: https://www.cs.northwestern.edu/~riesbeck/programming/c++/stl-iterator-define.html
	* AIterator accepts two parameters, this is the current picture at the address for pictures, while 0 is the beginning of the vector
	*/
	///This is the begin of iter
	AIterator begin() { return AIterator(this, 0); }
	///This is the end of iter
	AIterator end() { return AIterator(this, mActors.size()); }

private:
	/// The picture size
	Gdiplus::Size mSize = Gdiplus::Size(800, 600);

	/// The observers of this picture
	std::vector<CPictureObserver *> mObservers;

	/// The actors of this picture
	std::vector<std::shared_ptr<CActor>> mActors;
};
/////-------------------------------------------------------------------------------------------------------------------------------------------------
///// beginning of iterator
//AIterator begin() 
//{
//	return AIterator(this, 0);
//
//}
///// end of iterator
//AIterator end()
//{
//
//	return AIterator(this, sizeof(mActors));
//
//}
//NOTE FOR LEARNING: THE ABOVE IMPLEMENTATION DIDNT WORK BECAUSE I USED SIZEOF() WHICH GIVES OUTPUT IN BYTES