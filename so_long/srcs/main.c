/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:33:23 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/04 18:09:45 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h" 

int main()
{
	int		result;
	int		fd;
	int		i;
	char	*temp_str;
	t_list	*map;
	void	*mlx;
	void	*mlx_win;
	t_map	map_info;

	i = 0;
	map = ft_lstnew(NULL);
	fd = open("./map/map.bar", O_RDONLY);
	if (fd == -1)
		printf("open fail\n");
	else
	{
		get_next_line(fd, (char **)(&map->content));
		while (1)
		{
			result = get_next_line(fd, &temp_str);
			if (result == -1)
			{
				ft_lstclear(&map, free);
				return (1);
			}
			else
			{
				ft_lstadd_back(&map, ft_lstnew(NULL));
				ft_lstlast(map)->content = temp_str;
				if (result == 0)
					break ;
			}
		}
		t_list *temp;
		temp = map;
		while (temp != NULL)
		{
			printf("%s\n", (char *)temp->content);
			temp = temp->next;
		}
		if (check_map(map) == ERROR)
			prt_map_error();
		// else
		// 	printf("GOOD\n");
		ft_lstclear(&map, free);

	}
	close(fd);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello MLX!");
	 if (init_map(mlx, &map_info) == ERROR)
	 	return (prt_img_error());
	// mlx_put_image_to_window(mlx, mlx_win, map_info.empty_info, 0, 0);
	// mlx_put_image_to_window(mlx, mlx_win, map_info.wall_info, 0, 50);
	mlx_put_image_to_window(mlx, mlx_win, map_info.coll_info->img, 50, 0);
	// mlx_put_image_to_window(mlx, mlx_win, map_info.exit_info, 100, 0);
	// mlx_put_image_to_window(mlx, mlx_win, map_info.player_info, 50, 50);
	mlx_loop(mlx);
	return (0);
}