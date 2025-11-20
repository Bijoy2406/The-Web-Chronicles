void drawPeterHealthBar2()				
{
	int barWidth = 325;					
	int barHeight = 25;					
	int barX = 150;
	int barY = screenHeight - 130;

	int healthBarWidth = (spidermanHealth2 * barWidth) / 1000; 
	iShowImage(0, screenHeight - 150, 150, 150, spideyIcon);
	iShowImage(150, screenHeight - 90, 350, 60, t1);


	

	iSetColor(255, 0, 0); 
	iFilledRectangle(barX, barY, barWidth, barHeight);
	if (spidermanHealth2 >= 0)
	{
		
		iSetColor(0, 255, 0);
		iFilledRectangle(barX, barY, healthBarWidth, barHeight);
	}
}

void drawRhinoHealthBar()					
{
	int barWidth = 325;					
	int barHeight = 25;					
	int barX = screenWidth - (325 + 150);
	int barY = screenHeight - 130;
	
	int healthBarWidth = (rhinoHealth * barWidth) / 1000; 



	iSetColor(255, 0, 0); 
	iFilledRectangle(barX, barY, barWidth, barHeight);
	if (rhinoHealth >= 0){
		
		iSetColor(0, 255, 0); 
		iFilledRectangle(barX, barY, healthBarWidth, barHeight);
	}
}

//peter movement
void peterMovement2()
{
	if (jump2 && RIGHT2 == false && LEFT2 == false)
	{
		if (jumpUp2)
		{
			iShowImage(x2, y2 + peterCordinateJump2, peterWidth, peterHeight, peterJump2[0]);

		}
		else
		{
			iShowImage(x2, y2 + peterCordinateJump2, peterWidth - 15, peterHeight - 15, peterJump2[1]);
		}
	}
	if (jump2)
	{
		if (jumpUp2 == true && RIGHT2 == true)
		{
			iShowImage(x2, y2 + peterCordinateJump2, peterWidth, peterHeight, peterJump2[0]);
		}
		else if (jumpUp2 == false && RIGHT2 == true)
		{
			iShowImage(x2, y2 + peterCordinateJump2, peterWidth, peterHeight, peterJump2[1]);
		}

		if (jumpUp2 == true && LEFT2 == true)
		{
			iShowImage(x2, y2 + peterCordinateJump2, peterWidth, peterHeight, peterJump12[0]);
		}
		else if (jumpUp2 == false && LEFT2 == true)
		{
			iShowImage(x2, y2 + peterCordinateJump2, peterWidth - 20, peterHeight - 20, peterJump12[1]);
		}
	}
	else
	{
		if (stand2)
		{
			iShowImage(x2, y2, peterWidth, peterHeight, peterStand2[sindex2]);
		}

		else if (!stand2 && RIGHT2 == true)
		{
			ulti2 = false;
			iShowImage(x2, y2, peterWidth, peterHeight, peterRun12[r1index2]);

			standCounter2++;

			if (standCounter2 >= 200)
			{
				standCounter2 = 0;
				r1index2 = 0;
				stand2 = true;
				RIGHT2 = false;
			}

		}

		else if (!stand2 && LEFT2 == true)
		{
			ulti2 = false;
			iShowImage(x2, y2, peterWidth, peterHeight, peterRun22[r2index2]);

			standCounter2++;

			if (standCounter2 >= 180)
			{
				standCounter2 = 0;
				r2index2 = 0;
				stand2 = true;
				LEFT2 = false;
			}
		}

		else if (!stand2 && pun2)
		{
			ulti2 = false;
			iShowImage(x2, y2, peterWidth, peterHeight - 15, punch2[punchIndex2]);
			standCounter2++;
			if (standCounter2 >= 200)
			{
				standCounter2 = 0;
				punchIndex2 = 0;
				stand2 = true;
				pun2 = false;
			}
		}

		else if (!stand2 && kic2)
		{
			ulti2 = false;
			iShowImage(x2, y2, peterWidth, peterHeight - 15, kick2[kickIndex2]);
			standCounter2++;
			if (standCounter2 >= 200)
			{
				standCounter2 = 0;
				punchIndex2 = 0;
				stand2 = true;
				kic2 = false;
			}
		}

		else if (!stand2 && bloc2)
		{
			ulti2 = false;
			iShowImage(x2, y2, peterWidth + 140, peterHeight, block2);
			standCounter2++;
			if (standCounter2 >= 600)
			{
				standCounter2 = 0;
				blockIndex2 = 0;
				stand2 = true;
				bloc2 = false;
			}
		}

		else if (!stand2 && movebg2)
		{
			standCounter2++;
			if (standCounter2 >= 150)
			{
				standCounter2 = 0;
				punchIndex2 = 0;
				stand2 = true;
				movebg2 = false;
			}
		}

		else if (!stand2 && ulti2)
		{
			iShowImage(x2, y2, peterWidth, peterHeight, ult2);
			standCounter2++;
			if (standCounter2 >= 700)
			{
				standCounter2 = 0;
				ultIndex2 = 0;
				stand2 = true;
				ulti2 = false;
			}
		}

	}
}

