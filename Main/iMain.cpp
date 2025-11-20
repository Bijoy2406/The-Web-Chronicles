# include <iostream>
using namespace std;
#define  _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"
# include "score.h"
# include "gover.h"
# include "variables1.h"
# include "variables2.h"
# include "variables3.h"
# include "variables4.h"
# include "variables5.h"
# include "methods5.h"
# include "methods4.h"
# include "methods3.h"
# include "methods2.h"
# include "methods1.h"



char scores[10];
int selectedButton = 0;

void gameOver(){
	//cout << player.score << endl;
	if (flag == 5)
	{
		saveScore();
		sort();
		HighScore();

		strcpy(player.name, "");
		score = 0;
		player.score = 0;
		len = 0;
		flag = 0;

	}
}


void die()
{
	iShowImage(0, 0, screenWidth, screenHeight, sequence[index]);
}

void iDraw()
{
	//place your drawing codes here
	iClear();

	_itoa(score, scores, 10);
	_itoa(score1, score11, 10);
	_itoa(score2, score22, 10);
	_itoa(score3, score33, 10);
	_itoa(score4, score44, 10);
	_itoa(score4, score55, 10);

	if (gamestate == -1)
	{
		iShowImage(0, 0, screenWidth, screenHeight, title);
		//iPauseTimer(0);
		sort();
		HighScore();
	}

	else if (gamestate == 0)
	{
		//menu state
		iShowImage(0, 0, screenWidth, screenHeight, menu);
		for (int i = 0; i < 5; i++)
		{
			iShowImage(bCoordinate[i].x, bCoordinate[i].y, 260, 75, buttons[i]);
			if (gamestate == 0 && i == selectedButton)
			{
				iRectangle(bCoordinate[i].x, bCoordinate[i].y - 10, 265, 90);
				// Draw white box around selected button
			}
		}
		iSetColor(255, 255, 255);
		iText(127, 25, "Press Insert on the selected button", GLUT_BITMAP_TIMES_ROMAN_24);

	}

	else if (gamestate == 1)
	{

		iShowImage(0, 0, screenWidth, screenHeight, imgy);
		/*
		iShowImage(0, 0, screenWidth, screenHeight, inst);
		iSetColor(255, 255, 255);
		iText(screenWidth / 2, screenHeight / 2, "Enter Name", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(screenWidth / 2 + 200, screenHeight / 2, player.name, GLUT_BITMAP_TIMES_ROMAN_24);
		*/
		iSetColor(0, 0, 0);
		//iText(screenWidth / 2, screenHeight / 2, "Enter Name", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(380, 75, player.name, GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 255, 255);
		iText(480, 30, "Press enter to continue", GLUT_BITMAP_TIMES_ROMAN_24);


	}

	else if (gamestate == 2)
	{

		//iShowImage(0, 0, screenWidth, screenHeight, imgy);

		if (gamephase == 1)
		{
			//iShowImage(0, 0, screenWidth, screenHeight, sequence[index]);
		}

		else if (gamephase == 2)
		{
			player.score = score;
			//bg rendering
			for (int i = 0; i < 5; i++)
			{
				iShowImage(mainbg[i].x, mainbg[i].y, screenWidth, screenHeight, bg[i]);
			}
			
			
			//iFilledRectangle(800, 525, 100, 100);
			iSetColor(0, 0, 0);
			iText(screenWidth / 2, screenHeight - 100, player.name, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(screenWidth / 2, screenHeight - 150, scores, GLUT_BITMAP_TIMES_ROMAN_24);
			iSetColor(255, 255, 255);
			iText(700, 645, "PRESS X TO FIRE BULLETS FROM ENEMY", GLUT_BITMAP_TIMES_ROMAN_24);
			//movement of enemies function call
			enemyMovement();
			enemy2Movement();
			//movement of peter function call
			peterMovement();
			
			//drawing all the bars
			drawDimensionalBar();
			drawUltimateBar();
			drawPeterHealthBar();
			thugHealthBars();

			//ult web methods calling(in idraw because damage will be most for this)
			webMovement();
			fireMovement();
			webCollision();

			//orb movement and collision
			rOrbsMovement();
			collisioncheck3();

			rhOrbsMovement();
			collisioncheck4();

			ruOrbsMovement();
			collisioncheck5();

			if (spidermanHealth <= 0)
			{
				die();
			}
			//transporting to next level
			flag = 1;
			if (dBar >= 50)
			{
				gamephase = 3;
				score += 100;

			}
		}

		else if (gamephase == 3)
		{
			player.score = score;
			
			//bg rendering			
			for (int i = 0; i < 5; i++)
			{
				iShowImage(mainbg2[i].x2, mainbg2[i].y2, screenWidth, screenHeight, bg2[i]);
			}
			iSetColor(255, 255, 255);
			iText(screenWidth / 2, screenHeight - 100, player.name, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(screenWidth / 2, screenHeight - 150, scores, GLUT_BITMAP_TIMES_ROMAN_24);

			//Rhino details display
			iShowImage(1450, screenHeight - 150, 150, 150, imga);
			iShowImage(1200, screenHeight - 90, 250, 60, imgb);

			//displaying healthbars
			drawPeterHealthBar2();
			drawRhinoHealthBar();

			//web and character movements

			webMovement2();
			rhinoMovement();
			peterMovement2();
			
			if (spidermanHealth2 <= 0)
			{
				die();
			}
			flag = 2;
			if (rhinoHealth <= 0)
			{
				gamephase = 4;
				score += 300;

			}
			
		}

		else if (gamephase == 4)
		{
			player.score = score;
			//bg rendering
			//ctr2 = true;
			for (int i = 0; i < n3; i++)
			{
				iShowImage(mainbg3[i].x3, mainbg3[i].y3, screenWidth, screenHeight, bg3[i]);
			}
			iSetColor(255, 255, 255);
			iText(screenWidth / 2, screenHeight - 100, player.name, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(screenWidth / 2, screenHeight - 150, scores, GLUT_BITMAP_TIMES_ROMAN_24);
			iSetColor(255, 255, 255);
			iText(700, 645, "PRESS X TO FIRE BULLETS FROM ENEMY", GLUT_BITMAP_TIMES_ROMAN_24);

			//movement of enemies function call
			enemyMovement3();
			enemy2Movement3();

			//movement of peter function call

			drawDimensionalBar3();
			drawUltimateBar3();
			peterMovement3();

			//health bars function call
			drawPeterHealthBar3();
			thugHealthBars3();


			//ult web methods calling(in idraw because damage will be most for this)
			webMovement3();
			webCollision3();

			fireMovement3();

			//d-orb movement and collision
			rOrbsMovement3();
			collisioncheck33();

			rhOrbsMovement3();
			collisioncheck43();


			ruOrbsMovement3();
			collisioncheck53();

			if (spidermanHealth3 <= 0)
			{
				die();
			}
			flag = 3;
			if (dBar3 >= 50)
			{
				gamephase = 5;
				score += 100;
			}
		}

		else if (gamephase == 5)
		{
			player.score = score;
			//bg rendering
			for (int i = 0; i < n4; i++)
			{
				iShowImage(mainbg4[i].x4, mainbg4[i].y4, screenWidth, screenHeight, bg4[i]);
			}
			iSetColor(255, 255, 255);
			iText(screenWidth / 2, screenHeight - 100, player.name, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(screenWidth / 2, screenHeight - 150, scores, GLUT_BITMAP_TIMES_ROMAN_24);

			//movement of peter function call
			iShowImage(1450, screenHeight - 190, 190, 190, imgm);
			iShowImage(990, screenHeight - 90, 450, 40, imgn);
			//miles pic and text
			iShowImage(0, screenHeight - 190, 190, 220, imgk);
			iShowImage(180, screenHeight - 125, 380, 110, imgl);
			drawPeterHealthBar4();
			drawKravenHealthBar();
			peterMovement4();
			kravenMovement();

			//ult web methods calling(in idraw because damage will be most for this)
			webMovement4();
			//webCollision();
			//webCollision2();

			if (spidermanHealth4 <= 0)
			{
				die();
			}
			flag = 4;
			if (kravenHealth <= 0)
			{
				//iSetColor(255, 255, 255);
				//iText(750, 610, "KRAVEN LOSES!", GLUT_BITMAP_TIMES_ROMAN_24);
				gamephase = 6;
				score += 100;
			}
		}

		else if (gamephase == 6)
		{
			player.score = score;
			//bg rendering
			for (int i = 0; i < n5; i++)
			{
				iShowImage(mainbg5[i].x5, mainbg5[i].y5, screenWidth, screenHeight, bg5[i]);
			}

			iSetColor(255, 255, 255);
			iText(screenWidth / 2, screenHeight - 100, player.name, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(screenWidth / 2, screenHeight - 150, scores, GLUT_BITMAP_TIMES_ROMAN_24);

			iShowImage(0, screenHeight - 190, 190, 220, spideyIcon5);
			iShowImage(180, screenHeight - 125, 380, 90, imgd);

			iShowImage(1410, screenHeight - 190, 190, 190, mysterioIcon);
			iShowImage(1050, screenHeight - 90, 350, 30, imge);
			//movement of peter function call
			drawPeterHealthBar5();
			drawmysterioHealthBar();
			peterMovement5();
			mysterioMovement();


			//ult web methods calling(in idraw because damage will be most for this)
			webMovement5();
			if (spidermanHealth5 <= 0)
			{
				die();
			}

			flag = 5;
			if (mysterioHealth <= 0)
			{
				//iSetColor(255, 255, 255);
				//iText(750, 610, "Mysterio LOSES!", GLUT_BITMAP_TIMES_ROMAN_24);
				score += 100;
				gameOver();
				iShowImage(0, 0, screenWidth, screenHeight, victory);
			}
		}

	}

	else if (gamestate == 3)
	{
		iShowImage(0, 0, screenWidth, screenHeight, inst);
		//cout << hs2 << endl;
		//cout << score22 << endl;
	}

	else if (gamestate == 4)
	{
		iShowImage(0, 0, screenWidth, screenHeight, highscore);
		iSetColor(0, 0, 0);
		iText(150, 500, hs1, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(350, 500, score11, GLUT_BITMAP_TIMES_ROMAN_24);

		iText(150, 400, hs2, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(350, 400, score22, GLUT_BITMAP_TIMES_ROMAN_24);

		iText(150, 300, hs3, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(350, 300, score33, GLUT_BITMAP_TIMES_ROMAN_24);

		iText(150, 200, hs4, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(350, 200, score44, GLUT_BITMAP_TIMES_ROMAN_24);

		iText(150, 100, hs5, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(350, 100, score55, GLUT_BITMAP_TIMES_ROMAN_24);
	}

	else if (gamestate == 5)
	{
		iShowImage(0, 0, screenWidth, screenHeight, credits);
		//exit(0);
	}
	else if (gamestate == 6)
	{
		gamestate = 0;
	}

}

void iPassiveMouse(int mx, int my)
{
	;
}


/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{

	//place your codes here
}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	printf("%d %d ", mx, my);
	/*
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		if (gamestate == 0)
		{
			for (int i = 0; i < 5; i++)
			{
				if (mx >= bCoordinate[i].x && mx <= bCoordinate[i].x + 359 && my >= bCoordinate[i].y && my <= bCoordinate[i].y + 90)
				{
					gamestate = i + 1;

				}
			}
		}

	}
	*/
}


/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (key == '\r')
	{
		gamestate = 2;
		gamephase = 2;
		ctr = true;
		iPauseTimer(0);
	}
	if (gamestate == 1)
	{
		if (key != '\b')
		{
			player.name[len] = key;
			len++;
			player.name[len] = '\0';
			//printf("%s", player.name);

		}
		else{
			if (len <= 0)
			{
				len = 0;
			}
			else{
				len -= 1;
				player.name[len] = '\0';
			}
		}

	}
	/*
	if (key == 'q')
	{
		exit(0);
	}
	*/
	else if (key == 'z')
	{
		gamestate = 0;
	}

	else if (key == 'y')
	{
		gamestate = 1;
	}

	if (gamephase == 2)
	{
		if (key == ' ')
		{
			if (!jump)
			{
				jump = true;
				jumpUp = true;
			}
		}

		else if (key == '1')
		{
			pun = true;

		}

		else if (key == '2')
		{
			kic = true;

		}
		else if (key == '3' && uBar >= 100)
		{
			ulti = true;
			bloc = false;
			setWebVariables();
		}

		else if (key == '4')
		{
			bloc = true;

		}
		else if (key == 'a')
		{
			kic = false;
			pun = false;
			bloc = false;
			LEFT = true;
			if (x >= 0)
			{
				x = x - 15;
			}
			r2index++;
			if (r2index >= 6)
			{
				r2index = 0;
			}
			stand = false;
			RIGHT = false;
			jumper = false;
			jumpL = true;
			jumpR = false;
		}

		else if (key == 'd')
		{
			kic = false;
			bloc = false;
			pun = false;
			RIGHT = true;
			if (x + 180 <= screenWidth)
			{
				x = x + 15;
			}
			r1index++;
			if (r1index >= 6)
			{
				r1index = 0;
			}
			stand = false;
			LEFT = false;
			jumpR = true;
			jumpL = false;
		}

		else if (key == 'x')
		{
			thugUlt = true;
			setFireVariables();
		}


	}

	else if (gamephase == 3)
	{
		if (key == ' ')
		{
			if (!jump2)
			{
				jump2 = true;
				jumpUp2 = true;
			}
		}

		else if (key == '1')
		{
			pun2 = true;

		}

		else if (key == '2')
		{
			kic2 = true;

		}
		else if (key == '3')
		{
			ulti2 = true;
			bloc2 = false;
			setWebVariables2();

		}

		else if (key == '4')
		{
			bloc2 = true;


		}

		else if (key == 'a')
		{
			LEFT2 = true;
			if (x2 >= 0)
			{
				x2 = x2 - 15;
			}
			r2index2++;
			if (r2index2 >= 6)
			{
				r2index2 = 0;
			}
			stand2 = false;
			RIGHT2 = false;
			jumper2 = false;
			jumpL2 = true;
			jumpR2 = false;
		}

		else if (key == 'd')
		{
			RIGHT2 = true;
			if (x2 + 180 <= screenWidth)
			{
				x2 = x2 + 15;
			}
			r1index2++;
			if (r1index2 >= 6)
			{
				r1index2 = 0;
			}
			stand2 = false;
			LEFT2 = false;
			jumpR2 = true;
			jumpL2 = false;
		}

		else if (key == '8')
		{
			rhinoPun = true;

		}

		else if (key == '9')
		{
			rhinoKic = true;

		}

		else if (key == '0')
		{
			rhinoUlti = true;

		}
	}

	else if (gamephase == 4)
	{
		if (key == ' ')
		{
			if (!jump3)
			{
				jump3 = true;
				jumpUp3 = true;
			}
		}

		else if (key == '1')
		{
			pun3 = true;

		}

		else if (key == '2')
		{
			kic3 = true;

		}
		else if (key == '3' && uBar3 >= 100)
		{
			ulti3 = true;
			bloc3 = false;
			setWebVariables3();

		}

		else if (key == '4')
		{
			bloc3 = true;

		}
		else if (key == 'a')
		{
			kic3 = false;
			pun3 = false;
			bloc3 = false;
			LEFT3 = true;
			if (x3 >= 0)
			{
				x3 = x3 - 15;
			}
			r2index3++;
			if (r2index3 >= 5)
			{
				r2index3 = 0;
			}
			stand3 = false;
			RIGHT3 = false;
			jumper3 = false;
			jumpL3 = true;
			jumpR3 = false;
		}

		else if (key == 'd')
		{
			kic3 = false;
			bloc3 = false;
			pun3 = false;
			RIGHT3 = true;
			if (x3 + 180 <= screenWidth)
			{
				x3 = x3 + 15;
			}
			r1index3++;
			if (r1index3 >= 5)
			{
				r1index3 = 0;
			}
			stand3 = false;
			LEFT3 = false;
			jumpR3 = true;
			jumpL3 = false;
		}

		else if (key == 'x')
		{
			thugUlt3 = true;
			setFireVariables3();
		}
	}

	else if (gamephase == 5)
	{
		if (key == ' ')
		{
			if (!jump4)
			{
				jump4 = true;
				jumpUp4 = true;
			}
		}

		else if (key == '1')
		{
			pun4 = true;

		}

		else if (key == '2')
		{
			kic4 = true;

		}
		else if (key == '3')
		{
			ulti4 = true;
			bloc4 = false;
			setWebVariables4();

		}
		else if (key == '4')
		{
			bloc4 = true;


		}
		else if (key == 'a')
		{
			LEFT4 = true;
			if (x4 >= 0)
			{
				x4 = x4 - 15;
			}
			r2index4++;
			if (r2index4 >= 4)
			{
				r2index4 = 0;
			}
			stand4 = false;
			RIGHT4 = false;
			jumper4 = false;
			jumpL4 = true;
			jumpR4 = false;
		}

		else if (key == 'd')
		{
			RIGHT4 = true;
			if (x4 + 180 <= screenWidth)
			{
				x4 = x4 + 15;
			}
			r1index4++;
			if (r1index4 >= 4)
			{
				r1index4 = 0;
			}
			stand4 = false;
			LEFT4 = false;
			jumpR4 = true;
			jumpL4 = false;
		}
		else if (key == '8')
		{
			kravenPun = true;

		}
		else if (key == '9')
		{
			kravenKic = true;

		}
		else if (key == '0')
		{
			kravenUlti = true;

		}
	}

	else if (gamephase == 6)
	{
	    if (key == ' ')
		{
			if (!jump5)
			{
				jump5 = true;
				jumpUp5 = true;
			}
		}

		else if (key == '1')
		{
			pun5 = true;

		}

		else if (key == '2')
		{
			kic5 = true;

		}
		else if (key == '3')
		{
			ulti5 = true;
			bloc5 = false;
			setWebVariables5();
		}
		else if (key == '4')
		{
			bloc5 = true;
		
		}
		else if (key == '5')
		{
			ulti25 = true;
		}
		else if (key == '6')
		{
			ulti35 = true;
		}
		else if (key == 'a')
		{
			LEFT5 = true;
			if (x5 >= 0)
			{
				x5 = x5 - 15;
			}
			r2index5++;
			if (r2index5 >= 5)
			{
				r2index5 = 0;
			}
			stand5 = false;
			RIGHT5 = false;
			jumper5 = false;
			jumpL5 = true;
			jumpR5 = false;
		}

		else if (key == 'd')
		{
			RIGHT5 = true;
			if (x5 + 180 <= screenWidth)
			{
				x5 = x5 + 15;
			}
			r1index5++;
			if (r1index5 >= 5)
			{
				r1index5 = 0;
			}
			stand5 = false;
			LEFT5 = false;
			jumpR5 = true;
			jumpL5 = false;
		}
		else if (key == '7')
		{
			mysterioPun = true;

		}
		else if (key == '8')
		{
			mysterioKic = true;

		}
		else if (key == '9')
		{
			mysterioUlti = true;

		}
		else if (key == '0')
		{
			mysterioUlti2 = true;

		}
	}

}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/

void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	if (gamestate == 0)
	{
		if (key == GLUT_KEY_UP)
		{
			selectedButton = (selectedButton - 1 + 5) % 5; 
		}
		else if (key == GLUT_KEY_DOWN)
		{
			selectedButton = (selectedButton + 1) % 5; 
		}
		else if (key == GLUT_KEY_INSERT)
		{
			if (selectedButton >= 0 && selectedButton < 5)
			{
				gamestate = selectedButton + 1; 
			}
		}
	}
	if (key == GLUT_KEY_F1)
	{
		gamephase = 1;
		iResumeTimer(0);
	}


	else if (key == GLUT_KEY_F2)
	{
		/*
		gamestate = 2;
		gamephase = 2;
		ctr = true;
		iPauseTimer(0);
		*/
	}

	if (gamephase == 3)
	{
		if (key == GLUT_KEY_LEFT)
		{
			rhinoLEFT = true;
		}

		else if (key == GLUT_KEY_RIGHT)
		{
			rhinoRIGHT = true;
		}

		else if (key == GLUT_KEY_UP)
		{
			if (!rhinoJump)
			{
				rhinoJump = true;
				rhinoJumpUp = true;
			}
		}
	}

	if (gamephase == 5)
	{
		if (key == GLUT_KEY_END)
		{
			exit(0);
		}
		else if (key == GLUT_KEY_LEFT)
		{
			kravenRIGHT = true;
			
		}
		else if (key == GLUT_KEY_RIGHT)
		{
			kravenLEFT = true;
			
		}

		else if (key == GLUT_KEY_UP)
		{
			if (!kravenJump)
			{
				kravenJump = true;
				kravenJumpUp = true;
			}
		}
	}

	if (gamephase == 6)
	{
		if (key == GLUT_KEY_LEFT)
		{
			mysterioRIGHT = true;
			
		}
		else if (key == GLUT_KEY_RIGHT)
		{
			mysterioLEFT = true;			
		}

		else if (key == GLUT_KEY_UP)
		{
			if (!mysterioJump)
			{
				mysterioJump = true;
				mysterioJumpUp = true;
			}
		}
	}
	//place your codes for other keys here
}



int main()
{
	system("Color 0C"); //For only windows platform.
	cout << "WITH GREAT POWER, COMES GREAT RESPONSIBILITY!" << endl;
	iInitialize(screenWidth, screenHeight, "Demo");

	callback();
	//Level-1 method calls
	gameOver();
	rsetOrbVariables();
	rsethOrbVariables();
	rsetuOrbVariables();
	thugImages();
	peterImages();
	iSetTimer(120, stan);
	iSetTimer(120, declare);
	bgImages();
	titleButtons();

	//Level-2 method calls
	peterImages2();
	rhinoImages();
	setAll2();


	//Level-3 method calls
	setAll3();
	rsetOrbVariables3();
	rsethOrbVariables3();
	rsetuOrbVariables3();
	thugImages3();
	peterImages3();

	//Level-4 method calls
	setAll4();
	peterImages4();
	kravenImages();

	iSetTimer(120, attack5);
	imgd = iLoadImage("99text.png");
	imge = iLoadImage("doomtext.png");
	//peterImages5();
	//mysterioImages();

	iStart();

	return 0;
}

