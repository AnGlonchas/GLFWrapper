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
    createWindow(640, 640, "Test");
    // Loop until the user closes the window
    while (isWindowOpen()) {
        // Render here
        updateBackgroundColor(LIGHTAQUA);
        drawRectangle(-0.25f, 0.25f, 0.5f, 0.5f, DARKRED);
        updateWindow();
    }

    closeWindow();
    return 0;
}
