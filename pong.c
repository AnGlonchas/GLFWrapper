#include "glfwrapper.h"

/*
gcc pong.c -o programa -I/opt/homebrew/include -L/opt/homebrew/lib -lglfw -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -DGL_SILENCE_DEPRECATION
./programa

*/

void drawEffect(Circle *ball) {
    // Loop through all screen drawing diamonds

    for(float x = -1.0f; x <= 1.25f; x += 0.12f) {
        for(float y = -1.0f; y <= 1.25f; y += 0.12f) {
            // Get distance between the ball and the square
            float dist = distance((Vector2){ball->x, ball->y}, (Vector2){x, y});
            float sqSize = 1/dist/30;
            limitF(&sqSize, 0.0f, 0.1f);

            Color col = {
                .r = dist/3,
                .g = dist/32,
                .b = 1/dist/30,
                .a = 1.0f,
            };
            drawPolygon(x, y, sqSize, 4, col);
        }
    }
}

int main() {
    createWindow(700, 700, "Pong");

    Color veryDarkBlue = {0.0f, 0.0f, 0.1f, 1.0f};

    // Paddles and ball - posiciones ajustadas
    Rect paddleLeft = {-0.95f, 0.0f, 0.05f, 0.4f};  // y = centro, h = altura total
    Rect paddleRight = {0.90f, 0.0f, 0.05f, 0.4f};
    Circle ball = {0, 0, 0.04f};

    Vector2 ballSpeed = {0.01f, 0.0f};
    float paddleSpeed = 0.021f;
    int scoreL = 0;
    int scoreR = 0;

    while (isWindowOpen()) {
        updateBackgroundColor(veryDarkBlue);
        
        // Movimiento de paletas con límites
        if (isKeyDown(KEY_W))    paddleLeft.y += paddleSpeed*getDeltaTime();
        if (isKeyDown(KEY_S))    paddleLeft.y -= paddleSpeed*getDeltaTime();
        if (isKeyDown(KEY_UP))   paddleRight.y += paddleSpeed*getDeltaTime();
        if (isKeyDown(KEY_DOWN)) paddleRight.y -= paddleSpeed*getDeltaTime();
        
        // Limitar paletas (considerando que y es el CENTRO del paddle)
        limitF(&paddleLeft.y, -0.55f, 0.95f);  // Límites ajustados
        limitF(&paddleRight.y, -0.55f, 0.95f);

        // Movimiento de la bola
        ball.x += ballSpeed.x*getDeltaTime();
        ball.y += ballSpeed.y*getDeltaTime();

        //Make the ball faster as time passes
        Vector2Dot(&ballSpeed, 1.001f);

        // Colisión con paletas
        if(checkCollisionRectCircle(paddleLeft, ball) && ballSpeed.x < 0) {
            float paddleCenter = paddleLeft.y - (paddleLeft.h/2);
            ballSpeed.x *= -1;
            // Get Y velocity in function of the angle of the collision
            ballSpeed.y = (ball.y - paddleCenter)/15;
            printf("Colision izquierda\n");
        }
        
        if(checkCollisionRectCircle(paddleRight, ball) && ballSpeed.x > 0) {
            float paddleCenter = paddleRight.y - (paddleRight.h/2);
            ballSpeed.x *= -1;
            // Get Y velocity in function of the angle of the collision
            ballSpeed.y = (ball.y - paddleCenter)/15;
            printf("Colision derecha\n");
        }

        // Colisión con bordes superior e inferior
        if(ball.y + ball.radius > 1.0f || ball.y - ball.radius < -1.0f) {
            ballSpeed.y *= -1;
        }

        // Reiniciar si sale por los lados
        if(ball.x - ball.radius < -1.0f || ball.x + ball.radius > 1.0f) {
            ball.x = 0;
            ball.y = 0;
            ballSpeed.x = 0.01f * (rand() % 2 ? 1 : -1);
            ballSpeed.y = 0.01f * (rand() % 2 ? 1 : -1);
            if(ball.x - ball.radius < -1.0f){
                scoreL += 1;
            }
            else{
                scoreR += 1;
            }
        }
        // Blending mode, mixes the colors together
        beginBlending(BLEND_ADD);
            drawEffect(&ball);
            drawRectangleRect(paddleLeft, YELLOW);
            drawRectangleRect(paddleRight, YELLOW);
            drawCircleCircle(ball, YELLOW);
        endBlending();

        updateWindow();
    }

    closeWindow();
    return 0;
}
