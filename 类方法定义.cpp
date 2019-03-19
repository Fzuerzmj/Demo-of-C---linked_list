Date_Linklist::~Date_Linklist()
{
	Knot *save,*p;
	for(p=head,save=head;p!=NULL;p=save)
	{
		save=p->next;
		delete p;
	}
}

Date_Linklist::Date_Linklist(){                     //默认构造函数
	max_cnt=5000;
	knot_cnt=0;
	head=new Knot;    //为头节点分配内存
	Is_New_Success(head);  //检查分配空间是否成功
	head->next=NULL;
}

void Date_Linklist::Add_Date(int cnt=5000)
{
	Knot *p;
	srand(time(0));
	for(int i=0;i<cnt;i++)
	{
		  p=new Knot;
		  Is_New_Success(p);          //检查空间分配是否成功
		  p->date[0]=2000+rand()%100+1;
		  p->date[1]=rand()%12+1;
		  p->date[2]=rand()%31+1;
		  p->next=head->next;
		  head->next=p;
		  knot_cnt++;
	}
}
void Date_Linklist::Show_Knot(int n)
{
	int i=0,a_show=0;
	for(Knot *p=head->next;p!=NULL&&a_show<n;p=p->next,i++,a_show++)
	{
		cout<<p->date[0]<<'.'<<setw(2)<<setfill('0')<<p->date[1]<<'.'<<setw(2)<<setfill('0')<<p->date[2]<<"       ";  //输出并统一格式
		if(i==6)         //每 7个一组
		{
			cout<<endl;
			i-=7;
		}
	}
	cout<<endl;
}

int Date_Linklist::Day_To_200011()               //计算节点日期到2000.1.1日的天数
{
	Knot *p;
	int i=1;
	cout<<endl<<"程序中存储的日期到2000年1月1日天数为："<<endl;
	for(p=head->next;p!=NULL&&i<21;p=p->next,i++)
	{
		  int day_cnt=Day_Of_Year(p->date)+Day_To_2000((p->date)[0]);
		  cout<<setw(5)<<day_cnt<<"             ";
		  if(i%4==0)
			cout<<endl;
	}
	int show_day;//打印了多少个日期
	show_day=knot_cnt<20?knot_cnt:20;
	cout<<endl<<"为你打印了前"<<show_day<<"个日期"<<endl;
}

void Date_Linklist::Ile_Out()  //U:显示链表中的不合法日期
{
	int cnt=0; //标识什么时候应该回车了
	for(Knot *p=head->next;p!=NULL;p=p->next)
	{
		if(!Is_Legal(p->date))
		{
  			cout<<p->date[0]<<'.'<<setw(2)<<setfill('0')<<p->date[1]<<'.'<<setw(2)<<setfill('0')<<p->date[2]<<"       ";  //输出并统一格式
  			cnt++;
  			if(cnt%5==0)
				cout<<endl;
		}
	}
	cout<<"找到"<<cnt<<"个非法日期"<<endl;
}

void Date_Linklist::Delete_Knot()//D:删除链表第一个，最后一个,合法日期
{
	int delete_cnt=0;//记录删除的总个数。
	Knot *pre;
	Knot *p=head->next;
	head->next=p->next;
	delete p;//释放空间
	delete_cnt++;
	cout<<endl<<"第一个日期结点已删除。"<<endl;   //删除第一个结点
	knot_cnt--;
	for(pre=head,p=head->next;p!=NULL;)
	{
		if(!Is_Legal(p->date))
		{
			pre->next=p->next;
			delete p;   //释放空间
			knot_cnt--;
			delete_cnt++;
			p=pre->next;
		}
		else
		{
			pre=p;
			p=p->next;
		}
	}
	cout<<"非法日期结点已删除。"<<endl;
	for(pre=head,p=head->next;p->next!=NULL;pre=p,p=p->next);
	pre->next=NULL;
	delete p;
	knot_cnt--;
	delete_cnt++;
	cout<<"最后一个日期结点已释放。"<<endl;
	cout<<"共删除"<<delete_cnt<<"个结点。"<<"其中不合法结点"<<delete_cnt-2<<"个"<<endl;
}

void Date_Linklist::Find_Prime() //F:查找链表中“年、月、日”都是素数的日期
{
	cout<<endl<<"年月日均为素数的日期如下："<<endl;
	Knot *p;
	int cnt=0;
	for(p=head->next;p!=NULL;p=p->next)
	{
		if(Is_Prime(p->date[2])&&Is_Prime(p->date[1])&&Is_Prime(p->date[0]))
		{
			cout<<p->date[0]<<'.'<<setw(2)<<setfill('0')<<p->date[1]<<'.'<<setw(2)<<setfill('0')<<p->date[2]<<"       ";  //输出并统一格式
			cnt++;
			if(cnt%5==0)
				cout<<endl;
		}
	}
	cout<<endl;
}

