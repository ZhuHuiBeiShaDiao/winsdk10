/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:

    UcxUsbDevice.h

Abstract:

    UCX UsbDevice object types and methods.

Environment:

    Kernel-mode only.

--*/

//
// NOTE: This header is generated by stubwork.  Please make any 
//       modifications to the corresponding template files 
//       (.x or .y) and use stubwork to regenerate the header
//

#ifndef _UCXUSBDEVICE_H_
#define _UCXUSBDEVICE_H_

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





typedef struct _USBDEVICE_MGMT_HEADER {
    ULONG                   Size;
    UCXUSBDEVICE            Hub;
    UCXUSBDEVICE            UsbDevice;
} USBDEVICE_MGMT_HEADER, *PUSBDEVICE_MGMT_HEADER;

typedef struct _ADDRESS0_OWNERSHIP_ACQUIRE {
#ifdef __cplusplus
    USBDEVICE_MGMT_HEADER            Header;
#else
    USBDEVICE_MGMT_HEADER;
#endif
} ADDRESS0_OWNERSHIP_ACQUIRE, *PADDRESS0_OWNERSHIP_ACQUIRE;

typedef struct _USBDEVICE_ENABLE_FAILURE_FLAGS {
    ULONG                   InsufficientHardwareResourcesForDefaultEndpoint:1;
    ULONG                   InsufficientHardwareResourcesForDevice:1;
    ULONG                   Reserved:30;
} USBDEVICE_ENABLE_FAILURE_FLAGS;

typedef struct _USBDEVICE_ENABLE {
#ifdef __cplusplus
    USBDEVICE_MGMT_HEADER            Header;
#else
    USBDEVICE_MGMT_HEADER;
#endif
    UCXENDPOINT                      DefaultEndpoint;
    USBDEVICE_ENABLE_FAILURE_FLAGS   FailureFlags;
} USBDEVICE_ENABLE, *PUSBDEVICE_ENABLE;

typedef struct _USBDEVICE_RESET {
#ifdef __cplusplus
    USBDEVICE_MGMT_HEADER            Header;
#else
    USBDEVICE_MGMT_HEADER;
#endif
    UCXENDPOINT             DefaultEndpoint;
    ULONG                   EndpointsToDisableCount;
    UCXENDPOINT *           EndpointsToDisable;
} USBDEVICE_RESET, *PUSBDEVICE_RESET;

typedef struct _USBDEVICE_PURGEIO {
#ifdef __cplusplus
    USBDEVICE_MGMT_HEADER            Header;
#else
    USBDEVICE_MGMT_HEADER;
#endif
    BOOLEAN                 OnSuspend;
} USBDEVICE_PURGEIO, *PUSBDEVICE_PURGEIO;

typedef struct _USBDEVICE_ABORTIO {
#ifdef __cplusplus
    USBDEVICE_MGMT_HEADER            Header;
#else
    USBDEVICE_MGMT_HEADER;
#endif
} USBDEVICE_ABORTIO, *PUSBDEVICE_ABORTIO;

typedef struct _USBDEVICE_STARTIO {
#ifdef __cplusplus
    USBDEVICE_MGMT_HEADER            Header;
#else
    USBDEVICE_MGMT_HEADER;
#endif
} USBDEVICE_STARTIO, *PUSBDEVICE_STARTIO;

typedef struct _USBDEVICE_TREE_PURGEIO {
#ifdef __cplusplus
    USBDEVICE_MGMT_HEADER            Header;
#else
    USBDEVICE_MGMT_HEADER;
#endif
} USBDEVICE_TREE_PURGEIO, *PUSBDEVICE_TREE_PURGEIO;

typedef struct _USBDEVICE_ADDRESS {
#ifdef __cplusplus
    USBDEVICE_MGMT_HEADER            Header;
#else
    USBDEVICE_MGMT_HEADER;
#endif
    ULONG                   Reserved;
    ULONG                   Address;
} USBDEVICE_ADDRESS, *PUSBDEVICE_ADDRESS;

typedef struct _USBDEVICE_UPDATE_FLAGS {
    ULONG                   UpdateDeviceDescriptor:1;
    ULONG                   UpdateBosDescriptor:1;
    ULONG                   UpdateMaxExitLatency:1;
    ULONG                   UpdateIsHub:1;
    ULONG                   UpdateAllowIoOnInvalidPipeHandles:1;
    ULONG                   Update20HardwareLpmParameters:1;
    ULONG                   UpdateRootPortResumeTime:1;
    ULONG                   Reserved:26;
} USBDEVICE_UPDATE_FLAGS;

