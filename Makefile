CC = cc
SV_NAME = server
CL_NAME = client

SV_SRC = server.c
CL_SRC = client.c

SV_OBJ = $(SV_SRC:.c=.o)
CL_OBJ = $(CL_SRC:.c=.o)

FT_PRINTF := ./ft_printf
LIBFT := ./libft
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L../LeakSanitizer -llsan -lc++ -Wno-gnu-include-next -I ../LeakSanitize

all: ft_printf libft $(SV_NAME) $(CL_NAME)

ft_printf:
	@$(MAKE) -C $(FT_PRINTF)

libft:
	@$(MAKE) -C $(LIBFT)

$(SV_NAME): $(SV_OBJ)
	$(CC) $(SV_OBJ) $(FT_PRINTF)/ft_printf.a $(LIBFT)/libft.a -o $(SV_NAME)

$(CL_NAME): $(CL_OBJ)
	$(CC) $(CL_OBJ) $(FT_PRINTF)/ft_printf.a $(LIBFT)/libft.a -o $(CL_NAME)

clean:
	rm -f $(SV_OBJ) $(CL_OBJ)
	@$(MAKE) -C $(FT_PRINTF) clean
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(SV_NAME) $(CL_NAME)
	@$(MAKE) -C $(FT_PRINTF) fclean
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re ft_printf libft