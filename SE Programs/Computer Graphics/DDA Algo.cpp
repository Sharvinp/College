#include<windows.h>
#include<GL/glut.h>
#include<iostream>
#include<cmath>
using namespace std;
float x1,x2;
float Y1,y2;
void myInit()
{
glClearColor(0.0,0.0,.0,0.0);
glColor3f(1.0,1.0,1.0);
glPointSize(4.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,100.0,0.0,100.0);
}
void DDA()
{
float x,y,dx,dy,L ; // L = length
int i ;
if(abs(x2-x1)>abs(y2-Y1))
L=abs(x2-x1);
else
L=abs(y2-Y1);
dx=(x2-x1)/L ;
dy=(y2-Y1)/L ;
x=x1;
y=Y1;
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
while(i<=L)
{
x=x+dx;
y=y+dy;
glBegin(GL_POINTS);

glVertex2i(x,y);
glEnd();
i = i+1;
}
glFlush();
}
int main (int argc,char**argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGB);
cout<<"ENTER x1 : "<<flush;
cin>>x1;
cout<<"ENTER x2 : "<<flush;
cin>>x2;
cout<<"ENTER y1 : "<<flush;
cin>>Y1;
cout<<"ENTER y2 : "<<flush;
cin>>y2;
glutInitWindowSize(500,500);
glutInitWindowPosition(100,100);
glutCreateWindow("DDA ALGORITHM");
glutDisplayFunc(DDA);
myInit();
glutMainLoop();
return 0;
}
