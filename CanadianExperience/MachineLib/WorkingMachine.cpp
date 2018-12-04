/**
 * \file WorkingMachine.cpp
 *
 * \author Mark Maroki
 */

#include "stdafx.h"
#include "WorkingMachine.h"
#include "Component.h"
#include "Motor.h"


using namespace std;

/**
 * Constructor
 */
CWorkingMachine::CWorkingMachine(int i)
{

}


/**
 * Destructor
 */
CWorkingMachine::~CWorkingMachine()
{

}

/**
 * Set the time
 * \param time 
 */
void CWorkingMachine::SetTime(double time)
{
	mTime = time;
	mMotor->SetTime(mTime);

}


	/**
	* Add a component
	* \param component		
	*/
void CWorkingMachine::AddComponent(std::shared_ptr<CComponent> component)
{
	mComponents.push_back(component);
	component->SetMachine(this);

}

/**
* Add a motor
* \param motor
*/
void CWorkingMachine::AddMotor(std::shared_ptr<CMotor> motor)
{
	mMotor = motor; ///< mMotor = motor

	mComponents.push_back(motor); ///<pushback that motor

	mMotor->SetMachine(this);
}


/**
 * Draws the machine
 * \param graphics 
 * \param x 
 * \param y 
 */
void CWorkingMachine::DrawMachine(Gdiplus::Graphics * graphics, int x, int y)
{
	for (auto i : mComponents)
	{
		i->Draw(graphics, x, y);
	}
}