typedef struct _USBDEVICE_UPDATE_FAILURE_FLAGS {
    ULONG                   MaxExitLatencyTooLarge:1;
    ULONG                   Reserved:31;
} USBDEVICE_UPDATE_FAILURE_FLAGS;

typedef struct _USBDEVICE_UPDATE_20_HARDWARE_LPM_PARAMETERS {
    ULONG                   HardwareLpmEnable:1;
    ULONG                   RemoteWakeEnable:1;
    ULONG                   HostInitiatedResumeDurationMode:1;
    ULONG                   BestEffortServiceLatency:4;
    ULONG                   BestEffortServiceLatencyDeep:4;
    ULONG                   L1Timeout:8;
    ULONG                   Reserved:13;
} USBDEVICE_UPDATE_20_HARDWARE_LPM_PARAMETERS;

typedef struct _USBDEVICE_UPDATE {
#ifdef __cplusplus
    USBDEVICE_MGMT_HEADER            Header;
#else
    USBDEVICE_MGMT_HEADER;
#endif
    USBDEVICE_UPDATE_FLAGS                      Flags;
    PUSB_DEVICE_DESCRIPTOR                      DeviceDescriptor;
    PUSB_BOS_DESCRIPTOR                         BosDescriptor;
    ULONG                                       MaxExitLatency;
    BOOLEAN                                     IsHub;
    USBDEVICE_UPDATE_FAILURE_FLAGS              FailureFlags;
    USBDEVICE_UPDATE_20_HARDWARE_LPM_PARAMETERS Usb20HardwareLpmParameters;
    USHORT                                      RootPortResumeTime;
} USBDEVICE_UPDATE, *PUSBDEVICE_UPDATE;

typedef struct _USBDEVICE_HUB_INFO {
#ifdef __cplusplus
    USBDEVICE_MGMT_HEADER            Header;
#else
    USBDEVICE_MGMT_HEADER;
#endif
    ULONG                   NumberOfPorts;
    ULONG                   NumberOfTTs;
    ULONG                   TTThinkTime;
} USBDEVICE_HUB_INFO, *PUSBDEVICE_HUB_INFO;

typedef struct _USBDEVICE_DISABLE {
#ifdef __cplusplus
    USBDEVICE_MGMT_HEADER            Header;
#else
    USBDEVICE_MGMT_HEADER;
#endif
    UCXENDPOINT             DefaultEndpoint;
} USBDEVICE_DISABLE, *PUSBDEVICE_DISABLE;

#define MAX_USB_DEVICE_DEPTH 6

typedef struct _USB_DEVICE_PORT_PATH {

    ULONG   Size;
    ULONG   PortPathDepth;
    ULONG   TTHubDepth;
    ULONG   PortPath[ MAX_USB_DEVICE_DEPTH ];

} USB_DEVICE_PORT_PATH, *PUSB_DEVICE_PORT_PATH;

typedef struct _UCXUSBDEVICE_INFO {
    ULONG                      Size;
    USB_DEVICE_SPEED           DeviceSpeed;
    UCXUSBDEVICE               TtHub;
    USB_DEVICE_PORT_PATH       PortPath;
} UCXUSBDEVICE_INFO, *PUCXUSBDEVICE_INFO;

typedef
_Function_class_(EVT_UCX_USBDEVICE_ENDPOINTS_CONFIGURE)
_IRQL_requires_same_
__drv_maxIRQL(DISPATCH_LEVEL)
VOID
EVT_UCX_USBDEVICE_ENDPOINTS_CONFIGURE(
    __in
    UCXCONTROLLER   UcxController,
    __in
    WDFREQUEST      Request
);

typedef EVT_UCX_USBDEVICE_ENDPOINTS_CONFIGURE *PFN_UCX_USBDEVICE_ENDPOINTS_CONFIGURE;

typedef
_Function_class_(EVT_UCX_USBDEVICE_ENABLE)
_IRQL_requires_same_
__drv_maxIRQL(DISPATCH_LEVEL)
VOID
EVT_UCX_USBDEVICE_ENABLE(
    __in
    UCXCONTROLLER   UcxController,
    __in
    WDFREQUEST      Request
);

