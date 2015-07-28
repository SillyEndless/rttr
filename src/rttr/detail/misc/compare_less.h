/************************************************************************************
*                                                                                   *
*   Copyright (c) 2014, 2015 Axel Menzel <info@axelmenzel.de>                       *
*                                                                                   *
*   This file is part of RTTR (Run Time Type Reflection)                            *
*   License: MIT License                                                            *
*                                                                                   *
*   Permission is hereby granted, free of charge, to any person obtaining           *
*   a copy of this software and associated documentation files (the "Software"),    *
*   to deal in the Software without restriction, including without limitation       *
*   the rights to use, copy, modify, merge, publish, distribute, sublicense,        *
*   and/or sell copies of the Software, and to permit persons to whom the           *
*   Software is furnished to do so, subject to the following conditions:            *
*                                                                                   *
*   The above copyright notice and this permission notice shall be included in      *
*   all copies or substantial portions of the Software.                             *
*                                                                                   *
*   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR      *
*   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,        *
*   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE     *
*   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER          *
*   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,   *
*   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE   *
*   SOFTWARE.                                                                       *
*                                                                                   *
*************************************************************************************/

#ifndef RTTR_COMPARE_LESS_H_
#define RTTR_COMPARE_LESS_H_

#include "rttr/detail/base/core_prerequisites.h"
#include "rttr/detail/misc/misc_type_traits.h"

#include <type_traits>

namespace rttr
{
namespace detail
{

/*!
 * \brief This function returns the result of the expression `lhs < rhs` when the type \p T has the less-than operator defined,
 *         otherwise this function will return false.
 */
template<typename T>
typename std::enable_if<has_less_than_operator<T>::value && !std::is_array<T>::value, bool>::type 
compare_less(const T& lhs, const T& rhs)
{
    return lhs < rhs;
}

template<typename T>
typename std::enable_if<!has_less_than_operator<T>::value && !std::is_array<T>::value, bool>::type 
compare_less(const T& lhs, const T& rhs)
{
    return false;
}

template<typename T>
typename std::enable_if<std::is_array<T>::value && has_less_than_operator<typename array_mapper<T>::raw_type>::value, bool>::type 
compare_less(const T& lhs, const T& rhs)
{
    return false
}

template<typename T>
typename std::enable_if<std::is_array<T>::value && !has_less_than_operator<typename array_mapper<T>::raw_type>::value, bool>::type 
compare_less(const T& lhs, const T& rhs)
{
    return false;
}

} // end namespace detail
} // end namespace rttr

#endif // RTTR_COMPARE_LESS_H_
