/**
 * \file Component.cpp
 *
 * \author Mark Maroki
 */


#include "stdafx.h"
#include "Component.h"
#include "Polygon.h"

/**
 * Constructor
 */
CComponent::CComponent()
{
}

/**
 * Destructor
 */
CComponent::~CComponent()
{
}

void CComponent::SetPosition(int x, int y)
{
	mPosition.X = x;
	mPosition.Y = y;

}

