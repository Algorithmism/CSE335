/**
 * \file FishBeta.h
 *
 * \author Mark Maroki
 *
 * Class the implements a Beta fish
 */


#pragma once

#include <memory>
#include "Item.h"
#include "XmlNode.h"
#include "Fish.h"

using namespace xmlnode;
/**
 * Implements a Dory fish
 */
class CFishDory : public CFish
{
public:
	CFishDory(CAquarium *aquarium);

	/// Default constructor (disabled)
	CFishDory() = delete;

	/// Copy constructor (disabled)
	CFishDory(const CFishDory &) = delete;
	
	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;
	
	virtual ~CFishDory();


};
