/*
 * Named.cpp
 *
 *  Created on: 11 de out de 2017
 *      Author: gilvan
 */

#include "stdafx.h"
#include "Named.h"
namespace salty
{
	Named::Named()
		: _name(), _id(0) {

	}
	Named::Named(const char* nm, unsigned int id)
		: _name(nm), _id(id) {
		// TODO Auto-generated constructor stub

	}
	Named::~Named() {
		// TODO Auto-generated destructor stub
	}
	const String& Named::getName() const
	{
		return _name;
	}
	unsigned int Named::getId() const
	{
		return _id;
	}
}
