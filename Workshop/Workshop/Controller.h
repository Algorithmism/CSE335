/**
 * \file Controller.h
 *
 * \author 
 *
 * 
 */

#include "WorkshopController.h"

 /// The time the door remains open
const double BagRunningTime = 2.0;

#pragma once


/**
 * Controller class
 */
class CController :
    public CWorkshopController
{
public:
	/** Constructor */
    CController();
	
	/**Destruct*/
    virtual ~CController();
	
	/**Initialize*/
    virtual void Initialize() override;
	
	/** On Next Pressed*/
    virtual void OnNextPressed() override;

    virtual void OnNaughtyPressed() override;
    virtual void OnShipPressed() override;
    virtual void Service() override;
    virtual void OnGiftSelected(int col, int row) override;

	/** The state machine states */
	enum States { Idle, SelectingGift, FillingGift, FillingCoal, ShippingBag, ClawMovingDiag, BagFilled, BagPositioning, ClawMovingHoriz, ClawMovingVerti, BagMoving};

private:
	States mState = Idle; ///< The current state
	
	double mStateTime = 0; ///< The time in a current state	
							
	/** Sets the states
	 * \param state	*/
	void SetState(States state);

	int mPosition = 1; ///< The current floor

	bool mCoalLoaded = true; ///< Check if the coal is loaded

	int mCol; ///< column

	int mRow; ///< row
	
	double mSpeedX = 0; ///<SpeedX
	 
	double mSpeedY = 0; ///<SpeedY

};

