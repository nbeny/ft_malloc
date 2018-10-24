#include "ft_malloc.h"

int     Check_tab(size_t size)
{
    t_page  *save;
    size_t  i;

    save = g_page;
    i = 0;
    while (save != NULL)
    {
        i += 1;
        save = save->next;
    }
    if (i < g_page->tab)
        return (1);
    return (0);
}

int     check_page_tiny(size_t power, int id)
{
    t_page  *save;
    int     ok;

    save = NULL;
    ok = -1;
    save = g_page;
    if (power == -1)
        return (-1);
    while (save)
    {
        if (save->id == 0 && TINY - (save->addr - save->page) > power)
            return (1);
        save = save->next;
    }
    return (0);
}