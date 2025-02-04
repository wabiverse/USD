//
// Copyright 2024 Pixar
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#ifndef PXR_EXTERNAL_BOOST_PYTHON_DETAIL_TYPE_LIST_HPP
# define PXR_EXTERNAL_BOOST_PYTHON_DETAIL_TYPE_LIST_HPP

# include <boost/config.hpp>
# include "pxr/external/boost/python/detail/preprocessor.hpp"
# include <boost/preprocessor/arithmetic/inc.hpp>

# if BOOST_PYTHON_MAX_ARITY + 2 > BOOST_PYTHON_MAX_BASES
#  define BOOST_PYTHON_LIST_SIZE BOOST_PP_INC(BOOST_PP_INC(BOOST_PYTHON_MAX_ARITY))
# else
#  define BOOST_PYTHON_LIST_SIZE BOOST_PYTHON_MAX_BASES
# endif

// Compute the MPL vector header to use for lists up to BOOST_PYTHON_LIST_SIZE in length
# if BOOST_PYTHON_LIST_SIZE > 48
#  error Arities above 48 not supported by Boost.Python due to MPL internal limit
# elif BOOST_PYTHON_LIST_SIZE > 38
#  include <boost/mpl/vector/vector50.hpp>
# elif BOOST_PYTHON_LIST_SIZE > 28
#  include <boost/mpl/vector/vector40.hpp>
# elif BOOST_PYTHON_LIST_SIZE > 18
#  include <boost/mpl/vector/vector30.hpp>
# elif BOOST_PYTHON_LIST_SIZE > 8
#  include <boost/mpl/vector/vector20.hpp>
# else
#  include <boost/mpl/vector/vector10.hpp>
# endif

#  include "pxr/external/boost/python/detail/type_list_impl.hpp"

#endif // PXR_EXTERNAL_BOOST_PYTHON_DETAIL_TYPE_LIST_HPP
