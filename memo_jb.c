#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>

#define P1 1
#define P2 0

typedef struct  s_point
{
    int   x;
    int   y;
    int   z;
}               t_point;

typedef struct  s_piece
{
    int     **tab;
    int     x_lim;
    int     y_lim;
}               t_piece;

typedef struct  s_filler
{
    int     x_lim;
    int     y_lim;
}               t_filler;

typedef struct  s_sqrt
{
    int     p1_d;
    int     p2_d;
    float   possession;
}               t_sqrt;

t_sqrt **map_init(t_sqrt **map)
{
    int x;
    int y;
    map = (t_sqrt **)malloc(sizeof(t_sqrt *) * 6);
    y = 0;
    while (y < 6)
    {
        map[y] = (t_sqrt *)malloc(sizeof(t_sqrt) * 6);
        x = 0;
        while (x < 6)
        {
            map[y][x].p1_d = 1000;
            map[y][x].p2_d = 1000;
            map[y][x].possession = 0.5;
            x++;
        }
    y++;
    }
    return (map);
}

void    map_distance_update_0(t_sqrt ***map)
{
    int x;
    int y;

    y = 0;
    while (y < 6)
    {
        x = 0;
        while (x < 6)
        {
            if ((*map)[y][x].possession == P1)
            {
                (*map)[y][x].p1_d = 0;
                (*map)[y][x].p2_d = 500;
            }
            else if ((*map)[y][x].possession == P2)
            {
                (*map)[y][x].p1_d = 500;
                (*map)[y][x].p2_d = 0;
            }
            x++;
        }
        y++;
    }
}

void    map_print(t_sqrt **map)
{
    int x;
    int y;

    y = 0;
    while (y < 6)
    {
        x = 0;
        while (x < 6)
        {
            //printf("%5d ", map[y][x].p1_d);
            printf("%3.f%% ", map[y][x].possession * 100);
            x++;
        }
        printf("\n");
        y++;
    }
        printf("\n");
}

void    map_possession_update(t_sqrt ***map)
{
    int x;
    int y;
    int p2_d_tmp;

    y = 0;
    while (y < 6)
    {
        x = 0;
        while (x < 6)
        {
            p2_d_tmp = (*map)[y][x].p2_d;
            (*map)[y][x].possession = (float)((float)p2_d_tmp / (float)((float)p2_d_tmp + (float)(*map)[y][x].p1_d));
            //printf("x: %d y: %d p1_d %d p2_d %d possession %3.f%%", x, y, (*map)[y][x].p1_d, p2_d_tmp, (*map)[y][x].possession * 100);
            x++;
        }
        y++;
    }
}

/*void    map_distance_update_1(t_sqrt ***map)
{
    int x;
    int y;
    int p1_d_tmp;
    int p2_d_tmp;
    float possession;

    y = 0;
    while (y < 6)
    {
        x = 0;
        while (x < 6)
        {
            p1_d_tmp = 500;
            p2_d_tmp = 500;
            val = (*map)[y][x].possession;
            if (val == P1)
            {
                    p1_d_tmp = 0;
                    p2_d_tmp = 500;
            }
            else if (val == P2)
            {
                p1_d_tmp = 500;
                p2_d_tmp = 0;
            }
            if ((*map)[y][x].p1_d > p1_d_tmp)
                (*map)[y][x].p1_d = p1_d_tmp;
            else
                    p1_d_tmp = (*map)[y][x].p1_d;
            if ((*map)[y][x].p2_d > p2_d_tmp)
                (*map)[y][x].p2_d = p2_d_tmp;
            else
                p2_d_tmp = (*map)[y][x].p2_d;
            p1_d_tmp++;
            p2_d_tmp++;
            x++;
        }
        y++;
    }
}*/

void    map_distance_update_1(t_sqrt ***map)
{
    int x;
    int y;
    int p1_d_tmp;
    int p2_d_tmp;
    float possession;

    y = 0;
    while (y < 6)
    {
        x = 1;
        while (x < 6)
        {
            p1_d_tmp = (*map)[y][x - 1].p1_d + 1;
            p2_d_tmp = (*map)[y][x - 1].p2_d + 1;
            possession = (*map)[y][x].possession;
            if (p1_d_tmp < (*map)[y][x].p1_d && possession != P2)
                (*map)[y][x].p1_d = p1_d_tmp;
            if (p2_d_tmp < (*map)[y][x].p2_d && possession != P1)
                (*map)[y][x].p2_d = p2_d_tmp;
            x++;
        }
        y++;
    }
}