void rhinoMovement()
{
	if (rhinoJump && rhinoRIGHT == false && rhinoLEFT == false)
	{
		if (rhinoJumpUp)
		{
			iShowImage(rx, ry + rhinoCordinateJump, rhinoWidth - 20, rhinoHeight - 20, rhinoJump1[0]);
		}
		else
		{
			iShowImage(rx, ry + rhinoCordinateJump, rhinoWidth - 20, rhinoHeight - 20, rhinoJump1[1]);
		}
	}
	if (rhinoJump)
	{
		if (rhinoJumpUp == true && rhinoRIGHT == true)
		{
			iShowImage(rx, ry + rhinoCordinateJump, rhinoWidth - 20, rhinoHeight - 20, rhinoJump1[0]);
		}
		else if (rhinoJumpUp == false && rhinoRIGHT == true)
		{
			iShowImage(rx, ry + rhinoCordinateJump, rhinoWidth - 20, rhinoHeight - 20, rhinoJump1[1]);
		}

		if (rhinoJumpUp == true && rhinoLEFT == true)
		{
			iShowImage(rx, ry + rhinoCordinateJump, rhinoWidth - 20, rhinoHeight - 20, rhinoJump2[0]);
		}
		else if (rhinoJumpUp == false && rhinoLEFT == true)
		{
			iShowImage(rx, ry + rhinoCordinateJump, rhinoWidth - 20, rhinoHeight - 20, rhinoJump2[1]);
		}
	}
	else
	{
		if (rhiStand)
		{
			iShowImage(rx, ry, rhinoWidth, rhinoHeight, rhinoStand[rhinoIndex]);
		}

		else if (!rhiStand && rhinoRIGHT == true)
		{
			iShowImage(rx, ry, rhinoWidth, rhinoHeight, rhinoRun1[rhino1index]);

			rhinoStandCounter++;

			if (rhinoStandCounter >= 300)
			{
				rhinoStandCounter = 0;
				rhino1index = 0;
				rhiStand = true;
				rhinoRIGHT = false;
			}

		}

		else if (!rhiStand && rhinoLEFT == true)
		{
			iShowImage(rx, ry, rhinoWidth, rhinoHeight, rhinoRun2[rhino2index]);


			rhinoStandCounter++;

			if (rhinoStandCounter >= 300)
			{
				rhinoStandCounter = 0;
				rhino2index = 0;
				rhiStand = true;
				rhinoLEFT = false;
			}

		}

		else if (!rhiStand && rhinoPun)
		{
			iShowImage(rx, ry, rhinoWidth, rhinoHeight, rhinoPunch[rhinoPunchIndex]);
			rhinoStandCounter++;
			if (rhinoStandCounter >= 350)
			{
				rhinoStandCounter = 0;
				rhinoPunchIndex = 0;
				rhiStand = true;
				rhinoPun = false;
			}
		}

		else if (!rhiStand && rhinoKic)
		{
			iShowImage(rx, ry, rhinoWidth, rhinoHeight, rhinoKick[rhinoKickIndex]);
			rhinoStandCounter++;
			if (rhinoStandCounter >= 350)
			{
				rhinoStandCounter = 0;
				rhinoKickIndex = 0;
				rhiStand = true;
				rhinoKic = false;
			}
		}
		else if (!rhiStand && rhinoUlti)
		{
			iShowImage(rx, ry, rhinoWidth, rhinoHeight, rhinoUlt[rhinoUltIndex]);
			rhinoStandCounter++;
			if (rhinoStandCounter >= 400)
			{
				rhinoStandCounter = 0;
				rhinoUltIndex = 0;
				rhiStand = true;
				rhinoUlti = false;
			}
		}
	}
}

