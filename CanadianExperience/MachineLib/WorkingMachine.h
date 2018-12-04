/**
 * \file WorkingMachine.h
 *
 * \author Mark Maroki
 *
 * Describes working machine 
 */

#pragma once
#include <vector>
#include "ActualMachine.h"
#include "Motor.h"
#include "Component.h"
#include "WavPlayer.h"

///forward references
class CActualMachine;
class CMotor;
class CWavPlayer;
/**
 * Describes working machine
 */
class CWorkingMachine
{
public:
	/** Working Machine Constructor
	 *\param i*/
	CWorkingMachine(int i);
	/**Working Machine Destructor*/
	virtual ~CWorkingMachine();
	/** \brief Default constructor disabled */
	CWorkingMachine() = delete;
	/** \brief Copy constructor disabled */
	CWorkingMachine(const CWorkingMachine &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CWorkingMachine &) = delete;
	
	///set time
	virtual void SetTime(double time);

	///add component
	void AddComponent(std::shared_ptr<CComponent> component);
	///adding motor
	void AddMotor(std::shared_ptr<CMotor> motor);

	/**
	* Draw the machine at the currently specified location
	* \param graphics GDI+ Graphics object
	*/
	void DrawMachine(Gdiplus::Graphics *graphics, int x, int y);

	/// Get a pointer to the WAVE file player object
	/// \return CWavPlayer object pointer
	CWavPlayer *GetWavPlayer() { return &mWavPlayer; }

private:

	CWavPlayer mWavPlayer;  ///< waveplayer member var

	///composition connection
	CActualMachine * mMachineActual = nullptr;
	
	///double time member var
	double mTime;

	/// Machines relating to the actual machine
	std::vector<std::shared_ptr<CComponent>> mComponents;

	///speed
	double mSpeed;

	///motor
	std::shared_ptr<CMotor> mMotor;
};

