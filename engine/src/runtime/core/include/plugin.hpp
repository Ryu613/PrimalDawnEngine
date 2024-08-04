#pragma once
namespace PrimalDawn {
    class Plugin {
    public:
        Plugin() {};
        virtual ~Plugin() {};
        virtual void install() = 0;
        virtual void init() = 0;
        virtual void shutdown() = 0;
        virtual void uninstall() = 0;
    };
}
