#include "engine/context.hpp"

namespace engine {

    std::unique_ptr<Context> Context::instance_ = nullptr;

    void Context::Init() {
        instance_.reset(new Context);

    }
    void Context::Quit() {
        instance_.reset();
    }
    Context& Context::GetInstance() {
        return *instance_;
    }

    Context::Context() {
        // 配置vk实例的参数和创建实例
        vk::InstanceCreateInfo createInfo;
        // 要开启的layers
        std::vector<const char*> layers = { "VK_LAYER_KHRONOS_validation" };

        vk::ApplicationInfo appInfo;
        // 指定vk版本号
        appInfo.setApiVersion(VK_API_VERSION_1_3);
        createInfo.setPApplicationInfo(&appInfo)
            .setPEnabledLayerNames(layers);

        instance = vk::createInstance(createInfo);
    }

    Context::~Context() {
        instance.destroy();
    }
}