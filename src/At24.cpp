/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2016, Christopher Friedt <chrisfriedt@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include <iostream>

#include <libi2c/I2c.h>
#include "libat24/At24.h"

using namespace ::std;
using namespace ::com::github::cfriedt;

#ifndef ARRAY_SIZE
#define ARRAY_SIZE( x ) ( sizeof( x ) / sizeof( (x)[ 0 ] ) )
#endif // ARRAY_SIZE

At24::At24()
:
	bus( -1 ),
	bus_addr( -1 )
{
}
At24::At24( unsigned bus, uint16_t bus_addr )
:
	bus( bus ),
	bus_addr( bus_addr )
{
}
At24::~At24()
{
}

void At24::read( unsigned addr, void *buf, unsigned buf_len ) {
	int r;
	r = at24_read( bus, bus_addr, addr, buf, buf_len );
	if ( -1 == r ) {
		throw std::system_error( errno, std::system_category() );
	}
}
void At24::write( unsigned addr, void *buf, unsigned buf_len ) {
	int r;
	r = at24_write( bus, bus_addr, addr, buf, buf_len );
	if ( -1 == r ) {
		throw std::system_error( errno, std::system_category() );
	}
}
