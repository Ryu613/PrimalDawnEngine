#pragma once

#include "app/App.hpp"

/**
* @brief vulkan最简样例，旨在确认项目是否能正常运行
*/
namespace pd {
    class Boxes : public App {

    public:
        Boxes(AppConfig& config);

        virtual ~Boxes() = default;

        virtual void prepare() = 0;
        virtual void setupScene() {};
        virtual void setupWindow() {};
        virtual void setupEngine() {};
        virtual void run() {};
        virtual void close() {};
    private:

        void initWindow();
        void initRenderSystem();
    };

}