typedef EVT_UCX_USBDEVICE_ENABLE *PFN_UCX_USBDEVICE_ENABLE;

typedef
_Function_class_(EVT_UCX_USBDEVICE_DISABLE)
_IRQL_requires_same_
__drv_maxIRQL(DISPATCH_LEVEL)
VOID
EVT_UCX_USBDEVICE_DISABLE(
    __in
    UCXCONTROLLER   UcxController,
    __in
    WDFREQUEST      Request
);

typedef EVT_UCX_USBDEVICE_DISABLE *PFN_UCX_USBDEVICE_DISABLE;

typedef
_Function_class_(EVT_UCX_USBDEVICE_RESET)
_IRQL_requires_same_
__drv_maxIRQL(DISPATCH_LEVEL)
VOID
EVT_UCX_USBDEVICE_RESET(
    __in
    UCXCONTROLLER   UcxController,
    __in
    WDFREQUEST      Request
);

typedef EVT_UCX_USBDEVICE_RESET *PFN_UCX_USBDEVICE_RESET;

typedef
_Function_class_(EVT_UCX_USBDEVICE_ADDRESS)
_IRQL_requires_same_
__drv_maxIRQL(DISPATCH_LEVEL)
VOID
EVT_UCX_USBDEVICE_ADDRESS(
    __in
    UCXCONTROLLER   UcxController,
    __in
    WDFREQUEST      Request
);

typedef EVT_UCX_USBDEVICE_ADDRESS *PFN_UCX_USBDEVICE_ADDRESS;

typedef
_Function_class_(EVT_UCX_USBDEVICE_UPDATE)
_IRQL_requires_same_
__drv_maxIRQL(DISPATCH_LEVEL)
VOID
EVT_UCX_USBDEVICE_UPDATE(
    __in
    UCXCONTROLLER   UcxController,
    __in
    WDFREQUEST      Request
);

typedef EVT_UCX_USBDEVICE_UPDATE *PFN_UCX_USBDEVICE_UPDATE;

typedef
_Function_class_(EVT_UCX_USBDEVICE_HUB_INFO)
_IRQL_requires_same_
__drv_maxIRQL(DISPATCH_LEVEL)
VOID
EVT_UCX_USBDEVICE_HUB_INFO(
    __in
    UCXCONTROLLER   UcxController,
    __in
    WDFREQUEST      Request
);

typedef EVT_UCX_USBDEVICE_HUB_INFO *PFN_UCX_USBDEVICE_HUB_INFO;

typedef
_Function_class_(EVT_UCX_USBDEVICE_DEFAULT_ENDPOINT_ADD)
_IRQL_requires_same_
__drv_requiresIRQL(PASSIVE_LEVEL)
NTSTATUS
EVT_UCX_USBDEVICE_DEFAULT_ENDPOINT_ADD(
    __in
    UCXCONTROLLER       UcxController,
    __in
    UCXUSBDEVICE        UcxUsbDevice,
    __in
    ULONG               MaxPacketSize,
    __in
    PUCXENDPOINT_INIT   UcxEndpointInit
);

typedef EVT_UCX_USBDEVICE_DEFAULT_ENDPOINT_ADD *PFN_UCX_USBDEVICE_DEFAULT_ENDPOINT_ADD;

typedef
_Function_class_(EVT_UCX_USBDEVICE_ENDPOINT_ADD)
_IRQL_requires_same_
__drv_requiresIRQL(PASSIVE_LEVEL)
NTSTATUS
EVT_UCX_USBDEVICE_ENDPOINT_ADD(
    __in
    UCXCONTROLLER   UcxController,
    __in
    UCXUSBDEVICE    UcxUsbDevice,
    __in_bcount(UsbEndpointDescriptorBufferLength)
    PUSB_ENDPOINT_DESCRIPTOR    UsbEndpointDescriptor,
    __in
    ULONG           UsbEndpointDescriptorBufferLength,
    __in_opt
    PUSB_SUPERSPEED_ENDPOINT_COMPANION_DESCRIPTOR SuperSpeedEndpointCompanionDescriptor,
    __in
    PUCXENDPOINT_INIT   UcxEndpointInit
);

