/**
 * \file Motor.cpp
 *
 * \author Mark Maroki
 */


#include "stdafx.h"
#include "Motor.h"

/**
 * Constructor for motor
 */
CMotor::CMotor()
{
	mSource.SetComponent(this); ///<setting the source
	int rad = 10; ///<set radius to 15
	Circle(rad, 0); ///< circle radius 
	SetImage(L"images/shaft.png"); ///< set the image on the circle

	
	int width = 75; ///< width as an integer
	mMotor->Rectangle(-width / 2, 0, width, width); ///< set the rectangle 
	mMotor->SetImage(L"images/motor2.png"); ///<place the image of the motor on the rectangle
}


/**
 * Destructor
 */
CMotor::~CMotor()
{
}

/**
 * Set Speed
 * \param speed 
 */
void CMotor::SetSpeed(double speed)
{
	mSpeed = speed; ///< Speed
}

/**
 * Controls rotations
 * \param speed 
 * \param time 
 */
void CMotor::Rotations(double speed, double time)
{
	mRotation = speed * time;
	mMotor->SetRotation(mRotation);
}

/**
 * Set the motor time
 * \param time 
 */
void CMotor::SetTime(double time)
{
	mRotation = mSpeed * time;
	SetRotation(mRotation);
	mSource.SetRotation(mRotation);
}

/**
 * Drive function
 * \param rotation 
 */
void CMotor::Drive(double rotation)
{
//	SetRotation(rotation);
}

/**
 * Draw motors and shafts
 * \param graphics 
 * \param x 
 * \param y 
 */
void CMotor::Draw(Gdiplus::Graphics * graphics, int x, int y)
{
	mMotor->DrawPolygon(graphics, x - 155, y - 40);
	///Draw
	CComponent::Draw(graphics, this->GetPosition().X+x+145, this->GetPosition().Y+y);


}
