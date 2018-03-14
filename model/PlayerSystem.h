#ifndef PLAYERSYSTEM_H
#define PLAYERSYSTEM_H
#include "../head"
class PlayerSystem
{
	public:
		PlayerSystem();
		~PlayerSystem();
		void volumeUp();//������ 
		void volumeDown();//������ 
		void playButton();//���ź���ͣ 
		void forword();//��� 
		void goback();//���� 
		void updateTimer();//����ʱ�� 
		void updateProgressBarWithTimer();//����ʱ��������� 
		void nextSong();//��һ�� 
		int listview(int id);//�б� 
		int importMusicFromFolder();//������� 
		void rota_ablum();//��20180303��������תר��ͼ 
		int run();
		void showAbout();//[20180314����] 
	protected:
		MusicPlayer mm;
		MusicList ml;
		char songlen[11];
		int id;
		bool button;
		int rota_rad;
};

#endif


