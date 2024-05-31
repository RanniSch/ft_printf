# ft_printf
The goal of this project is to recode printf() with a variable number of arguments.<br> <br>
For example, the function can handle the following conversions: ```cspdiuxX%``` <br> <br>
For each conversion required by the subject, there's a function that converts the argument and returns the numer of bytes writed: <br>
• ```%c``` print a single character.<br>
• ```%s``` print a string of characters.<br>
• ```%p``` The void * pointer argument is printed in hexadecimal.<br>
• ```%d``` print a decimal (base 10) number.<br>
• ```%i``` print an integer in base 10.<br>
• ```%u``` print an unsigned decimal (base 10) number.<br>
• ```%x``` print a number in hexadecimal (base 16).<br>
• ```%%``` print a percent sign.<br>

## How to run the code
Enter the repository with ``` cd ``` and add a "main.c" with ``` touch main.c ```. <br>
For example copy paste the following code into main:
```
#include "ft_printf.h"

int	main(void)
{
    long int     hd_big;
    long int     hd_small;
    char	*name;
	char	n[8] = "Heather";
    name = &n[0];
    hd_big = 590;
    hd_small = 590;
	ft_printf("Hexa big %X and small %x. Position %p \n", hd_big, hd_small, name);
    char	*name2;
	char	n2[10] = "Christian";
	char	chr;
	int		age;
    int     base;
    int     pos;
    long int     hd_big2;
    long int     hd_small2;
	name2 = &n2[0];
	chr = 'a';
	age = 24;
    base = 12;
    pos = 160;
    hd_big2 = 590;
    hd_small2 = 590;
	ft_printf("My name is %s with an %c saved at: %p. Hexa big %X and small %x. Positive: %u, age %d, %% and %i.\n", name2, chr, name2, hd_big2, hd_small2, pos, age, base);  
	return (0);
}
```
Run ```make``` (to run the Makefile that will compile the source code and create the library). <br>
You should now see a libftprintf.a file and some object files (.o). <br>
To clean up (removing the .o files), call ```make clean```. <br>

Compile your .c files with gcc using ```gcc main.c libftprintf.a```.
You need to include the libftprintf.a to tell the file which library it is using.<br> <br>
Now you can run the code using ```./a.out```. <br> <br>
![ft_printf-01](https://github.com/RanniSch/ft_printf/assets/104382315/30190c94-434c-4c8e-a467-028b73b9d411)


