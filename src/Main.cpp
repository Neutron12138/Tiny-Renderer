#ifndef TR_MAIN
#define TR_MAIN

#include <iostream>
#include "TR.hpp"

#define TR_SIGNAL_HANDLER(sig)                                                                  \
    void signal_handler_##sig(int)                                                              \
    {                                                                                           \
        std::cout << "Program aborted after receiving signal: \"" << #sig << "\"" << std::endl; \
    }

#define TR_REGISTER_SIGNAL(sig) \
    signal(sig, signal_handler_##sig)

TR_SIGNAL_HANDLER(SIGINT);
TR_SIGNAL_HANDLER(SIGILL);
TR_SIGNAL_HANDLER(SIGABRT_COMPAT);
TR_SIGNAL_HANDLER(SIGFPE);
TR_SIGNAL_HANDLER(SIGSEGV);
TR_SIGNAL_HANDLER(SIGTERM);
TR_SIGNAL_HANDLER(SIGBREAK);
TR_SIGNAL_HANDLER(SIGABRT);
TR_SIGNAL_HANDLER(SIGABRT2);

int main(int argc, char *argv[])
{
    TR_REGISTER_SIGNAL(SIGINT);
    TR_REGISTER_SIGNAL(SIGILL);
    TR_REGISTER_SIGNAL(SIGABRT_COMPAT);
    TR_REGISTER_SIGNAL(SIGFPE);
    TR_REGISTER_SIGNAL(SIGSEGV);
    TR_REGISTER_SIGNAL(SIGTERM);
    TR_REGISTER_SIGNAL(SIGBREAK);
    TR_REGISTER_SIGNAL(SIGABRT);
    TR_REGISTER_SIGNAL(SIGABRT2);

    TR_TRYS(
        tr::Application &app = get_application();
        return app.run(argc, argv););
}

#endif
