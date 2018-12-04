/**
 * \file MachineAdapter.h
 *
 * \author Mark Maroki
 *
 */
#pragma once

#include "Drawable.h"
#include "../MachineDemo/MachineDemoView.h"
#include "AnimChannelPoint.h"

using namespace Gdiplus;

/**
 * Class that allows the machine to draw
 */
class CMachineAdapter : public CDrawable
{
public:
	/**\brief Constructor
	 * \param &name */
	CMachineAdapter(const std::wstring &name);
	/** Destructor */
	~CMachineAdapter();

	/** Default constructor disabled */
	CMachineAdapter() = delete;
	/** Copy constructor disabled */
	CMachineAdapter(const CMachineAdapter &) = delete;
	/** Assignment operator disabled */
	void operator=(const CMachineAdapter &) = delete;

	/**\brief Draw funct
	 * \param graphics	*/
	virtual void Draw(Gdiplus::Graphics *graphics) override;
	
	/**\brief Hittest
	 * \param pos
	 * \return false */
	virtual bool HitTest(Gdiplus::Point pos) override { return false; }
	
	/**\brief Timeline
	 * \param *timeline	*/
	virtual void SetTimeline(CTimeline *timeline) override;
	/**\brief SetPosition
	 * \param *point	*/
	void SetPosition(Gdiplus::Point point) override;

	/**\brief GetStartFrame
	 * \return mStartFrame	*/
	int GetStartFrame() { return mStartFrame; }

	/**\brief SetStartFrame
	 * \param frame	*/
	void SetStartFrame(int frame);

	/**\brief GetStartFrame
	 * \return mEndFrame	*/
	int GetEndFrame() { return mEndFrame; }

	/**\brief SetEndFrame
	 * \param frame	*/
	void SetEndFrame(int frame);


	/** \brief Getting the machine */
	std::shared_ptr<CMachine> GetMachine();

private:
	
	std::shared_ptr<CMachine> mMachine; ///< created machine

	CAnimChannelPoint mMachineChan; ///< Machine Channel	

	int mStartFrame = 0;///< start frame time
	int mEndFrame = 900; ///< end frame time
};
