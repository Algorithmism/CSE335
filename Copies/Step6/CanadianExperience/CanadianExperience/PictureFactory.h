/**
 * \file PictureFactory.h
 *
 * \author Mark Maroki
 *
 * 
 */

#pragma once

#include <memory>
#include "Picture.h"

using namespace std;


/**
 * Pic Factory
 */
class CPictureFactory
{
public:
	//constructor
	CPictureFactory();
	//virtual destructor
	virtual ~CPictureFactory();

	//create for function to create
	std::shared_ptr<CPicture> Create();


};

