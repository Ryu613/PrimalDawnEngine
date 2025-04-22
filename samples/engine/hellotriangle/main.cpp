#include "HelloTriangle.hpp"

using namespace primaldawn;

int main() {
    ApplicationConfig config{
        .app_name = "Hello-Triangle",
        .engine_config {
            .platform {
                .window_system_type = WindowSystemType::SDL2,
                .window_system {
                    .title = "Hello-Triangle",
                    .extent {
                        .width = 1024,
                        .height = 768
                    }
                }
            },
            .render_system {
                .render_system_type = RenderSystemType::VULKAN,
                .enable_debug = true,
            }
        }
    };
    HelloTriangle app(config);
    app.Prepare();
    app.Run();
    app.Close();
    return 0;
}
