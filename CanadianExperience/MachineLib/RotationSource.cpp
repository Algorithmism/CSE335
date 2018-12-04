#include "stdafx.h"
#include "RotationSource.h"


/**
 * Constructor
 */
CRotationSource::CRotationSource()
{

}


/**
 * Destructor
 */
CRotationSource::~CRotationSource()
{
}

void CRotationSource::SetRotation(double rotation) 
{
	for (auto sinks : mRotationSink)
	{
		sinks->SetRotation(rotation);
	}	

}

void CRotationSource::AddSink(CRotationSink * sinks)
{
	mRotationSink.push_back(sinks);
}
