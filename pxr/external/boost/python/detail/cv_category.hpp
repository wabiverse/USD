//
// Copyright 2024 Pixar
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#ifndef PXR_EXTERNAL_BOOST_PYTHON_DETAIL_CV_CATEGORY_HPP
# define PXR_EXTERNAL_BOOST_PYTHON_DETAIL_CV_CATEGORY_HPP
# include "pxr/external/boost/python/detail/type_traits.hpp"

namespace boost { namespace python { namespace detail { 

template <bool is_const_, bool is_volatile_>
struct cv_tag
{
    BOOST_STATIC_CONSTANT(bool, is_const = is_const_);
    BOOST_STATIC_CONSTANT(bool, is_volatile = is_volatile_);
};

typedef cv_tag<false,false> cv_unqualified;
typedef cv_tag<true,false> const_;
typedef cv_tag<false,true> volatile_;
typedef cv_tag<true,true> const_volatile_;

template <class T>
struct cv_category
{
//    BOOST_STATIC_CONSTANT(bool, c = is_const<T>::value);
//    BOOST_STATIC_CONSTANT(bool, v = is_volatile<T>::value);
    typedef cv_tag<
        is_const<T>::value
      , is_volatile<T>::value
    > type;
};

}}} // namespace boost::python::detail

#endif // PXR_EXTERNAL_BOOST_PYTHON_DETAIL_CV_CATEGORY_HPP
