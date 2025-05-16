# Basic Setup
```c
#include "glfwrapper.h"

int main() {
    createWindow(640, 640, "Easy Example");

    // Loop until the user closes the window
    while (isWindowOpen()) {
        updateBackgroundColor(BLACK);

        drawRectangle(0.0f, 0.0f, 1.0f, 1.0f, RED);

        updateWindow();
    }

    closeWindow();
    return 0;
}
```

# Install compiler for windows
Download [here](https://github.com/niXman/mingw-builds-binaries/releases/download/15.1.0-rt_v12-rev0/x86_64-15.1.0-release-posix-seh-ucrt-rt_v12-rev0.7z) \
In the cmd type `setx path "%path%;c:/path/to/gcc.exe` \
Reopen cmd and type `gcc --version` \
You should see something like 
```
gcc.exe (x86_64-posix-seh-rev0, Built by MinGW-Builds project) 14.2.0
Copyright (C) 2024 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

# Install project
To install the project you need to preferably install git, \
at the desired directory, then 
```
git clone https://github.com/AnGlonchas/GLFWrapper
```
Or download the zip directly into the desired directory 

# Compile Project (Windows)
```
gcc main.c -Wall -o a.exe -I./include/ -L./lib/ -lglfw3 -lopengl32 -lgdi32
```

# Project Structure
```
/ProjectName
├── lib/
    ├── libglfw3.a
├── include/
    ├── GL/gl.h
    ├── GLFW/glfw3.h
├── main.c
```

# Run for windows
In the main.c directory, open a cmd, then type `run` 

# How to use in MacOS
If you are using a Mac, you have to use the same files that we have given u, but changing de "libglfw3.a" in the "lib" folder instaling the GLFW Mac's version [here](https://www.glfw.org/download.html) and changing the "libglfw3.a" to the current project instead of the others files in "lib", this way, you must play the game if you follow the next steps in "Terminal":

Install Homebrew
```
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```
Install glfw
```
brew install glfw
```
Go to the "GLFWrapper" folder using "cd file_x" and use this code:
```
gcc pong.c -o programa \
  -I/opt/homebrew/include \
  -L/opt/homebrew/lib \
  -lglfw \
  -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo \
  -DGL_SILENCE_DEPRECATION
```
After that, just type the next executable and you would be able to play it: 
```
./programa
```
