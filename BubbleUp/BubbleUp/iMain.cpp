/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"

/* 
	function iDraw() is called again and again by the system.
*/
char ball[10][20]={"ball\\1.bmp","ball\\2.bmp","ball\\3.bmp","ball\\4.bmp","ball\\5.bmp","ball\\6.bmp","ball\\7.bmp","ball\\8.bmp","ball\\9.bmp","ball\\10.bmp"};
char bg[30][20]={"bg\\1.bmp","bg\\2.bmp","bg\\3.bmp","bg\\4.bmp","bg\\5.bmp","bg\\6.bmp","bg\\7.bmp","bg\\8.bmp","bg\\9.bmp","bg\\10.bmp","bg\\11.bmp","bg\\12.bmp","bg\\13.bmp","bg\\14.bmp","bg\\15.bmp","bg\\16.bmp","bg\\17.bmp","bg\\18.bmp","bg\\19.bmp","bg\\20.bmp","bg\\21.bmp","bg\\22.bmp","bg\\23.bmp","bg\\24.bmp","bg\\25.bmp","bg\\26.bmp","bg\\27.bmp","bg\\28.bmp","bg\\29.bmp","bg\\30.bmp"};
int ballnum=0;
int i=0;
int ballx=200;

int bally=600;

struct pform{
int pformx;
	int pformy;
}a[7];

bool jump=false;
bool startingposition=true;
int tempy=0;


