!/bin/sh

echo "############### EX00 ###############"
norminette -R CheckForbiddenSourceHeader ex00/ft_ft.c
gcc -Wall -Wextra -Werror testC01/ex0.c ex00/ft_ft.c && ./a.out && rm -rf ./a.out
echo "\n"
read -n 1 -r -s -p $'Press any key to continue...CTR+C to cancel\n';

echo "############### EX01 ###############"
norminette -R CheckForbiddenSourceHeader ex01/ft_ultimate_ft.c
gcc -Wall -Wextra -Werror testC01/ex1.c ex01/ft_ultimate_ft.c && ./a.out && rm -rf ./a.out
echo "\n"
read -n 1 -r -s -p $'Press any key to continue...CTR+C to cancel\n';

echo "############### EX02 ###############"
norminette -R CheckForbiddenSourceHeader ex02/ft_swap.c
gcc -Wall -Wextra -Werror testC01/ex2.c ex02/ft_swap.c && ./a.out && rm -rf ./a.out
echo "\n"
read -n 1 -r -s -p $'Press any key to continue...CTR+C to cancel\n';

echo "############### EX03 ###############"
norminette -R CheckForbiddenSourceHeader ex03/ft_div_mod.c
gcc -Wall -Wextra -Werror testC01/ex3.c ex03/ft_div_mod.c && ./a.out && rm -rf ./a.out
echo "\n"
read -n 1 -r -s -p $'Press any key to continue...CTR+C to cancel\n';

echo "############### EX04 ###############"
norminette -R CheckForbiddenSourceHeader ex04/ft_ultimate_div_mod.c
gcc -Wall -Wextra -Werror testC01/ex4.c ex04/ft_ultimate_div_mod.c && ./a.out && rm -rf ./a.out
echo "\n"
read -n 1 -r -s -p $'Press any key to continue...CTR+C to cancel\n';

echo "############### EX05 ###############"
norminette -R CheckForbiddenSourceHeader ex05/ft_putstr.c
gcc -Wall -Wextra -Werror testC01/ex5.c ex05/ft_putstr.c && ./a.out && rm -rf ./a.out
echo "\n"
read -n 1 -r -s -p $'Press any key to continue...CTR+C to cancel\n';

echo "############### EX06 ###############"
norminette -R CheckForbiddenSourceHeader ex06/ft_strlen.c
gcc -Wall -Wextra -Werror testC01/ex6.c ex06/ft_strlen.c ex05/ft_putstr.c && ./a.out && rm -rf ./a.out
echo "\n"
read -n 1 -r -s -p $'Press any key to continue...CTR+C to cancel\n';

echo "############### EX07 ###############"
norminette -R CheckForbiddenSourceHeader ex07/ft_rev_int_tab.c
gcc -Wall -Wextra -Werror testC01/ex7.c ex07/ft_rev_int_tab.c && ./a.out && rm -rf ./a.out
echo "\n"
read -n 1 -r -s -p $'Press any key to continue...CTR+C to cancel\n';

echo "############### EX08 ###############"
norminette -R CheckForbiddenSourceHeader ex08/ft_sort_int_tab.c
gcc -Wall -Wextra -Werror testC01/ex8.c ex08/ft_sort_int_tab.c && ./a.out && rm -rf ./a.out
echo "\n"
read -n 1 -r -s -p $'Press any key to continue...CTR+C to cancel\n';
