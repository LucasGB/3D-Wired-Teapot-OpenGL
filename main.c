/*
Author: Lucas Guedes Barboza

Description: 3D visualization of a wired teapot with multiple viewports using OpenGL.

*** To compile and run on linux ***
    - cd to workdir on terminal
    - gcc main.c -o main -lGL -lglut -lGLU
    - ./main
*/

#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static int WIDTH = 800;
static int HEIGHT = 800;

static GLfloat angle = 0.0;

int init(){
    glClearColor (1.0f , 1.0f , 1.0f , 1.0f);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-3.0, 3.0, -3.0, 3.0, 1.0, 50.0);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glColor3f(1.0f, 0.0f, 0.0f);

    // Bottom Left Viewport
    glViewport(0, 0, WIDTH / 2, HEIGHT / 2);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glutWireTeapot(2);

    // Bottom Right Viewport
    glViewport(WIDTH / 2, 0, WIDTH / 2, HEIGHT / 2);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glRotatef (angle, 0.0, 0.0, 1.0);
    glRotatef(45, 1.0, 0.0, 0.0);
    glutWireTeapot(2);

    // Top Left Viewport
    glViewport(0, HEIGHT / 2, WIDTH / 2, HEIGHT / 2);
    glLoadIdentity();
    gluLookAt(0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
    glutWireTeapot(2);

    // Top Right Viewport
    glViewport(WIDTH / 2, HEIGHT / 2, WIDTH / 2, HEIGHT / 2);
    glLoadIdentity();
    gluLookAt(5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glutWireTeapot(2);

    glFlush();
}

void rotate_animation(void) {
    angle = angle + 0.1;

    if(angle > 360.0){ angle = 0; }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - WIDTH) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - HEIGHT) / 2);
    glutCreateWindow("Visualizacao 3D Viewports");
    glutIdleFunc(rotate_animation);
    init();
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glShadeModel(GL_FLAT);
    glutDisplayFunc(display);
    glutMainLoop();

    return EXIT_SUCCESS;
}