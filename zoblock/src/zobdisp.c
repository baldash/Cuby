/*
** zobdisp.c for zobdisp in /home/sylvain/Documents/projets/perso/zoblock/src
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Feb  1 15:29:02 2017 Sylvain Chaugny
** Last update Wed Feb  1 15:43:46 2017 Sylvain Chaugny
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<termios.h>
#include	<curses.h>
#include	<sys/ioctl.h>

char		*zob[] =
  {
    "           0000000",
    "         000  0  000",
    "       000       000",
    "       0          0",
    "       0          0",
    "       0000  0   000",
    "         0  000  0",
    "         0 0   0 0",
    "         0       0",
    "         0       0",
    "         0       0",
    "         0       0",
    "         0       0",
    "   0000000       000000",
    " 0000    0            000",
    "00                      00",
    "0                        0",
    "0           000          0",
    "00         00 00        00",
    " 000      00   00     000",
    "   0000000      0000000",
    NULL
  };

int			main()
{
  SCREEN		*win;
  struct winsize	ws;
  bool			side_y;
  bool			side_x;
  int			x;
  int			y;
  int			i;
  char			col;

  side_y = true;
  side_x = false;
  x = 0;
  y = 0;
  if ((win = newterm(NULL, stdout, stdin)) == NULL)
    return (0);
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
  curs_set(FALSE);
  timeout(1);

  start_color();
  init_pair(1, 1, 0);
  init_pair(2, 2, 0);
  init_pair(3, 3, 0);
  init_pair(4, 4, 0);
  init_pair(5, 5, 0);
  init_pair(6, 6, 0);
  init_pair(7, 7, 0);

  while (1)
    {
      x += side_x ? 1 : -1;
      y += side_y ? 1 : -1;

      if (side_x && x > ws.ws_col - 30)
	{
	  side_x = false;
	  x -= 2;
	}
      if (!side_x && x < 0)
	{
	  side_x = true;
	  x += 2;
	}

      if (side_y && y > ws.ws_row - 21)
	{
	  side_y = false;
	  y -= 2;
	}
      if (!side_y && y < 0)
	{
	  side_y = true;
	  y += 2;
	}
      i = 0;
      clear();
      while (zob[i])
	{
	  col = rand() % 7 + 1;
	  attron(A_BOLD);
	  attron(COLOR_PAIR(col));
	  mvprintw(y + i, x, zob[i]);
	  attroff(COLOR_PAIR(col));
	  attroff(A_BOLD);
	  i++;
	}
      refresh();
      usleep(20000);
    }
  return (0);
}
