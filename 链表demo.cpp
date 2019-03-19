#include "链表demo.h"
#include "类方法定义.cpp"
#include "普通函数定义.cpp"
int main()
{
	
	cout<<"版权所有：郑茂基<学号:221801222>"<<endl;
	Put_Time();
	Menu();                                                                             //显示菜单
	Date_Linklist demo;                                                                 //创建Date_Linklist实例对象
	char ch;
	while(ch=toupper(ch=getch()))
	{
		cout<<ch;
		switch(ch)
		{
			case'C':
				Creat_Knot(&demo);      //创建结点
				Menu();
				break;
			case'I':
				demo.Inser_Knot();
				Menu();
				break;
			case'O':
				Outshow_Knot(&demo);         //显示结点
				Menu();
				break;
            case'T':                         //显示结点到2000.1.1天数
            	demo.Date_Linklist::Day_To_200011();
            	Menu();
            	break;
			case'Q':
				cout<<ch<<endl<<"您已退出，感谢使用本系统。"<<endl;
				exit(0);
				break;
			case'U':
				cout<<"所存储日期中不合法日期如下："<<endl;
				demo.Ile_Out();
				cout<<endl;
				Menu();
				break;
            case'D':
            	demo.Delete_Knot();
				Menu();
            	break;
			case'F':
				demo.Find_Prime();
				Menu();
				break;
			case'P':
				demo.Sort_Linklist_Btos();
				Menu();
				break;
			case'R':
				demo.Reverse_Linklist();
				Menu();
				break;
			case'S':
				demo.SaveToFile();
				Menu();
				break;
			case'X':
				X_Ping();
				Menu();
				break;
			default:
				cout<<endl<<"输入有误请重新输入。"<<endl;
				break;
				
		}
    }
}








