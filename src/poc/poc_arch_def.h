/*
 * Copyright (c) 2009, Bjoern Knafla
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this 
 *   list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice, 
 *   this list of conditions and the following disclaimer in the documentation 
 *   and/or other materials provided with the distribution.
 * - Neither the name of the Bjoern Knafla nor the names of its contributors may 
 *   be used to endorse or promote products derived from this software without 
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file
 *
 * Include poc_arch_undef.h  to undefine all preprocessor symbols potentially set herein.
 *
 * See poc_arch.h for details.
 *
 * @attention This header doesn't have header guards to allow successive inclusion of it and its sibling 
 *            poc_arch_undef.h . If header guards are wanted or needed use poc.h or 
 *            poc_arch.h instead.
 *
 * @todo TODO: Detect if running on a CUDA device or on a @c __DEVICE_EMULATION__ and if running on the host or the 
 *             device.
 * @todo TODO: Detect if running on a OpenCL host or device and which one the moment this is possible to detect.
 * @todo TODO: Add support for iPhone, iPod Touch, and device emulation.
 */

/* Only allow definition of POC machine architecture macros if poc_arch.h hasn't been included 
 * in this compilation unit.
 */
#if !defined(POC_ARCH_HEADER_DISABLE_DEF_UNDEF)



/***************************************************************************//**
 * @name Predefined architecture ids
 ******************************************************************************/
/*@{*/
#define POC_ARCH_UNKNOWN_ID (1)
#define POC_ARCH_X86_ID (1 << 1)
#define POC_ARCH_X86_32_ID (1 << 2)
#define POC_ARCH_X86_64_ID (1 << 3)
#define POC_ARCH_PPC_ID (1 << 4)
#define POC_ARCH_PPC64_ID (1 << 5)
#define POC_ARCH_ARM_ID (1 << 6)
#define POC_ARCH_ARM_THUMB_ID (1 << 7)
#define POC_ARCH_CELL_PPU_ID (1 << 8)
#define POC_ARCH_CELL_SPU_ID (1 << 9)
#define POC_ARCH_CELL_SPU_EDP_ID (1 << 10)
/*@}*/


/***************************************************************************//**
 * @name Predefined architecture strings
 *
 * See http://predef.sourceforge.net/index.php for macros defined by language 
 * standards, compilers, libraries, etc.
 ******************************************************************************/
/*@{*/
#define POC_ARCH_UNKNOWN_STRING "Unknown architecture"
#define POC_ARCH_X86_STRING "x86"
#define POC_ARCH_X86_32_STRING "x86-32"
#define POC_ARCH_X86_64_STRING "x86-64"
#define POC_ARCH_PPC_STRING "PowerPC"
#define POC_ARCH_PPC64_STRING "PowerPC64"
#define POC_ARCH_ARM_STRING "ARM"
#define POC_ARCH_ARM_THUMB_STRING "ARM Thumb"
#define POC_ARCH_CELL_PPU_STRING "Cell BE PPU"
#define POC_ARCH_CELL_SPU_STRING "Cell BE SPU"
/* Cell BE SPU nhanced double-precision instructions */
#define POC_ARCH_CELL_SPU_EDP_STRING "Cell BE SPU EDP"
/*@}*/


/* 
 * If @c POC_ARCH_DISABLE_AUTODETECT or @c POC_DISABLE_AUTODETECT is defined no 
 * automatic operating system detection 
 * takes place.
 */
#if !defined(POC_ARCH_DISABLE_AUTODETECT) && !defined(POC_DISABLE_AUTODETECT)


/*******************************************************************************
 * Detect architecture
 ******************************************************************************/


/* Detect x86_32 (not x86_64)
 */
#if defined(i386) \
|| defined(__i386) \
|| defined(__i386__) \
|| defined(_M_IX86) \
|| defined(_X86_) \
|| defined(__THW_INTEL__) \
|| defined(__I86__) \
|| defined(__INTEL__)
#   define POC_ARCH_X86 POC_ARCH_X86_ID
#   define POC_ARCH_X86_32 POC_ARCH_X86_32_ID
#endif


