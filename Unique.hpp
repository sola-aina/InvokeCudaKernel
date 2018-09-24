// Copyright (c) 2018 Sola Aina
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <type_traits>

////////////////////////////////////////////////////////////////////////////////

template<int Id1 , int Id2 , typename T , typename ... Ts>
struct Unique
{
	typedef Unique<Id1 + 1,Id2,Ts ...> Next;
	typedef typename Next::type type;
	static const bool value = !std::is_same<type , T>::value && Next::value;
};

////////////////////////////////////////////////////////////////////////////////

template<int Id , typename T , typename ... Ts>
struct Unique<Id,Id,T,Ts ...>
{
	static const bool value = true;
	typedef T type;
};

////////////////////////////////////////////////////////////////////////////////

template<int>
struct Dummy{};

template<int I, typename ... Ts>
using UniqueType = typename std::conditional<
												Unique<0,I,Ts...>::value ,
												typename Unique<0,I,Ts...>::type ,
												Dummy<I>
											>::type;

////////////////////////////////////////////////////////////////////////////////

