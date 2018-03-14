#ifndef MFRAME_H
#define MFRAME_H
#define FHEIGHT 500
#define FWIDTH 500
#define TITLE "Music Player By cendeal"
#define INITABLUM "src\\ablum.jpg"
#define BORDER 20
#define HWHITE RGB(0xff,0xff,0xff)
#include <string>
#include <graphics.h>
/*
	Name: MFrame 
	Author: cendeal
	Date: 04/02/18 22:14
	Description: MFrame��Ҫ���������Ž������Ⱦ��
					 ���а�������������ʱ���ʱ������������ 
*/

class MFrame
{
	public:
		static void createFrame(bool init=false);//��������
		static void createFrame(int w,int h);
		static void destroyFrame();//�ͷŽ���
		static int getHeight();//��ȡ����߶�
		static int getWidth();//��ȡ������
		static void progressBar(const int statuslen);//���ý���������
		static void setAblum(PIMAGE im,int rad=0);//���ø���ר��ͼ ��20180303�޸ġ� 
		static int getBorder();//��ȡ����߽�
		static void volumeBar(const  float level);//�������� ��20180303�޸ġ� 
		static void playAndStopButton(bool isplay);//��������ͣ��ť
		static void songTile(std::string name);//���ø�������
		static void warningInfo(std::string msg);//������Ϣ
		static void curtimer(std::string time);//��ǰʱ����ʾ
		static void textBar(std::string content,int position);

	private:
		int static height;
		int static width;
		int static border;
};

#endif
