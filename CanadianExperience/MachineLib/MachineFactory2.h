/**
 * \file MachineFactory2.h
 *
 * \author Mark Maroki
 *
 * Machine Factory 2
 */
#pragma once

#include <memory> 
#include "WorkingMachine.h"

using namespace std;
/**
 * Machine Factory 2
 */
class CMachineFactory2
{
public:
	/** Constructor */
	CMachineFactory2();

	/** Destructor */
	virtual ~CMachineFactory2();

	/** \brief Create the machine */
	std::shared_ptr<CWorkingMachine> CreateMachine();
};