void setWebVariables2();
void webMovement2()
{
	if (ulti2)
	{
		for (int i = 0; i < webNumber; i++)
		{
			if (webs2[i].webShow2)
			{
				iShowImage(webs2[i].webX2, webs2[i].webY2, 57, 54, Web2[webs2[i].webIndex2]);
			}
		}
	}
}

void setAll2()
{
	int sum2 = 0;
	for (int i = 0; i < 4; i++)
	{
		mainbg2[i].y2 = 0;
		mainbg2[i].x2 = sum2;
		sum2 += screenWidth; // Increment x-coordinate by screenWidth to line up images horizontally
	}
}

void setWebVariables2()
{
	for (int i = 0; i < webNumber; i++)
	{
		webs2[i].webX2 = x2;
		webs2[i].webY2 = y2 + 35 + (peterCordinateJump2);
		webs2[i].webIndex2 = 0;
		webs2[i].webShow2 = true;
	}
}


void peterImages2()
{
	//peter icon
	spideyIcon = iLoadImage("rhi\\spidey.png");
	t1 = iLoadImage("rhi\\txt1.png");

	//snippets for stand
	peterStand2[0] = iLoadImage("rhi\\s\\s0.png");
	peterStand2[1] = iLoadImage("rhi\\s\\s1.png");
	peterStand2[2] = iLoadImage("rhi\\s\\s2.png");

	//snippets for punching
	punch2[0] = iLoadImage("rhi\\punch\\p1.png");
	punch2[1] = iLoadImage("rhi\\punch\\p2.png");
	punch2[2] = iLoadImage("rhi\\punch\\p3.png");
	punch2[3] = iLoadImage("rhi\\punch\\p4.png");
	punch2[4] = iLoadImage("rhi\\punch\\p5.png");
	punch2[5] = iLoadImage("rhi\\punch\\p6.png");
	punch2[6] = iLoadImage("rhi\\punch\\p7.png");

	//snippets for kicking
	kick2[0] = iLoadImage("rhi\\kick\\k1.png");
	kick2[1] = iLoadImage("rhi\\kick\\k2.png");
	kick2[2] = iLoadImage("rhi\\kick\\k3.png");
	kick2[3] = iLoadImage("rhi\\kick\\k4.png");

	//block
	block2 = iLoadImage("rhi\\block\\tile001.png");

	//snippets for ult
	ult2 = iLoadImage("rhi\\tile003.png");


	//web images
	Web2[0] = iLoadImage("rhi\\web\\tile000.png");
	Web2[1] = iLoadImage("rhi\\web\\tile001.png");

	//snippets for running right
	peterRun12[0] = iLoadImage("rhi\\r\\r0.png");
	peterRun12[1] = iLoadImage("rhi\\r\\r1.png");
	peterRun12[2] = iLoadImage("rhi\\r\\r2.png");
	peterRun12[3] = iLoadImage("rhi\\r\\r3.png");
	peterRun12[4] = iLoadImage("rhi\\r\\r4.png");
	peterRun12[5] = iLoadImage("rhi\\r\\r5.png");
	peterRun12[6] = iLoadImage("rhi\\r\\r6.png");

	//snippets for running left
	peterRun22[0] = iLoadImage("rhi\\l\\L0.png");
	peterRun22[1] = iLoadImage("rhi\\l\\L1.png");
	peterRun22[2] = iLoadImage("rhi\\l\\L2.png");
	peterRun22[3] = iLoadImage("rhi\\l\\L3.png");
	peterRun22[4] = iLoadImage("rhi\\l\\L4.png");
	peterRun22[5] = iLoadImage("rhi\\l\\L5.png");
	peterRun22[6] = iLoadImage("rhi\\l\\L6.png");

	//snippets for jumping
	peterJump2[0] = iLoadImage("rhi\\jump\\jump1.png");
	peterJump2[1] = iLoadImage("rhi\\jump\\jump2.png");
	peterJump12[0] = iLoadImage("rhi\\jump\\jumpL1.png");
	peterJump12[1] = iLoadImage("rhi\\jump\\jumpL2.png");


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




}

