#include "ListView.h"
ListView::ListView(int w,int h)
{
	width=w;
	height=h;
	icon=newimage();
}
void ListView::setName(string name)
{
	this->name=name;
}
void ListView::setIcon(string path)
{
	getimage(icon,path.c_str());
}
void ListView::setSelcted(bool s)
{
	selected=s;
}
bool ListView::isSelectItem()
{
	return selected;
}
void ListView::show(int state,int itemcount, bool select)
{
	setbkcolor(WHITE);
	if(state==0) {
		setfillcolor(LIGHTGRAY);
		setfontbkcolor(LIGHTGRAY);
	} else {
		setfillcolor(YELLOW);
		setfontbkcolor(YELLOW);
	}
	bar(0, itemcount*(getheight(icon)+10)+5, width, itemcount*(getheight(icon)+10)+getheight(icon)+13);

	if(selected) {
		if(select) {
			setfillcolor(GREEN);
		} else {
			setfillcolor(WHITE);

		}
		fillellipse(width-15,itemcount*(getheight(icon)+10)+getheight(icon)/2+10,10,10);
	}
	putimage_transparent(NULL, icon, 10, itemcount*(getheight(icon)+10)+10, BLACK);
	setcolor(WHITE);
	outtextxy(getwidth(icon)+20,itemcount*(getheight(icon)+10)+getheight(icon)/3,name.c_str());
}
void ListView::hide(int itemcount)
{
	setfillcolor(WHITE);
	bar(0, itemcount*(getheight(icon)+10)+5, width, itemcount*(getheight(icon)+10)+getheight(icon)+13);
}
void ListView::info(string msg)
{
	setcolor(BLACK);
	outtextxy(width/2-msg.size()/2*5,100,msg.c_str());
	delay_fps(10);
	outtextxy(width/2-msg.size()/2*5,100,msg.c_str());
	delay_fps(2);
}

