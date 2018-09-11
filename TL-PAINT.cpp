// REQUIRED HEADER FILES
#include<iostream.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<process.h>
#include<fstream.h>
#include<stdio.h>

union REGS in,out;	// STRUCTURES FOR MOUSE

int alpha,color;
int colorselect(); // FUNCTION DECLARATIONS
void shapeselect();
void startpaint();
void cleardev();
void menu();
void help();
void endofp();
///////////////////FUNCTIONS FOR MAIN MENU AND MOUSE /////////////////////////
 	                /// FUNCTION TO SHOW TO MOUSE ///
class flow
{
 		public:
 		void algo()
 			{
 				char c1=getche();
 				if(c1=='h') help();
 				if(c1=='w') colorselect();
 				if(c1=='c') cleardev();
if(c1=='a') shapeselect();
 				if(c1=='s') startpaint();
 				if(c1=='q') endofp();
 			}
};

void callmouse()
 {
 	in.x.ax=1;
 	int86(51,&in,&out);
 }
  	/// FUNCTION FOR MOUSE CURSOR///
void mouseposi(int &xpos,int &ypos,int &click)
 {
  	in.x.ax=3;
  	int86(51,&in,&out);
  	click=out.x.bx;   // TO USE THE CLICKING BUTTONS
  	xpos=out.x.cx;	// FOR GETTING MOUSE POSITION
  	ypos=out.x.dx;
 }
  	             /// FUNCTION FOR REMOVING MOUSE ON SCREEN ///
void hidemouse()
 {
 	in.x.ax=2;
 	int86(51,&in,&out);
 }
  	                               /// FUNCTION FOR CREDITS PAGE ///
void credits ()
{
 cleardevice();    	// TO CLEAR THE SCREEN
     	// TO DISPLAY THE CREDITS SCENE
 	settextstyle(3,HORIZ_DIR,3);
 	setcolor(WHITE);
 	outtextxy(60,20,"MADE BY:-");
 	settextstyle(3,HORIZ_DIR,6);
 	setcolor(LIGHTMAGENTA);
 	outtextxy(250,150,"UDAY NEGI");
settextstyle(3,HORIZ_DIR,5);
 	setcolor(YELLOW);
 	outtextxy(300,250,"AND");
 	settextstyle(3,HORIZ_DIR,6);
 	setcolor(LIGHTGREEN);
 	outtextxy(200,350,"PULKIT ARYA");
 	settextstyle(3,HORIZ_DIR,3);
 	setcolor(WHITE);
 	outtextxy(120,460,"COPYRIGHT @2017");
 	char c = getche();
 	if ( c == 'm' ||  'M' ) menu();  // TO RETURN TO MENU
 	if ( c == 'q' ||  'Q' ) endofp(); // TO EXIT
}
void cleardev()
{
 	char ans;
 	cleardevice();
 	settextstyle(2,0,5);
 	outtextxy(250,220,"DO YOU WANT TO SEE HELP MENU ? (Y/N)");
 	cin>>ans;
 	if( ans == 'Y'|| 'y')
  	{
  		cleardevice();
 		outtextxy(110,40,"1 FOR SQUARE");
  		outtextxy(110,60,"2 FOR RECTANGLE");
  		outtextxy(110,80,"3 FOR PENCIL");
  		outtextxy(110,100," 4 FOR CIRCLE");
  		outtextxy(100,120,"Q TO EXIT");
  		outtextxy(100,140,"C FOR CLEARSCREEN");
  		outtextxy(110,160,"M TO GO BACK TO MENU");
  		outtextxy(250,40,"COLORS :");
  		outtextxy(250,60,"1.BLUE");
  		outtextxy(250,80,"2.GREEN");
  		outtextxy(250,100,"3.RED");
 		outtextxy(250,120,"4.BROWN");
  		outtextxy(250,140,"5.YELLOW");
  		outtextxy(250,160,"6.WHITE");
      }
 else
  	{
   		cleardevice();
  	}
  		colorselect();
  		shapeselect();
 }


