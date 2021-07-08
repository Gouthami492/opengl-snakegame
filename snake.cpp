#include "game.h"
#include<GL/glut.h>
#include<ctime>
void drawGrid();
int snake_length = 5;
int gridX, gridY;
bool food = true;
short sDirection = RIGHT;
extern bool gameOver;
int foodx, foody;
extern int score;
int posx[MAX] = { 20,20,20,20,20 }, posy[MAX] = { 20,19,18,17,19 };

void initGrid(int x, int y)
{
	gridX = x;
	gridY = y;

}
void unit(int,int);

void drawGrid()
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			unit(i, j);
		}
	}
		
	unit(20, 20);
}

void unit(int x, int y)
{

	if (x == 0 || y==0 || x == 40 - 1 || y == 40 - 1)
	{
		glLineWidth(3.0);
		glColor3f(1, 0, 0);
	}
	else
	{
		glLineWidth(1.0);
		glColor3f(1.0, 1.0, 1.0);
	}
	glBegin(GL_LINE_LOOP);
	 glVertex2f(x, y);
	 glVertex2f(x + 1, y);
	 glVertex2f(x + 1, y + 1);
	 glVertex2f(x, y + 1);

	glEnd();
	glFlush();
}

void drawfood()
{
	if (food)
		random(foodx, foody);
	food = false;
	glColor3f(1, 1, 1);
	glRectf(foodx, foody, foodx + 1, foody + 1);
	
}
void drawsnake()
{

	glColor3f(0, 1, 0);
	for (int i = snake_length - 1; i > 0;i--)
	{
		posx[i] = posx[i - 1];
		posy[i] = posy[i - 1];
		
	}


	if (sDirection == UP)
		posy[0]++;
	else if (sDirection == DOWN)
		posy[0]--;
	else if (sDirection == RIGHT)
		posx[0]++;
	else if (sDirection == LEFT)
		posx[0]--;


	for (int i = 0; i < snake_length; i++)
	{
		if (i == 0)
			glColor3f(0, 0, 1);
		else
			glColor3f(0, 1, 0);
		glRectd(posx[i], posy[i], posx[i] + 1, posy[i] + 1);
	}
	
	if (posx[0] == 0 || posx[0] == 39 || posy[0] == 0 || posy[0] == 39)
	{
		gameOver = true;
	}
	if (posx[0] == foodx && posy[0] == foody)
	{
		score++;
		snake_length++;
		if (snake_length > MAX)
			snake_length = MAX;
		food = true;
	}

}

void random(int& x, int& y)
{
	int maxX = 38;
	int maxY = 38;
	int min = 1;
	srand(time(NULL));
	//min = rand % (max - min);
	x = min + rand() % (maxX - min);
	y = min + rand() % (maxY - min);
}

