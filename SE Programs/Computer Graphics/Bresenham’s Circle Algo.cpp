#include <iostream>
#include <math.h>
#include <GL/glut.h>
#define w 500
#define b 500
using namespace std;
GLint h, k, r;
void myInit()
{
glClearColor(0.0,0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-w/2,w/2,-b/2,b/2);
}
void setpixel(GLint x, GLint y)
{
glColor3f(1.0f, 0.0f, 0.0f);
glPointSize(3.0);
glBegin(GL_POINTS);
glVertex2f(x,y);
glEnd();
glFlush();
}
void display(int x, int y)
{
setpixel(h+x, k+y);
setpixel(h+x, k-y);
setpixel(h-x, k+y);
setpixel(h-x, k-y);
setpixel(h+y, k+x);
setpixel(h+y, k-x);
setpixel(h-y, k+x);
setpixel(h-y, k-x);
}
void bresenham_algo()
{
float dp;
int x,y;
x=0;
y=r;
dp=3-2*r;
glBegin(GL_LINES);

glVertex2i(h,k);
glVertex2i(h,r+k);
glEnd();
setpixel(h,k);
while(x<=y)
{
if(dp<=0)
{
dp=dp+(4*x)+6;
}
else
{
dp=dp+4*(x-y)+10;
y--;
}
x++;
display(x,y);
}
}
void cir(void)
{
int i;
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);
glPointSize(4.0);
for(i=-w; i<=w; i+=2)
{
setpixel(i,0);
setpixel(0,i);
}
}
void myMouse(int button, int state, int x, int y)
{
int x1, y1, p, q;
if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
{
x1=x-250;
y1=250-y;
p=h-x1;
q=k-y1;
r=sqrt(p*p+q*q);
cout<<"\n\nBresenham's Circle Drawing Algorithm: "<<endl;
cout<<"x = "<<x1<<endl;
cout<<"y = "<<y1<<endl;
cout<<"radius = "<<r;
glBegin(GL_POINTS);
glVertex2i(x1,y1);
glEnd();
}
}
void menu(int item)

{
if(item==1)
{
bresenham_algo();
}
if(item==2)
{
bresenham_algo();
r = r/2;
bresenham_algo();
}
if(item==3)
{
exit(0);
}
}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(w,b);
glutCreateWindow("Bresenham's Circle Algorithm");
glutDisplayFunc(cir);
myInit();
glutMouseFunc(myMouse);
glutCreateMenu(menu);
glutAddMenuEntry("Single Circle", 1);
glutAddMenuEntry("Concentric circles", 2);
glutAddMenuEntry("Exit", 3);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutMainLoop();
return 0;
}
