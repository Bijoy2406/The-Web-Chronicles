void drawPeterHealthBar5()				
{
	int barWidth = 325;					
	int barHeight = 25;					
	int barX = 200;
	int barY = screenHeight - 130;

	int healthBarWidth = (spidermanHealth5 * barWidth) / 1000; 
		

	iSetColor(255, 0, 0); 
	iFilledRectangle(barX, barY, barWidth, barHeight);
	if (spidermanHealth5 >= 0)
	{
		
		iSetColor(0, 255, 0); 
		iFilledRectangle(barX, barY, healthBarWidth, barHeight);
	}
}

void drawmysterioHealthBar()					
{
	int barWidth = 325;					
	int barHeight = 25;					
	int barX = screenWidth - (325 + 200);
	int barY = screenHeight - 130;
	
	int healthBarWidth = (mysterioHealth * barWidth) / 1000; 


	iSetColor(255, 0, 0); 
	iFilledRectangle(barX, barY, barWidth, barHeight);
	if (mysterioHealth >= 0){
		
		iSetColor(0, 255, 0); 
		iFilledRectangle(barX, barY, healthBarWidth, barHeight);
	}
}

void peterMovement5()
{
	if (jump5 && RIGHT5 == false && LEFT5 == false)
	{
		if (jumpUp5)
		{
			iShowImage(x5, y5 + peterCordinateJump5, peterWidth + 40, peterHeight + 30, peterJump5[0]);

		}
		else
		{
			iShowImage(x5, y5 + peterCordinateJump5, peterWidth + 40, peterHeight + 30, peterJump5[1]);
		}
	}
	if (jump5)
	{
		if (jumpUp5 == true && RIGHT5 == true)
		{
			iShowImage(x5, y5 + peterCordinateJump5, peterWidth + 40, peterHeight + 30, peterJump5[0]);
		}
		else if (jumpUp5 == false && RIGHT5 == true)
		{
			iShowImage(x5, y5 + peterCordinateJump5, peterWidth + 40, peterHeight + 30, peterJump5[1]);
		}

		if (jumpUp5 == true && LEFT5 == true)
		{
			iShowImage(x5, y5 + peterCordinateJump5, peterWidth + 40, peterHeight + 30, peterJump15[0]);
		}
		else if (jumpUp5 == false && LEFT5 == true)
		{
			iShowImage(x5, y5 + peterCordinateJump5, peterWidth + 40, peterHeight + 30, peterJump15[1]);
		}
	}
	else
	{
		if (stand5)
		{
			iShowImage(x5, y5, peterWidth - 70, peterHeight + 20, peterStand5[sindex5]);
		}

		else if (!stand5 && RIGHT5 == true)
		{
			ulti5 = false;
			iShowImage(x5, y5, peterWidth - 40, peterHeight + 10, peterRun15[r1index5]);

			standCounter5++;

			if (standCounter5 >= 200)
			{
				standCounter5 = 0;
				r1index5 = 0;
				stand5 = true;
				RIGHT5 = false;
			}

		}

		else if (!stand5 && LEFT5 == true)
		{
			ulti5 = false;
			iShowImage(x5, y5, peterWidth - 40, peterHeight + 10, peterRun25[r2index5]);

			standCounter5++;

			if (standCounter5 >= 200)
			{
				standCounter5 = 0;
				r2index5 = 0;
				stand5 = true;
				LEFT5 = false;
			}
		}

		else if (!stand5 && pun5)
		{
			ulti5 = false;
			iShowImage(x5 + 3, y5 + 10, peterWidth + 20, peterHeight, punch5[punchIndex5]);
			standCounter5++;
			if (standCounter5 >= 300)
			{
				standCounter5 = 0;
				punchIndex5 = 0;
				stand5 = true;
				pun5 = false;
			}
		}

		else if (!stand5 && kic5)
		{
			ulti5 = false;
			iShowImage(x5 - 5, y5 - 200, peterWidth + 800, peterHeight + 400, kick5[kickIndex5]);
			standCounter5++;
			if (standCounter5 >= 280)
			{
				standCounter5 = 0;
				punchIndex5 = 0;
				stand5 = true;
				kic5 = false;
			}
		}

		else if (!stand5 && bloc5)
		{
			ulti5 = false;
			iShowImage(x5, y5, peterWidth + 80, peterHeight + 20, block5);
			standCounter5++;
			if (standCounter5 >= 600)
			{
				standCounter5 = 0;
				blockIndex5 = 0;
				stand5 = true;
				bloc5 = false;
			}
		}

		else if (!stand5 && movebg5)
		{
			standCounter5++;
			if (standCounter5 >= 150)
			{
				standCounter5 = 0;
				punchIndex5 = 0;
				stand5 = true;
				movebg5 = false;
			}
		}

		else if (!stand5 && ulti5)
		{
			iShowImage(x5, y5, peterWidth + 70, peterHeight - 30, ult5);
			standCounter5++;
			if (standCounter5 >= 700)
			{
				standCounter5 = 0;
				ultIndex5 = 0;
				stand5 = true;
				ulti5 = false;
			}
		}

		//________________extra_______________________//
		else if (!stand5 && ulti25)
		{
			iShowImage(x5, y5, peterWidth - 70, peterHeight + 20, imgst);
			iShowImage(msx - 120, msy + 80, 230, 250, ult25[ultIndex25]);
			standCounter5++;
			if (standCounter5 >= 700)
			{
				standCounter5 = 0;
				ultIndex25 = 0;
				stand5 = true;
				ulti25 = false;
			}
		}

		else if (!stand5 && ulti35)
		{
			iShowImage(x5, y5, peterWidth - 70, peterHeight + 20, imgst);
			iShowImage(msx - 120, msy + 90, 240, 225, ult35[ultIndex35]);
			standCounter5++;
			if (standCounter5 >= 700)
			{
				standCounter5 = 0;
				ultIndex35 = 0;
				stand5 = true;
				ulti35 = false;
			}
		}

		//______________________extra_______________________//

	}
}

