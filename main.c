/*

This file is only for testing
the glfwrapper.h is the product
feel free to edit this file

Notes:

The screen is like a cartesian plane
the left side is x = -1
the right side is x = 1
same for y

*/

#define GLFW_INCLUDE_NONE
#include "include/GLFW/glfw3.h"
#include "glfwrapper.h"

#include <stdio.h>
#include <GL/gl.h>

int main()
{
    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
        return -1;

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(640, 640, "Test file", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        // Render here
        setBackgroundColor(0.0f,0.2f,0.5f);


        drawPolygonLines(0.0f, 0.0f, 0.1f, 8);
        //drawRectangle(0.0f, 0.0f, 0.5, 0.5f);
        drawRectangleLines(0.0f, 0.0f, 0.5, 0.5f);
        //drawLine(-0.5f, -0.5f, 0.5f, 0.5f);


        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}