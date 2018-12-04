/**
 * \file ActualMachine.cpp
 *
 * \author Mark Maroki
 */

#include "stdafx.h"
#include "ActualMachine.h"
#include "MachineFactory1.h"
#include "MachineFactory2.h"
#include "WorkingMachine.h"
#include "Component.h"

/**
 * Constructor
 */
CActualMachine::CActualMachine()
{
	SetMachineNumber(1);
}

/**
 * Destructor
 */
CActualMachine::~CActualMachine()
{
}


/**
 * \brief Set Location
 * \param x
 * \param y
 */
void CActualMachine::SetLocation(int x, int y)
{
	mLocation.X = x;
	mLocation.Y = y;

}

/**
 * \brief Draw Machine
 * \param graphics 
 */
void CActualMachine::DrawMachine(Gdiplus::Graphics *graphics)
{
	mMachineActual->DrawMachine(graphics, mLocation.X, mLocation.Y);
}

/** \brief Set Machine Number function
 *
 * \param machine 
 */
void CActualMachine::SetMachineNumber(int machine)
{
	mMachineTag = machine;
	if (mMachineTag == 1) 
	{
		CMachineFactory1 newFactory; 
		mMachineActual = newFactory.CreateMachine();
	}
	if (machine == 2) 
	{
		CMachineFactory2 newFactory2;
		mMachineActual = newFactory2.CreateMachine();
	}
}

/** \brief Sets the mFrame mem var
 * \param rate */
void CActualMachine::SetFrameRate(double rate)
{
	mFrameRate = rate; ///< mFrameRate is the rate
}

/**
 * Setting the speed
 * \param speed 
 */
void CActualMachine::SetSpeed(double speed)
{
	mSpeed = speed;
}


/**
 * SetMachineFrame
 * \param frame 
 */
void CActualMachine::SetMachineFrame(int frame)
{
	mTime = ( frame / mFrameRate ) * mSpeed;
	mMachineActual->SetTime(mTime);
}