#include "����demo.h"
#include "�෽������.cpp"
#include "��ͨ��������.cpp"
int main()
{
	
	cout<<"��Ȩ���У�֣ï��<ѧ��:221801222>"<<endl;
	Put_Time();
	Menu();                                                                             //��ʾ�˵�
	Date_Linklist demo;                                                                 //����Date_Linklistʵ������
	char ch;
	while(ch=toupper(ch=getch()))
	{
		cout<<ch;
		switch(ch)
		{
			case'C':
				Creat_Knot(&demo);      //�������
				Menu();
				break;
			case'I':
				demo.Inser_Knot();
				Menu();
				break;
			case'O':
				Outshow_Knot(&demo);         //��ʾ���
				Menu();
				break;
            case'T':                         //��ʾ��㵽2000.1.1����
            	demo.Date_Linklist::Day_To_200011();
            	Menu();
            	break;
			case'Q':
				cout<<ch<<endl<<"�����˳�����лʹ�ñ�ϵͳ��"<<endl;
				exit(0);
				break;
			case'U':
				cout<<"���洢�����в��Ϸ��������£�"<<endl;
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
				cout<<endl<<"�����������������롣"<<endl;
				break;
				
		}
    }
}








