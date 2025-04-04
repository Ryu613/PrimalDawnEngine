#pragma once

#include <string>
#include <memory>
#include "platform/PlatformEnums.hpp"

namespace pd {
    class Engine;
    class WindowSystem;
    class SwapChain;

    struct RenderSystemConfig {
        std::string appName{"default"};
        std::string engineName{ "Primal Dawn" };
        OS os = OS::UNKNOWN;
        Backend backend = Backend::UNKWONN;
        bool enableDebug = false;
    };

    struct PipelineDesc {

    };
    /**
    * @brief 渲染系统接口，对图形API做封装
    */
    class RenderSystem {
    public:
        /**
        * @brief 
        */
        virtual std::unique_ptr<SwapChain> createSwapChain(Engine& engine, WindowSystem* windowSystem) = 0;
        /**
        * @ brief 绑定管线
        */
        virtual void bindPipeline(const PipelineDesc& pipelineDesc) = 0;

        /**
        * @brief 绘制图像
        */
        virtual void draw(PipelineDesc state) = 0;

        /**
        * 渲染通道开始
        */
        virtual void beginRenderPass() = 0;
        /**
        * 渲染通道结束
        */
        virtual void endRenderPass() = 0;

    protected:
        RenderSystem(RenderSystemConfig& cfg);
        RenderSystemConfig& mRenderSystemConfig;
    private:
    };
}
