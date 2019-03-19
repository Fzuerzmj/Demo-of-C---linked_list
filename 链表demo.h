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
		//���������
		void Add_Date(int cnt);
		int Get_Max_Cnt(){return max_cnt;}                   //���������������������ܴ����������
		int Get_Date_Cnt(){return knot_cnt;}                   //������������ǰ�������ڵĸ���
		void Show_Knot(int n=50);
		int Day_To_200011();               //����ڵ����ڵ�2000.1.1�յ�����
		void Ile_Out(); //U:��ʾ�����еĲ��Ϸ�����
		void Delete_Knot();//D:ɾ�������һ�������һ��,�Ϸ�����
		void Find_Prime(); //F:���������С��ꡢ�¡��ա���������������
		void Sort_Linklist_Btos();//P:������������
  		void Reverse_Linklist();//R:����ת����
  		void SaveToFile();//����Sʵ�֣����ڵ�����ݴ����ļ�����
  		void Inser_Knot();//��ӽ��

};


//��ͨ����

void Menu();//��ʾ�˵�
void Put_time();//��ʾϵͳʱ��
bool Is_New_Success(void *p);//�жϿռ�����Ƿ�ɹ�

/////main�����еĿ��ƺ���
void C(Date_Linklist *demo);//����Cʵ��,�������ڽ��
//ʵ������main�к�������ĸ�������
int Day_Of_Year(int *time);  //����һ��������һ��ĵڼ���,�������Ϊ���������յ�����
int Day_To_2000(int year);      //����2000��1.1ָ�����1.1���˶�����
bool Is_Leapyear(int year);       //�Ƿ�Ϊ����
bool Is_Legal(int *time);        //�ж������Ƿ�Ϸ�
bool Is_Prime(int num);         //�ж�����
int Cmp_Date(int *time1,int *time2);//�Ƚ��������ڴ�С���󷵻�һ(��2000.1.1Զ)����֮����0
void X_Ping();// X:������ʾ���������ļ���(ȫ������)





















