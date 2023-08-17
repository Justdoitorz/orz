/**
 * @file orz_cdef.s.h
 * @author Orz (justdoit_dog@163.com)
 * @brief For the freedom!
 * @version 0.1
 * @date 2023-07-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __ORZ_CDEFS_H__
#define __ORZ_CDEFS_H__

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#ifdef __cplusplus

#   define __ORZ_C_SYMBOL__ extern "C"
#   define __ORZ_C_ENTER__  extern "C" {
#   define __ORZ_C_LEAVE__  }
#   define __ORZ_FUNC__     __PRETTY_FUNCTION__

#else

#   define __ORZ_C_SYMBOL__
#   define __ORZ_C_ENTER__  
#   define __ORZ_C_LEAVE__  
#   define __ORZ_FUNC__     __FUNCTION__ 

#endif 

#if defined(__GNUC__) && __GNUC__ >= 4
#   define __ORZ_EXPORT __attribute((visibility("default")))
#else
#   define __ORZ_EXPORT
#endif

#endif //__ORZ_CDEFS_H__