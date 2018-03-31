/*管理员菜单*/

#include"my.h"

/*查看彩票信息*/
void faxing();
/*查询彩民信息*/
psu printinfo();
void print();
/*按彩民用户名排序*/
psu paixu();
/*保存彩票信息和彩民信息到文件中*/
void writetofile();

void adminmenu()
{
	while(1)
	{
		system("clear");
		printf("\t\t\t***************************\n");
		printf("\t\t\t** 1.发行彩票            **\n");
		printf("\t\t\t** 2.查看彩民信息        **\n");
		printf("\t\t\t** 3.根据彩民帐号排序    **\n");
		printf("\t\t\t** 4.保存彩票和彩民信息  **\n");
		printf("\t\t\t***************************\n");
		printf("请选择：");
		int num;
		scanf("%d",&num);
		switch(num)
		{
			case 1:if(lucknum == -1)
					{
						printf("对不起，上一期彩票还未开奖，您无权发行彩票！！\n");
						continue;
					}
					faxing();//发行彩票
					break;
			case 2:print();//查看彩民信息
					break;
			case 3:paixu();//排序；
					break;
			case 4:writetofile();
					menu();
					break;
			default:printf("输入了无效的选择！！\n");
	//				adminmenu();
					break;
		}
	}
}
/*查看彩票信息*/
void faxing()
{
	int qihao=0,price=5,sum,zhu;
	sum=zhu*5;
	char bingo[3]={'\0'};
	if (lucknum != -1)
		strcpy(bingo,"开");
	else
		strcpy(bingo,"无");
	printf("本次彩票期号：%d\n",qihao);
	printf("    彩票单价：%d元/注\n",price);
	printf("    开奖状态：%s\n",bingo);
	printf("    中奖号码：%d\n",lucknum);
//	printf("本期售出注数：%d\n",zhu);
//	printf("本期奖池总额：%d\n",sum);
}
/*查看彩民信息，并返回查看后链表*/
psu printinfo()
{
	FILE *fp=fopen("./etc/username.txt","r");
	if (NULL == fp)    return;
	psu L = (psu)malloc(sizeof(SU));
	L->next=NULL;
	psu p=L;
	SU us;
	while( !feof(fp))
	{
		if(fscanf(fp,"%s%s%d",us.name,us.passwd,&us.balance)==3)
		{
			psu new= (psu)malloc(sizeof(SU));
			strcpy(new->name,us.name);
			strcpy(new->passwd,us.passwd);
			new->balance = us.balance;
			p->next=new;
			p=new;
		}
		p->next=NULL;
	}
	fclose(fp);
	return L;
}
void print()
{
	psu L=printinfo();
	psu q=L->next;
	while(q)
	{
		printf("用户名：%s\n余额：%d\n",q->name,q->balance);
		q=q->next;
	}
}

/*按彩民用户名排序*/
psu paixu()
{
	psu L=printinfo();
	psu p=L,x,y;
	psu tmax=NULL;
	if(L->next == NULL)
	{
		printf("无用户信息！！\n");
		return;
	} 
	else if(L->next->next == NULL)
	{
		printf("只有一个用户，无需排序！！\n");
		return;
	}
	else
	{
		 while( tmax !=L->next->next)
		 {
			 for(p=L;p->next->next != tmax;p=p->next)
			 {
			 	if(strcmp(p->next->name,p->next->next->name)> 0)
			 	{
			 		x = p->next;	y=p->next->next;
			 		p->next = y;	x->next = y->next;
			 		y->next = x;
			 	}
			 }
			 tmax=p->next;
		}
	}
	return L;
}

/*保存彩票信息和彩民信息到文件中*/
void writetofile()
{
	psu L=paixu();
	psu q=L->next;
	FILE *fp=fopen("./etc/lotanduser.txt","w");
	if (NULL == fp)   return;
	while(q)
	{
		fprintf(fp,"%s\t\t%s\t\%d\n",q->name,q->passwd,q->balance);
		q=q->next;
	}
}

