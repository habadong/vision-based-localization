#include "GL/freeglut.h"
 
 
void changeSize(int w, int h) {
 
    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if (h == 0)
        h = 1;
 
    float ratio = w * 1.0 / h;
 
    // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);
 
    // Reset Matrix
    glLoadIdentity();
 
    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);
 
    // Set the correct perspective.
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);
 
    // Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}
 
float angle = 0.0f;
 
void renderScene(void) {   // renderSence 전체를 쉐이더로 바꿔???
 
    // Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
    // Reset transformations
    glLoadIdentity();
    // Set the camera
    gluLookAt(0.0f, 0.0f, 10.0f,    
        0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f); //버전 2개로 해봐도 됨 여기다가 받은 데이터를 넘겨서 적용해봐도 되고 쉐이터 적용해서 바꿔봐도되고
 
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
 
    glBegin(GL_TRIANGLES);
    glVertex3f(-2.0f, -2.0f, 0.0f);
    glVertex3f(2.0f, 0.0f, 0.0);
    glVertex3f(0.0f, 2.0f, 0.0); //좌표를 텍스트로 출력을 해야되는데 같이 3D로 돌아버림 -? 공간상에 글자를 opencv화면에 표시하는걸로
    glEnd();
 
    angle += 0.1f;
 
    glutSwapBuffers();
}
 
int main(int argc, char **argv) {
 
    // init GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(500, 500);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL");
 
    // register callbacks
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
 
    // enter GLUT event processing cycle
    glutMainLoop();
 
    return 1;
}
