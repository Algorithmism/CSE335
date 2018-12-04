/**
 * \file Shape.h
 *
 * \author Mark Maroki
 *
 * Shapes class 
 */

#pragma once

#include "Component.h"
#include "RotationSink.h"
#include "RotationSource.h"

/**
 * Describes the shape class
 */
class CShape : public CComponent
{
public:
	/** Shape Constructor*/
	CShape();

	/** Shape Destructor */
	virtual ~CShape();

	/** \brief Get pointer to source object
	 *	\return Pointer */
	CRotationSource *GetSource() { return &mSource; }

	/// Get a pointer to the source object
	/// \return Pointer to CRotationSource object
	CRotationSink *GetSink() { return &mSink; }

private:
	CRotationSink mSink; ///< mSink
	CRotationSource mSource; ///< mSource


};

