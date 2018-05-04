/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:

    UcmGlobals.h

Abstract:

    UCM global definitions.

Environment:

    Kernel-mode.

--*/

//
// NOTE: This header is generated by stubwork.  Please make any 
//       modifications to the corresponding template files 
//       (.x or .y) and use stubwork to regenerate the header
//

#ifndef _UCMGLOBALS_H_
#define _UCMGLOBALS_H_

#ifndef WDF_EXTERN_C
  #ifdef __cplusplus
    #define WDF_EXTERN_C       extern "C"
    #define WDF_EXTERN_C_START extern "C" {
    #define WDF_EXTERN_C_END   }
  #else
    #define WDF_EXTERN_C
    #define WDF_EXTERN_C_START
    #define WDF_EXTERN_C_END
  #endif
#endif

WDF_EXTERN_C_START




typedef struct _UCM_DRIVER_GLOBALS {
    ULONG Reserved;
} UCM_DRIVER_GLOBALS, *PUCM_DRIVER_GLOBALS;





WDF_EXTERN_C_END

#endif // _UCMGLOBALS_H_

