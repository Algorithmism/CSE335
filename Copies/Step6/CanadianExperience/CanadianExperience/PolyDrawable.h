/**
 * \file PolyDrawable.h
 *
 * \author Mark Maroki
 * A drawable based on polygon images.
 *
 * This class has a list of points and draws a polygon
 * drawable based on those points.
 * 
 */

#pragma once
#include <string>
#include <vector>
#include "Drawable.h"

/**
 * PolyDrawable Class that describes polydrawable objects
 */
class CPolyDrawable :
	public CDrawable
{
public:

//constructors/destructors
	//copy constructor
	CPolyDrawable(const std::wstring & name);

	//virtual destructor
	virtual ~CPolyDrawable();

//Cleanup
/** Default constructor disabled */
	CPolyDrawable() = delete;
	/** Copy constructor disabled */
	CPolyDrawable(const CPolyDrawable &) = delete;
	/** Assignment operator disabled */
	void operator=(const CPolyDrawable &) = delete;

//Getters and Setters
	
	/** Set the Color
	* \ setss cullah to Gdiplus value*/
	void SetColor(Gdiplus::Color culluh) ///< Color culluh is the color of the actor i need 
	{
		mColor = culluh; ///<mColor is the color of actor
	}

	/** Get the Color angle in radians
	* \returns The color*/
	Gdiplus::Color GetColor() const { return mColor; }

//Other Functionality
	///hit test functionality
	bool HitTest(Gdiplus::Point position);
	
	///draw functionality
	void Draw(Gdiplus::Graphics *graphics);

	/** Adds point at point
	* \param point */
	void AddPoint (Gdiplus::Point point ); 


private:
	/// The polygon color
	Gdiplus::Color mColor = Gdiplus::Color::Cyan;
	
	/// The array of point objects
	std::vector<Gdiplus::Point> mPoints;

};

