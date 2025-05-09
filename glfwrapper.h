/*

see https://learn.microsoft.com/es-es/windows/win32/opengl/glbegin for more info

*/


#ifndef HEADER_H

#define GLFW_INCLUDE_NONE
#include "include/GLFW/glfw3.h"
#include <GL/gl.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#ifndef PI
    #define PI 3.14159265358979323846f
#endif
#ifndef DEG2RAD
    #define DEG2RAD (PI/180.0f)
#endif
#ifndef RAD2DEG
    #define RAD2DEG (180.0f/PI)
#endif

typedef struct {
    char *vertex;
    char *fragment;
    unsigned int id;
} Shader;

typedef struct {
    float x;
    float y;
} Vector;

typedef struct {
    float x;
    float y;
} Vector2;

typedef struct {
    float x;
    float y;
    float z;
} Vector3;

typedef struct {
    int fps;
    float deltatime;
} DeltaTime;

typedef struct {
    float x;
    float y;
    float w;
    float h;
} Rect;

Shader LoadShader(const char *vertexPath, const char *fragPath) {
    // To do
}

/* 
static means its only for this file
long double has the highest precission
and its treated as a float

*/

static clock_t start;
static clock_t stop;
static double delta;

void takeTime() {
    start = clock();
}

void getTime() {
    stop = clock();
    delta = (double)(stop-start);
}

double getFrameTime() {
    return delta;
}



/*
Drawing Modes for Opengl

see https://learn.microsoft.com/es-es/windows/win32/opengl/glbegin for more info

*/

GLFWwindow* createWindow(){
    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
        exit(1);

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(640, 640, "Test file", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(1);
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    return window;
}

void setBackgroundColor(float r, float g, float b) {
    glClearColor(r,g,b,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void setBackgroundColorAlpha(float r, float g, float b, float a) {
    glClearColor(r,g,b,a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void drawTriangle(float x, float y, float w, float h){
    glBegin(GL_TRIANGLES);
    glVertex2f(x,y);
    glVertex2f(x-(w/2.0f), y-h);
    glVertex2f(x+(w/2.0f), y-h);              
    glEnd();
}

void drawTriangleLines(float x, float y, float w, float h){
    glBegin(GL_LINES);

    glVertex2f(x  ,y  );
    glVertex2f(x+(w/2.0f)  ,y-h);

    glVertex2f(x  ,y  );
    glVertex2f(x-(w/2.0f)  ,y-h);

    glVertex2f(x+(w/2.0f)  ,y-h);
    glVertex2f(x-(w/2.0f)  ,y-h);

    glEnd();
}


void drawRectangle(Rect r) {
    glBegin(GL_TRIANGLES);

    glVertex2f(r.x  ,r.y  );
    glVertex2f(r.x  ,r.y+r.h);
    glVertex2f(r.x+r.w,r.y+r.h);

    glVertex2f(r.x  ,r.y  );
    glVertex2f(r.x+r.w,r.y  );
    glVertex2f(r.x+r.w,r.y+r.h);

    glEnd();
}


void drawRectangleLines(float x, float y, float w, float h) {
    glBegin(GL_LINES);

    glVertex2f(x  ,y  );
    glVertex2f(x+w,y  );

    glVertex2f(x+w,y  );
    glVertex2f(x+w,y+h);

    glVertex2f(x+w,y+h);
    glVertex2f(x  ,y+h);

    glVertex2f(x  ,y+h);
    glVertex2f(x  ,y  );

    glEnd();
}

void drawPolygonLines(float centerx, float centery, float size, int sides) {
    glBegin(GL_LINES);

    for(int i = 0; i < sides; i++) {
        glVertex2f(
            centerx + size*cos(i*DEG2RAD*( 360/sides) ),
            centery - size*sin(i*DEG2RAD*( 360/sides) )
        );
        glVertex2f(
            centerx + size*cos((i+1)*DEG2RAD*( 360/sides) ),
            centery - size*sin((i+1)*DEG2RAD*( 360/sides) )
        );
    }
    glEnd();

}

void drawPolygon(float centerx, float centery, float size, int sides) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerx, centery);

    for(int i = 0; i < sides; i++) {
        glVertex2f(
            centerx + size*cos(i*DEG2RAD*( 360/sides) ),
            centery - size*sin(i*DEG2RAD*( 360/sides) )
        );
        glVertex2f(
            centerx + size*cos((i+1)*DEG2RAD*( 360/sides) ),
            centery - size*sin((i+1)*DEG2RAD*( 360/sides) )
        );
    }
    glEnd();

}



#endif