void help()
 	{
 	 	cleardevice();
  		settextstyle(2,0,5);
  		outtextxy(100,20,"THIS IS PAINT");
  		outtextxy(110,40,"PRESS 1 FOR SQUARE");
  		outtextxy(110,60,"PRESS 2 FOR RECTANGLE");
  		outtextxy(110,80,"PRESS 3 FOR PENCIL");
  		outtextxy(110,100,"PRESS 4 FOR CIRCLE");
  		outtextxy(100,120,"PRESS Q TO EXIT");
  		outtextxy(100,140,"PRESS C FOR CLEARSCREEN");
  		outtextxy(110,160,"PRESS M TO GO BACK TO MENU");
  		outtextxy(100,180,"COLORS :");
  		outtextxy(100,200,"1.BLUE");
  		outtextxy(100,220,"2.GREEN");
  		outtextxy(100,240,"3.RED");
  		outtextxy(100,260,"4.BROWN");
  		outtextxy(100,280,"5.YELLOW");
  		outtextxy(100,300,"6.WHITE");
  		char c = getche();
 		if ( c == 'm' ||  'M' ) menu();  // TO RETURN TO MENU
  		if ( c == 'q' ||  'Q' ) endofp(); // TO EXIT
 	}
                                        /// FUNCTION FOR MENU ///
void menu()
{
 		cleardevice();                       	// TO CLEAR THE SCREEN
 		settextjustify(CENTER_TEXT, CENTER_TEXT);// TO SHOW THE TEXT IN THE CENTER
 		settextstyle(TRIPLEX_FONT, HORIZ_DIR,5); //FOR FONT,DIRECTION OF FONT AND SIZE OF FONT
 		setcolor(BLUE);                      	// TO USE COLOURS
 		outtextxy(210,50,"P");               	//DISPLAYING THE NAME OF THE PROJECT
 		setcolor(RED) ;
 		outtextxy(250,50,"A");
 		setcolor(GREEN)   ;
 		outtextxy(290,50,"I");
 		setcolor(RED) 	;
 		outtextxy(320,50,"N");
 		setcolor(BLUE)  ;
 		outtextxy(360,50,"T");
 		settextstyle(TRIPLEX_FONT, HORIZ_DIR,2);
 		setcolor(WHITE);
 		outtextxy(260,150,"PRESS");
 		settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
 		setcolor(RED);
 		outtextxy(210,200,"1=>TO PAINT"); // GIVING THE OPTIONS
 		settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
 		setcolor(YELLOW);
 		outtextxy(210,250,"2=>HELP");
 	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
 		setcolor(LIGHTGREEN);
 		outtextxy(210,300,"3=>CREDITS");
 		delay(100);
 		setcolor(WHITE);
 		char c=getche();// GETTING THE OPTIONS
 if(c=='1')
 	{
 		cleardevice();
 		startpaint();
 	}
 if(c=='2') help();
 if(c=='3') credits();
 if(c=='q' || 'Q' ) endofp();
 }
///////////////////////////////FUNCTIONS FOR SHAPES AND COLOURS///////////////////////////
flow r;
void shape()
 {
  	int x1=100,y1=100,x2,y2,cl;
  	setcolor(color);
  	mouseposi(x1,y1,cl);
  	while(!kbhit())
 	{
  		callmouse();
  		mouseposi(x1,y1,cl);
  		x2=x1;
  		y2=y1;
  		while(cl==1)
  		{
   			hidemouse();
   			line(x1,y1,x2,y2) ;
 			 x1=x2;
  			 y1=y2;
   			mouseposi(x2,y2,cl);
  	}
 }
 r.algo();
}
                                        /// FUNCTION FOR SQUARE///
void square()
 	{
  		int a=100,b=400,cl,x1=0,y1=0,x2,y2,i=0;
  		setcolor(color);
  		callmouse();
  		mouseposi(a,b,cl);
  		setfillstyle(1,color);
   		while(!kbhit())
   		{
  			callmouse();
  			mouseposi(x1,y1,cl);
  			x2=x1;
  			y2=y1;
  				while(cl==1)
   				{
 					hidemouse();
 					rectangle(x1,y1,x1+10+i,y1+10+i);
 					floodfill(x1+5,y1+5,color);
 		x1=x2;
 					y1=y2;
 					mouseposi(x2,y2,cl);
   				}
   		}
   r.algo();
}

	             
                                                    ///FUNCTION FOR RECTANGLE//
