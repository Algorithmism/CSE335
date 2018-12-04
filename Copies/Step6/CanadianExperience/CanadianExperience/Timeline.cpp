/**
 * \file Timeline.cpp
 *
 * Implements timeline class
 *
 * \author Mark Maroki
 */

#include "stdafx.h"
#include "Timeline.h"


/**
 * Timeline Constuctor
 */
CTimeline::CTimeline()
{

}


/**
 * Timeline Destructor
 */
CTimeline::~CTimeline()
{

}
/** Sets the current time
*
* Ensures all of the channels are
* valid for that point in time.
*/
void CTimeline::SetCurrentTime(double t)
{
	// Set the time
	mCurrentTime = t;

	for (auto channel : mChannels)
	{
		channel->SetFrame(GetCurrentFrame());
	}
}

/**
 * Adds channel implementation
 * \param channel 
 */
 void CTimeline::AddChannel(CAnimChannel * channel)
 {
	 ///pushes back channel to list of channels
	 mChannels.push_back(channel);
	 ///sets the timeline for the channel
	 channel->SetTimeline(this);
 }
