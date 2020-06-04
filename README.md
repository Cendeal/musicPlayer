---
这是一个比较简易的mp3播放器，基于ege,一个最简单的图形库，刚入门c/c++的同学可以尝试一下玩玩,入门槛非常低


## 1.ege环境配置
- [ege新手入门](http://xege.org/%e6%96%b0%e6%89%8b%e5%85%a5%e9%97%a8%e3%80%8e%e4%b8%80%e3%80%8fege%e7%9a%84%e4%bb%8b%e7%bb%8d%e3%80%81%e5%ae%89%e8%a3%85%e5%92%8c%e4%bd%bf%e7%94%a8.html)
- [ege简单基础知识](http://xege.org/%e6%96%b0%e6%89%8b%e5%85%a5%e9%97%a8%e3%80%8e%e4%ba%8c%e3%80%8f%e5%88%9b%e5%bb%ba%e7%ac%ac%e4%b8%80%e4%b8%aaege%e7%a8%8b%e5%ba%8f.html)

## 2.项目文件结构
```
│  head//头文件导入
│  main.cpp//主文件
│  Makefile.win
│  musicPlayer.dev//devc++项目文件
│  musicPlayer.zip//windows软件包，使用请解压
│  musicPlayer.ico
│  musicPlayer.layout
├─data
│      about.txt//关于
│      defaultList//歌单存储文件
│      usage.txt//使用方法文件
│
├─model
│      FileExplorer.cpp//文件夹浏览实现
│      FileExplorer.h
│      MusicList.cpp//音乐列表结构
│      MusicList.h
│      MusicPlayer.cpp//播放器基本功能
│      MusicPlayer.h
│      PlayerSystem.cpp//播放系统实现
│      PlayerSystem.h
├─src
│  │  ablum.jpg//默认歌曲封面（没有实现从MP3文件提取图片）
│  │  file.png//文件夹视图
│  │  mp3.gif//演示动态图
│  │  mp3.png//MP3文件试图
│  │
│  └─mp3
│         //mp3文件
└─view
        ListView.cpp//列表视图
        ListView.h
        MFrame.cpp//基本框架
        MFrame.h
```
## 3.播放器原理
> 导入歌曲：通过记录歌曲所在路径到一个文本文件下
> 播放歌曲：通过路经来播放
> 删除歌曲：不是实际的删除本地文件，只是把记录的路径从数据擦除，重新覆盖原来的记录文件
## 4.关键代码文件
- 1 MFrame.h

```
    Name: MFrame 
    Author: cendeal
    Date: 04/02/18 22:14
    Description:MFrame主要负责主播放界面的渲染，其中包括：进度条、时间计时器、歌曲名等 
```

```
class MFrame
{
	public:
		static void createFrame(bool init=false);//创建界面
		static void createFrame(int w,int h);
		static void destroyFrame();//释放界面
		static int getHeight();//获取界面高度
		static int getWidth();//获取界面宽度
		static void progressBar(const int statuslen);//设置进度条进度
		static void setAblum(PIMAGE im,int rad=0);//设置歌曲专辑图 【20180303修改】 
		static int getBorder();//获取界面边界
		static void volumeBar(const  float level);//声音条形 【20180303修改】 
		static void playAndStopButton(bool isplay);//播放与暂停按钮
		static void songTile(std::string name);//设置歌曲名字
		static void warningInfo(std::string msg);//警告消息
		static void curtimer(std::string time);//当前时间显示
		static void textBar(std::string content,int position);

	private:
		int static height;
		int static width;
		int static border;
};
```
- 2 ListView.h
```
	Name: ListView
	Author: cendeal 
	Date: 04/02/18 22:19
	Description: ListView主要是负责列表视图渲染，主要是设置视图的样式 

```
---
```
class ListView
{
	public:
		ListView(int w,int h);
		~ListView(){
			cleardevice(icon);
		};
		void setName(string name);//设置显示的名字 
		void setIcon(string path);//通过路径来设置图标签 
		void setSelcted(bool s);//设置为是否为可选的列表 
		bool isSelectItem();//是否为可选 
		void show(int state,int itemcount,bool select=false);//显示，state为0时视图背景为灰色色，其他为白色;itemcout为显示的位置0-8;select是否为选中状态	
		void hide(int itemcount);//设置第itemcout项为白色覆盖 
		void info(string msg);//提示信息 
	private:
		PIMAGE icon;//图标签 
		string name;//显示文字 
		bool selected;//是否为可选 
		int  width;//列表的宽度 
		int height;//列表的高度 
};
```
- 3 Musiclist.h
```
    Name: Musiclist 
	Author: cendeal
	Date: 04/02/18 21:33
	Description: Musiclist类主要负责从外部存储器获取歌单，
					 更新外部存储器的歌单，为MusicPlayer类
					 提供歌曲路径、歌曲名..... 
```
---
```
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
```
- 4 FileExplorer.h
```	
    Name: FileExplorer
	Author: cendeal 
	Date: 04/02/18 21:38
	Description:FileExplorer为客户导入歌曲提供浏览本地电脑下的所有文件夹的入口,	
    仅提供浏览，不可以修改任何文件夹下的内容；可以获取指定后缀名的文件。
```
---
```
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
```

- 5 PlayerSystem.h

```
class PlayerSystem
{
	public:
		PlayerSystem();
		~PlayerSystem();
		void volumeUp();//声音加 
		void volumeDown();//声音减 
		void playButton();//播放和暂停 
		void forword();//快进 
		void goback();//快退 
		void updateTimer();//更新时间 
		void updateProgressBarWithTimer();//更新时间与进度条 
		void nextSong();//下一曲 
		int listview(int id);//列表 
		int importMusicFromFolder();//导入歌曲 
		void rota_ablum();//【20180303新增】旋转专辑图 
		int run();
		void showAbout();//[20180314新增] 
	protected:
		MusicPlayer mm;
		MusicList ml;
		char songlen[11];
		int id;
		bool button;
		int rota_rad;
};
```

- 6 main.cpp
```
	Name: main 
	Author: cendeal
	Date: 05/02/18 00:09
	Description: 主函数 
```
---
```
#include "model/PlayerSystem.h"
int main(){
	PlayerSystem sys;
	sys.run();
	return 0;
}
```
---
## 5.示例演示

![mp3.gif](https://upload-images.jianshu.io/upload_images/4413333-f53879ec3796962d.gif)

## 6.项目地址
[musicPlayer By Cendeal](https://github.com/Cendeal/musicPlayer)
