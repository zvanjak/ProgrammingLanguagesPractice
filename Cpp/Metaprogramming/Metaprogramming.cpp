// Metaprogramming.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
/*
template <class _A1, class _A2> typename enable_if<is_arithmetic<_A1>::value && is_arithmetic<_A2>::value, typename __promote<_A1, _A2>::type>::type
pow(_A1 __x, _A2 __y)
{
	typedef typename __promote<_A1, _A2>::type __result_type;
	return pow((__result_type)__x, (__result_type)__y);
}

template <class _A1, class _A2>
inline _LIBCPP_INLINE_VISIBILITY
typename std::enable_if<
	!std::is_same<typename numeric_type<_A1>::type, void>::value &&
	!std::is_same<typename numeric_type<_A2>::type, void>::value,
	typename __promote<
		typename numeric_type<_A1>::type,
		typename numeric_type<_A2>::type>
	::type>
::type
pow(_A1 __x, _A2 __y)
{
	typedef typename numeric_type<_A1>::type _D1;
	typedef typename numeric_type<_A2>::type _D2;
	typedef typename std::__promote<_D1, _D2>::type type;
	return pow((type)_D1(__x), (type)_D2(__y));
}
*/

int _tmain(int argc, _TCHAR* argv[])
{

}

