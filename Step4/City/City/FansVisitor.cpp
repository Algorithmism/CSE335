/**
 * \file FansVisitor.cpp
 *	Fans visitor class
 * \author Mark Maroki
 */



#include "stdafx.h"
#include "FansVisitor.h"
#include "TileFans.h"


/**
 * Constructor
 */
CFansVisitor::CFansVisitor()
{
}


/**
 * Destructor
 */
CFansVisitor::~CFansVisitor()
{
}

/**
 * Include functionality for Visit Fans
 * \param fans 
 */
void CFansVisitor::VisitFans(CTileFans * fans)
{
	fans->downState();

}

