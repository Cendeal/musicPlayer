#ifndef LISTVIEW_H
#define LISTVIEW_H
#include <string>
#include <graphics.h>
using namespace std;
/*
	Name: ListView
	Author: cendeal 
	Date: 04/02/18 22:19
	Description: ListView��Ҫ�Ǹ����б���ͼ��Ⱦ����Ҫ��������ͼ����ʽ 
*/

class ListView
{
	public:
		ListView(int w,int h);
		~ListView(){
			cleardevice(icon);
		};
		void setName(string name);//������ʾ������ 
		void setIcon(string path);//ͨ��·��������ͼ��ǩ 
		void setSelcted(bool s);//����Ϊ�Ƿ�Ϊ��ѡ���б� 
		bool isSelectItem();//�Ƿ�Ϊ��ѡ 
		void show(int state,int itemcount,bool select=false);//��ʾ��stateΪ0ʱ��ͼ����Ϊ��ɫɫ������Ϊ��ɫ;itemcoutΪ��ʾ��λ��0-8;select�Ƿ�Ϊѡ��״̬	
		void hide(int itemcount);//���õ�itemcout��Ϊ��ɫ���� 
		void info(string msg);//��ʾ��Ϣ 
	private:
		PIMAGE icon;//ͼ��ǩ 
		string name;//��ʾ���� 
		bool selected;//�Ƿ�Ϊ��ѡ 
		int  width;//�б�Ŀ�� 
		int height;//�б�ĸ߶� 
};

#endif
