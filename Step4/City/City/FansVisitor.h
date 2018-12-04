/**
 * \file FansVisitor.h
 *
 * \author Mark Maroki
 * Visitor class to load all fans.
 * Applies to all fans.
 */

#pragma once
#include "TileVisitor.h"

class CTileFans;


/**
 * Visitor Class to load fans.
 */
class CFansVisitor : public CTileVisitor
{
public:
	CFansVisitor();

	virtual ~CFansVisitor();
	///virtual function for fans to visit/access
	virtual void VisitFans(CTileFans *fans);
};

