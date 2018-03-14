#include "MusicList.h"
MusicList::MusicList()
{
	mfilepath="data\\defaultList";
	modify=false;
	if(!loadListData(mfilepath)) {
		fstream ftemp(mfilepath.c_str(),ios_base::out);
		ftemp.close();
		loadListData(mfilepath);
	}
}
bool MusicList::loadListData(string filepath)
{
	f.open(filepath.c_str(),ios_base::in);
	if(!f.is_open())
		return false;
	string song;
	while(!f.eof()) {
		getline(f,song);
		if(song.empty())
			break;
		mclist[song]=getSongName(song);
	}
	f.close();
	return true;
}
bool MusicList::renewList()
{
	map<string,string>::iterator it=mclist.begin();

	f.open(mfilepath.c_str(),ios_base::out);
	if(!f.is_open())
		return false;
	while(it!=mclist.end()) {

		f<<(*it).first<<endl;
		it++;
	}
	f.close();
	return true;

}
void MusicList::clearList()
{
	f.open(mfilepath.c_str(),ios_base::out);
	mclist.clear();
	f.close();
}

map<string,string>::iterator MusicList::moveIterator(int &id)
{
	map<string,string>::iterator it=mclist.begin();
	if(id<=mclist.size())
		for(int i=0; i<id; i++,it++);
	return it;
}
void MusicList::delSong(int id)
{
	if(mclist.empty())
		return;
	mclist.erase(moveIterator(id));
	modify=true;
}
void MusicList::addSong(string songNamePath)
{
	mclist[songNamePath]=getSongName(songNamePath);
	modify=true;
}
string MusicList::getSongPath(int id)
{
	if (mclist.empty())
		return "";
	return (*moveIterator(id)).first;
}

string MusicList::getSongName(string path)
{
	if(path.size()<=2)
		return path;
	int last=path.find_last_of('.');
	int first=path.find_last_of('\\')+1;
	return path.substr(first,last);
}

string MusicList::getSongNameById(int id)
{
	if (mclist.empty()||id>=mclist.size())
		return "";
	return (*moveIterator(id)).second;
}
int MusicList::getsize()
{
	return mclist.size();
}
MusicList::~MusicList()
{
	if(modify) {
		renewList();
	}
	mclist.clear();
}
