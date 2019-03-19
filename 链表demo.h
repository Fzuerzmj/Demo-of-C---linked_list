#include<iostream>
#include<conio.h>
#include<cctype>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<cstring>
#include<cmath>
#include<fstream>
using namespace std;
const int DAYOFMONTH[12]={31,28,31,30,31,30,31,31,30,31,30,31};

class Date_Linklist
{
	private:
		enum{three=3};
		int knot_cnt;
		int max_cnt;
		typedef struct knot{
			int date[three];
			knot *next;
		}Knot;
		Knot *head;
	public:
		Date_Linklist();
		~Date_Linklist();
		//运算符重载
		void Add_Date(int cnt);
		int Get_Max_Cnt(){return max_cnt;}                   //内联函数，返回链表所能储存的最大个数
		int Get_Date_Cnt(){return knot_cnt;}                   //内联函数，当前储存日期的个数
		void Show_Knot(int n=50);
		int Day_To_200011();               //计算节点日期到2000.1.1日的天数
		void Ile_Out(); //U:显示链表中的不合法日期
		void Delete_Knot();//D:删除链表第一个，最后一个,合法日期
		void Find_Prime(); //F:查找链表中“年、月、日”都是素数的日期
		void Sort_Linklist_Btos();//P:链表日期排序
  		void Reverse_Linklist();//R:单向翻转链表
  		void SaveToFile();//功能S实现，将节点的数据存入文件当中
  		void Inser_Knot();//添加结点

};


//普通函数

void Menu();//显示菜单
void Put_time();//显示系统时间
bool Is_New_Success(void *p);//判断空间分配是否成功

/////main函数中的控制函数
void C(Date_Linklist *demo);//功能C实现,创建日期结点
//实现上述main中函数所需的辅助函数
int Day_Of_Year(int *time);  //计算一个数是这一年的第几天,传入参数为存有年月日的数组
int Day_To_2000(int year);      //计算2000。1.1指定年的1.1过了多少天
bool Is_Leapyear(int year);       //是否为闰年
bool Is_Legal(int *time);        //判断日期是否合法
bool Is_Prime(int num);         //判断素数
int Cmp_Date(int *time1,int *time2);//比较两个日期大小，大返回一(离2000.1.1远)，反之返回0
void X_Ping();// X:分屏显示日期数据文件的(全部内容)





