void rhinoImages()
{
	//snippets for stand
	rhinoStand[0] = iLoadImage("rhi\\rhinoStand\\tile003.png");
	rhinoStand[1] = iLoadImage("rhi\\rhinoStand\\tile002.png");
	rhinoStand[2] = iLoadImage("rhi\\rhinoStand\\tile001.png");
	rhinoStand[3] = iLoadImage("rhi\\rhinoStand\\tile000.png");

	//snippets for running right
	rhinoRun1[0] = iLoadImage("rhi\\rhinoRunRight\\image_0.png");
	rhinoRun1[1] = iLoadImage("rhi\\rhinoRunRight\\image_1.png");
	rhinoRun1[2] = iLoadImage("rhi\\rhinoRunRight\\image_2.png");
	rhinoRun1[3] = iLoadImage("rhi\\rhinoRunRight\\image_3.png");
	rhinoRun1[4] = iLoadImage("rhi\\rhinoRunRight\\image_4.png");
	rhinoRun1[5] = iLoadImage("rhi\\rhinoRunRight\\image_5.png");
	rhinoRun1[6] = iLoadImage("rhi\\rhinoRunRight\\image_6.png");
	rhinoRun1[7] = iLoadImage("rhi\\rhinoRunRight\\image_7.png");
	rhinoRun1[8] = iLoadImage("rhi\\rhinoRunRight\\image_8.png");
	rhinoRun1[9] = iLoadImage("rhi\\rhinoRunRight\\image_9.png");
	rhinoRun1[10] = iLoadImage("rhi\\rhinoRunRight\\image_10.png");

	//snippets for running left
	rhinoRun2[0] = iLoadImage("rhi\\rhinoRunLeft\\image_0.png");
	rhinoRun2[1] = iLoadImage("rhi\\rhinoRunLeft\\image_1.png");
	rhinoRun2[2] = iLoadImage("rhi\\rhinoRunLeft\\image_2.png");
	rhinoRun2[3] = iLoadImage("rhi\\rhinoRunLeft\\image_3.png");
	rhinoRun2[4] = iLoadImage("rhi\\rhinoRunLeft\\image_4.png");
	rhinoRun2[5] = iLoadImage("rhi\\rhinoRunLeft\\image_5.png");
	rhinoRun2[6] = iLoadImage("rhi\\rhinoRunLeft\\image_6.png");
	rhinoRun2[7] = iLoadImage("rhi\\rhinoRunLeft\\image_7.png");
	rhinoRun2[8] = iLoadImage("rhi\\rhinoRunLeft\\image_8.png");
	rhinoRun2[9] = iLoadImage("rhi\\rhinoRunRLeft\\image_9.png");
	rhinoRun2[10] = iLoadImage("rhi\\rhinoRunRLeft\\image_10.png");

	//snippets for rhinojumping
	rhinoJump2[0] = iLoadImage("rhi\\rjump\\rj1.png");
	rhinoJump2[1] = iLoadImage("rhi\\rjump\\rj2.png");
	rhinoJump1[0] = iLoadImage("rhi\\rjump\\lj1.png");
	rhinoJump1[1] = iLoadImage("rhi\\rjump\\lj2.png");

	//snippets for rhino punching
	rhinoPunch[0] = iLoadImage("rhi\\rpun\\1.png");
	rhinoPunch[1] = iLoadImage("rhi\\rpun\\2.png");
	rhinoPunch[2] = iLoadImage("rhi\\rpun\\3.png");
	rhinoPunch[3] = iLoadImage("rhi\\rpun\\4.png");
	rhinoPunch[4] = iLoadImage("rhi\\rpun\\5.png");
	rhinoPunch[5] = iLoadImage("rhi\\rpun\\6.png");
	rhinoPunch[6] = iLoadImage("rhi\\rpun\\7.png");

	//snippets for rhino kicking
	rhinoKick[0] = iLoadImage("rhi\\rkick\\1.png");
	rhinoKick[1] = iLoadImage("rhi\\rkick\\2.png");
	rhinoKick[2] = iLoadImage("rhi\\rkick\\3.png");
	rhinoKick[3] = iLoadImage("rhi\\rkick\\4.png");


	//snippets for rhino ult
	rhinoUlt[0] = iLoadImage("rhi\\rult\\1.png");
	rhinoUlt[1] = iLoadImage("rhi\\rult\\2.png");
	rhinoUlt[2] = iLoadImage("rhi\\rult\\3.png");
	rhinoUlt[3] = iLoadImage("rhi\\rult\\4.png");
	rhinoUlt[4] = iLoadImage("rhi\\rult\\5.png");
	rhinoUlt[5] = iLoadImage("rhi\\rult\\6.png");
	rhinoUlt[6] = iLoadImage("rhi\\rult\\7.png");

	//iSetTimer(15,changex2);
	//displaying rhino text and pic
	imga = iLoadImage("rpic.png");
	imgb = iLoadImage("rtext.png");
}


