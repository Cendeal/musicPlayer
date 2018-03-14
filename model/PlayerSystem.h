#ifndef PLAYERSYSTEM_H
#define PLAYERSYSTEM_H
#include "../head"
class PlayerSystem
{
	public:
		PlayerSystem();
		~PlayerSystem();
		void volumeUp();//声音加 
		void volumeDown();//声音减 
		void playButton();//播放和暂停 
		void forword();//快进 
		void goback();//快退 
		void updateTimer();//更新时间 
		void updateProgressBarWithTimer();//更新时间与进度条 
		void nextSong();//下一曲 
		int listview(int id);//列表 
		int importMusicFromFolder();//导入歌曲 
		void rota_ablum();//【20180303新增】旋转专辑图 
		int run();
		void showAbout();//[20180314新增] 
	protected:
		MusicPlayer mm;
		MusicList ml;
		char songlen[11];
		int id;
		bool button;
		int rota_rad;
};

#endif