void mysterioMovement()
{

	if (mysterioJump && mysterioRIGHT == false && mysterioLEFT == false)
	{
		if (mysterioJumpUp)
		{
			iShowImage(msx, msy + mysterioCordinateJump, mysterioWidth - 240, mysterioHeight - 180, mysterioJump1[0]);
		}
		else
		{
			iShowImage(msx, msy + mysterioCordinateJump + 100, mysterioWidth - 240, mysterioHeight - 180, mysterioJump1[1]);
		}
	}
	if (mysterioJump)
	{
		if (mysterioJumpUp == true && mysterioRIGHT == true)
		{
			iShowImage(msx, msy + mysterioCordinateJump, mysterioWidth - 240, mysterioHeight - 180, mysterioJump1[0]);
		}
		else if (mysterioJumpUp == false && mysterioRIGHT == true)
		{
			iShowImage(msx, msy + mysterioCordinateJump + 100, mysterioWidth - 240, mysterioHeight - 180, mysterioJump1[1]);
		}

		if (mysterioJumpUp == true && mysterioLEFT == true)
		{
			iShowImage(msx, msy + mysterioCordinateJump, mysterioWidth - 240, mysterioHeight - 180, mysterioJump2[0]);
		}
		else if (mysterioJumpUp == false && mysterioLEFT == true)
		{
			iShowImage(msx, msy + mysterioCordinateJump + 100, mysterioWidth - 240, mysterioHeight - 180, mysterioJump2[1]);
		}
	}


	else
	{

		if (mysStand)
		{
			iShowImage(msx, msy + 80, mysterioWidth - 280, mysterioHeight - 230, mysterioStand[mysterioIndex]);
		}

		else if (!mysStand && mysterioRIGHT == true)
		{
			iShowImage(msx, msy + 80, mysterioWidth - 280, mysterioHeight - 230, mysterioRun1[mysterio1index]);

			mysterioStandCounter++;

			if (mysterioStandCounter >= 300)
			{
				mysterioStandCounter = 0;
				mysterio1index = 0;
				mysStand = true;
				mysterioRIGHT = false;
			}

		}

		else if (!mysStand && mysterioLEFT == true)
		{
			iShowImage(msx, msy + 80, mysterioWidth - 280, mysterioHeight - 230, mysterioRun2[mysterio2index]);


			mysterioStandCounter++;

			if (mysterioStandCounter >= 250)
			{
				mysterioStandCounter = 0;
				mysterio2index = 0;
				mysStand = true;
				mysterioLEFT = false;
			}

		}

		else if (!mysStand && mysterioPun)
		{
			iShowImage(msx, msy + 80, mysterioWidth - 280, mysterioHeight - 230, mysterioPunch[mysterioPunchIndex]);
			mysterioStandCounter++;
			if (mysterioStandCounter >= 150)
			{
				mysterioStandCounter = 0;
				mysterioPunchIndex = 0;
				mysStand = true;
				mysterioPun = false;
			}
		}

		else if (!mysStand && mysterioKic)
		{
			iShowImage(msx, msy + 80, mysterioWidth - 280, mysterioHeight - 230, mysterioKick[mysterioKickIndex]);
			mysterioStandCounter++;
			if (mysterioStandCounter >= 250)
			{
				mysterioStandCounter = 0;
				mysterioKickIndex = 0;
				mysStand = true;
				mysterioKic = false;
			}
		}

		else if (!mysStand && mysterioUlti)
		{
			iShowImage(msx, msy + 80, mysterioWidth - 280, mysterioHeight - 230, mysterioUlt[mysterioUltIndex]);
			mysterioStandCounter++;
			if (mysterioStandCounter >= 400)
			{
				mysterioStandCounter = 0;
				mysterioUltIndex = 0;
				mysStand = true;
				mysterioUlti = false;
			}
		}

		else if (!mysStand && mysterioUlti2)
		{
			iShowImage(msx, msy + 80, mysterioWidth - 280, mysterioHeight - 230, mystImage);
			iShowImage(x5 - 80, y5 - 20, 300, 800, mysterioUlt2);
			mysterioStandCounter++;
			if (mysterioStandCounter >= 400)
			{
				mysterioStandCounter = 0;
				mysterioUltIndex = 0;
				mysStand = true;
				mysterioUlti2 = false;
			}
		}
	}


}
void setWebVariables5();
void webCollision5();
void webCollision25();
void webMovement5()
{
	if (ulti5)
	{
		for (int i = 0; i < webNumber; i++)
		{
			if (webs5[i].webShow5)
			{
				iShowImage(webs5[i].webX5 + 65, webs5[i].webY5 + 26, 57, 54, Web5[webs5[i].webIndex5]);
			}
		}
	}
}
void setAll5()
{
	int sum = 0;
	for (int i = 0; i < n5; i++)
	{
		mainbg5[i].y5 = 0;
		mainbg5[i].x5 = sum;
		sum += screenWidth; 
	}
}

