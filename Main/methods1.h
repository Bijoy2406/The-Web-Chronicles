int flag = 0;
void drawPeterHealthBar()
{
	int barWidth = 325;         
	int barHeight = 25;         
	int barX = 190;
	int barY = screenHeight - 90;

	int maxHealth = 500;

	int healthBarWidth = (spidermanHealth * barWidth) / maxHealth;

	if (healthBarWidth > barWidth) {
		healthBarWidth = barWidth; 
	}

	iShowImage(0, screenHeight - 200, 180, 200, spideyIcon);
	iShowImage(180, screenHeight - 65, 350, 60, t1);

	iSetColor(255, 0, 0); 
	iFilledRectangle(barX, barY, barWidth, barHeight);

	if (spidermanHealth > 0)
	{
		iSetColor(0, 255, 0); 
		iFilledRectangle(barX, barY, healthBarWidth, barHeight);
	}
}

void drawDimensionalBar()
{
	int barWidth = 325;
	int barHeight = 25;
	int barX = 190;
	int barY = screenHeight - 130;

	int dBarWidth = (dBar * barWidth) / 1000;


	iSetColor(255, 0, 0);
	iFilledRectangle(barX, barY, barWidth, barHeight);

	if (dBar <= 100)
	{

		int newDBarWidth = (dBar * barWidth) / 100;


		iSetColor(0, 0, 255);
		iFilledRectangle(barX, barY, newDBarWidth, barHeight);
	}
	else
	{
		iSetColor(0, 0, 255);
		iFilledRectangle(barX, barY, barWidth, barHeight);
	}
}

void drawUltimateBar()
{
	int ubarWidth = 325;
	int ubarHeight = 25;
	int ubarX = 190;
	int ubarY = screenHeight - 170;

	int udBarWidth = (uBar * ubarWidth) / 1000;


	iSetColor(255, 0, 0);
	iFilledRectangle(ubarX, ubarY, ubarWidth, ubarHeight);

	if (uBar <= 100)
	{

		int newuBarWidth = (uBar * ubarWidth) / 100;


		iSetColor(255, 165, 0);
		iFilledRectangle(ubarX, ubarY, newuBarWidth, ubarHeight);
	}
	else
	{
		iSetColor(255, 165, 165);
		iFilledRectangle(ubarX, ubarY, ubarWidth, ubarHeight);
	}
}

//peter movement
void peterMovement()
{
	if (jump && RIGHT == false && LEFT == false)
	{
		if (jumpUp)
		{
			iShowImage(x, y + peterCordinateJump, peterWidth, peterHeight, peterJump[0]);

		}
		else
		{
			iShowImage(x, y + peterCordinateJump, peterWidth - 15, peterHeight - 15, peterJump[1]);
		}
	}
	if (jump)
	{
		if (jumpUp == true && RIGHT == true)
		{
			iShowImage(x, y + peterCordinateJump, peterWidth, peterHeight, peterJump[0]);
		}
		else if (jumpUp == false && RIGHT == true)
		{
			iShowImage(x, y + peterCordinateJump, peterWidth, peterHeight, peterJump[1]);
		}

		if (jumpUp == true && LEFT == true)
		{
			iShowImage(x, y + peterCordinateJump, peterWidth, peterHeight, peterJump1[0]);
		}
		else if (jumpUp == false && LEFT == true)
		{
			iShowImage(x, y + peterCordinateJump, peterWidth - 20, peterHeight - 20, peterJump1[1]);
		}
	}
	else
	{
		if (stand)
		{
			iShowImage(x, y, peterWidth, peterHeight, peterStand[sindex]);
		}

		else if (!stand && RIGHT == true)
		{
			ulti = false;
			iShowImage(x, y, peterWidth, peterHeight, peterRun1[r1index]);

			standCounter++;

			if (standCounter >= 200)
			{
				standCounter = 0;
				r1index = 0;
				stand = true;
				RIGHT = false;
			}

		}

		else if (!stand && LEFT == true)
		{
			ulti = false;
			iShowImage(x, y, peterWidth, peterHeight, peterRun2[r2index]);

			standCounter++;

			if (standCounter >= 180)
			{
				standCounter = 0;
				r2index = 0;
				stand = true;
				LEFT = false;
			}
		}

		else if (!stand && pun)
		{
			ulti = false;
			iShowImage(x, y, peterWidth, peterHeight - 15, punch[punchIndex]);
			standCounter++;
			if (standCounter >= 200)
			{
				standCounter = 0;
				punchIndex = 0;
				stand = true;
				pun = false;
			}
		}

		else if (!stand && kic)
		{
			ulti = false;
			iShowImage(x, y, peterWidth, peterHeight - 15, kick[kickIndex]);
			standCounter++;
			if (standCounter >= 200)
			{
				standCounter = 0;
				punchIndex = 0;
				stand = true;
				kic = false;
			}
		}

		else if (!stand && bloc)
		{
			ulti = false;
			iShowImage(x, y, peterWidth + 140, peterHeight, block);
			standCounter++;
			if (standCounter >= 600)
			{
				standCounter = 0;
				blockIndex = 0;
				stand = true;
				bloc = false;
			}
		}

		else if (!stand && movebg)
		{
			standCounter++;
			if (standCounter >= 150)
			{
				standCounter = 0;
				punchIndex = 0;
				stand = true;
				movebg = false;
			}
		}

		else if (!stand && ulti && uBar >= 100)
		{
			iShowImage(x, y, peterWidth, peterHeight, ult);
			standCounter++;
			if (standCounter >= 700)
			{
				standCounter = 0;
				ultIndex = 0;
				stand = true;
				ulti = false;
			}
		}

	}
}

/*__________________________________________web________________________________________*/

void setWebVariables()
{
	for (int i = 0; i < webNumber; i++)
	{
		webs[i].webX = x;
		webs[i].webY = y + 35;
		webs[i].webIndex = 0;
		webs[i].webShow = true;
	}
}
void webMovement()
{
	if (ulti && uBar >= 100)
	{
		for (int i = 0; i < webNumber; i++)
		{
			if (webs[i].webShow)
			{
				iShowImage(webs[i].webX, webs[i].webY, 57, 54, web[webs[i].webIndex]);
			}
		}
	}
}

/*_________________________________________________Health ORB DEFINITIONS____________________________________________________________*/
void rsethOrbVariables()
{
	for (int i = 0; i < dOrbNumber; i++)
	{
		horb[i].hOrb_x = screenWidth;
		horb[i].hOrb_y = screenHeight - 200;
		horb[i].hOrbIndex = rand() % 5;
		horb[i].hOrbShow = true;
	}
}
void collisioncheck4()
{
	for (int i = 0; i < dOrbNumber; i++)
	{
		if (x + peterWidth >= horb[i].hOrb_x && x <= horb[i].hOrb_x + 80 && y + peterHeight + peterCordinateJump > horb[i].hOrb_y && y < horb[i].hOrb_y + 80)
		{
			if (horb[i].hOrbShow)
			{
				horb[i].hOrbShow = false;
				rsethOrbVariables();
				spidermanHealth += 90;
			}
		}

	}
}
void rhOrbsMovement() ///for animation
{
	for (int i = 0; i < dOrbNumber; i++)
	{
		if (horb[i].hOrbShow)
		{
			iShowImage(horb[i].hOrb_x, horb[i].hOrb_y, 80, 80, Horb[horb[i].hOrbIndex]);
		}
	}
}

/*_________________________________________________Dimensional ORB DEFINITIONS____________________________________________________________*/
void rsetOrbVariables()
{
	for (int i = 0; i < dOrbNumber; i++)
	{
		dorb[i].dOrb_x = screenWidth;
		dorb[i].dOrb_y = screenHeight - 300;
		dorb[i].dOrbIndex = rand() % 5;
		dorb[i].dOrbShow = true;
	}
}
void collisioncheck3()
{
	for (int i = 0; i < dOrbNumber; i++)
	{
		if (x + peterWidth >= dorb[i].dOrb_x && x <= dorb[i].dOrb_x + 80 && y + peterHeight + peterCordinateJump > dorb[i].dOrb_y && y < dorb[i].dOrb_y + 80)
		{
			if (dorb[i].dOrbShow)
			{
				score += 5;
				dorb[i].dOrbShow = false;
				rsetOrbVariables();
				dBar += 20;
			}
		}

	}
}
void rOrbsMovement() ///for animation
{
	for (int i = 0; i < dOrbNumber; i++)
	{
		if (dorb[i].dOrbShow)
		{
			iShowImage(dorb[i].dOrb_x, dorb[i].dOrb_y, 80, 80, orb[dorb[i].dOrbIndex]);
		}
	}
}

