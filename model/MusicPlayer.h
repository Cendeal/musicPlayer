#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H
#define HIGHVL 1.0
#define LOWVL 0.0
#define NORMOLVL 0.5
#define SPEED 2000
#include <graphics.h>
#include <string>
using namespace std;

/*
	Name: MusicPlayer 
	Author: cendeal
	Date: 04/02/18 21:28
	Description: MusicPlayer是继承ege.h下的MUSIC的派生类，
					 新添加声音level,歌曲名,快进,快退等等 
*/

class MusicPlayer : public MUSIC
{
	public:
		MusicPlayer();
		void setVolume(float v);//设置声音,+0.1为加，-0.1为减 
		float getVolume();//获取当前的声音level 0-1level 【20180303修改】 
		int getProgressBarLen(const int width);//获取当前的进度条总长 
		void setSongname(std::string name);//设置当前播放的歌曲名 
		std::string getSongname();//获取当前播放的歌曲名 
		void forword();//快进 默认为2000ms 
		void goback(); //快退 默认为2000ms 
		//new 【20180303新增】
		void setAlbum(const char *src); 
		PIMAGE getAlbum();
	private:
		float volume;//当前的声音level 
		std::string songname;//当前的歌曲名 
		//new 【20180303新增】 
		PIMAGE album;
};

#endif
