#pragma once

#include "application/Application.hpp"

/**
* @brief vulkan最简样例，旨在确认项目是否能正常运行
*/
namespace pd {
    class Boxes : public pd::Application {

    public:
        Boxes();

        virtual ~Boxes() = default;

        virtual bool prepare(const pd::AppConfig& options) override;

        virtual void runOneFrame(float ms) override {
            // empty
        }

        virtual void finish() override;

        void run();

    private:

        void initWindow();
        void initRenderSystem();
    };

}
