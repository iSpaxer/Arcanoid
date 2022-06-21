#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <locale.h>

#define length 40 //длинна ---
#define  wigth 20 //высота |
#define longRacket 7

typedef struct
{
	int x, y;
	int w;
}tRacket;
typedef struct
{
    float x,y;
    float alfa;
    float speed;
}tBall;
typedef struct
{
	int x, y;
	int w, s;
}tNumbers;

typedef struct
{
    int x,y;
}tNumeral;

BOOL KlickSPACE = FALSE;

tBall ball;
tRacket racket;
tNumbers numb;

int Win;
int Exit = 3;
char mass[wigth][length+1];
char nmass[wigth][length+1];

int i, j;

 //printf("!!213123123 %d - i, %d - j, %d X, %d - y, !%c!", i, j, searchXL, searchY, mass[searchY][searchXL]);  int asdad; scanf("%d", &asdad);


void PutNumb(int* count, int searchXR, int searchXL, int searchY)
{

    if (*count == 5)
    {
            i = 0; j = 0;
            for( searchXR ; nmass[searchY][searchXR] == '5'; searchXR++) //mass[searchY][XR]
                {
                    i++;
                }
            for(searchXL; nmass[searchY][searchXL] == '5' ; searchXL--)
                {
                    j++;
                }
                searchXL++;
                for(int k = 0; k < i + j - 1; k++)
                    nmass[searchY][searchXL + k] = '4';


    }
    if (*count == 4)
    {
            i = 0; j = 0;
            for( searchXR ; nmass[searchY][searchXR] == '4'; searchXR++) //mass[searchY][XR]
                {
                    i++;
                }
            for(searchXL; nmass[searchY][searchXL] == '4' ; searchXL--)
                {
                    j++;
                }
                searchXL++;
                for(int k = 0; k < i + j - 1; k++)
                    nmass[searchY][searchXL + k] = '3';



    }

    if (*count == 3)
    {
            i = 0; j = 0;
            for( searchXR ; nmass[searchY][searchXR] == '3'; searchXR++) //mass[searchY][XR]
                {
                    i++;
                }
            for(searchXL; nmass[searchY][searchXL] == '3' ; searchXL--)
                {
                    j++;
                }
                searchXL++;
                for(int k = 0; k < i + j - 1; k++)
                    nmass[searchY][searchXL + k] = '2';



    }

    if (*count == 2)
    {
            i = 0; j = 0;
            for( searchXR ; nmass[searchY][searchXR] == '2'; searchXR++) //mass[searchY][XR]
                {
                    i++;
                }
            for(searchXL; nmass[searchY][searchXL] == '2' ; searchXL--)
                {
                    j++;
                }
                searchXL++;
                for(int k = 0; k < i + j - 1; k++)
                    nmass[searchY][searchXL + k] = '1';


    }if (*count == 1)
    {
            i = 0; j = 0;
            for( searchXR ; nmass[searchY][searchXR] == '1'; searchXR++) //mass[searchY][XR]
                {
                    i++;
                }
            for(searchXL; nmass[searchY][searchXL] == '1' ; searchXL--)
                {
                    j++;
                }
                searchXL++;
                for(int k = 0; k < i + j - 1; k++)
                    nmass[searchY][searchXL + k] = ' ';


    }
    *count--;
    for (i = 1; i < numb.w; i++)
        strncpy (mass[i], nmass[i], length+1);

}

void initNumbers ()
{
    int omg;
    omg = rand() % 5 + 1;

    if ( omg == 1){
    for(i = 0; i < numb.s; i++)
        mass[numb.y][numb.x + i] = '1';
    }

    if ( omg == 2){
    for(i = 0; i < numb.s; i++)
        mass[numb.y][numb.x + i] = '2';
    }
    if ( omg == 3){
    for(i = 0; i < numb.s; i++)
        mass[numb.y][numb.x + i] = '3';
    }
    if ( omg == 4){
    for(i = 0; i < numb.s; i++)
        mass[numb.y][numb.x + i] = '4';
    }
    if ( omg == 5){
    for(i = 0; i < numb.s; i++)
        mass[numb.y][numb.x + i] = '5';
    }
    strncpy (nmass[numb.y], mass[numb.y], length+1);
}


void Numbers ()
{
    numb.w = (rand () % ((int)wigth / 6)) +(int)wigth/2;

    for (numb.y = 1; numb.y < numb.w; numb.y++)
    {

            for (numb.x = rand() % 2 + 1; numb.x < length; numb.x = numb.x + numb.s + rand() % 3)
            {
                numb.s = rand() % 5 + 3; //длинна. Пр: 1111
                if(length - numb.x > numb.s)
                       {
                           initNumbers();
                       }
            }


    }
}


void SpeedBall()
{
    ball.speed = 1;
}

void AlfaBall()
{
    ball.alfa = -1;
}

void initBall ()
{
        ball.y = (float)(racket.y - 1);
        ball.x = (float)(racket.x + (int)(racket.w / 2)) ;
}

void putBall ()
{
    mass[(int)round(ball.y)][(int)round(ball.x)] = '*';
}

