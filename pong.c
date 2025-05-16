#include "glfwrapper.h"

/*
gcc pong.c -o programa -I/opt/homebrew/include -L/opt/homebrew/lib -lglfw -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -DGL_SILENCE_DEPRECATION
./programa

*/
Color array = {{0.0f, 0.0f, 0.0f, 1.0f}};

int main() {
    createWindow(800, 800, "Pong");

    // Paddles and ball - posiciones ajustadas
    Rect paddleLeft = {-0.95f, 0.0f, 0.05f, 0.4f};  // y = centro, h = altura total
    Rect paddleRight = {0.90f, 0.0f, 0.05f, 0.4f};
    Circle ball = {0, 0, 0.04f};
    float ballSpeedX = 0.02f;
    float ballSpeedY = 0.005f;
    float paddleSpeed = 0.02f;
    int scoreL = 0;
    int scoreR = 0;
    int x = 1; //color de la pelota en COLOR_ARRAY[]

    while (isWindowOpen()) {
        updateBackgroundColor(BLACK);
        
        // Movimiento de paletas con límites
        if (isKeyDown(KEY_W)) paddleLeft.y += paddleSpeed;
        if (isKeyDown(KEY_S)) paddleLeft.y -= paddleSpeed;
        if (isKeyDown(KEY_UP)) paddleRight.y += paddleSpeed;
        if (isKeyDown(KEY_DOWN)) paddleRight.y -= paddleSpeed;
        
        // Limitar paletas (considerando que y es el CENTRO del paddle)
        limitF(&paddleLeft.y, -0.55f, 0.95f);  // Límites ajustados
        limitF(&paddleRight.y, -0.55f, 0.95f);

        // Movimiento de la bola
        ball.x += ballSpeedX;
        ball.y += ballSpeedY;

        // Colisión con paletas (función corregida)
        if(CheckCollisionRectCircle(paddleLeft, ball) && ballSpeedX < 0) {
            ballSpeedX *= -1;
            printf("Colisión izquierda\n");
            x = (rand() % 19)+1;
        }
        
        if(CheckCollisionRectCircle(paddleRight, ball) && ballSpeedX > 0) {
            ballSpeedX *= -1;
            printf("Colisión derecha\n");
            x = (rand() % 19)+1;
        }

        // Colisión con bordes superior e inferior
        if(ball.y + ball.radius > 1.0f || ball.y - ball.radius < -1.0f) {
            ballSpeedY *= -1;
            if (ballSpeedX > 0 && ballSpeedX < 0.025){
                ballSpeedX += 0.002;
                ballSpeedY += 0.002;
            }
            if (ballSpeedX < 0 && ballSpeedX < -0.025){
                ballSpeedX -= 0.002;
                ballSpeedY -= 0.002;
            }

        }

        // Reiniciar si sale por los lados
        if(ball.x - ball.radius < -1.0f || ball.x + ball.radius > 1.0f) {
            ball.x = 0;
            ball.y = 0;
            ballSpeedX = 0.01f * (rand() % 2 ? 1 : -1);
            ballSpeedY = 0.01f * (rand() % 2 ? 1 : -1);
            if(ball.x - ball.radius < -1.0f){
                scoreL += 1;
            }
            else{
                scoreR += 1;
            }
        }

        drawRectangleRect(paddleLeft, WHITE);
        drawRectangleRect(paddleRight, WHITE);
        drawCircleCircle(ball, COLOR_ARRAY[x]);

        updateWindow();
    }

    closeWindow();
    return 0;
}
