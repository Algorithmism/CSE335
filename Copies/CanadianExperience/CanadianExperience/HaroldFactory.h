/**
 * \file HaroldFactory.h
 * Factory class that builds the Harold character 
 * \author Mark Maroki
 */

#pragma once
#include "ActorFactory.h"


/**
 * Class that describes Harold Factory implementation
 */
class CHaroldFactory : public CActorFactory
{
public:
	CHaroldFactory();
	virtual ~CHaroldFactory();
	///shared pointer to return pointer to actor obj
	std::shared_ptr<CActor> Create();



};

