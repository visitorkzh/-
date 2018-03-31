/*管理员登录*/

#include"my.h"

void adminlogin ()
{
	char adminame[7]={'\0'},passwd[7]={'\0'};
	while(1)
	{
		printf("请输入管理员帐号：");
		scanf("%s",adminame);
		printf("请输入管理员密码：");
		scanf("%s",passwd);
		if ( strcmp(adminame,"admin") !=0 || strcmp(passwd, "admin") != 0)
		{
			printf("输入的帐号或密码不正确，请重新输入！\n");
			continue;
		}
		else if( strcmp(adminame,"admin") == 0 && strcmp(passwd,"admin") == 0)
			break;
		else
			continue;
	}
	adminmenu();
}

