//
// Copyright (c) 2003--2009
// Toon Knapen, Karl Meerbergen, Kresimir Fresl,
// Thomas Klimpel and Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// THIS FILE IS AUTOMATICALLY GENERATED
// PLEASE DO NOT EDIT!
//

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_TGEVC_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_TGEVC_HPP

#include <boost/assert.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/numeric/bindings/lapack/detail/lapack.h>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
#include <boost/numeric/bindings/traits/is_complex.hpp>
#include <boost/numeric/bindings/traits/is_real.hpp>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/utility/enable_if.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//$DESCRIPTION

// overloaded functions to call lapack
namespace detail {
    inline void tgevc( char const side, char const howmny, logical_t* select,
            integer_t const n, float* s, integer_t const lds, float* p,
            integer_t const ldp, float* vl, integer_t const ldvl, float* vr,
            integer_t const ldvr, integer_t const mm, integer_t& m,
            float* work, integer_t& info ) {
        LAPACK_STGEVC( &side, &howmny, select, &n, s, &lds, p, &ldp, vl,
                &ldvl, vr, &ldvr, &mm, &m, work, &info );
    }
    inline void tgevc( char const side, char const howmny, logical_t* select,
            integer_t const n, double* s, integer_t const lds, double* p,
            integer_t const ldp, double* vl, integer_t const ldvl, double* vr,
            integer_t const ldvr, integer_t const mm, integer_t& m,
            double* work, integer_t& info ) {
        LAPACK_DTGEVC( &side, &howmny, select, &n, s, &lds, p, &ldp, vl,
                &ldvl, vr, &ldvr, &mm, &m, work, &info );
    }
    inline void tgevc( char const side, char const howmny, logical_t* select,
            integer_t const n, traits::complex_f* s, integer_t const lds,
            traits::complex_f* p, integer_t const ldp, traits::complex_f* vl,
            integer_t const ldvl, traits::complex_f* vr, integer_t const ldvr,
            integer_t const mm, integer_t& m, traits::complex_f* work,
            float* rwork, integer_t& info ) {
        LAPACK_CTGEVC( &side, &howmny, select, &n, traits::complex_ptr(s),
                &lds, traits::complex_ptr(p), &ldp, traits::complex_ptr(vl),
                &ldvl, traits::complex_ptr(vr), &ldvr, &mm, &m,
                traits::complex_ptr(work), rwork, &info );
    }
    inline void tgevc( char const side, char const howmny, logical_t* select,
            integer_t const n, traits::complex_d* s, integer_t const lds,
            traits::complex_d* p, integer_t const ldp, traits::complex_d* vl,
            integer_t const ldvl, traits::complex_d* vr, integer_t const ldvr,
            integer_t const mm, integer_t& m, traits::complex_d* work,
            double* rwork, integer_t& info ) {
        LAPACK_ZTGEVC( &side, &howmny, select, &n, traits::complex_ptr(s),
                &lds, traits::complex_ptr(p), &ldp, traits::complex_ptr(vl),
                &ldvl, traits::complex_ptr(vr), &ldvr, &mm, &m,
                traits::complex_ptr(work), rwork, &info );
    }
}

// value-type based template
template< typename ValueType, typename Enable = void >
struct tgevc_impl{};

// real specialization
template< typename ValueType >
struct tgevc_impl< ValueType, typename boost::enable_if< traits::is_real<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename VectorSELECT, typename MatrixS, typename MatrixP,
            typename MatrixVL, typename MatrixVR, typename WORK >
    static void invoke( char const side, char const howmny,
            VectorSELECT& select, integer_t const n, MatrixS& s, MatrixP& p,
            MatrixVL& vl, MatrixVR& vr, integer_t const mm, integer_t& m,
            integer_t& info, detail::workspace1< WORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixS >::value_type, typename traits::matrix_traits<
                MatrixP >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixS >::value_type, typename traits::matrix_traits<
                MatrixVL >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixS >::value_type, typename traits::matrix_traits<
                MatrixVR >::value_type >::value) );
        BOOST_ASSERT( side == 'R' || side == 'L' || side == 'B' );
        BOOST_ASSERT( howmny == 'A' || howmny == 'B' || howmny == 'S' );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( traits::leading_dimension(s) >= std::max(1,n) );
        BOOST_ASSERT( traits::leading_dimension(p) >= std::max(1,n) );
        BOOST_ASSERT( mm >= m );
        BOOST_ASSERT( traits::vector_size(work.select(real_type())) >=
                min_size_work( n ));
        detail::tgevc( side, howmny, traits::vector_storage(select), n,
                traits::matrix_storage(s), traits::leading_dimension(s),
                traits::matrix_storage(p), traits::leading_dimension(p),
                traits::matrix_storage(vl), traits::leading_dimension(vl),
                traits::matrix_storage(vr), traits::leading_dimension(vr), mm,
                m, traits::vector_storage(work.select(real_type())), info );
    }

    // minimal workspace specialization
    template< typename VectorSELECT, typename MatrixS, typename MatrixP,
            typename MatrixVL, typename MatrixVR >
    static void invoke( char const side, char const howmny,
            VectorSELECT& select, integer_t const n, MatrixS& s, MatrixP& p,
            MatrixVL& vl, MatrixVR& vr, integer_t const mm, integer_t& m,
            integer_t& info, minimal_workspace work ) {
        traits::detail::array< real_type > tmp_work( min_size_work( n ) );
        invoke( side, howmny, select, n, s, p, vl, vr, mm, m, info,
                workspace( tmp_work ) );
    }

    // optimal workspace specialization
    template< typename VectorSELECT, typename MatrixS, typename MatrixP,
            typename MatrixVL, typename MatrixVR >
    static void invoke( char const side, char const howmny,
            VectorSELECT& select, integer_t const n, MatrixS& s, MatrixP& p,
            MatrixVL& vl, MatrixVR& vr, integer_t const mm, integer_t& m,
            integer_t& info, optimal_workspace work ) {
        invoke( side, howmny, select, n, s, p, vl, vr, mm, m, info,
                minimal_workspace() );
    }

    static integer_t min_size_work( integer_t const n ) {
        return 6*n;
    }
};

