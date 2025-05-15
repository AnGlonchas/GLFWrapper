/*



see https://learn.microsoft.com/es-es/windows/win32/opengl/glbegin for more info


TO-DO:

Collision Checkers:
    Between rects
    Between circles
    between rects and circles
*/


#ifndef GLFWRAPPER_H 

#define GLFW_INCLUDE_NONE

#include "include/GLFW/glfw3.h"

#include <GL/gl.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef PI
    #define PI 3.14159265358979323846f
#endif
#ifndef DEG2RAD
    #define DEG2RAD (PI/180.0f)
#endif
#ifndef RAD2DEG
    #define RAD2DEG (180.0f/PI)
#endif
#ifndef MAX_CIRCLE_SIDES
    #define MAX_CIRCLE_SIDES 30
#endif

typedef enum {
    KEY_NULL            = 0,        // Key: NULL, used for no key pressed
    // Alphanumeric keys
    KEY_APOSTROPHE      = 39,       // Key: '
    KEY_COMMA           = 44,       // Key: ,
    KEY_MINUS           = 45,       // Key: -
    KEY_PERIOD          = 46,       // Key: .
    KEY_SLASH           = 47,       // Key: /
    KEY_ZERO            = 48,       // Key: 0
    KEY_ONE             = 49,       // Key: 1
    KEY_TWO             = 50,       // Key: 2
    KEY_THREE           = 51,       // Key: 3
    KEY_FOUR            = 52,       // Key: 4
    KEY_FIVE            = 53,       // Key: 5
    KEY_SIX             = 54,       // Key: 6
    KEY_SEVEN           = 55,       // Key: 7
    KEY_EIGHT           = 56,       // Key: 8
    KEY_NINE            = 57,       // Key: 9
    KEY_SEMICOLON       = 59,       // Key: ;
    KEY_EQUAL           = 61,       // Key: =
    KEY_A               = 65,       // Key: A | a
    KEY_B               = 66,       // Key: B | b
    KEY_C               = 67,       // Key: C | c
    KEY_D               = 68,       // Key: D | d
    KEY_E               = 69,       // Key: E | e
    KEY_F               = 70,       // Key: F | f
    KEY_G               = 71,       // Key: G | g
    KEY_H               = 72,       // Key: H | h
    KEY_I               = 73,       // Key: I | i
    KEY_J               = 74,       // Key: J | j
    KEY_K               = 75,       // Key: K | k
    KEY_L               = 76,       // Key: L | l
    KEY_M               = 77,       // Key: M | m
    KEY_N               = 78,       // Key: N | n
    KEY_O               = 79,       // Key: O | o
    KEY_P               = 80,       // Key: P | p
    KEY_Q               = 81,       // Key: Q | q
    KEY_R               = 82,       // Key: R | r
    KEY_S               = 83,       // Key: S | s
    KEY_T               = 84,       // Key: T | t
    KEY_U               = 85,       // Key: U | u
    KEY_V               = 86,       // Key: V | v
    KEY_W               = 87,       // Key: W | w
    KEY_X               = 88,       // Key: X | x
    KEY_Y               = 89,       // Key: Y | y
    KEY_Z               = 90,       // Key: Z | z
    KEY_LEFT_BRACKET    = 91,       // Key: [
    KEY_BACKSLASH       = 92,       // Key: '\'
    KEY_RIGHT_BRACKET   = 93,       // Key: ]
    KEY_GRAVE           = 96,       // Key: `
    // Function keys
    KEY_SPACE           = 32,       // Key: Space
    KEY_ESCAPE          = 256,      // Key: Esc
    KEY_ENTER           = 257,      // Key: Enter
    KEY_TAB             = 258,      // Key: Tab
    KEY_BACKSPACE       = 259,      // Key: Backspace
    KEY_INSERT          = 260,      // Key: Ins
    KEY_DELETE          = 261,      // Key: Del
    KEY_RIGHT           = 262,      // Key: Cursor right
    KEY_LEFT            = 263,      // Key: Cursor left
    KEY_DOWN            = 264,      // Key: Cursor down
    KEY_UP              = 265,      // Key: Cursor up
    KEY_PAGE_UP         = 266,      // Key: Page up
    KEY_PAGE_DOWN       = 267,      // Key: Page down
    KEY_HOME            = 268,      // Key: Home
    KEY_END             = 269,      // Key: End
    KEY_CAPS_LOCK       = 280,      // Key: Caps lock
    KEY_SCROLL_LOCK     = 281,      // Key: Scroll down
    KEY_NUM_LOCK        = 282,      // Key: Num lock
    KEY_PRINT_SCREEN    = 283,      // Key: Print screen
    KEY_PAUSE           = 284,      // Key: Pause
    KEY_F1              = 290,      // Key: F1
    KEY_F2              = 291,      // Key: F2
    KEY_F3              = 292,      // Key: F3
    KEY_F4              = 293,      // Key: F4
    KEY_F5              = 294,      // Key: F5
    KEY_F6              = 295,      // Key: F6
    KEY_F7              = 296,      // Key: F7
    KEY_F8              = 297,      // Key: F8
    KEY_F9              = 298,      // Key: F9
    KEY_F10             = 299,      // Key: F10
    KEY_F11             = 300,      // Key: F11
    KEY_F12             = 301,      // Key: F12
    KEY_LEFT_SHIFT      = 340,      // Key: Shift left
    KEY_LEFT_CONTROL    = 341,      // Key: Control left
    KEY_LEFT_ALT        = 342,      // Key: Alt left
    KEY_LEFT_SUPER      = 343,      // Key: Super left
    KEY_RIGHT_SHIFT     = 344,      // Key: Shift right
    KEY_RIGHT_CONTROL   = 345,      // Key: Control right
    KEY_RIGHT_ALT       = 346,      // Key: Alt right
    KEY_RIGHT_SUPER     = 347,      // Key: Super right
    KEY_KB_MENU         = 348,      // Key: KB menu
    // Keypad keys
    KEY_KP_0            = 320,      // Key: Keypad 0
    KEY_KP_1            = 321,      // Key: Keypad 1
    KEY_KP_2            = 322,      // Key: Keypad 2
    KEY_KP_3            = 323,      // Key: Keypad 3
    KEY_KP_4            = 324,      // Key: Keypad 4
    KEY_KP_5            = 325,      // Key: Keypad 5
    KEY_KP_6            = 326,      // Key: Keypad 6
    KEY_KP_7            = 327,      // Key: Keypad 7
    KEY_KP_8            = 328,      // Key: Keypad 8
    KEY_KP_9            = 329,      // Key: Keypad 9
    KEY_KP_DECIMAL      = 330,      // Key: Keypad .
    KEY_KP_DIVIDE       = 331,      // Key: Keypad /
    KEY_KP_MULTIPLY     = 332,      // Key: Keypad *
    KEY_KP_SUBTRACT     = 333,      // Key: Keypad -
    KEY_KP_ADD          = 334,      // Key: Keypad +
    KEY_KP_ENTER        = 335,      // Key: Keypad Enter
    KEY_KP_EQUAL        = 336,      // Key: Keypad =
    // Android key buttons
    KEY_BACK            = 4,        // Key: Android back button
    KEY_MENU            = 5,        // Key: Android menu button
    KEY_VOLUME_UP       = 24,       // Key: Android volume up button
    KEY_VOLUME_DOWN     = 25        // Key: Android volume down button
} KeyboardKeys;

