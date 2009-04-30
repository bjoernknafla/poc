


#if !defined(POC_STATIC_ASSERT_HEADER_DISABLE_DEF_UNDEF)


#include "poc_preprocessor_utilities_def.h"


#ifndef POC_poc_poc_static_assert_def_H
#define POC_poc_poc_static_assert_def_H


namespace poc 
{
    namespace internal {
        
        /*
         * Declaration but not definition - therefore the @c POC_STATIC_ASSERT macro can only
         * instantiate it if @c Expr is @c true, which means that the assertion is valid. 
         * If it can't be instantiated the compiler fails and pinpoints the invalid assertion.
         *
         * Don't use directly.
         */
        template< bool Expr>
        struct static_assertion_test;
        
        /*
         * Specialization of @c static_assertion_test which can be instantiated.
         *
         * Don't use directly.
         */
        template<>
        struct static_assertion_test< true > {
            static_assertion_test( char const* /* message */ ) {}
        };
        
        /*
         * Additional class to @c static_assertion_test.
         *
         * Don't use directly.
         */
        template< int >
        struct static_assertion {};
        
    } // namespace internal    
} // namespace poc



#endif // POC_poc_poc_static_assert_def_H



/**
 * Asserts at compile time that the compile time evaluable expression is @c true.
 * 
 * @a expr must be a compile time evalueable expression, like 
 * @code sizeof( char ) <= sizeof( int ) @endcode .
 * @a msg must be a string describing the assertion.
 *
 * If @a expr is evaluated to @c true a specialized definition of the 
 * @c static_assertion_test template class can be instantiated. A good compiler
 * will then remove the non-used @c typedef.
 *
 * If @a expr is evaluated to @c false , if the assertion is wrong, no object
 * can be created because the definition is missing and the compiler will fail with an error.
 *
 * The typedef allows calling the macro even directly in a header or a source
 * file and surpresses warnings about unused variables in functions. Idea 
 * based on Boost's @c BOOST_STATIC_ASSERT and the POSH libraries @c POSH_COMPILE_TIME_ASSERT, 
 * see
 * http://www.boost.org/doc/libs/1_35_0/doc/html/boost_staticassert.html
 * and
 * http://www.bookofhook.com/poshlib/index.html
 */
#define POC_STATIC_ASSERT( EXPR, MSG ) \
typedef ::poc::internal::static_assertion< \
sizeof( ::poc::internal::static_assertion_test< (0 != (EXPR) ) >( MSG ) ) > \
POC_CONCAT(POC_STATIC_ASSERTION_, __LINE__ )




#endif // !defined(POC_STATIC_ASSERT_HEADER_DISABLE_DEF_UNDEF)




