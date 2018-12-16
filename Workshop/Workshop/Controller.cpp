/**
 * \file Controller.cpp
 *
 * \author
 */

#include "stdafx.h"
#include "Controller.h"
#include "Claw.h"
#include "WorkshopController.h"



/**
 * Constructor
 */
CController::CController()
{
}

/**
 * Destructor
 */
CController::~CController()
{
}


/** Initialization function.
*
* This function is called when the system is initialized. This is
* later than when it is constructed, since the controller is not installed on
* a workshop when it is constructed. This function is called when the workshop
* controller is installed and ready to control a workshop.
*/
void CController::Initialize()
{


}


/** Service the workshop.
*
* This function is called once every millisecond during workshop
* operation. It provides a place to put code the controls the
* workshop. Override in a local function.
*/
void CController::Service()
{
	// Increment state time by 1 millisecond
	mStateTime += 0.001;
	auto claw = GetClaw();

	switch (mState)
	{
	case SelectingGift:

		EnableButtonNext(false);
		if (GetBagPosition() < 0)
		{
			SetConveyerSpeed(0);
			EnableButtonNaughty(true);
		}
		break;
	case BagMoving:
		if (GetBagPosition() < 0)
		{
		
			SetConveyerSpeed(0);
		
		}



	case FillingCoal:
		EnableButtonNaughty(false);


	case ShippingBag:

		if (mCoalLoaded == true && IsCoalLoaded() == true)
		{
			EnableButtonNaughty(false);
			EnableButtonShip(true);
		}

		if (GetBagPosition() > 1)
		{
			SetConveyerSpeed(0);
			EnableButtonNext(true);
			EnableButtonShip(false);
			SetState(Idle);
		}


	case ClawMovingDiag:
		if (mSpeedX < 0 && claw->GetX() <= mCol)
			SetState(ClawMovingVerti);

		else if (mSpeedY < 0 && claw->GetY() <= mRow)
			SetState(ClawMovingHoriz);



		break;
	}

}


/**
* Indication that the Next On List button has been pressed
*
* This function is called whenever the Next On List button is pressed.
* It is only called if the button is enabled.
*/
void CController::OnNextPressed() 
{
	switch (mState)
	{
	case Idle:
		SetState(SelectingGift);
		EnableButtonNaughty(false);
		EnableButtonNext(false);
		EnableButtonShip(false);
		break;
	

	default:
		break;
	}
}

/**
* Indication that the Naughty button has been pressed
*
* This function is called whenever the Naughty button is pressed.
* It is only called if the button is enabled.
*/
void CController::OnNaughtyPressed() 
{
	switch (mState) 
	{
	case SelectingGift:
		SetState(FillingCoal);
		EnableButtonNaughty(false);

	case FillingCoal:
		SetState(ShippingBag);

	}

}

/**
* Indication that the Ship button has been pressed
*
* This function is called whenever the Ship button is pressed.
* It is only called if the button is enabled.
*/
void CController::OnShipPressed() 
{
	switch (mState)
	{
	
	case ShippingBag:
		SetConveyerSpeed(1);

	}

}

/**
* Indication that a Gift has been clicked on
*
* This functin is called whenever the user clicks on
* any of the gifts.
* \param col Column clicked on, left is 0, right is 3
* \param row Row clicked on. Bottom row is 0, top is 3
*/
void CController::OnGiftSelected(int col, int row)
{
	switch (mState)
	{
	case BagPositioning:
		mRow = row;
		mCol = col;
		SetState(ClawMovingDiag);
	default:
		break;
	}

}

void CController::SetState(States state)
{
	mState = state;
	mStateTime = 0;

	switch (mState)
	{
	case Idle:
		EnableButtonNext(true);
		break;

	case SelectingGift:
		SetConveyerSpeed(-1);
		break;

	case FillingCoal:
		LoadCoal();
		
		break;
	case FillingGift:
		break;

	}
}
