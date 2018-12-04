/**
 * \file FishBeta.h
 *
 * \author Charles B. Owen
 *
 * Class the implements a Beta fish
 */

#pragma once

#include <memory>
#include "XmlNode.h"
#include "Item.h"
#include "Fish.h"
#include "Aquarium.h"

using namespace xmlnode;

 /**
  * Implements a Beta fish
  */
class CFishBeta : public CFish
{
public:
    CFishBeta(CAquarium *aquarium);


    /// Default constructor (disabled)
    CFishBeta() = delete;

    /// Copy constructor (disabled)
    CFishBeta(const CFishBeta &) = delete;
	
	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;


    ~CFishBeta();
};
