#include "stdafx.h"
#include "Roller.h"
#include "Shape.h"
#include "Bell.h"

using namespace std;
using namespace Gdiplus;

/**
 * Destructor
 */
CRoller::CRoller(double radius, double angle)
{
	mSource.SetComponent(this);
	mRadius = radius;
	mAngle = angle;
	CenteredSquare(radius);
	CPolygon::SetImage(L"images/roller.png");
	mShape = make_shared<CShape>();


}

/**
 * Constructor
 */
CRoller::~CRoller()
{
}


/**
 * Draw function
 * \param graphics 
 * \param x 
 * \param y 
 */
void CRoller::Draw(Gdiplus::Graphics *graphics, int x, int y)
{
	PointF intersection;
	if (mCam->Intersection(mAngle, intersection))
	{
		float fx = intersection.X + mCam->GetPosition().X + x;
		float fy = intersection.Y + mCam->GetPosition().Y + y; 
		SetPosition(fx - x, fy - y); ///< SetPosition
		mShape->SetPosition(fx - x, fy - y); ///< mShape
		double distance = sqrt(intersection.X * intersection.X +
			intersection.Y * intersection.Y);
		///if rising
		if (distance > mPrevDist) 
		{
			if ((abs(distance - (mCam->GetCamRadius() + 7)) < 3.5) && ( mPlayerFlag == false) ) 
			{
				mChannel->Play();
				mPlayerFlag = true;
			}
					
		}

		else if (distance < mPrevDist) 
		{
		
			if (((abs(distance - (mCam->GetCamRadius() + 7))) >= 3.5) && (mPlayerFlag == true)) 
			{
				mPlayerFlag = false;
			}
		
		}
		mPrevDist = distance;
	}



	
	//int mPinSize = 7;
	
	//if ((this->GetPosition().Y + y == 330) && mYHolder != 330)
	//{
	//	mChannel->Play(); ///<play the bells
	//	mYHolder = 330; ///< checks height
	//}
	//if (this -> GetPosition().Y + y == 330 ) 
	//{
	//	mYHolder = 0; ///< checks height
	//}
	CComponent::Draw(graphics, x, y);
}

/**
 * Add the Part
 * \param shape 
 */
void CRoller::AddPart(shared_ptr<CShape> shape)
{
	mShape = shape; ///< mShape
}
