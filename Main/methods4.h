void drawPeterHealthBar4()				
{
	int barWidth = 325;					
	int barHeight = 25;					
	int barX = 200;
	int barY = screenHeight - 130;

	int healthBarWidth = (spidermanHealth4 * barWidth) / 1000; 


	iSetColor(255, 0, 0); 
	iFilledRectangle(barX, barY, barWidth, barHeight);
	if (spidermanHealth4 >= 0)
	{
		
		iSetColor(0, 255, 0); 
		iFilledRectangle(barX, barY, healthBarWidth, barHeight);
	}
}


void drawKravenHealthBar()					
{
	int barWidth = 325;					
	int barHeight = 25;					
	int barX = screenWidth - (325 + 160);
	int barY = screenHeight - 130;
	//iShowImage(1450, screenHeight - 190, 190, 190, kravenIcon);
	//iShowImage(990, screenHeight - 90, 450, 40, t2);
	int healthBarWidth = (kravenHealth * barWidth) / 1000; 





	iSetColor(255, 0, 0); 
	iFilledRectangle(barX, barY, barWidth, barHeight);
	if (kravenHealth >= 0){
		
		iSetColor(0, 255, 0); 
		iFilledRectangle(barX, barY, healthBarWidth, barHeight);
	}
}

void peterMovement4()
{
	if (jump4 && RIGHT4 == false && LEFT4 == false)
	{
		if (jumpUp4)
		{
			iShowImage(x4, y4 + peterCordinateJump4, peterWidth, peterHeight - 40, peterJump4[0]);

		}
		else
		{
			iShowImage(x4, y4 + peterCordinateJump4, peterWidth, peterHeight - 40, peterJump4[1]);
		}
	}
	if (jump4)
	{
		if (jumpUp4 == true && RIGHT4 == true)
		{
			iShowImage(x4, y4 + peterCordinateJump4, peterWidth, peterHeight - 40, peterJump4[0]);
		}
		else if (jumpUp4 == false && RIGHT4 == true)
		{
			iShowImage(x4, y4 + peterCordinateJump4, peterWidth, peterHeight - 40, peterJump4[1]);
		}

		if (jumpUp4 == true && LEFT4 == true)
		{
			iShowImage(x4, y4 + peterCordinateJump4, peterWidth, peterHeight - 40, peterJump14[0]);
		}
		else if (jumpUp4 == false && LEFT4 == true)
		{
			iShowImage(x4, y4 + peterCordinateJump4, peterWidth, peterHeight - 40, peterJump14[1]);
		}
	}
	else
	{
		if (stand4)
		{
			iShowImage(x4, y4, peterWidth, peterHeight - 40, peterStand4[sindex4]);
		}

		else if (!stand4 && RIGHT4 == true)
		{
			ulti4 = false;
			iShowImage(x4, y4, peterWidth, peterHeight - 40, peterRun14[r1index4]);

			standCounter4++;

			if (standCounter4 >= 200)
			{
				standCounter4 = 0;
				r1index4 = 0;
				stand4 = true;
				RIGHT4 = false;
			}

		}

		else if (!stand4 && LEFT4 == true)
		{
			ulti4 = false;
			iShowImage(x4, y4, peterWidth, peterHeight - 40, peterRun24[r2index4]);

			standCounter4++;

			if (standCounter4 >= 180)
			{
				standCounter4 = 0;
				r2index4 = 0;
				stand4 = true;
				LEFT4 = false;
			}
		}

		else if (!stand4 && pun4)
		{
			ulti4 = false;
			iShowImage(x4, y4, peterWidth, peterHeight - 15, punch4[punchIndex4]);
			standCounter4++;
			if (standCounter4 >= 200)
			{
				standCounter4 = 0;
				punchIndex4 = 0;
				stand4 = true;
				pun4 = false;
			}
		}

		else if (!stand4 && kic4)
		{
			ulti4 = false;
			iShowImage(x4, y4, peterWidth, peterHeight - 15, kick4[kickIndex4]);
			standCounter4++;
			if (standCounter4 >= 200)
			{
				standCounter4 = 0;
				punchIndex4 = 0;
				stand4 = true;
				kic4 = false;
			}
		}

		else if (!stand4 && bloc4)
		{
			ulti4 = false;
			iShowImage(x4, y4 - 60, peterWidth + 150, peterHeight + 60, block4);
			standCounter4++;
			if (standCounter4 >= 600)
			{
				standCounter4 = 0;
				blockIndex4 = 0;
				stand4 = true;
				bloc4 = false;
			}
		}

		else if (!stand4 && movebg4)
		{
			standCounter4++;
			if (standCounter4 >= 150)
			{
				standCounter4 = 0;
				punchIndex4 = 0;
				stand4 = true;
				movebg4 = false;
			}
		}

		else if (!stand4 && ulti4)
		{
			iShowImage(x4, y4 - 30, peterWidth + 30, peterHeight + 30, ult4);
			standCounter4++;
			if (standCounter4 >= 700)
			{
				standCounter4 = 0;
				ultIndex4 = 0;
				stand4 = true;
				ulti4 = false;
			}
		}

	}
}

