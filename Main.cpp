#include"Header.h"




int main() {

	InitWindow(Rong, Cao, "Bao");
	SetTargetFPS(10);
	srand(time(0));

	Map A;
	Snack B;
	Food C;

	B.Init_snack();
	C.Init_food();
	

	while (!WindowShouldClose()) {

		A.Show_map();
		B.Show_snack();
		C.Show_food();
		B.Move_snack();
		B.Handling_snack();
		
		
	}

	
	CloseWindow();
	return 0;
}

