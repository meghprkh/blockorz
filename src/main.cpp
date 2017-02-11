#include "main.h"
#include "assets.h"
#include "timer.h"

GLuint programID;
GLFWwindow* window;
GLMatrices Matrices;
glm::mat4 VP;

void tick_elements() {
}

int main (int argc, char** argv)
{
    int width = 600;
    int height = 600;

    window = initGLFW(width, height);

    initGL (window, width, height);

    Timer t60(1/60.0), t240(1/240.0);

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

        if (t240.processTick()) {
            // Poll for Keyboard and mouse events
            glfwPollEvents();
        }
    }

    quit(window);
}
