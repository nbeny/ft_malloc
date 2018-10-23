#include "ft_malloc.h"

int     check_page_tiny(size_t size, int id)
{
    t_page  *save;
    int     ok;
    int     power;

    save = NULL;
    ok = -1;
    if (g_page == NULL)
    {
        g_page = create_tab(size, id);
    }
    else
    {
        save = g_page;
        while (save)
        {
            power = ft_power_of(size);
            if (save->id == 0 && TINY - (save->addr - save->page) > power && power != -1)
                return (1);
            if (power == -1)
                return (-1);
            save = save->next;
        }
    }
    return (0);
}