/* ************************************************************************** */
/*                                                                            */
/*                                                      /\ ___ /\             */
/*   gcm.h                                             (  o   o  )            */
/*                                                      \  >#<  /             */
/*   By: alex <alexandre.loubeyres@gmail.com>           /       \             */
/*                                                     /         \       ^    */
/*   Created: 2015/06/21 17:42:52 by alex             |           |     //    */
/*   Updated: 2015/06/21 17:43:58 by alex              \         /    //      */
/*                                                      ///  ///   --         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GCM_H_
# define GCM_H_

void	*get_new_obj(int size, int id);
void	*resize_obj(void *oldobj, int new_size);
void	*get_new_obj_set(int size, int id);

void	free_exept_obj(void *obj);
void	free_by_id(int id);
void	free_me_all();

#endif /* !GCM_H_ */
