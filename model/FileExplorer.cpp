#include "FileExplorer.h"
FileExplorer::FileExplorer()
{
	backToHome();
}
void FileExplorer::openNextFolder(int id)
{
	if(folder[id]!=".") {
		if(folder[id]=="..") {
			cur_path.pop_back();
		} else {
			cur_path.push_back(folder[id]);
		}
	}
	long addr=_findfirst((getCurrentPath()+"*").c_str(),&file);
	if(addr==-1) {
		cur_path.pop_back();
		return;
	}
	folder.clear();
	mp3file.clear();
	do {
		if(16==file.attrib||file.attrib==17) {
			folder.push_back(file.name);
		} else if(nameHash(file.name,"mp3")) {
			mp3file.push_back(file.name);
		}
	} while(_findnext(addr,&file)!=-1);
	_findclose(addr);
}
void FileExplorer::backToHome()
{
	folder.clear();
	mp3file.clear();
	cur_path.clear();
	TCHAR szBuf[100];
	memset(szBuf,0,100);
	GetLogicalDriveStrings(sizeof(szBuf)/sizeof(TCHAR),szBuf);
	for (TCHAR * s= szBuf;  *s;  s+=_tcslen(s)+1) {
		LPCTSTR Drivestr = s;
		folder.push_back(s);
	}
}
bool FileExplorer::nameHash(string target,string suffix)
{
	int first=target.find_last_of('.')+1;
	if(target.substr(first)==suffix)
		return true;
	return false;
}
string FileExplorer::getCurrentPath()
{
	string curpath="";
	for(int i=0; i<cur_path.size(); i++) {
		curpath+=cur_path[i]+"\\";
	}
	return curpath;
}
FileExplorer::~FileExplorer()
{
	folder.clear();
	mp3file.clear();
	cur_path.clear();
}
