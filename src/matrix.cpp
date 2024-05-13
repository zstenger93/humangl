#include "../includes/includes.hpp"

void rotatePoint(glm::vec3 &point, glm::vec3 angle, glm::vec3 &rotationPoint) {
    float x, y, z, temp_y, temp_x, temp_z;
    point -= rotationPoint;
    glm::vec3 rad = glm::radians(angle);
    // x
    temp_y = point.y;
    temp_z = point.z;
    y = temp_y * cos(rad.x) - temp_z * sin(rad.x);
    z = temp_y * sin(rad.x) + temp_z * cos(rad.x);

    // y
    temp_x = point.x;
    temp_z = z;
    x = temp_x * cos(rad.y) + temp_z * sin(rad.y);
    z = -temp_x * sin(rad.y) + temp_z * cos(rad.y);

    // z
    temp_x = x;
    temp_y = y;
    x = temp_x * cos(rad.z) - temp_y * sin(rad.z);
    y = temp_x * sin(rad.z) + temp_y * cos(rad.z);

    point.x = x;
    point.y = y;
    point.z = z;
    point += rotationPoint;
}