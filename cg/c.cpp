#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the body
    glColor3f(0.4f, 0.4f, 0.4f);  // Set body color to gray
    glutSolidCube(1.5);  // Draw a cube for the body

    // Draw the head
    glColor3f(0.4f, 0.4f, 0.4f);  // Set head color to gray
    glTranslatef(0.0f, 1.5f, 0.0f);  // Move to the head position
    glutSolidCube(0.8);  // Draw a cube for the head

    // Draw the horns
    glColor3f(0.8f, 0.4f, 0.1f);  // Set horn color to brown

    glPushMatrix();
    glTranslatef(0.4f, 1.7f, 0.0f);  // Move to the right horn position
    glScalef(0.3f, 0.3f, 0.3f);  // Scale the horn dimensions
    glutSolidSphere(1.0, 50, 50);  // Draw the right horn
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4f, 1.7f, 0.0f);  // Move to the left horn position
    glScalef(0.3f, 0.3f, 0.3f);  // Scale the horn dimensions
    glutSolidSphere(1.0, 50, 50);  // Draw the left horn
    glPopMatrix();

    // Draw the legs
    glColor3f(0.0f, 0.0f, 0.0f);  // Set leg color to black

    glPushMatrix();
    glTranslatef(-0.6f, -0.75f, 0.6f);  // Move to front left leg position
    glScalef(0.2f, 1.5f, 0.2f);  // Scale the leg dimensions
    glutSolidCube(1.0);  // Draw the front left leg
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6f, -0.75f, 0.6f);  // Move to front right leg position
    glScalef(0.2f, 1.5f, 0.2f);  // Scale the leg dimensions
    glutSolidCube(1.0);  // Draw the front right leg
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.6f, -0.75f, -0.6f);  // Move to back left leg position
    glScalef(0.2f, 1.5f, 0.2f);  // Scale the leg dimensions
    glutSolidCube(1.0);  // Draw the back left leg
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6f, -0.75f, -0.6f);  // Move to back right leg position
    glScalef(0.2f, 1.5f, 0.2f);  // Scale the leg dimensions
    glutSolidCube(1.0);  // Draw the back right leg
    glPopMatrix();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Ox");

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}

