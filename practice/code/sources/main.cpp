

#include "Game.h"

using namespace std;
using namespace example;

int main()
{
	Game* game = new Game("Bullet example!!!!", 1280, 720);

	game->init();

	return 0;
}