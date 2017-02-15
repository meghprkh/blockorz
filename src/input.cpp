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
        bool game_status = true;
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
        if (!game_status) game.lose();
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
        camera_view = (camera_view_t) ((camera_view + 1) % 5);
        break;
    default:
        break;
    }
}

int prev_xpos = 0, prev_ypos = 0;

/* Executed when a mouse button is pressed/released */
void mouseButton (GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        prev_xpos = xpos;
        prev_ypos = ypos;
    }
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

    int width, height;
    glfwGetWindowSize(window, &width, &height);
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
        camera_look_x -= -360 + (xpos - prev_xpos) * 90 / width;
        camera_look_y -= -360 + (ypos - prev_ypos) * 90 / height;
        camera_look_x = camera_look_x > 360 ? camera_look_x - ((int) (camera_look_x / 360))*360 : camera_look_x;
        camera_look_y = camera_look_y > 360 ? camera_look_y - ((int) (camera_look_y / 360))*360 : camera_look_y;
        prev_xpos = xpos;
        prev_ypos = ypos;
    }
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    camera_zoom += yoffset;
}
