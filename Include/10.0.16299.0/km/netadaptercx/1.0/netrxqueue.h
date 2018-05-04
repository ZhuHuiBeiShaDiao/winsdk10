/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    NetRxQueue.h

Abstract:

    This is the interfaces for the NetRxQueue

Environment:

    kernel mode only

Revision History:

--*/

//
// NOTE: This header is generated by stubwork.  Please make any 
//       modifications to the corresponding template files 
//       (.x or .y) and use stubwork to regenerate the header
//

#ifndef _NETRXQUEUE_H_
#define _NETRXQUEUE_H_

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




#define NET_RX_QUEUE_DEFAULT_ALIGNMENT ((ULONG)(-1))

typedef struct NETRXQUEUE_INIT *PNETRXQUEUE_INIT;

typedef
_Function_class_(EVT_RXQUEUE_CANCEL)
_IRQL_requires_same_
_IRQL_requires_(PASSIVE_LEVEL)
VOID
EVT_RXQUEUE_CANCEL(
    _In_
    NETRXQUEUE RxQueue
    );

typedef EVT_RXQUEUE_CANCEL *PFN_RXQUEUE_CANCEL;

typedef
_Function_class_(EVT_RXQUEUE_SET_NOTIFICATION_ENABLED)
_IRQL_requires_same_
_IRQL_requires_(PASSIVE_LEVEL)
NTSTATUS
EVT_RXQUEUE_SET_NOTIFICATION_ENABLED(
    _In_
    NETRXQUEUE RxQueue,
    _In_
    BOOLEAN NotificationEnabled
    );

typedef EVT_RXQUEUE_SET_NOTIFICATION_ENABLED *PFN_RXQUEUE_SET_NOTIFICATION_ENABLED;

typedef
_Function_class_(EVT_RXQUEUE_ADVANCE)
_IRQL_requires_same_
_IRQL_requires_max_(DISPATCH_LEVEL)
VOID
EVT_RXQUEUE_ADVANCE(
    _In_ 
    NETRXQUEUE RxQueue
    );

typedef EVT_RXQUEUE_ADVANCE *PFN_RXQUEUE_ADVANCE;

typedef struct _NET_RXQUEUE_CONFIG
{
    //
    // Size of structure. 
    //
    ULONG Size;

    PFN_RXQUEUE_CANCEL EvtRxQueueCancel;

    PFN_RXQUEUE_SET_NOTIFICATION_ENABLED EvtRxQueueSetNotificationEnabled;

    PFN_RXQUEUE_ADVANCE EvtRxQueueAdvance;

    PCNET_CONTEXT_TYPE_INFO ContextTypeInfo;

    ULONG AllocationSize;
    ULONG AlignmentRequirement;

} NET_RXQUEUE_CONFIG, *PNET_RXQUEUE_CONFIG;

VOID
FORCEINLINE
NET_RXQUEUE_CONFIG_INIT(
    _Out_ PNET_RXQUEUE_CONFIG NetRxQueueConfig,
    _In_  PFN_RXQUEUE_ADVANCE EvtRxQueueAdvance,
    _In_  PFN_RXQUEUE_SET_NOTIFICATION_ENABLED EvtRxQueueSetNotificationEnabled,
    _In_  PFN_RXQUEUE_CANCEL EvtRxQueueCancel
)
{
    RtlZeroMemory(NetRxQueueConfig, sizeof(NET_RXQUEUE_CONFIG));
    NetRxQueueConfig->Size = sizeof(NET_RXQUEUE_CONFIG);
    NetRxQueueConfig->AlignmentRequirement = NET_RX_QUEUE_DEFAULT_ALIGNMENT;
    NetRxQueueConfig->EvtRxQueueAdvance = EvtRxQueueAdvance;
    NetRxQueueConfig->EvtRxQueueSetNotificationEnabled = EvtRxQueueSetNotificationEnabled;
    NetRxQueueConfig->EvtRxQueueCancel = EvtRxQueueCancel;
}

