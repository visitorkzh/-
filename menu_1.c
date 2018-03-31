/*登录子界面*/
#include"my.h"

void menu_1()
{
	system("clear");
	printf("\t\t\t**************************\n");
	printf("\t\t\t**    1.管理员登录      **\n");
	printf("\t\t\t**    2.普通彩民登录    **\n");
	printf("\t\t\t**    3.公证人登录      **\n");
	printf("\t\t\t**    4.退出            **\n");
	printf("\t\t\t**************************\n");
	printf("请选择：");
	int num;
	scanf("%d",&num);
	switch(num)
	{
		case 1:adminlogin();//调用管理员登录函数
			break;
		case 2:userlogin(); //调用普通用户登录函数
			break;
		case 3:goodman();	  //调用公证人登录函数
			break;
		case 4:menu();		  //返回主函数
			break;
		default:printf("选择无效！\n");
			break;
	}
}