/* Detect x86_64 (AMD not (!!) Itanium)
 */
#if defined(__x86_64) || defined(__x86_64__) || defined(__amd64) || defined(__amd64__) || defined(_M_X64)
#   define POC_ARCH_X86 POC_ARCH_X86_ID
#   define POC_ARCH_X86_64 POC_ARCH_X86_64_ID
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif


/* Detect PowerPC and PowerPC64
 */
#if defined(__ppc__) || defined(__ppc64__) || defined(__PPU__)
#   define POC_ARCH_PPC POC_ARCH_PPC_ID
#   if defined(__ppc64__) || defined(__PPU__)
#       define POC_ARCH_PPC64 POC_ARCH_PPC64_ID
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

/* Detect ARM and ARM Thumb
 */
#if defined(__arm__) || (__thumb__)
#   if defined(__arm__)
#       define POC_ARCH_ARM POC_ARCH_ARM_ID
#   endif
#   if defined(__thumb__)
#       define POC_ARCH_ARM_THUMB POC_ARCH_ARM_THUMB_ID
#   endif
#endif

/* Detect Cell PPU
 */
/**
 * @todo TODO: Check if @c __PPC__ macros and @c __PPU__ macros are defined when
 *       compiling for the Cell.
 */
#if defined(__PPU__)
#   if !defined(POC_ARCH_PPC)
#       define POC_ARCH_PPC POC_ARCH_PPC_ID
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   if !defined(POC_ARCH_PPC64)
#       define POC_ARCH_PPC64 POC_ARCH_PPC64_ID
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   define POC_ARCH_CELL_PPU POC_ARCH_CELL_PPU_ID
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

/* Detect Cell SPU or Cell SPU with enhanced double precision instructions
 */
#if defined(__SPU__) || defined(__SPU_EDP__)
#   define POC_ARCH_CELL_SPU POC_ARCH_CELL_SPU_ID
#   if defined(__SPU_EDP__)
#       define POC_ARCH_CELL_SPU_EDP POC_ARCH_CELL_SPU_EDP_ID
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

/*******************************************************************************
 * Determine @c POC_ARCH_STRING and @c POC_ARCH_ID
 ******************************************************************************/


#if defined(POC_ARCH_X86_32)
#   define POC_ARCH (POC_ARCH_X86_ID | POC_ARCH_X86_32_ID)
#   define POC_ARCH_STRING POC_ARCH_X86_32_STRING
#endif

#if defined(POC_ARCH_X86_64)
#   define POC_ARCH (POC_ARCH_X86_ID | POC_ARCH_X86_64_ID)
#   define POC_ARCH_STRING POC_ARCH_X86_64_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(POC_ARCH_PPC)
#   define POC_ARCH POC_ARCH_PPC_ID
#   define POC_ARCH_STRING POC_ARCH_PPC_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(POC_ARCH_PPC64)
#   undef POC_ARCH
#   undef POC_ARCH_STRING
#   define POC_ARCH (POC_ARCH_PPC_ID | POC_ARCH_PPC64_ID)
#   define POC_ARCH_STRING  POC_ARCH_PPC64_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(POC_ARCH_ARM)
#   define POC_ARCH POC_ARCH_ARM_ID
#   define POC_ARCH_STRING  POC_ARCH_ARM_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(POC_ARCH_ARM_THUMB)
#   define POC_ARCH POC_ARCH_ARM_THUMB_ID
#   define POC_ARCH_STRING  POC_ARCH_ARM_THUMB_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(POC_ARCH_CELL_PPU)
#   undef POC_ARCH
#   undef POC_ARCH_STRING
#   define POC_ARCH (POC_ARCH_PPC_ID | POC_ARCH_PPC64_ID | POC_ARCH_CELL_PPU_ID)
#   define POC_ARCH_STRING  POC_ARCH_CELL_PPU_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(POC_ARCH_CELL_SPU)
#   define POC_ARCH POC_ARCH_CELL_SPU_ID
#   define POC_ARCH_STRING  POC_ARCH_CELL_SPU_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(POC_ARCH_CELL_SPU_EDP)
#   undef POC_ARCH
#   undef POC_ARCH_STRING
#   define POC_ARCH (POC_ARCH_CELL_SPU_ID | POC_ARCH_CELL_SPU_EDP_ID)
#   define POC_ARCH_STRING  POC_ARCH_CELL_SPU_EDP_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#endif /* !defined(POC_ARCH_DISABLE_AUTODETECT) && !defined(POC_DISABLE_AUTODETECT) */



