struct scores
{
	char name[20];
	int score;
	void setScore(scores x)
	{

		strcpy(name, x.name);
		score = x.score;
	}

}s[6], player, temp;

char hs1[20], hs2[20], hs3[20], hs4[20], hs5[20];
int score1 = 0, score2 = 0, score3 = 0, score4 = 0, score5 = 0;
int len = 0, score = 0;
char score11[10], score22[10], score33[10], score44[10], score55[10];

void sort()
{
	int i = 0;
	FILE *fp;
	fp = fopen("highScore.bin", "rb");
	if (fp == NULL)
	{
		printf("file notfound\n");
	}
	else{
		while (i<6 && fread(&s[i], sizeof(struct scores), 1, fp) == 1) {
			i++;
			//cout << "call" << endl;
		}
	}
	fclose(fp);
	int l = i;
	for (i = 0; i < l - 1; i++) {
		for (int j = 0; j < l - i - 1; j++) {
			if (s[j].score < s[j + 1].score) {  
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}
	FILE *dp;
	dp = fopen("highScore.bin", "wb");
	for (int i = 0; i < 5; i++){
		fwrite(&s[i], sizeof(struct scores), 1, dp);
	}

	fclose(dp);
}
void saveScore()
{
	strcpy(s[5].name, player.name);
	s[5].score = player.score;
	FILE *fp;
	fp = fopen("highScore.bin", "ab");
	{
		fwrite(&s[5], sizeof(struct scores), 2, fp);
	}
	fclose(fp);
}
void HighScore()
{
	strcpy(hs1, s[0].name);
	score1 = s[0].score;

	strcpy(hs2, s[1].name);
	score2 = s[1].score;

	strcpy(hs3, s[2].name);
	score3 = s[2].score;

	strcpy(hs4, s[3].name);
	score4 = s[3].score;

	strcpy(hs5, s[4].name);
	score5 = s[4].score;
}