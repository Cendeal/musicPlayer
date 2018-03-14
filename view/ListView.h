#ifndef LISTVIEW_H
#define LISTVIEW_H
#include <string>
#include <graphics.h>
using namespace std;
/*
	Name: ListView
	Author: cendeal 
	Date: 04/02/18 22:19
	Description: ListView主要是负责列表视图渲染，主要是设置视图的样式 
*/

class ListView
{
	public:
		ListView(int w,int h);
		~ListView(){
			cleardevice(icon);
		};
		void setName(string name);//设置显示的名字 
		void setIcon(string path);//通过路径来设置图标签 
		void setSelcted(bool s);//设置为是否为可选的列表 
		bool isSelectItem();//是否为可选 
		void show(int state,int itemcount,bool select=false);//显示，state为0时视图背景为灰色色，其他为白色;itemcout为显示的位置0-8;select是否为选中状态	
		void hide(int itemcount);//设置第itemcout项为白色覆盖 
		void info(string msg);//提示信息 
	private:
		PIMAGE icon;//图标签 
		string name;//显示文字 
		bool selected;//是否为可选 
		int  width;//列表的宽度 
		int height;//列表的高度 
};

#endif