void    map_distance_update_2(t_sqrt ***map)
{
    int x;
    int y;
    int p1_d_tmp;
    int p2_d_tmp;
    float possession;

    x = 5;
    while (x >= 0)
    {
        y = 1;
        while (y < 6)
        {
            p1_d_tmp = (*map)[y - 1][x].p1_d + 1;
            p2_d_tmp = (*map)[y - 1][x].p2_d + 1;
            possession = (*map)[y][x].possession;
            if (p1_d_tmp < (*map)[y][x].p1_d && possession != P2)
                (*map)[y][x].p1_d = p1_d_tmp;
            if (p2_d_tmp < (*map)[y][x].p2_d && possession != P1)
                (*map)[y][x].p2_d = p2_d_tmp;
            y++;
        }
    x--;
    }
}

void    map_distance_update_3(t_sqrt ***map)
{
    int x;
    int y;
    int p1_d_tmp;
    int p2_d_tmp;
    float possession;

    y = 5;
    while (y >= 0)
    {
        x = 4;
        while (x >= 0)
        {
            p1_d_tmp = (*map)[y][x + 1].p1_d + 1;
            p2_d_tmp = (*map)[y][x + 1].p2_d + 1;
            possession = (*map)[y][x].possession;
            if (p1_d_tmp < (*map)[y][x].p1_d && possession != P2)
                (*map)[y][x].p1_d = p1_d_tmp;
            if (p2_d_tmp < (*map)[y][x].p2_d && possession != P1)
                (*map)[y][x].p2_d = p2_d_tmp;
        x--;
        }
    y--;
    }
}

void    map_distance_update_4(t_sqrt ***map)
{
    int x;
    int y;
    int p1_d_tmp;
    int p2_d_tmp;
    float possession;

    x = 0;
    while (x < 6)
    {
        y = 4;
        while (y >= 0)
        {
            p1_d_tmp = (*map)[y + 1][x].p1_d + 1;
            p2_d_tmp = (*map)[y + 1][x].p2_d + 1;
            possession = (*map)[y][x].possession;
            if (p1_d_tmp < (*map)[y][x].p1_d && possession != P2)
                (*map)[y][x].p1_d = p1_d_tmp;
            if (p2_d_tmp < (*map)[y][x].p2_d && possession != P1)
                (*map)[y][x].p2_d = p2_d_tmp;
            y--;
        }
        x++;
    }
}

void    map_distance_update_5(t_sqrt ***map)
{
    int     x;
    int     y;
    int     p1_d_tmp;
    int     p2_d_tmp;
    float   possession;

    y = 1;
    while (y < 6)
    {
        x = 1;
        while (x < 6)
        {
            possession = (*map)[y][x].possession;
            p1_d_tmp = (*map)[y - 1][x - 1].p1_d + 2;
            p2_d_tmp = (*map)[y - 1][x - 1].p2_d + 2;
            if (p1_d_tmp < (*map)[y][x].p1_d && possession != P2)
                (*map)[y][x].p1_d = p1_d_tmp;
            if (p2_d_tmp < (*map)[y][x].p2_d && possession != P1)
                (*map)[y][x].p2_d = p2_d_tmp;
            x++;
        }
        y++;
    }
}

void    map_distance_update_6(t_sqrt ***map)
{
    int x;
    int y;
    int p1_d_tmp;
    int p2_d_tmp;
    float   possession;

    x = 4;
    while (x >= 0)
    {
        y = 1;
        while (y < 6)
        {
            possession = (*map)[y][x].possession;
            p1_d_tmp = (*map)[y - 1][x + 1].p1_d + 2;
            p2_d_tmp = (*map)[y - 1][x + 1].p2_d + 2;
            if (p1_d_tmp < (*map)[y][x].p1_d && possession != P2)
                (*map)[y][x].p1_d = p1_d_tmp;
            if (p2_d_tmp < (*map)[y][x].p2_d && possession != P1)
                (*map)[y][x].p2_d = p2_d_tmp;
            y++;
        }
        x--;
    }
}

void    map_distance_update_7(t_sqrt ***map)
{
    int x;
    int y;
    int p1_d_tmp;
    int p2_d_tmp;
    float   possession;

    y = 4;
    while (y >= 0)
    {
        x = 4;
        while (x >= 0)
        {
            possession = (*map)[y][x].possession;
            p1_d_tmp = (*map)[y + 1][x + 1].p1_d + 2;
            p2_d_tmp = (*map)[y + 1][x + 1].p2_d + 2;
            if (p1_d_tmp < (*map)[y][x].p1_d && possession != P2)
                (*map)[y][x].p1_d = p1_d_tmp;
            if (p2_d_tmp < (*map)[y][x].p2_d && possession != P1)
                (*map)[y][x].p2_d = p2_d_tmp;
            x--;
        }
        y--;
    }
}