void attack5()
{

	//Level-4
	sindex4++;
	if (sindex4 >= 3)
	{
		sindex4 = 0;
	}

	kravenIndex++;
	if (kravenIndex >= 7)
	{
		kravenIndex = 0;
	}

	if (pun4)
	{
		punchIndex4++;
		if (punchIndex4 >= 5)
		{
			punchIndex4 = 0;
		}
		stand4 = false;
		LEFT4 = false;
		RIGHT4 = false;
	}

	if (kravenPun)
	{
		kravenPunchIndex++;
		if (kravenPunchIndex >= 3)
		{
			kravenPunchIndex = 0;
		}
		kraStand = false;
		kravenLEFT = false;
		kravenRIGHT = false;
	}

	if (kic4)
	{
		kickIndex4++;
		if (kickIndex4 >= 4)
		{
			kickIndex4 = 0;
		}
		stand4 = false;
		LEFT4 = false;
		RIGHT4 = false;
	}
	if (kravenKic)
	{
		kravenKickIndex++;
		if (kravenKickIndex >= 11)
		{
			kravenKickIndex = 0;
		}
		kraStand = false;
		kravenLEFT = false;
		kravenRIGHT = false;
	}

	if (bloc4)
	{

		stand4 = false;
		LEFT4 = false;
		RIGHT4 = false;

	}

	if (ulti4)
	{
		ultIndex4++;

		stand4 = false;
		LEFT4 = false;
		RIGHT4 = false;

	}

	for (int i = 0; i < webNumber; i++)
	{
		webs4[i].webX4 += 150;
		if (webs4[i].webX4 >= screenWidth)
		{
			webs4[i].webX4 = 145 + x4;
			webs4[i].webY4 = 55 + y4;

		}
		webs4[i].webIndex4++;
		if (webs4[i].webIndex4 >= 2)
		{
			webs4[i].webIndex4 = 0;
		}
	}

	if (jump4 || jumpUp4)
	{
		for (int i = 0; i < webNumber; i++)
		{
			//webs4[i].webShow4 = false;
			webs4[i].webY4 = y4 + peterCordinateJump4;
		}
	}
	else if (!jump4)
	{
		for (int i = 0; i < webNumber; i++)
		{
			webs4[i].webShow4 = true;
		}
	}

	if (kravenUlti)
	{
		kravenUltIndex++;
		if (kravenUltIndex >= 10)
		{
			kravenUltIndex = 0;
		}
		kraStand = false;
		kravenLEFT = false;
		kravenRIGHT = false;
	}

	//level 5
	sindex5++;
	if (sindex5 >= 9)
	{
		sindex5 = 0;
	}

	mysterioIndex++;
	if (mysterioIndex >= 13)
	{
		mysterioIndex = 0;
	}

	if (pun5)
	{
		punchIndex5++;
		if (punchIndex5 >= 8)
		{
			punchIndex5 = 0;
		}
		stand5 = false;
		LEFT5 = false;
		RIGHT5 = false;
	}

	if (mysterioPun)
	{
		mysterioPunchIndex++;
		if (mysterioPunchIndex >= 3)
		{
			mysterioPunchIndex = 0;
		}
		mysStand = false;
		mysterioLEFT = false;
		mysterioRIGHT = false;
	}

	if (ulti5)
	{
		ultIndex5++;

		stand5 = false;
		LEFT5 = false;
		RIGHT5 = false;

	}

	for (int i = 0; i < webNumber; i++)
	{
		webs5[i].webX5 += 150;
		if (webs5[i].webX5 >= screenWidth)
		{
			webs5[i].webX5 = 145 + x5;
			webs5[i].webY5 = 85 + y5;

		}
		webs5[i].webIndex5++;
		if (webs5[i].webIndex5 >= 2)
		{
			webs5[i].webIndex5 = 0;
		}
	}

	if (jump5 || jumpUp5)
	{
		for (int i = 0; i < webNumber; i++)
		{
			//webs5[i].webShow5 = false;
			webs5[i].webY5 = y5 + peterCordinateJump5;
		}
	}
	else if (!jump5)
	{
		for (int i = 0; i < webNumber; i++)
		{
			webs5[i].webShow5 = true;
		}
	}

	if (mysterioUlti)
	{
		mysterioUltIndex++;
		if (mysterioUltIndex >= 8)
		{
			mysterioUltIndex = 0;
		}
		mysStand = false;
		mysterioLEFT = false;
		mysterioRIGHT = false;
	}

	if (mysterioUlti2)
	{
		mysStand = false;
		mysterioLEFT = false;
		mysterioRIGHT = false;
	}

	if (bloc5)
	{

		stand5 = false;
		LEFT5 = false;
		RIGHT5 = false;

	}

	if (kic5)
	{
		kickIndex5++;
		if (kickIndex5 >= 4)
		{
			kickIndex5 = 0;
		}
		stand5 = false;
		LEFT5 = false;
		RIGHT5 = false;
	}
	if (mysterioKic)
	{
		mysterioKickIndex++;
		if (mysterioKickIndex >= 5)
		{
			mysterioKickIndex = 0;
		}
		mysStand = false;
		mysterioLEFT = false;
		mysterioRIGHT = false;
	}

	if (mysterioUlti2 && !bloc5)
	{
		spidermanHealth5 -= 15;
	}
	//___________extra_____________//
	if (ulti25)
	{

		ultIndex25++;
		if (ultIndex25 >= 11)
		{
			ultIndex25 = 0;

		}
		stand5 = false;
		LEFT5 = false;
		RIGHT5 = false;
	}

	if (ulti35)
	{

		ultIndex35++;
		if (ultIndex35 >= 9)
		{
			ultIndex35 = 0;

		}
		stand5 = false;
		LEFT5 = false;
		RIGHT5 = false;
	}

	if (ulti25 && !mysterioJump)
	{
		mysterioHealth -= 5;
	}

	if (ulti35 && !mysterioJump)
	{
		mysterioHealth -= 5;
	}
	//________________________________//
}

void setWebVariables5()
{
	for (int i = 0; i < webNumber; i++)
	{
		webs5[i].webX5 = x5;
		webs5[i].webY5 = y5 + 85;
		webs5[i].webIndex5 = 0;
		webs5[i].webShow5 = true;
	}
}

void peterImages5()
{

	
	
}
