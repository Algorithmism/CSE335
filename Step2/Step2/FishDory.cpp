/**
 * \file FishDory.cpp
 *
 * \author Mark Maroki
 */

#include "stdafx.h"
#include "FishDory.h"
#include "XmlNode.h"

using namespace std;
using namespace Gdiplus;
using namespace xmlnode;

/// Fish filename 
const wstring FishDoryImageName = L"images/dory.png";

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CFishDory::CFishDory(CAquarium *aquarium) :
	CFish(aquarium, FishDoryImageName)
{
}

/**
 * Destructor
 */
CFishDory::~CFishDory()
{
}
 
/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishDory::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CFish::XmlSave(node);
	itemNode->SetAttribute(L"type", L"dory");
	return itemNode;
}