
#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include <Windows.h>

#include<winuser.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include<stdlib.h>

#define COLUMNS 40
#define ROWS 40
extern short sDirection;

bool gameOver = false;
int score = 0;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawGrid();
	drawsnake();
	drawfood();
	glutSwapBuffers();
	if (gameOver)
	{
		char _score[10];
		_itoa(score, _score,10);
		char text[50] = "Your score : ";
		strcat(text, _score);
	//	MessageBox(NULL,(LPCWSTR)text,(LPCWSTR)L"Game Over",0);
		MessageBoxA(NULL, text, "Game Over", MB_OK | MB_ICONQUESTION);
		exit(0);
	}
}
void init()
{
	glClearColor(1,1,1,1);
	initGrid(COLUMNS,ROWS);
	
}
void myreshape(int w,int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 40, 0.0, 40, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);


}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 10, timer, 0);
}


void mykey(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		if (sDirection != DOWN)
			sDirection = UP;
		break;
	case GLUT_KEY_DOWN:
		if (sDirection != UP)
			sDirection = DOWN;
		break;
	case GLUT_KEY_RIGHT:
		if (sDirection != LEFT)
			sDirection = RIGHT;
		break;
	case GLUT_KEY_LEFT:
		if (sDirection != RIGHT)
			sDirection = LEFT;
		break;
	}
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0,0);
	glutCreateWindow("SNAKE");
	
	glutDisplayFunc(display);
	
	glutReshapeFunc(myreshape);
	
	glutTimerFunc(0,timer,0);

	glutSpecialFunc(mykey);

	glutMainLoop();



}

