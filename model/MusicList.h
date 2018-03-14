#ifndef MUSICLIST_H
#define MUSICLIST_H
#include <string>
#include <map>
#include <fstream>
/*
	Name: Musiclist 
	Author: cendeal
	Date: 04/02/18 21:33
	Description: Musiclist类主要负责从外部存储器获取歌单，
					 更新外部存储器的歌单，为MusicPlayer类
					 提供歌曲路径、歌曲名..... 
*/

using namespace std;
class MusicList
{
	public:
		MusicList();
		bool loadListData(string filepath);//加载内存中的表
		bool renewList();//将现在的表更新保存到内存中
		void clearList();//清空表单包括内存中的表单
		void delSong(int id);//通过id删除歌曲
		void addSong(string songNamePath);//增加歌曲
		string getSongPath(int id);//通过id获取歌曲路径
		map<string,string>::iterator moveIterator(int &id);//迭代到id
		string getSongName(string path);//通过路径截取歌曲名
		string getSongNameById(int id);//通过id获取歌名
		int getsize();//获取歌曲总数 
		~MusicList();

	private:
		map<string,string> mclist;
		string mfilepath;
		bool modify;
		fstream f;

};

#endif
