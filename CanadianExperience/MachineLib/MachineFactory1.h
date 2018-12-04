/**
 * \file MachineFactory1.h
 *
 * \author Mark Maroki
 *
 * Implements multiple machines 
 */

#pragma once

#include <memory>

class CWorkingMachine;

/**
 * Class for MachinesFactory because it will create multiple machines
 */
class CMachineFactory1
{

public:
	/** Default Constructor */
	CMachineFactory1();

	/** Virtual Destructor */
	virtual ~CMachineFactory1();

	/** Create the machine! */
	std::shared_ptr<CWorkingMachine> CreateMachine();

};

