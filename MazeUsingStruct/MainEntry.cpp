#include <iostream>
#include "MazeMap.h"
#include "Renderer.h"
#include <CoreWindow.h>
#include "Player.h"
#include <conio.h>
#include "Input.h"
using namespace std;

void main()
{
	MazeMap m;
	Renderer r;
	m.loadFromFile("testMap.txt");
	r.drawMap(m);
	r.drawGoal(m);

	//--
	Player p;
	p.assignMap(m);
	p.initPos(m.playerInitPosX, m.playerInitPosY);
	r.drawPlayer(p);
	
	Input i;

	while (!i.esc && !p.reachTheGoal())
	{
		i.getKey();
		r.erasePlayer(p);
		if (i.up)
		{
			if (p.canGoUp())
				p.goUp();
		}
		else if (i.down)
		{
			if (p.canGoDown())
				p.goDown();
		}
		else if (i.left)
		{
			if (p.canGoLeft())
				p.goLeft();
		}
		else
		{
			if (p.canGoRight())
				p.goRight();
		}
		//r->debugDrawPlayerPos(p);
		//r->erasePlayer(p);
		r.drawPlayer(p);
	}
	if (p.reachTheGoal())
	{
		r.gotoxy(70, 1);
		cout << "YOU WIN ";
	}
	else
	{
		r.gotoxy(70, 1);

		cout << "esc";
	}
	//--
}