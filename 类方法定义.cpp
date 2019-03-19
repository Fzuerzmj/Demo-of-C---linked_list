Date_Linklist::~Date_Linklist()
{
	Knot *save,*p;
	for(p=head,save=head;p!=NULL;p=save)
	{
		save=p->next;
		delete p;
	}
}

Date_Linklist::Date_Linklist(){                     //Ĭ�Ϲ��캯��
	max_cnt=5000;
	knot_cnt=0;
	head=new Knot;    //Ϊͷ�ڵ�����ڴ�
	Is_New_Success(head);  //������ռ��Ƿ�ɹ�
	head->next=NULL;
}

void Date_Linklist::Add_Date(int cnt=5000)
{
	Knot *p;
	srand(time(0));
	for(int i=0;i<cnt;i++)
	{
		  p=new Knot;
		  Is_New_Success(p);          //���ռ�����Ƿ�ɹ�
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
		cout<<p->date[0]<<'.'<<setw(2)<<setfill('0')<<p->date[1]<<'.'<<setw(2)<<setfill('0')<<p->date[2]<<"       ";  //�����ͳһ��ʽ
		if(i==6)         //ÿ 7��һ��
		{
			cout<<endl;
			i-=7;
		}
	}
	cout<<endl;
}

int Date_Linklist::Day_To_200011()               //����ڵ����ڵ�2000.1.1�յ�����
{
	Knot *p;
	int i=1;
	cout<<endl<<"�����д洢�����ڵ�2000��1��1������Ϊ��"<<endl;
	for(p=head->next;p!=NULL&&i<21;p=p->next,i++)
	{
		  int day_cnt=Day_Of_Year(p->date)+Day_To_2000((p->date)[0]);
		  cout<<setw(5)<<day_cnt<<"             ";
		  if(i%4==0)
			cout<<endl;
	}
	int show_day;//��ӡ�˶��ٸ�����
	show_day=knot_cnt<20?knot_cnt:20;
	cout<<endl<<"Ϊ���ӡ��ǰ"<<show_day<<"������"<<endl;
}

void Date_Linklist::Ile_Out()  //U:��ʾ�����еĲ��Ϸ�����
{
	int cnt=0; //��ʶʲôʱ��Ӧ�ûس���
	for(Knot *p=head->next;p!=NULL;p=p->next)
	{
		if(!Is_Legal(p->date))
		{
  			cout<<p->date[0]<<'.'<<setw(2)<<setfill('0')<<p->date[1]<<'.'<<setw(2)<<setfill('0')<<p->date[2]<<"       ";  //�����ͳһ��ʽ
  			cnt++;
  			if(cnt%5==0)
				cout<<endl;
		}
	}
	cout<<"�ҵ�"<<cnt<<"���Ƿ�����"<<endl;
}