/*_________________________________________________Ultimate ORB DEFINITIONS____________________________________________________________*/
void rsetuOrbVariables()
{
	for (int i = 0; i < dOrbNumber; i++)
	{
		uorb[i].uOrb_x = screenWidth;
		uorb[i].uOrb_y = screenHeight - 400;
		uorb[i].uOrbIndex = rand() % 5;
		uorb[i].uOrbShow = true;
	}
}
void collisioncheck5()
{
	for (int i = 0; i < dOrbNumber; i++)
	{
		if (x + peterWidth >= uorb[i].uOrb_x && x <= uorb[i].uOrb_x + 80 && y + peterHeight + peterCordinateJump > uorb[i].uOrb_y && y < uorb[i].uOrb_y + 80)
		{
			if (uorb[i].uOrbShow)
			{
				score += 5;
				uorb[i].uOrbShow = false;
				rsetuOrbVariables();
				uBar += 20;
			}
		}

	}
}
void ruOrbsMovement() ///for animation
{
	for (int i = 0; i < dOrbNumber; i++)
	{
		if (uorb[i].uOrbShow)
		{
			iShowImage(uorb[i].uOrb_x, uorb[i].uOrb_y, 80, 80, Uorb[uorb[i].uOrbIndex]);
		}
	}
}

/*________________________________________________thug-1_____________________________________________*/
void enemyMovement()
{
	for (int i = 0; i < thug1Number; i++)
	{
		if (enemy[i].thugShow)
		{
			iShowImage(enemy[i].thugX, enemy[i].thugY, peterWidth, peterHeight, thugRun[enemy[i].thugIndex]);
		}
	}
}

