/**
 * \file MachineAdapter.cpp
 *
 * \author Mark Maroki
 */

#include "stdafx.h"
#include "MachineAdapter.h"
#include "MachineFactory.h"
#include "TimeLine.h"
#include "AnimChannelPoint.h"
#include "MachineDlg.h"

/**
 * Constructor
 * \param name 
 */
CMachineAdapter::CMachineAdapter(const std::wstring &name) :
	CDrawable(name)
{
	CMachineFactory factory;
	mMachine = factory.CreateMachine();

	CMachineDlg dlg(mMachine);
	if (dlg.DoModal() == IDOK) 
	{
		mMachine->SetMachineFrame(0);
		mMachine->SetFrameRate(30);
		
	}
}


/**
 * Destructor
 */
CMachineAdapter::~CMachineAdapter()
{

}

/**
 * Sets the Draw Function
 * \param graphics 
 */
void CMachineAdapter::Draw(Gdiplus::Graphics *graphics)
{
	if (mStartFrame <= mMachineChan.GetTimeline()->GetCurrentFrame() && mMachineChan.GetTimeline()->GetCurrentFrame() <= mEndFrame)
	{
		mMachine->SetMachineFrame(mMachineChan.GetTimeline()->GetCurrentFrame() - mStartFrame); ///<current frame
	}
	else
	{
		mMachine->SetMachineFrame(0); ///< Set machine frame
	}
	///*mMachine->SetMachineFrame(mMachineChan.GetTimeline()->GetCurrentFrame());*/
	mMachine->SetLocation(mPlacedPosition.X, mPlacedPosition.Y);
	mMachine->SetSpeed(1);
	mMachine->DrawMachine(graphics);

}


/**
 * Sets the timeline
 * \param timeline 
 */
void CMachineAdapter::SetTimeline(CTimeline * timeline)
{
	CDrawable::SetTimeline(timeline);
	timeline->AddChannel(&mMachineChan);
}

/**
 * \brief SetPosition
 * \param point 
 */
void CMachineAdapter::SetPosition(Gdiplus::Point point)
{
	CDrawable::SetPosition(point);
	mMachine->SetLocation(point.X, point.Y);
}

/**
 * \brief Set StartFrame
 * \param frame */
void CMachineAdapter::SetStartFrame(int frame)
{
	mStartFrame = frame; ///< mStartFrame
}

/**
 * Set End Frame
 * \param frame 
 */
void CMachineAdapter::SetEndFrame(int frame)
{
	mEndFrame = frame; ///< mEndFrame
}

/**
 * Getting the Machine 
 * \returns mMachine
 */
std::shared_ptr<CMachine> CMachineAdapter::GetMachine()
{
	return mMachine;
}