typedef EVT_UCX_USBDEVICE_ENDPOINT_ADD *PFN_UCX_USBDEVICE_ENDPOINT_ADD;

typedef struct _UCX_USBDEVICE_EVENT_CALLBACKS {
    ULONG                                       Size;
    PFN_UCX_USBDEVICE_ENDPOINTS_CONFIGURE      EvtUsbDeviceEndpointsConfigure;
    PFN_UCX_USBDEVICE_ENABLE                   EvtUsbDeviceEnable;
    PFN_UCX_USBDEVICE_DISABLE                  EvtUsbDeviceDisable;
    PFN_UCX_USBDEVICE_RESET                    EvtUsbDeviceReset;
    PFN_UCX_USBDEVICE_ADDRESS                  EvtUsbDeviceAddress;
    PFN_UCX_USBDEVICE_UPDATE                   EvtUsbDeviceUpdate;
    PFN_UCX_USBDEVICE_HUB_INFO                 EvtUsbDeviceHubInfo;
    PFN_UCX_USBDEVICE_DEFAULT_ENDPOINT_ADD     EvtUsbDeviceDefaultEndpointAdd;
    PFN_UCX_USBDEVICE_ENDPOINT_ADD             EvtUsbDeviceEndpointAdd;
} UCX_USBDEVICE_EVENT_CALLBACKS, *PUCX_USBDEVICE_EVENT_CALLBACKS;

VOID
FORCEINLINE
UCX_USBDEVICE_EVENT_CALLBACKS_INIT(
    __out
        PUCX_USBDEVICE_EVENT_CALLBACKS          Callbacks,
    __in
        PFN_UCX_USBDEVICE_ENDPOINTS_CONFIGURE  EvtUsbDeviceEndpointsConfigure,
    __in
        PFN_UCX_USBDEVICE_ENABLE               EvtUsbDeviceEnable,
    __in
        PFN_UCX_USBDEVICE_DISABLE              EvtUsbDeviceDisable,
    __in
        PFN_UCX_USBDEVICE_RESET                EvtUsbDeviceReset,
    __in
        PFN_UCX_USBDEVICE_ADDRESS              EvtUsbDeviceAddress,
    __in
        PFN_UCX_USBDEVICE_UPDATE               EvtUsbDeviceUpdate,
    __in
        PFN_UCX_USBDEVICE_HUB_INFO             EvtUsbDeviceHubInfo,
    __in
        PFN_UCX_USBDEVICE_DEFAULT_ENDPOINT_ADD EvtUsbDeviceDefaultEndpointAdd,
    __in
        PFN_UCX_USBDEVICE_ENDPOINT_ADD         EvtUsbDeviceEndpointAdd
    )
{
    RtlZeroMemory(Callbacks, sizeof(UCX_USBDEVICE_EVENT_CALLBACKS));
    Callbacks->Size = sizeof(UCX_USBDEVICE_EVENT_CALLBACKS);
    Callbacks->EvtUsbDeviceEndpointsConfigure = EvtUsbDeviceEndpointsConfigure;
    Callbacks->EvtUsbDeviceEnable = EvtUsbDeviceEnable;
    Callbacks->EvtUsbDeviceDisable = EvtUsbDeviceDisable;
    Callbacks->EvtUsbDeviceReset = EvtUsbDeviceReset;
    Callbacks->EvtUsbDeviceAddress = EvtUsbDeviceAddress;
    Callbacks->EvtUsbDeviceUpdate = EvtUsbDeviceUpdate;
    Callbacks->EvtUsbDeviceHubInfo = EvtUsbDeviceHubInfo;
    Callbacks->EvtUsbDeviceDefaultEndpointAdd = EvtUsbDeviceDefaultEndpointAdd;
    Callbacks->EvtUsbDeviceEndpointAdd = EvtUsbDeviceEndpointAdd;
}

//
// In an earlier version of this header, the function pointers for the callbacks used to be prefixed
// with "PEVT" instead of the standard "PFN". Typedef those old names so that existing clients that
// may be using the old names continue to compile with the new header.
//

