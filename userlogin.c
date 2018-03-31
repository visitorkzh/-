/*普通用户登录*/

#include"my.h"

/*用户界面*/
void usermenu(psu H,char *usern);

/*保存退出*/
//void savetofile(psu H);

/*查看当前用户信息*/
void checkuserinfo(psu H,char *usern);

/*修改彩民密码*/
void changpasswd(psu H,char *usern);

/*彩民充值*/
void chongzhi(psu H,char *usern);

/*注销帐号*/
void deleteuser(psu H,char *usern);

/*彩民登录*/
psu userlogin()
{
	char usern[10]={'\0'};
	char passw[10]={'\0'};
	printf("请输入帐号：");
	scanf("%s",usern);
	printf("请输入密码：");
	scanf("%s",passw);
	psu H=(psu)malloc(sizeof(SU));
	H->next=NULL;
	psu p = H;
	FILE *fp=fopen("./etc/username.txt","r");
	if(NULL == fp)	return ;
	while( !feof(fp))
	{
		psu new = (psu)malloc(sizeof(SU));
		new ->next = NULL;
		if (fscanf(fp,"%s%s%d",new->name,new->passwd,&new->balance) == 3)
		{
			p->next = new;
			p = new;
		}
	} p->next = NULL;
	fclose(fp);
	psu q = H;
	q = q->next; 
	while(q)
	{
		if (strcmp(q->name,usern) == 0 && strcmp(q->passwd,passw) == 0)
		{
			usermenu(H,usern);
			;
		}
		else
			q = q->next;;	
	}
	printf("对不起，登录失败！！\n");
	printf("是否前去注册？( y / n)");
	char ch;
	getchar();
	scanf("%c",&ch);
	if ( ch == 'y' || ch =='Y')
		enroll();
	else
		menu_1();
}

/*user   menu*/
void usermenu(psu H,char *usern)
{
	system("clear");
	printf("\t\t\t**************************\n");
	printf("\t\t\t**  1.查看个人信息      **\n");
	printf("\t\t\t**  2.修改密码          **\n");
	printf("\t\t\t**  3.帐户充值          **\n");
	printf("\t\t\t**  4.购买彩票          **\n");
	printf("\t\t\t**  5.查看未开奖彩票    **\n");
	printf("\t\t\t**  6.查看历史记录      **\n");
	printf("\t\t\t**  7.保存注销登录      **\n");
	printf("\t\t\t**  8.注销帐号          **\n");
	printf("\t\t\t**************************\n");
	int num;
	static int balance;
	printf("请选择：");
	scanf("%d",&num);
	switch(num)
	{
		case 1:checkuserinfo(H,usern);		//查看个人信息
				break;
		case 2:changpasswd(H,usern);		   //修改密码
				break;
		case 3:chongzhi(H,usern);			   //帐户充值
				break;
		case 4:		//购买彩票
				break;
		case 5:		//待开奖彩票
				break;
		case 6:		//历史购买记录
				break;
		case 7:	//保存信息，注销登录
				menu();
				break;
		case 8:deleteuser(H,usern);
				break;
		default:printf("输入了无效选择！！\n请重新选择：\n");
	//			usermenu();
				break;
	}
}

/*查看当前用户信息*/
void checkuserinfo(psu H,char *usern)
{
	psu p,q;
	p=H;
	p = p->next;	
	while(p)
	{
		if(strcmp(p->name,usern) == 0)
		{
			printf("用户名：%s\n帐户余额：%d\n",p->name,p->balance);
			break;
		}
		else
			p=p->next;
	}
	printf("\t\t\t**************************\n");
	printf("\t\t\t**  1.返回上一菜单      **\n");
	printf("\t\t\t**  2.返回主菜单        **\n");
	printf("\t\t\t**************************\n");
	printf("\n\n**请选择：");
	int num;
	while(1)
	{
		scanf("%d",&num);
		switch(num)
		{
			case 1:usermenu(H,usern);
				break;
			case 2:menu();
				break;
			default:printf("***选择无效！！\n***请重新选择：");
				continue;
		}	
	}
}


