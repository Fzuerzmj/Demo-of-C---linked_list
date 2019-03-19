
void Menu()
{
	cout<<"************************************************************************"<<endl;
	cout<<"*     C:创建无序日期链表              				        *"<<endl;
	cout<<"*     O:显示列表特定区间结点            				*"<<endl;
	cout<<"*     I:插入结点(链头，结点前，结点后，链尾)                            *"<<endl;
	cout<<"*     S:将链表中的数据存入到文件中       				*"<<endl;
	cout<<"*     X:分屏显示日期数据文件的(全部内容) 				*"<<endl;
	cout<<"*     U:显示链表中的不合法日期           				*"<<endl;
	cout<<"*     D:删除链表第一个，最后一个,合法日期				*"<<endl;
	cout<<"*     T:显示节点日期到2000.1.1日的天数   				*"<<endl;
	cout<<"*     P:链表日期排序                     				*"<<endl;
	cout<<"*     F:查找链表中“年、月、日”都是素数的日期			        *"<<endl;
	cout<<"*     R:单向翻转链表                     				*"<<endl;
	cout<<"*     Q:退出系统                         				*"<<endl;
	cout<<"************************************************************************"<<endl;
	cout<<"请选择需要执行的操作：";

}

void Put_Time()     //显示系统时间
{
 	const string wday[7]={"星期天","星期一","星期二","星期三","星期四","星期五","星期六"};
	time_t t;
    struct tm *lt;
    time (&t);//获取时间戳
    lt = localtime (&t);//转为时间结构
//    printf ( "当前时间：%d年%02d月%02d日（%s） %02d:%02d:%02d\n",lt->tm_year+1900, lt->tm_mon+1, \
//	lt->tm_mday, wday[lt->tm_wday],lt->tm_hour, lt->tm_min, lt->tm_sec);//输出结果
	cout<<"当前时间："<<lt->tm_year+1900<<"年"<<setw(2)<<setfill('0')<<lt->tm_mon+1<<"月"<<setw(2)<<setfill('0')<<lt->tm_mday<<"日"<<"      "<<wday[lt->tm_wday]<<"       ";
	cout<<setw(2)<<setfill('0')<<lt->tm_hour<<":"<<setw(2)<<setfill('0')<<lt->tm_min<<":"<<setw(2)<<setfill('0')<<lt->tm_sec<<endl;
 }

bool Is_New_Success(void *p)//判断空间分配是否成功
{
    if(p==NULL)
	{
		cout<<"空间不足，内存分配失败，自动退出系统。"<<endl;
		exit(1);
	}
	else
	{
		return true;
	}
}

void Creat_Knot(Date_Linklist *demo)  //功能C实现,创建指定个数日期结点
{
	int sign;
	cout<<endl<<"1>自定义日期个数(最大长度为5000)        2>默认日期个数"<<endl<<"请选择:";                //个性化选择
	while(sign=getch()-'0')
	{
		cout<<sign;
		bool is_success=false;                                                                                  //无缓冲选择
		if(sign==2)
		{
			demo->Add_Date();
			cout<<endl<<demo->Get_Date_Cnt()<<" 个日期已随机生成。"<<endl;
			is_success=true;   //创建成功
		}
		else if(sign==1)
		{
			cout<<endl<<"请输入想要创建的日期的个数,并按<Enter>结束输入:";
			int cnt;
			while(cin>>cnt)
			{
				bool sign=false;
				if(cnt>5000)
				{
                   	cout<<endl<<"自定义个数只能在5000以内，请重新输入：";

				}
				else
				{
					demo->Add_Date(cnt);
					cout<<demo->Get_Date_Cnt()<<" 个日期已随机生成。"<<endl;
					sign=true;
					is_success=true;
				}
				if(sign==true)
					break;
				}
			}
			if(is_success==true)
				break;
	}

}

void Outshow_Knot(Date_Linklist *demo)        //功能o实现，显示结点
{
		 cout<<endl<<"需要显示的日期个数（当前日期个数有"<<demo->Get_Date_Cnt()<<"个）：";
			 int show;     //显示的个数
			 while(cin>>show)
			 {
			 	int Is_Success=false;
			 	if(show>demo->Get_Date_Cnt())
			 	{
			 		cout<<endl<<"输入的个数大于当前系统所含的最大日期个数,请重新输入。" ;
			 		cout<<endl<<"请输入：";
			 	}
			 	else
			 	{
					demo->Show_Knot(show);
					Is_Success=true;
				}
				if(Is_Success)
					break;
			 }
}

int Day_Of_Year(int *time)     //计算一个数是这一年的第几天,传入参数为存有年月日的数组
{
	int sum=0;
	for(int i=0;i<*(time+1)-1;i++)
		sum+=DAYOFMONTH[i];
	sum+=*(time+2);
	if(Is_Leapyear(*(time+0))&&(*(time+1)>2||(*(time+1)==2&&*(time+2)==29)));
		sum+=1;
	return sum;
}

int Day_To_2000(int year)      //计算2000。1.1指定年的1.1过了多少天
{
	int cnt_leap=(year-2000)/4;  //2000年不是闰年，所以可以不加一
	cnt_leap-=((year-2000)-1)/400;    //减去2400，2000这种特殊情况的平年
	return 366*cnt_leap+365*(year-1900-cnt_leap);
}

bool Is_Leapyear(int year)       //是否为闰年
{
	if((year%100==0&&year%400!=0)||(year%100!=0&&year%4==0))
		return true;
	else
		return false;
}

bool Is_Legal(int *time)        //判断日期是否合法 ，传入参数为存有年月日的数组
{
    if(Is_Leapyear(time[0])&&time[1]==2&&time[2]==29)      //优先考虑特殊现象
		return true;
    else
    {
    	if(DAYOFMONTH[time[1]-1]<time[2])
			return false;
		else
			return true;
    }
}

bool Is_Prime(int num)         //判断素数
{
	double sqr=sqrt(double(num));
	bool prime=true;
	if(num==0||num==1)
		prime=false;
	else if(num>2)
	{
		for(int i=2;i<sqr;i++)
		{
			if(num%i==0)
			{
				prime=false;
				break;
			}
		}
	}
	return prime;
}

int Cmp_Date(int *time1,int *time2)          //比较两个日期大小，前者大返回1(离2000.1.1远)，两者相同返回0，后者大返回2传入两个数组
{
	int sign=1;
	if(time1[0]<time2[0])
		sign=2;
	else if(time1[0]==time2[0])
	{
		if(time1[1]<time2[1])
			sign=2;
		else if(time1[1]==time2[1])
		{
			if(time1[2]<time2[2])
				sign=2;
			else if(time1[2]==time2[2])
				sign=0;
		}
	}
	return sign;
}

void X_Ping()// X:分屏显示日期数据文件的(全部内容)
{
	ifstream fin;
	fin.open("Date.txt");
	if(!fin)
	{
		cout<<endl<<"文件不存在，读取数据失败"<<endl;
	}
	else
	{
		char str[200];
		int out_cnt=0;
		cout<<endl;
		while(fin.getline(str,200))
		{
			out_cnt++;
			cout<<'<'<<setw(3)<<setfill('0')<<out_cnt<<'>'<<"    "<<str<<endl;

			if(out_cnt%30==0)
			{
				cout<<"按任意键继续。。。。。"<<endl;
				getch();
			}
		}

	}
}

































