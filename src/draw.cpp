#include "main.h"
#include "assets.h"

double camera_rotation_angle = -135, camera_y = 8, camera_zoom = 0, camera_look_x = 0, camera_look_y = 0;
bool camera_ortho;
camera_view_t camera_view;

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw ()
{
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Scene render
    game.draw();
}
