#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "MySerialPort.h"
#define ACTION_QUEUE_NUM 20 //20个动作一组
#define MAX_ACTION_NUM 50 //每组数据20字节
void push(char receive);
void write_temp();

char temp[ACTION_QUEUE_NUM][MAX_ACTION_NUM];//最近动作序列
int action_group = 0;
int action_num = 0;
ofstream file("output.txt");//打开文件


int main(int argc,char *argv[])
{
	jeff_class::CMySerialPort obj;
	
	if (false == obj.Open(3,9600))//打开COM3，频率9600
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

				//输出
				cout << receive;
				if(receive == ' '){
					cout<<endl;
				}
				//响应事件
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

//循环二维数组，返回某行
char* circle_pick_row(char** temp,int row){
	char a[MAX_ACTION_NUM];
	for( int j = 0;j++;j<MAX_ACTION_NUM){
		a[j] = temp[row][j];
	}
	return a;
}

//把当前temp写入文件
void write_temp(){
	for(int i = -ACTION_QUEUE_NUM;i++ ;i<0){
		file<< temp[(action_group+i-1) % ACTION_QUEUE_NUM]<<endl;
	}
}

//不断循环添加到temp数组中
void push(char receive){
		temp[action_group % ACTION_QUEUE_NUM][action_num] = receive;
		action_num++;
		if(receive == ' '){
			temp[action_group % ACTION_QUEUE_NUM][action_num] = '\0';
			action_group ++;
			action_num = 0;
		}
		//输出
		if(action_group % ACTION_QUEUE_NUM == 1 & action_num == 0){
			int i = 0;
			while(i<ACTION_QUEUE_NUM){
				i++;
			}
		}
}

//打印数组
void print_chars(char** temp){
	
}