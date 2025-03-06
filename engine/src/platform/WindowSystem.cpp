#include "platform/WindowSystem.h"

using namespace pd;

WindowSystem::WindowSystem(const WindowSystemOptions& windowSystemOptions) : mWindowSystemOptions{ windowSystemOptions } {}

void WindowSystem::doEvents() {

}

WindowSystem::Extent WindowSystem::getExtent() const {
    return mWindowSystemOptions.extent;
}
