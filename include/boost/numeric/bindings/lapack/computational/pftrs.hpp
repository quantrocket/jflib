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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_PFTRS_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_PFTRS_HPP

#include <boost/assert.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/numeric/bindings/lapack/detail/lapack.h>
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
    inline void pftrs( char const transr, char const uplo, integer_t const n,
            integer_t const nrhs, float* a, float* b, integer_t const ldb,
            integer_t& info ) {
        LAPACK_SPFTRS( &transr, &uplo, &n, &nrhs, a, b, &ldb, &info );
    }
    inline void pftrs( char const transr, char const uplo, integer_t const n,
            integer_t const nrhs, double* a, double* b, integer_t const ldb,
            integer_t& info ) {
        LAPACK_DPFTRS( &transr, &uplo, &n, &nrhs, a, b, &ldb, &info );
    }
    inline void pftrs( char const transr, char const uplo, integer_t const n,
            integer_t const nrhs, traits::complex_f* a, traits::complex_f* b,
            integer_t const ldb, integer_t& info ) {
        LAPACK_CPFTRS( &transr, &uplo, &n, &nrhs, traits::complex_ptr(a),
                traits::complex_ptr(b), &ldb, &info );
    }
    inline void pftrs( char const transr, char const uplo, integer_t const n,
            integer_t const nrhs, traits::complex_d* a, traits::complex_d* b,
            integer_t const ldb, integer_t& info ) {
        LAPACK_ZPFTRS( &transr, &uplo, &n, &nrhs, traits::complex_ptr(a),
                traits::complex_ptr(b), &ldb, &info );
    }
}

// value-type based template
template< typename ValueType, typename Enable = void >
struct pftrs_impl{};

// real specialization
template< typename ValueType >
struct pftrs_impl< ValueType, typename boost::enable_if< traits::is_real<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // templated specialization
    template< typename VectorA, typename MatrixB >
    static void invoke( char const transr, integer_t const n, VectorA& a,
            MatrixB& b, integer_t& info ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorA >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type >::value) );
        BOOST_ASSERT( transr == 'N' || transr == 'T' );
        BOOST_ASSERT( traits::matrix_uplo_tag(rfp) == 'U' ||
                traits::matrix_uplo_tag(rfp) == 'L' );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( traits::matrix_num_columns(b) >= 0 );
        BOOST_ASSERT( traits::vector_size(a) >= n*(n+1)/2 );
        BOOST_ASSERT( traits::leading_dimension(b) >= std::max(1,n) );
        detail::pftrs( transr, traits::matrix_uplo_tag(rfp), n,
                traits::matrix_num_columns(b), traits::vector_storage(a),
                traits::matrix_storage(b), traits::leading_dimension(b),
                info );
    }
};

// complex specialization
template< typename ValueType >
struct pftrs_impl< ValueType, typename boost::enable_if< traits::is_complex<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // templated specialization
    template< typename VectorA, typename MatrixB >
    static void invoke( char const transr, integer_t const n, VectorA& a,
            MatrixB& b, integer_t& info ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorA >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type >::value) );
        BOOST_ASSERT( transr == 'N' || transr == 'C' );
        BOOST_ASSERT( traits::matrix_uplo_tag(rfp) == 'U' ||
                traits::matrix_uplo_tag(rfp) == 'L' );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( traits::matrix_num_columns(b) >= 0 );
        BOOST_ASSERT( traits::vector_size(a) >= n*(n+1)/2 );
        BOOST_ASSERT( traits::leading_dimension(b) >= std::max(1,n) );
        detail::pftrs( transr, traits::matrix_uplo_tag(rfp), n,
                traits::matrix_num_columns(b), traits::vector_storage(a),
                traits::matrix_storage(b), traits::leading_dimension(b),
                info );
    }
};


// template function to call pftrs
template< typename VectorA, typename MatrixB >
inline integer_t pftrs( char const transr, integer_t const n, VectorA& a,
        MatrixB& b ) {
    typedef typename traits::vector_traits< VectorA >::value_type value_type;
    integer_t info(0);
    pftrs_impl< value_type >::invoke( transr, n, a, b, info );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
