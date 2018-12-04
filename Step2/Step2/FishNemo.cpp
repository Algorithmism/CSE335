/**
 * \file FishNemo.cpp
 *
 * \author Mark Maroki
 */

#include "stdafx.h"
#include <string>
#include "FishNemo.h"

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring FishNemoImageName = L"images/nemo.png";

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CFishNemo::CFishNemo(CAquarium *aquarium) :
	CFish(aquarium, FishNemoImageName)
{
}

/**
 * Destructor
 */
CFishNemo::~CFishNemo()
{
}
/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishNemo::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CFish::XmlSave(node);
	itemNode->SetAttribute(L"type", L"nemo");
	return itemNode;
}