void moveBall (int* count, int* searchXR, int* searchXL, int* searchY)
{

        if(GetKeyState('W') < 0)
            KlickSPACE = TRUE;

        if(KlickSPACE == FALSE)
        {
            ball.y = racket.y - 1;
            ball.x = racket.x + (int)(racket.w / 2) ;
        }
        else
            {
                ball.y = (ball.y + sin(ball.alfa) * ball.speed);
                ball.x = (ball.x + cos(ball.alfa) * ball.speed);
            }
        if((int)round(ball.y) == 0)
            ball.alfa = -ball.alfa;
        if(mass[(int)round(ball.y)][(int)round(ball.x)] == '@')
            ball.alfa = -ball.alfa;
        if ((int)round(ball.x) == 0 || (int)round(ball.x) == length-1)
            ball.alfa = M_PI - ball.alfa;





        if(mass[(int)round(ball.y)][(int)round(ball.x)] == '1')
        {
            ball.alfa = -ball.alfa;
            *searchY = (int)round(ball.y);

            *searchXR = (int)round(ball.x)  ;
            *searchXL = (int)round(ball.x) ;
            *count = 1;


        }

        if(mass[(int)round(ball.y)][(int)round(ball.x)] == '2')
        {
            ball.alfa = -ball.alfa;
            *searchY = (int)round(ball.y);

            *searchXR = (int)round(ball.x)  ;
            *searchXL = (int)round(ball.x) ;
            *count = 2;


        }
        if(mass[(int)round(ball.y)][(int)round(ball.x)] == '3')
        {
            ball.alfa = -ball.alfa;
            *searchY = (int)round(ball.y);

            *searchXR = (int)round(ball.x)  ;
            *searchXL = (int)round(ball.x) ;
            *count = 3;


        }
        if(mass[(int)round(ball.y)][(int)round(ball.x)] == '4')
        {
            ball.alfa = -ball.alfa;
            *searchY = (int)round(ball.y);

            *searchXR = (int)round(ball.x)  ;
            *searchXL = (int)round(ball.x) ;
            *count = 4;


        }
        if(mass[(int)round(ball.y)][(int)round(ball.x)] == '5')
        {
            ball.alfa = -ball.alfa;
            *searchY = (int)round(ball.y);

            *searchXR = (int)round(ball.x)  ;
            *searchXL = (int)round(ball.x) ;
            *count = 5;
        }

}

void initRacket (){ //координаты ракетки
	racket.w = longRacket;
	racket.x = (int)((length - racket.w) / 2) ;
	racket.y = wigth - 1;
}

void PutRacket () //рисовка ракетки
{

	for(i = 0; i < racket.w; i++)
		mass[racket.y][racket.x + i] = '@';
}

void init ()
{
	for (i = 0; i < length; i++)
	{
		mass[0][i] = '#'; //первая строка вся в #
	}
	for(i = 1; i < wigth; i++) //пробелы
        {
                mass[i][0] = '#';	//#____________#
                mass[i][length-1] = '#';
                for (j = 1; j< length-1; j++)
                {
                        mass[i][j] = ' ';
                }
        }
}


void paint ()
{

		for(i = 0; i < wigth; i++)
            {
                 printf("%s", mass[i]);
                if( i == 3)
                printf("      HP - %i   ", Exit);



                if (i < wigth - 1)
                    printf("\n");
            }



}

int moveRacket ()
{
	int old_x;// old_y
	old_x = racket.x;

        if(GetKeyState('D') < 0)
                racket.x++;
        if(GetKeyState('A') < 0)
                racket.x--;


	if(racket.x == 0 || (racket.x + racket.w) == length)//limitation racket
	{
		racket.x = old_x;
		printf("\a");
	}

    return 0;
}

void NoFast()
{

    int u = 0,v = 0;
    for(u = 1; u < numb.w; u++)
        {
//
            for(v = 1; v < length - 1; v++)
            {
                if ( mass[u][v] != ' ' )
                {
                    v = v + 100;
                    u= u + 100;
                }


        }

}
        if (u == numb.w )
                Win = 1;
}

void setcur (int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main ()
{
    srand(time(NULL));
    char c;
    int count = 0;
    int searchXR = 0;
    int searchXL = 0;
    int searchY = 0;
    setlocale(LC_ALL, "Russian");

    char Sturieren;
    printf("Здравствуйте, Вы в игре арканоид\n\tОбучение:\n\t\t1)Сделайте раскладку на англ");
    printf("\n\t\t2)Бросить мяч клавиша 'W'\n\t\t3)Движение ракетки 'A' и 'D'\n\t\t4)Задача уничтожить все цифры");
    printf("\n\t\tДля продолжения нажмите 'ENTER' ");
    do
    {
        Sturieren = getchar();
    }
    while(Sturieren != '\n');
    system("cls");


    HANDLE  handle = GetStdHandle(STD_OUTPUT_HANDLE); //спрятать курсор
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);

	initRacket();
	initBall ();
	SpeedBall();
	AlfaBall();
	init();
	Numbers ();
	do
	{
	init();

    PutNumb(&count, searchXR, searchXL, searchY);
	PutRacket ();
	putBall ();
	paint();
    moveRacket ();
    moveBall (&count, &searchXR, &searchXL, &searchY);
    NoFast();

	setcur(0,0);

	/*char b;
    printf("%s",nmass[1]);
    b = getchar();*/

    Sleep(30);
    if ((int)round(ball.y) == wigth)
        {
            KlickSPACE = FALSE;
            Exit--;

        }

	if( Win == 1)
    {

        system("cls");
    printf("YOU WIN!!!!!! Enter --> Exit\n");
    int k;
    k = getchar();
    return 0;
    }

    }
	while (  Exit != 0);

	do{
	system("cls");
	printf("Game Over\n\tRestart - 1\n\tEXIT - 2\n");
	printf("Пожалуйста, стерите всё до символа ':', и введите своё число \n\n\t:");
	Exit = 0;
	scanf("%d", &Exit);
	if (Exit == 1)
    {
        system("cls");
        Exit = 3;
        main();
    }
    if (Exit == 2)
        return 0;

        Exit = 1;
	}
	while(Exit == 0 );
	return 0;
}

