#include "square.h"
#include "colors.h"
#include "models.h"

void Square::init(square_t type)
{
    this->type = type;
    static const GLfloat vertex_buffer_data[] = {
        1.000000, -0.050000, 1.000000,
        -1.000000, -0.050000, -1.000000,
        1.000000, -0.050000, -1.000000,

        -1.000000, 0.050000, -1.000000,
        1.000000, 0.050000, 1.000001,
        1.000000, 0.050000, -1.000000,

        1.000000, 0.050000, -1.000000,
        1.000000, -0.050000, 1.000000,
        1.000000, -0.050000, -1.000000,

        1.000000, 0.050000, 1.000001,
        -1.000000, -0.050000, 1.000000,
        1.000000, -0.050000, 1.000000,

        -1.000000, 0.050000, 1.000000,
        -1.000000, -0.050000, -1.000000,
        -1.000000, -0.050000, 1.000000,

        1.000000, -0.050000, -1.000000,
        -1.000000, 0.050000, -1.000000,
        1.000000, 0.050000, -1.000000,

        1.000000, -0.050000, 1.000000,
        -1.000000, -0.050000, 1.000000,
        -1.000000, -0.050000, -1.000000,

        -1.000000, 0.050000, -1.000000,
        -1.000000, 0.050000, 1.000000,
        1.000000, 0.050000, 1.000001,

        1.000000, 0.050000, -1.000000,
        1.000000, 0.050000, 1.000001,
        1.000000, -0.050000, 1.000000,

        1.000000, 0.050000, 1.000001,
        -1.000000, 0.050000, 1.000000,
        -1.000000, -0.050000, 1.000000,

        -1.000000, 0.050000, 1.000000,
        -1.000000, 0.050000, -1.000000,
        -1.000000, -0.050000, -1.000000,

        1.000000, -0.050000, -1.000000,
        -1.000000, -0.050000, -1.000000,
        -1.000000, 0.050000, -1.000000,
    };

    static const GLfloat edge_vertex_buffer_data[] = {
        1.000999, 0.051000, 1.001001,
        -1.001000, 0.051000, 1.001000,
        -1.001000, -0.051000, 1.001000,

        1.001001, 0.051000, -1.000999,
        1.000999, 0.051000, 1.001001,
        1.001000, -0.051000, 1.001000,

        1.001001, 0.051000, -1.000999,
        1.001000, -0.051000, 1.001000,
        1.001000, -0.051000, -1.001000,

        1.000999, 0.051000, 1.001001,
        -1.001000, -0.051000, 1.001000,
        1.001000, -0.051000, 1.001000,

        -1.001000, -0.051000, 1.001000,
        -1.001000, 0.051000, -1.001000,
        -1.001000, -0.051000, -1.001000,

        1.001000, -0.051000, -1.001000,
        -1.001000, 0.051000, -1.001000,
        1.001001, 0.051000, -1.000999,

        0.900900, -0.051000, 0.900900,
        1.001000, -0.051000, -1.001000,
        1.001000, -0.051000, 1.001000,

        0.900900, -0.051000, -0.900900,
        -1.001000, -0.051000, -1.001000,
        1.001000, -0.051000, -1.001000,

        0.900900, -0.051000, 0.900900,
        -1.001000, -0.051000, 1.001000,
        -0.900900, -0.051000, 0.900900,

        -0.900900, -0.051000, -0.900900,
        -1.001000, -0.051000, 1.001000,
        -1.001000, -0.051000, -1.001000,

        0.900899, 0.051000, 0.900901,
        1.001001, 0.051000, -1.000999,
        0.900900, 0.051000, -0.900900,

        0.900900, 0.051000, -0.900900,
        -1.001000, 0.051000, -1.001000,
        -0.900900, 0.051000, -0.900900,

        0.900899, 0.051000, 0.900901,
        -1.001000, 0.051000, 1.001000,
        1.000999, 0.051000, 1.001001,

        -0.900900, 0.051000, -0.900900,
        -1.001000, 0.051000, 1.001000,
        -0.900900, 0.051000, 0.900900,

        -1.001000, -0.051000, 1.001000,
        -1.001000, 0.051000, 1.001000,
        -1.001000, 0.051000, -1.001000,

        1.001000, -0.051000, -1.001000,
        -1.001000, -0.051000, -1.001000,
        -1.001000, 0.051000, -1.001000,

        0.900900, -0.051000, 0.900900,
        0.900900, -0.051000, -0.900900,
        1.001000, -0.051000, -1.001000,

        0.900900, -0.051000, -0.900900,
        -0.900900, -0.051000, -0.900900,
        -1.001000, -0.051000, -1.001000,

        0.900900, -0.051000, 0.900900,
        1.001000, -0.051000, 1.001000,
        -1.001000, -0.051000, 1.001000,

        -0.900900, -0.051000, -0.900900,
        -0.900900, -0.051000, 0.900900,
        -1.001000, -0.051000, 1.001000,

        0.900899, 0.051000, 0.900901,
        1.000999, 0.051000, 1.001001,
        1.001001, 0.051000, -1.000999,

        0.900900, 0.051000, -0.900900,
        1.001001, 0.051000, -1.000999,
        -1.001000, 0.051000, -1.001000,

        0.900899, 0.051000, 0.900901,
        -0.900900, 0.051000, 0.900900,
        -1.001000, 0.051000, 1.001000,

        -0.900900, 0.051000, -0.900900,
        -1.001000, 0.051000, -1.001000,
        -1.001000, 0.051000, 1.001000,
    };

    color_t col;
    if (type == SQUARE_NORMAL) col = COLOR_RED;
    else if (type == SQUARE_WEAK) col = COLOR_GREEN;
    else if (type == SQUARE_B1SO || type == SQUARE_B2SO) col = COLOR_CANNON1;
    else if (type == SQUARE_B1SX || type == SQUARE_B2SX) col = COLOR_CANNON2;
    else if (type == SQUARE_TELEPORT) col = COLOR_BLACK;

    this->object = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, col, GL_FILL);
    this->object_edge = create3DObject(GL_TRIANGLES, 24*3, edge_vertex_buffer_data, 0.75, .15, .25, GL_FILL);
    if (type == SQUARE_B1SO || type == SQUARE_B2SO) this->object_switch = create3DObject(GL_TRIANGLES, switchot * 3, switcho, COLOR_LASER, GL_FILL);
    else if (type == SQUARE_B1SX || type == SQUARE_B2SX) this->object_switch = create3DObject(GL_TRIANGLES, switchxt * 3, switchx, COLOR_LASER, GL_FILL);
}

void Square::draw() {
    if (this->object == NULL || type == SQUARE_HOLE || type == SQUARE_NONE || (type == SQUARE_B1 && !bridge1) || (type == SQUARE_B2 && !bridge2)) return;
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);        // glTranslatef
    Matrices.model *= translate;
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object_edge);
    MVP = VP * glm::translate(glm::vec3(0, 0.1, 0)) * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    if (this->object_switch) draw3DObject(this->object_switch);
}

void Square::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}
