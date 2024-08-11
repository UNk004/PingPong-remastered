#include<iostream>
#include<raylib.h>
#include "libraries/scene.hpp"

int screen_height=600;
int screen_width=1068;
int frmCtr;
Color neorange = {255,92,0,255};

class Paddle
{
    private:
    const float paddle_width = 20.0f;
    const float paddle_height = 70.0f;

    public:
    float xPos,yPos;
    int speed;

    void drawPaddle()
    {
        DrawRectangleRoundedLines(Rectangle{xPos,yPos,paddle_width,paddle_height},0.8,0.5,WHITE);
        DrawRectangleRounded(Rectangle{xPos,yPos,paddle_width,paddle_height},0.8,0.5,neorange);
    
    }
    
    void playerInput()
    {
        if(IsKeyDown(KEY_UP))
        {
            yPos -= speed;
        }else if(IsKeyDown(KEY_DOWN))
        {
            yPos += speed;
        }

        if(yPos<= 0)
        {
            yPos = 0;
        }else if(yPos+70 >= GetScreenHeight())
        {
            yPos = GetScreenHeight() - 70;
        }
    }
    
};
class Bot
{
    private:
    int chance;
    const float paddle_width = 20.0f;
    const float paddle_height = 70.0f;

    public:
    float x,y;
    int speed;
    void drawPaddle()
    {
        DrawRectangleRoundedLines(Rectangle{x,y,paddle_width,paddle_height},0.8,0.5,WHITE);
        DrawRectangleRounded(Rectangle{x,y,paddle_width,paddle_height},0.8,0.5,neorange);
    }
    void AI(int r)
    {
        frmCtr++;
        if(frmCtr>=30){
        chance = GetRandomValue(0,100);
        frmCtr = 0;
        }
        if(frmCtr >= 10){
        if(chance <=80)
        {
            y = r - 35;
        }
        else if(chance >80 && chance < 90)
        {
            y = r + 35;
        }
        else y = r;
        
        }

        if(y<= 0)
        {
            y = 0;
        }else if(y+70 >= GetScreenHeight())
        {
            y = GetScreenHeight() - 70;
        }
    }

};
class Ball
{
    private:
    const float radius = 16;
    int x= screen_width/2;
    

    public:
    int y;
    int Xspeed,Yspeed;
    void drawBall()
    {
        DrawCircle(x,y,radius,WHITE);
    }
    void update()
    {
        x += Xspeed;
        y += Yspeed;
        if(x + 16 >= screen_width || x - 16 <= 0)
        {
            Xspeed *= -1;
        }
        if(y + 16 > screen_height || y - 16 <= 0)
        {
            Yspeed *= -1;
        }
    }
};



int fps_cap = 60;

int main()
{
    Paddle paddle;
    Bot bot;
    Ball ball;

    bot.x = screen_width - 30;
    bot.y = screen_height/2 - 35;
    paddle.xPos = 30;
    paddle.yPos = screen_height/2 - 35;
    paddle.speed = 5;
    ball.y = screen_height/2;
    ball.Xspeed = 5;
    ball.Yspeed = 5;

    InitWindow(screen_width,screen_height,"Ping Pong remastered");
    SetTargetFPS(fps_cap);
    
    while(!WindowShouldClose())
    {
        BeginDrawing();
        
        paddle.playerInput();
        paddle.drawPaddle();
        bot.drawPaddle();
        bot.AI(ball.y);
        ball.drawBall();
        ball.update();
        ClearBackground(GRAY);
        EndDrawing();
        
    }
}