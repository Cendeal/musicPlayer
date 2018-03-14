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
	Description: MusicPlayer�Ǽ̳�ege.h�µ�MUSIC�������࣬
					 ���������level,������,���,���˵ȵ� 
*/

class MusicPlayer : public MUSIC
{
	public:
		MusicPlayer();
		void setVolume(float v);//��������,+0.1Ϊ�ӣ�-0.1Ϊ�� 
		float getVolume();//��ȡ��ǰ������level 0-1level ��20180303�޸ġ� 
		int getProgressBarLen(const int width);//��ȡ��ǰ�Ľ������ܳ� 
		void setSongname(std::string name);//���õ�ǰ���ŵĸ����� 
		std::string getSongname();//��ȡ��ǰ���ŵĸ����� 
		void forword();//��� Ĭ��Ϊ2000ms 
		void goback(); //���� Ĭ��Ϊ2000ms 
		//new ��20180303������
		void setAlbum(const char *src); 
		PIMAGE getAlbum();
	private:
		float volume;//��ǰ������level 
		std::string songname;//��ǰ�ĸ����� 
		//new ��20180303������ 
		PIMAGE album;
};

#endif
