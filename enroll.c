/*注册帐号*/
#include"my.h"

void enroll()
{
	psu L,p,r;
	char username[10]={'\0'};
	char passwd1[10]={'\0'};
	char passwd2[10]={'\0'};
	L = (psu)malloc(sizeof(SU));
	L->next = NULL;
	p=L;
	FILE *fp;
	fp = fopen("./etc/username.txt","a+");
	if(NULL == fp)
	{
		printf("open  username.txt  defeated!!\n");
		return;
	}
	while( !feof(fp))
	{
		psu new = (psu)malloc(sizeof(SU));
		if (fscanf(fp,"%s%s%d",new->name,new->passwd,&new->balance) == 3)
		{
			p->next = new;
			p = new;
		}
		new ->next = NULL;
	}
	p->next = NULL;
	while( 1 )
	{
		printf("请输入用户名：");
		scanf("%s",username);
		printf("请输入密码：");
		scanf("%s",passwd1);
		printf("请再输入一次密码：");
		scanf("%s",passwd2);
		if ( strcmp(passwd1,passwd2) != 0 )
		{
			printf("两次输入的密码不一致，请重新输入：\n");
			continue;
		}
		else
			break;
	}
	r=L;
	r=r->next;
	while(r)
	{
		if(strcmp(r->name,username) == 0)
		{
			printf("对不起，该帐户已存在，请重新选择！\n");
			return;
		}
		else
			r=r->next;
	}
	psu q;
	q = (psu)malloc(sizeof(SU));
	q->next = NULL;
	q = L->next;
	strcpy(q->name,username);
	strcpy(q->passwd,passwd1);
	q->balance = 0;
	while(q)
	{
		fprintf(fp,"%s\t\t%s\t%d\n",q->name,q->passwd,q->balance);
		q=q->next;
	}
	fclose(fp);
	printf("恭喜！！注册成功！！\n");
	menu();
}