typedef enum {
    MOUSE_BUTTON_LEFT    = 0,       // Mouse button left
    MOUSE_BUTTON_RIGHT   = 1,       // Mouse button right
    MOUSE_BUTTON_MIDDLE  = 2,       // Mouse button middle (pressed wheel)
    MOUSE_BUTTON_SIDE    = 3,       // Mouse button side (advanced mouse device)
    MOUSE_BUTTON_EXTRA   = 4,       // Mouse button extra (advanced mouse device)
    MOUSE_BUTTON_FORWARD = 5,       // Mouse button forward (advanced mouse device)
    MOUSE_BUTTON_BACK    = 6,       // Mouse button back (advanced mouse device)
} MouseButtons;

typedef enum {
    BLEND_ADD = 0,
    BLEND_SCREEN = 1,
    BLEND_SUB = 2,
    BLEND_ALPHA = 3,
    BLEND_THING = 4,
} BlendingModes;

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
    float r;
    float g;
    float b;
    float a;
} Color;

typedef struct {
    float x;
    float y;
    float w;
    float h;
} Rect;

typedef struct {
    float x;
    float y;
    float radius;
} Circle;

typedef struct {
    float x1;
    float y1;
    float x2;
    float y2;
    float width;
} Line;

typedef struct {
    int width;
    int height;
    GLFWwindow* window;
} Window;

