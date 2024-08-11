#include<iostream>
#include<raylib.h>
#include "libraries/scene.hpp"

Color neorange = {255,92,0,255};
class Paddle
{
    private:
    float paddle_width = 20.0f;
    float paddle_height = 70.0f;

    public:
    float xPos,yPos;
    int speed;
    

    void drawPaddle()
    {
        DrawRectangleRoundedLines(Rectangle{xPos,yPos,paddle_width+1,paddle_height+1},0.8,0.5,WHITE);
        DrawRectangleRounded(Rectangle{xPos,yPos,paddle_width,paddle_height},0.8,0.5,neorange);
    }
    
};
class Player : public Paddle
{
 public:
   
    
    void playerInput()
    {
        if(IsKeyPressed(KEY_UP))
        {
            yPos += speed;
            std::cout << "up key is pressed \n";
        }else if(IsKeyPressed(KEY_DOWN))
        {
            yPos -= speed;
            std::cout << "down key is pressed \n";
        }
    }

};

int screen_height=600;
int screen_width=1068;
int fps_cap = 60;

int main()
{
    Paddle paddle;
    Player player;

    paddle.xPos = 30;
    paddle.yPos = screen_height/2 - 35;
    player.speed = 100;
    float* yPtr = &paddle.yPos;

    InitWindow(screen_width,screen_height,"Ping Pong remastered");
    SetTargetFPS(fps_cap);
    
    while(!WindowShouldClose())
    {
        BeginDrawing();
        
        player.playerInput();
        paddle.drawPaddle();
        ClearBackground(BLACK);
        std::cout << "x = " << paddle.xPos << "\t y = " << paddle.yPos << "\n";
        EndDrawing();
    }
}