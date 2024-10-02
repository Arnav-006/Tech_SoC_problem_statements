#include <iostream>
#include <conio.h>

using namespace std;

bool gameover;
const int width=60;
const int height=20;
int x,y,fruitx,fruity,score,nTail;
int tailX[100],tailY[100];
enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
void setup()
{
    gameover=false;
    dir=STOP;
    x=width/2;
    y=height/2;
    fruitx=rand()%width;
    fruity=rand()%height;

}

void draw()
{
    system("cls");
    int f=0;
    for (int i = 0; i < height; i++)
    {
        if (i==0 || i==height-1)
        {
            for (int j = 0; j < width; j++)
            cout<<"#";
        }
        
        else
        {
            for (int j = 0; j < width; j++)
            {
                for (int k = 1; k<= nTail; k++)
                {
                    if(j==tailX[k] && i==tailY[k])
                    {
                        f=1;
                        break;
                    }
                }
                
                if(j==0 || j==width-1)
                cout<<"#";
                else if(j==x && i==y)
                cout<<"O";
                else if(f==1)
                {
                    cout<<"o";
                    f=0;
                }
                else if (j==fruitx && i==fruity)
                cout<<"F";
                else
                cout<<" ";
            }
        }
        cout<<endl;
    }
    cout<<"Score: "<<score;
    // cout<<fruitx<<" "<<fruity;
    
}

void input()
{
    if(_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            if(dir!=RIGHT || nTail==0)
            dir=LEFT;
            break;
        case 'd':
            if(dir!=LEFT || nTail==0)
            dir=RIGHT;
            break;
        case 'w':
            if(dir!=DOWN || nTail==0)
            dir=UP;
            break;
        case 's':
            if(dir!=UP || nTail==0)
            dir=DOWN;
            break;
        case 'x':
            gameover=true;
            break;
        }
    }
}

void logic()
{
    tailX[0]=x;
    tailY[0]=y;
    switch (dir)
    {
    case LEFT:
        x--;
        break;

    case RIGHT:
        x++;
        break;

    case UP:
        y--;
        break;

    case DOWN:
        y++;
        break;
    
    }
    
    for (int i = 0; i < nTail; i++)
    {
        tailX[nTail-i]=tailX[nTail-i-1];
        tailY[nTail-i]=tailY[nTail-i-1];
        if(tailX[nTail-i]==x && tailY[nTail-i]==y)
        gameover=true;
    }
    tailX[0]=x;
    tailY[0]=y;
    
    if (x>width || x<0 || y<0 || y>height)
    gameover=true;
    if(x==fruitx && y==fruity)
    {
        score++;
        nTail++;
        fruitx=rand()%(width-3)+1;
        fruity=rand()%(height-1)+1;
    }
}

int main()
{
    setup();
    while (!gameover)
    {
        draw();
        input();
        logic();
    }
    return 0;
}