/*________________________________________________thug-2_____________________________________________*/
void enemy2Movement()
{
	for (int i = 0; i < thug2Number; i++)
	{
		if (enemy2[i].bullShow)
		{
			iShowImage(enemy2[i].bullX, enemy2[i].bullY, peterWidth, peterHeight, thug2Run[enemy2[i].bullIndex]);
		}
	}
}
void setFireVariables()
{
	for (int i = 0; i < fireNumber; i++)
	{
		fire[i].fireX = enemy2[i].bullX - 100;
		fire[i].fireY = 165;
		fire[i].fireIndex = rand() % 1;
		fire[i].fireShow = true;
	}
}
void checkCollision()
{
	//for video
	index++;
	if (index >= 20)
	{
		index = 0;
	}
	
	//for thug1
	for (int i = 0; i < thug1Number; i++)
	{
		if (!enemy[i].thugShow)
		{
			enemy[i].thugX = screenWidth + (i * peterWidth);
			enemy[i].thugY = y;
			enemy[i].thugIndex = rand() % 3;
			enemy[i].thugHealth = 100;
			enemy[i].thugShow = true;
		}
	}

	for (int i = 0; i < thug1Number; i++)
	{
		if ((x + peterWidth > enemy[i].thugX && enemy[i].thugX + peterWidth > x) &&
			(y + peterHeight > enemy[i].thugY && enemy[i].thugY + peterHeight > y))
		{
			//printf("collision");
			if (enemy[i].thugShow)
			{
				if (pun)
				{
					if (flag == 1){
						score += 5;
					}//-----------------------------//
					enemy[i].thugHealth -= 20;
					if (enemy[i].thugHealth <= 0)
					{
						// Enemy is killed, reset its position
						if (enemy[i].thugHealth == 0)
						{
							enemy[i].thugShow = false;
						}
						enemy[i].thugX = screenWidth + (i * peterWidth);
						enemy[i].thugY = y;
						enemy[i].thugIndex = rand() % 3;
						enemy[i].thugHealth = 100;
						enemy[i].thugShow = true;
					}

				}

				else if (kic)
				{
					if (flag == 1){
						score += 10;
					}//-----------------------------//
					enemy[i].thugHealth -= 40;

					if (enemy[i].thugHealth <= 0)
					{
						// Enemy is killed, reset its position
						if (enemy[i].thugHealth == 0)
						{
							enemy[i].thugShow = false;
						}
						enemy[i].thugX = screenWidth + (i * peterWidth);
						enemy[i].thugY = y;
						enemy[i].thugIndex = rand() % 3;
						enemy[i].thugHealth = 100;
						enemy[i].thugShow = true;
					}

				}
			}
		}

	}

	// for thug2
	for (int i = 0; i < thug2Number; i++)
	{
		if (!enemy2[i].bullShow)
		{
			enemy2[i].bullX = screenWidth + rand() % 800;
			enemy2[i].bullY = 75;
			enemy2[i].bullIndex = rand() % 3;
			enemy2[i].bullHealth = 100;
			enemy2[i].bullShow = true;
		}
	}

	for (int i = 0; i < thug2Number; i++)
	{
		if ((x + peterWidth > enemy2[i].bullX && enemy2[i].bullX + peterWidth > x) &&
			(y + peterHeight > enemy2[i].bullY && enemy2[i].bullY + peterHeight > y))
			
		{
			//printf("collision2");
			if (enemy2[i].bullShow)
			{
				
				if (pun)
				{
					if(flag==1)
					{	
						score += 10;
					}//-----------------------------//
					enemy2[i].bullHealth -= 20;
					if (enemy2[i].bullHealth <= 0)
					{

						if (enemy2[i].bullHealth == 0)
						{
							enemy2[i].bullShow = false;
						}
						enemy2[i].bullX = screenWidth + rand() % 800;
						enemy2[i].bullY = 75;
						enemy2[i].bullIndex = rand() % 3;
						enemy2[i].bullHealth = 100;
						enemy2[i].bullShow = true;

					}

				}

				else if (kic)
				{
					if (flag == 1){
						score += 15;
					}
					//-----------------------------//
					enemy2[i].bullHealth -= 40;

					if (enemy2[i].bullHealth <= 0)
					{

						if (enemy2[i].bullHealth == 0)
						{
							enemy2[i].bullShow = false;
						}
						enemy2[i].bullX = screenWidth + (i * peterWidth);
						enemy2[i].bullY = 75;
						enemy2[i].bullIndex = rand() % 3;
						enemy2[i].bullHealth = 100;
						enemy2[i].bullShow = true;
					}

				}
			}
		}

	}

	//for rhino
	if ((x2 + peterWidth >= rx && rx + rhinoWidth >= x2) && (y2 + peterHeight >= ry && ry + rhinoHeight >= ry))
	{

		if (pun2 && !rhinoJump && !jump2)
		{
			if (flag== 2){
				score += 10;
			}
		//-----------------------------//
			rhinoHealth -= 5;
			//printf("punch");
		}

		else if (kic2 && !rhinoJump && !jump2)
		{
			if (flag==2){
				score += 15;
			}//-----------------------------//
			rhinoHealth -= 10;
			//printf("kick");
		}

	}

	for (int i = 0; i < 5; i++)
	{
		if ((webs2[i].webX2 + 57 >= rx && webs2[i].webX2 <= rx + rhinoWidth) && (webs2[i].webY2 + 50 >= ry && webs2[i].webY2 <= ry + rhinoHeight))
		{
			if (ulti2 && !rhinoJump && !jump2)
			{
				if (flag == 2){
					score += 5;
				}//-----------------------------//
				rhinoHealth -= 10;
			}
		}
	}

	if ((rx + rhinoWidth >= x2 && x2 + peterWidth >= rx) && (ry + rhinoHeight >= y2 && y2 + peterHeight >= ry))
	{

		if (rhinoPun && !jump2 && !bloc2 && !rhinoJump)
		{
			spidermanHealth2 -= 5;
			//printf("punch");
		}

		else if (rhinoKic && !jump2 && !bloc2 && !rhinoJump)
		{
			spidermanHealth2 -= 10;
			//printf("kick");
		}


		else if (rhinoUlti && !jump2 && !bloc2 && !rhinoJump)
		{
			spidermanHealth2 -= 20;
		}

	}

	//for thug1
	for (int i = 0; i < thug1Number; i++)
	{
		if (!enemy3[i].thugShow3)
		{
			enemy3[i].thugX3 = screenWidth + (i * peterWidth);
			enemy3[i].thugY3 = y3;
			enemy3[i].thugIndex3 = rand() % 3;
			enemy3[i].thugHealth3 = 100;
			enemy3[i].thugShow3 = true;
		}
	}

	for (int i = 0; i < thug1Number; i++)
	{
		if ((x3 + peterWidth > enemy3[i].thugX3 && enemy3[i].thugX3 + peterWidth > x3) &&
			(y3 + peterHeight > enemy3[i].thugY3 && enemy3[i].thugY3 + peterHeight > y3))
		{
			if (enemy3[i].thugShow3)
			{
				if (pun3)
				{
					if (flag == 3){
						score += 5;
					}//-----------------------------//
					enemy3[i].thugHealth3 -= 20;
					if (enemy3[i].thugHealth3 <= 0)
					{
						// Enemy is killed, reset its position
						if (enemy3[i].thugHealth3 == 0)
						{
							enemy3[i].thugShow3 = false;
						}
						enemy3[i].thugX3 = screenWidth + (i * peterWidth);
						enemy3[i].thugY3 = y3;
						enemy3[i].thugIndex3 = rand() % 3;
						enemy3[i].thugHealth3 = 100;
						enemy3[i].thugShow3 = true;
					}

				}

				else if (kic3)
				{
					if (flag==3){
						score += 10;
					}
					//-----------------------------//
					enemy3[i].thugHealth3 -= 40;

					if (enemy3[i].thugHealth3 <= 0)
					{
						// Enemy is killed, reset its position
						if (enemy3[i].thugHealth3 == 0)
						{
							enemy3[i].thugShow3 = false;
						}
						enemy3[i].thugX3 = screenWidth + (i * peterWidth);
						enemy3[i].thugY3 = y3;
						enemy3[i].thugIndex3 = rand() % 3;
						enemy3[i].thugHealth3 = 100;
						enemy3[i].thugShow3 = true;
					}

				}
			}
		}

	}

	// for thug2
	for (int i = 0; i < thug2Number; i++)
	{
		if (!enemy23[i].bullShow3)
		{
			enemy23[i].bullX3 = screenWidth + rand() % 800;
			enemy23[i].bullY3 = y3;
			enemy23[i].bullIndex3 = rand() % 3;
			enemy23[i].bullHealth3 = 100;
			enemy23[i].bullShow3 = true;
		}
	}

	for (int i = 0; i < thug2Number; i++)
	{
		if ((x3 + peterWidth > enemy23[i].bullX3 && enemy23[i].bullX3 + peterWidth > x3) &&
			(y3 + peterHeight > enemy23[i].bullY3 && enemy23[i].bullY3 + peterHeight > y3))
		{
			if (enemy23[i].bullShow3)
			{

				if (pun3)
				{
					if (flag == 3){
						score += 10;
					}//-----------------------------//
					enemy23[i].bullHealth3 -= 20;
					if (enemy23[i].bullHealth3 <= 0)
					{

						if (enemy23[i].bullHealth3 == 0)
						{
							enemy23[i].bullShow3 = false;
						}
						enemy23[i].bullX3 = screenWidth + rand() % 800;
						enemy23[i].bullY3 = y3;
						enemy23[i].bullIndex3 = rand() % 3;
						enemy23[i].bullHealth3 = 100;
						enemy23[i].bullShow3 = true;

					}

				}

				else if (kic3)
				{
					if (flag == 3)
					{
						score += 15;
					}//-----------------------------//
					enemy23[i].bullHealth3 -= 40;

					if (enemy23[i].bullHealth3 <= 0)
					{

						if (enemy23[i].bullHealth3 == 0)
						{
							enemy23[i].bullShow3 = false;
						}
						enemy23[i].bullX3 = screenWidth + (i * peterWidth);
						enemy23[i].bullY3 = 75;
						enemy23[i].bullIndex3 = rand() % 3;
						enemy23[i].bullHealth3 = 100;
						enemy23[i].bullShow3 = true;
					}

				}
			}
		}

	}

	if ((x4 + peterWidth >= kx && kx + kravenWidth >= x4) && (y4 + peterHeight >= ky && ky + kravenHeight >= y4))
	{

		if (pun4 && !kravenJump && !jump4)
		{
			if (flag == 4){
				score += 5;
			}//-----------------------------//
			kravenHealth -= 5;
			printf("punch");
		}

		else if (kic4 && !kravenJump && !jump4)
		{
			if (flag == 4){
				score += 10;
			}//-----------------------------//
			kravenHealth -= 10;
			printf("kick");
		}

	}

	for (int i = 0; i < 5; i++)
	{
		if ((webs4[i].webX4 + 57 >= kx && webs4[i].webX4 <= kx + kravenWidth) && (webs4[i].webY4 + 50 >= ky && webs4[i].webY4 <= ky + kravenHeight))
		{
			if (ulti4 && !kravenJump && !jump4)
			{
				if (flag == 4){
					score += 5;
				}
				kravenHealth -= 10;
			}
		}
	}

	if ((kx + kravenWidth >= x4 && x4 + peterWidth >= kx) && (ky + kravenHeight >= y4 && y4 + peterHeight >= ky))
	{

		if (kravenPun && !jump4 && !bloc4 && !kravenJump)
		{
			spidermanHealth4 -= 15;
			//printf("punch");
		}

		else if (kravenKic && !jump4 && !bloc4 && !kravenJump)
		{
			spidermanHealth4 -= 20;
			//printf("kick");
		}


		else if (kravenUlti && !jump4 && !bloc4 && !kravenJump)
		{
			spidermanHealth4 -= 25;
		}

	}

	//for thuugfiring
	for (int i = 0; i<fireNumber; i++)
	{
		if ((x + peterWidth >= fire[i].fireX && x <= fire[i].fireX + 198) &&
			(y + peterHeight >= fire[i].fireY &&  y <= fire[i].fireY + 93))
		{
			if (thugUlt && !jump && !bloc)
			{
				spidermanHealth -= 10;
				fire[i].fireShow = false;
				setFireVariables();
			}
			//thugUlt = false;

		}
	}

	for (int i = 0; i<fireNumber; i++)
	{
		if ((x3 + peterWidth >= fire3[i].fireX3 && x3 <= fire3[i].fireX3 + 198) &&
			(y3 + peterHeight >= fire3[i].fireY3 &&  y3 <= fire3[i].fireY3 + 93))
		{
			if (thugUlt3 && !jump3 && !bloc3)
			{
				spidermanHealth3 -= 10;
				fire3[i].fireShow3 = false;
				setFireVariables3();
			}
			//thugUlt = false;

		}
	}


	//for dr dooom
	if ((x5 + peterWidth >= msx && msx + mysterioWidth >= x5) && (y5 + peterHeight >= msy && msy + mysterioHeight >= y5))
	{

		if (pun5 && !mysterioJump && !jump5)
		{
			if (flag == 5){
				score += 10;
			}
			mysterioHealth -= 5;
			printf("punch");
		}

		else if (kic5 && !mysterioJump && !jump5)
		{
			if (flag == 5){
				score += 15;
			}
			mysterioHealth -= 10;
			printf("kick");
		}

	}

	for (int i = 0; i < 5; i++)
	{
		if ((webs5[i].webX5 + 57 >= msx && webs5[i].webX5 <= msx + mysterioWidth) && (webs5[i].webY5 + 50 >= msy && webs5[i].webY5 <= msy + mysterioHeight))
		{
			if (ulti5 && !mysterioJump && !jump5)
			{
				if (flag == 5){
					score += 5;
				}
				mysterioHealth -= 10;
			}
		}
	}

	if ((msx + mysterioWidth >= x5 && x5 + peterWidth >= msx) && (msy + mysterioHeight >= y5 && y5 + peterHeight >= msy))
	{

		if (mysterioPun && !jump5 && !bloc5 && !mysterioJump)
		{
			spidermanHealth5 -= 15;
			//printf("punch");
		}

		else if (mysterioKic && !jump5 && !bloc5 && !mysterioJump)
		{
			spidermanHealth5 -= 20;
			//printf("kick");
		}


		else if (mysterioUlti && !jump5 && !bloc5 && !mysterioJump)
		{
			spidermanHealth5 -= 25;
		}



	}
}
void webCollision()
{
	//for thug1
	for (int i = 0; i < thug1Number; i++)
	{
		if (!enemy[i].thugShow)
		{
			enemy[i].thugX = screenWidth + (i * peterWidth);
			enemy[i].thugY = y;
			enemy[i].thugIndex = rand() % 3;
			enemy[i].thugHealth = 100;
			enemy[i].thugShow = true;
		}
		for (int i = 0; i < thug1Number; i++)
		{
			if ((webs[i].webX + 57 >= enemy[i].thugX && webs[i].webX <= enemy[i].thugX + peterWidth) &&
				(webs[i].webY + 50 >= enemy[i].thugY && webs[i].webY <= enemy[i].thugX + peterHeight))
			{
				if (enemy[i].thugShow)
				{
					if (ulti)
					{
						enemy[i].thugShow = false;
						enemy[i].thugX = screenWidth + (i * peterWidth);
						enemy[i].thugY = y;
						enemy[i].thugIndex = rand() % 3;
						enemy[i].thugShow = true;
					}
				}
			}
		}
	}

	//for thug2
	for (int i = 0; i < thug2Number; i++)
	{
		if (!enemy2[i].bullShow)
		{
			enemy2[i].bullX = screenWidth + (i * peterWidth);
			enemy2[i].bullY = 75;
			enemy2[i].bullIndex = rand() % 3; 
			enemy2[i].bullHealth = 100; 
			enemy2[i].bullShow = true;
		}
		for (int i = 0; i < thug2Number; i++)
		{
			if ((webs[i].webX + 57 >= enemy2[i].bullX && webs[i].webX <= enemy2[i].bullX + peterWidth) && (webs[i].webY + 50 >= enemy2[i].bullY && webs[i].webY <= enemy2[i].bullX + peterHeight))
			{
				if (enemy2[i].bullShow)
				{
					if (ulti)
					{
						enemy2[i].bullShow = false;
						enemy2[i].bullX = screenWidth + (i * peterWidth);
						enemy2[i].bullY = 75;
						enemy2[i].bullIndex = rand() % 3;
						enemy2[i].bullShow = true;
						//numSpawnedThugs++;
					}
				}
			}
		}
	}



	//for thug1
	for (int i = 0; i < thug1Number; i++)
	{
		if (!enemy3[i].thugShow3)
		{
			enemy3[i].thugX3 = screenWidth + (i * peterWidth);
			enemy3[i].thugY3 = y3;
			enemy3[i].thugIndex3 = rand() % 3;
			enemy3[i].thugHealth3 = 100;
			enemy3[i].thugShow3 = true;
		}
		for (int i = 0; i < thug1Number; i++)
		{
			if ((webs3[i].webX3 + 57 >= enemy3[i].thugX3 && webs3[i].webX3 <= enemy3[i].thugX3 + peterWidth) &&
				(webs3[i].webY3 + 50 >= enemy3[i].thugY3 && webs3[i].webY3 <= enemy3[i].thugX3 + peterHeight))
			{
				if (enemy3[i].thugShow3)
				{
					if (ulti3)
					{
						enemy3[i].thugShow3 = false;
						enemy3[i].thugX3 = screenWidth + (i * peterWidth);
						enemy3[i].thugY3 = y3;
						enemy3[i].thugIndex3 = rand() % 3;
						enemy3[i].thugShow3 = true;
					}
				}
			}
		}
	}

	//for thug2
	for (int i = 0; i < thug2Number; i++)
	{
		if (!enemy23[i].bullShow3)
		{
			enemy23[i].bullX3 = screenWidth + (i * peterWidth);
			enemy23[i].bullY3 = y3;
			enemy23[i].bullIndex3 = rand() % 3; 
			enemy23[i].bullHealth3 = 100; 
			enemy23[i].bullShow3 = true;
		}
		for (int i = 0; i < thug2Number; i++)
		{
			if ((webs3[i].webX3 + 57 >= enemy23[i].bullX3 && webs3[i].webX3 <= enemy23[i].bullX3 + peterWidth) && (webs3[i].webY3 + 50 >= enemy23[i].bullY3 && webs3[i].webY3 <= enemy23[i].bullX3 + peterHeight))
			{
				if (enemy23[i].bullShow3)
				{
					if (ulti3)
					{
						enemy23[i].bullShow3 = false;
						enemy23[i].bullX3 = screenWidth + (i * peterWidth);
						enemy23[i].bullY3 = y3;
						enemy23[i].bullIndex3 = rand() % 3;
						enemy23[i].bullShow3 = true;
						//numSpawnedThugs++;
					}
				}
			}
		}
	}

}
void thugHealthBars()
{
	int barWidth = 50;
	int barHeight = 10; 
	int barYOffset = 20;

	for (int i = 0; i < thug1Number; i++)
	{
		if (enemy[i].thugShow)
		{
			int barX = enemy[i].thugX + (peterWidth - barWidth) / 2;
			int barY = enemy[i].thugY + peterHeight + barYOffset;

			int healthBarWidth = (enemy[i].thugHealth * barWidth) / 100; 

			iSetColor(255, 0, 0); 
			iFilledRectangle(barX, barY, barWidth, barHeight);


			iSetColor(0, 255, 0); 
			iFilledRectangle(barX, barY, healthBarWidth, barHeight);
		}
	}

	
	for (int i = 0; i < thug2Number; i++)
	{
		if (enemy2[i].bullShow)
		{
			int barX = enemy2[i].bullX + (peterWidth - barWidth) / 2;
			int barY = enemy2[i].bullY + peterHeight + barYOffset;

			int healthBarWidth = (enemy2[i].bullHealth * barWidth) / 100; 

			iSetColor(255, 0, 0);
			iFilledRectangle(barX, barY, barWidth, barHeight);

			iSetColor(0, 255, 0); 
			iFilledRectangle(barX, barY, healthBarWidth, barHeight);
		}
	}
}

