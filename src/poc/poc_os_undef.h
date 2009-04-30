/*
 * Copyright (c) 2009, Bjoern Knafla
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the 
 * following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this list of conditions and the following 
 *   disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following 
 *   disclaimer in the documentation and/or other materials provided with the distribution.
 * - Neither the name of the Bjoern Knafla nor the names of its contributors may be used to 
 *   endorse or promote products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file
 *
 * Undefines all preprocessor symbols potentially set by @c poc_os_def.h.
 *
 * @attention This header doesn't have header guards to allow successive inclusion.
 */


#if !defined(POC_OS_HEADER_DISABLE_DEF_UNDEF)

#undef POC_OS
#undef POC_OS_STRING

#undef POC_OS_UNKNOWN
#undef POC_OS_UNKNOWN_ID
#undef POC_OS_UNKNOWN_STRING

#undef POC_OS_UNIX
#undef POC_OS_UNIX_ID
#undef POC_OS_UNIX_STRING

#undef POC_OS_MACOSX
#undef POC_OS_MACOSX_ID
#undef POC_OS_MACOSX_STRING

#undef POC_OS_LINUX
#undef POC_OS_LINUX_ID
#undef POC_OS_LINUX_STRING

#undef POC_OS_WIN
#undef POC_OS_WIN_ID
#undef POC_OS_WIN_STRING

#undef POC_OS_WIN32
#undef POC_OS_WIN32_ID
#undef POC_OS_WIN32_STRING

#undef POC_OS_WIN64
#undef POC_OS_WIN64_ID
#undef POC_OS_WIN64_STRING



#endif // !defined(POC_OS_HEADER_DISABLE_DEF_UNDEF)
