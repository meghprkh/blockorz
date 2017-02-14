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
        bool game_status;
        switch (key) {
        case GLFW_KEY_ESCAPE:
            quit(window);
            break;
        case GLFW_KEY_LEFT:
            game_status = game.move(DIR_LEFT);
            break;
        case GLFW_KEY_RIGHT:
            game_status = game.move(DIR_RIGHT);
            break;
        case GLFW_KEY_UP:
            game_status = game.move(DIR_UP);
            break;
        case GLFW_KEY_DOWN:
            game_status = game.move(DIR_DOWN);
            break;
        default:
            break;
        }
        if (!game_status) game.init();
    }
}

/* Executed for character input (like in text boxes) */
void keyboardChar (GLFWwindow* window, unsigned int key) {
    switch (key) {
    case 'Q':
    case 'q':
        quit(window);
        break;
    case 'c':
        camera_ortho = !camera_ortho;
        break;
    case 'v':
        camera_view = (camera_view_t) ((camera_view + 1) % 3);
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
//    if (glfwGetKey(window, GLFW_KEY_LEFT)) game.move(DIR_LEFT);
//    if (glfwGetKey(window, GLFW_KEY_RIGHT)) game.move(DIR_RIGHT);
//    if (glfwGetKey(window, GLFW_KEY_UP)) game.move(DIR_UP);
//    if (glfwGetKey(window, GLFW_KEY_DOWN)) game.move(DIR_DOWN);
//    if (glfwGetKey(window, GLFW_KEY_A)) cube.position.z += 0.05;
//    if (glfwGetKey(window, GLFW_KEY_S)) cube.position.z -= 0.05;
    if (glfwGetKey(window, GLFW_KEY_SPACE)) camera_rotation_angle += 5;
    if (glfwGetKey(window, GLFW_KEY_Z)) camera_y += 0.05;
    if (glfwGetKey(window, GLFW_KEY_X)) camera_y -= 0.05;
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    camera_zoom += yoffset;
}
