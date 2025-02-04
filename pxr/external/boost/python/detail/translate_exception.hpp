//
// Copyright 2024 Pixar
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#ifndef PXR_EXTERNAL_BOOST_PYTHON_DETAIL_TRANSLATE_EXCEPTION_HPP
# define PXR_EXTERNAL_BOOST_PYTHON_DETAIL_TRANSLATE_EXCEPTION_HPP

# include "pxr/external/boost/python/detail/exception_handler.hpp"
# include "pxr/external/boost/python/detail/type_traits.hpp"

# include <boost/call_traits.hpp>

# include <boost/function/function0.hpp>

namespace boost { namespace python { namespace detail { 

// A ternary function object used to translate C++ exceptions of type
// ExceptionType into Python exceptions by invoking an object of type
// Translate. Typically the translate function will be curried with
// boost::bind().
template <class ExceptionType, class Translate>
struct translate_exception
{
// workaround for broken gcc that ships with SuSE 9.0 and SuSE 9.1
# if defined(__linux__) && defined(__GNUC__) \
    && BOOST_WORKAROUND(__GNUC__, == 3) \
    && BOOST_WORKAROUND(__GNUC_MINOR__, == 3) \
    && (BOOST_WORKAROUND(__GNUC_PATCHLEVEL__, == 1) \
        || BOOST_WORKAROUND(__GNUC_PATCHLEVEL__, == 3))
    typedef typename remove_reference<
        typename add_const<ExceptionType>::type
    >::type exception_non_ref;
# else
    typedef typename add_lvalue_reference<
        typename add_const<ExceptionType>::type
    >::type exception_cref;
# endif
    
    inline bool operator()(
        exception_handler const& handler
      , function0<void> const& f
      , typename call_traits<Translate>::param_type translate) const
    {
        try
        {
            return handler(f);
        }
// workaround for broken gcc that ships with SuSE 9.0 and SuSE 9.1
# if defined(__linux__) && defined(__GNUC__) \
    && BOOST_WORKAROUND(__GNUC__, == 3) \
    && BOOST_WORKAROUND(__GNUC_MINOR__, == 3) \
    && (BOOST_WORKAROUND(__GNUC_PATCHLEVEL__, == 1) \
        || BOOST_WORKAROUND(__GNUC_PATCHLEVEL__, == 3))
        catch(exception_non_ref& e)
# else
        catch(exception_cref e)
# endif
        {
            translate(e);
            return true;
        }
    }
};

}}} // namespace boost::python::detail

#endif // TRANSLATE_EXCEPTION_DWA2002810_HPP
