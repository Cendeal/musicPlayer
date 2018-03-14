#ifndef MFRAME_H
#define MFRAME_H
#define FHEIGHT 500
#define FWIDTH 500
#define TITLE "Music Player By cendeal"
#define INITABLUM "src\\ablum.jpg"
#define BORDER 20
#define HWHITE RGB(0xff,0xff,0xff)
#include <string>
#include <graphics.h>
/*
	Name: MFrame 
	Author: cendeal
	Date: 04/02/18 22:14
	Description: MFrame主要负责主播放界面的渲染，
					 其中包括：进度条、时间计时器、歌曲名等 
*/

class MFrame
{
	public:
		static void createFrame(bool init=false);//创建界面
		static void createFrame(int w,int h);
		static void destroyFrame();//释放界面
		static int getHeight();//获取界面高度
		static int getWidth();//获取界面宽度
		static void progressBar(const int statuslen);//设置进度条进度
		static void setAblum(PIMAGE im,int rad=0);//设置歌曲专辑图 【20180303修改】 
		static int getBorder();//获取界面边界
		static void volumeBar(const  float level);//声音条形 【20180303修改】 
		static void playAndStopButton(bool isplay);//播放与暂停按钮
		static void songTile(std::string name);//设置歌曲名字
		static void warningInfo(std::string msg);//警告消息
		static void curtimer(std::string time);//当前时间显示
		static void textBar(std::string content,int position);

	private:
		int static height;
		int static width;
		int static border;
};

#endif
