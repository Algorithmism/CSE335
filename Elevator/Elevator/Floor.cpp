/**
 * \file Floor.cpp
 *
 * \author Mark Maroki
 */

#include "stdafx.h"
#include "Floor.h"
#include "Controller.h"

/**
 * Constructor
 */
CFloor::CFloor()
{
}


/**
 * Destructor
 */
CFloor::~CFloor()
{
}

/** Set the value of Up for a floor.
 * \param s */
void CFloor::SetUp(bool s)
{
	mUp = s;
	mController->SetCallLight(mFloor, CElevatorController::Up, mUp);
}

/**
 * Set Down
 * \param down 
 */
void CFloor::SetDown(bool down)
{
	mDown = down;
	mController->SetCallLight(mFloor, CElevatorController::Down, mDown);
}

/** Set the value of Panel for a floor.
 * \param p The new value for mPanel
 */
void CFloor::SetPanel(bool p)
{
	mPanel = p;
	mController->SetPanelFloorLight(mFloor, mPanel);
}