bool gravitych=true; 
bool jumpch=true;
int speed=1;
int start;
int end;
char times[10];
char timem[10];
int bgx[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int bgy[30]={0,42,84,126,168,210,252,294,336,378,420,462,504,546,588,630,672,714,756,798,840,882,924,966,1008,1050,1092,1134,1176,1218};
int background=0;
int menuspy=360;
int menuch=0;
int t;
int start2;
int end2;
int t2=0;
int s;
int m;
bool timep=false;
int tempt2;
int score=0;
char sscore[10];
char pname[50];
int namelen=0;
struct playerinfo{
char hsname[50];
int hsscore;
}pl[6],pl2[6],ptemp;
int k;
int life=3;
char slife[2];
int dx=120*rand()%6;
int dy=750*(rand()%4+1);


void svalue(){
	score=0;
	 ballnum=0;
	 life=3;
	 dx=120*rand()%6;
dy=750*(rand()%4+1);
i=0;
ballx=200;
bally=600;
jump=false;
startingposition=true;
tempy=0;
gravitych=true; 
jumpch=true;
speed=1;
int temp=0;
for(i=0;i<30;i++){
 bgx[i]=0;
 bgy[i]=temp;
	 temp+=42;
}
background=0;
menuspy=360;
menuch=0;
	iResumeTimer(0);
	iResumeTimer(1);
	iResumeTimer(2);
	iResumeTimer(3);
	iResumeTimer(4);
	iResumeTimer(5);
	iResumeTimer(6);
	iResumeTimer(7);
	start=clock();
}
void checkscore(){
	int index;
    FILE *pn;
	int i,j;
	pl[5].hsscore=score;
	pname;
	pn=fopen("highscore.txt","r");

	for(i=0;i<5;i++){
	fscanf(pn,"%d\t%[^\n]",&pl[i].hsscore,pl[i].hsname);

	}
	fclose(pn);
	if(score>pl[4].hsscore){
	background=3;
	}
	else
	{
		if(background!=4){
		svalue();
	background=0;
		}
	}
}
void gameover(){
	int index;
    FILE *pn2;
	int i,j;
		pn2=fopen("highscore.txt","w");
	for(i=4;i>=0;i--){
            if(score>pl[i].hsscore){
                index=i;
            }
            else
                break;
	}
	for(i=0,j=0;j<5;j++,i++)
{
    if(j==index){
            fprintf(pn2,"%d\t%s\n",score,pname);
            i--;

    }
    else
		fprintf(pn2,"%d\t%s\n",pl[i].hsscore,pl[i].hsname);
}

	fclose(pn2);
}
void changespeed(){
	if(t==30||t==59){
speed++;
	}
}
void diamondposition(){
if(dy==0)
{
	dx=120*(rand()%6);
	dy=750*(rand()%4+1);
}
else
	dy-=speed;
}
void getdiamond(){
if (ballx<dx+32&&ballx+32>dx&&bally<dy+32&&32+bally>dy){
		score+=10;
		dx=120*rand()%6;
		dy=750*(rand()%4+1);
	}
}



void iDraw()
{
	//place your drawing codes here	
	iClear();
	if(timep){
	end2=clock();
	t2=((end2-start2)/CLOCKS_PER_SEC)+tempt2;
	}
	if(background==1){
	
		
	for(i=0;i<30;i++)
	iShowBMP(bgx[i],bgy[i],bg[i]);
	getdiamond();
	iShowBMP2(dx,dy,"diamond.bmp",0);
	iShowBMP2(ballx,bally,ball[ballnum],0);
	iShowBMP2(a[0].pformx,a[0].pformy,"platform.bmp",0);
	iShowBMP2(a[1].pformx,a[1].pformy,"platform.bmp",0);
	iShowBMP2(a[2].pformx,a[2].pformy,"platform.bmp",0);
	iShowBMP2(a[3].pformx,a[3].pformy,"platform.bmp",0);
	iShowBMP2(a[4].pformx,a[4].pformy,"platform.bmp",0);
	iShowBMP2(a[5].pformx,a[5].pformy,"platform.bmp",0);
	iShowBMP2(a[6].pformx,a[6].pformy,"platform.bmp",0);
	
	iShowBMP2(0,0,"thornes.bmp",0);
	iSetColor(0,255,0);
	_itoa(score,sscore,10);
	iText(600, 680, "Score:", GLUT_BITMAP_TIMES_ROMAN_24);
	 iText(680, 680, sscore, GLUT_BITMAP_TIMES_ROMAN_24); 
	 _itoa(life,slife,10);
	iText(20, 680, "Life:", GLUT_BITMAP_TIMES_ROMAN_24);
	 iText(70, 680, slife, GLUT_BITMAP_TIMES_ROMAN_24); 
	end=clock();
	t=((end-start)/CLOCKS_PER_SEC)-t2;
	s=t%60;
	m=t/60;
	iSetColor(255,0,0);
	_itoa(s,times,10);
	 iText(390, 680, times, GLUT_BITMAP_HELVETICA_18); 
	 iText(360, 680," : ", GLUT_BITMAP_HELVETICA_18);
	 _itoa(m,timem,10);
	 iText(330, 680, timem, GLUT_BITMAP_HELVETICA_18);
	 if(bally<=10){
		 life--;
		 if(life==0)
			 checkscore();
		 else{
		 ballx=340;
		 bally=720;
		 }
	 }
	}
	if(background==0){
		
		iPauseTimer(0);
			iPauseTimer(1);
			iPauseTimer(2);
			iPauseTimer(3);
			iPauseTimer(4);
			iPauseTimer(5);
			iPauseTimer(6);
			iPauseTimer(7);
	iShowBMP(0,0,"Menu\\bg.bmp");
	iShowBMP2(250,menuspy,"Menu\\mselect.bmp",0);
	iShowBMP2(250,360,"Menu\\mstart.bmp",0);
	iShowBMP2(250,300,"Menu\\mhow.bmp",0);
	iShowBMP2(250,240,"Menu\\mscore.bmp",0);
	iShowBMP2(250,180,"Menu\\mcredits.bmp",0);
	iShowBMP2(250,120,"Menu\\mexit.bmp",0);
	
	}
	if(background==2){
		iShowBMP(0,0,"paused.bmp");
		
	}
	if(background==3){
		iShowBMP(0,0,"newhscore.bmp");
		iSetColor(254,239,56);
		iText(280, 140, pname, GLUT_BITMAP_TIMES_ROMAN_24); 
	}
	if(background==6){
		iShowBMP(0,0,"credits.bmp"); 
	}
	if(background==5){
		iShowBMP(0,0,"howto.bmp"); 
	}
	if(background==4){
	iShowBMP(0,0,"hscores.bmp");
	char showscore[5][100];
	checkscore();
	iSetColor(254,239,56);
	for(int i=0,j=420;i<5;i++,j=j-40)
		iText(140, j,pl[i].hsname, GLUT_BITMAP_TIMES_ROMAN_24); 
	
	iSetColor(255,0,0);
	for(int i=0,j=420;i<5;i++,j=j-40){
		_itoa(pl[i].hsscore,showscore[i],10);
	iText(400, j,showscore[i],GLUT_BITMAP_TIMES_ROMAN_24); 
	}
	
	}
	if(background==1){
	PlaySound("Closer.wav",NULL,SND_LOOP|SND_ASYNC|SND_NOSTOP);
	}
	else
		PlaySound(0,0,0);
	
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
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
		printf("%ld %ld",mx,my);

	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}
/*iPassiveMouseMove is called to detect and use 
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here
	
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/
 
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		//do something with 'q'
		
	}
	
	if(background==0)
	if(key == '\r'){
	if(menuch==0)
	{
		svalue();
		background=1;
		
	}
	if(menuch==2)
	{
		background=4;
	}
	if(menuch==4){
	exit(0);
	}
	if(menuch==3){
	background=6;
	}
	if(menuch==1){
	background=5;
	}
	}
	if(background==4){
		if(key == '\b'){
		background=0;
		}
	}
	if(background==3){
		if(key == '\r'){
			gameover();
		score=0;
		for(k=0;k<50;k++)
			pname[k]='\0';
		namelen=0;
	background=0;
	menuspy=360;
			menuch=0;
			
	}
		if(key=='\b'){
			if(namelen>0)
			namelen--;
	pname[namelen]='\0';
		}
	else{
	pname[namelen]=key;
	namelen++;
	}
	
	}

	if(background==2){
	if(key == 27){
		score=0;
		tempt2=0;
		t2=0;
		timep=false;
			background=0;
			menuspy=360;
			menuch=0;
	}
	if(key == '\r'){
		tempt2=t2;
		timep=false;
	background=1;
	iResumeTimer(0);
	iResumeTimer(1);
	iResumeTimer(2);
	iResumeTimer(3);
	iResumeTimer(4);
	iResumeTimer(5);
	iResumeTimer(6);
	iResumeTimer(7);
	}
	}
	if(background==1){
		
		if(key == 27){
			
			start2=clock();
			timep=true;
			background=2;
			iPauseTimer(0);
			iPauseTimer(1);
			iPauseTimer(2);
			iPauseTimer(3);
			iPauseTimer(4);
			iPauseTimer(5);
			iPauseTimer(6);
			iPauseTimer(7);
		}
	if(key == ' ')
	{
		
		if(jumpch){
		
		tempy=bally;
		bally+=8;
		jump=true;
		jumpch=false;
		}
	}
	}
	if(background==5)
		if(key == '\b'){
		background=0;
		}
	if(background==6)
		if(key == '\b'){
		background=0;
		}
	
	//place your codes for other keys here
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

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	if(background==1){
	if(key == GLUT_KEY_LEFT)
	{if(ballx>6)
		ballx-=(speed*6);	
	}
	if(key == GLUT_KEY_RIGHT)
	{
		if(ballx<698)
		ballx+=(speed*6);	
	}
	}
	if(background==0){
	if(key == GLUT_KEY_DOWN)
	{
			menuspy-=60;
			menuch+=1;
			if(menuspy<120){
				menuspy=360;
				menuch=0;
			}
	}
	if(key == GLUT_KEY_UP)
	{
			menuspy+=60;
			menuch-=1;
			if(menuspy>360){
				menuspy=120;
				menuch=4;
			}
	}
	
	}
	
	//place your codes for other keys here
}

void pformposition(){
	if(startingposition){
a[0].pformx=500;
a[0].pformy=170;
a[1].pformx=90;
a[1].pformy=340;
a[2].pformx=370;
a[2].pformy=510;
a[3].pformx=0;
a[3].pformy=680;
a[3].pformx=240;
a[4].pformy=850;
a[5].pformx=500;
a[5].pformy=1020;
a[6].pformx=240;
a[6].pformy=1190;
startingposition=false;
	}
for(i=0;i<7;i++)
{a[i].pformy-=speed;
if(a[i].pformy<=-190){
	score+=1;
	a[i].pformy=1000;
	srand(time(0));
	a[i].pformx=(rand()%6)*100;
	while(i>0&&a[i].pformx==a[i-1].pformx)
		a[i].pformx=(rand()%6)*100;
	if(a[6].pformx==a[0].pformx)
		a[0].pformx=(rand()%6)*100;
}

	
}

}
void bganimation(){
	for(i=0;i<30;i++){
	bgy[i]--;
	if(bgy[i]<-368)
		bgy[i]=890;
	}
}


void ballanimation(){
	ballnum++;
	if(ballnum>=10)
		ballnum=0;
}
void gravity(){
	for(i=0;i<7;i++){
	
	if((ballx-a[i].pformx>-30&&ballx-a[i].pformx<180)&&(bally-a[i].pformy<28&&bally-a[i].pformy>-28)){
		gravitych=false;
		jumpch=true;
		bally=bally+28-(bally-a[i].pformy);
	}
	else 
		gravitych=true;
	
	if(bally>10&&gravitych){
		
		 bally-=speed;
		 if(bally==11)
			 jumpch=true;
		
	}
}
	
}
void fjump(){
	if(jump){
	if(bally<tempy+330&&bally<720){
		bally+=7*speed;
		
		jumpch=false;
	}
	else
		
		jump=false;
	
	}

}
void jumpcollide(){for(i=0;i<7;i++){
	if((ballx-a[i].pformx>-30&&ballx-a[i].pformx<180)&&(bally-a[i].pformy<26&&bally-a[i].pformy>-30)){
		jump=false;
		gravity();
	}
	
}
}
//
int main()
{
	//place your own initialization codes here.
	
	iSetTimer(1,jumpcollide);
	iSetTimer(1,fjump);
	iSetTimer(40,gravity);
	iSetTimer(50,ballanimation);
	iSetTimer(50,bganimation);
	iSetTimer(25,pformposition);
	iSetTimer(1000,changespeed);
	iSetTimer(25,diamondposition);
	
	iInitialize(720, 720, "demooo");
	return 0;
}	