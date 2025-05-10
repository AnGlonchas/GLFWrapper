#include "glfwrapper.h"

int main() {
    Window* window = createWindow(640, 640, "Easy Example");

    // Loop until the user closes the window
    while (isWindowOpen(window)) {
        updateBackgroundColor(BLACK);

        drawRectangle(0.0f, 0.0f, 1.0f, 1.0f, RED);

        updateWindow(window);
    }

    closeWindow();
    return 0;
}
