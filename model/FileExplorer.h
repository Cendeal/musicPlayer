#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H
#include <io.h>
#include <string>
#include <windows.h>
#include <tchar.h>
#include <vector>
using namespace std;
/*
	Name: FileExplorer
	Author: cendeal 
	Date: 04/02/18 21:38
	Description: FileExplorer为客户导入歌曲提供浏览本地电脑下的所有文件夹的入口，
					 仅提供浏览，不可以修改任何文件夹下的内容；可以获取指定后缀名的文件。 
*/

class FileExplorer
{
	public:
		FileExplorer();//构造函数，会自动导入电脑系统下的所有盘符 
		void openNextFolder(int id);//根据id来打开指定的文件路径 
		void backToHome();//返回到盘符初始状态 
		void willAddTolist(int id);//未实现 
		bool nameHash(string name,string suffix);//判断参数name是否包含参数suffix相同的后缀 
		string getCurrentPath();// 返回当前的路径 
		~FileExplorer();
		
		vector<string> cur_path;//记录当前访问过的文件夹 
		vector<string> folder;//记录当前路径的所有文件夹 
		vector<string> mp3file;//记录当前路径的所有MP3文件 
		vector<int> willList;//愿意清单 
	private:
		_finddata_t file;
		
};

#endif