void    map_distance_update_8(t_sqrt ***map)
{
    int x;
    int y;
    int p1_d_tmp;
    int p2_d_tmp;
    float   possession;

    x = 1;
    while (x < 6)
    {
        y = 4;
        while (y >= 0)
        {
            possession = (*map)[y][x].possession;
            p1_d_tmp = (*map)[y + 1][x - 1].p1_d + 2;
            p2_d_tmp = (*map)[y + 1][x - 1].p2_d + 2;
            if (p1_d_tmp < (*map)[y][x].p1_d && possession != P2)
                (*map)[y][x].p1_d = p1_d_tmp;
            if (p2_d_tmp < (*map)[y][x].p2_d && possession != P1)
                (*map)[y][x].p2_d = p2_d_tmp;
            y--;
        }
        x++;
    }
}

void    map_update(t_sqrt ***map, t_filler game_settings)
{
    int i;
    i = 0;
    while (i++ < 2)
    {
        map_distance_update_1(map);
        map_distance_update_2(map);
        map_distance_update_3(map);
        map_distance_update_4(map);
        map_distance_update_5(map);
        map_distance_update_6(map);
        map_distance_update_7(map);
        map_distance_update_8(map);
    }
        map_possession_update(map);
}

float   map_score_calc(t_sqrt **map, t_filler game_settings)
{
    float score;
    int x;
    int y;

    score = 0;
    y = 0;
    while (y < game_settings.y_lim)
    {
        x = 0;
        while (x < game_settings.x_lim)
        {
            score += map[y][x].possession;
            x++;
        }
        y++;
    }
    return (score);
}

float   score_update(t_sqrt ***board_cpy, float *high_score, t_filler game_settings)
{
    float score;

    map_update(board_cpy, game_settings);
    score = map_score_calc(*board_cpy, game_settings);
    if (score > *high_score)
    {
        *high_score = score;
        return (1);
    }
    return (0);
}

int     is_placeable(t_sqrt **board, t_piece pc, t_point o)
{
    int     x;
    int     y;
    float   possession;

    if (pc.x_lim > 6 - o.x || pc.y_lim > 6 - o.y)
        return (0);
    y = 0;
    while (y < pc.y_lim)
    {
        x = 0;
        while (x < pc.x_lim)
        {
            possession = board[o.y + y][o.x + x].possession;
            if (pc.tab[y][x] == 1 && (possession == P1 || possession == P2))
                return (0);
            x++;
        }
        y++;
    }
    return (1);
}

void     piece_write(t_sqrt ***board_cpy, t_piece pc, t_point o)
{
    int     x;
    int     y;

    y = 0;
    while (y < pc.y_lim)
    {
        x = 0;
        while (x < pc.x_lim)
        {
            if (pc.tab[y][x] == 1)
            {
                (*board_cpy)[o.y + y][o.x + x].possession = 1;
                (*board_cpy)[o.y + y][o.x + x].p1_d = 0;
                (*board_cpy)[o.y + y][o.x + x].p2_d = 500;
            }
            x++;
        };
        y++;
    }
}

void    board_cpy_reset(t_sqrt **board, t_sqrt ***board_cpy, t_filler game_settings)
{
    int     x;
    int     y;

    y = 0;
    while (y < game_settings.y_lim)
    {
        x = 0;
        while (x < game_settings.x_lim)
        {
            (*board_cpy)[y][x].possession = board[y][x].possession;
            (*board_cpy)[y][x].p1_d = board[y][x].p1_d;
            (*board_cpy)[y][x].p2_d = board[y][x].p2_d;
            x++;
        };
        y++;
    }
}

t_point get_best_position(t_sqrt **board, t_sqrt ***board_cpy, t_piece pc, t_filler game_settings)
{
    t_point pt;
    t_point memo;
    float   high_score;

    pt.y = -1;
    high_score = 0;
    while (++pt.y < game_settings.y_lim)
    {
        pt.x = -1;
        while (++pt.x < game_settings.x_lim)
        {
            if (is_placeable(board, pc, pt))
            {
                board_cpy_reset(board, board_cpy, game_settings);
                piece_write(board_cpy, pc, pt);
                if (score_update(board_cpy, &high_score, game_settings))
                {
                    memo = pt;
                }
            }
        }
    }
    return (memo);
}

int     main(void)
{
        float   score;
        t_sqrt  **map;
        t_filler game_settings;

        game_settings.y_lim = 6;
        game_settings.x_lim = 6;
        map = map_init(map);
        map[0][3].possession = P1;
        map[1][3].possession = P1;
        map[2][3].possession = P2;
        map[2][2].possession = P1;
        map[2][1].possession = P1;
        map[2][0].possession = P1;
        map[0][5].possession = P2;
        map_print(map);
        map_distance_update_0(&map);
        map_print(map);
        map_update(&map, game_settings);
        map_print(map);
        score = map_score_calc(map, game_settings);
        printf("score = %.2f / %d\n", score, 6 * 6); fflush(stdout);

        return (0);
}
