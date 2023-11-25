#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 10

int gameOver;
int score;
int tailX[100], tailY[100];
int nTail;
int x, y, fruitX, fruitY, direction;

void setup() {
    gameOver = 0;
    score = 0;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    direction = 0; // initially not moving
}

void draw() {
    system("cls"); // clear the console

    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0)
                printf("#");

            if (i == y && j == x)
                printf("O");
            else if (i == fruitY && j == fruitX)
                printf("F");
            else {
                int printTail = 0;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o");
                        printTail = 1;
                    }
                }
                if (!printTail)
                    printf(" ");
            }

            if (j == WIDTH - 1)
                printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    printf("Score: %d", score);
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                direction = 1;
                break;
            case 'd':
                direction = 2;
                break;
            case 'w':
                direction = 3;
                break;
            case 's':
                direction = 4;
                break;
            case 'x':
                gameOver = 1;
                break;
        }
    }
}

void algorithm() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (direction) {
        case 1:
            x--;
            break;
        case 2:
            x++;
            break;
        case 3:
            y--;
            break;
        case 4:
            y++;
            break;
    }

    if (x < 0)
        x = WIDTH - 1;
    else if (x >= WIDTH)
        x = 0;

    if (y < 0)
        y = HEIGHT - 1;
    else if (y >= HEIGHT)
        y = 0;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = 1;

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        nTail++;
    }
}

int main() {
    setup();

    while (!gameOver) {
        draw();
        input();
        algorithm();
        Sleep(100); // Adjust the speed of the game
    }

    return 0;
}
