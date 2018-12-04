/**
 * \file Motor.h
 *
 * \author Mark Maroki
 * Motor Header file to describe motor 
 */

#pragma once

#include "Component.h"
#include "Polygon.h"
#include "RotationSource.h"

class CPolygon;
class CRotationSource;

/**
 * Motor Class to Describe motor
 */
class CMotor : public CComponent
{
public:
	/** Constructor */
	//CMotor(int temp);

	/** Destructor */
	virtual ~CMotor();

	/** \brief Default constructor disabled */
	CMotor();

	/** \brief Copy constructor disabled */
	CMotor(const CMotor &) = delete;
	
	/** \brief Assignment operator disabled */
	void operator=(const CMotor &) = delete;
	
	///speed
	virtual void SetSpeed(double speed);
	///rotations 
	virtual void Rotations(double speed, double time);
	
	/** \brief Gets the speed of the motor
	 * \return mSpeed */
	double GetSpeed() { return mSpeed;  }
	
	///set time
	void SetTime(double time);
	
	///drive
	void Drive(double rotation);

	/** Draw function used for drawing motor and shaft*/
	virtual void Draw(Gdiplus::Graphics *graphics, int x, int y);

	/// Get a pointer to the source object
	/// \return Pointer to CRotationSource object
	CRotationSource *GetSource() { return &mSource; }

private:
	std::shared_ptr<CPolygon>mMotor = std::make_shared<CPolygon>(); ///< mMotor polygon association with Polygon.
	std::shared_ptr<CPolygon>mShaft = std::make_shared<CPolygon>(); ///< mShaft polygon

	double mRotation; ///< mRotation double
	double mSpeed; ///< mSpeed double 
	
	/// Rotation source for this component
	CRotationSource mSource;
};

