/**
 * \file Shape.cpp
 *
 * \author Mark Maroki
 */

#include "stdafx.h"
#include "Shape.h"

/**
 * Shape Constructor
 */
CShape::CShape()
{
	mSink.SetComponent(this);
}

/**
 * Class Destructor
 */
CShape::~CShape()
{
}
