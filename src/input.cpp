#include "main.h"
#include "assets.h"

/* Executed when a regular key is pressed/released/held-down */
/* Prefered for Keyboard events */
void keyboard (GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // Function is called first on GLFW_PRESS.

    if (action == GLFW_RELEASE) {

    }
    else if (action == GLFW_PRESS) {
        switch (key) {
        case GLFW_KEY_ESCAPE:
            quit(window);
            break;
        default:
            break;
        }
    }
}

/* Executed for character input (like in text boxes) */
void keyboardChar (GLFWwindow* window, unsigned int key) {
    switch (key) {
    case 'Q':
    case 'q':
        quit(window);
        break;
    default:
        break;
    }
}

/* Executed when a mouse button is pressed/released */
void mouseButton (GLFWwindow* window, int button, int action, int mods) {

}

/* Process continuous input */
void tick_input(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_LEFT)) b1.position.x -= 0.05;
}
