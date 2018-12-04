/**
 * \file RotationSource.h
 *
 * \author Mark Maroki
 *
 * Describes the Rotation Source
 */

#pragma once

#include <memory>
#include <vector>
#include "RotationSink.h"

class CRotationSink;

class CMotor;
using namespace std;

/**
 * Describes the Rotation Source
 */
class CRotationSource
{
public:
	
	/** Constructor */
	CRotationSource();
	/** Destructor */
	virtual ~CRotationSource();
	/// Copy constructor (disabled)
	CRotationSource(const CRotationSource &) = delete;
	/// Assignment operator (disabled)
	void operator=(const CRotationSource &) = delete;
	
	
	/** \brief Sets Rotation
	 * \param *sink */
	void AddSink(CRotationSink * sink); 
	/** \brief Sets Rotation
	 * \param *component */
	virtual void SetComponent(CComponent * component) { mComponent = component; } ///< mComponent
	
	/** \brief Sets Rotation
	 * \param rotate */
	void SetRotation(double rotate);

	/** \brief Gets component
	 * \return mComponent */
	virtual CComponent *GetComponent() { return mComponent; }

	///** Driver for sink */
	//void Drive(double rotation);


private:
	double speed; ///< speed
	
	///motor member var
	std::shared_ptr<CMotor> mMotors; ///< mMotors

	std::vector<CRotationSink*> mRotationSink; ///< mRotationSink

	CComponent *mComponent = nullptr; ///< *mComponent
	CRotationSource *mSink = nullptr; ///< *mSink
};


