#include <stdio.h>
#include <stdlib.h>

#define bloc_len 3
#define x_max 5
#define y_max 3

typedef struct   s_point
{
    int x;
    int y;
}               t_point;

int step_maj(t_point *step)
{
    step->x++;
    if (step->x * bloc_len >= x_max)
    {
        step->x = 0;
        step->y++;
        if (step->y * bloc_len >= y_max)
            return (0);
    }
    return (1);
}

t_point t_point_init(int x, int y)
{
    t_point point;
    point.x = x;
    point.y = y;
    return (point);
}

int main()
{
    int tab[y_max][x_max];
    t_point pt;
    t_point step;

    step = t_point_init(-1, 0);
    while (step_maj(&step))
    {
            pt.y = step.y * bloc_len - 1;
            while (++pt.y < (step.y + 1) * bloc_len && pt.y < y_max && (pt.x = step.x * bloc_len - 1))
                while (++pt.x < (step.x + 1) * bloc_len && pt.x < x_max)
                {
                    printf("y: %d - x: %d\n", pt.y, pt.x);
                }
    }
    return(0);
}
