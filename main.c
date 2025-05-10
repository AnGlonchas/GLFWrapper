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

int main()
{
    GLFWwindow* window = createWindow();

    Rect rectangle1  = {0,0,0.5,0.5};

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        // Render here
        setBackgroundColor(0.0f,0.2f,0.5f);

        drawRectangle(0.0f, 0.0f, 0.5f, 0.5f);
        drawPolygonLines(0.0f, 0.0f, 0.1f, 2);
        drawRectangleLines(0.0f, 0.0f, 0.5, 0.5f);

        drawPolygonLines(0.0f, 0.0f, 0.1f, 10);
        drawRectangleRect(rectangle1);
        //drawRectangleLines(0.0f, 0.0f, 0.5, 0.5f);
        //drawLine(-0.5f, -0.5f, 0.5f, 0.5f);
        drawTriangleLines(0.0f, 0.0f, 0.1f, 0.1f);
        //drawTriangle(0.0f, 0.0f, 0.1f, 0.1f);


        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
