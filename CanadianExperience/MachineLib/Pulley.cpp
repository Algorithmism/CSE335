/**
 * \file Pulley.cpp
 *
 * \author Mark Maroki
 */

#include "stdafx.h"
#include "Pulley.h"

using namespace Gdiplus;

/**
 * Constructor
 */
CPulley::CPulley(double radius)
{

	mSink.SetComponent(this);
	mSource.SetComponent(this);
	mRadius = radius; ///<radius
	Circle(radius); ///
}

/**
 * Destructor
 */
CPulley::~CPulley()
{
}

/**
 * Draw the Graphics
 * \param graphics 
 * \param x 
 * \param y 
 */
void CPulley::Draw(Gdiplus::Graphics *graphics, int x, int y) 
{
	if (mPulley != nullptr) 
	{
		Pen belt(Color::Brown, 5);
		double radi1 = mRadius - 2;
		double radi2 = mPulley->GetRadius() - 2;
		Point p1 = Point(GetPosition().X + x, GetPosition().Y + y);
		Point p2 = Point(mPulley->GetPosition().X + x, mPulley->GetPosition().Y + y);

		double theta = atan2(p2.Y - p1.Y, p2.X - p1.X);
		double phi = asin((radi2 - radi1) / sqrt((p2.X - p1.X)*(p2.X - p1.X) + (p2.Y - p1.Y)*(p2.Y - p1.Y)));

		double b1 = theta + phi + (M_PI / 2);
		double b2 = theta - phi - (M_PI / 2);
		auto saveSM = graphics->GetSmoothingMode();
		graphics->SetSmoothingMode(SmoothingMode::SmoothingModeHighQuality);

		//top
		graphics->DrawLine(&belt, p1 + Point(radi1*cos(b1), radi1*sin(b1)), p2 + Point(radi2*cos(b1), radi2*sin(b1)));
		//bot
		graphics->DrawLine(&belt, p1 + Point(radi1*cos(b2), radi1*sin(b2)), p2 + Point(radi2*cos(b2), radi2*sin(b2)));		
		
		graphics->SetSmoothingMode(saveSM); ///< saving making smoothing mode
	}
	CComponent::Draw(graphics, x,y);

}

/**
 * Set Rotation
 * \param rotation 
 */
void CPulley::SetRotation(double rotation)
{
	CComponent::SetRotation(rotation);
	mSource.SetRotation(rotation);
}

/**
 * Adding Sink
 * \param pulley 
 */
void CPulley::AddSink(std::shared_ptr<CPulley> pulley)
{
	mListPulleys.push_back(pulley);
}

/**
 * Drive
 * \param pulley 
 */
void CPulley::Drive(std::shared_ptr<CPulley> pulley)
{

	auto sink = pulley->GetSink(); ///< sink

	mPulley = pulley; ///< mPulley
	mSource.AddSink(sink);
	sink->SetSource(&mSource);
	sink->SetSpeed( mRadius / pulley->GetRadius());
	
}
