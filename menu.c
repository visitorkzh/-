
#include"my.h"

void menu ()
{	
	system("clear");
	printf("\t\t\t**************************\n");
	printf("\t\t\t**       欢迎使用       **\n");
	printf("\t\t\t**    彩票管理系统1.0   **\n");
	printf("\t\t\t**************************\n");
	printf("\t\t\t**       1.登录         **\n");
	printf("\t\t\t**       2.注册         **\n");
	printf("\t\t\t**       3.退出         **\n");
	printf("\t\t\t**************************\n");
	int num;
	printf("请选择：");
	scanf("%d",&num);
	switch(num)
	{
		case 1:menu_1();
			break;
		case 2:enroll();
			break;
		case 3:
			exit(1);
		default:printf("选择无效！\n");
			break;
	}
}


