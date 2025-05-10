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

#include <stdio.h>
#include "glfwrapper.h"

int main() {
    Window* window = createWindow(640, 640, "TestFile");
    SetVsync(1);

    Rect rectangle1  = {0,0,0.5,0.5};
    Color red = {1.0f, 0.0f, 0.0f, 1.0f};

    // Loop until the user closes the window
    while (isWindowOpen(window)) {
        // Render here
        updateBackgroundColor(BLACK);
        if(isKeyDown(KEY_D, window)) {
            rectangle1.x += 0.05f*getDeltaTime();
        }
        if(isKeyDown(KEY_W, window)) {
            rectangle1.y += 0.05f*getDeltaTime();
        }
        if(isKeyDown(KEY_A, window)) {
            rectangle1.x -= 0.05f*getDeltaTime();
        }
        if(isKeyDown(KEY_S, window)) {
            rectangle1.y -= 0.05f*getDeltaTime();
        }

        drawRectangleRect(rectangle1, LIGHTRED);

        updateWindow(window);
    }

    closeWindow();
    return 0;
}
