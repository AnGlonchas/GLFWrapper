/*

This file is only for testing
the glfwrapper.h is the product
feel free to edit this file

Notes:

The screen is like a cartesian plane
the left side is x = -1
the right side is x = 1
same for y

see https://learn.microsoft.com/es-es/windows/win32/opengl/glbegin for more info

*/

#include "glfwrapper.h"

int main() {
    Window* window = createWindow(640, 640, "TestFile");

    Rect rect1  = {0,0,0.5,0.5};
    Color red = {1.0f, 0.0f, 0.0f, 1.0f};

    // Loop until the user closes the window
    while (isWindowOpen(window)) {
        // Render here
        updateBackgroundColor(BLACK);
        if(isKeyDown(KEY_D, window)) {
            rect1.x += 0.03f*getDeltaTime();
        }
        if(isKeyDown(KEY_W, window)) {
            rect1.y += 0.03f*getDeltaTime();
        }
        if(isKeyDown(KEY_A, window)) {
            rect1.x -= 0.03f*getDeltaTime();
        }
        if(isKeyDown(KEY_S, window)) {
            rect1.y -= 0.03f*getDeltaTime();
        }

        drawRectangleRect(rect1, BLUE);

        updateWindow(window);
    }

    closeWindow();
    return 0;
}
