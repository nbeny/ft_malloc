#include "ft_malloc.h"

t_page  *g_page = NULL;

void    *create_tab(size_t size, int id)
{
    t_page  *page;

    page = NULL;
    if (!(page = (t_page *)mmap(0, TAB, PROT, MAP, -1, 0)))
        return (NULL);
    page->id = 0;
    page->page = (size_t)page;
    page->addr = (size_t)page + size;
    page->tab = (size_t)TAB / (size_t)page;
    page->next = NULL;
    return (page);
}

void    *remake_tab(size_t, int id)
{
    t_page  *save;
    t_page  *page;

    save = g_page;
    page = NULL;
    while (save)
    {
        save = save->next;
    }
    return (page);
}

void    *ft_malloc(size_t size)
{
    void    *ptr;
    int     ok;
    size_t  power;

    ptr = NULL;
    power = ft_power_of(size);
    if (size <= 0 || size > (ft_power(2, 64) - 1))
        return (NULL);
    else if (size < 64)
    {
        if (g_page == NULL)
            g_page = create_tab(power, 0);
        ok = check_page_tiny(power, 0);
        if (!check_tab(TAB))
            g_page = remake_tab(TAB);
        if (ok == 0)
        {
            ;
        }
        else
        {
            ;
        }
    }
    else if (size >= 64 && size < 4096)
    {
        ok = check_page_small(size);
        if (ok == 0)
        {
            ;
        }
        else
        {
            ;
        }
    }
    else
    {
        ;
    }
    return ((void *)ptr)
}