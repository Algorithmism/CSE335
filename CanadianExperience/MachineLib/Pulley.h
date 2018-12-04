/**
 * \file Pulley.h
 *
 * \author Mark Maroki
 *
 * The Pulley Header File
 */

#pragma once


#include "Component.h"
#include "RotationSink.h"
#include "RotationSource.h"

/**
 * Class of Pullyys
 */
class CPulley :
	public CComponent
{
public:
	/** Constructor 
	 * \param radius */
	CPulley(double radius);

	/** Destructor */
	virtual ~CPulley();

	/** \brief Draws the Pulleys
	 * \param graphics
	 */
	virtual void Draw(Gdiplus::Graphics * graphics, int x, int y) override;
	/** \brief Set Rotation
	 *	\param rotation */
	void SetRotation(double rotation) override;

	/** \brief Setting the Machine Adapter
	 *	\param pulley */
	void AddSink(std::shared_ptr<CPulley> pulley);

	/// Get a pointer to the source object
	/// \return Pointer to CRotationSource object
	CRotationSource *GetSource() { return &mSource; }

	/// Get a pointer to the source object
	/// \return Pointer to CRotationSource object
	CRotationSink *GetSink() { return &mSink; }

	/** \brief Drive the pulleys
	 *	\param pulley */
	void Drive(std::shared_ptr<CPulley> pulley);
	
	/** \brief Setting the Machine Adapter
	 *	\return mRadius */
	double GetRadius() { return mRadius; }

private:

	/// Rotation source for this component
	CRotationSource mSource;///<source
	CRotationSink mSink; ///< mSink

	/** mPosition  */
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);
	
	double mRadius; ///<radius 

	std::vector<std::shared_ptr<CPulley>> mListPulleys;///< List of pulleys
	
	std::shared_ptr<CPulley> mPulley; ///<pulley single

};