/* No known architecture detected
 */
#if !defined(POC_ARCH)
#   define POC_ARCH_UNKNOWN POC_ARCH_UNKNOWN_ID
#   define POC_ARCH POC_ARCH_UNKNOWN_ID
#   error Machine architecture unknown.
#endif 

#if !defined(POC_ARCH_STRING)
#   define POC_ARCH_STRING POC_ARCH_UNKNOWN_STRING
#   error Machine architecture string unknown.
#endif

/*******************************************************************************
 * Error detection
 ******************************************************************************/



/* 
 * Exactly one architecture must have been detected - xor tests to find possible 
 * error.
 */
#if defined(POC_ARCH_X86) && !(defined(POC_ARCH_X86_32) || defined(POC_ARCH_X86_64))
#   error If POC_ARCH_X86 is defined POC_ARCH_X86_32 or POC_ARCH_X86_64 must also be defined.
#endif

#if defined(POC_ARCH_X86_32) && \
(!defined(POC_ARCH_X86) || \
 defined(POC_ARCH_X86_64) || \
 defined(POC_ARCH_PPC) || \
 defined(POC_ARCH_PPC64) || \
 defined(POC_ARCH_ARM) || \
 defined(POC_ARCH_ARM_THUMB) || \
 defined(POC_ARCH_UNKNOWN) || \
 defined(POC_ARCH_CELL_PPU) || \
 defined(POC_ARCH_CELL_SPU) || \
 defined(POC_ARCH_CELL_SPU_EDP))
#   error Exactly one architecture must be selected.
#endif

#if defined(POC_ARCH_X86_64) && \
(!defined(POC_ARCH_X86) || \
defined(POC_ARCH_X86_32) || \
defined(POC_ARCH_PPC) || \
defined(POC_ARCH_PPC64) || \
defined(POC_ARCH_ARM) || \
defined(POC_ARCH_ARM_THUMB) || \
defined(POC_ARCH_UNKNOWN) || \
defined(POC_ARCH_CELL_PPU) || \
defined(POC_ARCH_CELL_SPU) || \
defined(POC_ARCH_CELL_SPU_EDP) )
#   error Exactly one architecture must be selected.
#endif

#if defined(POC_ARCH_PPC) && \
(defined(POC_ARCH_X86) || \
defined(POC_ARCH_X86_64) || \
defined(POC_ARCH_X86_32) || \
/* defined(POC_ARCH_PPC64) || \ */ \
defined(POC_ARCH_ARM) || \
defined(POC_ARCH_ARM_THUMB) || \
defined(POC_ARCH_UNKNOWN) || \
/* defined(POC_ARCH_CELL_PPU) || \ */ \
defined(POC_ARCH_CELL_SPU) || \
defined(POC_ARCH_CELL_SPU_EDP) )
#   error Exactly one architecture must be selected.
#endif

#if defined(POC_ARCH_PPC64) && !defined(POC_ARCH_PPC) 
#   error If POC_ARCH_PPC64 is defined, POC_ARCH_PPC must also be defined.
#endif

#if defined(POC_ARCH_PPC64) && \
(defined(POC_ARCH_X86) || \
defined(POC_ARCH_X86_64) || \
defined(POC_ARCH_X86_32) || \
/* defined(POC_ARCH_PPC) || \ */ \
defined(POC_ARCH_ARM) || \
defined(POC_ARCH_ARM_THUMB) || \
defined(POC_ARCH_UNKNOWN) || \
/* defined(POC_ARCH_CELL_PPU) || \ */ \
defined(POC_ARCH_CELL_SPU) || \
defined(POC_ARCH_CELL_SPU_EDP) )
#   error Exactly one architecture must be selected.
#endif

