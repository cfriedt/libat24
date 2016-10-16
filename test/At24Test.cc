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
#include <sys/utsname.h>

#include <gtest/gtest.h>

#include <libi2c/I2c.h>
#include "libat24/At24.h"

using namespace ::std;
using namespace ::com::github::cfriedt;

#ifndef ARRAY_SIZE
#define ARRAY_SIZE( x ) ( sizeof( x ) / sizeof( (x)[ 0 ] ) )
#endif // ARRAY_SIZE

#define OSPASS_() \
	if ( ospass ) { \
		std::cout << "skipping test because this platform is not 'Linux'" << std::endl; \
		return; \
	} \

class At24Test : public testing::Test
{

public:

	At24 at24;
	bool ospass;

	At24Test();
	~At24Test();

	void SetUp();
	void TearDown();
};

At24Test::At24Test()
: ospass( false )
{
}

At24Test::~At24Test() {
}

void At24Test::SetUp() {
	struct utsname utsname;
	int rr;

	rr = uname( & utsname );
	ASSERT_EQ( EXIT_SUCCESS, rr );
	ospass = 0 != strcmp( "Linux", utsname.sysname );
	if ( ! ospass ) {
		at24 = At24( 0, I2C_ADDR_AT24_MIN );
	}
}

void At24Test::TearDown() {
}

TEST_F( At24Test, ReadByte ) {
	OSPASS_();

	uint8_t buf[ 1 ];
	at24.read( AT24_ADDR_CURRENT, buf, ARRAY_SIZE( buf ) );
}

TEST_F( At24Test, WriteByte ) {
	OSPASS_();

	uint8_t buf[ 1 ];
	at24.write( AT24_ADDR_CURRENT, buf, ARRAY_SIZE( buf ) );
}
