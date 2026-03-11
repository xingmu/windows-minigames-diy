/*
 * Zen-C Snake Game - C版本演示
 * 这是一个简单的贪吃蛇游戏，使用终端ASCII图形
 * 可以作为Zen-C版本的参考实现
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

// 游戏常量
#define WIDTH 20
#define HEIGHT 20
#define MAX_LENGTH 100

// 方向枚举
typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

// 位置结构
typedef struct {
    int x;
    int y;
} Position;

// 蛇结构
typedef struct {
    Position body[MAX_LENGTH];
    int length;
    Direction direction;
} Snake;

// 游戏状态
typedef struct {
    Snake snake;
    Position food;
    int score;
    int game_over;
} GameState;

// 初始化游戏
void init_game(GameState *game) {
    // 初始化蛇
    game->snake.length = 3;
    game->snake.direction = RIGHT;
    
    // 蛇的初始位置（水平线）
    for (int i = 0; i < game->snake.length; i++) {
        game->snake.body[i].x = 5 + i;
        game->snake.body[i].y = 10;
    }
    
    // 生成食物
    srand(time(NULL));
    game->food.x = rand() % (WIDTH - 2) + 1;
    game->food.y = rand() % (HEIGHT - 2) + 1;
    
    game->score = 0;
    game->game_over = 0;
}

// 绘制游戏界面
void draw_game(const GameState *game) {
    // 清屏
    printf("\033[2J\033[H");
    
    // 绘制上边框
    printf("╔");
    for (int i = 0; i < WIDTH; i++) printf("═");
    printf("╗\n");
    
    // 绘制游戏区域
    for (int y = 0; y < HEIGHT; y++) {
        printf("║");
        for (int x = 0; x < WIDTH; x++) {
            int is_snake = 0;
            int is_head = 0;
            
            // 检查是否是蛇身
            for (int i = 0; i < game->snake.length; i++) {
                if (game->snake.body[i].x == x && game->snake.body[i].y == y) {
                    is_snake = 1;
                    if (i == 0) is_head = 1;
                    break;
                }
            }
            
            // 检查是否是食物
            if (game->food.x == x && game->food.y == y) {
                printf("🍎");
            } else if (is_head) {
                printf("🐍");
            } else if (is_snake) {
                printf("🟩");
            } else {
                printf("  ");
            }
        }
        printf("║\n");
    }
    
    // 绘制下边框
    printf("╚");
    for (int i = 0; i < WIDTH; i++) printf("═");
    printf("╝\n");
    
    // 显示分数和指令
    printf("分数: %d\n", game->score);
    printf("控制: W/A/S/D 移动, Q 退出, P 暂停\n");
    if (game->game_over) {
        printf("\n游戏结束! 按R重新开始\n");
    }
}

// 处理输入
void process_input(GameState *game) {
    struct termios oldt, newt;
    int ch;
    
    // 设置非阻塞输入
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    int oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    
    ch = getchar();
    
    // 恢复终端设置
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    
    if (ch != EOF) {
        switch (ch) {
            case 'w': case 'W':
                if (game->snake.direction != DOWN)
                    game->snake.direction = UP;
                break;
            case 's': case 'S':
                if (game->snake.direction != UP)
                    game->snake.direction = DOWN;
                break;
            case 'a': case 'A':
                if (game->snake.direction != RIGHT)
                    game->snake.direction = LEFT;
                break;
            case 'd': case 'D':
                if (game->snake.direction != LEFT)
                    game->snake.direction = RIGHT;
                break;
            case 'q': case 'Q':
                game->game_over = 1;
                break;
            case 'r': case 'R':
                if (game->game_over) {
                    init_game(game);
                }
                break;
        }
    }
}

// 更新游戏状态
void update_game(GameState *game) {
    if (game->game_over) return;
    
    // 移动蛇
    Position new_head = game->snake.body[0];
    
    switch (game->snake.direction) {
        case UP:    new_head.y--; break;
        case DOWN:  new_head.y++; break;
        case LEFT:  new_head.x--; break;
        case RIGHT: new_head.x++; break;
    }
    
    // 检查边界碰撞
    if (new_head.x < 0 || new_head.x >= WIDTH ||
        new_head.y < 0 || new_head.y >= HEIGHT) {
        game->game_over = 1;
        return;
    }
    
    // 检查自身碰撞
    for (int i = 0; i < game->snake.length; i++) {
        if (game->snake.body[i].x == new_head.x &&
            game->snake.body[i].y == new_head.y) {
            game->game_over = 1;
            return;
        }
    }
    
    // 移动蛇身
    for (int i = game->snake.length; i > 0; i--) {
        game->snake.body[i] = game->snake.body[i - 1];
    }
    game->snake.body[0] = new_head;
    
    // 检查是否吃到食物
    if (new_head.x == game->food.x && new_head.y == game->food.y) {
        // 增加蛇长
        if (game->snake.length < MAX_LENGTH) {
            game->snake.length++;
        }
        
        // 生成新食物
        game->food.x = rand() % (WIDTH - 2) + 1;
        game->food.y = rand() % (HEIGHT - 2) + 1;
        
        // 增加分数
        game->score += 10;
    }
}

// 主函数
int main() {
    GameState game;
    
    printf("Zen-C贪吃蛇游戏 - C演示版本\n");
    printf("按任意键开始游戏...\n");
    getchar();
    
    init_game(&game);
    
    while (!game.game_over) {
        draw_game(&game);
        process_input(&game);
        update_game(&game);
        usleep(100000); // 100ms延迟
    }
    
    draw_game(&game);
    printf("\n游戏结束! 最终分数: %d\n", game.score);
    
    return 0;
}