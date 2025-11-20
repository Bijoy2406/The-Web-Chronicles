void drawPeterHealthBar3()
{
	int barWidth = 325;         
	int barHeight = 25;         
	int barX = 190;
	int barY = screenHeight - 90;

	
	int maxHealth = 500;

	
	int healthBarWidth = (spidermanHealth3 * barWidth) / maxHealth;

	if (healthBarWidth > barWidth) {
		healthBarWidth = barWidth; 
	}

	iShowImage(0, screenHeight - 220, 180, 240, spideyIcon3);
	iShowImage(180, screenHeight - 65, 350, 60, t13);

	
	iSetColor(255, 0, 0); 
	iFilledRectangle(barX, barY, barWidth, barHeight);

	if (spidermanHealth3 > 0)
	{
		
		iSetColor(0, 255, 0);
		iFilledRectangle(barX, barY, healthBarWidth, barHeight);
	}
}

void drawDimensionalBar3()
{
	int barWidth = 325;
	int barHeight = 25;
	int barX = 190;
	int barY = screenHeight - 130;

	int dBarWidth = (dBar3 * barWidth) / 1000;


	iSetColor(255, 0, 0);
	iFilledRectangle(barX, barY, barWidth, barHeight);

	if (dBar3 <= 100)
	{

		int newDBarWidth = (dBar3 * barWidth) / 100;


		iSetColor(0, 0, 255);
		iFilledRectangle(barX, barY, newDBarWidth, barHeight);
	}
	else
	{
		iSetColor(0, 0, 255);
		iFilledRectangle(barX, barY, barWidth, barHeight);
	}
}

void drawUltimateBar3()
{
	int ubarWidth = 325;
	int ubarHeight = 25;
	int ubarX = 190;
	int ubarY = screenHeight - 170;

	int udBarWidth = (uBar3 * ubarWidth) / 1000;


	iSetColor(255, 0, 0);
	iFilledRectangle(ubarX, ubarY, ubarWidth, ubarHeight);

	if (uBar3 <= 100)
	{

		int newuBarWidth = (uBar3 * ubarWidth) / 100;


		iSetColor(255, 165, 0);
		iFilledRectangle(ubarX, ubarY, newuBarWidth, ubarHeight);
	}
	else
	{
		iSetColor(255, 165, 165);
		iFilledRectangle(ubarX, ubarY, ubarWidth, ubarHeight);
	}
}

