CC = cc
SV_NAME = server
CL_NAME = client
SV_NAME_BNS = server_bonus
CL_NAME_BNS = client_bonus

SV_SRC = server.c
CL_SRC = client.c
SV_SRC_BNS = server_bonus.c
CL_SRC_BNS = client_bonus.c

SV_OBJ = $(SV_SRC:.c=.o)
CL_OBJ = $(CL_SRC:.c=.o)
SV_OBJ_BNS = $(SV_SRC:.c=.o)
CL_OBJ_BNS = $(CL_SRC:.c=.o)

FT_PRINTF := ./ft_printf
LIBFT := ./libft
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L../LeakSanitizer -llsan -lc++ -Wno-gnu-include-next -I ../LeakSanitize

all: ft_printf libft $(SV_NAME) $(CL_NAME)

bonus: ft_printf libft $(SV_NAME_BNS) $(CL_NAME_BNS)

ft_printf:
	@$(MAKE) -C $(FT_PRINTF)

libft:
	@$(MAKE) -C $(LIBFT)

$(SV_NAME): $(SV_OBJ)
	$(CC) $(SV_OBJ) $(FT_PRINTF)/ft_printf.a $(LIBFT)/libft.a -o $(SV_NAME)

$(CL_NAME): $(CL_OBJ)
	$(CC) $(CL_OBJ) $(FT_PRINTF)/ft_printf.a $(LIBFT)/libft.a -o $(CL_NAME)

$(SV_NAME_BNS): $(SV_OBJ_BNS)
	$(CC) $(SV_OBJ_BNS) $(FT_PRINTF)/ft_printf.a $(LIBFT)/libft.a -o $(SV_NAME_BNS)

$(CL_NAME_BNS): $(CL_OBJ_BNS)
	$(CC) $(CL_OBJ_BNS) $(FT_PRINTF)/ft_printf.a $(LIBFT)/libft.a -o $(CL_NAME_BNS)

clean:
	rm -f $(SV_OBJ) $(CL_OBJ)
	@$(MAKE) -C $(FT_PRINTF) clean
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(SV_NAME) $(CL_NAME)
	@$(MAKE) -C $(FT_PRINTF) fclean
	@$(MAKE) -C $(LIBFT) fclean

clean_bonus:
	rm -f $(SV_OBJ_BNS) $(CL_OBJ_BNS)
	@$(MAKE) -C $(FT_PRINTF) clean
	@$(MAKE) -C $(LIBFT) clean

fclean_bonus: clean_bonus
	rm -f $(SV_NAME_BNS) $(CL_NAME_BNS)
	@$(MAKE) -C $(FT_PRINTF) fclean
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

re_bonus: fclean_bonus all_bonus

.PHONY: all clean fclean re ft_printf libft bonus fclean_bonus clean_bonus re_bonus