/*__________________________________________fire________________________________________*/

void fireMovement()
{
	if (thugUlt)
	{
		for (int i = 0; i < fireNumber; i++)
		{
			if (fire[i].fireShow)
			{
				iShowImage(fire[i].fireX, fire[i].fireY, 198, 93, firing);
			}
		}
	}
}
void collisioncheck1()
{

	
}

//_______________________BG associated methods________________________//
void setAll()
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		mainbg[i].y = 0;
		mainbg[i].x = sum;
		sum += screenWidth;
	}
	
}


void changex()
{
	//for level1
	if (RIGHT || (jump && jumpR))
	{
		movebg = true;

		if (!stand)
		{
			for (int i = 0; i < 5; i++)
			{
				mainbg[i].x -= bgSpeed;
				if (mainbg[i].x <= -screenWidth)
				{
					mainbg[i].x = screenWidth;
				}
			}
		}
	}
	else if (LEFT || (jump && jumpL))
	{
		movebg = true;

		if (!stand)
		{
			for (int i = 0; i < 5; i++)
			{
				mainbg[i].x += bgSpeed;
				if (mainbg[i].x >= screenWidth)
				{
					mainbg[i].x = - screenWidth;
				}
			}
		}
	}
	else
	{
		movebg = false;
	}


	//for jumping
	if (jump)
	{
		kic = false;
		pun = false;
		if (jumpUp)
		{
			peterCordinateJump += 5;
			if (peterCordinateJump >= jumplimit)
			{
				jumpUp = false;

			}
		}

		else
		{
			peterCordinateJump -= 5;
			if (peterCordinateJump < 0)
			{
				jump = false;
			}
		}
	}


	//for level2
	if (RIGHT2 || (jump2 && jumpR2))
	{
		movebg2 = true;

		if (!stand2)
		{
			for (int i = 0; i < 5; i++)
			{
				mainbg2[i].x2 -= bgSpeed2;
				if (mainbg2[i].x2 <= -screenWidth)
				{
					mainbg2[i].x2 = +screenWidth;
				}
			}
		}
	}
	else if (LEFT2 || (jump2 && jumpL2))
	{
		movebg2 = true;

		if (!stand2)
		{
			for (int i = 0; i < 5; i++)
			{
				mainbg2[i].x2 += bgSpeed2;
				if (mainbg2[i].x2 >= screenWidth)
				{
					mainbg2[i].x2 = -screenWidth;
				}
			}
		}
	}
	else
	{
		movebg2 = false;
	}

	if (jump2)
	{
		if (jumpUp2)
		{
			peterCordinateJump2 += 5;
			if (peterCordinateJump2 >= jumplimit)
			{
				jumpUp2 = false;

			}
		}

		else
		{
			peterCordinateJump2 -= 5;
			if (peterCordinateJump2 < 0)
			{
				jump2 = false;
			}
		}
	}

	if (rhinoJump)
	{
		if (rhinoJumpUp)
		{
			rhinoCordinateJump += 5;
			if (rhinoCordinateJump >= jumplimit)
			{
				rhinoJumpUp = false;

			}
		}

		else
		{
			rhinoCordinateJump -= 5;
			if (rhinoCordinateJump < 0)
			{
				rhinoJump = false;
			}
		}
	}

	if (rhinoLEFT)
	{
		if (rx >= 0)
		{
			rx = rx - 8;
		}
		rhino2index++;
		if (rhino2index >= 9)
		{
			rhino2index = 0;
		}
		rhiStand = false;
		rhinoRIGHT = false;
		rhinoJumper = false;
		rhinoJumpL = true;
		rhinoJumpR = false;
	}

	if (rhinoRIGHT)
	{
		if (rx + 180 <= screenWidth)
		{
			rx = rx + 8;
		}
		rhino1index++;
		if (rhino1index >= 9)
		{
			rhino1index = 0;
		}
		rhiStand = false;
		rhinoLEFT = false;
		rhinoJumpR = true;
		rhinoJumpL = false;
	}
	if (rhinoUlti)
	{
		if (rx >= 0)
		{
			rx = rx - 30;
		}

		else if (rx <= 0)
		{
			rx = screenWidth;
		}

		rhinoUltIndex++;
		if (rhinoUltIndex >= 3)
		{
			rhinoUltIndex = 0;
		}
		rhiStand = false;
		rhinoJumper = false;
		rhinoJumpL = true;
		rhinoJumpR = false;

	}


	//for level4
	if (kravenRIGHT)
	{
		//if (kx + 180 <= screenWidth)
		//{
		kx = kx - 8;
		//}
		kraven1index++;
		if (kraven1index >= 6)
		{
			kraven1index = 0;
		}
		kraStand = false;
		kravenLEFT = false;
		kravenJumpR = true;
		kravenJumpL = false;
		kravenUlti = false;
		kravenPun = false;
		kravenKic = false;
	}

	if (kravenLEFT)
	{
		//if (kx >= 0)
		//{
		kx = kx + 8;
		//}


		kraven2index++;
		if (kraven2index >= 6)
		{
			kraven2index = 0;
		}
		kraStand = false;
		kravenRIGHT = false;
		kravenJumper = false;
		kravenJumpL = true;
		kravenJumpR = false;
		kravenUlti = false;
		kravenPun = false;
		kravenKic = false;
	}

	//for level4
	if (mysterioRIGHT)
	{
		//if (mx + 180 <= screenWidth)
		//{
		msx = msx - 8;
		//}
		mysterio1index++;
		if (mysterio1index >= 6)
		{
			mysterio1index = 0;
		}
		mysStand = false;
		mysterioLEFT = false;
		mysterioJumpR = true;
		mysterioJumpL = false;
		mysterioUlti = false;
		mysterioPun = false;
		mysterioKic = false;
	}

	if (mysterioLEFT)
	{
		//if (mx >= 0)
		//{
		msx = msx + 8;
		//}


		mysterio2index++;
		if (mysterio2index >= 6)
		{
			mysterio2index = 0;
		}
		mysStand = false;
		mysterioRIGHT = false;
		mysterioJumper = false;
		mysterioJumpL = true;
		mysterioJumpR = false;
		mysterioUlti = false;
		mysterioPun = false;
		mysterioKic = false;
	}
	//level3
	// Bg remove snippets
	if (RIGHT3 || (jump3 && jumpR3))
	{
		movebg3 = true;

		if (!stand3)
		{
			for (int i = 0; i < n3; i++)
			{
				mainbg3[i].x3 -= bgSpeed3;
				if (mainbg3[i].x3 <= -screenWidth)
				{
					mainbg3[i].x3 = screenWidth;
				}
			}
		}
	}
	else if (LEFT3 || (jump3 && jumpL3))
	{
		movebg3 = true;

		if (!stand3)
		{
			for (int i = 0; i < n3; i++)
			{
				mainbg3[i].x3 += bgSpeed3;
				if (mainbg3[i].x3 >= screenWidth)
				{
					mainbg3[i].x3 = -screenWidth;
				}
			}
		}
	}
	else
	{
		movebg3 = false;
	}


	//for jumping
	if (jump3)
	{
		kic3 = false;
		pun3 = false;
		if (jumpUp3)
		{
			peterCordinateJump3 += 5;
			if (peterCordinateJump3 >= jumplimit)
			{
				jumpUp3 = false;

			}
		}

		else
		{
			peterCordinateJump3 -= 5;
			if (peterCordinateJump3 < 0)
			{
				jump3 = false;
			}
		}
	}

	//for level4
	
	if (RIGHT4 || (jump4 && jumpR4))
	{
		movebg4 = true;

		if (!stand4)
		{
			for (int i = 0; i < n4; i++)
			{
				mainbg4[i].x4 -= bgSpeed4;
				if (mainbg4[i].x4 <= -screenWidth)
				{
					mainbg4[i].x4 = +screenWidth;
				}
			}
		}
	}
	else if (LEFT4 || (jump4 && jumpL4))
	{
		movebg4 = true;

		if (!stand4)
		{
			for (int i = 0; i < n4; i++)
			{
				mainbg4[i].x4 += bgSpeed4;
				if (mainbg4[i].x4 >= screenWidth)
				{
					mainbg4[i].x4 = -screenWidth;
				}
			}
		}
	}
	else
	{
		movebg4 = false;
	}

	if (jump4)
	{
		if (jumpUp4)
		{
			peterCordinateJump4 += 5;
			if (peterCordinateJump4 >= jumplimit)
			{
				jumpUp4 = false;

			}
		}

		else
		{
			peterCordinateJump4 -= 5;
			if (peterCordinateJump4 < 0)
			{
				jump4 = false;
			}
		}
	}

	if (kravenJump)
	{
		if (kravenJumpUp)
		{
			kravenCordinateJump += 5;
			if (kravenCordinateJump >= jumplimit)
			{
				kravenJumpUp = false;

			}
		}

		else
		{
			kravenCordinateJump -= 5;
			if (kravenCordinateJump < 0)
			{
				kravenJump = false;
			}
		}
	}
	//level5
	
	if (RIGHT5 || (jump5 && jumpR5))
	{
		movebg5 = true;

		if (!stand5)
		{
			for (int i = 0; i < n5; i++)
			{
				mainbg5[i].x5 -= bgSpeed5;
				if (mainbg5[i].x5 <= -screenWidth)
				{
					mainbg5[i].x5 = +screenWidth;
				}
			}
		}
	}
	else if (LEFT5 || (jump5 && jumpL5))
	{
		movebg5 = true;

		if (!stand5)
		{
			for (int i = 0; i < n5; i++)
			{
				mainbg5[i].x5 += bgSpeed5;
				if (mainbg5[i].x5 >= screenWidth)
				{
					mainbg5[i].x5 = -screenWidth;
				}
			}
		}
	}
	else
	{
		movebg5 = false;
	}

	if (jump5)
	{
		if (jumpUp5)
		{
			peterCordinateJump5 += 5;
			if (peterCordinateJump5 >= jumplimit)
			{
				jumpUp5 = false;

			}
		}

		else
		{
			peterCordinateJump5 -= 5;
			if (peterCordinateJump5 < 0)
			{
				jump5 = false;
			}
		}
	}

	if (mysterioJump)
	{
		if (mysterioJumpUp)
		{
			mysterioCordinateJump += 5;
			if (mysterioCordinateJump >= jumplimit)
			{
				mysterioJumpUp = false;

			}
		}

		else
		{
			mysterioCordinateJump -= 5;
			if (mysterioCordinateJump < 0)
			{
				mysterioJump = false;
			}
		}
	}
}

