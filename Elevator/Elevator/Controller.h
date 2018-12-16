/**
 * \file Controller.h
 *
 * \author Mark Maroki
 */

#pragma once

#include "ElevatorController.h"
#include "Floor.h"

/**
 * Controller class
 */
class CController : public CElevatorController
{
public:
	/** Constructor */
	CController();

	/** Destructor */
	virtual ~CController();
	
	/** On Open Pressed */
	virtual void OnOpenPressed() override;

	/** Service */
	virtual void Service() override;

	/** On Close Pressed */
	virtual void OnClosePressed() override;
	
	/** The state machine states */
	enum States { Idle, DoorOpening, DoorOpen, DoorClosing, Moving, Stop };

	/** On Panel Floor Pressed */
	virtual void OnPanelFloorPressed(int floor) override;

	/** On Call up Pressed */
	virtual void OnCallUpPressed(int floor) override;

	/**  On Cal Down Pressed */
	virtual void OnCallDownPressed(int floor) override;

	/** What floor to go to */
	virtual int WhatFloorToGoTo();

	/** What Floor Up */
	virtual int WhatFloorUp();
	
	/** What floor down */
	virtual int WhatFloorDown();
private:
	States mState = Idle;   ///< The current state

	double mStateTime = 0;  ///< The time in a current state	
	
	/// An object for each floor
	CFloor mFloors[NumFloors];

	/** Sets the states
	 * \param state	*/
	void SetState(States state);

	int mFloor = 1; ///< The current floor
	bool mGoingUp = true; ///< the machine is going up or not

};

