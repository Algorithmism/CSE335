/**
 * \file Component.h
 *
 * \author Mark Maroki
 *
 * Component Base Class 
 */

#pragma once
#include <vector>
#include "Polygon.h"

class CWorkingMachine;

/**
 * Describes Component Class
 */
class CComponent : public CPolygon
{
public:
	/** Constructor */
	CComponent();
	/** Destructor */
	virtual ~CComponent();
	
	/** \brief Copy constructor disabled */
	CComponent(const CComponent &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CComponent &) = delete;

	/** \brief Draws position of rotating components
	 *
	 * \param graphics
	 * \param x
	 * \param y 
	 **/
	virtual void Draw(Gdiplus::Graphics *graphics, int x, int y) { CPolygon::DrawPolygon(graphics, x + mPosition.X, y + mPosition.Y); }
	
	/** \brief Sets the machine
	 * \param *machine
	 */
	void SetMachine(CWorkingMachine * machine) { mWorkingMachine = machine; }

	/** \brief Gets the position for motor
	 * \return mPosition*/
	virtual Gdiplus::Point GetPosition() { return mPosition; }

	/**Sets the position of the getter
	 *\param x
	 *\param y */
	void SetPosition(int x, int y);

private:

	/**	mPosition is the position of the component */
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);
	
	///composition connection
	CWorkingMachine * mWorkingMachine = nullptr;



};

