// Copyright 2021 yuzu Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "core/hid/emulated_controller.h"
#include "core/hid/hid_core.h"
#include "core/hle/service/hid/hidbus/stubbed.h"

namespace Service::HID {
constexpr u8 DEVICE_ID = 0xFF;

HidbusStubbed::HidbusStubbed(Core::HID::HIDCore& hid_core_,
                             KernelHelpers::ServiceContext& service_context_)
    : HidbusBase(service_context_) {}
HidbusStubbed::~HidbusStubbed() = default;

void HidbusStubbed::OnInit() {
    return;
}

void HidbusStubbed::OnRelease() {
    return;
};

void HidbusStubbed::OnUpdate() {
    if (!is_activated) {
        return;
    }
    if (!device_enabled) {
        return;
    }
    if (!polling_mode_enabled || !is_transfer_memory_set) {
        return;
    }

    LOG_ERROR(Service_HID, "Polling mode not supported {}", polling_mode);
}

u8 HidbusStubbed::GetDeviceId() const {
    return DEVICE_ID;
}

std::vector<u8> HidbusStubbed::GetReply() const {
    return {};
}

bool HidbusStubbed::SetCommand(const std::vector<u8>& data) {
    LOG_ERROR(Service_HID, "Command not implemented");
    return false;
}

} // namespace Service::HID
