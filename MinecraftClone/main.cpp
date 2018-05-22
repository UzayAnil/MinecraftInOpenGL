#include "src/Display.h"
#include "src/App.h"

int main() {
    Display::init();

    App app;
    app.runMainLoop();

    return 0;
}
