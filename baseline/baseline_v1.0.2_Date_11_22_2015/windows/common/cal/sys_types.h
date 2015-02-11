/*---------------------------------------------------------------------------
** Project Name: UiMagician
** #Archive:
** #Author: # Dinesh Guleria
** #Date: # 15-03-2013
** Copyright (C) 2012-2014 Dinesh Guleria, VSCP Developer
**----------------------------------------------------------------------------
** #Revision: 1 #
**----------------------------------------------------------------------------
** Target system: QT - 4.8.1
** Compiler:
**----------------------------------------------------------------------------
**               A U T H O R   I D E N T I T Y
**----------------------------------------------------------------------------
** Initials           Name                     Project
** --------           ---------------------    -------------------------------
** DINESH.GULERIA     Dinesh Guleria           UiMagician
**----------------------------------------------------------------------------
**               R E V I S I O N   H I S T O R Y
**----------------------------------------------------------------------------
** #Log:
** 1. Creation of the file.
** 2. Review the implementation to bring it to 100%.
**--------------------------------------------------------------------------*/


// sys_types.h
//

// TODO should be moved to platform file.
#define SIZEOF_CHAR         1
#define SIZEOF_SHORT        2
#define SIZEOF_INT          4
//#ifndef _MSC_EXTENSIONS
#define SIZEOF_LONG_LONG    8
//#endif


#ifndef ___int8_t_defined
#define ___int8_t_defined

////#ifdef __VISUALC__
// VC6 does not support 'long long'.
// http://support.microsoft.com/kb/65472
//typedef __int64                           int64_t;
//#else
//typedef long long                         int64_t;
//#endif



#if SIZEOF_CHAR == 1
typedef unsigned char                       uint8_t;
typedef signed char                         int8_t;
#elif SIZEOF_INT == 1
typedef unsigned int                        uint8_t;
typedef signed int                          int8_t;
#else  /* XXX */
#error "there's no appropriate type for uint8_t"
#endif


#if SIZEOF_INT == 4
typedef signed int                          int32_t;
typedef unsigned int                        uint32_t;
#elif SIZEOF_LONG == 4
typedef unsigned long                       uint32_t;
typedef unsigned long                       uint32_t;
#elif SIZEOF_SHORT == 4
typedef unsigned short                      uint32_t;
typedef unsigned short                      uint32_t;
#else  /* XXX */
#error "there's no appropriate type for uint32_t"
#endif


#if SIZEOF_SHORT == 2
typedef unsigned short                      uint16_t;
typedef signed short                        int16_t;
#elif SIZEOF_INT == 2
typedef unsigned int                        uint16_t;
typedef signed int                          int16_t;
#elif SIZEOF_CHAR == 2
typedef unsigned char                       uint16_t;
typedef signed char                         int16_t;
#else  /* XXX */
#error "there's no appropriate type for uint16_t"
#endif

#if SIZEOF_LONG_LONG == 8
typedef unsigned long long                  uint64_t;
typedef long long                           int64_t;
#elif defined(_MSC_EXTENSIONS)
typedef unsigned _int64                     uint64_t;
typedef _int64                              int64_t;
#elif SIZEOF_INT == 8
typedef unsigned int                        uint64_t;
#elif SIZEOF_LONG == 8
typedef unsigned long                       uint64_t;
#elif SIZEOF_SHORT == 8
typedef unsigned short                      uint64_t;
#else  /* XXX */
#error "there's no appropriate type for     u_int64_t"
#endif


#endif  // __int8_t_defined
