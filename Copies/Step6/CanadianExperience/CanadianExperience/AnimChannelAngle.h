/**
 * Animation channel for angles.
 */

#pragma once
#include "AnimChannel.h"
#include <string>

using namespace std;

/**
 * CAnimChannelAngle class
 */
class CAnimChannelAngle : public CAnimChannel
{
public:
	///constructor default
	CAnimChannelAngle();
	///virtual destructor
	virtual ~CAnimChannelAngle();

	/** \brief Copy constructor disabled */
	CAnimChannelAngle(const CAnimChannelAngle &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CAnimChannelAngle &) = delete;
	
	/** Setter for keyframe
	* \param mAngle */
	void SetKeyframe(double mAngle);

	/** Name Setter
	* \param name   */
	void SetName(const std::wstring &name) { mName = name; }

	/** Getter for name
	* \return mName*/
	std::wstring GetName() const { return mName; }
	/**Gets the angle
	* \return mAngle  */
	double GetAngle() { return mAngle; }

	void Tween(double t);

	/** Class that represents a keyframe */
    class KeyframeAngle : public Keyframe
	{
	public:
		/** \brief Default constructor disabled */
		KeyframeAngle() = delete;
		/** \brief Copy constructor disabled */
		KeyframeAngle(const KeyframeAngle &) = delete;
		/** \brief Assignment operator disabled */
		void operator=(const KeyframeAngle &) = delete;

		/** Constructor
		 * \param channel The channel we are for
		 * \param angle The angle for the keyframe */
		KeyframeAngle(CAnimChannelAngle *channel, double angle) :
			Keyframe(channel), mChannel(channel), mAngle(angle) {}

		/** Use this keyframe as keyframe 1 */
		virtual void UseAs1() override { mChannel->mKeyframe1 = this; }

		/** Use this keyframe as keyfraem 2 */
		virtual void UseAs2() override { mChannel->mKeyframe2 = this; }

		/** Use this keyframe as the angle */
		virtual void UseOnly() override { mChannel->mAngle = mAngle; }

		/** Getter for angle
		* \return mAngle */
		double GetAngle() { return mAngle; }

	private:
		/// mAngle value to determine angle of rotation
		double mAngle;
		/// The channel this keyframe is associated with
		CAnimChannelAngle *mChannel;
	};



private:

	std::wstring mName;     ///< The channel name

	/// The first angle keyframe
	KeyframeAngle *mKeyframe1 = nullptr;

	/// The second angle keyframe
	KeyframeAngle *mKeyframe2 = nullptr;

	///mem var for angle
	double mAngle = 0;



};