typedef struct {
    int fxaaSamples;
    int fps;
    int vsync;
    int closeKey;

    double deltaTime;
    double currentTime;
    double lastTime;

    Vector2 mousePos;
    Window window;
} WrapperCore;

const Color BLACK        = (Color){0.0f, 0.0f, 0.0f, 1.0f};
const Color WHITE        = (Color){1.0f, 1.0f, 1.0f, 1.0f};
const Color NOCOLOR      = (Color){0.0f, 0.0f, 0.0f, 0.0f};

const Color RED          = (Color){1.0f, 0.0f, 0.0f, 1.0f};
const Color GREEN        = (Color){0.0f, 1.0f, 0.0f, 1.0f};
const Color BLUE         = (Color){0.0f, 0.0f, 1.0f, 1.0f};
const Color YELLOW       = (Color){1.0f, 1.0f, 0.0f, 1.0f};
const Color AQUA         = (Color){0.0f, 1.0f, 1.0f, 1.0f};
const Color MAGENTA      = (Color){1.0f, 0.0f, 1.0f, 1.0f};

const Color LIGHTRED     = (Color){1.0f, 0.5f, 0.5f, 1.0f};
const Color LIGHTGREEN   = (Color){0.5f, 1.0f, 0.5f, 1.0f};
const Color LIGHTBLUE    = (Color){0.5f, 0.5f, 1.0f, 1.0f};
const Color LIGHTYELLOW  = (Color){1.0f, 1.0f, 0.5f, 1.0f};
const Color LIGHTAQUA    = (Color){0.5f, 1.0f, 1.0f, 1.0f};
const Color LIGHTMAGENTA = (Color){1.0f, 0.5f, 1.0f, 1.0f};

const Color DARKRED      = (Color){0.5f, 0.0f, 0.0f, 1.0f};
const Color DARKGREEN    = (Color){0.0f, 0.5f, 0.0f, 1.0f};
const Color DARKBLUE     = (Color){0.0f, 0.0f, 0.5f, 1.0f};
const Color DARKYELLOW   = (Color){0.5f, 0.5f, 0.0f, 1.0f};
const Color DARKAQUA     = (Color){0.0f, 0.5f, 0.5f, 1.0f};
const Color DARKMAGENTA  = (Color){0.5f, 0.0f, 0.5f, 1.0f};

static WrapperCore CORE = {
    .fxaaSamples = 0,
    .fps = 60,
    .vsync = 1,
    .closeKey = KEY_ESCAPE,
    .deltaTime = 1,
    .currentTime = 0,
    .lastTime = 0,
    .mousePos = {0},
    .window = {0},
};

/*

Miscelaneous

*/

Shader LoadShader(const char *vertexPath, const char *fragPath) { 
    // To-do
    return (Shader){0};
}

static void printCoreInfo() {
    printf(
        "\nWelcome to GLFWrapper!\n"
        "\nScreen size:\t(%d, %d)"
        "\nTarget Fps:\t%d"
        "\nVsync Factor:\t%d\n", 
        CORE.window.width,
        CORE.window.height,
        CORE.fps,
        CORE.vsync
    );
}

