#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<ctype.h>
#include<../bin/tmpe.c>
void start()
{
  int gd=DETECT,gm,x=0,y=270,i;
  initgraph(&gd,&gm,"../bgi");
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
void reset()
{
  clrscr();
  cleardevice();
  setcolor(WHITE);
  line(160,0,160,400);
  rectangle(0,0,600,400);
}
void main()
{
  FILE *fp;
  FILE *tmpe;
  char name[10];
  int gd=DETECT,gm,x1,y1,x2,y2,maj,min,a,a1;
  start();
  initgraph(&gd,&gm,"../bgi");
  printf("Enter a file name[with .c extension]: ");
  scanf("%s",&name);
  cleardevice();
  fp=fopen(name,"a+");
  tmpe=fopen("../bin/tmpe.c","w");
  fprintf(tmpe,"\nvoid tmpe(); \n void tmpe() \n {");
  fprintf(tmpe,"\n line(160,0,160,400);");
  fprintf(tmpe,"\n rectangle(0,0,600,400);");
  fprintf(fp,"\n #include<stdio.h> \n #include<conio.h> \n #include<graphics.h> \n");
  fprintf(fp,"\n void main() \n {  \n int gd=DETECT,gm; \n ");
  fprintf(fp,"\n initgraph(&gd,&gm,../bgi);");
  up:
  printf("\nType 1 for line");
  printf("\nType 2 for rectangle");
  printf("\nType 3 for circle");
  printf("\nType 4 for ellipse");
  printf("\nType 5 to exit");
  printf("\n6:RED 7:BLUE \n 8:YELLOW 9:WHITE \n");
  line(160,0,160,400);
  rectangle(0,0,600,400);
  top:
  printf("\nEnter your choice[1-5]: ");
  scanf("%d",&a);
  if(a==10)
  {
    reset();
  }
  switch(a)
  {
    case 1:
    {
    printf("Enter start[x,y]: \n");
    scanf("%d%d",&x1,&y1);
    printf("Enter end[x,y]: \n");
    scanf("%d%d",&x2,&y2);
    x1+=165;
    x2+=165;
    line(x1,y1,x2,y2);
    fprintf(tmpe,"\n line(%d,%d,%d,%d); ",x1,y1,x2,y2);
    fprintf(fp,"\n line(%d,%d,%d,%d); ",x1,y1,x2,y2);
    goto top;
    }
    case 2:
    {
    printf("Enter corner1[x,y]: \n");
    scanf("%d%d",&x1,&y1);
    printf("Enter corner2[x,y]: \n");
    scanf("%d%d",&x2,&y2);
    x1+=165;
    x2+=165;
    rectangle(x1,y1,x2,y2);
    fprintf(fp,"\n rectangle(%d,%d,%d,%d); ",x1,y1,x2,y2);
    fprintf(tmpe,"\n rectangle(%d,%d,%d,%d);",x1,y1,x2,y2);
    goto top;
    }
    case 3:
    {
    printf("Enter center[x,y]: ");
    scanf("%d%d",&x1,&y1);
    x1+=165;
    printf("Enter Radius[r]: ");
    scanf("%d",&x2);
    circle(x1,y1,x2);
    fprintf(fp,"\n circle(%d,%d,%d); ",x1,y1,x2);
    fprintf(tmpe,"\n circle(%d,%d,%d); ",x1,y1,x2);
    goto top;
    }
    case 4:
    {
    printf("Enter center[x,y]: ");
    scanf("%d%d",&x1,&y1);
    x1+=165;
    printf("Enter angle[O,Q]: ");
    scanf("%d%d",&x2,&y2);
    printf("Enter major,minor axis[]:");
    scanf("%d%d",&maj,&min);
    ellipse(x1,y1,x2,y2,maj,min);
    fprintf(fp,"\n ellipse(%d,%d,%d,%d,%d,%d); ",x1,y1,x2,y2,maj,min);
    fprintf(tmpe,"\n ellipse(%d,%d,%d,%d,%d,%d); ",x1,y1,x2,y2,maj,min);
    goto top;
    }
    case 5:
    {
    fprintf(fp,"getch(); \n }");
    fprintf(tmpe,"\n }");
    cleardevice();
    fclose(fp);
    fclose(tmpe);
    tmpe=fopen("../bin/tmpe.c","w");
    fprintf(tmpe,"\n void tmpe(); \nvoid tmpe() \n { \n }");
    stop();
    }
    case 6:
    {
    setcolor(RED);
    fprintf(tmpe,"setcolor(RED);");
    fprintf(fp,"setcolor(RED);");
    goto top;
    }
    case 7:
    {
    setcolor(BLUE);
    fprintf(tmpe,"setcolor(BLUE);");
    fprintf(fp,"setcolor(RED);");
    goto top;
    }
    case 8:
    {
    setcolor(YELLOW);
    fprintf(tmpe,"setcolor(YELLOW);");
    fprintf(fp,"setcolor(RED);");
    goto top;
    }
    case 9:
    {
    setcolor(WHITE);
    fprintf(tmpe,"setcolor(WHITE);");
    goto top;
    }
    case 10:
    {
    void tmpe();
    tmpe();
    goto up;
    }
    default:
    {
    printf("\nyou entered an incorrect option");
    goto up;
    }
  }
}
