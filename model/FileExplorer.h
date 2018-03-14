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
	Description: FileExplorerΪ�ͻ���������ṩ������ص����µ������ļ��е���ڣ�
					 ���ṩ������������޸��κ��ļ����µ����ݣ����Ի�ȡָ����׺�����ļ��� 
*/

class FileExplorer
{
	public:
		FileExplorer();//���캯�������Զ��������ϵͳ�µ������̷� 
		void openNextFolder(int id);//����id����ָ�����ļ�·�� 
		void backToHome();//���ص��̷���ʼ״̬ 
		void willAddTolist(int id);//δʵ�� 
		bool nameHash(string name,string suffix);//�жϲ���name�Ƿ��������suffix��ͬ�ĺ�׺ 
		string getCurrentPath();// ���ص�ǰ��·�� 
		~FileExplorer();
		
		vector<string> cur_path;//��¼��ǰ���ʹ����ļ��� 
		vector<string> folder;//��¼��ǰ·���������ļ��� 
		vector<string> mp3file;//��¼��ǰ·��������MP3�ļ� 
		vector<int> willList;//Ը���嵥 
	private:
		_finddata_t file;
		
};

#endif