void peterMovement3()
{
	if (jump3 && RIGHT3 == false && LEFT3 == false)
	{
		if (jumpUp3)
		{
			iShowImage(x3, y3 + peterCordinateJump3, peterWidth, peterHeight - 40, peterJump3[0]);

		}
		else
		{
			iShowImage(x3, y3 + peterCordinateJump3, peterWidth, peterHeight - 40, peterJump3[1]);
		}
	}
	if (jump3)
	{
		if (jumpUp3 == true && RIGHT3 == true)
		{
			iShowImage(x3, y3 + peterCordinateJump3, peterWidth, peterHeight - 40, peterJump3[0]);
		}
		else if (jumpUp3 == false && RIGHT3 == true)
		{
			iShowImage(x3, y3 + peterCordinateJump3, peterWidth, peterHeight - 40, peterJump3[1]);
		}

		if (jumpUp3 == true && LEFT3 == true)
		{
			iShowImage(x3, y3 + peterCordinateJump3, peterWidth, peterHeight - 40, peterJump13[0]);
		}
		else if (jumpUp3 == false && LEFT3 == true)
		{
			iShowImage(x3, y3 + peterCordinateJump3, peterWidth, peterHeight - 40, peterJump13[1]);
		}
	}
	else
	{
		if (stand3)
		{
			iShowImage(x3, y3, peterWidth, peterHeight - 40, peterStand3[sindex3]);
		}

		else if (!stand3 && RIGHT3 == true)
		{
			ulti3 = false;
			iShowImage(x3, y3, peterWidth, peterHeight - 40, peterRun13[r1index3]);

			standCounter3++;

			if (standCounter3 >= 200)
			{
				standCounter3 = 0;
				r1index3 = 0;
				stand3 = true;
				RIGHT3 = false;
			}

		}

		else if (!stand3 && LEFT3 == true)
		{
			ulti3 = false;
			iShowImage(x3, y3, peterWidth, peterHeight - 40, peterRun23[r2index3]);

			standCounter3++;

			if (standCounter3 >= 180)
			{
				standCounter3 = 0;
				r2index3 = 0;
				stand3 = true;
				LEFT3 = false;
			}
		}

		else if (!stand3 && pun3)
		{
			ulti3 = false;
			iShowImage(x3, y3, peterWidth, peterHeight - 15, punch3[punchIndex3]);
			standCounter3++;
			if (standCounter3 >= 200)
			{
				standCounter3 = 0;
				punchIndex3 = 0;
				stand3 = true;
				pun3 = false;
			}
		}

		else if (!stand3 && kic3)
		{
			ulti3 = false;
			iShowImage(x3, y3, peterWidth, peterHeight - 15, kick3[kickIndex3]);
			standCounter3++;
			if (standCounter3 >= 200)
			{
				standCounter3 = 0;
				punchIndex3 = 0;
				stand3 = true;
				kic3 = false;
			}
		}

		else if (!stand3 && bloc3)
		{
			ulti3 = false;
			iShowImage(x3, y3 - 60, peterWidth + 150, peterHeight + 60, block3);
			standCounter3++;
			if (standCounter3 >= 600)
			{
				standCounter3 = 0;
				blockIndex3 = 0;
				stand3 = true;
				bloc3 = false;
			}
		}

		else if (!stand3 && movebg3)
		{
			standCounter3++;
			if (standCounter3 >= 150)
			{
				standCounter3 = 0;
				punchIndex3 = 0;
				stand3 = true;
				movebg3 = false;
			}
		}

		else if (!stand3 && ulti3)
		{
			iShowImage(x3, y3 - 30, peterWidth + 30, peterHeight + 30, ult3);
			standCounter3++;
			if (standCounter3 >= 700)
			{
				standCounter3 = 0;
				ultIndex3 = 0;
				stand3 = true;
				ulti3 = false;
			}
		}

	}
}

void setWebVariables3()
{
	for (int i = 0; i < webNumber; i++)
	{
		webs3[i].webX3 = x3;
		webs3[i].webY3 = y3 + 35;
		webs3[i].webIndex3 = 0;
		webs3[i].webShow3 = true;
	}
}
void webMovement3()
{
	if (ulti3 && uBar3 >= 100)
	{
		for (int i = 0; i < webNumber; i++)
		{
			if (webs3[i].webShow3)
			{
				iShowImage(webs3[i].webX3 + 65, webs3[i].webY3 + 26, 57, 54, Web3[webs3[i].webIndex3]);
			}
		}
	}
}

void rsethOrbVariables3()
{
	for (int i = 0; i < dOrbNumber; i++)
	{
		horb3[i].hOrb_x3 = screenWidth;
		horb3[i].hOrb_y3 = screenHeight - 200;
		horb3[i].hOrbIndex3 = rand() % 5;
		horb3[i].hOrbShow3 = true;
	}
}
void collisioncheck43()
{
	for (int i = 0; i < dOrbNumber; i++)
	{
		if (x3 + peterWidth >= horb3[i].hOrb_x3 && x3 <= horb3[i].hOrb_x3 + 80 && y3 + peterHeight + peterCordinateJump3 > horb3[i].hOrb_y3 && y3 < horb3[i].hOrb_y3 + 80)
		{
			if (horb3[i].hOrbShow3)
			{
				horb3[i].hOrbShow3 = false;
				rsethOrbVariables3();
				spidermanHealth3 += 90;
			}
		}

	}
}
void rhOrbsMovement3() ///for animation
{
	for (int i = 0; i < dOrbNumber; i++)
	{
		if (horb3[i].hOrbShow3)
		{
			iShowImage(horb3[i].hOrb_x3, horb3[i].hOrb_y3, 80, 80, Horb3[horb3[i].hOrbIndex3]);
		}
	}
}

