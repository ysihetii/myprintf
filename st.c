#include <stdio.h>
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>
#include  <float.h>
int main(void)
{


	int i; 

	ft_printf("@moulitest: %s\n", "NULLITO");
	printf("@moulitest: %s\n", "NULLITO");
	
	ft_printf("@moulitest: %s\n", "NULLITO");
	printf("@moulitest: %s\n", "NULLITO");
	
	int f_pr;
	int	pr;
	f_pr = ft_printf("%5%\n");
	printf("ft_printf: %d\n", f_pr);
	pr = printf("%5%\n");
	printf("printf: %d\n", pr);
	
	int c = 0;
	f_pr = ft_printf("%-7c, %c\n", c, c);
	printf("ft_printf: %d\n", f_pr);

	pr = printf("%-7c, %c\n", c, c);
	printf("printf: %d\n", pr);

	ft_printf("%+0*c\n", -10, 'a');
	int num = 2147483648;
	ft_printf("@moulitest: %5.2d %.2d\n", 0, 0);
	printf("@moulitest: %5.2d %.2d\n", 0, 0);

	ft_printf("%10.5d\n", -125);
	printf("%10.5d\n", -125);


	ft_printf("@moulitest: %.d %.0d\n", 0, 0);
	printf("@moulitest: %.d %.0d\n", 0, 0);

	ft_printf("% d\n", 42);
	printf("% d\n", 42);

	ft_printf("@moulitest: %.d %.0d\n", 42, 43);
	printf("@moulitest: %.d %.0d\n", 42, 43);

	ft_printf("@moulitest: %5.d %5.0d\n", 0, 0);
	printf("@moulitest: %5.d %5.0d\n", 0, 0);
	char n = 255;
	  printf("%x\n", n);

	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
	printf("@moulitest: %#.x %#.0x\n", 0, 0);

	ft_printf("@moulitest: %5.x %5.0x\n", 0, 0);
	printf("@moulitest: %5.x %5.0x\n", 0, 0);

	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
	printf("@moulitest: %#.x %#.0x\n", 0, 0);

	ft_printf("%x\n", 42);
	printf("%x\n", 42);

	ft_printf("%#8x\n", 42);
	printf("%#8x\n", 42);

	ft_printf("%jx\n", -4294967296);
	printf("%jx\n", -4294967296);

	ft_printf("%5o\n", 41);
	printf("%5o\n", 41);

	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
	printf("@moulitest: %#.x %#.0x\n", 0, 0);

	ft_printf("%#.o %#.0o\n", 0, 0);
	printf("%#.o %#.0o\n", 0, 0);

	ft_printf("%u\n", 0);
	printf("%u\n", 0);

	ft_printf("%15U\n", 4294967295); 
	printf("%15U\n", 4294967295);

	ft_printf("%hU\n", 4294967296);
	printf("%hU\n", 4294967296);

	ft_printf("%p\n", -42);
	printf("%X\n", -42);


		ft_printf("%X\n", 4294967296);
		printf("%X\n", 4294967296);
	


	i = 42;
	ft_printf("%.20p\n", &i);
	printf("%.20p\n", &i);

	ft_printf("{%-13p}\n", &i);
	printf("{%-1*p}\n", 8, &i);

	ft_printf("%O\n", LONG_MAX);
	printf("%O\n", LONG_MAX);

	ft_printf("% Zoooo %s\n", "abc");
	printf("% Zoooo %s\n", "abc");

	ft_printf("%i\n", 42);
	printf("%i\n", 42);

	ft_printf("%D\n", 0L);
	printf("%D\n", 0L);

	ft_printf("{%-03c}\n", 0);
	printf("{%-03c}\n", 0);

	ft_printf("{%05s}\n", "abc");
	printf("{%05s}\n", "abc");

	ft_printf("{%+ 03d}\n", 0);
	printf("{%+ 03d}", 0);

	ft_printf("{%*d}\n", -5, 42);
	printf("{%*d}\n", -5, 42);

	ft_printf("%10x\n", 42);
	printf("%10x\n", 42);

	ft_printf("{%3*p}\n", 10, 0);
	printf("{%3*p}\n", 10, 0);

	ft_printf("{%*3d}\n", 0, 0);
	printf("{%*3d}\n", 0, 0);

	ft_printf("%-oab\n", 0);
	printf("%-oab\n", 0);

	ft_printf("%-Zoab\n", 0);
	printf("%-Zoab\n", 0);

	ft_printf("@moulitest: %.o %.0o\n", 0, 0);
	printf("@moulitest: %.o %.0o\n", 0, 0);


	ft_printf("{%-15Zs}\n", 123);
	printf("{%-15Zs}\n", 123);

	ft_printf("{%hd}\n", -15);
	printf("{%hd}\n", -15);

	ft_printf("{%*d}\n", -5, 42);
	printf("{%*d}\n", -5, 42);

	ft_printf("{%#.5x}\n", 1);
	printf("{%#.5x}\n", 1);

	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
	printf("@moulitest: %#.x %#.0x\n", 0, 0);

	ft_printf("%zhd\n", 4294967296);
	printf("%zhd\n", 4294967296);

	ft_printf("%hhld\n", 128);
	printf("%hhld\n", 128);

	ft_printf("@main_ftprintf: %####0000 33..1..#00d\n", 256);
	printf("@main_ftprintf: %####0000 33..1..#00d\n", 256);
	
	printf("@main_ftprintf: %####0000 33.d\n", 256);
	printf("@main_ftprintf: %####0000 33d\n", 256);

	char *l = setlocale(LC_CTYPE, "");
    wchar_t w =	L'猫';
	
	printf("MB_CUR_MAX : %i\n", MB_CUR_MAX);
	printf("sizeof 猫: %zu\n", sizeof(w));

	ft_printf("%c\n", 'c');
	printf("%c\n", 'c');

	ft_printf("%C\n", 165);
    printf("%C\n", 165);

	ft_printf("%C\n", 10084);
	printf("%C\n", 10084);

	ft_printf("%C%C\n", '4', '2');
	printf("%C%C\n", '4', '2');

	ft_printf("%C, %i\n", L'猫', L'猫');
	printf("%C, %i\n", L'猫', L'猫');

	ft_printf("%lc, %lc\n", L'猫', L'猫');
	printf("%lc, %lc\n", L'猫', L'猫');


	setlocale(LC_CTYPE, "");
	ft_printf("sizeof ✓❤❤❤✓: %zu\n", sizeof(L"✓❤❤❤✓"));

	ft_printf("%S\n", NULL);
	
	ft_printf("%S\n", L"✓❤❤❤✓");
	printf("%3S\n", L"✓❤❤❤✓");
	

	ft_printf("%S\n", L"米");

	ft_printf("%40S\n", NULL);
	printf("%40S\n", NULL);

	ft_printf("{%05.S}\n", L"42 c est cool");
	printf("{%05.S}\n", L"42 c est cool");
	
	ft_printf("{%05p}\n", 0);
	printf("{%05p}\n", 0);

	int x;


	f_pr = ft_printf("%S%hhn\n", L"aa我是一只猫。", &x);
	pr = printf("%S%hhn\n", L"aa我是一只猫。", &n);
	
	printf("ft_printf: %d\n", f_pr);
	printf("printf: %d\n", pr);
	ft_printf("ft_printf ft_n: %d\n", x);
	printf("printf n: %d\n", n);



	ft_printf("|%04.2i|\n", 42);
	printf("|%04.2i|\n", 42);

	//ft_printf("***\n%lccabc\n%ad\n%s\n***\n", 65, 65, "asd");




	   
	system("leaks a.out");
	return(0);
}