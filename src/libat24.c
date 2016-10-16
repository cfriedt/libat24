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
#include <string.h>

#include <libi2c/libi2c.h>
#include "libat24/libat24.h"

#ifndef ARRAY_SIZE
#define ARRAY_SIZE( x ) ( sizeof( x ) / sizeof( (x)[ 0 ] ) )
#endif // ARRAY_SIZE

int at24_transfer( unsigned bus, uint16_t bus_addr, unsigned addr, void *buf, unsigned buf_len, bool is_write ) {
	int r;
	struct i2c_msg msg[ 2 ];
	uint8_t addr_buf[ 2 ];
	ssize_t expected_count;
	unsigned msg_idx;

	msg_idx = 0;
	expected_count = 1;

	memset( msg, 0, sizeof( msg ) );

	if ( ! ( is_write || AT24_ADDR_CURRENT == addr ) ) {
		msg[ msg_idx ].addr = bus_addr;
		msg[ msg_idx ].buf = addr_buf;
		msg[ msg_idx ].len = ARRAY_SIZE( addr_buf );

		// MBS first
		addr_buf[ 0 ] = addr >> 8;
		addr_buf[ 1 ] = addr;

		msg_idx++;
		expected_count++;
	}

	msg[ msg_idx ].addr = bus_addr;
	msg[ msg_idx ].flags = is_write ? 0 : I2C_M_RD;
	msg[ msg_idx ].buf = buf;
	msg[ msg_idx ].len = buf_len;

	r = i2c_transfer( bus, msg, msg_idx );
	if ( expected_count == r ) {
		r = EXIT_SUCCESS;
	}

	return r;
}
int at24_write( unsigned bus, uint16_t bus_addr, unsigned addr, void *buf, unsigned buf_len ) {
	return at24_transfer( bus, bus_addr, addr, buf, buf_len, true );
}

int at24_read( unsigned bus, uint16_t bus_addr, unsigned addr, void *buf, unsigned buf_len ) {
	return at24_transfer( bus, bus_addr, addr, buf, buf_len, false );
}
