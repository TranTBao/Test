#include"Header.h"




int main() {

	InitWindow(Rong, Cao, "Bao");
	SetTargetFPS(12);

	Map A;
	Snack B;
	Food C;

	B.Init_snack();
	C.Init_food();
	

	while (!WindowShouldClose()) {

		A.Show_map();
		B.Show_snack();
		B.Move_snack();
		B.Handling_snack();
		C.Show_food();
		
	}

	
	CloseWindow();
	return 0;
}