//_______________________peter associated methods________________________//
void stan()
{
	sindex++;
	if (sindex >= 3)
	{
		sindex = 0;
	}
	int xyz = 10;
	for (int i = 0; i < thug1Number; i++)
	{

		enemy[i].thugX -= xyz;
		xyz += 15;
		//cout << enemy[i].thugX << endl;
		if (enemy[i].thugX <= 0)
		{
			enemy[i].thugX = screenWidth;
		}
		if (enemy[i].thugX == 800 && ctr)
		{
			spidermanHealth -= 50;

		}

		enemy[i].thugIndex++;
		if (enemy[i].thugIndex >= 3)
		{
			enemy[i].thugIndex = 0;
		}
	}


	for (int i = 0; i < thug2Number; i++)
	{
		enemy2[i].bullX -= 15;
		//cout << enemy[i].thugX << endl;
		if (enemy2[i].bullX <= 0)
		{
			enemy2[i].bullX = screenWidth;
		}

		enemy2[i].bullIndex++;
		if (enemy2[i].bullIndex >= 3)
		{
			enemy2[i].bullIndex = 0;
		}
	}


	//level3
	sindex3++;
	if (sindex3 >= 3)
	{
		sindex3 = 0;
	}
	int xyz3 = 10;
	for (int i = 0; i < thug1Number; i++)
	{

		enemy3[i].thugX3 -= xyz3;
		xyz3 += 15;
		//cout << enemy[i].thugX << endl;
		if (enemy3[i].thugX3 <= 0)
		{
			enemy3[i].thugX3 = screenWidth;
		}
		/*
		if (enemy3[i].thugX3 == 800 )
		{
			spidermanHealth3 -= 50;

		}
		*/

		enemy3[i].thugIndex3++;
		if (enemy3[i].thugIndex3 >= 3)
		{
			enemy3[i].thugIndex3 = 0;
		}
	}


	for (int i = 0; i < thug2Number; i++)
	{
		enemy23[i].bullX3 -= 15;
		//cout << enemy[i].thugX << endl;
		if (enemy23[i].bullX3 <= 0)
		{
			enemy23[i].bullX3 = screenWidth;
		}

		enemy23[i].bullIndex3++;
		if (enemy23[i].bullIndex3 >= 3)
		{
			enemy23[i].bullIndex3 = 0;
		}
	}


}
void declare()
{
	/*__________________________________________DOrb LOOP____________________________________________*/
	for (int i = 0; i < dOrbNumber; i++)
	{
		dorb[i].dOrbIndex++;

		if (dorb[i].dOrbIndex >= 5)
		{
			dorb[i].dOrbIndex = 0;
		}
	}

	/*__________________________________________HOrb LOOP____________________________________________*/
	for (int i = 0; i < dOrbNumber; i++)
	{
		horb[i].hOrbIndex++;

		if (horb[i].hOrbIndex >= 5)
		{
			horb[i].hOrbIndex = 0;
		}
	}

	/*__________________________________________UOrb LOOP____________________________________________*/
	for (int i = 0; i < dOrbNumber; i++)
	{
		uorb[i].uOrbIndex++;

		if (uorb[i].uOrbIndex >= 5)
		{
			uorb[i].uOrbIndex = 0;
		}
	}

	//level3
	/*__________________________________________DOrb LOOP____________________________________________*/
	for (int i = 0; i < dOrbNumber; i++)
	{
		dorb3[i].dOrbIndex3++;

		if (dorb3[i].dOrbIndex3 >= 5)
		{
			dorb3[i].dOrbIndex3 = 0;
		}
	}

	/*__________________________________________HOrb LOOP____________________________________________*/
	for (int i = 0; i < dOrbNumber; i++)
	{
		horb3[i].hOrbIndex3++;

		if (horb3[i].hOrbIndex3 >= 5)
		{
			horb3[i].hOrbIndex3 = 0;
		}
	}

	/*__________________________________________UOrb LOOP____________________________________________*/
	for (int i = 0; i < dOrbNumber; i++)
	{
		uorb3[i].uOrbIndex3++;

		if (uorb3[i].uOrbIndex3 >= 5)
		{
			uorb3[i].uOrbIndex3 = 0;
		}
	}
}
void rc()
{
	for (int i = 0; i < dOrbNumber; i++)
	{
		dorb[i].dOrb_x -= 500;

		if (dorb[i].dOrb_x <= 0)
		{
			dorb[i].dOrb_x = screenWidth;
			dorb[i].dOrb_y = screenHeight - 300;
		}

	}

	for (int i = 0; i < dOrbNumber; i++)
	{
		horb[i].hOrb_x -= 800;

		if (horb[i].hOrb_x <= 0)
		{
			horb[i].hOrb_x = screenWidth;
			horb[i].hOrb_y = screenHeight - 200;
		}

	}

	//for level3


	for (int i = 0; i < dOrbNumber; i++)
	{
		dorb3[i].dOrb_x3 -= 500;

		if (dorb3[i].dOrb_x3 <= 0)
		{
			dorb3[i].dOrb_x3 = screenWidth;
			dorb3[i].dOrb_y3 = screenHeight - 300;
		}	

	}

	for (int i = 0; i < dOrbNumber; i++)
	{
		horb3[i].hOrb_x3 -= 800;

		if (horb3[i].hOrb_x3 <= 0)
		{
			horb3[i].hOrb_x3 = screenWidth;
			horb3[i].hOrb_y3 = screenHeight - 200;
		}

	}



}
void change()
{
	for (int i = 0; i < dOrbNumber; i++)
	{
		uorb[i].uOrb_x -= 1000;

		if (uorb[i].uOrb_x <= 0)
		{
			uorb[i].uOrb_x = screenWidth;
			uorb[i].uOrb_y = screenHeight - 400;
		}

	}

	//for level3
	for (int i = 0; i < dOrbNumber; i++)
	{
		uorb3[i].uOrb_x3 -= 1000;

		if (uorb3[i].uOrb_x3 <= 0)
		{
			uorb3[i].uOrb_x3 = screenWidth;
			uorb3[i].uOrb_y3 = screenHeight - 400;
		}

	}

}
void attack()
{
	//for punch
	if (pun)
	{
		punchIndex++;
		if (punchIndex >= 7)
		{
			punchIndex = 0;
		}
		stand = false;
		LEFT = false;
		RIGHT = false;
	}
	//for kick
	if (kic)
	{
		kickIndex++;
		if (kickIndex >= 4)
		{
			kickIndex = 0;
		}
		stand = false;
		LEFT = false;
		RIGHT = false;
	}

	//for webshoot
	if (ulti)
	{
		ultIndex++;

		stand = false;
		LEFT = false;
		RIGHT = false;

	}

	for (int i = 0; i < webNumber; i++)
	{
		webs[i].webX += 150;
		if (webs[i].webX >= screenWidth)
		{
			webs[i].webX = 145 + x;
			webs[i].webY = 55 + y;

		}
		webs[i].webIndex++;
		if (webs[i].webIndex >= 2)
		{
			webs[i].webIndex = 0;
		}
	}

	if (jump || jumpUp)
	{
		for (int i = 0; i < webNumber; i++)
		{
			//webs[i].webShow = false;
			webs[i].webY = y + peterCordinateJump;
		}
	}
	else if (!jump)
	{
		for (int i = 0; i < webNumber; i++)
		{
			webs[i].webShow = true;
		}
	}

	//for block
	if (bloc)
	{

		stand = false;
		LEFT = false;
		RIGHT = false;

	}


	//for fire
	for (int i = 0; i < fireNumber; i++)
	{
		fire[i].fireX -= 100;

		if (fire[i].fireX <= 0)
		{
			fire[i].fireX = enemy2[i].bullX - 100;
			fire[i].fireY = 190;
		}
		fire[i].fireIndex++;
	}

	sindex2++;
	if (sindex2 >= 3)
	{
		sindex2 = 0;
	}

	rhinoIndex++;
	if (rhinoIndex >= 4)
	{
		rhinoIndex = 0;
	}

	if (pun2)
	{
		punchIndex2++;
		if (punchIndex2 >= 7)
		{
			punchIndex2 = 0;
		}
		stand2 = false;
		LEFT2 = false;
		RIGHT2 = false;
	}

	if (rhinoPun)
	{
		rhinoPunchIndex++;
		if (rhinoPunchIndex >= 7)
		{
			rhinoPunchIndex = 0;
		}
		rhiStand = false;
		rhinoLEFT = false;
		rhinoRIGHT = false;
	}

	if (kic2)
	{
		kickIndex2++;
		if (kickIndex2 >= 4)
		{
			kickIndex2 = 0;
		}
		stand2 = false;
		LEFT2 = false;
		RIGHT2 = false;
	}

	if (rhinoKic)
	{
		rhinoKickIndex++;
		if (rhinoKickIndex >= 4)
		{
			rhinoKickIndex = 0;
		}
		rhiStand = false;
		rhinoLEFT = false;
		rhinoRIGHT = false;
	}

	if (ulti2)
	{
		ultIndex2++;

		stand2 = false;
		LEFT2 = false;
		RIGHT2 = false;

	}


	for (int i = 0; i < webNumber; i++)
	{
		webs2[i].webX2 += 150;
		if (webs2[i].webX2 >= screenWidth)
		{
			webs2[i].webX2 = 145 + x2;
			webs2[i].webY2 = 55 + y2;

		}
		webs2[i].webIndex2++;
		if (webs2[i].webIndex2 >= 2)
		{
			webs2[i].webIndex2 = 0;
		}
	}

	if (jump2 || jumpUp2)
	{
		for (int i = 0; i < webNumber; i++)
		{
			//webs[i].webShow = false;
			webs2[i].webY2 = y2 + peterCordinateJump2;
		}
	}
	else if (!jump2)
	{
		for (int i = 0; i < webNumber; i++)
		{
			webs2[i].webShow2 = true;
		}
	}

	if (bloc2)
	{

		stand2 = false;
		LEFT2 = false;
		RIGHT2 = false;

	}


}