/*修改密码*/
void changpasswd(psu H,char *usern)
{
	psu p,q;
	p=H;
	p=p->next;
	char passwd[10],passwd1[10],passwd2[10];
	/*
	while(p)
	{
		if (strcmp(p->name,usern) == 0)
			break;
		else
			p=p->next;
	}
	*/
	while(1)
	{	
		printf("请输入旧密码：");
		scanf("%s",passwd);
		printf("请输入新密码：");
		scanf("%s",passwd1);
		printf("请再输入一次新密码：");
		scanf("%s",passwd2);	
		if (strcmp(passwd1,passwd2) != 0)
		{
			printf("对不起，旧密码输入有误，请重新输入");
				continue;
		}
		else if (strcmp(passwd1,passwd2) == 0)
			break;
	}
	printf("是否确认修改？（y/n）");
	getchar();
	char ch;
	scanf("%c",&ch);
	if ( ch == 'Y' || ch == 'y' )
	{
		while(p)
		{
			if (strcmp(p->name,usern) == 0)
			{
				strcpy(p->passwd,passwd1);
				break;
			}
			else
				p=p->next;
		}
		FILE *fp=fopen("./etc/username.txt","w");
		if ( NULL == fp)   return;
		q=H;
		q=q->next;
		while(q)
		{
			fprintf(fp,"%s\t\t%s\t\t%d\n",q->name,p->passwd,p->balance);
			q=q->next;
		}
		fclose(fp);
		printf("密码修改成功！！\n");
	}
	else if (ch == 'n' || ch == 'N')
	{
		printf("密码无修改！！\n");
	}
	printf("\t\t\t**************************\n");
	printf("\t\t\t**  1.返回上一菜单      **\n");
	printf("\t\t\t**  2.返回主菜单        **\n");
	printf("\t\t\t**************************\n");
	printf("\n\n**请选择：");
	int num;
	while(1)
	{
		scanf("%d",&num);
		switch(num)
		{
			case 1:usermenu(H,usern);
				break;
			case 2:menu();
				break;
			default:printf("***选择无效！！\n***请重新选择：");
				continue;
		}	
	}	
}

/*彩民充值*/
void chongzhi(psu H,char *usern)
{
	psu p=H,q=H;
	p=p->next;
	int num;
	while(p)
	{
		if ( strcmp(p->name,usern) == 0)
			break;
		else
			p=p->next;
	}
	while(1)
	{
		printf("请输入充值金额(不能高于9999)：");
		scanf("%d",&num);
		if ( num >9999 || num < 0)
		{
			printf("对不起,无效充值！\n");
			continue;
		}
		else
		{
			p->balance += num;
			printf("充值成功！！\n");
			break;
		}
	}
	psu s=H;
	s=s->next;
	FILE *fp=fopen("./etc/username.txt","w+");
	if(NULL == fp)	return ;
	while(s)
	{
		fprintf(fp,"%s\t\t%s\t\t%d\n",s->name,s->passwd,s->balance);
		s=s->next;
	}
	fclose(fp);
//	usermenu(H,usern);
}
/*保存退出*/
void savetofile(psu H)
{
	
}

/*购买彩票*/
pi buylot()
{
	printf("");

}

/*注销帐号*/
void deleteuser(psu H,char *usern)
{
	psu p,q;
	p=H;
//	p=p->next;
	while(p->next)
	{
		q=p->next;
		if ( strcmp(q->name,usern) == 0 )
		{
			printf("确认注销帐号？(y/n)");
			getchar();
			char ch;
			scanf("%ch",&ch);
			if( ch == 'y' || ch == 'Y')
			{
				p=q->next;
				free(q);
				break;
			}
			else
			{
				printf("帐号无删除！\n");
				break;
			}
		}
		else
			p=p->next;
	}		
}

