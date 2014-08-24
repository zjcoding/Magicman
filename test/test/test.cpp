#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "MySerialPort.h"
#define ACTION_QUEUE_NUM 20 //20������һ��
#define MAX_ACTION_NUM 50 //ÿ������20�ֽ�
void push(char receive);
void write_temp();

char temp[ACTION_QUEUE_NUM][MAX_ACTION_NUM];//�����������
int action_group = 0;
int action_num = 0;
ofstream file("output.txt");//���ļ�


int main(int argc,char *argv[])
{
	jeff_class::CMySerialPort obj;
	
	if (false == obj.Open(3,9600))//��COM3��Ƶ��9600
	{
		cout << "open SerialPort is failed !" << endl;
	}
	
	int val = 0;
	char receive = NULL;

	if(!file)return 0;

	while (true)
	{
		//cin>>val;
		//cin.get();

		if (obj.IsOpened())
		{
			//obj.SendData((char*)&val,sizeof(val));
			if(obj.ReadDataWaiting()){
				obj.ReadData(&receive,1);

				//���
				cout << receive;
				if(receive == ' '){
					cout<<endl;
				}
				//��Ӧ�¼�
				if(receive == 'a'){
					write_temp();
					action_num --;
					file<< "-----------"<<endl;
				}
				push(receive);
				
				Sleep(2);
			}
		}


		else{
			cout << "SerialPort is not opened !" << endl;
		}
		if ( val == 726){
			break;
		}
	}
	

	obj.Close();
	return 0;
}

//ѭ����ά���飬����ĳ��
char* circle_pick_row(char** temp,int row){
	char a[MAX_ACTION_NUM];
	for( int j = 0;j++;j<MAX_ACTION_NUM){
		a[j] = temp[row][j];
	}
	return a;
}

//�ѵ�ǰtempд���ļ�
void write_temp(){
	for(int i = -ACTION_QUEUE_NUM;i++ ;i<0){
		file<< temp[(action_group+i-1) % ACTION_QUEUE_NUM]<<endl;
	}
}

//����ѭ����ӵ�temp������
void push(char receive){
		temp[action_group % ACTION_QUEUE_NUM][action_num] = receive;
		action_num++;
		if(receive == ' '){
			temp[action_group % ACTION_QUEUE_NUM][action_num] = '\0';
			action_group ++;
			action_num = 0;
		}
		//���
		if(action_group % ACTION_QUEUE_NUM == 1 & action_num == 0){
			int i = 0;
			while(i<ACTION_QUEUE_NUM){
				i++;
			}
		}
}

//��ӡ����
void print_chars(char** temp){
	
}