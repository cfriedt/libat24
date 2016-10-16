# The MIT License (MIT)
# 
# Copyright (c) 2016, Christopher Friedt <chrisfriedt@gmail.com>
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

if HAVE_GTEST

noinst_PROGRAMS += \
	test/At24Test

test_At24Test_SOURCES = \
	test/At24Test.cc
test_At24Test_DEPENDENCIES = \
	src/libat24.la \
	src/libat24++.la
test_At24Test_CPPFLAGS = \
	$(AM_CPPFLAGS) \
	@LIBI2C_CFLAGS@ \
	@GTEST_CPPFLAGS@
test_At24Test_LDFLAGS = \
	@GTEST_LDFLAGS@
test_At24Test_LDADD = \
	$(test_At24Test_DEPENDENCIES) \
	@LIBI2C_LIBS@ \
	@GTEST_LIBS@

TESTS += test/At24Test

endif