void kravenMovement()
{

	if (kravenJump && kravenRIGHT == false && kravenLEFT == false)
	{
		if (kravenJumpUp)
		{
			iShowImage(kx, ky + kravenCordinateJump, kravenWidth - 250, kravenHeight + 60, kravenJump1[0]);
		}
		else
		{
			iShowImage(kx, ky + kravenCordinateJump, kravenWidth - 250, kravenHeight + 30, kravenJump1[1]);
		}
	}
	if (kravenJump)
	{
		if (kravenJumpUp == true && kravenRIGHT == true)
		{
			iShowImage(kx, ky + kravenCordinateJump, kravenWidth - 250, kravenHeight + 60, kravenJump1[0]);
		}
		else if (kravenJumpUp == false && kravenRIGHT == true)
		{
			iShowImage(kx, ky + kravenCordinateJump, kravenWidth - 250, kravenHeight + 30, kravenJump1[1]);
		}

		if (kravenJumpUp == true && kravenLEFT == true)
		{
			iShowImage(kx, ky + kravenCordinateJump, kravenWidth - 250, kravenHeight + 60, kravenJump2[0]);
		}
		else if (kravenJumpUp == false && kravenLEFT == true)
		{
			iShowImage(kx, ky + kravenCordinateJump, kravenWidth - 250, kravenHeight + 30, kravenJump2[1]);
		}
	}


	else
	{

		if (kraStand)
		{
			iShowImage(kx, ky, kravenWidth, kravenHeight, kravenStand[kravenIndex]);
		}

		else if (!kraStand && kravenRIGHT == true)
		{
			iShowImage(kx, -25, kravenWidth - 200, kravenHeight - 150, kravenRun1[kraven1index]);

			kravenStandCounter++;

			if (kravenStandCounter >= 300)
			{
				kravenStandCounter = 0;
				kraven1index = 0;
				kraStand = true;
				kravenRIGHT = false;
			}

		}

		else if (!kraStand && kravenLEFT == true)
		{
			iShowImage(kx - 30, -25, kravenWidth - 200, kravenHeight - 150, kravenRun2[kraven2index]);


			kravenStandCounter++;

			if (kravenStandCounter >= 300)
			{
				kravenStandCounter = 0;
				kraven2index = 0;
				kraStand = true;
				kravenLEFT = false;
			}

		}

		else if (!kraStand && kravenPun)
		{
			iShowImage(kx - 280, ky, kravenWidth + 130, kravenHeight - 40, kravenPunch[kravenPunchIndex]);
			kravenStandCounter++;
			if (kravenStandCounter >= 150)
			{
				kravenStandCounter = 0;
				kravenPunchIndex = 0;
				kraStand = true;
				kravenPun = false;
			}
		}

		else if (!kraStand && kravenKic)
		{
			iShowImage(kx - 150, 0, kravenWidth, kravenHeight, kravenKick[kravenKickIndex]);
			kravenStandCounter++;
			if (kravenStandCounter >= 550)
			{
				kravenStandCounter = 0;
				kravenKickIndex = 0;
				kraStand = true;
				kravenKic = false;
			}
		}

		else if (!kraStand && kravenUlti)
		{
			iShowImage(kx - 250, -55, kravenWidth + 150, kravenHeight - 40, kravenUlt[kravenUltIndex]);
			kravenStandCounter++;
			if (kravenStandCounter >= 400)
			{
				kravenStandCounter = 0;
				kravenUltIndex = 0;
				kraStand = true;
				kravenUlti = false;
			}
		}
	}


}

