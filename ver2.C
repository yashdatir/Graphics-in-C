#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
union REGS i,o;
void show_mouse()
{
	i.x.ax=1;
	int86(0x33,&i,&o);
}
void get_mouse_pos(int *x,int *y,int *button)
{
	i.x.ax=3;
	int86(0x33,&i,&o);
	*x=o.x.cx;
	*y=o.x.dx;
	*button=o.x.bx&1;
}
void start()
{
  int gd=DETECT,gm,x=0,y=270,i;
  initgraph(&gd,&gm,"../bgi");
  settextstyle(0,0,0);
  cleardevice();
  printf("\nMade by : Yash Ajay Datir");
}
void stop()
{
  int gd=DETECT,gm,x1=150,y1=200,x2=450,y2=200,i;
  initgraph(&gd,&gm,"../bgi");
  settextstyle(5,0,2);
  outtextxy(250,100,"by Yash Datir");
  for(i=0;i<50;i++)
  {
    line(x1,y1,x2,y2);
    x1+=50;
    x2-=50;
    y1+=10;
    y2-=10;
    delay(100);
  }
  getch();
  exit(0);
}
void main()
{
FILE *fp;
int gd=DETECT,gm,x,y,b,x1[3],y1[3],i,ch,j[4],r;
char name[10];
initgraph(&gd,&gm,"../bgi");
start();
settextstyle(0,0,0);
cleardevice();
printf("Enter a file name[filename.c]: ");
scanf("%s",&name);
fp=fopen(name,"a+");
fprintf(fp,"#include<stdio.h>\n#include<conio.h>\n#include<graphics.h>\n");
fprintf(fp,"void main()\n{\n");
fprintf(fp,"int gd=DETECT,gm;\ninitgraph(&gd,&gm,");
fprintf(fp,"%c",34);
fprintf(fp,"../bgi");
fprintf(fp,"%c",34);
fprintf(fp,");\n");
show_mouse();
bar(0,0,600,25);
setcolor(BLUE);
outtextxy(25,10,"Simple Line");
outtextxy(175,10,"Quadrilateral");
outtextxy(350,10,"Circle");
outtextxy(500,10,"Ellipse");
bar(125,27,600,350);
bar(0,355,600,400);
printf("\n\nScripts;\n");
setcolor(BLACK);
rectangle(90,360,190,390);
rectangle(290,360,390,390);
rectangle(490,360,590,390);
outtextxy(100,375,"Save");
outtextxy(300,375,"Exit");
outtextxy(500,375,"3D figure");
rectangle(0,0,150,25);
rectangle(150,0,300,25);
rectangle(300,0,450,25);
rectangle(450,0,600,25);
setfillstyle(SOLID_FILL,RED);
bar(0,355,10,390);
setfillstyle(SOLID_FILL,BLUE);
bar(10,355,20,390);
setfillstyle(SOLID_FILL,YELLOW);
bar(20,355,30,390);
setfillstyle(SOLID_FILL,GREEN);
bar(30,355,40,390);
rectangle(40,355,50,390);
while(!kbhit())
{
get_mouse_pos(&x,&y,&b);
if(x>0&&x<10&&y>355&&b==1)
{
  fprintf(fp,"setcolor(RED); \n setfillstyle(SOLID_FILL,RED); \n");
  setcolor(RED);
  setfillstyle(SOLID_FILL,RED);
  delay(100);
}
if(x>10&&x<20&&y>355&&b==1)
{
  fprintf(fp,"setcolor(BLUE); \n setfillstyle(SOLID_FILL,BLUE); \n");
  setcolor(BLUE);
  setfillstyle(SOLID_FILL,BLUE);
  delay(100);
}
if(x>20&&x<30&&y>355&&b==1)
{
  fprintf(fp,"setcolor(YELLOW); \n setfillstyle(SOLID_FILL,YELLOW); \n");
  setcolor(YELLOW);
  setfillstyle(SOLID_FILL,YELLOW);
  delay(100);
}
if(x>30&&x<40&&y>355&&b==1)
{
  fprintf(fp,"setcolor(GREEN); \n setfillstyle(SOLID_FILL,GREEN); \n");
  setcolor(GREEN);
  setfillstyle(SOLID_FILL,GREEN);
  delay(100);
}
if(x>40&&x<50&&y>355&&b==1)
{
  fprintf(fp,"setcolor(WHITE); \n setfillstyle(SOLID_FILL,WHITE); \n");
  setcolor(WHITE);
  setfillstyle(SOLID_FILL,WHITE);
}
if(x>225&&x<325&&y>360&&b==1)
{
  fprintf(fp,"getch();\n}");
  fclose(fp);
  stop();
  exit(0);
}
if(x>=0&&x<=150&&y<=25&&b==1)
{
  delay(200);
  ch=1;
}
if(x>150&&x<=300&&y<=25&&b==1)
{
  delay(200);
  ch=2;
}
if(x>300&&x<450&&y<=25&&b==1)
{
  delay(100);
  ch=3;
}
if(x>450&&x<600&&y<=25&&b==1)
{
  delay(100);
  ch=4;
}
if(x>490&&x<590&&y>360&&b==1)
{
  delay(200);
  ch=5;
}
switch(ch)
{
case 1:
{
  get_mouse_pos(&x,&y,&b);
  if(b==1)
  {
    for(i=0;i<2;i++)
    {
      up:
      get_mouse_pos(&x,&y,&b);
      if(b==1)
      {
      x1[i]=x;
      y1[i]=y;
      delay(500);
      }else
      {
	goto up;
      }
    }
    fprintf(fp,"line(%d,%d,%d,%d);\n",x1[0],y1[0],x1[1],y1[1]);
    line(x1[0],y1[0],x1[1],y1[1]);
  }
}
break;
case 2:
{
  get_mouse_pos(&x,&y,&b);
  if(b==1)
  {
    for(i=0;i<2;i++)
    {
      upR:
      get_mouse_pos(&x,&y,&b);
      if(b==1)
      {
      x1[i]=x;
      y1[i]=y;
      delay(500);
      }else
      {
	goto upR;
      }
    }
    fprintf(fp,"rectangle(%d,%d,%d,%d);\n",x1[0],y1[0],x1[1],y1[1]);
    rectangle(x1[0],y1[0],x1[1],y1[1]);
  }
}
break;
case 3:
printf("Enter Radius: ");
scanf("%d",&r);
upC:
get_mouse_pos(&x,&y,&b);
{if(b==1)
{
  x1[0]=x;
  y1[0]=y;
}
else{
goto upC;} }
delay(500);
fprintf(fp,"circle(%d,%d,%d);\n",x1[0],y1[0],r);
circle(x1[0],y1[0],r);
ch=0;
break;
case 4:
printf("Angle[o,p]:\n");
scanf("%d%d",&j[0],&j[1]);
printf("Arc[maj|min]\n");
scanf("%d%d",&j[2],&j[3]);
upE:
get_mouse_pos(&x,&y,&b);
{if(b==1)
{
  x1[0]=x;
  y1[0]=y;
}
else{
goto upE;} }
delay(500);
fprintf(fp,"ellipse(%d,%d,%d,%d,%d,%d);\n",x1[0],y1[0],j[1],j[1],j[1],j[1]);
ellipse(x1[0],y1[0],j[0],j[1],j[2],j[3]);
ch=0;
break;
case 5:
{
  get_mouse_pos(&x,&y,&b);
  if(b==1)
  {
    for(i=0;i<2;i++)
    {
      upB:
      get_mouse_pos(&x,&y,&b);
      if(b==1)
      {
      x1[i]=x;
      y1[i]=y;
      delay(500);
      }else
      {
	goto upB;
      }
    }
    printf("Enter depth: ");
    scanf("%d",&r);
    fprintf(fp,"bar3d(%d,%d,%d,%d,%d,1);\n",x1[0],y1[0],x1[1],y1[1],r);
    bar3d(x1[0],y1[0],x1[1],y1[1],r,1);
  }
}
break;
default:
break;
}
}
fprintf(fp,"getch();\n}");
stop();
getch();
}
