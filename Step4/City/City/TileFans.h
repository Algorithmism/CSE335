/**
 * \file TileFans.h
 *
 * \author Mark Maroki
 *
 * Class that implements Tile Fans
 */



#pragma once
#include "Tile.h"
#include "TileVisitor.h"

class CTileFans : public CTile
{
public:
	CTileFans(CCity *city);

	virtual ~CTileFans();


	///  Default constructor (disabled)
	CTileFans() = delete;

	///  Copy constructor (disabled)
	CTileFans(const CTileFans &) = delete;

	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node);
	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CTileVisitor *visitor) override { visitor->VisitFans(this); }
	

	/**  Draw this item
	* \param graphics The graphics context to draw on */
	virtual void Draw(Gdiplus::Graphics *graphics);
	
	///Gives the states of either hands up or down;
	enum States {Up, Down};

	virtual void upState();
	virtual void downState();

	void LoadImagee(std::unique_ptr<Gdiplus::Bitmap>& image, std::wstring name);

	void Update(double elapsed);

	/// How much we offset drawing the tile to the left of the center
	const static int OffsetLeft = 64;

	/// How much we offset drawing the tile above the center
	const static int OffsetDown = 32;


private:
	///Sets the member var to the first image (Grass tile)
	std::unique_ptr<Gdiplus::Bitmap> mGrass;
	
	///Sets the member var to the second image (Hands Down)
	std::unique_ptr<Gdiplus::Bitmap> mHandsDown;
	
	///Sets the member var to the third image (Hands Up)
	std::unique_ptr<Gdiplus::Bitmap> mHandsUp;
	
	///sets Fan to 0- initialization of location
	int mRunX = 0;

	///Member variable to keep track of states
	States mState = Down;

	///Fan speed in the X direction
	double mSpeedX;

	///Fan speed in the Y direction
	double mSpeedY;

};

