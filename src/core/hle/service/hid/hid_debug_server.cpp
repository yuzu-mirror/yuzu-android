// SPDX-FileCopyrightText: Copyright 2023 yuzu Emulator Project
// SPDX-License-Identifier: GPL-3.0-or-later

#include "core/hle/service/hid/hid_debug_server.h"
#include "core/hle/service/hid/resource_manager.h"
#include "core/hle/service/ipc_helpers.h"

namespace Service::HID {

IHidDebugServer::IHidDebugServer(Core::System& system_, std::shared_ptr<ResourceManager> resource)
    : ServiceFramework{system_, "hid:dbg"}, resource_manager{resource} {
    // clang-format off
    static const FunctionInfo functions[] = {
        {0, nullptr, "DeactivateDebugPad"},
        {1, nullptr, "SetDebugPadAutoPilotState"},
        {2, nullptr, "UnsetDebugPadAutoPilotState"},
        {10, nullptr, "DeactivateTouchScreen"},
        {11, nullptr, "SetTouchScreenAutoPilotState"},
        {12, nullptr, "UnsetTouchScreenAutoPilotState"},
        {13, nullptr, "GetTouchScreenConfiguration"},
        {14, nullptr, "ProcessTouchScreenAutoTune"},
        {15, nullptr, "ForceStopTouchScreenManagement"},
        {16, nullptr, "ForceRestartTouchScreenManagement"},
        {17, nullptr, "IsTouchScreenManaged"},
        {20, nullptr, "DeactivateMouse"},
        {21, nullptr, "SetMouseAutoPilotState"},
        {22, nullptr, "UnsetMouseAutoPilotState"},
        {25, nullptr, "SetDebugMouseAutoPilotState"},
        {26, nullptr, "UnsetDebugMouseAutoPilotState"},
        {30, nullptr, "DeactivateKeyboard"},
        {31, nullptr, "SetKeyboardAutoPilotState"},
        {32, nullptr, "UnsetKeyboardAutoPilotState"},
        {50, nullptr, "DeactivateXpad"},
        {51, nullptr, "SetXpadAutoPilotState"},
        {52, nullptr, "UnsetXpadAutoPilotState"},
        {53, nullptr, "DeactivateJoyXpad"},
        {60, nullptr, "ClearNpadSystemCommonPolicy"},
        {61, nullptr, "DeactivateNpad"},
        {62, nullptr, "ForceDisconnectNpad"},
        {91, nullptr, "DeactivateGesture"},
        {110, nullptr, "DeactivateHomeButton"},
        {111, nullptr, "SetHomeButtonAutoPilotState"},
        {112, nullptr, "UnsetHomeButtonAutoPilotState"},
        {120, nullptr, "DeactivateSleepButton"},
        {121, nullptr, "SetSleepButtonAutoPilotState"},
        {122, nullptr, "UnsetSleepButtonAutoPilotState"},
        {123, nullptr, "DeactivateInputDetector"},
        {130, nullptr, "DeactivateCaptureButton"},
        {131, nullptr, "SetCaptureButtonAutoPilotState"},
        {132, nullptr, "UnsetCaptureButtonAutoPilotState"},
        {133, nullptr, "SetShiftAccelerometerCalibrationValue"},
        {134, nullptr, "GetShiftAccelerometerCalibrationValue"},
        {135, nullptr, "SetShiftGyroscopeCalibrationValue"},
        {136, nullptr, "GetShiftGyroscopeCalibrationValue"},
        {140, nullptr, "DeactivateConsoleSixAxisSensor"},
        {141, nullptr, "GetConsoleSixAxisSensorSamplingFrequency"},
        {142, nullptr, "DeactivateSevenSixAxisSensor"},
        {143, nullptr, "GetConsoleSixAxisSensorCountStates"},
        {144, nullptr, "GetAccelerometerFsr"},
        {145, nullptr, "SetAccelerometerFsr"},
        {146, nullptr, "GetAccelerometerOdr"},
        {147, nullptr, "SetAccelerometerOdr"},
        {148, nullptr, "GetGyroscopeFsr"},
        {149, nullptr, "SetGyroscopeFsr"},
        {150, nullptr, "GetGyroscopeOdr"},
        {151, nullptr, "SetGyroscopeOdr"},
        {152, nullptr, "GetWhoAmI"},
        {201, nullptr, "ActivateFirmwareUpdate"},
        {202, nullptr, "DeactivateFirmwareUpdate"},
        {203, nullptr, "StartFirmwareUpdate"},
        {204, nullptr, "GetFirmwareUpdateStage"},
        {205, nullptr, "GetFirmwareVersion"},
        {206, nullptr, "GetDestinationFirmwareVersion"},
        {207, nullptr, "DiscardFirmwareInfoCacheForRevert"},
        {208, nullptr, "StartFirmwareUpdateForRevert"},
        {209, nullptr, "GetAvailableFirmwareVersionForRevert"},
        {210, nullptr, "IsFirmwareUpdatingDevice"},
        {211, nullptr, "StartFirmwareUpdateIndividual"},
        {215, nullptr, "SetUsbFirmwareForceUpdateEnabled"},
        {216, nullptr, "SetAllKuinaDevicesToFirmwareUpdateMode"},
        {221, nullptr, "UpdateControllerColor"},
        {222, nullptr, "ConnectUsbPadsAsync"},
        {223, nullptr, "DisconnectUsbPadsAsync"},
        {224, nullptr, "UpdateDesignInfo"},
        {225, nullptr, "GetUniquePadDriverState"},
        {226, nullptr, "GetSixAxisSensorDriverStates"},
        {227, nullptr, "GetRxPacketHistory"},
        {228, nullptr, "AcquireOperationEventHandle"},
        {229, nullptr, "ReadSerialFlash"},
        {230, nullptr, "WriteSerialFlash"},
        {231, nullptr, "GetOperationResult"},
        {232, nullptr, "EnableShipmentMode"},
        {233, nullptr, "ClearPairingInfo"},
        {234, nullptr, "GetUniquePadDeviceTypeSetInternal"},
        {235, nullptr, "EnableAnalogStickPower"},
        {236, nullptr, "RequestKuinaUartClockCal"},
        {237, nullptr, "GetKuinaUartClockCal"},
        {238, nullptr, "SetKuinaUartClockTrim"},
        {239, nullptr, "KuinaLoopbackTest"},
        {240, nullptr, "RequestBatteryVoltage"},
        {241, nullptr, "GetBatteryVoltage"},
        {242, nullptr, "GetUniquePadPowerInfo"},
        {243, nullptr, "RebootUniquePad"},
        {244, nullptr, "RequestKuinaFirmwareVersion"},
        {245, nullptr, "GetKuinaFirmwareVersion"},
        {246, nullptr, "GetVidPid"},
        {247, nullptr, "GetAnalogStickCalibrationValue"},
        {248, nullptr, "GetUniquePadIdsFull"},
        {249, nullptr, "ConnectUniquePad"},
        {250, nullptr, "IsVirtual"},
        {251, nullptr, "GetAnalogStickModuleParam"},
        {301, nullptr, "GetAbstractedPadHandles"},
        {302, nullptr, "GetAbstractedPadState"},
        {303, nullptr, "GetAbstractedPadsState"},
        {321, nullptr, "SetAutoPilotVirtualPadState"},
        {322, nullptr, "UnsetAutoPilotVirtualPadState"},
        {323, nullptr, "UnsetAllAutoPilotVirtualPadState"},
        {324, nullptr, "AttachHdlsWorkBuffer"},
        {325, nullptr, "ReleaseHdlsWorkBuffer"},
        {326, nullptr, "DumpHdlsNpadAssignmentState"},
        {327, nullptr, "DumpHdlsStates"},
        {328, nullptr, "ApplyHdlsNpadAssignmentState"},
        {329, nullptr, "ApplyHdlsStateList"},
        {330, nullptr, "AttachHdlsVirtualDevice"},
        {331, nullptr, "DetachHdlsVirtualDevice"},
        {332, nullptr, "SetHdlsState"},
        {350, nullptr, "AddRegisteredDevice"},
        {400, nullptr, "DisableExternalMcuOnNxDevice"},
        {401, nullptr, "DisableRailDeviceFiltering"},
        {402, nullptr, "EnableWiredPairing"},
        {403, nullptr, "EnableShipmentModeAutoClear"},
        {404, nullptr, "SetRailEnabled"},
        {500, nullptr, "SetFactoryInt"},
        {501, nullptr, "IsFactoryBootEnabled"},
        {550, nullptr, "SetAnalogStickModelDataTemporarily"},
        {551, nullptr, "GetAnalogStickModelData"},
        {552, nullptr, "ResetAnalogStickModelData"},
        {600, nullptr, "ConvertPadState"},
        {650, nullptr, "AddButtonPlayData"},
        {651, nullptr, "StartButtonPlayData"},
        {652, nullptr, "StopButtonPlayData"},
        {2000, nullptr, "DeactivateDigitizer"},
        {2001, nullptr, "SetDigitizerAutoPilotState"},
        {2002, nullptr, "UnsetDigitizerAutoPilotState"},
        {2002, nullptr, "ReloadFirmwareDebugSettings"},
    };
    // clang-format on

    RegisterHandlers(functions);
}

IHidDebugServer::~IHidDebugServer() = default;

std::shared_ptr<ResourceManager> IHidDebugServer::GetResourceManager() {
    resource_manager->Initialize();
    return resource_manager;
}

} // namespace Service::HID