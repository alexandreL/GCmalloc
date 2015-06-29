/* ************************************************************************** */
/*                                                                            */
/*                                                      /\ ___ /\             */
/*   get_gc_malloc.c                                   (  o   o  )            */
/*                                                      \  >#<  /             */
/*   By: alex <alexandre.loubeyres@gmail.com>           /       \             */
/*                                                     /         \       ^    */
/*   Created: 2015/06/29 19:27:39 by alex             |           |     //    */
/*   Updated: 2015/06/29 19:28:10 by alex              \         /    //      */
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
