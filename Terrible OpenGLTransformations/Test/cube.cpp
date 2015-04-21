#include<stdio.h>
#include<stdlib.h>
#include<windows.h>	   
#include<GL/gl.h>	
#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>
#include<math.h>

using namespace std;

#define PI 3.14159265

const int X = 4;
const int Y = 24;
float cube1[X][Y];
float cubeTransform1[X][Y];


void matrixMult(float a[4][4], float b[4][1], float c[4][1])
{
	int x = 4;
	int y = 4;
	int m = 4;
	int n = 1;

	for(int i=0;i<x;i++)
    {
        for(int j=0;j<n;j++)
        {
            c[i][j]=0;
            for(int k=0;k<m;k++)
            {
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
        }
    }
}

void shearEffect(float s)
{
	//x = vertex[0][0], y = vertex[1][0], z = vertex[2][0]
	float vertex[4][1];
	float newVertex[4][1];
	float Shear[X][X];

	for(int i = 0; i<4; i++)
		newVertex[i][0] = 0.0;
	for(int i = 0; i<24; i++)
	{
		//Store Vertex
		vertex[0][0] = cube1[0][i];
		vertex[1][0] = cube1[1][i];
		vertex[2][0] = cube1[2][i];
		vertex[3][0] = cube1[3][i];
		//Create Shear Matrix
		Shear[0][0] = 1.0;
		Shear[0][1] = s*vertex[0][0]*vertex[1][0];
		Shear[0][2] = s*vertex[0][0]*vertex[2][0];
		Shear[0][3] = 0.0;
		Shear[1][0] = s*vertex[1][0]*vertex[0][0];
		Shear[1][1] = 1.0;
		Shear[1][2] = s*vertex[1][0]*vertex[2][0];
		Shear[1][3] = 0.0;
		Shear[2][0] = s*vertex[2][0]*vertex[0][0];
		Shear[2][1] = s*vertex[2][0]*vertex[1][0];
		Shear[2][2] = 1.0;
		Shear[2][3] = 0.0;
		Shear[3][0] = 0.0;
		Shear[3][1] = 0.0;
		Shear[3][2] = 0.0;
		Shear[3][3] = 1.0;
		//Multiply Shear Matrix by Vertex
		matrixMult(Shear, vertex, newVertex);
		cubeTransform1[0][i] = newVertex[0][0];
		cubeTransform1[1][i] = newVertex[1][0];
		cubeTransform1[2][i] = newVertex[2][0];
		cubeTransform1[3][i] = 1.0;
	}
}

void taperEffect()
{
	//For purpose of Testing tapering, just using the function "f(x) = .2x"
	//x = vertex[0][0], y = vertex[1][0], z = vertex[2][0]
	float vertex[4][1];
	float newVertex[4][1];
	float Taper[X][X];
	

	for(int i = 0; i<4; i++)
		newVertex[i][0] = 0.0;
	for(int i = 0; i<24; i++)
	{
		//Store Vertex
		vertex[0][0] = cube1[0][i];
		vertex[1][0] = cube1[1][i];
		vertex[2][0] = cube1[2][i];
		vertex[3][0] = cube1[3][i];
		//Create Shear Matrix
		Taper[0][0] = 1.0;
		Taper[0][1] = 0.0;
		Taper[0][2] = 0.0;
		Taper[0][3] = 0.0;
		Taper[1][0] = 0.0;
		Taper[1][1] = 0.2*vertex[0][0];
		Taper[1][2] = 0.0;
		Taper[1][3] = 0.0;
		Taper[2][0] = 0.0;
		Taper[2][1] = 0.0;
		Taper[2][2] = 0.2*vertex[0][0];
		Taper[2][3] = 0.0;
		Taper[3][0] = 0.0;
		Taper[3][1] = 0.0;
		Taper[3][2] = 0.0;
		Taper[3][3] = 1.0;
		//Multiply Shear Matrix by Vertex
		matrixMult(Taper, vertex, newVertex);
		cubeTransform1[0][i] = newVertex[0][0];
		cubeTransform1[1][i] = newVertex[1][0];
		cubeTransform1[2][i] = newVertex[2][0];
		cubeTransform1[3][i] = 1.0;
	}
}

void twistEffect(float angle)
{
	//x = vertex[0][0], y = vertex[1][0], z = vertex[2][0]
	float vertex[4][1];
	float newVertex[4][1];
	float Twist[X][X];
	

	for(int i = 0; i<4; i++)
		newVertex[i][0] = 0.0;
	for(int i = 0; i<24; i++)
	{
		//Store Vertex
		vertex[0][0] = cube1[0][i];
		vertex[1][0] = cube1[1][i];
		vertex[2][0] = cube1[2][i];
		vertex[3][0] = cube1[3][i];
		//Create Shear Matrix
		Twist[0][0] = vertex[1][0]*cos(angle*PI/180.0);
		Twist[0][1] = 0.0;
		Twist[0][2] = vertex[1][0]*sin(angle*PI/180.0);
		Twist[0][3] = 0.0;
		Twist[1][0] = 0.0;
		Twist[1][1] = 1.0;
		Twist[1][2] = 0.0;
		Twist[1][3] = 0.0;
		Twist[2][0] = vertex[1][0]*(-(sin(angle*PI/180.0)));
		Twist[2][1] = 0.0;
		Twist[2][2] = vertex[1][0]*cos(angle*PI/180.0);
		Twist[2][3] = 0.0;
		Twist[3][0] = 0.0;
		Twist[3][1] = 0.0;
		Twist[3][2] = 0.0;
		Twist[3][3] = 1.0;
		//Multiply Shear Matrix by Vertex
		matrixMult(Twist, vertex, newVertex);
		cubeTransform1[0][i] = newVertex[0][0];
		cubeTransform1[1][i] = newVertex[1][0];
		cubeTransform1[2][i] = newVertex[2][0];
		cubeTransform1[3][i] = 1.0;
	}
}

void bendEffect()
{
	//"f(y) = .23y, g(y) = .27y, h(y) = .30y, k(y) = .33y"
	//x = vertex[0][0], y = vertex[1][0], z = vertex[2][0]
	float vertex[4][1];
	float newVertex[4][1];
	float Bend[X][X];
	

	for(int i = 0; i<4; i++)
		newVertex[i][0] = 0.0;
	for(int i = 0; i<24; i++)
	{
		//Store Vertex
		vertex[0][0] = cube1[0][i];
		vertex[1][0] = cube1[1][i];
		vertex[2][0] = cube1[2][i];
		vertex[3][0] = cube1[3][i];
		//Create Shear Matrix
		Bend[0][0] = 1.0;
		Bend[0][1] = 0.0;
		Bend[0][2] = 0.0;
		Bend[0][3] = 0.0;
		Bend[1][0] = 0.0;
		Bend[1][1] = 0.23*vertex[1][0];
		Bend[1][2] = 0.27*vertex[1][0];
		Bend[1][3] = 0.0;
		Bend[2][0] = 0.0;
		Bend[2][1] = 0.30*vertex[1][0];
		Bend[2][2] = 0.33*vertex[1][0];
		Bend[2][3] = 0.0;
		Bend[3][0] = 0.0;
		Bend[3][1] = 0.0;
		Bend[3][2] = 0.0;
		Bend[3][3] = 1.0;
		//Multiply Shear Matrix by Vertex
		matrixMult(Bend, vertex, newVertex);
		cubeTransform1[0][i] = newVertex[0][0];
		cubeTransform1[1][i] = newVertex[1][0];
		cubeTransform1[2][i] = newVertex[2][0];
		cubeTransform1[3][i] = 1.0;
	}
}

void display(void) {
    glClear (GL_COLOR_BUFFER_BIT);
	//Front
	glBegin(GL_POLYGON);
		glColor3f (1.0, 0.0, 0.0);
		glVertex3f (cube1[0][0], cube1[1][0], cube1[2][0]); //BL
        glVertex3f (cube1[0][1], cube1[1][1], cube1[2][1]); //BR
        glVertex3f (cube1[0][2], cube1[1][2], cube1[2][2]); //TR
        glVertex3f (cube1[0][3], cube1[1][3], cube1[2][3]); //TL
	glEnd();
	//Right
	glBegin(GL_POLYGON);
		glColor3f (0.0, 1.0, 0.0);
		glVertex3f (cube1[0][4], cube1[1][4], cube1[2][4]); 
        glVertex3f (cube1[0][5], cube1[1][5], cube1[2][5]); 
        glVertex3f (cube1[0][6], cube1[1][6], cube1[2][6]); 
        glVertex3f (cube1[0][7], cube1[1][7], cube1[2][7]); 
	glEnd();
	//Left
	glBegin(GL_POLYGON);
		glColor3f (0.0, 0.0, 1.0);
		glVertex3f (cube1[0][8], cube1[1][8], cube1[2][8]); 
        glVertex3f (cube1[0][9], cube1[1][9], cube1[2][9]); 
        glVertex3f (cube1[0][10], cube1[1][10], cube1[2][10]); 
        glVertex3f (cube1[0][11], cube1[1][11], cube1[2][11]); 
	glEnd();
	//Top
	glBegin(GL_POLYGON);
		glColor3f (1.0, 1.0, 0.0);
		glVertex3f (cube1[0][12], cube1[1][12], cube1[2][12]); 
        glVertex3f (cube1[0][13], cube1[1][13], cube1[2][13]); 
        glVertex3f (cube1[0][14], cube1[1][14], cube1[2][14]); 
        glVertex3f (cube1[0][15], cube1[1][15], cube1[2][15]); 
	glEnd();
	//Bottom
	glBegin(GL_POLYGON);
		glColor3f (1.0, 0.0, 1.0);
		glVertex3f (cube1[0][16], cube1[1][16], cube1[2][16]); 
        glVertex3f (cube1[0][17], cube1[1][17], cube1[2][17]); 
        glVertex3f (cube1[0][18], cube1[1][18], cube1[2][18]); 
        glVertex3f (cube1[0][19], cube1[1][19], cube1[2][19]); 
	glEnd();
	//Back
	glBegin(GL_POLYGON);
		glColor3f (0.0, 1.0, 1.0);
		glVertex3f (cube1[0][20], cube1[1][20], cube1[2][20]); 
        glVertex3f (cube1[0][21], cube1[1][21], cube1[2][21]); 
        glVertex3f (cube1[0][22], cube1[1][22], cube1[2][22]); 
        glVertex3f (cube1[0][23], cube1[1][23], cube1[2][23]); 
	glEnd();
    glFlush ();
}

void displayTransform(void) {
    glClear (GL_COLOR_BUFFER_BIT);
	//Front
	glBegin(GL_POLYGON);
		glColor3f (1.0, 0.0, 0.0);
		glVertex3f (cubeTransform1[0][0], cubeTransform1[1][0], cubeTransform1[2][0]); //BL
        glVertex3f (cubeTransform1[0][1], cubeTransform1[1][1], cubeTransform1[2][1]); //BR
        glVertex3f (cubeTransform1[0][2], cubeTransform1[1][2], cubeTransform1[2][2]); //TR
        glVertex3f (cubeTransform1[0][3], cubeTransform1[1][3], cubeTransform1[2][3]); //TL
	glEnd();
	//Right
	glBegin(GL_POLYGON);
		glColor3f (0.0, 1.0, 0.0);
		glVertex3f (cubeTransform1[0][4], cubeTransform1[1][4], cubeTransform1[2][4]); 
        glVertex3f (cubeTransform1[0][5], cubeTransform1[1][5], cubeTransform1[2][5]); 
        glVertex3f (cubeTransform1[0][6], cubeTransform1[1][6], cubeTransform1[2][6]); 
        glVertex3f (cubeTransform1[0][7], cubeTransform1[1][7], cubeTransform1[2][7]); 
	glEnd();
	//Left
	glBegin(GL_POLYGON);
		glColor3f (0.0, 0.0, 1.0);
		glVertex3f (cubeTransform1[0][8], cubeTransform1[1][8], cubeTransform1[2][8]); 
        glVertex3f (cubeTransform1[0][9], cubeTransform1[1][9], cubeTransform1[2][9]); 
        glVertex3f (cubeTransform1[0][10], cubeTransform1[1][10], cubeTransform1[2][10]); 
        glVertex3f (cubeTransform1[0][11], cubeTransform1[1][11], cubeTransform1[2][11]); 
	glEnd();
	//Top
	glBegin(GL_POLYGON);
		glColor3f (1.0, 1.0, 0.0);
		glVertex3f (cubeTransform1[0][12], cubeTransform1[1][12], cubeTransform1[2][12]); 
        glVertex3f (cubeTransform1[0][13], cubeTransform1[1][13], cubeTransform1[2][13]); 
        glVertex3f (cubeTransform1[0][14], cubeTransform1[1][14], cubeTransform1[2][14]); 
        glVertex3f (cubeTransform1[0][15], cubeTransform1[1][15], cubeTransform1[2][15]); 
	glEnd();
	//Bottom
	glBegin(GL_POLYGON);
		glColor3f (1.0, 0.0, 1.0);
		glVertex3f (cubeTransform1[0][16], cubeTransform1[1][16], cubeTransform1[2][16]); 
        glVertex3f (cubeTransform1[0][17], cubeTransform1[1][17], cubeTransform1[2][17]); 
        glVertex3f (cubeTransform1[0][18], cubeTransform1[1][18], cubeTransform1[2][18]); 
        glVertex3f (cubeTransform1[0][19], cubeTransform1[1][19], cubeTransform1[2][19]); 
	glEnd();
	//Back
	glBegin(GL_POLYGON);
		glColor3f (0.0, 1.0, 1.0);
		glVertex3f (cubeTransform1[0][20], cubeTransform1[1][20], cubeTransform1[2][20]); 
        glVertex3f (cubeTransform1[0][21], cubeTransform1[1][21], cubeTransform1[2][21]); 
        glVertex3f (cubeTransform1[0][22], cubeTransform1[1][22], cubeTransform1[2][22]); 
        glVertex3f (cubeTransform1[0][23], cubeTransform1[1][23], cubeTransform1[2][23]); 
	glEnd();
    glFlush ();
}

void init(void) 
{
    glClearColor (0.0, 0.0, 0.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(0.0, 4.0, 0.0, 4.0, 2.0, -2.0);
	glOrtho(0.0, 5.0, 0.0, 5.0, 2.0, -2.0);
}


int main(int argc, char** argv)
{
	/*Cube1*/
	for(int i = 0; i<24; i++)
	{
		cube1[3][i] = 1.0;
	}
	//front
	cube1[0][0] = 1.0;
	cube1[1][0] = 1.0;
	cube1[2][0] = 1.0;

	cube1[0][1] = 3.0;
	cube1[1][1] = 1.0;
	cube1[2][1] = 1.0;

	cube1[0][2] = 3.0;
	cube1[1][2] = 3.0;
	cube1[2][2] = 1.0;

	cube1[0][3] = 1.0;
	cube1[1][3] = 3.0;
	cube1[2][3] = 1.0;

	//Right
	cube1[0][4] = 3.0;
	cube1[1][4] = 1.0;
	cube1[2][4] = 1.0;

	cube1[0][5] = 3.0;
	cube1[1][5] = 1.0;
	cube1[2][5] = -1.0;

	cube1[0][6] = 3.0;
	cube1[1][6] = 3.0;
	cube1[2][6] = -1.0;

	cube1[0][7] = 3.0;
	cube1[1][7] = 3.0;
	cube1[2][7] = 1.0;

	//Left
	cube1[0][8] = 1.0;
	cube1[1][8] = 1.0;
	cube1[2][8] = 1.0;

	cube1[0][9] = 1.0;
	cube1[1][9] = 1.0;
	cube1[2][9] = -1.0;

	cube1[0][10] = 1.0;
	cube1[1][10] = 3.0;
	cube1[2][10] = -1.0;

	cube1[0][11] = 1.0;
	cube1[1][11] = 3.0;
	cube1[2][11] = 1.0;

	//Top
	cube1[0][12] = 1.0;
	cube1[1][12] = 3.0;
	cube1[2][12] = 1.0;

	cube1[0][13] = 3.0;
	cube1[1][13] = 3.0;
	cube1[2][13] = 1.0;

	cube1[0][14] = 3.0;
	cube1[1][14] = 3.0;
	cube1[2][14] = -1.0;

	cube1[0][15] = 1.0;
	cube1[1][15] = 3.0;
	cube1[2][15] = -1.0;

	//Bottom
	cube1[0][16] = 1.0;
	cube1[1][16] = 1.0;
	cube1[2][16] = 1.0;

	cube1[0][17] = 3.0;
	cube1[1][17] = 1.0;
	cube1[2][17] = 1.0;

	cube1[0][18] = 3.0;
	cube1[1][18] = 1.0;
	cube1[2][18] = -1.0;

	cube1[0][19] = 1.0;
	cube1[1][19] = 1.0;
	cube1[2][19] = -1.0;

	//Back
	cube1[0][20] = 1.0;
	cube1[1][20] = 1.0;
	cube1[2][20] = 1.0;

	cube1[0][21] = 3.0;
	cube1[1][21] = 1.0;
	cube1[2][21] = 1.0;

	cube1[0][22] = 3.0;
	cube1[1][22] = 1.0;
	cube1[2][22] = -1.0;

	cube1[0][23] = 1.0;
	cube1[1][23] = 1.0;
	cube1[2][23] = -1.0;

	int selection;

	cout << "1. No transformation cube" << endl;
	cout << "2. Sheared cube" << endl;
	cout << "3. Tapered cube" << endl;
	cout << "4. Twisted cube" << endl;
	cout << "5. Bent cube" << endl;
	cout << "Select tansformation (1,2,3,4,5):" << endl;
	cin >> selection;

	if(selection == 1)
	{
		glutInit(&argc, argv);
		glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize (250, 250); 
		glutInitWindowPosition (100, 100);
		glutCreateWindow ("Cube");
		init();
		glutDisplayFunc(display); 
		glutMainLoop();
	}
	if(selection == 2)
	{
		shearEffect(0.2);
		glutInit(&argc, argv);
		glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize (250, 250); 
		glutInitWindowPosition (100, 100);
		glutCreateWindow ("Cube");
		init();
		glutDisplayFunc(displayTransform); 
		glutMainLoop();
	}
	if(selection == 3)
	{
		taperEffect();
		glutInit(&argc, argv);
		glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize (250, 250); 
		glutInitWindowPosition (100, 100);
		glutCreateWindow ("Cube");
		init();
		glutDisplayFunc(displayTransform); 
		glutMainLoop();
	}
	if(selection == 4)
	{
		twistEffect(45.0);
		glutInit(&argc, argv);
		glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize (250, 250); 
		glutInitWindowPosition (100, 100);
		glutCreateWindow ("Cube");
		init();
		glutDisplayFunc(displayTransform); 
		glutMainLoop();
	}
	if(selection == 5)
	{
		bendEffect();
		glutInit(&argc, argv);
		glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize (250, 250); 
		glutInitWindowPosition (100, 100);
		glutCreateWindow ("Cube");
		init();
		glutDisplayFunc(displayTransform); 
		glutMainLoop();
	}
	
	system("pause");
	return 0;
}