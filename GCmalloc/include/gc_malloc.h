/* ************************************************************************** */
/*                                                                            */
/*                                                      /\ ___ /\             */
/*   gc_malloc.h                                       (  o   o  )            */
/*                                                      \  >#<  /             */
/*   By: alex <alexandre.loubeyres@gmail.com>           /       \             */
/*                                                     /         \       ^    */
/*   Created: 2015/06/18 15:30:16 by alex             |           |     //    */
/*   Updated: 2015/06/21 17:43:48 by alex              \         /    //      */
/*                                                      ///  ///   --         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_MALLOC_H_
# define GC_MALLOC_H_

typedef struct	s_gc_m
{
  void		*data;
  int		id;
  int		size;
  struct s_gc_m	*prev;
  struct s_gc_m	*next;  
}		t_gc_m;

t_gc_m	*get_struct_start_malloc();
t_gc_m	*get_struct_last_malloc(t_gc_m *prev);

#endif /* GC_MALLOC_H_ */
