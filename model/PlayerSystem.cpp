#include "PlayerSystem.h"
#include <fstream>
using namespace std;
PlayerSystem::PlayerSystem()
{
	id=1;
	button=false;
	rota_rad=0;
	showAbout();
	MFrame::createFrame(false);
}

PlayerSystem::~PlayerSystem()
{
	MFrame::destroyFrame();
}
void PlayerSystem::volumeUp()
{
	mm.setVolume(0.1);
	MFrame::volumeBar(mm.getVolume()) ;
}
void PlayerSystem::volumeDown()
{
	mm.setVolume(-0.1);
	MFrame::volumeBar(mm.getVolume()) ;
}
void PlayerSystem::playButton()
{
	if(mm.GetPlayStatus()==MUSIC_MODE_PLAY) {
		MFrame::playAndStopButton(true);
		mm.Pause();
	} else {
		MFrame::playAndStopButton(false);
		mm.Play();
	}
}
void PlayerSystem::forword()
{
	mm.forword();
	MFrame::playAndStopButton(false);
}
void PlayerSystem::goback()
{
	mm.goback();
	MFrame::playAndStopButton(false);
}
void PlayerSystem::updateTimer()
{
	if(!mm.IsOpen())
		return;
	sprintf(songlen,"%02d:%02d/%02d:%02d",mm.GetPosition()/1000/60,mm.GetPosition()/1000%60,
	        mm.GetLength()/1000/60,mm.GetLength()/1000%60);
	MFrame::curtimer(songlen);
}
void PlayerSystem::updateProgressBarWithTimer()
{
	int curlen=mm.getProgressBarLen(MFrame::getWidth()-MFrame::getBorder());
	MFrame::progressBar(curlen);
	updateTimer();
}
void PlayerSystem::nextSong()
{

	id++;
	id%=ml.getsize();
	mm.OpenFile(ml.getSongPath(id).c_str());
	mm.setSongname(ml.getSongNameById(id));
	//new
	mm.setAlbum(INITABLUM);
	MFrame::playAndStopButton(true);
	MFrame::songTile(mm.getSongname().c_str());

	while(!mm.IsOpen()) {
		MFrame::warningInfo("�޷�����");
		id++;
		id%=ml.getsize();
		mm.OpenFile(ml.getSongPath(id).c_str());
		mm.setSongname(ml.getSongNameById(id));
		MFrame::songTile(mm.getSongname().c_str());
		MFrame::playAndStopButton(true);
		if(ml.getsize()==1) {
			button=false;
			return ;
		}
	}
	mm.setVolume(0);
	updateProgressBarWithTimer();
	MFrame::volumeBar(mm.getVolume());
	//updateTimer();
}
int PlayerSystem::listview(int id)
{
	cleardevice();
	int ch=id-1;
	int begin=0;
	ListView t(MFrame::getWidth(),MFrame::getHeight());
	if(ml.getsize()<=0) {
		t.info("����Ϊ��!");
		return -1;
	}
	for(int i=0; i<9; i++) {
		if(i+1+begin>ml.getsize()) {
			if(i>=1) {
				t.hide(i);
			}
			break;
		}
		t.setIcon("src\\mp3.png");
		t.setName(ml.getSongNameById(i));
		t.setSelcted(false);
		if(i!=ch)
			t.show(0,i);
		else
			t.show(1,i);
	}
	while(is_run()) {
		if(kbhit()) {
			key_msg k=getkey();
			if(k.key==key_esc)
				return -1;
			if(k.key==key_down) {
				ch++;
				if(ch>=ml.getsize()) {
					ch=ch-1;
					if(ch>=7&&begin>0) {
						begin--;
					}
				}
				if(ch>7) {
					begin++;
				}
			}
			if(k.key==key_up) {
				ch--;
				if(ch<0) {
					ch=0;
				}
				if(ch>=7&&begin>0) {
					begin--;
				}
			}
			if(k.key=='m') {
				return -1;
			}
			if(k.key=='d') {
				if(ch>=0) {
					if(ml.getSongNameById(ch)==mm.getSongname()&&mm.GetPlayStatus()==MUSIC_MODE_PLAY) {
						t.info("�ø������ڲ���,�޷�ɾ��!");
					} else {
						ml.delSong(ch);
						t.info("��ɾ��!");
						if(ml.getsize()<=0) {
							t.info("����Ϊ��!");
							button=false;
							return -1;
						}
					}
				}
				if(ch>=ml.getsize()) {
					ch=ml.getsize()-1;
				}
			}
			if(k.key==key_space&&button)
				return ch;
			cleardevice();
			for(int i=0; i<9; i++) {
				if(i+1+begin>ml.getsize()) {
					if(i>=1) {
						t.hide(i);
					}
					break;
				}
				t.setName(ml.getSongNameById(i+begin));
				t.setSelcted(false);
				if(i+begin!=ch)
					t.show(0,i);
				else
					t.show(1,i);
			}
			flushkey();
		}
		if(mm.IsOpen())
			if(mm.GetLength()==mm.GetPosition())
				return -1;
		delay_fps(60);
	}
}
int PlayerSystem::importMusicFromFolder()
{
	FileExplorer infile;
	cleardevice();
	ListView v(MFrame::getWidth(),MFrame::getHeight());
	int ch=0;
	int begin=0;
	for(int i=0; i<9; i++) {
		v.setIcon("src\\file.png");
		if(i+1+begin>infile.folder.size()+infile.mp3file.size()) {
			if(i>=1) {
				v.hide(i);
			}
			break;
		}
		v.setName(infile.folder[i+begin]);
		v.setSelcted(false);
		if(i+begin!=ch)
			v.show(0,i);
		else
			v.show(1,i);
	}
	while(is_run()) {
		if(kbhit()) {
			key_msg k=getkey();
			if(k.key=='i') {
				return -1;
			}
			if(k.key==key_esc) {
				return 27;
			}
			if(k.key==key_down) {
				ch++;
				if(ch>=infile.folder.size()+infile.mp3file.size()) {
					ch=ch-1;
					if(ch>=7&&begin>0) {
						begin--;
					}
				}
				if(ch>7) {
					begin++;
				}
			}
			if(k.key==key_up) {
				ch--;
				if(ch<0) {
					ch=0;
				}
				if(ch>=7&&begin>0) {
					begin--;
				}
			}
			if(k.key==key_space) {
				if(ch>=infile.folder.size()) {
					int num=ch-infile.folder.size();
					ml.addSong(infile.getCurrentPath()+infile.mp3file[num]);
					v.info("�����!");
				}
			}
			if(k.key==key_enter) {
				if(ch<infile.folder.size()) {
					infile.openNextFolder(ch);
					ch=0;
					begin=0;
				}
			}
			if(k.key=='b') {
				infile.backToHome();
				ch=0;
				begin=0;
			}
			cleardevice();
			for(int i=0; i<9; i++) {
				if(i+begin<infile.folder.size()) {
					v.setName(infile.folder[i+begin]);
					v.setIcon("src\\file.png");
				} else if(i+begin>=infile.folder.size()&&i+begin<infile.folder.size()+infile.mp3file.size()) {
					v.setName(infile.mp3file[i+begin-infile.folder.size()]);
					v.setIcon("src\\mp3.png");
				} else {
					if(i>=1) {
						v.hide(i);
					}
					break;
				}
				v.setSelcted(false);
				if(i+begin!=ch)
					v.show(0,i);
				else
					v.show(1,i);
			}
			flushkey();
		}
		if(mm.IsOpen())
			if(mm.GetLength()==mm.GetPosition())
				return -1;
		delay_fps(60);
	}
	return 27;
}
void PlayerSystem::rota_ablum()
{
	MFrame::setAblum(mm.getAlbum(),rota_rad);
	rota_rad++;
	if(rota_rad==64)
		rota_rad=0;
}
int PlayerSystem::run()
{
	delay_fps(60);
	if(ml.getsize()<=0) {
		MFrame::warningInfo("Ŀ¼��esc�˳�,i�������");
		int ch;
		delay_fps(1);
		MFrame::warningInfo("�뵼�������");
		while((ch=importMusicFromFolder())==-1&&ml.getsize()<=0&&is_run()) {
			MFrame::warningInfo("�뵼�������");
		}
		if(ch==27)
			return 0;
		MFrame::createFrame(true);
		MFrame::songTile(mm.getSongname());
		MFrame::playAndStopButton(mm.GetPlayStatus()!=MUSIC_MODE_PLAY);
	}
	button=true;

	mm.OpenFile(ml.getSongPath(0).c_str());
	mm.setSongname(ml.getSongNameById(0));
	MFrame::songTile(mm.getSongname());
	if(mm.IsOpen()) {
		mm.setVolume(0);
		mm.setAlbum(INITABLUM);
		updateTimer();
		updateProgressBarWithTimer();
	}

	while(is_run()) {
		if(kbhit()) {
			key_msg k=getkey();

			if(k.key==key_esc)
				return 0;
			//������
			if(k.key==key_up) {
				volumeUp();
			}
			//������
			if(k.key==key_down) {
				volumeDown();
			}
			//���ź���ͣ
			if(k.key==key_space&&button) {
				if(!mm.IsOpen())
					MFrame::warningInfo("�޷����Ÿø���");
				else
					playButton();
				if(ml.getsize()<=0) {
					MFrame::songTile("�޸���!");

				} else
					MFrame::songTile(mm.getSongname());
			}
			//���
			if(k.key==key_right&&button) {
				forword();
			}
			//����
			if(k.key==key_left&&button) {
				goback();
			}
			//��һ��
			if(k.key=='n'&&button) {
				nextSong();
			}
			//�赥
			if(k.key=='m') {
				int temp=listview(id);
				cleardevice();
				MFrame::createFrame(true);
				if(temp!=-1) {
					id=temp-1;
					nextSong();
					mm.Play();
				}
				if(ml.getsize()<=0) {
					MFrame::songTile("�޸���!");
					button=false;
				} else {
					MFrame::songTile(mm.getSongname());
					button=true;
				}
				MFrame::playAndStopButton(mm.GetPlayStatus()!=MUSIC_MODE_PLAY);
			}
			//����¸���
			if(k.key=='i') {
				importMusicFromFolder();
				cleardevice();
				MFrame::createFrame(true);
				if(ml.getsize()<=0) {
					MFrame::songTile("�޸���!");
					button=false;
				} else if(ml.getsize()>0) {
					if(button)
						MFrame::songTile(mm.getSongname());
					else {
						nextSong();
						button=true;
					}
				}
				MFrame::playAndStopButton(mm.GetPlayStatus()!=MUSIC_MODE_PLAY);
			}
			flushkey();
		}
		if(mm.GetPlayStatus()==MUSIC_MODE_PLAY) {
			rota_ablum();
			updateProgressBarWithTimer();
			if(mm.GetPosition()==mm.GetLength()) {
				mm.Close();
				nextSong();
				playButton();
			}
			MFrame::playAndStopButton(false);
		}
		delay_fps(60);
		if(ml.getsize()>0) {

			button=true;
		} else {
			button=false;
		}
	}
	return 0;
}

void PlayerSystem::showAbout(){
	MFrame::createFrame();
	fstream r;
	r.open("data\\usage.txt",ios_base::in);
	string line;
	if(!r.is_open())
	return;
	cleardevice();

	int nline=0;
		MFrame::textBar(TITLE,5);
		MFrame::textBar("�����������......",6);
	while(r>>line){
		if(line[0]=='1'||line[0]=='2'||line[0]=='3'){
		getch();
		cleardevice();	
		nline=0;
		}
		MFrame::textBar(line,nline);
		nline++;	
	}
	
	r.close();
	getch();
	
}


