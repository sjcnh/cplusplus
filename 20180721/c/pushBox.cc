///
/// @file    test.cc
/// @author  LJW
/// @date    2018-07-21 22:28:44
///
//

#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#define ROW 9
#define COL 11

// 空地0  墙1  目的地3  箱子4  人5
int map[ROW][COL] = {
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
	{0, 1, 0, 4, 4, 4, 4, 4, 0, 1, 0},
	{0, 1, 0, 4, 0, 4, 0, 4, 0, 1, 0},
	{0, 1, 0, 0, 0, 5, 0, 0, 4, 0, 1},
	{1, 1, 0, 1, 1, 1, 1, 0, 4, 0, 1},
	{1, 0, 3, 3, 3, 3, 3, 1, 0, 0, 1},
	{1, 0, 3, 3, 3, 3, 3, 0, 0, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
};

void beginGame();
void drawMap()
{
	for(int i = 0; i < ROW; ++i)
	{
		for(int j = 0; j < COL; ++j)
		{
			switch(map[i][j])
			{
				case 0:
					cout << " ";
					break;
				case 1:
					cout << "■";
					break;
				case 3:
					cout << "☆";
					break;
				case 4:
					cout << "□";
					break;
				case 5:
					cout << "p";
					break;
				case 7:
					cout << "★";
					break;
				case 8: // 人在目的地中
					cout << "p";
					break;
				default :
					cout << " ";
					break;



			}
		}
		cout << endl;
	}
}

int main()
{
	while(1)
	{
		system("cls");
		drawMap();
		beginGame();
	}
}

void beginGame()
{
	// 1.需要接受键盘
	// 2.再接收键盘的时候，接收二维数组
	// 3.需要改变哪些元素, 人周围的值
	// 4.如何确定人的位置
	//
	// =========找到人的位置==================
	int r, c; // 人的行列
	for(int i = 0; i < ROW; ++i)
	{
		for(int j = 0; j < COL; ++j) 
		{
			if(5 == map[i][j] || 8 == map[i][j])
			{
				r = i;
				c = j;
			}
		}
	}
	// =========接收键盘输入==================
	int ch;
	cin >> ch;
	// getchar()  会显示回文，按下键盘之后接收完成
	// getch()    不显示回文，按下键盘直接接收
	switch(ch)
	{
		case 'W':
		case 'w':
		case 72: // 上 键盘的方向键  键值
			break;
		case 'S':
		case 's':
		case 80:
			break;
		case 'A':
		case 'a':
		case 75:
			break;
		case 'D':
		case 'd':
		case 77:
			break;
		default:
			break;
	}
	// 游戏规则：
	// 可以动的：（改变坐标）
	//		1.人的前面是空地
	//		2.人的前面是目的地
	//		3.人的前面是箱子（不一定）：
	//			3.1箱子前面是空地可以动
	//			3.2箱子前面是目的地
	//
	// 不可以动：（什么都不做）
	// 
}

