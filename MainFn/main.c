#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<F:\Semester-wise\6th Semester-2016\Computer Graphics\Lab\MainFn\Shapes.h>
//directory to be changed when used outside my computer

int main()
{
    initwindow(640,640);
    cord();
    //carteCircle(0,0,120);
   // DDALine(11,12,345,234);
    /*int i=0,xc,yc,rx,ry;
    printf("Enter xc: ");
    scanf("%d",&xc);
    printf("Enter yc: ");
    scanf("%d",&yc);
    printf("Enter rx: ");
    scanf("%d",&rx);
    printf("Enter ry: ");
    scanf("%d",&ry);
    for cartesian coordinate
    x1=320+x1;
    y1=320-y1;
    x2=320+x2;
    */
//int i=0;
   //while(i<10)
   //{
     //  bresenLine(10+i,112,340+i,340);
       //i+=5;
   //}
   //midEllipse(xc,yc,rx,ry);
    //paraCircle(12,45,67);
    //midCircle(12,45,67);
   //bresenCircle(12,45,67);
      //paraCircle(12,45,67);
    //carteEllipse(30,60,120,60);
   //paraEllipse(30,60,120,60);*/
   //DDALine(430,310,330,120);
   //midLine(520,330,330,420);
  //bresenLine(420,330,330,520);

  //int x1[4]={12,12,122,122};
  //int y1[4]={12,122,122,12};
  //Rotate(12,122,122,12,0,0,45);
  //polyReflection(4,x1,y1,INFINITY,0);
    //midLine(12,12,12,200);
    //midLine(12,12,200,12);
    //midLine(12,200,200,200);
    //midLine(200,12,200,200);
  //SuderlandAlgo(12,12,200,200,33,33,300,56);
  //polyScale(4,x1,y1,0,0,3,2);
    //th=(th/180)*PI;
    int x1[]={12,12,122,122};
    int y1[]={12,122,122,12};
    Shearing(x1,y1,0,0,2,0);
    delay(10000);
    closegraph();
    return 0;
}
