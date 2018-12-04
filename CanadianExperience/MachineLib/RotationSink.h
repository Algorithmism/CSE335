/**
 * \file RotationSink.h
 *
 * \author Mark Maroki
 *
 * 
 */
#pragma once

#include "Component.h"
#include "RotationSource.h"

class CRotationSource;

/**
 * Class Rotation sink
 */
class CRotationSink
{
public:
	/** Constructor */
	CRotationSink();
	/** Destructor */
	virtual ~CRotationSink();

	/** \brief Copy constructor disabled */
	CRotationSink(const CRotationSink &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CRotationSink &) = delete;
	/** \brief Setting the component 
	 *	\param component */
	virtual void SetComponent(CComponent * component) { mComponent = component; }

	/** \brief Setting the Source
	 *	\param source */
	virtual void SetSource(CRotationSource * source) { mSource = source; }
	
	/** \brief Setting the rotation	*/
	void SetRotation(double rotate);

	/** \brief Get the component
	 *	\return mComponent */
	virtual CComponent *GetComponent() { return mComponent; }

	/** \brief Setting the speed
	 *	\param speed */
	void SetSpeed(double speed) { mSpeed = speed;  }

private:

	double mSpeed = 1; ///< Speed
	CComponent *mComponent = nullptr; ///<*mComponent
	CRotationSource *mSource = nullptr; ///<*mSource
};

