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

#ifndef libat24_At24_h_
#define libat24_At24_h_

#include <stdint.h>

#include <libat24/libat24.h>

namespace com {
namespace github {
namespace cfriedt {

class At24 {
public:
	At24();
	At24( unsigned bus, uint16_t bus_addr );
	virtual ~At24();

	void read( unsigned addr, void *buf, unsigned buf_len );
	void write( unsigned addr, void *buf, unsigned buf_len );

	unsigned getBus() {
		return bus;
	}
	uint16_t getBusAddress() {
		return bus_addr;
	}

protected:
	unsigned bus;
	uint16_t bus_addr;
};

}
}
} // com.cfriedt.github

#endif // libat24_At24_h_
