/*公证人功能*/

#include"my.h"

/*开奖函数*/
void randnum();
/*查看彩票信息*/


void goodman()
{
	system("clear");
	printf("\t\t\t**************************\n");
	printf("\t\t\t**      1.开奖          **\n");
	printf("\t\t\t**      2.查看彩票信息  **\n");
	printf("\t\t\t**      3.退出登录      **\n");
	printf("\t\t\t**************************\n");
	printf("请选择：");
	int num;
	scanf("%d",&num);
	switch(num)
	{
		case 1:randnum();//调用开奖函数，产生本期中奖号码
				break;
		case 2:          //查看彩票信息
				break;
		case 3:menu();   //退出公证人帐号，返回主界面
				break;
		default:printf("选择无效！！\n");
				break;
	}
}

/*开奖函数,获得随即数*/
void randnum()
{
	srand((unsigned)time(0));
	lucknum= rand()%10;
	system("clear");
	printf("\t\t\t**************************\n");
	printf("\t\t\t**  本期中奖号码是：%d   **\n",lucknum);
	printf("\t\t\t**  恭喜各位中奖者！！  **\n");
	while(1)
	{
		printf("\t\t\t**************************\n");
		printf("\t\t\t**  1.返回上一菜单      **\n");
		printf("\t\t\t**  2.返回主菜单        **\n");
		printf("\t\t\t**************************\n");
		printf("**请选择：");
		int num;
		if (scanf("%d",&num) != 1)
		{
			getchar();
			printf("输入无效！！\n请重新输入：\n");
			continue;
		}
		else 
		{
			switch(num)
			{
				case 1:goodman();
					break;
				case 2:menu();
					break;
				default:printf("***选择无效！！\n***请重新选择：\n");
					continue;
			}	
		}
	}
}




