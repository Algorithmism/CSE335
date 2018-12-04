/**
 * \file ActualMachine.h
 *
 * \author Mark Maroki
 * The Actual Machine
 * 
 */
#pragma once

#include <memory>
#include "Machine.h"
#include "MachineFactory.h"


class CWorkingMachine;

/**
 * Describes the actual machine
 */
class CActualMachine : public CMachine
{

public:

	/**
	* Constructor
	*/
	CActualMachine();
	
	/**
	* Destructor
	*/
	virtual ~CActualMachine();

	/** \brief Copy constructor disabled */
	CActualMachine(const CActualMachine &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CActualMachine &) = delete;

	/**
	* Set the position for the root of the machine
	* \param x
	* \param y*/
	virtual void SetLocation(int x, int y) override;

	/**
	* Draw the machine at the currently specified location
	* \param graphics GDI+ Graphics object
	*/
	void DrawMachine(Gdiplus::Graphics *graphics) override;

	/**
	* Set the current machine animation frame
	* \param frame Frame number
	*/
	void SetMachineFrame(int frame) override;

	/**
	 * Set the expected frame rate in frames per second
	 * \param rate Frame rate in frames per second
	 */
	void SetFrameRate(double rate) override;

	/**
	* Set the speed
	* \param speed Speed from 0 to 1, where 1 is full speed
	*/
	virtual void SetSpeed(double speed) override;


	/**
	* Set the machine number
	* \param machine An integer number. Each number makes a different machine
	*/
	virtual void SetMachineNumber(int machine);

	/**
	 * Get the current machine number
	 * \return Machine number integer
	 */
	virtual int GetMachineNumber() override { return mMachineTag; }


private:

	double mFrameRate = 30;	 ///< Framerate

	Gdiplus::Point mLocation = Gdiplus::Point(0,0); ///< Location

	double mSpeed;	///< Speed

	double mTime;		///< Time

	/// Machines relating to the working machine
	std::shared_ptr<CWorkingMachine> mMachineActual = 0;


	int mMachineTag; ///< Tag for which machine number is being used



};

