/* ************************************************************************** */
/*                                                                            */
/*                                                      /\ ___ /\             */
/*   creat_gc_malloc.c                                 (  o   o  )            */
/*                                                      \  >#<  /             */
/*   By: alex <alexandre.loubeyres@gmail.com>           /       \             */
/*                                                     /         \       ^    */
/*   Created: 2015/06/21 02:05:53 by alex             |           |     //    */
/*   Updated: 2015/06/21 17:43:36 by alex              \         /    //      */
/*                                                      ///  ///   --         */
/*                                                                            */
/* ************************************************************************** */

#include "gc_malloc.h"
#include <stdlib.h>

t_gc_m		*get_struct_start_malloc()
{
  static t_gc_m	obj = {NULL, 0, 0, NULL, NULL};

  return (&obj);
}

t_gc_m		*get_struct_last_malloc(t_gc_m *prev)
{
  static t_gc_m	*obj = NULL;

  if (prev != NULL)
    {
      obj = prev;
      while (obj->next)
	obj = obj->next;
    }
  return (obj);
}

void		*get_new_obj(int size, int id)
{
  t_gc_m	*list;

  if ((list = get_struct_last_malloc(NULL)) == NULL)
    list = get_struct_start_malloc();
  else
    {
      if ((list->next = malloc(sizeof(t_gc_m))) == NULL)
	return (NULL);
      list->next->prev = list;
      list = list->next;
      list->next = NULL;
    }
  if ((list->data = malloc(size)) == NULL)
    return (NULL);
  list->size = size;
  list->id = id;
  get_struct_last_malloc(list);
  return (list->data);
}

void		*resize_obj(void *oldobj, int new_size)
{
  void		*tmp;
  t_gc_m	*list;
  int		i;

  list = get_struct_start_malloc();
  while (list)
    {
      if (list->data == oldobj)
	{
	  if ((tmp = malloc(new_size)) == NULL)
	    return (NULL);
	  i = -1;
	  while (++i < list->size)
	    ((char *)(list->data))[i] = ((char *)(tmp))[i];
	  while (++i < new_size)
	    ((char *)(tmp))[i] = 0;
	  free(list->data);
	  list->data = tmp;
	  list->size = new_size;
	  return (tmp);
	}
      list = list->next;
    }
  return (NULL);
}

void		*get_new_obj_set(int size, int id)
{
  void		*obj;
  int		i;

  obj = get_new_obj(size, id);
  i = -1;
  while (++i < size)
    ((char *)(obj))[i] = 0;  
  return (obj);
}
