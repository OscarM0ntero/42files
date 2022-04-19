!/bin/sh

echo "############### EX00 ###############"
norminette -R CheckForbiddenSourceHeader ex00/ft_putchar.c
gcc -Wall -Wextra -Werror testC00/ex0.c ex00/ft_putchar.c && ./a.out && rm -rf ./a.out
echo "\n"
read -n 1 -r -s -p $'Press any key to continue...CTR+C to cancel\n';

echo "############### EX01 ###############"
norminette -R CheckForbiddenSourceHeader ex01/ft_print_alphabet.c
gcc -Wall -Wextra -Werror testC00/ex1.c ex01/ft_print_alphabet.c && ./a.out && rm -rf ./a.out
echo "\n"
read -n 1 -r -s -p $'Press any key to continue...CTR+C to cancel\n';

echo "############### EX02 ###############"
norminette -R CheckForbiddenSourceHeader ex02/ft_print_reverse_alphabet.c
gcc -Wall -Wextra -Werror testC00/ex2.c ex02/ft_print_reverse_alphabet.c && ./a.out && rm -rf ./a.out
echo "\n"
read -n 1 -r -s -p $'Press any key to continue...CTR+C to cancel\n';

echo "############### EX03 ###############"
norminette -R CheckForbiddenSourceHeader ex03/ft_print_numbers.c
gcc -Wall -Wextra -Werror testC00/ex3.c ex03/ft_print_numbers.c && ./a.out && rm -rf ./a.out
echo "\n"
read -n 1 -r -s -p $'Press any key to continue...CTR+C to cancel\n';

echo "############### EX04 ###############"
norminette -R CheckForbiddenSourceHeader ex04/ft_is_negative.c
gcc -Wall -Wextra -Werror testC00/ex4.c ex04/ft_is_negative.c ex00/ft_putchar.c && ./a.out && rm -rf ./a.out
echo "\n"
read -n 1 -r -s -p $'Press any key to continue...CTR+C to cancel\n';

echo "############### EX05 ###############"
norminette -R CheckForbiddenSourceHeader ex05/ft_print_comb.c
gcc -Wall -Wextra -Werror testC00/ex5.c ex05/ft_print_comb.c && ./a.out && rm -rf ./a.out
echo "\n"
read -n 1 -r -s -p $'Press any key to continue...CTR+C to cancel\n';

echo "############### EX06 ###############"
norminette -R CheckForbiddenSourceHeader ex06/ft_print_comb2.c
gcc -Wall -Wextra -Werror testC00/ex6.c ex06/ft_print_comb2.c && ./a.out && rm -rf ./a.out
echo "\n"
read -n 1 -r -s -p $'Press any key to continue...CTR+C to cancel\n';

echo "############### EX07 ###############"
norminette -R CheckForbiddenSourceHeader ex07/ft_putnbr.c
gcc -Wall -Wextra -Werror testC00/ex7.c ex07/ft_putnbr.c ex00/ft_putchar.c && ./a.out && rm -rf ./a.out
echo "\n"
read -n 1 -r -s -p $'Press any key to continue...CTR+C to cancel\n';

echo "############### EX08 ###############"
norminette -R CheckForbiddenSourceHeader ex08/ft_print_combn.c
gcc -Wall -Wextra -Werror testC00/ex8.c ex08/ft_print_combn.c ex00/ft_putchar.c && ./a.out && rm -rf ./a.out
echo "\n"
read -n 1 -r -s -p $'Press any key to continue...CTR+C to cancel\n';
