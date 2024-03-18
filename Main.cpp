#include <glut.h>
#include <Windows.h>
#include <iostream>

int curr_width;
int curr_height;
#pragma region  callbacks


void DisplayCallback()
{
	int firstViewPortx = 0;
	int firstViewPorty = 0;
	int firstViewPortw = 0;
	int firstViewPorth = 0;
	int secondViewPortx = 0;
	int secondViewPorty = 0;
	int secondViewPortw = 0;
	int secondViewPorth = 0;
	std::cout << ":my draw called" << std::endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//messing wit viewports for each draw call
	if (curr_width > 640)
	{
		firstViewPortx = 0;
		firstViewPorty = 0;
		firstViewPortw = curr_width / 2;
		firstViewPorth = curr_height;
		secondViewPortx = curr_width / 2;
		secondViewPorty = 0;
		secondViewPortw = curr_width / 2;
		secondViewPorth = curr_height;
	}
	else
	{
		secondViewPortx = 0;
		secondViewPorty = 0;
		secondViewPortw = curr_width / 2;
		secondViewPorth = curr_height;
		firstViewPortx = curr_width / 2;
		firstViewPorty = 0;
		firstViewPortw = curr_width / 2;
		firstViewPorth = curr_height;
	}
	glViewport(firstViewPortx, firstViewPorty, firstViewPortw, firstViewPorth);
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(0.9, 0.5);
	glVertex2f(0.5, 0.9);
	glVertex2f(0.1, 0.5);
	glVertex2f(0.5, 0.1);
	glEnd();
	glViewport(secondViewPortx, secondViewPorty, secondViewPortw, secondViewPorth);
	glColor3f(0.0f, 0.0f, 1.0f);
	glRectf(0.0, 0.0, 1.0f, 1.0f);


	glutSwapBuffers();
};

void ReshapeCallback(int w, int h)
{
	curr_width = w;
	curr_height = h;
	glutPostRedisplay();
}

void MouseEventCallback(int button, int state, int x, int y)
{
	static int counter = 0;
	/*std::cout << counter << ":MouseEventCallbacke called:" <<
		"button:" << button <<
		" :state: " << state <<
		" :x: " << x <<
		" :y: " << y
		<< std::endl;*/
	counter++;
}

void KeyboardEventCallback(unsigned char c, int x, int y)
{
	/*static int counter = 0;
	std::cout << counter << ":KeyboardEventCallback called:" <<
		"char:" << c <<
		" :x: " << x <<
		" :y: " << y
		<< std::endl;
	counter++;*/

	switch (c)
	{
	case 'q':
	case 'Q':
		exit(0);
	}

}
#pragma endregion


void myInit(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	curr_width = 1920;
	curr_height = 1080;
	glutInitWindowSize(curr_width, curr_height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Window title");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0, 1, 0, 1);
	glMatrixMode(GL_MODELVIEW);
}

//set callbacks
void setEvents()
{
	glutDisplayFunc(DisplayCallback);
	glutReshapeFunc(ReshapeCallback);
	glutMouseFunc(MouseEventCallback);
	glutKeyboardFunc(KeyboardEventCallback);
}


int main(int argc, char** argv)
{
	myInit(argc, argv);
	setEvents();

	glutMainLoop();

	return 0;
}