void rsetOrbVariables3()
{
	for (int i = 0; i < dOrbNumber; i++)
	{
		dorb3[i].dOrb_x3 = screenWidth;
		dorb3[i].dOrb_y3 = screenHeight - 300;
		dorb3[i].dOrbIndex3 = rand() % 5;
		dorb3[i].dOrbShow3 = true;
	}
}
void collisioncheck33()
{
	for (int i = 0; i < dOrbNumber; i++)
	{
		if (x3 + peterWidth >= dorb3[i].dOrb_x3 && x3 <= dorb3[i].dOrb_x3 + 80 && y3 + peterHeight + peterCordinateJump3 > dorb3[i].dOrb_y3 && y3 < dorb3[i].dOrb_y3 + 80)
		{
			if (dorb3[i].dOrbShow3)
			{
				score += 5;
				dorb3[i].dOrbShow3 = false;
				rsetOrbVariables3();
				dBar3 += 20;
			}
		}

	}
}
void rOrbsMovement3() ///for animation
{
	for (int i = 0; i < dOrbNumber; i++)
	{
		if (dorb3[i].dOrbShow3)
		{
			iShowImage(dorb3[i].dOrb_x3, dorb3[i].dOrb_y3, 80, 80, orb3[dorb3[i].dOrbIndex3]);
		}
	}
}
void rsetuOrbVariables3()
{
	for (int i = 0; i < dOrbNumber; i++)
	{
		uorb3[i].uOrb_x3 = screenWidth;
		uorb3[i].uOrb_y3 = screenHeight - 400;
		uorb3[i].uOrbIndex3 = rand() % 5;
		uorb3[i].uOrbShow3 = true;
	}
}
void collisioncheck53()
{
	for (int i = 0; i < dOrbNumber; i++)
	{
		if (x3 + peterWidth >= uorb3[i].uOrb_x3 && x3 <= uorb3[i].uOrb_x3 + 80 && y3 + peterHeight + peterCordinateJump3 > uorb3[i].uOrb_y3 && y3 < uorb3[i].uOrb_y3 + 80)
		{
			if (uorb3[i].uOrbShow3)
			{
				score += 5;
				uorb3[i].uOrbShow3 = false;
				rsetuOrbVariables3();
				uBar3 += 20;
			}
		}

	}
}

void ruOrbsMovement3() ///for animation
{
	for (int i = 0; i < dOrbNumber; i++)
	{
		if (uorb3[i].uOrbShow3)
		{
			iShowImage(uorb3[i].uOrb_x3, uorb3[i].uOrb_y3, 80, 80, Uorb3[uorb3[i].uOrbIndex3]);
		}
	}
}

void enemyMovement3()
{
	for (int i = 0; i < thug1Number; i++)
	{
		if (enemy3[i].thugShow3)
		{
			iShowImage(enemy3[i].thugX3, enemy3[i].thugY3, peterWidth, peterHeight, thugRun3[enemy3[i].thugIndex3]);
		}
	}
}

void enemy2Movement3()
{
	for (int i = 0; i < thug2Number; i++)
	{
		if (enemy23[i].bullShow3)
		{
			iShowImage(enemy23[i].bullX3, enemy23[i].bullY3, peterWidth, peterHeight, thug2Run3[enemy23[i].bullIndex3]);
		}
	}
}



