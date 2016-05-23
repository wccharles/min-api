//	Copyright 2013 - Cycling '74
//	Timothy Place, tim@cycling74.com	

#pragma once

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>

#ifdef WIN_VERSION
#ifndef snprintf
#define snprintf _snprintf
#endif
#endif

// Max
#include "c74_max.h"
#include "c74_mock_atoms.h"
#include "c74_mock_classes.h"
#include "c74_mock_inlets.h"
#include "c74_mock_outlets.h"
#include "c74_mock_kernel.h"
#include "c74_mock_memory.h"
#include "c74_mock_misc.h"

// MSP
#include "c74_mock_msp.h"

// Jitter
// ...


namespace c74 {
namespace max {


/** Send int or float or symbol messages to an object.
	Sort of like object_method(), but much simpler with no dependencies etc.
	Unlike object_method() you can specify the inlet for which the message is intended.
 
	@param x		The object to which the message is sent.
	@param value	The int, float, or symbol to send.
	@param inletnum	Optional inlet number for the message.  Defaults to inlet 0.
	@return			Whatever value is returned from the method.
 */
template <class T>
void *mock_send_message(void *x, T value, int inletnum=0)
{
	t_object		*o = (t_object*)x;
	object_inlets*	inlets = (object_inlets*)o->o_inlet;
	t_mock_inlet&	inlet = inlets->mock_inlets[inletnum];
	
	return inlet.push(value);
}

	
}} // namespace c74::max