#if defined(POC_ARCH_CELL_PPU) && !defined(POC_ARCH_PPC) && !defined(POC_ARCH_PPC64)
#   error If POC_ARCH_CELL_PPU is defined, POC_ARCH_PPC and POC_ARCH_PPC64 must also be defined.
#endif

#if defined(POC_ARCH_CELL_PPU) && \
(defined(POC_ARCH_X86) || \
defined(POC_ARCH_X86_64) || \
defined(POC_ARCH_X86_32) || \
/* defined(POC_ARCH_PPC64) || \ */ \
defined(POC_ARCH_ARM) || \
defined(POC_ARCH_ARM_THUMB) || \
/* defined(POC_ARCH_PPC) || \ */ \
defined(POC_ARCH_UNKNOWN) || \
defined(POC_ARCH_CELL_SPU) || \
defined(POC_ARCH_CELL_SPU_EDP) )
#   error Exactly one architecture must be selected.
#endif


#if defined(POC_ARCH_CELL_SPU) && \
(defined(POC_ARCH_X86) || \
defined(POC_ARCH_X86_64) || \
defined(POC_ARCH_X86_32) || \
defined(POC_ARCH_PPC64) || \
defined(POC_ARCH_ARM) || \
defined(POC_ARCH_ARM_THUMB) || \
defined(POC_ARCH_PPC) || \
defined(POC_ARCH_UNKNOWN) || \
defined(POC_ARCH_CELL_PPU) \
/* defined(POC_ARCH_CELL_SPU_EDP) */ )
#   error Exactly one architecture must be selected.
#endif


#if defined(POC_ARCH_CELL_SPU_EDP) && \
(defined(POC_ARCH_X86) || \
defined(POC_ARCH_X86_64) || \
defined(POC_ARCH_X86_32) || \
defined(POC_ARCH_PPC64) || \
defined(POC_ARCH_ARM) || \
defined(POC_ARCH_ARM_THUMB) || \
defined(POC_ARCH_PPC) || \
defined(POC_ARCH_UNKNOWN) || \
defined(POC_ARCH_CELL_PPU) || \
! defined(POC_ARCH_CELL_SPU) )
#   error Exactly one architecture must be selected.
#endif



#if defined(POC_ARCH_ARM) && \
(defined(POC_ARCH_X86_64) || \
defined(POC_ARCH_X86_32) || \
defined(POC_ARCH_PPC64) || \
defined(POC_ARCH_PPC) || \
defined(POC_ARCH_ARM_THUMB) || \
defined(POC_ARCH_UNKNOWN) || \
defined(POC_ARCH_CELL_PPU) || \
defined(POC_ARCH_CELL_SPU) || \
defined(POC_ARCH_CELL_SPU_EDP) )
#   error Exactly one architecture must be selected.
#endif

#if defined(POC_ARCH_ARM_THUMB) && \
(defined(POC_ARCH_X86) || \
defined(POC_ARCH_X86_64) || \
defined(POC_ARCH_X86_32) || \
defined(POC_ARCH_PPC64) || \
defined(POC_ARCH_ARM) || \
defined(POC_ARCH_PPC) || \
defined(POC_ARCH_UNKNOWN) || \
defined(POC_ARCH_CELL_PPU) || \
defined(POC_ARCH_CELL_SPU) || \
defined(POC_ARCH_CELL_SPU_EDP) )
#   error Exactly one architecture must be selected.
#endif

#if defined(POC_ARCH_UNKNOWN) && \
(defined(POC_ARCH_X86) || \
defined(POC_ARCH_X86_64) || \
defined(POC_ARCH_X86_32) || \
defined(POC_ARCH_PPC64) || \
defined(POC_ARCH_ARM) || \
defined(POC_ARCH_ARM_THUMB) || \
defined(POC_ARCH_PPC) || \
defined(POC_ARCH_CELL_PPU) || \
defined(POC_ARCH_CELL_SPU) || \
defined(POC_ARCH_CELL_SPU_EDP) )
#   error Exactly one architecture must be selected.
#endif



#endif /* !defined(POC_ARCH_HEADER_DISABLE_DEF_UNDEF) */