typedef PFN_UCX_USBDEVICE_ADDRESS PEVT_UCX_USBDEVICE_ADDRESS;
typedef PFN_UCX_USBDEVICE_DEFAULT_ENDPOINT_ADD PEVT_UCX_USBDEVICE_DEFAULT_ENDPOINT_ADD;
typedef PFN_UCX_USBDEVICE_DISABLE PEVT_UCX_USBDEVICE_DISABLE;
typedef PFN_UCX_USBDEVICE_ENABLE PEVT_UCX_USBDEVICE_ENABLE;
typedef PFN_UCX_USBDEVICE_ENDPOINT_ADD PEVT_UCX_USBDEVICE_ENDPOINT_ADD;
typedef PFN_UCX_USBDEVICE_ENDPOINTS_CONFIGURE PEVT_UCX_USBDEVICE_ENDPOINTS_CONFIGURE;
typedef PFN_UCX_USBDEVICE_HUB_INFO PEVT_UCX_USBDEVICE_HUB_INFO;
typedef PFN_UCX_USBDEVICE_RESET PEVT_UCX_USBDEVICE_RESET;
typedef PFN_UCX_USBDEVICE_UPDATE PEVT_UCX_USBDEVICE_UPDATE;

//
// UCX Function: UcxUsbDeviceCreate
//
typedef
_Must_inspect_result_
__drv_requiresIRQL(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(*PFN_UCXUSBDEVICECREATE)(
    _In_
    PUCX_DRIVER_GLOBALS DriverGlobals,
    __in
    UCXCONTROLLER Controller,
    __deref_inout
    PUCXUSBDEVICE_INIT* UsbDeviceInit,
    __in_opt
    PWDF_OBJECT_ATTRIBUTES Attributes,
    __out
    UCXUSBDEVICE* UsbDevice
    );

_Must_inspect_result_
__drv_requiresIRQL(PASSIVE_LEVEL)
NTSTATUS
FORCEINLINE
UcxUsbDeviceCreate(
    __in
    UCXCONTROLLER Controller,
    __deref_inout
    PUCXUSBDEVICE_INIT* UsbDeviceInit,
    __in_opt
    PWDF_OBJECT_ATTRIBUTES Attributes,
    __out
    UCXUSBDEVICE* UsbDevice
    )
{
    return ((PFN_UCXUSBDEVICECREATE) UcxFunctions[UcxUsbDeviceCreateTableIndex])(UcxDriverGlobals, Controller, UsbDeviceInit, Attributes, UsbDevice);
}

//
// UCX Function: UcxUsbDeviceInitSetEventCallbacks
//
typedef
WDFAPI
VOID
(*PFN_UCXUSBDEVICEINITSETEVENTCALLBACKS)(
    _In_
    PUCX_DRIVER_GLOBALS DriverGlobals,
    __inout
    PUCXUSBDEVICE_INIT UsbDeviceInit,
    __in
    PUCX_USBDEVICE_EVENT_CALLBACKS EventCallbacks
    );

VOID
FORCEINLINE
UcxUsbDeviceInitSetEventCallbacks(
    __inout
    PUCXUSBDEVICE_INIT UsbDeviceInit,
    __in
    PUCX_USBDEVICE_EVENT_CALLBACKS EventCallbacks
    )
{
    ((PFN_UCXUSBDEVICEINITSETEVENTCALLBACKS) UcxFunctions[UcxUsbDeviceInitSetEventCallbacksTableIndex])(UcxDriverGlobals, UsbDeviceInit, EventCallbacks);
}

//
// UCX Function: UcxUsbDeviceRemoteWakeNotification
//
typedef
__drv_maxIRQL(DISPATCH_LEVEL)
WDFAPI
VOID
(*PFN_UCXUSBDEVICEREMOTEWAKENOTIFICATION)(
    _In_
    PUCX_DRIVER_GLOBALS DriverGlobals,
    __in
    UCXUSBDEVICE UsbDevice,
    __in
    ULONG Interface
    );

__drv_maxIRQL(DISPATCH_LEVEL)
VOID
FORCEINLINE
UcxUsbDeviceRemoteWakeNotification(
    __in
    UCXUSBDEVICE UsbDevice,
    __in
    ULONG Interface
    )
{
    ((PFN_UCXUSBDEVICEREMOTEWAKENOTIFICATION) UcxFunctions[UcxUsbDeviceRemoteWakeNotificationTableIndex])(UcxDriverGlobals, UsbDevice, Interface);
}



WDF_EXTERN_C_END

#endif // _UCXUSBDEVICE_H_