void webMovement4()
{
	if (ulti4)
	{
		for (int i = 0; i < webNumber; i++)
		{
			if (webs4[i].webShow4)
			{
				iShowImage(webs4[i].webX4 + 65, webs4[i].webY4 + 26, 57, 54, Web4[webs4[i].webIndex4]);
			}
		}
	}
}

void setAll4()
{
	int sum = 0;
	for (int i = 0; i < n4; i++)
	{
		mainbg4[i].y4 = 0;
		mainbg4[i].x4 = sum;
		sum += screenWidth; 
	}
}

void setWebVariables4()
{
	for (int i = 0; i < webNumber; i++)
	{
		webs4[i].webX4 = x4;
		webs4[i].webY4 = y4 + 35;
		webs4[i].webIndex4 = 0;
		webs4[i].webShow4 = true;
	}
}


void peterImages4()
{

	//snippets for stand
	peterStand4[0] = iLoadImage("kra\\s\\s.png");
	peterStand4[1] = iLoadImage("kra\\s\\s (1).png");
	peterStand4[2] = iLoadImage("kra\\s\\s (2).png");
	peterStand4[3] = iLoadImage("kra\\s\\s (3).png");
	peterStand4[4] = iLoadImage("kra\\s\\s (4).png");

	//iSetTimer(120, attack4);

	//snippets for running right
	peterRun14[0] = iLoadImage("kra\\r\\r.png");
	peterRun14[1] = iLoadImage("kra\\r\\r (1).png");
	peterRun14[2] = iLoadImage("kra\\r\\r (2).png");
	peterRun14[3] = iLoadImage("kra\\r\\r (3).png");
	peterRun14[4] = iLoadImage("kra\\r\\r (4).png");

	//snippets for running left
	peterRun24[0] = iLoadImage("kra\\l\\l (1).png");
	peterRun24[1] = iLoadImage("kra\\l\\l (2).png");
	peterRun24[2] = iLoadImage("kra\\l\\l (3).png");
	peterRun24[3] = iLoadImage("kra\\l\\l (4).png");
	peterRun24[4] = iLoadImage("kra\\l\\l (5).png");

	//snippets for jumping
	peterJump4[0] = iLoadImage("kra\\jump\\j (1).png");
	peterJump4[1] = iLoadImage("kra\\jump\\j (2).png");
	peterJump14[0] = iLoadImage("kra\\jump\\j (3).png");
	peterJump14[1] = iLoadImage("kra\\jump\\j (4).png");

	//snippets for punching
	punch4[0] = iLoadImage("kra\\punch\\p (1).png");
	punch4[1] = iLoadImage("kra\\punch\\p (2).png");
	punch4[2] = iLoadImage("kra\\punch\\p (3).png");
	punch4[3] = iLoadImage("kra\\punch\\p (4).png");
	punch4[4] = iLoadImage("kra\\punch\\p (5).png");

	//snippets for kicking
	kick4[0] = iLoadImage("kra\\kick\\k.png");
	kick4[1] = iLoadImage("kra\\kick\\k (1).png");
	kick4[2] = iLoadImage("kra\\kick\\k (2).png");
	kick4[3] = iLoadImage("kra\\kick\\k (3).png");
	kick4[4] = iLoadImage("kra\\kick\\k (4).png");


	//snippets for ult
	ult4 = iLoadImage("kra\\ult.png");

	//web images
	Web4[0] = iLoadImage("kra\\web\\tile000.png");
	Web4[1] = iLoadImage("kra\\web\\tile001.png");


	//block
	block4 = iLoadImage("kra\\block\\tile001.png");

	
}
void kravenImages()
{
	//snippets for stand
	kravenStand[0] = iLoadImage("kra\\ks\\s1.png");
	kravenStand[1] = iLoadImage("kra\\ks\\s2.png");
	kravenStand[2] = iLoadImage("kra\\ks\\s3.png");
	kravenStand[3] = iLoadImage("kra\\ks\\s4.png");
	kravenStand[4] = iLoadImage("kra\\ks\\s5.png");
	kravenStand[5] = iLoadImage("kra\\ks\\s6.png");
	kravenStand[6] = iLoadImage("kra\\ks\\s7.png");

	//snippets for running right
	kravenRun1[0] = iLoadImage("kra\\kw\\lr1.png");
	kravenRun1[1] = iLoadImage("kra\\kw\\lr2.png");
	kravenRun1[2] = iLoadImage("kra\\kw\\lr3.png");
	kravenRun1[3] = iLoadImage("kra\\kw\\lr4.png");
	kravenRun1[4] = iLoadImage("kra\\kw\\lr5.png");
	kravenRun1[5] = iLoadImage("kra\\kw\\lr6.png");
	kravenRun1[6] = iLoadImage("kra\\kw\\lr7.png");


	//snippets for running left
	kravenRun2[0] = iLoadImage("kra\\kw\\rr1.png");
	kravenRun2[1] = iLoadImage("kra\\kw\\rr2.png");
	kravenRun2[2] = iLoadImage("kra\\kw\\rr3.png");
	kravenRun2[3] = iLoadImage("kra\\kw\\rr4.png");
	kravenRun2[4] = iLoadImage("kra\\kw\\rr5.png");
	kravenRun2[5] = iLoadImage("kra\\kw\\rr6.png");
	kravenRun2[6] = iLoadImage("kra\\kw\\rr7.png");


	//snippets for rhinojumping
	kravenJump2[0] = iLoadImage("kra\\kj\\rj1.png");
	kravenJump2[1] = iLoadImage("kra\\kj\\rj2.png");
	kravenJump1[0] = iLoadImage("kra\\kj\\lj1.png");
	kravenJump1[1] = iLoadImage("kra\\kj\\lj2.png");


	//snippets for rhino punching
	kravenPunch[0] = iLoadImage("kra\\kp\\p1.png");
	kravenPunch[1] = iLoadImage("kra\\kp\\p2.png");
	kravenPunch[2] = iLoadImage("kra\\kp\\p3.png");

	//snippets for rhino kicking
	kravenKick[0] = iLoadImage("kra\\kk\\k1.png");
	kravenKick[1] = iLoadImage("kra\\kk\\k2.png");
	kravenKick[2] = iLoadImage("kra\\kk\\k3.png");
	kravenKick[3] = iLoadImage("kra\\kk\\k4.png");
	kravenKick[4] = iLoadImage("kra\\kk\\k5.png");
	kravenKick[5] = iLoadImage("kra\\kk\\k6.png");
	kravenKick[6] = iLoadImage("kra\\kk\\k7.png");
	kravenKick[7] = iLoadImage("kra\\kk\\k8.png");
	kravenKick[8] = iLoadImage("kra\\kk\\k9.png");
	kravenKick[9] = iLoadImage("kra\\kk\\k10.png");
	kravenKick[10] = iLoadImage("kra\\kk\\k11.png");

	//snippets for rhino ult
	kravenUlt[0] = iLoadImage("kra\\ku\\u1.png");
	kravenUlt[1] = iLoadImage("kra\\ku\\u2.png");
	kravenUlt[2] = iLoadImage("kra\\ku\\u3.png");
	kravenUlt[3] = iLoadImage("kra\\ku\\u4.png");
	kravenUlt[4] = iLoadImage("kra\\ku\\u5.png");
	kravenUlt[5] = iLoadImage("kra\\ku\\u6.png");
	kravenUlt[6] = iLoadImage("kra\\ku\\u7.png");
	kravenUlt[7] = iLoadImage("kra\\ku\\u8.png");
	kravenUlt[8] = iLoadImage("kra\\ku\\u9.png");
	kravenUlt[9] = iLoadImage("kra\\ku\\u10.png");

	imgk = iLoadImage("miles.png");
	imgl = iLoadImage("milestxt1.png");

	imgm = iLoadImage("kpicx.png");
	imgn = iLoadImage("ktextx.png");
	//kravenIcon = iLoadImage("kra\\kraven2.png");


	//snippets for stand
	mysterioStand[0] = iLoadImage("dd\\ms\\s (1).png");
	mysterioStand[1] = iLoadImage("dd\\ms\\s (2).png");
	mysterioStand[2] = iLoadImage("dd\\ms\\s (3).png");
	mysterioStand[3] = iLoadImage("dd\\ms\\s (4).png");
	mysterioStand[4] = iLoadImage("dd\\ms\\s (5).png");
	mysterioStand[5] = iLoadImage("dd\\ms\\s (6).png");
	mysterioStand[6] = iLoadImage("dd\\ms\\s (7).png");
	mysterioStand[7] = iLoadImage("dd\\ms\\s (8).png");
	mysterioStand[8] = iLoadImage("dd\\ms\\s (9).png");
	mysterioStand[9] = iLoadImage("dd\\ms\\s (10).png");
	mysterioStand[10] = iLoadImage("dd\\ms\\s (11).png");
	mysterioStand[11] = iLoadImage("dd\\ms\\s (12).png");
	mysterioStand[12] = iLoadImage("dd\\ms\\s (13).png");
	mysterioStand[13] = iLoadImage("dd\\ms\\s (14).png");

	//snippets for running right

	mysterioRun1[0] = iLoadImage("dd\\mw\\r (1).png");
	mysterioRun1[1] = iLoadImage("dd\\mw\\r (2).png");
	mysterioRun1[2] = iLoadImage("dd\\mw\\r (3).png");
	mysterioRun1[3] = iLoadImage("dd\\mw\\r (4).png");
	mysterioRun1[4] = iLoadImage("dd\\mw\\r (5).png");
	mysterioRun1[5] = iLoadImage("dd\\mw\\r (6).png");

	//snippets for running left

	mysterioRun2[0] = iLoadImage("dd\\mw\\l (1).png");
	mysterioRun2[1] = iLoadImage("dd\\mw\\l (2).png");
	mysterioRun2[2] = iLoadImage("dd\\mw\\l (3).png");
	mysterioRun2[3] = iLoadImage("dd\\mw\\l (4).png");
	mysterioRun2[4] = iLoadImage("dd\\mw\\l (5).png");
	mysterioRun2[5] = iLoadImage("dd\\mw\\l (6).png");

	//snippets for rhinojumping
	mysterioJump2[0] = iLoadImage("dd\\mj\\rj (1).png");
	mysterioJump2[1] = iLoadImage("dd\\mj\\rj (2).png");
	mysterioJump1[0] = iLoadImage("dd\\mj\\lj (1).png");
	mysterioJump1[1] = iLoadImage("dd\\mj\\lj (2).png");


	//snippets for rhino punching
	mysterioPunch[0] = iLoadImage("dd\\mp\\p (1).png");
	mysterioPunch[1] = iLoadImage("dd\\mp\\p (2).png");
	mysterioPunch[2] = iLoadImage("dd\\mp\\p (3).png");
	mysterioPunch[3] = iLoadImage("dd\\mp\\p (4).png");
	mysterioPunch[4] = iLoadImage("dd\\mp\\p (5).png");
	mysterioPunch[5] = iLoadImage("dd\\mp\\p (6).png");


	//snippets for rhino kicking
	mysterioKick[0] = iLoadImage("dd\\mk\\k (1).png");
	mysterioKick[1] = iLoadImage("dd\\mk\\k (2).png");
	mysterioKick[2] = iLoadImage("dd\\mk\\k (3).png");
	mysterioKick[3] = iLoadImage("dd\\mk\\k (4).png");
	mysterioKick[4] = iLoadImage("dd\\mk\\k (5).png");

	//snippets for rhino ult
	mysterioUlt[0] = iLoadImage("dd\\mu\\u (1).png");
	mysterioUlt[1] = iLoadImage("dd\\mu\\u (2).png");
	mysterioUlt[2] = iLoadImage("dd\\mu\\u (3).png");
	mysterioUlt[3] = iLoadImage("dd\\mu\\u (4).png");
	mysterioUlt[4] = iLoadImage("dd\\mu\\u (5).png");
	mysterioUlt[5] = iLoadImage("dd\\mu\\u (6).png");
	mysterioUlt[6] = iLoadImage("dd\\mu\\u (7).png");
	mysterioUlt[7] = iLoadImage("dd\\mu\\u (8).png");

	mysterioUlt2 = iLoadImage("dd\\sprite.png");
	mystImage = iLoadImage("dd\\sprite2.png");

	//iSetTimer(20, rhinoultim);

	mysterioIcon = iLoadImage("dd\\mysterio2.png");

}