/*

Math

*/

int randInt(int min, int max) {
    return rand() % ((max+1) -min) + min;
}

float distance(Vector2 vecA, Vector2 vecB) {
    return sqrt(pow(vecA.x - vecB.x, 2) + pow(vecA.y - vecB.y, 2));
}

void limitI(int *num, int from, int to){
        if((*num) < from) (*num) = from;
        if((*num) > to) (*num) = to;
}

void limitF(float *num, float from, float to){
        if((*num) < from) (*num) = from;
        if((*num) > to) (*num) = to;
}

void limitD(double *num, double from, double to){
        if((*num) < from) (*num) = from;
        if((*num) > to) (*num) = to;
}

void Vector2Add(Vector2 *vectorA, Vector2 vectorB) {
    vectorA->x += vectorB.x;
    vectorA->y += vectorB.y;
}

void Vector2Dot(Vector2 *vectorA, float dot) {
    vectorA->x *= dot;
    vectorA->y *= dot;
}

/*

Input capture

*/

int isKeyDown(int key) {
    int state = glfwGetKey(CORE.window.window, key);

    if(state == GLFW_PRESS) {
        return 1;
    }
    return 0;
}

int isKeyReleased(int key) {
    int state = glfwGetKey(CORE.window.window, key);

    if(state == GLFW_RELEASE) {
        return 1;
    }
    return 0;
}

void setCloseKey(int newKey) {
    CORE.closeKey = newKey;
}

int isMouseButtonDown(int key) {
    int state = glfwGetMouseButton(CORE.window.window, key);
    if (state == GLFW_PRESS) {
        return 1;
    }
    return 0;
}

int isMouseButtonReleased(int key) {
    int state = glfwGetMouseButton(CORE.window.window, key);
    if (state == GLFW_RELEASE) {
        return 1;
    }
    return 0;
}

Vector2 getMousePos() {
    double x, y;
    glfwGetCursorPos(CORE.window.window, &x, &y);

    CORE.mousePos.x = (float)x;
    CORE.mousePos.y = (float)y;

    return (Vector2){
        (2*CORE.mousePos.x/CORE.window.width)-1,
        (-2*CORE.mousePos.y/CORE.window.height)+1
    };
}

double getMouseX() {
    double x, y;
    glfwGetCursorPos(CORE.window.window, &x, &y);
    //glfwSetInputMode(CORE.window.window, GLFW_CURSOR, GLFW_CURSOR_CAPTURED);
    CORE.mousePos.x = (float)x;

    return (2*CORE.mousePos.x/CORE.window.width)-1;
}

double getMouseY() {
    double x, y;
    glfwGetCursorPos(CORE.window.window, &x, &y);
    //glfwSetInputMode(CORE.window.window, GLFW_CURSOR, GLFW_CURSOR_CAPTURED);
    CORE.mousePos.y = (float)y;

    return (-2*CORE.mousePos.y/CORE.window.height)+1;
}

Vector2 getMouseMotion() {
// To-Do
    return (Vector2){0,0};
}

/*

Window stuff

*/

void forceProgramClose() {
    glfwTerminate();
    exit(1);
}

void setAntialiasingFactor(int factor) {
    CORE.fxaaSamples = factor;
}

void createWindow(int width, int height, const char* name) {
    srand(time(NULL));
    // Initialize the library
    if (!glfwInit()) {
        fprintf(stderr, "Error: GLFW didnt load (Error code 1)");
        exit(1);
    }

    glfwWindowHint(GLFW_SAMPLES, CORE.fxaaSamples);

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(width, height, name, NULL, NULL);

    if (!window) {
        fprintf(stderr, "Error: Window didnt load (Error code 2)");
        glfwTerminate();
        exit(1);
    }
    printCoreInfo();
    // Make the window's context current
    glfwMakeContextCurrent(window);
    glfwSwapInterval(CORE.vsync);

    CORE.window = (Window){width, height, window};
    
} 