#define NET_RXQUEUE_CONFIG_SET_DEFAULT_PACKET_CONTEXT_TYPE(_queueconfig, _contexttype)          \
    (_queueconfig)->ContextTypeInfo = WDF_GET_CONTEXT_TYPE_INFO(_contexttype);                  \

//
// NET Function: NetRxQueueCreate
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(*PFN_NETRXQUEUECREATE)(
    _In_
    PNET_DRIVER_GLOBALS DriverGlobals,
    _Inout_
    PNETRXQUEUE_INIT NetRxQueueInit,
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES RxQueueAttributes,
    _In_
    PNET_RXQUEUE_CONFIG Configuration,
    _Out_
    NETRXQUEUE* RxQueue
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
FORCEINLINE
NetRxQueueCreate(
    _Inout_
    PNETRXQUEUE_INIT NetRxQueueInit,
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES RxQueueAttributes,
    _In_
    PNET_RXQUEUE_CONFIG Configuration,
    _Out_
    NETRXQUEUE* RxQueue
    )
{
    return ((PFN_NETRXQUEUECREATE) NetFunctions[NetRxQueueCreateTableIndex])(NetDriverGlobals, NetRxQueueInit, RxQueueAttributes, Configuration, RxQueue);
}

//
// NET Function: NetRxQueueNotifyMoreReceivedPacketsAvailable
//
typedef
_IRQL_requires_max_(HIGH_LEVEL)
WDFAPI
VOID
(*PFN_NETRXQUEUENOTIFYMORERECEIVEDPACKETSAVAILABLE)(
    _In_
    PNET_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETRXQUEUE RxQueue
    );

_IRQL_requires_max_(HIGH_LEVEL)
VOID
FORCEINLINE
NetRxQueueNotifyMoreReceivedPacketsAvailable(
    _In_
    NETRXQUEUE RxQueue
    )
{
    ((PFN_NETRXQUEUENOTIFYMORERECEIVEDPACKETSAVAILABLE) NetFunctions[NetRxQueueNotifyMoreReceivedPacketsAvailableTableIndex])(NetDriverGlobals, RxQueue);
}

//
// NET Function: NetRxQueueInitGetQueueId
//
typedef
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
ULONG
(*PFN_NETRXQUEUEINITGETQUEUEID)(
    _In_
    PNET_DRIVER_GLOBALS DriverGlobals,
    _In_
    PNETRXQUEUE_INIT NetRxQueueInit
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
ULONG
FORCEINLINE
NetRxQueueInitGetQueueId(
    _In_
    PNETRXQUEUE_INIT NetRxQueueInit
    )
{
    return ((PFN_NETRXQUEUEINITGETQUEUEID) NetFunctions[NetRxQueueInitGetQueueIdTableIndex])(NetDriverGlobals, NetRxQueueInit);
}

//
// NET Function: NetRxQueueConfigureDmaAllocator
//
typedef
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(*PFN_NETRXQUEUECONFIGUREDMAALLOCATOR)(
    _In_
    PNET_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETRXQUEUE RxQueue,
    _In_
    WDFDMAENABLER Enabler
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
FORCEINLINE
NetRxQueueConfigureDmaAllocator(
    _In_
    NETRXQUEUE RxQueue,
    _In_
    WDFDMAENABLER Enabler
    )
{
    return ((PFN_NETRXQUEUECONFIGUREDMAALLOCATOR) NetFunctions[NetRxQueueConfigureDmaAllocatorTableIndex])(NetDriverGlobals, RxQueue, Enabler);
}

//
// NET Function: NetRxQueueGetRingBuffer
//
typedef
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
PNET_RING_BUFFER
(*PFN_NETRXQUEUEGETRINGBUFFER)(
    _In_
    PNET_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETRXQUEUE NetRxQueue
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
PNET_RING_BUFFER
FORCEINLINE
NetRxQueueGetRingBuffer(
    _In_
    NETRXQUEUE NetRxQueue
    )
{
    return ((PFN_NETRXQUEUEGETRINGBUFFER) NetFunctions[NetRxQueueGetRingBufferTableIndex])(NetDriverGlobals, NetRxQueue);
}



WDF_EXTERN_C_END

#endif // _NETRXQUEUE_H_

