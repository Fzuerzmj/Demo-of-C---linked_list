
void Menu()
{
	cout<<"************************************************************************"<<endl;
	cout<<"*     C:����������������              				        *"<<endl;
	cout<<"*     O:��ʾ�б��ض�������            				*"<<endl;
	cout<<"*     I:������(��ͷ�����ǰ��������β)                            *"<<endl;
	cout<<"*     S:�������е����ݴ��뵽�ļ���       				*"<<endl;
	cout<<"*     X:������ʾ���������ļ���(ȫ������) 				*"<<endl;
	cout<<"*     U:��ʾ�����еĲ��Ϸ�����           				*"<<endl;
	cout<<"*     D:ɾ�������һ�������һ��,�Ϸ�����				*"<<endl;
	cout<<"*     T:��ʾ�ڵ����ڵ�2000.1.1�յ�����   				*"<<endl;
	cout<<"*     P:������������                     				*"<<endl;
	cout<<"*     F:���������С��ꡢ�¡��ա���������������			        *"<<endl;
	cout<<"*     R:����ת����                     				*"<<endl;
	cout<<"*     Q:�˳�ϵͳ                         				*"<<endl;
	cout<<"************************************************************************"<<endl;
	cout<<"��ѡ����Ҫִ�еĲ�����";

}

void Put_Time()     //��ʾϵͳʱ��
{
 	const string wday[7]={"������","����һ","���ڶ�","������","������","������","������"};
	time_t t;
    struct tm *lt;
    time (&t);//��ȡʱ���
    lt = localtime (&t);//תΪʱ��ṹ
//    printf ( "��ǰʱ�䣺%d��%02d��%02d�գ�%s�� %02d:%02d:%02d\n",lt->tm_year+1900, lt->tm_mon+1, \
//	lt->tm_mday, wday[lt->tm_wday],lt->tm_hour, lt->tm_min, lt->tm_sec);//������
	cout<<"��ǰʱ�䣺"<<lt->tm_year+1900<<"��"<<setw(2)<<setfill('0')<<lt->tm_mon+1<<"��"<<setw(2)<<setfill('0')<<lt->tm_mday<<"��"<<"      "<<wday[lt->tm_wday]<<"       ";
	cout<<setw(2)<<setfill('0')<<lt->tm_hour<<":"<<setw(2)<<setfill('0')<<lt->tm_min<<":"<<setw(2)<<setfill('0')<<lt->tm_sec<<endl;
 }

bool Is_New_Success(void *p)//�жϿռ�����Ƿ�ɹ�
{
    if(p==NULL)
	{
		cout<<"�ռ䲻�㣬�ڴ����ʧ�ܣ��Զ��˳�ϵͳ��"<<endl;
		exit(1);
	}
	else
	{
		return true;
	}
}

void Creat_Knot(Date_Linklist *demo)  //����Cʵ��,����ָ���������ڽ��
{
	int sign;
	cout<<endl<<"1>�Զ������ڸ���(��󳤶�Ϊ5000)        2>Ĭ�����ڸ���"<<endl<<"��ѡ��:";                //���Ի�ѡ��
	while(sign=getch()-'0')
	{
		cout<<sign;
		bool is_success=false;                                                                                  //�޻���ѡ��
		if(sign==2)
		{
			demo->Add_Date();
			cout<<endl<<demo->Get_Date_Cnt()<<" ��������������ɡ�"<<endl;
			is_success=true;   //�����ɹ�
		}
		else if(sign==1)
		{
			cout<<endl<<"��������Ҫ���������ڵĸ���,����<Enter>��������:";
			int cnt;
			while(cin>>cnt)
			{
				bool sign=false;
				if(cnt>5000)
				{
                   	cout<<endl<<"�Զ������ֻ����5000���ڣ����������룺";

				}
				else
				{
					demo->Add_Date(cnt);
					cout<<demo->Get_Date_Cnt()<<" ��������������ɡ�"<<endl;
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

void Outshow_Knot(Date_Linklist *demo)        //����oʵ�֣���ʾ���
{
		 cout<<endl<<"��Ҫ��ʾ�����ڸ�������ǰ���ڸ�����"<<demo->Get_Date_Cnt()<<"������";
			 int show;     //��ʾ�ĸ���
			 while(cin>>show)
			 {
			 	int Is_Success=false;
			 	if(show>demo->Get_Date_Cnt())
			 	{
			 		cout<<endl<<"����ĸ������ڵ�ǰϵͳ������������ڸ���,���������롣" ;
			 		cout<<endl<<"�����룺";
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

int Day_Of_Year(int *time)     //����һ��������һ��ĵڼ���,�������Ϊ���������յ�����
{
	int sum=0;
	for(int i=0;i<*(time+1)-1;i++)
		sum+=DAYOFMONTH[i];
	sum+=*(time+2);
	if(Is_Leapyear(*(time+0))&&(*(time+1)>2||(*(time+1)==2&&*(time+2)==29)));
		sum+=1;
	return sum;
}

int Day_To_2000(int year)      //����2000��1.1ָ�����1.1���˶�����
{
	int cnt_leap=(year-2000)/4;  //2000�겻�����꣬���Կ��Բ���һ
	cnt_leap-=((year-2000)-1)/400;    //��ȥ2400��2000�������������ƽ��
	return 366*cnt_leap+365*(year-1900-cnt_leap);
}

bool Is_Leapyear(int year)       //�Ƿ�Ϊ����
{
	if((year%100==0&&year%400!=0)||(year%100!=0&&year%4==0))
		return true;
	else
		return false;
}

bool Is_Legal(int *time)        //�ж������Ƿ�Ϸ� ���������Ϊ���������յ�����
{
    if(Is_Leapyear(time[0])&&time[1]==2&&time[2]==29)      //���ȿ�����������
		return true;
    else
    {
    	if(DAYOFMONTH[time[1]-1]<time[2])
			return false;
		else
			return true;
    }
}

bool Is_Prime(int num)         //�ж�����
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

int Cmp_Date(int *time1,int *time2)          //�Ƚ��������ڴ�С��ǰ�ߴ󷵻�1(��2000.1.1Զ)��������ͬ����0�����ߴ󷵻�2������������
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

void X_Ping()// X:������ʾ���������ļ���(ȫ������)
{
	ifstream fin;
	fin.open("Date.txt");
	if(!fin)
	{
		cout<<endl<<"�ļ������ڣ���ȡ����ʧ��"<<endl;
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
				cout<<"���������������������"<<endl;
				getch();
			}
		}

	}
}

































