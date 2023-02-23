#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct Pos
{
	int y;
	int x;
} t_Pos;

t_Pos setPos(int inY, int inX)
{
	struct Pos myPos;
	myPos.y = inY;
	myPos.x = inX;
	return (myPos);
}

t_Pos getPrincessPos(int const n, char grid[101][101])
{
	int len = n - 1;
	if (grid[0][0] == 'p')
		return (setPos(0, 0));
	if (grid[len][0] == 'p')
		return (setPos(len, 0));
	if (grid[0][len] == 'p')
		return (setPos(0, len));
	if (grid[len][len] == 'p')
		return (setPos(len, len));
	return (setPos(-1, -1));
}

t_Pos getBotPos(int const n, char grid[101][101])
{
	for (int y = 0; y < n; ++y)
		for (int x = 0; x < n; ++x)
			if (grid[y][x] == 'm')
				return (setPos(y, x));
	return (setPos(-1, -1));
}

void moveLeft(void)
{
	printf("LEFT\n");
}

void moveRight(void)
{
	printf("RIGHT\n");
}

void moveUp(void)
{
	printf("UP\n");
}

void moveDown(void)
{
	printf("DOWN\n");
}

void displayPathtoPrincess(int n, char grid[101][101]){
	//logic here
	t_Pos princess = getPrincessPos(n, grid);
	t_Pos bot = getBotPos(n, grid);
	void (*moveX)(void) = NULL;
	void (*moveY)(void) = NULL;
	int stepY = 0;
	int stepX = 0;
	if (bot.y > princess.y)
	{
		stepY = -1;
		moveY = &moveUp;
	}
	else if (bot.y < princess.y)
	{
		stepY = 1;
		moveY = &moveDown;
	}

	if (bot.x > princess.x)
	{
		stepX = -1;
		moveX = &moveLeft;
	}
	else if (bot.x < princess.x)
	{
		stepX = 1;
		moveX = &moveRight;
	}

	while (bot.y != princess.y || bot.x != princess.x)
	{
		if (bot.y != princess.y)
		{
			(*moveY)();
			bot.y += stepY;
		}
		if (bot.x != princess.x)
		{
			(*moveX)();
			bot.x += stepX;
		}
	}
}

int main(void)
{
	int m;
	scanf("%d", &m);
	char grid[101][101]={};
	char line[101];

	for(int i=0; i<m; i++) {
		scanf("%s", line);
		strcpy(grid[i], line);
	}
	displayPathtoPrincess(m,grid);
	return 0;
}