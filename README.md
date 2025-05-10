# Basic Setup
```c
#include "glfwrapper.h"

int main() {
    Window* window = createWindow(640, 640, "Easy Example");

    // Loop until the user closes the window
    while (isWindowOpen(window)) {
        updateBackgroundColor(BLACK);

        drawRectangle(0.0f, 0.0f, 1.0f, 1.0f, RED);

        updateWindow(window);
    }

    closeWindow();
    return 0;
}
```

# Install compiler
Download [here](https://github.com/niXman/mingw-builds-binaries/releases/download/14.2.0-rt_v12-rev1/x86_64-14.2.0-release-win32-seh-msvcrt-rt_v12-rev1.7z) \
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

# Run
In the main.c directory, open a cmd, then type `run` 
