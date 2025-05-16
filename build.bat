gcc -c glfwrapper.h -I./include/ -L./lib/ -lglfw3 -lopengl32 -lgdi32
ar crf libglfwrapper.a glfwrapper.h.gch