void rectangle()
 {
  	int a=100,b=400,cl,x1,y1,x2,y2;
  	setcolor(color);
  	callmouse();
  	mouseposi(a,b,cl);
  	setfillstyle(1,color);
  	while(!kbhit())
   		{
			callmouse();
			mouseposi(x1,y1,cl);
			x2=x1;
			y2=y1;
			while(cl==1)
			{
 				hidemouse();
 				rectangle(x1,y1,x1+10,y1+20);
 				floodfill(x1+5,y1+5,color);
 				x1=x2;
 				y1=y2;
 				mouseposi(x2,y2,cl);
			}
   		}
 r.algo();
 }
 	                                     ///FUNCTION FOR CIRCLE///
void circle()
 {
  int a=100,b=400,cl,x1,y1,x2,y2;
  setcolor(color);
  callmouse();
  mouseposi(a,b,cl);
  setfillstyle(1,color);
  while(!kbhit())
   {
	callmouse();
	mouseposi(x1,y1,cl);
	x2=x1;
	y2=y1;
	while(cl==1)
	{
 	hidemouse();
 	circle(x1,y1,10);
 	floodfill(x1,y1,color);
 	x1=x2;
 	y1=y2;
 	mouseposi(x2,y2,cl);
	}
   }
 r.algo();
 }
                                             ///FUNCTION FOR COLOR SELECTION///
int col;
int colorselect()
 {
  	outtextxy(350,100,"COLOR CHOICE: ");
  	cout<<"\t\t\t\t\n\n\n\n\n\";
  	cin>>alpha;
  	if(alpha==1) setcolor(BLUE); // DIFFERENT COLOURS FOR PAINTING
  	if(alpha==2) setcolor(GREEN);
  	if(alpha==3) setcolor(RED);
  	if(alpha==4) setcolor(BROWN);
  	if(alpha==5) setcolor(YELLOW);
  	if(alpha==6) setcolor(WHITE);
  	color=getcolor();
  	col=color;
  	return color;
 }
    	         /////FUNCTION FOR MOUSE WORKING IN SHAPES////
   	/// FUNCTION TO USE DIFFERENT OPTIONS///
void shapeselect()
 {
  	setcolor(col);
  	outtextxy(250,240,"SHAPE CHOICE :");
  	settextstyle(2,0,5);
  	while(1)
   	{
		char a=getche();
		switch(a)
 		{
 			case '1' :  square();     		break;
 			case '2' :  rectangle();  		break;
 			case '3' :  shape();   		break;
 			case '4' :  circle();   		break;
 			case 'c' :  cleardev();      	break;
 			case 'm' :  menu();       	break;
 			case 'q' :   endofp();      	break;
 		}
   	}
 }
   	           /// FUNCTION FOR THE MAIN PAINTING SCREEN ///
void startpaint()
 {
  	setbkcolor(BLACK);
  	setcolor(GREEN);
  	int cl;
  	settextstyle(2,0,5);
  	outtextxy(110,40,"1 FOR SQUARE");
  	outtextxy(110,60,"2 FOR RECTANGLE");
  	outtextxy(110,80,"3 FOR PENCIL");
  	outtextxy(110,100,"4 FOR CIRCLE");
  	outtextxy(100,120,"Q TO EXIT");
  	outtextxy(100,140,"C FOR CLEARSCREEN");
  	outtextxy(110,160,"M TO GO BACK TO MENU");
  	outtextxy(250,40,"COLORS :");
  	outtextxy(250,60,"1.BLUE");
  	outtextxy(250,80,"2.GREEN");
  	outtextxy(250,100,"3.RED");
  	outtextxy(250,120,"4.BROWN");
  	outtextxy(250,140,"5.YELLOW");
  	outtextxy(250,160,"6.WHITE");
  	colorselect();
  	shapeselect();
}


void endofp()
{
cleardevice();
  	char  c ;
 	 ifstream fin ;
   	fin.open("end.txt");
	while (!fin.eof())
		{
			fin.get(c);
  			cout << c;
		}
	fin.close();
delay(5000);
exit(0);
}                                                    /// FUNCTION FOR MAIN ///
void main()
 {
  	int g= DETECT,m;             	// STARTING GRAPHICS MODE
  	initgraph(&g,&m,"C;\\TURBOC4\\TC\\BIN");  // PATH TO GRAPHICS DRIVER
  	int a=100,b=400,cl;
  	callmouse();                 	// FUNCTION CALL
  	mouseposi(a,b,cl);           	//MOUSE POINTER LOCATION
  	menu();                      	//JUMPS TO MENU
  	getch();
  	closegraph();                	// CLOSING GRAPHICS MODE
 }
