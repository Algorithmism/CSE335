/**
 * \file Bell.h
 *
 * \author Mark Maroki
 *
 *  Bell Class to Play Bell for machine
 */
#pragma once

#include "Component.h"
#include "WavChannel.h"
#include "WavPlayer.h"

/**
 * Bell class
 */
class CBell : public CComponent
{
public:

	///** Constructor */
	//CBell();
	/** Destructor */
	virtual ~CBell();

	/** \brief Default constructor disabled */
	CBell() = delete;
	/** \brief Copy constructor disabled */
	CBell(const CBell &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CBell &) = delete;

	void Play();
};

