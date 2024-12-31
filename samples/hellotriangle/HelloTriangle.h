#ifndef DAWN_PRIMALDAWN_SAMPLES_HELLOTRIANGLE_H
#define DAWN_PRIMALDAWN_SAMPLES_HELLOTRIANGLE_H

#include "pdapp/Application.h"

/**
* @brief vulkan最简样例，旨在确认项目是否能正常运行
*/
class HelloTriangle : public pd::Application {
public:
    HelloTriangle();

    virtual ~HelloTriangle();

    virtual bool prepare(const pd::AppConfig& options) override;

    virtual void runOneFrame(float ms) override;

    virtual void finish() override;
private:

    void initVkInstance();

    void initVkDevice();

    void initVkSwapchain();

    void initVkRenderPass();

    void initVkPipeline();

    void initVkFrameBuffers();

    Context context;
};

#endif
