/**
 * \file FishKarp.cpp
 *
 * \author Mark Maroki
 */

#include "stdafx.h"
#include <string>
#include "FishKarp.h"
#include "Aquarium.h"

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring FishKarpImageName = L"images/carp.png";

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CFishKarp::CFishKarp(CAquarium *aquarium) :
	CFish(aquarium, FishKarpImageName)
{
}

/**
 * Destructor
 */
CFishKarp::~CFishKarp()
{
}


/**
 * Gets location of killer karp and kills 
 * \param x 
 * \param y 
 */
void CFishKarp::SetLocation(double x, double y)
{
	CItem::SetLocation(x, y);
	while (GetAquarium()->Killing(this))
	{

	}
}
/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishKarp::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CFish::XmlSave(node);
	itemNode->SetAttribute(L"type", L"karp");
	return itemNode;
}