void updateWindow() {
    glfwPollEvents();

    CORE.currentTime = glfwGetTime();
    CORE.deltaTime = CORE.currentTime - CORE.lastTime;
    CORE.lastTime = CORE.currentTime;
    
    if(isKeyDown(CORE.closeKey)) {
        forceProgramClose();
    }

    glfwSwapBuffers(CORE.window.window);
}

int isWindowOpen() {
    return !glfwWindowShouldClose(CORE.window.window);
}

void closeWindow() {
    glfwTerminate();
    printf("GLFW Closed succesfully");
}

/*

Fps stuff

*/

double getFPS() {
    return 1/CORE.deltaTime;
}

double getFrameTime() {
    return CORE.deltaTime;
}

double getDeltaTime() {
    return CORE.deltaTime * CORE.fps;
}

void setVsync(int factor) {
    CORE.vsync = factor;
    glfwSwapInterval(CORE.vsync);
}

/*

Blending stuff

*/

void beginBlending(BlendingModes mode) {
    glEnable(GL_BLEND);
    switch(mode){
        case BLEND_ADD: glBlendFunc(GL_ONE, GL_ONE); break;
        case BLEND_SCREEN: glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO); break;
        case BLEND_SUB: glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ONE); break;
        case BLEND_ALPHA: glBlendFunc(GL_ZERO, GL_ONE); break;
        case BLEND_THING: glBlendFunc(GL_SRC_ALPHA_SATURATE, GL_ONE); break;
    }
}

void endBlending() {
    glDisable(GL_BLEND);
}

/*
Drawing Modes for Opengl

see https://learn.microsoft.com/es-es/windows/win32/opengl/glbegin for more info

*/

