/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucorrei <rucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:56:00 by rucorrei          #+#    #+#             */
/*   Updated: 2024/05/23 11:30:37 by rucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_atoi(const char *str);

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size);

int		ft_isalnum(char c);

int		ft_isalpha(char c);

int		ft_isascii(int c);

int		ft_isdigit(char c);

int		ft_isprint(char c);

char	*ft_itoa(int n);

void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dst, const void *src, size_t len);

void	*ft_memset(void *s, int c, size_t n);

void	ft_putchar(char c);

void	ft_putchar_fd(char c, int fd);

void	ft_putendl(const char *s);

void	ft_putendl_fd(const char *s, int fd);

void	ft_putnbr(int n);

void	ft_putnbr_fd(int fd, int n);

void	ft_putstr(char *str);

void	ft_putstr_fd(char *str, int fd);

char	**ft_split(char const *s, char c);

char	*ft_strcat(char *dest, const char *src);

char	*ft_strchr(const char *s, int c);

char	*ft_strdup(const char *src);

int		ft_strequ(const char *s1, const char *s2);

void	ft_striteri(char *s, void (*f)(unsigned int, char *));

char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t	ft_strlen(const char *str);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	*ft_strncat(char *dest, const char *src, size_t n);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strncpy(char *dest, const char *src, size_t size);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_strrchr(const char *s, int c);

char	**ft_strsplit(char const *s, char c);

char	*ft_strstr(char *haystack, char *needle);

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_substr(char const *s, unsigned int start, size_t len);

int		ft_tolower(int c);

int		ft_toupper(int c);

//BONUS
t_list	*ft_lstnew(void *content);

void	ft_lstdelone(t_list *lst, void (*del)(void*));

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstadd_front(t_list **lst, t_list *new);

void	ft_lstclear(t_list **lst, void (*del)(void*));

void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

#endif