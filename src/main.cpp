#include "main.h"
#include "assets.h"
#include "timer.h"

GLuint programID;
GLFWwindow* window;
GLMatrices Matrices;
glm::mat4 VP;

void tick_elements() {
    b1.tick();
    b2.tick();
}

int main (int argc, char** argv)
{
    int width = 600;
    int height = 600;

    window = initGLFW(width, height);

    initGL (window, width, height);

    Timer t60(1/60.0);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}
