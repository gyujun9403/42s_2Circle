/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:33:23 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/04 11:17:47 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h" 

int main()
{
	// void	*mlx;
	// void	*mlx_win;
	// void	*img;
	// int		img_width;
	// int		img_height;
	int		fd;
	int		i;
	t_list	*map;

	i = 0;
	map = ft_lstnew(NULL);
	fd = open("./map/map.bar", O_RDONLY);
	if (fd == -1)
		printf("open fail\n");
	else
	{
		get_next_line(fd, (char **)(&map->content));
		printf("%s\n", (char *)(map->content));
		ft_lstadd_back(&map, ft_lstnew(NULL));
		while (get_next_line(fd, (char **)(&ft_lstlast(map)->content)) == 1)
			printf("%s\n", (char *)ft_lstlast(map)->content);
		ft_lstclear(&map, free);
	}
	close(fd);
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello MLX!");
	// img = mlx_png_file_to_image(mlx, "./imgs/50*50tile.png", &img_width, &img_height);
	// mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	// mlx_put_image_to_window(mlx, mlx_win, img, 25, 25);
	// mlx_loop(mlx);
	return (0);
}