void bgImages()
{
	bg[0] = iLoadImage("bgren2\\tile000.png");
	bg[1] = iLoadImage("bgren2\\tile001.png");
	bg[2] = iLoadImage("bgren2\\tile002.png");
	bg[3] = iLoadImage("bgren2\\tile003.png");
	bg[4] = iLoadImage("bgren2\\tile004.png");


	bg2[0] = iLoadImage("rhi\\bgren4\\tile000.png");
	bg2[1] = iLoadImage("rhi\\bgren4\\tile001.png");
	bg2[2] = iLoadImage("rhi\\bgren4\\tile002.png");
	bg2[3] = iLoadImage("rhi\\bgren4\\tile003.png");
	bg2[4] = iLoadImage("rhi\\bgren4\\tile004.png");
	setAll();

	bg3[0] = iLoadImage("mi\\bgren2\\tile000.png");
	bg3[1] = iLoadImage("mi\\bgren2\\tile001.png");
	bg3[2] = iLoadImage("mi\\bgren2\\tile002.png");
	bg3[3] = iLoadImage("mi\\bgren2\\tile003.png");
	bg3[4] = iLoadImage("mi\\bgren2\\tile004.png");

	bg4[0] = iLoadImage("kra\\bgren2\\tile000.png");
	bg4[1] = iLoadImage("kra\\bgren2\\tile001.png");
	bg4[2] = iLoadImage("kra\\bgren2\\tile002.png");
	bg4[3] = iLoadImage("kra\\bgren2\\tile003.png");
	bg4[4] = iLoadImage("kra\\bgren2\\tile004.png");

	bg5[0] = iLoadImage("dd\\bgren3\\tile000.png");
	bg5[1] = iLoadImage("dd\\bgren3\\tile001.png");
	bg5[2] = iLoadImage("dd\\bgren3\\tile002.png");
	bg5[3] = iLoadImage("dd\\bgren3\\tile003.png");
	bg5[4] = iLoadImage("dd\\bgren3\\tile004.png");

	setAll5();

	//for rendering and jumping
	iSetTimer(15, changex);
	
	iSetTimer(12000, rc);
}
void peterImages()
{
	//peter pic and text
	spideyIcon = iLoadImage("spidey.png");
	t1 = iLoadImage("txt1.png");

	//snippets for stand
	peterStand[0] = iLoadImage("s\\s0.png");
	peterStand[1] = iLoadImage("s\\s1.png");
	peterStand[2] = iLoadImage("s\\s2.png");


	iSetTimer(120, declare);
	iSetTimer(4000, change);


	//snippets for running right
	peterRun1[0] = iLoadImage("r\\r0.png");
	peterRun1[1] = iLoadImage("r\\r1.png");
	peterRun1[2] = iLoadImage("r\\r2.png");
	peterRun1[3] = iLoadImage("r\\r3.png");
	peterRun1[4] = iLoadImage("r\\r4.png");
	peterRun1[5] = iLoadImage("r\\r5.png");
	peterRun1[6] = iLoadImage("r\\r6.png");

	//snippets for running left
	peterRun2[0] = iLoadImage("l\\L0.png");
	peterRun2[1] = iLoadImage("l\\L1.png");
	peterRun2[2] = iLoadImage("l\\L2.png");
	peterRun2[3] = iLoadImage("l\\L3.png");
	peterRun2[4] = iLoadImage("l\\L4.png");
	peterRun2[5] = iLoadImage("l\\L5.png");
	peterRun2[6] = iLoadImage("l\\L6.png");

	//snippets for jumping
	peterJump[0] = iLoadImage("jump\\jump1.png");
	peterJump[1] = iLoadImage("jump\\jump2.png");
	peterJump1[0] = iLoadImage("jump\\jumpL1.png");
	peterJump1[1] = iLoadImage("jump\\jumpL2.png");
	//iSetTimer(15, change);


	//snippets for punching
	punch[0] = iLoadImage("punch\\p1.png");
	punch[1] = iLoadImage("punch\\p2.png");
	punch[2] = iLoadImage("punch\\p3.png");
	punch[3] = iLoadImage("punch\\p4.png");
	punch[4] = iLoadImage("punch\\p5.png");
	punch[5] = iLoadImage("punch\\p6.png");
	punch[6] = iLoadImage("punch\\p7.png");


	//snippets for kicking
	kick[0] = iLoadImage("kick\\k1.png");
	kick[1] = iLoadImage("kick\\k2.png");
	kick[2] = iLoadImage("kick\\k3.png");
	kick[3] = iLoadImage("kick\\k4.png");

	//snippets for ult
	ult = iLoadImage("ultim.png");

	//block
	block = iLoadImage("block\\tile001.png");

	//web images
	web[0] = iLoadImage("web\\tile000.png");
	web[1] = iLoadImage("web\\tile001.png");

	iSetTimer(100, attack);

	orb[0] = iLoadImage("orb\\1.png");
	orb[1] = iLoadImage("orb\\2.png");
	orb[2] = iLoadImage("orb\\3.png");
	orb[3] = iLoadImage("orb\\4.png");
	orb[4] = iLoadImage("orb\\5.png");

	Horb[0] = iLoadImage("orb\\frame_00.png");
	Horb[1] = iLoadImage("orb\\frame_01.png");
	Horb[2] = iLoadImage("orb\\frame_02.png");
	Horb[3] = iLoadImage("orb\\frame_03.png");
	Horb[4] = iLoadImage("orb\\frame_04.png");

	Uorb[0] = iLoadImage("orb\\frame2_00.png");
	Uorb[1] = iLoadImage("orb\\frame2_01.png");
	Uorb[2] = iLoadImage("orb\\frame2_02.png");
	Uorb[3] = iLoadImage("orb\\frame2_03.png");
	Uorb[4] = iLoadImage("orb\\frame2_04.png");

	iSetTimer(200, checkCollision);
	//iSetTimer(200, collisioncheck1);




}
void thugImages()
{
	//for thug 1
	thugRun[0] = iLoadImage("t1run\\tr1.png");
	thugRun[1] = iLoadImage("t1run\\tr2.png");
	thugRun[2] = iLoadImage("t1run\\tr3.png");


	//for thug 2
	thug2Run[0] = iLoadImage("thug2.0\\tr (1).png");
	thug2Run[1] = iLoadImage("thug2.0\\tr (2).png");
	thug2Run[2] = iLoadImage("thug2.0\\tr (3).png");

	//bullet fire images
	firing = iLoadImage("1.png");

	//snippets for stand
	peterStand5[0] = iLoadImage("dd\\s\\s (1).png");
	peterStand5[1] = iLoadImage("dd\\s\\s (2).png");
	peterStand5[2] = iLoadImage("dd\\s\\s (3).png");
	peterStand5[3] = iLoadImage("dd\\s\\s (4).png");
	peterStand5[4] = iLoadImage("dd\\s\\s (5).png");
	peterStand5[5] = iLoadImage("dd\\s\\s (6).png");
	peterStand5[6] = iLoadImage("dd\\s\\s (7).png");
	peterStand5[7] = iLoadImage("dd\\s\\s (8).png");
	peterStand5[8] = iLoadImage("dd\\s\\s (9).png");



	//snippets for running right
	peterRun15[0] = iLoadImage("dd\\r\\r (1).png");
	peterRun15[1] = iLoadImage("dd\\r\\r (2).png");
	peterRun15[2] = iLoadImage("dd\\r\\r (3).png");
	peterRun15[3] = iLoadImage("dd\\r\\r (4).png");
	peterRun15[4] = iLoadImage("dd\\r\\r (5).png");
	peterRun15[5] = iLoadImage("dd\\r\\r (6).png");
	peterRun15[6] = iLoadImage("dd\\r\\r (7).png");
	peterRun15[7] = iLoadImage("dd\\r\\r (8).png");

	//snippets for running left
	peterRun25[0] = iLoadImage("dd\\l\\l (1).png");
	peterRun25[1] = iLoadImage("dd\\l\\l (2).png");
	peterRun25[2] = iLoadImage("dd\\l\\l (3).png");
	peterRun25[3] = iLoadImage("dd\\l\\l (4).png");
	peterRun25[4] = iLoadImage("dd\\l\\l (5).png");
	peterRun25[5] = iLoadImage("dd\\l\\l (6).png");
	peterRun25[6] = iLoadImage("dd\\l\\l (7).png");
	peterRun25[7] = iLoadImage("dd\\l\\l (8).png");
	peterRun25[8] = iLoadImage("dd\\l\\l (9).png");
	peterRun25[9] = iLoadImage("dd\\l\\l (10).png");
	peterRun25[10] = iLoadImage("dd\\l\\l (11).png");
	peterRun25[11] = iLoadImage("dd\\l\\l (12).png");
	peterRun25[12] = iLoadImage("dd\\l\\l (13).png");
	peterRun25[13] = iLoadImage("dd\\l\\l (14).png");
	peterRun25[14] = iLoadImage("dd\\l\\l (15).png");

	//snippets for jumping
	peterJump5[0] = iLoadImage("dd\\jump\\j (1).png");
	peterJump5[1] = iLoadImage("dd\\jump\\j (2).png");
	peterJump15[0] = iLoadImage("dd\\jump\\j (3).png");
	peterJump15[1] = iLoadImage("dd\\jump\\j (4).png");



	//snippets for punching
	punch5[0] = iLoadImage("dd\\punch\\p (1).png");
	punch5[1] = iLoadImage("dd\\punch\\p (2).png");
	punch5[2] = iLoadImage("dd\\punch\\p (3).png");
	punch5[3] = iLoadImage("dd\\punch\\p (4).png");
	punch5[4] = iLoadImage("dd\\punch\\p (5).png");
	punch5[5] = iLoadImage("dd\\punch\\p (6).png");
	punch5[6] = iLoadImage("dd\\punch\\p (7).png");
	punch5[7] = iLoadImage("dd\\punch\\p (8).png");



	//snippets for kicking
	kick5[0] = iLoadImage("dd\\kick\\k (1).png");
	kick5[1] = iLoadImage("dd\\kick\\k (2).png");
	kick5[2] = iLoadImage("dd\\kick\\k (3).png");
	kick5[3] = iLoadImage("dd\\kick\\k (4).png");
	kick5[4] = iLoadImage("dd\\kick\\k (5).png");
	kick5[5] = iLoadImage("dd\\kick\\k (6).png");

	//snippets for ult
	ult5 = iLoadImage("dd\\ult.png");

	//web images
	Web5[0] = iLoadImage("dd\\web\\tile000.png");
	Web5[1] = iLoadImage("dd\\web\\tile001.png");


	//block
	block5 = iLoadImage("dd\\block\\tile001.png");

	imgst = iLoadImage("dd\\s\\s (2).png");

	ult25[0] = iLoadImage("dd\\pu\\p1.png");
	ult25[1] = iLoadImage("dd\\pu\\p2.png");
	ult25[2] = iLoadImage("dd\\pu\\p3.png");
	ult25[3] = iLoadImage("dd\\pu\\p4.png");
	ult25[4] = iLoadImage("dd\\pu\\p5.png");
	ult25[5] = iLoadImage("dd\\pu\\p6.png");
	ult25[6] = iLoadImage("dd\\pu\\p7.png");
	ult25[7] = iLoadImage("dd\\pu\\k1.png");
	ult25[8] = iLoadImage("dd\\pu\\k2.png");
	ult25[9] = iLoadImage("dd\\pu\\k3.png");
	ult25[10] = iLoadImage("dd\\pu\\k4.png");

	ult35[0] = iLoadImage("dd\\pu2\\p (1).png");
	ult35[1] = iLoadImage("dd\\pu2\\p (2).png");
	ult35[2] = iLoadImage("dd\\pu2\\p (3).png");
	ult35[3] = iLoadImage("dd\\pu2\\p (4).png");
	ult35[4] = iLoadImage("dd\\pu2\\p (5).png");
	ult35[5] = iLoadImage("dd\\pu2\\k.png");
	ult35[6] = iLoadImage("dd\\pu2\\k (1).png");
	ult35[7] = iLoadImage("dd\\pu2\\k (2).png");
	ult35[8] = iLoadImage("dd\\pu2\\k (3).png");

	spideyIcon5 = iLoadImage("dd\\spidey.png");
}
void titleButtons()
{
	//Image for title screen
	title = iLoadImage("Title\\spidermanTitle.png");

	//Image for main menu
	menu = iLoadImage("Title\\mainmenu.png");

	//menu button positioning
	for (int i = 0; i <= n; i++)
	{
		bCoordinate[i].x = 150;
		bCoordinate[i].y = screenHeight - (i + 2) * 105;
	}

	//Buttons for main menu
	buttons[0] = iLoadImage("Buttons\\start.png");
	buttons[1] = iLoadImage("Buttons\\story.png");
	buttons[2] = iLoadImage("buttons\\howtoplay.png");
	buttons[3] = iLoadImage("buttons\\highscores.png");
	buttons[4] = iLoadImage("buttons\\credits.png");

	//Image for instructions page
	inst = iLoadImage("Title\\instructions_page (1).png");

	//Image for high score page
	highscore = iLoadImage("Title\\hs.png");

	//Image for credits page
	credits = iLoadImage("Title\\credits.png");

	//Image before game
	imgy = iLoadImage("plot.png");

	//image after winning
	victory = iLoadImage("Title\\victory.png");
	
}