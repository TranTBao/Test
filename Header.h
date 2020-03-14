#include<raylib.h>
#include<cstdlib>
#include<ctime>

enum Status { LEFT, RIGHT, UP, DOWN, STOP };

class Map {

public:
	void Show_map();
};


class Snack {

	Vector2* snack;
	Status status;
public:

	void Init_snack();
	void Show_snack();
	void Move_snack();
	void Handling_snack();
};

class Food {
	Vector2 food;
public:
	void Init_food();
	void Show_food();

};


// varible
static bool gameover = false;
static const int Rong = 800;
static const int Cao = 460;
static const size_t SQUARE = 20;
static int So_Dot = 3;



// funtion
static void Show_map();