void Date_Linklist::Sort_Linklist_Btos()//P:链表日期排序
{
	Knot *temp=NULL;//交换时使用
	Knot *p1,*p2,*pre1,*pre2;
	cout<<endl<<"排序中..........."<<endl;
	for(pre1=head,p1=head->next;p1->next!=NULL;pre1=p1,p1=p1->next)
	{
		for(pre2=p1->next,p2=pre2->next;p2!=NULL;pre2=p2,p2=p2->next)
		{
			 if(Cmp_Date(p1->date,p2->date)==1)
			 {
			 	  temp=p2->next;
				  pre1->next=p2;
				  p2->next=p1->next;
				  pre2->next=p1;
				  p1->next=temp;
				  temp=p1;
				  p1=p2;
				  p2=temp;
			 }
		}
	}
	cout<<"已完成日期从前到后排序"<<endl;
	
}

void Date_Linklist::Reverse_Linklist()//R:单向翻转链表
{
	 knot *pre,*p;
	 for(pre=head->next,p=pre->next;p!=NULL;)
	 {
	 	pre->next=p->next;
	 	p->next=head->next;
	 	head->next=p;
	 	p=pre->next;
	 }
	 cout<<endl<<"链表翻转完成。"<<endl;
}

void Date_Linklist::SaveToFile()//功能S实现，将节点的数据存入文件当中
{
	 ofstream fout;//创建一个输出流
	 fout.open("Date.txt");
	 if(!fout)
	 {
	 	cout<<endl<<"文件打开失败";
	 	return ;
	 }
	 else
	 {
	 	int cnt=0;
	 	for(knot *p=head->next;p!=NULL;p=p->next)
	 	{
	 		fout<<(p->date)[0]<<'.'<<setw(2)<<setfill('0')<<(p->date)[1]<<'.'<<setw(2)<<setfill('0')<<(p->date)[2]<<"           ";
			if((++cnt)%5==0)
			{
				fout<<endl;
			}
		}
		cout<<endl<<cnt<<"个日期已经写入文件\"Date.txt\""<<endl;
	 }
}

void Date_Linklist::Inser_Knot()//添加结点
{
	//为生成今天日期
	time_t t;
    struct tm *lt;
    time (&t);//获取时间戳
    lt = localtime (&t);//转为时间结构
    knot *p,*pre,*ppp,*x;
    //在链头增加
	p=new knot;
	Is_New_Success(p);  //分配空间是否成功
    (p->date)[0]=lt->tm_year+1900,(p->date)[1]=lt->tm_mon+1,(p->date)[2]=lt->tm_mday;
	p->next=head->next;
	head->next=p;
	knot_cnt++;
	
	//在链尾添加
	p=new knot;       //重新分配空间
	Is_New_Success(p);  //分配空间是否成功
    (p->date)[0]=lt->tm_year+1900,(p->date)[1]=lt->tm_mon+1,(p->date)[2]=lt->tm_mday;//新分配一个空间
    for(x=head;x->next!=NULL;x=x->next);   //遍历到链尾
	x->next=p;
	p->next=NULL;
	knot_cnt++;
	
	//在结点前插入结点
	srand(time(0));
	int random=rand()%knot_cnt;   //随机生成一个插入点
	p=new knot;
	 Is_New_Success(p);  //分配空间是否成功
    (p->date)[0]=lt->tm_year+1900,(p->date)[1]=lt->tm_mon+1,(p->date)[2]=lt->tm_mday;//新分配一个空间
	int i=0;
	for(i=0,pre=head,ppp=head->next;i<random;i++,pre=ppp,ppp=ppp->next); //遍历到指定插入位置
	pre->next=p,p->next=ppp;
	knot_cnt++;
	
	//在结点后添加
	p=new knot;
	Is_New_Success(p);  //分配空间是否成功
	(p->date)[0]=lt->tm_year+1900,(p->date)[1]=lt->tm_mon+1,(p->date)[2]=lt->tm_mday;//新分配一个空间
	srand(time(0));
	random=rand()%knot_cnt;   //随机生成一个插入点
	for(i=0,ppp=head;i<random;i++,ppp=ppp->next); //遍历到指定插入位置
	p->next=ppp->next,ppp->next=p;
	knot_cnt++;
	cout<<endl<<"分别在链头，链尾以及任意结点前后插入今天日期。"<<endl;
	
	
}

















