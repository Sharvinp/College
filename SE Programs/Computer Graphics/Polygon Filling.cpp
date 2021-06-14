#include <GL/glut.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int w=640,h=480;
int xi,y2;
float boundaryColor[3]={0.0,1.0,0.0}, interiorColor[3]={1,1,1},
fillColor1[3]={6,0,6.9},fillColor2[3]={3,0,0};
float readPixel[3];

void init()
{
glClearColor(1.0,1.0,1.0,0.0);
glLoadIdentity();
gluOrtho2D(0,640,0,480);
glClear(GL_COLOR_BUFFER_BIT);
}
void setPixel(int x,int y,float fillcolor[]) {
glColor3fv(fillcolor);
glBegin(GL_POINTS);
glVertex2f(x,y);
glEnd();
glFlush();
}

void getPixel(int x, int y, float *color)
{
glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,color);
}
void display()
{
glColor3f(0.0,1.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2i(250,250);
glVertex2i(250,300);
glVertex2i(300,300);
glVertex2i(300,250);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2i(350,250);
glVertex2i(400,250);
glVertex2i(375,320);
glEnd();
glFlush();
}
void floodFill(int x,int y) {
getPixel(x,y,readPixel);
if( readPixel[0]==interiorColor[0] && readPixel[1]==interiorColor[1] &&
readPixel[2]==interiorColor[2] )
{
setPixel(x,y,fillColor1);
floodFill(x+1,y);
floodFill(x,y+1);
floodFill(x-1,y);
floodFill(x,y-1);

glFlush();
}
}
void boundaryFill(int x,int y)
{
getPixel(x,y,readPixel);
if((readPixel[0]!= boundaryColor[0] && readPixel[1]!=boundaryColor[1]
&& readPixel[2]!=boundaryColor[2])||
(readPixel[0]!=fillColor2[0] && readPixel[1]!=fillColor2[1] &&
readPixel[2]!=fillColor2[2]))
{
setPixel (x,y,fillColor2);
boundaryFill(x+1,y);
boundaryFill(x-1,y);
boundaryFill(x,y+1);
boundaryFill(x,y-1);
}
glFlush();
}
void menu(int option)
{
if(option==1){
cout<<"FloodFill"<<endl;
floodFill(xi,y2);
}
if(option==2){
cout<<"BoundaryFill"<<endl;
boundaryFill(xi,y2);
}
if(option==3){
exit(0);
}
}

void mouse(int btn,int state,int x,int y)
{
if((btn==GLUT_LEFT_BUTTON)&&(state==GLUT_DOWN))
{
xi=x;
y2=480-y;
glutCreateMenu(menu);
glutAddMenuEntry("FloodFill",1);
glutAddMenuEntry("BoundaryFill",2);
glutAddMenuEntry("Exit",3);
glutAttachMenu(GLUT_RIGHT_BUTTON);
}
}

int main(int argc,char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(w,h);
glutCreateWindow("Polygon Filling");
glutDisplayFunc(display);
glutMouseFunc(mouse);
init();
glutMainLoop();
return 0;
}
