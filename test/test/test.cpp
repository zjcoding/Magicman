#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "MySerialPort.h"
#define ACTION_QUEUE_NUM 5 //20������һ��
void push(char receive);

char temp[ACTION_QUEUE_NUM][50];//�����������
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

				cout << receive;
				//file << receive ;
				//����
				if(receive == ' '){
				//	file << "\n";
					cout<<endl;
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

//ѭ����ά���飬���������ά����
char* circle_pick(char** temp,int length,int begin){
	return 0;
}

//����ѭ����ӵ�temp������
void push(char receive){
	if(action_group < ACTION_QUEUE_NUM){
					temp[action_group][action_num] = receive;
					action_num++;
					if(receive == ' '){
						temp[action_group][action_num] = '\0';
						action_group ++;
						action_num = 0;
					}
				}else{
					int i = 0;
					while(i<ACTION_QUEUE_NUM){
						cout<<temp[i]<<endl;
						file<<temp[i]<<endl;
						i++;
					}
					action_group =0;
				}
}