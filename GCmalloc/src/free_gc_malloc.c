/* ************************************************************************** */
/*                                                                            */
/*                                                      /\ ___ /\             */
/*   free_gc_malloc.c                                  (  o   o  )            */
/*                                                      \  >#<  /             */
/*   By: alex <alexandre.loubeyres@gmail.com>           /       \             */
/*                                                     /         \       ^    */
/*   Created: 2015/06/21 02:05:53 by alex             |           |     //    */
/*   Updated: 2015/07/02 12:00:39 by alex              \         /    //      */
/*                                                      ///  ///   --         */
/*                                                                            */
/* ************************************************************************** */

#include "gc_malloc.h"
#include <stdlib.h>

void		free_exept_obj(void *obj)
{
  t_gc_m	*list;

  list = get_struct_start_malloc();
  while (list && (list->data != obj))
    list = list->next;
  if (list && (list->data == obj))
    {
      free(obj);
      list->data = NULL;
      if (list->next)
	list->next->prev = list->prev;
      if (list->prev)
	list->prev->next = list->next;
      if (list != get_struct_start_malloc())
	free(list);
    }
  get_struct_last_malloc(get_struct_start_malloc());
}

void		free_by_id(int id)
{
  t_gc_m	*list;
  t_gc_m	*del;

  list = get_struct_start_malloc();
  while (list)
    {
      del = list;
      list = list->next;
      if (del->id == id)
	{
	  free(del->data);
	  del->data = NULL;
	  if (del->next)
	    del->next->prev = del->prev;
	  if (del->prev)
	    del->prev->next = del->next;
	  if (del != get_struct_start_malloc())
	    free(del);
	}
    }
  get_struct_last_malloc(get_struct_start_malloc());
}

void		free_me_all()
{
  t_gc_m	*list;
  t_gc_m	*del;

  list = get_struct_start_malloc();
  while (list)
    {
      del = list;
      list = list->next;
      if (del->data)
	free(del->data);
      del->data = NULL;
      if (del != get_struct_start_malloc())
	free(del);
    }
}

void		free_me_all_secure()
{
  t_gc_m	*list;
  t_gc_m	*del;
  int		pos;

  list = get_struct_start_malloc();
  while (list)
    {
      pos = 0;
      del = list;
      list = list->next;
      if (del->data)
	{
	  while (pos < del->size)
	    ((char *)(del->data))[pos++] = 0;
	  free(del->data);
	}
      del->data = NULL;
      if (del != get_struct_start_malloc())
	free(del);
    }
}
