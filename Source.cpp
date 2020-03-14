#include<raylib.h>
#include<iostream>


enum Status{LEFT , RIGHT , UP , DOWN , STOP};


class Snack {

	Vector2* snack;
	Status status;
public:

	void Init_snack();
	void Show_snack();
	void Move_snack();
	void Handling_snack();
};



// varible
static bool gameover = false;
static const int Rong = 600;
static const int Cao = 460;
static const size_t SQUARE = 20;
static int So_Dot = 3;




// funtion
static void Show_map();


int main() {

	

	InitWindow(Rong, Cao, "Bao");
	SetTargetFPS(12);
	
	

	Snack Bao;
	Bao.Init_snack();
	

	while (!WindowShouldClose()) {

		Show_map();
		Bao.Show_snack();
		Bao.Move_snack();
		Bao.Handling_snack();
		
	}

	
	CloseWindow();
	return 0;
}


void Snack::Init_snack() {

	this->snack = new Vector2[So_Dot];

	this->snack[0].x = 60;
	this->snack[0].y = 20;
	this->snack[1].x = 40;
	this->snack[1].y = 20;
	this->snack[2].x = 20;
	this->snack[2].y = 20;

	this->status = RIGHT;
	
}

void Snack::Show_snack() {

	
	for (int i = 1; i < So_Dot; i++) {
		DrawRectangleV(this->snack[0], { SQUARE ,SQUARE }, DARKGREEN);
		DrawRectangleV(this->snack[i], { SQUARE ,SQUARE }, GREEN);
	}

	if (IsKeyPressed(KEY_ENTER)) {
		Init_snack();
		gameover = false;
	}
	
}

void Snack::Move_snack() {

	// truyen ttrang thai.
	if(!gameover){
		for (int i = So_Dot - 1; i > 0; i--) {
			this->snack[i] = this->snack[i - 1];
		}
	}


	if (!gameover) {
		if (IsKeyPressed(KEY_W) && this->status != DOWN) this->status = UP;
		else if (IsKeyPressed(KEY_S) && this->status != UP) this->status = DOWN;
		else if (IsKeyPressed(KEY_A) && this->status != RIGHT) this->status = LEFT;
		else if (IsKeyPressed(KEY_D) && this->status != LEFT) this->status = RIGHT;
	}

	if (this->status == UP) this->snack[0].y -= 20;
	else if (this->status == DOWN) this->snack[0].y += 20;
	else if (this->status == LEFT) this->snack[0].x -= 20;
	else if (this->status == RIGHT) this->snack[0].x += 20;

	else if (this->status == STOP) {

		this->snack[0].x += 0;
		this->snack[0].y += 0;
	}


}

void Snack::Handling_snack() {

	if (this->snack[0].x < SQUARE || this->snack[0].x == Rong - SQUARE || this->snack[0].y < SQUARE || this->snack[0].y == Cao - SQUARE) gameover = true;
	
	if (gameover == true) {
		//this->status = STOP;
		DrawText("LOSE- Press ENTER to Play again", Rong / 2 - MeasureText("LOSE- Press ENTER to Play again", 20) / 2, Cao / 2 - 20, 20, BLUE);

	}

}













void Show_map() {

	BeginDrawing();

	ClearBackground(BEIGE);

	DrawFPS(Rong - 100, SQUARE);

	if (1) {

	     
		// draw sọc đứng
		for (int i = 0; i < Rong / SQUARE; i++) {  
			//DrawLine(SQUARE * i, 0, SQUARE * i, Cao, BLACK);

			DrawLineV( Vector2{(float)SQUARE * i , 0 }, Vector2{ (float)SQUARE * i , Cao }, GRAY);

		}
		// soc ngang
		for (int i = 0; i < Cao / SQUARE; i++) {
			DrawLine(0, SQUARE * i, Rong, SQUARE * i,GRAY);
		}

		// vien xung quanh (cho vui)
		for (int i = 0; i < Cao / SQUARE; i++) {
			for (int j = 0; j < Rong / SQUARE ; j++) {

				if (i == 0 || i == Cao / SQUARE-1 && j == 0) DrawRectangle(j*SQUARE, i*SQUARE, Rong, SQUARE, DARKBROWN);
				if (j == 0 || j == Rong / SQUARE - 1 && i == 0) DrawRectangle(j * SQUARE, i * SQUARE, SQUARE, Cao, DARKBROWN);
				
			}
		}


	}

	EndDrawing();

}

