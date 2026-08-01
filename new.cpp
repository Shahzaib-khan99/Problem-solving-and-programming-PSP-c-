#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 640
#define HEIGHT 480
#define BLOCK_SIZE 20

struct Point {
    int x, y;
};

int main() {
    // Initialize graphics window
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Snake initialization
    Point snake[100];
    int snake_length = 5;
    for (int i = 0; i < snake_length; i++) {
        snake[i] = {100 - i * BLOCK_SIZE, 100};
    }
    char direction = 'R'; // Initial direction (R: Right, L: Left, U: Up, D: Down)

    // Food initialization
    Point food = {200, 200};
    srand(time(0));

    // Game loop
    while (true) {
        // Clear screen
        cleardevice();

        // Draw snake
        for (int i = 0; i < snake_length; i++) {
            setfillstyle(SOLID_FILL, GREEN);
            bar(snake[i].x, snake[i].y, snake[i].x + BLOCK_SIZE, snake[i].y + BLOCK_SIZE);
        }

        // Draw food
        setfillstyle(SOLID_FILL, RED);
        bar(food.x, food.y, food.x + BLOCK_SIZE, food.y + BLOCK_SIZE);

        // Input handling
        if (kbhit()) {
            char key = getch();
            if ((key == 'w' || key == 'W') && direction != 'D') direction = 'U';
            if ((key == 's' || key == 'S') && direction != 'U') direction = 'D';
            if ((key == 'a' || key == 'A') && direction != 'R') direction = 'L';
            if ((key == 'd' || key == 'D') && direction != 'L') direction = 'R';
        }

        // Move snake
        for (int i = snake_length - 1; i > 0; i--) {
            snake[i] = snake[i - 1];
        }
        if (direction == 'R') snake[0].x += BLOCK_SIZE;
        if (direction == 'L') snake[0].x -= BLOCK_SIZE;
        if (direction == 'U') snake[0].y -= BLOCK_SIZE;
        if (direction == 'D') snake[0].y += BLOCK_SIZE;

        // Check collision with food
        if (snake[0].x == food.x && snake[0].y == food.y) {
            snake_length++;
            food.x = (rand() % (WIDTH / BLOCK_SIZE)) * BLOCK_SIZE;
            food.y = (rand() % (HEIGHT / BLOCK_SIZE)) * BLOCK_SIZE;
        }

        // Check collision with walls
        if (snake[0].x < 0 || snake[0].x >= WIDTH || snake[0].y < 0 || snake[0].y >= HEIGHT) {
            outtextxy(WIDTH / 2 - 50, HEIGHT / 2, "Game Over!");
            getch();
            break;
        }

        // Check collision with itself
        for (int i = 1; i < snake_length; i++) {
            if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
                outtextxy(WIDTH / 2 - 50, HEIGHT / 2, "Game Over!");
                getch();
                break;
            }
        }

        // Delay for game speed
        delay(100);
    }

    // Close graphics window
    closegraph();
    return 0;
}