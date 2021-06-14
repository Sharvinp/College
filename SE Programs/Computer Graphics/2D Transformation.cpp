#include<GL/glut.h>
#include <iostream>
#include <math.h>
#define w 500
#define h 500
using namespace std;
void setpixel(GLint x, GLint y)
{
glColor3f(1.0,1.0,1.0);
glPointSize(2.0);
glBegin(GL_POINTS);
glVertex2f(x,y);
glEnd();
glFlush();
}
float mati[30][2], mato[30][2];
int k=0, c;
class trans
{
int transl[2][2];
public:
void mul(float s[2][2])
{
int i,j,k;
float sum;
for(i=0; i<c; i++)
{
for(j=0; j<2; j++)
{
sum=0;
for(k=0; k<2; k++)
{
sum = sum + mati[i][k]*s[k][j];
}
mato[i][j] = sum;
}
}
}
void plot(float m[][2])
{
glColor3f(0.0,1.0,0.0);
glBegin(GL_LINE_LOOP);

for(int i=0; i<c; i++)
{
glVertex2f(m[i][0], m[i][1]);
}
glEnd();
glFlush();
}
void translation(float tx, float ty)
{
for(int i=0; i<c; i++)
{
mato[i][0] = mati[i][0] + tx;
mato[i][1] = mati[i][1] + ty;
}
}
void scaling()
{
float scale[2][2];
int i;
float sx, sy;
cout<<"\nEnter sx Factor: ";
cin>>sx;
cout<<"\nEnter sy Factor: ";
cin>>sy;
scale[0][0] = sx;
scale[0][1] = 0;
scale[1][0] = 0;
scale[1][1] = sy;
mul(scale);
plot(mato);
}
void rotation()
{
int rot;
float angle, rota[2][2];
cout<<"\nEnter Angle: ";
cin>>angle;
angle = (3.14*angle)/180;
cout<<"\n1)Clockwise rotation \n2)Anticlockwise Rotation \nEnter your choice: ";
cin>>rot;
switch(rot)
{
case 1:
rota[0][0] = cos(angle);
rota[0][1] = -sin(angle);
rota[1][0] = sin(angle);
rota[1][1] = cos(angle);
break;

case 2:
rota[0][0] = cos(angle);
rota[0][1] = sin(angle);
rota[1][0] = -sin(angle);
rota[1][1] = cos(angle);
break;
default:
cout<<"\nWrong choice";
exit(0);
}
mul(rota);
}
void rot_arbit()
{
float xm, ym;
int i, j;
cout<<"\nEnter Co-ordinates of the arbitrary point: ";
cout<<"\nX Co-ordinate: ";
cin>>xm;
cout<<"\nY Co-ordinate: ";
cin>>ym;
translation(-xm, -ym);
for(i=0; i<c; i++)
{
for(j=0; j<2; j++)
{
mati[i][j] = mato[i][j];
}
}
rotation();
for(i=0; i<c; i++)
{
for(j=0; j<2; j++)
{
mati[i][j] = mato[i][j];
}
}
translation(xm, ym);
plot(mato);
}
};
void choice(void)
{
int i, ch;
glColor3f(1.0,1.0,1.0);
glPointSize(4.0);
for(i=-w; i<=w; i+=2)
{

setpixel(i,0);
setpixel(0,i);
}
glFlush();
}
void init()
{
glClearColor(0.0,0.0,0.0,1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-w/2,w/2,-h/2,h/2);
}
void menu(int item)
{
trans t;
float tx, ty;
cout<<"\nYou have selected item number: "<<item;
if(item==1)
{
cout<<"\nEnter tx factor: ";
cin>>tx;
cout<<"\nEnter ty factor: ";
cin>>ty;
t.translation(tx,ty);
t.plot(mato);
glClear(GL_COLOR_BUFFER_BIT);
}
if(item==2)
{
t.scaling();
glClear(GL_COLOR_BUFFER_BIT);
}
if(item==3)
{
t.rotation();
t.plot(mato);
glClear(GL_COLOR_BUFFER_BIT);
}
if(item==4)
{
t.rot_arbit();
}
if(item==5)
{
exit(0);
}

}
void MouseClick(int button, int state, int x, int y)
{
int x1, y1, p, q;
if(state == GLUT_DOWN)
{
if(button == GLUT_LEFT_BUTTON)
{
mati[k][0] = (float)(x-250);
mati[k][1] = (float)(250-y);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POINTS);
glVertex2f(mati[k][0],mati[k][1]);
glEnd();
k++;
glFlush();
}
if(button == GLUT_RIGHT_BUTTON)
{
glBegin(GL_LINE_LOOP);
int i;
for(i=0; i<k; i++)
{
glVertex2f(mati[i][0],mati[i][1]);
}
glEnd();
c = k;
k = 0;
glFlush();
}
}
}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(w,h);
glutCreateWindow("2D Transformation");
glutDisplayFunc(choice);
init();
glutMouseFunc(MouseClick);
glutCreateMenu(menu);
glutAddMenuEntry("Translation", 1);
glutAddMenuEntry("Scaling", 2);
glutAddMenuEntry("Rotation", 3);
glutAddMenuEntry("Rotation about arbitrary point", 4);
glutAddMenuEntry("Exit", 5);
glutAttachMenu(GLUT_MIDDLE_BUTTON);
glutMainLoop();
return 0;

}
