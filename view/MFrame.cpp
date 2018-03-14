#include "MFrame.h"
int MFrame::height=FHEIGHT;
int MFrame::width=FWIDTH;
int MFrame::border=BORDER;

void MFrame::createFrame(bool init)
{
	if(!init)
	initgraph(width,height,INIT_NOFORCEEXIT);
	else
	cleardevice();
	setcaption(TITLE);
	setbkcolor(HWHITE);//´¿°×É«

	setAblum(NULL,0);
	progressBar(0);
	volumeBar(0.5);
	songTile("¸èÇúÃû");
	playAndStopButton(true);
}
void MFrame::createFrame(int w,int h)
{
	width=w;
	height=h;
	initgraph(width,height,INIT_NOFORCEEXIT);
	setcaption(TITLE);
	setbkcolor(HWHITE);//´¿°×É«
	
	setAblum(NULL,0);
	progressBar(0);
	volumeBar(0.5);
	songTile("¸èÇúÃû");
	playAndStopButton(true);
}

void MFrame::setAblum(PIMAGE im,int rad)
{
	if(im==NULL){
	im=newimage();
	getimage(im,INITABLUM);
	} 
	float x=width/2-getwidth(im)/2;
	float y=height/2-getheight(im)/2;
	putimage_rotatezoom(NULL,im,x*2,y*2,0.5,0.5,-0.1*rad,0.8,0,-1,1);
}

void MFrame::progressBar(const int statuslen)
{
	setfillcolor(RED);
	bar(border/2,height-100,statuslen+border/2,height-100-10);
	setfillcolor(BLACK);
	bar(statuslen+border/2,height-100,width-border/2,height-100-10);

}
void MFrame::volumeBar(const  float level)
{
	float j;
	int i;
	for(i=0,j=0.0; i<10; i++,j+=0.1) {
		if(j<level) {
			setfillcolor(EGERGB(0xFF, 0xFF, 0x00));
			bar(width-25,height-120-i*10,width-10,height-125-i*10);
		} else {
			setfillcolor(DARKGRAY);
			bar(width-25,height-120-i*10,width-10,height-125-i*10);
		}
	}

}
void MFrame::songTile(std::string name)
{
	setfillcolor(HWHITE);
	bar(0,10,getWidth(),30);
	int len=name.length();
	if(name.length()>50)
		len=50;
	setcolor(RED);
	outtextrect(getWidth()/2-len/2*5,10,250,20,name.c_str());
}

void MFrame::playAndStopButton(bool isplay)
{
	int r=40;
	int ox=width/2,oy=height-border-r;
	setcolor(HWHITE);
	setfillcolor(HWHITE);
	fillellipse(ox,oy,r,r);
	if(isplay) {
		//»­Èý½ÇÐÎ
		setcolor(RED);//±ß½çÑÕÉ«
		setfillcolor(RED);//Ìî³äÑÕÉ«
		line(ox-12,oy-32,ox+r-2,oy);
		line(ox+r-2,oy,ox-12,oy+32);
		line(ox-12,oy+32,ox-12,oy-32);
		floodfill(ox,oy, RED);//¿ªÊ¼Ìî³ä
	} else {
		//»­Ë«¸Ü
		setfillcolor(RED);
		bar(ox-22,oy-32,ox-12,oy+32);
		bar(ox+12,oy-32,ox+22,oy+32);
	}
}
void MFrame::warningInfo(std::string msg)
{
	LOGFONTA *tf;
	color_t tc=getcolor();
	//color_t tcbk=getbkcolor();
	getfont(tf);
	setcolor(HWHITE);
	setfontbkcolor(RED);
	setfont(20,10,"ËÎÌå");

	outtextxy(getWidth()/2-msg.size()/2*10,40,msg.c_str());
	delay_fps(1);
	outtextxy(getWidth()/2-msg.size()/2*10,40,msg.c_str());
	delay_fps(1);
	
	setfont(tf);
	setcolor(RED);
	setbkcolor(HWHITE);
	setfillcolor(HWHITE);
	bar(0,40,getWidth(),60);
}
/*
position:x=20 ,y=height-140

*/ 
void MFrame::curtimer(std::string time){
	setfillcolor(HWHITE);
	bar(20,height-140,100,height-120);
	setcolor(RED);
	outtextxy(20,height-140,time.c_str());
} 

void MFrame::destroyFrame()
{
	closegraph();
}

int MFrame::getHeight()
{
	return height;
}

int MFrame::getWidth()
{
	return width;
}

int MFrame::getBorder()
{
	return border;
}
void MFrame::textBar(std::string content,int position){

	outtextxy(120,110+position*20,content.c_str());
}
