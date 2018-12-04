/**
 * \file Roller.h
 *
 * \author Mark Maroki
 *
 *  Roller for machine
 */

#pragma once
#include <vector>
#include "Component.h"
#include "RotationSink.h"
#include "Cam.h"
#include "Shape.h"
#include "Bell.h"

/**
 * Roller class
 */
class CRoller : public CComponent
{
public:
	/** Constructor
	 * \param radius 
	 * \param angle	*/
	CRoller(double radius, double angle);
	
	/** Destructor */
	virtual ~CRoller();

	/** \brief Default constructor disabled */
	CRoller() = delete;
	
	/** \brief Copy constructor disabled */
	CRoller(const CRoller &) = delete;
	
	/** \brief Assignment operator disabled */
	void operator=(const CRoller &) = delete;
	
	/** Draw function*/
	void Draw(Gdiplus::Graphics * graphics, int x, int y);
	
	/** Set cam function
	 * \param cam*/
	void SetCam(CCam *cam) { mCam = cam; }
	
	/**Set Channel function
	 * \param channel */
	void SetChannel(shared_ptr<CWavChannel> channel) { mChannel = channel; }
	
	/** Add Part function 
	 * \param shape	*/
	void AddPart(shared_ptr<CShape> shape);

	/** \brief Gets pointer to source object
	 * \return &mSource	*/
	CRotationSource *GetSource() { return &mSource; }

private:
	std::shared_ptr<CShape> mShape; ///< pointer to shape objects
	CBell * mBell = nullptr; ///<pointer to bell objects
	Gdiplus::Point mLocation; ///< location of roller object
	CCam *mCam = nullptr; ///< reference to cam object

	CRotationSource mSource;///< source
	double mRadius; ///< radius 
	double mAngle; ///< Angle
	double mDistance; ///< Distance
	shared_ptr<CWavChannel> mChannel = nullptr; ///< channel to play
	int mYHolder = 330; ///< height of roller
	bool mPlayerFlag = false; ///< checks if bells should play
	double mPrevDist = 0.0; ///< previous distance
	

};