/**
 * \file BuildingCounter.h
 *
 * \author Mark Maroki
 * Tile Visitor Class giving ability to use visitor concept
 * 
 */




#pragma once
#include "TileVisitor.h"

/**
 * Class that implements building counter
 */
class CBuildingCounter : public CTileVisitor
{
public:
	CBuildingCounter();
	virtual ~CBuildingCounter();


	/** Get the number of buildings
	* \returns Number of buildings */
	int GetNumBuildings() const { return mNumBuildings; }

	/** Visit a CTileBuilding object
	* \param building Building we are visiting */
	void CBuildingCounter::VisitBuilding(CTileBuilding *building)
	{
		mNumBuildings++;
	}

private:
	/// Buildings counter
	int mNumBuildings = 0;
};

