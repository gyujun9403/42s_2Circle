/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:33:23 by gyeon             #+#    #+#             */
/*   Updated: 2021/09/30 18:15:10 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h" 

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_rec(void *mlx, void	*mlx_win, int st_x, int st_y, int fin_x, int fin_y)
{
	int		i;
	int		backup_st_x;
	static t_data	img;

	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	int color = 0x500073;
	i = 0;
	backup_st_x = st_x;
	while (st_y < fin_y)
	{
		while (st_x < fin_x)
		{
			my_mlx_pixel_put(&img, st_x, st_y, color);
			mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
			st_x++;
		}
		st_y++;
		st_x = backup_st_x;
	}
}

int main()
{
	void	*mlx;
	void	*mlx_win;
	

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello MLX!");
	my_mlx_rec(mlx, mlx_win, 100, 200, 200, 300);
	mlx_loop(mlx);
	return (0);
}