// complex specialization
template< typename ValueType >
struct tgevc_impl< ValueType, typename boost::enable_if< traits::is_complex<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename VectorSELECT, typename MatrixS, typename MatrixP,
            typename MatrixVL, typename MatrixVR, typename WORK,
            typename RWORK >
    static void invoke( char const side, char const howmny,
            VectorSELECT& select, integer_t const n, MatrixS& s, MatrixP& p,
            MatrixVL& vl, MatrixVR& vr, integer_t const mm, integer_t& m,
            integer_t& info, detail::workspace2< WORK, RWORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixS >::value_type, typename traits::matrix_traits<
                MatrixP >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixS >::value_type, typename traits::matrix_traits<
                MatrixVL >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixS >::value_type, typename traits::matrix_traits<
                MatrixVR >::value_type >::value) );
        BOOST_ASSERT( side == 'R' || side == 'L' || side == 'B' );
        BOOST_ASSERT( howmny == 'A' || howmny == 'B' || howmny == 'S' );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( traits::leading_dimension(s) >= std::max(1,n) );
        BOOST_ASSERT( traits::leading_dimension(p) >= std::max(1,n) );
        BOOST_ASSERT( mm >= m );
        BOOST_ASSERT( traits::vector_size(work.select(value_type())) >=
                min_size_work( n ));
        BOOST_ASSERT( traits::vector_size(work.select(real_type())) >=
                min_size_rwork( n ));
        detail::tgevc( side, howmny, traits::vector_storage(select), n,
                traits::matrix_storage(s), traits::leading_dimension(s),
                traits::matrix_storage(p), traits::leading_dimension(p),
                traits::matrix_storage(vl), traits::leading_dimension(vl),
                traits::matrix_storage(vr), traits::leading_dimension(vr), mm,
                m, traits::vector_storage(work.select(value_type())),
                traits::vector_storage(work.select(real_type())), info );
    }

    // minimal workspace specialization
    template< typename VectorSELECT, typename MatrixS, typename MatrixP,
            typename MatrixVL, typename MatrixVR >
    static void invoke( char const side, char const howmny,
            VectorSELECT& select, integer_t const n, MatrixS& s, MatrixP& p,
            MatrixVL& vl, MatrixVR& vr, integer_t const mm, integer_t& m,
            integer_t& info, minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work( n ) );
        traits::detail::array< real_type > tmp_rwork( min_size_rwork( n ) );
        invoke( side, howmny, select, n, s, p, vl, vr, mm, m, info,
                workspace( tmp_work, tmp_rwork ) );
    }

    // optimal workspace specialization
    template< typename VectorSELECT, typename MatrixS, typename MatrixP,
            typename MatrixVL, typename MatrixVR >
    static void invoke( char const side, char const howmny,
            VectorSELECT& select, integer_t const n, MatrixS& s, MatrixP& p,
            MatrixVL& vl, MatrixVR& vr, integer_t const mm, integer_t& m,
            integer_t& info, optimal_workspace work ) {
        invoke( side, howmny, select, n, s, p, vl, vr, mm, m, info,
                minimal_workspace() );
    }

    static integer_t min_size_work( integer_t const n ) {
        return 2*n;
    }

    static integer_t min_size_rwork( integer_t const n ) {
        return 2*n;
    }
};


// template function to call tgevc
template< typename VectorSELECT, typename MatrixS, typename MatrixP,
        typename MatrixVL, typename MatrixVR, typename Workspace >
inline integer_t tgevc( char const side, char const howmny,
        VectorSELECT& select, integer_t const n, MatrixS& s, MatrixP& p,
        MatrixVL& vl, MatrixVR& vr, integer_t const mm, integer_t& m,
        Workspace work ) {
    typedef typename traits::matrix_traits< MatrixS >::value_type value_type;
    integer_t info(0);
    tgevc_impl< value_type >::invoke( side, howmny, select, n, s, p, vl,
            vr, mm, m, info, work );
    return info;
}

// template function to call tgevc, default workspace type
template< typename VectorSELECT, typename MatrixS, typename MatrixP,
        typename MatrixVL, typename MatrixVR >
inline integer_t tgevc( char const side, char const howmny,
        VectorSELECT& select, integer_t const n, MatrixS& s, MatrixP& p,
        MatrixVL& vl, MatrixVR& vr, integer_t const mm, integer_t& m ) {
    typedef typename traits::matrix_traits< MatrixS >::value_type value_type;
    integer_t info(0);
    tgevc_impl< value_type >::invoke( side, howmny, select, n, s, p, vl,
            vr, mm, m, info, optimal_workspace() );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
