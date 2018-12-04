/**
 * \file AnimShiftChannel.h
 *
 * \author Mark Maroki
 *
 * 
 */
#pragma once

#include <string>
#include "AnimChannel.h"
#include "AnimChannelAngle.h"

using namespace Gdiplus;
using namespace std;

/**
 * Task for last part of step assignment
 */
class CAnimShiftChannel
{
public:
	///default constructor
	CAnimShiftChannel();
	///destructor
	virtual ~CAnimShiftChannel();

	/** \brief Copy constructor disabled */
	CAnimShiftChannel(const CAnimShiftChannel &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CAnimShiftChannel &) = delete;
	/**
	* Getter of Point
	* \return mPoint */
	Point GetPoint() { return mPoint; }

	/** Getter of Point
	* \return mPoint */
	void SetKeyFrame(Point mPoint);



	///** Class that represents a keyframe */
	//class KeyframePlacement : public Keyframe
	//{
	//public:
	//	/** Default constructor disabled */
	//	KeyframePlacement() = delete;
	//	/** Copy constructor disabled */
	//	KeyframePlacement(const KeyframePlacement &) = delete;
	//	/** Assignment operator disabled */
	//	void operator=(const KeyframePlacement &) = delete;
	//	/** Constructor
	//	* \param channel The channel we are for
	//	* \param point The point for the keyframe */
	//	KeyframePlacement(CAnimShiftChannel *channel, Point point) :
	//		Keyframe(channel), mChannel(channel), mPoint(point) {}

	//	/** Use this keyframe as keyframe 1 */
	//	virtual void UseAs1() override { mChannel->mKeyframe1 = this; }

	//	/** Use this keyframe as keyfraem 2 */
	//	virtual void UseAs2() override { mChannel->mKeyframe2 = this; }

	//	/** Use this keyframe as the angle */
	//	virtual void UseOnly() override { mChannel->mPoint = mPoint; }

	private:
		/// Point of movement in move channel
		Point mPoint;
		/// The channel this keyframe is associated with
		CAnimShiftChannel *mChannel;

	};
//private:
//	Point mPoint;
//
//	/// The first angle keyframe
//	KeyframePlacement *mKeyframe1 = nullptr;
//
//	/// The second angle keyframe
//	KeyframePlacement *mKeyframe2 = nullptr;
//};