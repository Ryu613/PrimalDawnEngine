#include "HelloTriangle.hpp"

using namespace primaldawn;

int main() {
    ApplicationConfig config{
        .app_name = "Hello-Triangle",
        .engine_config {
            .platform {
                .window_system {
                    .title = "Hello-Triangle"
                }
            },
            .render_system {
                .render_system_type = RenderSystemType::OPENGL
            }
        }
    };
    HelloTriangle app(config);
    app.Prepare();
    app.Run();
    app.Close();
    return 0;
}
