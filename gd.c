#include "glfwrapper.h"

typedef struct {
    Circle circle;
    float accel;
    float vel;
    float angle;
} Player;

Player newPlayer() {
    return (Player){
        (Circle){
            .x = -0.0f,
            .y = -0.0f,
            .radius = 0.1f
        },
        .accel = -1e-2f,
        .vel = 0.0f,
        .angle = 45,
    };
}

void drawPlayer(Player *player) {
    drawPolygonRot(player->circle.x, player->circle.y, player->angle, player->circle.radius, 4, WHITE);
}

void updatePlayerControls(Player *player) {
    player->vel += player->accel;

    player->circle.y += player->vel;
    if ( (isKeyDown(KEY_UP) || isKeyDown(KEY_SPACE)) && player->circle.y - player->circle.radius > -0.5f) {
        printf("asidaii\n");
        player->accel *= -1;
        player->circle.x = -0.5f + 2*player->circle.radius;

    }
}

void drawFloor(Player *player) {
    drawRectangle(-1.0f, -0.5f, 2.0f, 0.5f, BLUE);
}

int main() {
    createWindow(640, 640, "Geometry Dash");
    Player player = newPlayer();

    // Loop until the user closes the window
    while (isWindowOpen()) {
        // Render here
        updatePlayerControls(&player);

        updateBackgroundColor(DARKBLUE);

        drawPlayer(&player);
        drawFloor(&player);

        updateWindow();
    }

    closeWindow();
    return 0;
}
