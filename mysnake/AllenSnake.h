#pragma once
#pragma comment(lib,"winmm.lib")
#include<Windows.h>
#include <vector>
using std::vector;
#define SNAKE_SHAPE "◎"
#define SNAKE_CLEAR "  "
#define SNAKE_SHAPESHEN "■"
#define SNAKE_SHAPESHEN2 "※"
#define SNAKE_SHAPESHEN3 "卐"
#define SNAKE_SHAPESHENUP "∧"
#define SNAKE_SHAPESHENDW "∨"
#define SNAKE_SHAPESHENL "＜"
#define SNAKE_SHAPESHENR "＞"
#define SNAKE_DIR_UP 0
#define SNAKE_DIR_DW 2
#define SNAKE_DIR_LF 1
#define SNAKE_DIR_RH 3
typedef struct _SNAKENODE {
	int nPosX;
	int nPosY;
}SNAKENODE;

class AllenSnake
{
public:
	AllenSnake();
	~AllenSnake();
	void InitSnake(int nX, int nY, int nDir);
	bool SnakeMove();
	bool ChangeDir(char cDir);
	bool m_bDie;
	vector<SNAKENODE> m_vecSnake;
private:
	bool SnakeCanMove();
	void Eat();
	int m_nDir;
	
	
};
//生命值
extern int Nnum;
//分数
extern int Nnum2;