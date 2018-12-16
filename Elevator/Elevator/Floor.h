/**
 * \file Floor.h
 *
 * \author Mark Maroki
 *
 * 
 */
#pragma once
#include "ElevatorController.h"

class CController;

/**
 * Floor Class
 */
class CFloor
{
public:
	/** Constructor */
	CFloor();

	/** Destructor */
	virtual ~CFloor();
	
	/** Setter for mUp */
	void SetUp(bool s);

	/** GetUp from the SetUp
	 *\return mUp	*/
	bool GetUp() { return mUp; }

	/** Setter for mDown
	 *\param down */
	void SetDown(bool down);

	/** GetUp from the SetUp
	 *\return mUp	*/
	bool GetDown() { return mDown; }

	/** Setter for mPanel */
	void SetPanel(bool panel);

	/** GetUp from the GetPanel
	 *\return mPanel	*/
	bool GetPanel() { return mPanel; }

	/** Setter for mFloor
	 *\param floor */
	void SetFloor(int floor) { mFloor = floor; } ///<mFloor is floor

	/** GetUp from the SetUp
	 *\return mUp	*/
	int GetFloor() { return mFloor; }

	/** Sets the Controller
	 *\param *controller	*/
	void SetController(CController *controller) { mController = controller; } ///< mController = controller

private:

	bool mUp = false; ///< mUp
	bool mDown = false; ///< mDown
	bool mPanel = false; ///< mPanel
	int mFloor = 0; ///< mFloor = 0
	CController *mController = nullptr;   ///< Controller for this object

};

