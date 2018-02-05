// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2014 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */

// 17.4.1.2 Headers

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
int main()
{
    int i, j, k, q, w, e, r, t, y, u, p, o, a[9], m, n, v = 0;
    for (i = 1; i <= 3; i++)         //百位不可能大于4，否则乘三大于999
        for (j = 1; j <= 9; j++)     //0不符合从1开始
            for (k = 1; k <= 9; k++) {
                q = i * 100 + j * 10 + k; //第一个数
                w = q * 2;                //第二个
                e = q * 3;                //第三个
                r = w / 100;              //第二个数百位
                t = (w % 100) / 10;       //十位
                y = w % 10;               //个位
                u = e / 100;              //第三个数百位
                p = (e % 100) / 10;       //十位
                o = e % 10;               //个位
                a[0] = i;                 //储存第一二三个数的百十个位数
                a[1] = j;
                a[2] = k;
                a[3] = r;
                a[4] = t;
                a[5] = y;
                a[6] = u;
                a[7] = o;
                a[8] = p;
                v = 0;
                for (m = 0; m <= 8; m++) //一个数一个数比较，若有相同v=1
                    for (n = m + 1; n <= 8; n++) {
                        if (a[m] == a[n])
                            v = 1;
                    }
                if (v != 1 && e <= 999 && t != 0 && y != 0 && o != 0 && p != 0) //如果没有相同的就输出
                    cout << q << " " << w << " " << e << endl;
            }
    return 0;
}