void Date_Linklist::Delete_Knot()//D:ɾ�������һ�������һ��,�Ϸ�����
{
	int delete_cnt=0;//��¼ɾ�����ܸ�����
	Knot *pre;
	Knot *p=head->next;
	head->next=p->next;
	delete p;//�ͷſռ�
	delete_cnt++;
	cout<<endl<<"��һ�����ڽ����ɾ����"<<endl;   //ɾ����һ�����
	knot_cnt--;
	for(pre=head,p=head->next;p!=NULL;)
	{
		if(!Is_Legal(p->date))
		{
			pre->next=p->next;
			delete p;   //�ͷſռ�
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
	cout<<"�Ƿ����ڽ����ɾ����"<<endl;
	for(pre=head,p=head->next;p->next!=NULL;pre=p,p=p->next);
	pre->next=NULL;
	delete p;
	knot_cnt--;
	delete_cnt++;
	cout<<"���һ�����ڽ�����ͷš�"<<endl;
	cout<<"��ɾ��"<<delete_cnt<<"����㡣"<<"���в��Ϸ����"<<delete_cnt-2<<"��"<<endl;
}

void Date_Linklist::Find_Prime() //F:���������С��ꡢ�¡��ա���������������
{
	cout<<endl<<"�����վ�Ϊ�������������£�"<<endl;
	Knot *p;
	int cnt=0;
	for(p=head->next;p!=NULL;p=p->next)
	{
		if(Is_Prime(p->date[2])&&Is_Prime(p->date[1])&&Is_Prime(p->date[0]))
		{
			cout<<p->date[0]<<'.'<<setw(2)<<setfill('0')<<p->date[1]<<'.'<<setw(2)<<setfill('0')<<p->date[2]<<"       ";  //�����ͳһ��ʽ
			cnt++;
			if(cnt%5==0)
				cout<<endl;
		}
	}
	cout<<endl;
}

void Date_Linklist::Sort_Linklist_Btos()//P:������������
{
	Knot *temp=NULL;//����ʱʹ��
	Knot *p1,*p2,*pre1,*pre2;
	cout<<endl<<"������..........."<<endl;
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
	cout<<"��������ڴ�ǰ��������"<<endl;
	
}

void Date_Linklist::Reverse_Linklist()//R:����ת����
{
	 knot *pre,*p;
	 for(pre=head->next,p=pre->next;p!=NULL;)
	 {
	 	pre->next=p->next;
	 	p->next=head->next;
	 	head->next=p;
	 	p=pre->next;
	 }
	 cout<<endl<<"����ת��ɡ�"<<endl;
}

void Date_Linklist::SaveToFile()//����Sʵ�֣����ڵ�����ݴ����ļ�����
{
	 ofstream fout;//����һ�������
	 fout.open("Date.txt");
	 if(!fout)
	 {
	 	cout<<endl<<"�ļ���ʧ��";
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
		cout<<endl<<cnt<<"�������Ѿ�д���ļ�\"Date.txt\""<<endl;
	 }
}

void Date_Linklist::Inser_Knot()//��ӽ��
{
	//Ϊ���ɽ�������
	time_t t;
    struct tm *lt;
    time (&t);//��ȡʱ���
    lt = localtime (&t);//תΪʱ��ṹ
    knot *p,*pre,*ppp,*x;
    //����ͷ����
	p=new knot;
	Is_New_Success(p);  //����ռ��Ƿ�ɹ�
    (p->date)[0]=lt->tm_year+1900,(p->date)[1]=lt->tm_mon+1,(p->date)[2]=lt->tm_mday;
	p->next=head->next;
	head->next=p;
	knot_cnt++;
	
	//����β���
	p=new knot;       //���·���ռ�
	Is_New_Success(p);  //����ռ��Ƿ�ɹ�
    (p->date)[0]=lt->tm_year+1900,(p->date)[1]=lt->tm_mon+1,(p->date)[2]=lt->tm_mday;//�·���һ���ռ�
    for(x=head;x->next!=NULL;x=x->next);   //��������β
	x->next=p;
	p->next=NULL;
	knot_cnt++;
	
	//�ڽ��ǰ������
	srand(time(0));
	int random=rand()%knot_cnt;   //�������һ�������
	p=new knot;
	 Is_New_Success(p);  //����ռ��Ƿ�ɹ�
    (p->date)[0]=lt->tm_year+1900,(p->date)[1]=lt->tm_mon+1,(p->date)[2]=lt->tm_mday;//�·���һ���ռ�
	int i=0;
	for(i=0,pre=head,ppp=head->next;i<random;i++,pre=ppp,ppp=ppp->next); //������ָ������λ��
	pre->next=p,p->next=ppp;
	knot_cnt++;
	
	//�ڽ������
	p=new knot;
	Is_New_Success(p);  //����ռ��Ƿ�ɹ�
	(p->date)[0]=lt->tm_year+1900,(p->date)[1]=lt->tm_mon+1,(p->date)[2]=lt->tm_mday;//�·���һ���ռ�
	srand(time(0));
	random=rand()%knot_cnt;   //�������һ�������
	for(i=0,ppp=head;i<random;i++,ppp=ppp->next); //������ָ������λ��
	p->next=ppp->next,ppp->next=p;
	knot_cnt++;
	cout<<endl<<"�ֱ�����ͷ����β�Լ�������ǰ�����������ڡ�"<<endl;
	
	
}

















