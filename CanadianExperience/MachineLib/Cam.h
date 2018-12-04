#pragma once

#include <vector>
#include "Component.h"
#include "RotationSink.h"

class CRoller;
/**
 * Class that describes the cam
 */
class CCam : public CComponent
{
public:
	/** Constructor
	 * \param radius
	 * \param steps */
	CCam(double radius, int steps);
	
	/** Destructor */
	virtual ~CCam();
	
	/** Build */
	void Build();

	/** GetCamRadius */
	double GetCamRadius();

	/// Get a pointer to the source object
	/// \return Pointer to CRotationSource object
	CRotationSink *GetSink() { return &mSink; }
	void Draw(Gdiplus::Graphics * graphics, int x, int y) override;
	/** Add the 
	*/
	void AddPin(int mPin);
	void AddRoller(std::shared_ptr<CRoller> rollers);

private:
	std::vector<int> mPins; ///<pins
	double mRadius; ///<mRadius 
	int mSteps; ///<mSteps

	CRotationSink mSink; ///< mSink

	std::vector<std::shared_ptr<CRoller>> mRollers; ///< mRollers
	double mPinSize = 5; ///< mPinSize
	double mRotation; ///<mRotation


};

