/*
 * Named.h
 *
 *  Created on: 11 de out de 2017
 *      Author: gilvan
 */
#ifndef INCLUDE_NAMED_ROOT_CLASS_H_
#define INCLUDE_NAMED_ROOT_CLASS_H_
#pragma once

#include "stdafx.h"
#include <string>
namespace salty
{
	typedef std::string String;

	class Named
	{
	public:
		Named();
		/// nm nunca pode ser nulo
		Named(const char* nameStr, unsigned int id);
		~Named();

		const String& getName() const;
		unsigned int getId() const;

	protected:

		String _name;
		unsigned int _id;
	};
}

#endif /* INCLUDE_NAMED_ROOT_CLASS_H_ */
