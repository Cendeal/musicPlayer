#ifndef MUSICLIST_H
#define MUSICLIST_H
#include <string>
#include <map>
#include <fstream>
/*
	Name: Musiclist 
	Author: cendeal
	Date: 04/02/18 21:33
	Description: Musiclist����Ҫ������ⲿ�洢����ȡ�赥��
					 �����ⲿ�洢���ĸ赥��ΪMusicPlayer��
					 �ṩ����·����������..... 
*/

using namespace std;
class MusicList
{
	public:
		MusicList();
		bool loadListData(string filepath);//�����ڴ��еı�
		bool renewList();//�����ڵı���±��浽�ڴ���
		void clearList();//��ձ������ڴ��еı�
		void delSong(int id);//ͨ��idɾ������
		void addSong(string songNamePath);//���Ӹ���
		string getSongPath(int id);//ͨ��id��ȡ����·��
		map<string,string>::iterator moveIterator(int &id);//������id
		string getSongName(string path);//ͨ��·����ȡ������
		string getSongNameById(int id);//ͨ��id��ȡ����
		int getsize();//��ȡ�������� 
		~MusicList();

	private:
		map<string,string> mclist;
		string mfilepath;
		bool modify;
		fstream f;

};

#endif
