
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

extern int id;		//记录彩票的id；
extern int lucknum;//记录中奖号码；
//extern int balance;//记录彩民余额；

/*定义彩票信息的结构体*/
typedef struct piaoinfo
{
	int qihao;		//记录彩票期号
	int id;			//记录彩票id
	int price;		//记录彩票单价
	int num;			//记录购买号码
	char name[10];  //记录购买彩票的用户名
	int zhu;			//记录购买注数，单张不得超过5张
	char bingo[3]; 	//记录中奖状态0表不中，1表中
	int rmb;			//记录中奖金额
	struct piaoinfo *next;
}PI,*pi;

/*管理员发布的彩票*/
typedef struct faxing
{
	int qihao;		//期号
	int price;		//单价
	char bingo[3];	//开奖状态
	int lucknum;		//中奖号码
	int zhu;			//注数
	int sum;			//奖池金额
}FX,*pfx;
/*彩民注册帐号和密码的结构体*/
typedef struct user{
	char name[10];
	char passwd[10];
	int balance;
	struct user *next;
}SU,*psu;

/*主界面 1.登录，2.注册，3.退出*/
void menu ();

/*登录子界面*/
void menu_1();

/*普通用户登录界面*/
psu userlogin();

/*管理员登录*/
void adminlogin();

/*管理员菜单*/
void adminmenu();

/*公证人功能函数*/
void goodman();

/*注册功能*/
void enroll();



