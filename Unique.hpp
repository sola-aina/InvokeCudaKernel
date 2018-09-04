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

