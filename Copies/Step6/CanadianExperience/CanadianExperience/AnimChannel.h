/**
 * Base class for animation channels
 *
 * This class provides basic functionality and a polymorphic
 * representation for animation channels.
 */

#pragma once
#include <sstream>
#include <vector>
#include <memory>
#include <string>

class CTimeline;

/**
 * Animal Channel Class
 */
class CAnimChannel
{
public:
	///default constructor
	CAnimChannel();

	///virtual destructor
	virtual ~CAnimChannel();



	/** \brief Copy constructor disabled */
	CAnimChannel(const CAnimChannel &) = delete;
	
	/** \brief Assignment operator disabled */
	void operator=(const CAnimChannel &) = delete;

	/** Timeline getter
	* \returns mTimeline   */
	CTimeline* GetTimeline() { return mTimeline; }

	/** Timeline setter
	* \param timeline
	* \returns mTimeline */
	void SetTimeline(CTimeline *timeline) { mTimeline = timeline; }
	
	/**
	 * Is the channel valid, meaning has keyframes?
	 * \returns true if the channel is valid.
	 */
	bool CAnimChannel::IsValid()
	{
		return mKeyframe1 >= 0 || mKeyframe2 >= 0;
	}
	
	/**
	* Class implements key frame (nested)
	*/
	class Keyframe
	{
	public:
		/** Copy constructor
		* \param channel */
		Keyframe(CAnimChannel channel);
		/** Default constructor disabled */
		Keyframe() = delete;
		/** Copy constructor disabled */
		Keyframe(const Keyframe &) = delete;
		/** Assignment operator disabled */
		void operator=(const Keyframe &) = delete;


		/** Use this keyframe as keyframe 1 */
		virtual void UseAs1() = 0;
		/** Use this keyframe as keyframe 2 */
		virtual void UseAs2() = 0;
		/** Use this keyframe as angle keyframe */
		virtual void UseOnly() = 0;

		/** Frame Getter
		* \returns mFrame */
		int GetFrame() { return mFrame; }
		
		/** Setter for frame
		* \param frame
		* \returns mFrame */
		void SetFrame(int frame) { mFrame = frame; }

	protected:
		/// frame to know what frame we are on in the timeline
		int mFrame;
		/** Constructor
		 * \param channel Channel we are associated with */
		Keyframe(CAnimChannel *channel) : mChannel(channel) {}
	private:
		/// The channel this keyframe is associated with
		CAnimChannel *mChannel;
	};

	void InsertKeyframe(std::shared_ptr<Keyframe> keyframe);

	/**
	*	Tweening
	*\param t for tweening
	*/
	virtual void Tween(double t);
	/**
	*	Tweening
	*\param currFrame for tweening
	*/
	void SetFrame(int currFrame);

private:
	std::wstring mName;     ///< The channel name
	int mKeyframe1 = -1;    ///< The first keyframe
	int mKeyframe2 = -1;    ///< The second keyframe
	
	/// The timeline object
	CTimeline *mTimeline = nullptr;

	/// The collection of keyframes for this channel
	std::vector<std::shared_ptr<Keyframe>> mKeyframes;
};