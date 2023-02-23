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
	for (int y = 0; y < n; ++y)
		for (int x = 0; x < n; ++x)
			if (grid[y][x] == 'p')
				return (setPos(y, x));
	return (setPos(-1, -1));
}

void nextMove(int n, int r, int c, char grid[101][101]){
	//logic here

	t_Pos princess = getPrincessPos(n, grid);
	t_Pos bot = setPos(r, c);

	if (bot.y != princess.y)
	{
		if (bot.y > princess.y)
			printf("UP\n");
		else if (bot.y < princess.y)
			printf("DOWN\n");
	}
	else if (bot.x != princess.x)
	{
		if (bot.x > princess.x)
			printf("LEFT\n");
		else if (bot.x < princess.x)
			printf("RIGHT\n");
	}
}

int main(void)
{
	int n, r, c;

	scanf("%d", &n);
	scanf("%d", &r);
	scanf("%d", &c);

	char grid[101][101];
	
	for(int i=0; i<n; i++) {
		scanf("%s[^\n]%*c", grid[i]);
	}

	nextMove(n, r, c, grid);
	return 0;
}