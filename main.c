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

    Vector2 mousepos = {0};
    int ismousedown = 0;

    Rect rect1 = {0.0f, 0.0f, 0.5f, 0.5f}; 

    // Loop until the user closes the window
    while (isWindowOpen()) {
        // Render here
        updateBackgroundColor(DARKRED);
        /*
        if(isKeyDown(KEY_D)) {
            rect1.x += 0.03f*getDeltaTime();
        }
        if(isKeyDown(KEY_W)) {
            rect1.y += 0.03f*getDeltaTime();
        }
        if(isKeyDown(KEY_A)) {
            rect1.x -= 0.03f*getDeltaTime();
        }
        if(isKeyDown(KEY_S)) {
            rect1.y -= 0.03f*getDeltaTime();
        }
        */

        mousepos = getMousePos();
        printf("%.2f\t%.2f\n", mousepos.x, mousepos.y);

        updateWindow();
    }

    closeWindow();
    return 0;
}
