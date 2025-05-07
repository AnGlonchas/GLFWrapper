#ifndef HEADER_H

#define GLFW_INCLUDE_NONE
#include "include/GLFW/glfw3.h"
#include <stdio.h>
#include <stdlib.h>

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

Shader LoadShader(const char *vertexPath, const char *fragPath) {
    // To make
}



#endif