void webCollision3()
{
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
void thugHealthBars3()
{
	int barWidth = 50; 
	int barHeight = 10; 
	int barYOffset = 20; 

	
	for (int i = 0; i < thug1Number; i++)
	{
		if (enemy3[i].thugShow3)
		{
			int barX = enemy3[i].thugX3 + (peterWidth - barWidth) / 2;
			int barY = enemy3[i].thugY3 + peterHeight + barYOffset;

			int healthBarWidth = (enemy3[i].thugHealth3 * barWidth) / 100; 

			iSetColor(255, 0, 0); 
			iFilledRectangle(barX, barY, barWidth, barHeight);


			iSetColor(0, 255, 0); 
			iFilledRectangle(barX, barY, healthBarWidth, barHeight);
		}
	}


	for (int i = 0; i < thug2Number; i++)
	{
		if (enemy23[i].bullShow3)
		{
			int barX = enemy23[i].bullX3 + (peterWidth - barWidth) / 2;
			int barY = enemy23[i].bullY3 + peterHeight + barYOffset;

			int healthBarWidth = (enemy23[i].bullHealth3 * barWidth) / 100; 

			
			iSetColor(255, 0, 0); 
			iFilledRectangle(barX, barY, barWidth, barHeight);

			
			iSetColor(0, 255, 0); 
			iFilledRectangle(barX, barY, healthBarWidth, barHeight);
		}
	}
}

void setFireVariables3()
{
	for (int i = 0; i < fireNumber; i++)
	{
		fire3[i].fireX3 = enemy23[i].bullX3 - 100;
		fire3[i].fireY3 = 165;
		fire3[i].fireIndex3 = rand() % 1;
		fire3[i].fireShow3 = true;
	}
}
void fireMovement3()
{
	if (thugUlt3)
	{
		for (int i = 0; i < fireNumber; i++)
		{
			if (fire3[i].fireShow3)
			{
				iShowImage(fire3[i].fireX3, fire3[i].fireY3, 198, 93, firing3);
			}
		}
	}
}
void collisioncheck13()
{


}

void setAll3()
{
	int sum = 0;
	for (int i = 0; i < n3; i++)
	{
		mainbg3[i].y3 = 0;
		mainbg3[i].x3 = sum;
		sum += screenWidth; 
	}
}
void attack2()
{
	if (pun3)
	{
		punchIndex3++;
		if (punchIndex3 >= 5)
		{
			punchIndex3 = 0;
		}
		stand3 = false;
		LEFT3 = false;
		RIGHT3 = false;
	}
	//for kick
	if (kic3)
	{
		kickIndex3++;
		if (kickIndex3 >= 5)
		{
			kickIndex3 = 0;
		}
		stand3 = false;
		LEFT3 = false;
		RIGHT3 = false;
	}

	//for webshoot
	if (ulti3)
	{
		ultIndex3++;

		stand3 = false;
		LEFT3 = false;
		RIGHT3 = false;

	}

	for (int i = 0; i < webNumber; i++)
	{
		webs3[i].webX3 += 150;
		if (webs3[i].webX3 >= screenWidth)
		{
			webs3[i].webX3 = 145 + x3;
			webs3[i].webY3 = 55 + y3;

		}
		webs3[i].webIndex3++;
		if (webs3[i].webIndex3 >= 2)
		{
			webs3[i].webIndex3 = 0;
		}
	}

	/*_________________________________________________________________________________________________________________*/
	if (jump3 || jumpUp3)
	{
		for (int i = 0; i < webNumber; i++)
		{
			//webs[i].webShow = false;
			webs3[i].webY3 = y3 + peterCordinateJump3;
		}
	}
	else if (!jump3)
	{
		for (int i = 0; i < webNumber; i++)
		{
			webs3[i].webShow3 = true;
		}
	}

	//for block
	if (bloc3)
	{

		stand3 = false;
		LEFT3 = false;
		RIGHT3 = false;

	}


	//for fire
	for (int i = 0; i < fireNumber; i++)
	{
		fire3[i].fireX3 -= 100;

		if (fire3[i].fireX3 <= 0)
		{
			fire3[i].fireX3 = enemy23[i].bullX3 - 100;
			fire3[i].fireY3 = 190;
		}
		fire3[i].fireIndex3++;
	}
}
void peterImages3()
{
	//peter pic and text
	spideyIcon3 = iLoadImage("mi\\spidey.png");
	t13 = iLoadImage("mi\\txt1.png");

	//snippets for stand
	peterStand3[0] = iLoadImage("mi\\s\\s.png");
	peterStand3[1] = iLoadImage("mi\\s\\s (1).png");
	peterStand3[2] = iLoadImage("mi\\s\\s (2).png");
	peterStand3[3] = iLoadImage("mi\\s\\s (3).png");
	peterStand3[4] = iLoadImage("mi\\s\\s (4).png");

	//snippets for running right
	peterRun13[0] = iLoadImage("mi\\r\\r.png");
	peterRun13[1] = iLoadImage("mi\\r\\r (1).png");
	peterRun13[2] = iLoadImage("mi\\r\\r (2).png");
	peterRun13[3] = iLoadImage("mi\\r\\r (3).png");
	peterRun13[4] = iLoadImage("mi\\r\\r (4).png");

	//snippets for running left
	peterRun23[0] = iLoadImage("mi\\l\\l (1).png");
	peterRun23[1] = iLoadImage("mi\\l\\l (2).png");
	peterRun23[2] = iLoadImage("mi\\l\\l (3).png");
	peterRun23[3] = iLoadImage("mi\\l\\l (4).png");
	peterRun23[4] = iLoadImage("mi\\l\\l (5).png");

	//snippets for jumping
	peterJump3[0] = iLoadImage("mi\\jump\\j (1).png");
	peterJump3[1] = iLoadImage("mi\\jump\\j (2).png");
	peterJump13[0] = iLoadImage("mi\\jump\\j (3).png");
	peterJump13[1] = iLoadImage("mi\\jump\\j (4).png");
	//iSetTimer(15, change);


	//snippets for punching
	punch3[0] = iLoadImage("mi\\punch\\p (1).png");
	punch3[1] = iLoadImage("mi\\punch\\p (2).png");
	punch3[2] = iLoadImage("mi\\punch\\p (3).png");
	punch3[3] = iLoadImage("mi\\punch\\p (4).png");
	punch3[4] = iLoadImage("mi\\punch\\p (5).png");


	//snippets for kicking
	kick3[0] = iLoadImage("mi\\kick\\k.png");
	kick3[1] = iLoadImage("mi\\kick\\k (1).png");
	kick3[2] = iLoadImage("mi\\kick\\k (2).png");
	kick3[3] = iLoadImage("mi\\kick\\k (3).png");
	kick3[4] = iLoadImage("mi\\kick\\k (4).png");

	//snippets for ult
	ult3 = iLoadImage("mi\\ult.png");

	//block
	block3 = iLoadImage("mi\\block\\tile001.png");

	//web images
	Web3[0] = iLoadImage("mi\\web\\tile000.png");
	Web3[1] = iLoadImage("mi\\web\\tile001.png");

	iSetTimer(100, attack2);

	orb3[0] = iLoadImage("mi\\orb\\1.png");
	orb3[1] = iLoadImage("mi\\orb\\2.png");
	orb3[2] = iLoadImage("mi\\orb\\3.png");
	orb3[3] = iLoadImage("mi\\orb\\4.png");
	orb3[4] = iLoadImage("mi\\orb\\5.png");

	Horb3[0] = iLoadImage("mi\\orb\\frame_00.png");
	Horb3[1] = iLoadImage("mi\\orb\\frame_01.png");
	Horb3[2] = iLoadImage("mi\\orb\\frame_02.png");
	Horb3[3] = iLoadImage("mi\\orb\\frame_03.png");
	Horb3[4] = iLoadImage("mi\\orb\\frame_04.png");

	Uorb3[0] = iLoadImage("mi\\orb\\frame2_00.png");
	Uorb3[1] = iLoadImage("mi\\orb\\frame2_01.png");
	Uorb3[2] = iLoadImage("mi\\orb\\frame2_02.png");
	Uorb3[3] = iLoadImage("mi\\orb\\frame2_03.png");
	Uorb3[4] = iLoadImage("mi\\orb\\frame2_04.png");

	//iSetTimer(200, checkCollision3);
	//iSetTimer(200, collisioncheck13);


}

void thugImages3()
{
	//for thug 1
	thugRun3[0] = iLoadImage("mi\\t1run\\tile000.png");
	thugRun3[1] = iLoadImage("mi\\t1run\\tile001.png");
	thugRun3[2] = iLoadImage("mi\\t1run\\tile002.png");

	//for thug 2
	thug2Run3[0] = iLoadImage("mi\\thug2.0\\t1.png");
	thug2Run3[1] = iLoadImage("mi\\thug2.0\\t2.png");
	thug2Run3[2] = iLoadImage("mi\\thug2.0\\t3.png");
	thug2Run3[3] = iLoadImage("mi\\thug2.0\\t4.png");
	thug2Run3[4] = iLoadImage("mi\\thug2.0\\t5.png");
	thug2Run3[5] = iLoadImage("mi\\thug2.0\\t6.png");
	thug2Run3[6] = iLoadImage("mi\\thug2.0\\t7.png");
	thug2Run3[7] = iLoadImage("mi\\thug2.0\\t8.png");
	thug2Run3[8] = iLoadImage("mi\\thug2.0\\t9.png");

	//bullet fire images
	firing3 = iLoadImage("mi\\Missile.png");
}