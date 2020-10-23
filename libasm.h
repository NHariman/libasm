/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libasm.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/09 00:29:36 by nhariman      #+#    #+#                 */
/*   Updated: 2020/10/23 12:03:07 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

/*
** the main functions
*/

extern ssize_t		ft_read(int fd, void *buf, size_t count);
extern char			*ft_strdup(const char *s);
extern ssize_t		ft_write(int fd, const void *buf, size_t count);
extern int			ft_strcmp(const char *s1, const char *s2);
extern char			*ft_strcpy(char *dst, char *src);
extern size_t		ft_strlen(const char *s);

/*
** the functions used to make a pretty main for testing
*/
void		blue(void);
void		reset(void);
void		test_strlen(void);
void		test_strcmp(void);
void		test_strcpy(void);
void		test_strdup(void);
void		test_read(void);
void		test_write(void);

#endif
