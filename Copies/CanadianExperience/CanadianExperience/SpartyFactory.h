/**
 * \file SpartyFactory.h
 *
 * \author Mark Maroki
 *
 * 
 */

#pragma once

#include "ActorFactory.h"



/**
 * Describes Sparty Object
 */
class CSpartyFactory : public CActorFactory
{
public:
	CSpartyFactory();
	virtual ~CSpartyFactory();
	std::shared_ptr<CActor> Create();
};

