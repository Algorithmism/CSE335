/**
 * \file Cam.cpp
 *
 * \author Mark Maroki
 */



#include "stdafx.h"
#include "Cam.h"
#include "Roller.h"

using namespace Gdiplus;
using namespace std;

const int SubSteps = 3; ///<substeps

/**
 * Constructor
 */
CCam::CCam(double radius, int steps)
{
	mRadius = radius;
	mSteps = steps;
	mSink.SetComponent(this);
}

/**
 * Destructor
 */
CCam::~CCam()
{
}

/**
 * Build the cam after all of the pins have been set.
 */
void CCam::Build()
{

	for (int i = 0; i < mSteps * SubSteps; i++)
	{
		double angle = 2 * M_PI * i / double(mSteps * SubSteps);
		double radius = mRadius;

		for (auto pin : mPins)
		{
			if (pin * SubSteps == i || pin * SubSteps == (i - 1))
			{
				radius = mRadius + mPinSize;
				break;
			}
		}

		AddPoint(radius * cos(angle), radius * -sin(angle));
	}
}

/**
 * GetCamRadius 
 * \returns 
 */
 double CCam::GetCamRadius()
 {
	 return mRadius; ///<mRadius
 }

/**
 * Draw the Cam
 * \param graphics 
 * \param x 
 * \param y 
 */
void CCam::Draw(Gdiplus::Graphics *graphics, int x, int y)
{
	CComponent::Draw(graphics, x, y);
}

/**
 * Add pin
 * \param mPin 
 */
void CCam::AddPin(int mPin)
{
	mPins.push_back(mPin);
}

/**
 * Add Rollers
 * \param rollers 
 */
void CCam::AddRoller(shared_ptr<CRoller> rollers)
{
	mRollers.push_back(rollers);
	rollers->SetCam(this);
}
