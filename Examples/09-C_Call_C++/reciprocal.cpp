/*
 * reciprocal.cpp
 *
 *  Created on: 21 de fev de 2019
 *      Author: solid
 */

#include <cassert>
#include "reciprocal.hpp"

double reciprocal(int i)
{
	assert(i != 0);
	return 1.0/i;
}
