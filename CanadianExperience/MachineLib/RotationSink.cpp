#include "stdafx.h"
#include "RotationSink.h"
#include "Pulley.h"


/**
 * Constructor
 */
CRotationSink::CRotationSink()
{
}

/**
 * Destructor
 */
CRotationSink::~CRotationSink()
{
}

/** \brief SetRotation
 *\param rotation */
void CRotationSink::SetRotation(double rotation)
{
	if (GetComponent() != nullptr) 
	{

		GetComponent()->SetRotation(rotation * mSpeed);
	}
}

