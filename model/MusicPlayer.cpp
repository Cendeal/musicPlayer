#include "MusicPlayer.h"

MusicPlayer::MusicPlayer():MUSIC()
{
	volume=NORMOLVL;
	
}
void MusicPlayer::setVolume(float v)
{
	if(volume+v<=LOWVL)
		volume=LOWVL;
	else if(volume+v>=HIGHVL)
		volume=HIGHVL;
	else
		volume+=v;
	MUSIC::SetVolume(volume);
}
float MusicPlayer::getVolume()
{
	return volume;
}
void MusicPlayer::forword()
{
	Play(GetPosition()+SPEED);
}
void MusicPlayer::goback()
{
	Play(GetPosition()-SPEED);
}
int MusicPlayer::getProgressBarLen(const int width)
{
	return GetPosition()*width/GetLength();
}

void MusicPlayer::setSongname(std::string name)
{
	songname=name;
}
std::string MusicPlayer::getSongname()
{
	return songname;
}
void MusicPlayer::setAlbum(const char *src){
	album=newimage();
	getimage(album,src);
} 
PIMAGE MusicPlayer::getAlbum(){
	return album;
} 
