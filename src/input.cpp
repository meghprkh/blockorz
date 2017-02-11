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
//    if (glfwGetKey(window, GLFW_KEY_LEFT)) cube.position.x -= 0.05;
//    if (glfwGetKey(window, GLFW_KEY_RIGHT)) cube.position.x += 0.05;
//    if (glfwGetKey(window, GLFW_KEY_UP)) cube.position.y += 0.05;
//    if (glfwGetKey(window, GLFW_KEY_DOWN)) cube.position.y -= 0.05;
//    if (glfwGetKey(window, GLFW_KEY_A)) cube.position.z += 0.05;
//    if (glfwGetKey(window, GLFW_KEY_S)) cube.position.z -= 0.05;
    if (glfwGetKey(window, GLFW_KEY_SPACE)) camera_rotation_angle += 5;
    if (glfwGetKey(window, GLFW_KEY_Z)) camera_y += 0.05;
    if (glfwGetKey(window, GLFW_KEY_X)) camera_y -= 0.05;
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    camera_zoom += yoffset;
}