void updateBackgroundColor(Color color) {
    glClearColor(color.r,color.g,color.b,color.a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void drawLine(float x1, float y1, float x2, float y2, float wide, Color color) {
    glLineWidth(wide);
    glBegin(GL_LINES);
    glColor4f(color.r, color.g, color.b, color.a);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);

    glEnd();
    glLineWidth(1);
}

void drawLineLine(Line line, Color color) {
    glLineWidth(line.width);
    glBegin(GL_LINES);
    glColor4f(color.r, color.g, color.b, color.a);
    glVertex2f(line.x1, line.y1);
    glVertex2f(line.x2, line.y2);

    glEnd();
    glLineWidth(1);
}

void drawTriangle(float x, float y, float w, float h, Color color) {
    glBegin(GL_TRIANGLES);
    glColor4f(color.r, color.g, color.b, color.a);

    glVertex2f(x,y);
    glVertex2f(x-(w/2.0f), y-h);
    glVertex2f(x+(w/2.0f), y-h);

    glEnd();
}

void drawTriangleRect(Rect rect, Color color) {
    glBegin(GL_TRIANGLES);
    glColor4f(color.r, color.g, color.b, color.a);

    glVertex2f(rect.x,rect.y);
    glVertex2f(rect.x-(rect.w/2.0f), rect.y-rect.h);
    glVertex2f(rect.x+(rect.w/2.0f), rect.y-rect.h);

    glEnd();
}

void drawTriangleLines(float x, float y, float w, float h, float wide, Color color) {
    glLineWidth(wide);
    glBegin(GL_LINES);
    glColor4f(color.r, color.g, color.b, color.a);
    glVertex2f(x  ,y  );
    glVertex2f(x+(w/2.0f)  ,y-h);

    glVertex2f(x  ,y  );
    glVertex2f(x-(w/2.0f)  ,y-h);

    glVertex2f(x+(w/2.0f)  ,y-h);
    glVertex2f(x-(w/2.0f)  ,y-h);

    glEnd();
    glLineWidth(1);
}

void drawRectangle(float x, float y, float w, float h, Color color) {
    glBegin(GL_TRIANGLES);
    glColor4f(color.r, color.g, color.b, color.a);
    glVertex2f(x  ,y  );
    glVertex2f(x  ,y-h);
    glVertex2f(x+w,y-h);

    glVertex2f(x  ,y  );
    glVertex2f(x+w,y  );
    glVertex2f(x+w,y-h);

    glEnd();
}

void drawRectangleRect(Rect rect, Color color) {
    glBegin(GL_TRIANGLES);
    glColor4f(color.r, color.g, color.b, color.a);

    glVertex2f(rect.x       ,rect.y  );
    glVertex2f(rect.x       ,rect.y-rect.h);
    glVertex2f(rect.x+rect.w,rect.y-rect.h);

    glVertex2f(rect.x       ,rect.y  );
    glVertex2f(rect.x+rect.w,rect.y  );
    glVertex2f(rect.x+rect.w,rect.y-rect.h);

    glEnd();
}

void drawRectangleLines(float x, float y, float w, float h, float wide, Color color) {
    glLineWidth(wide);
    glBegin(GL_LINES);
    glColor4f(color.r, color.g, color.b, color.a);

    glVertex2f(x  ,y  );
    glVertex2f(x+w,y  );

    glVertex2f(x+w,y  );
    glVertex2f(x+w,y-h);

    glVertex2f(x+w,y-h);
    glVertex2f(x  ,y-h);

    glVertex2f(x  ,y-h);
    glVertex2f(x  ,y  );

    glEnd();
    glLineWidth(1);
}

void drawPolygonLines(float centerx, float centery, float size, int sides, float wide, Color color) {
    glLineWidth(wide);
    glBegin(GL_LINES);
    glColor4f(color.r, color.g, color.b, color.a);

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
    glLineWidth(1);
}

void drawPolygon(float centerx, float centery, float radius, int sides, Color color) {
    glBegin(GL_TRIANGLE_FAN);
    glColor4f(color.r, color.g, color.b, color.a);
    glVertex2f(centerx, centery);

    for(int i = 0; i < sides; i++) {
        glVertex2f(
            centerx + radius*cos(i*DEG2RAD*( 360/sides) ),
            centery - radius*sin(i*DEG2RAD*( 360/sides) )
        );
        glVertex2f(
            centerx + radius*cos((i+1)*DEG2RAD*( 360/sides) ),
            centery - radius*sin((i+1)*DEG2RAD*( 360/sides) )
        );
    }

    glEnd();
}

void drawPolygonRot(float centerx, float centery, float initAngle, float radius, int sides, Color color) {
    glBegin(GL_TRIANGLE_FAN);
    glColor4f(color.r, color.g, color.b, color.a);
    glVertex2f(centerx, centery);

    for(int i = 0; i < sides; i++) {
        glVertex2f(
            centerx + radius*cos(i*DEG2RAD*( 360/sides)+ DEG2RAD*initAngle ),
            centery - radius*sin(i*DEG2RAD*( 360/sides)+ DEG2RAD*initAngle )
        );
        glVertex2f(
            centerx + radius*cos((i+1)*DEG2RAD*( 360/sides) + DEG2RAD*initAngle),
            centery - radius*sin((i+1)*DEG2RAD*( 360/sides) + DEG2RAD*initAngle)
        );
    }

    glEnd();
}

void drawPolygonRotLines(float centerx, float centery, float initAngle, float radius, int sides, float wide, Color color) {
    glLineWidth(wide);
    glBegin(GL_LINES);
    glColor4f(color.r, color.g, color.b, color.a);

    for(int i = 0; i < sides; i++) {
        glVertex2f(
            centerx + radius*cos(i*DEG2RAD*( 360/sides)+ DEG2RAD*initAngle ),
            centery - radius*sin(i*DEG2RAD*( 360/sides)+ DEG2RAD*initAngle )
        );
        glVertex2f(
            centerx + radius*cos((i+1)*DEG2RAD*( 360/sides) + DEG2RAD*initAngle),
            centery - radius*sin((i+1)*DEG2RAD*( 360/sides) + DEG2RAD*initAngle)
        );
    }

    glEnd();
    glLineWidth(1);
}

void drawPolygonCircle(Circle circle, int sides, Color color) {
    glBegin(GL_TRIANGLE_FAN);
    glColor4f(color.r, color.g, color.b, color.a);
    glVertex2f(circle.x, circle.y);

    for(int i = 0; i < sides; i++) {
        glVertex2f(
            circle.x + circle.radius*cos(i*DEG2RAD*( 360/sides) ),
            circle.y - circle.radius*sin(i*DEG2RAD*( 360/sides) )
        );
        glVertex2f(
            circle.x + circle.radius*cos((i+1)*DEG2RAD*( 360/sides) ),
            circle.y - circle.radius*sin((i+1)*DEG2RAD*( 360/sides) )
        );
    }

    glEnd();
}

void drawCircle(float centerx, float centery, float radius, Color color) {
    glBegin(GL_TRIANGLE_FAN);
    glColor4f(color.r, color.g, color.b, color.a);
    glVertex2f(centerx, centery);

    for(int i = 0; i < MAX_CIRCLE_SIDES; i++) {
        glVertex2f(
            centerx + radius*cos(i*DEG2RAD*( 360/MAX_CIRCLE_SIDES) ),
            centery - radius*sin(i*DEG2RAD*( 360/MAX_CIRCLE_SIDES) )
        );
        glVertex2f(
            centerx + radius*cos((i+1)*DEG2RAD*( 360/MAX_CIRCLE_SIDES) ),
            centery - radius*sin((i+1)*DEG2RAD*( 360/MAX_CIRCLE_SIDES) )
        );
    }

    glEnd();
}

void drawCircleCircle(Circle circle, Color color) {
    glBegin(GL_TRIANGLE_FAN);
    glColor4f(color.r, color.g, color.b, color.a);
    glVertex2f(circle.x, circle.y);

    for(int i = 0; i < MAX_CIRCLE_SIDES; i++) {
        glVertex2f(
            circle.x + circle.radius*cos(i*DEG2RAD*( 360/MAX_CIRCLE_SIDES) ),
            circle.y - circle.radius*sin(i*DEG2RAD*( 360/MAX_CIRCLE_SIDES) )
        );
        glVertex2f(
            circle.x + circle.radius*cos((i+1)*DEG2RAD*( 360/MAX_CIRCLE_SIDES) ),
            circle.y - circle.radius*sin((i+1)*DEG2RAD*( 360/MAX_CIRCLE_SIDES) )
        );
    }

    glEnd();
}

//Collision checkers:
int checkCollisionRectCircle(Rect rect, Circle circle) {
    // Considerar que rect.y es la parte SUPERIOR del rectángulo
    // y rect.h es la altura hacia ABAJO (coordenadas OpenGL)
    float rectLeft = rect.x;
    float rectRight = rect.x + rect.w;
    float rectTop = rect.y;  // Parte superior
    float rectBottom = rect.y - rect.h;  // Parte inferior
    
    // Encontrar el punto más cercano en el rectángulo al círculo
    float closestX = fmaxf(rectLeft, fminf(circle.x, rectRight));
    float closestY = fmaxf(rectBottom, fminf(circle.y, rectTop));
    
    // Calcular distancia al cuadrado
    float dx = circle.x - closestX;
    float dy = circle.y - closestY;
    float distanceSquared = (dx * dx) + (dy * dy);
    
    return distanceSquared <= (circle.radius * circle.radius);
}

int checkCollisionCircles(Circle a, Circle b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    float distanceSquared = dx * dx + dy * dy;
    float radiusSum = a.radius + b.radius;

    return distanceSquared <= (radiusSum * radiusSum);
}

int checkCollisionRects(Rect rectA, Rect rectB) {
    return (
        rectA.x < rectB.x + rectB.w &&
        rectA.x + rectA.w > rectB.x &&
        rectA.y < rectB.y + rectB.h &&
        rectA.y + rectA.h > rectB.y
    );
}

#endif
