/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 1990-1999  Microsoft Corporation

Module Name:

    ntddksec.h

Abstract:

    This file defines the IOCTLs and names for the KSecDD driver (the kernel
    mode security API driver).

Author:

    Richard Ward (richardw)

Revision History:

--*/

#ifndef _NTDDKSEC_
#define _NTDDKSEC_

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define DD_KSEC_DEVICE_NAME     "\\Device\\KSecDD"
#define DD_KSEC_DEVICE_NAME_U   L"\\Device\\KsecDD"

#define DD_CNG_DEVICE_NAME_U    L"\\Device\\CNG"

//
// Public KSecDD IOCTL's:
//
// Note: Do not define IOCTL's here with function codes exceeding 0xFF. Function
//       codes 0x0100 to 0xFFFF are reserved for Windows internal use only.
//

#define IOCTL_KSEC_CONNECT_LSA                      CTL_CODE(FILE_DEVICE_KSEC,  0, METHOD_BUFFERED,     FILE_WRITE_ACCESS )
#define IOCTL_KSEC_RNG                              CTL_CODE(FILE_DEVICE_KSEC,  1, METHOD_BUFFERED,     FILE_ANY_ACCESS )
#define IOCTL_KSEC_RNG_REKEY                        CTL_CODE(FILE_DEVICE_KSEC,  2, METHOD_BUFFERED,     FILE_ANY_ACCESS )
#define IOCTL_KSEC_ENCRYPT_MEMORY                   CTL_CODE(FILE_DEVICE_KSEC,  3, METHOD_OUT_DIRECT,   FILE_ANY_ACCESS )
#define IOCTL_KSEC_DECRYPT_MEMORY                   CTL_CODE(FILE_DEVICE_KSEC,  4, METHOD_OUT_DIRECT,   FILE_ANY_ACCESS )
#define IOCTL_KSEC_ENCRYPT_MEMORY_CROSS_PROC        CTL_CODE(FILE_DEVICE_KSEC,  5, METHOD_OUT_DIRECT,   FILE_ANY_ACCESS )
#define IOCTL_KSEC_DECRYPT_MEMORY_CROSS_PROC        CTL_CODE(FILE_DEVICE_KSEC,  6, METHOD_OUT_DIRECT,   FILE_ANY_ACCESS )
#define IOCTL_KSEC_ENCRYPT_MEMORY_SAME_LOGON        CTL_CODE(FILE_DEVICE_KSEC,  7, METHOD_OUT_DIRECT,   FILE_ANY_ACCESS )
#define IOCTL_KSEC_DECRYPT_MEMORY_SAME_LOGON        CTL_CODE(FILE_DEVICE_KSEC,  8, METHOD_OUT_DIRECT,   FILE_ANY_ACCESS )
#define IOCTL_KSEC_FIPS_GET_FUNCTION_TABLE          CTL_CODE(FILE_DEVICE_KSEC,  9, METHOD_BUFFERED,     FILE_ANY_ACCESS )
#define IOCTL_KSEC_ALLOC_POOL                       CTL_CODE(FILE_DEVICE_KSEC, 10, METHOD_BUFFERED,     FILE_ANY_ACCESS )
#define IOCTL_KSEC_FREE_POOL                        CTL_CODE(FILE_DEVICE_KSEC, 11, METHOD_BUFFERED,     FILE_ANY_ACCESS )
#define IOCTL_KSEC_COPY_POOL                        CTL_CODE(FILE_DEVICE_KSEC, 12, METHOD_BUFFERED,     FILE_ANY_ACCESS )
#define IOCTL_KSEC_DUPLICATE_HANDLE                 CTL_CODE(FILE_DEVICE_KSEC, 13, METHOD_BUFFERED,     FILE_ANY_ACCESS )
#define IOCTL_KSEC_REGISTER_EXTENSION               CTL_CODE(FILE_DEVICE_KSEC, 14, METHOD_BUFFERED,     FILE_ANY_ACCESS )   
#define IOCTL_KSEC_CLIENT_CALLBACK                  CTL_CODE(FILE_DEVICE_KSEC, 15, METHOD_BUFFERED,     FILE_ANY_ACCESS )
#define IOCTL_KSEC_GET_BCRYPT_EXTENSION	            CTL_CODE(FILE_DEVICE_KSEC, 16, METHOD_BUFFERED,     FILE_ANY_ACCESS )
#define IOCTL_KSEC_GET_SSL_EXTENSION                CTL_CODE(FILE_DEVICE_KSEC, 17, METHOD_BUFFERED,     FILE_ANY_ACCESS )
#define IOCTL_KSEC_GET_DEVICECONTROL_EXTENSION	    CTL_CODE(FILE_DEVICE_KSEC, 18, METHOD_BUFFERED,     FILE_ANY_ACCESS )
#define IOCTL_KSEC_ALLOC_VM                         CTL_CODE(FILE_DEVICE_KSEC, 19, METHOD_BUFFERED,     FILE_ANY_ACCESS )
#define IOCTL_KSEC_FREE_VM                          CTL_CODE(FILE_DEVICE_KSEC, 20, METHOD_BUFFERED,     FILE_ANY_ACCESS )
#define IOCTL_KSEC_COPY_VM                          CTL_CODE(FILE_DEVICE_KSEC, 21, METHOD_BUFFERED,     FILE_ANY_ACCESS )
#define IOCTL_KSEC_CLIENT_FREE_VM                   CTL_CODE(FILE_DEVICE_KSEC, 22, METHOD_BUFFERED,     FILE_ANY_ACCESS )
#define IOCTL_KSEC_INSERT_PROTECTED_PROCESS_ADDRESS CTL_CODE(FILE_DEVICE_KSEC, 23, METHOD_BUFFERED,     FILE_ANY_ACCESS )
#define IOCTL_KSEC_REMOVE_PROTECTED_PROCESS_ADDRESS CTL_CODE(FILE_DEVICE_KSEC, 24, METHOD_BUFFERED,     FILE_ANY_ACCESS )
#define IOCTL_KSEC_GET_BCRYPT_EXTENSION2            CTL_CODE(FILE_DEVICE_KSEC, 25, METHOD_BUFFERED,     FILE_ANY_ACCESS )
#define IOCTL_KSEC_IPC_GET_QUEUED_FUNCTION_CALLS    CTL_CODE(FILE_DEVICE_KSEC, 26, METHOD_OUT_DIRECT,   FILE_ANY_ACCESS)
#define IOCTL_KSEC_IPC_SET_FUNCTION_RETURN          CTL_CODE(FILE_DEVICE_KSEC, 27, METHOD_NEITHER,      FILE_ANY_ACCESS)

#ifdef __cplusplus
}
#endif

#endif
