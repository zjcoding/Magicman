#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "MySerialPort.h"


int main(int argc,char *argv[])
{
	jeff_class::CMySerialPort obj;
	
	if (false == obj.Open(3,9600))//打开COM3，频率9600
	{
		cout << "open SerialPort is failed !" << endl;
	}
	
	int val = 0;
	char receive = NULL;

	ofstream file("output.txt");//打开文件
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
				file << receive ;
				//换行
				if(receive == ' '){
					file << "\n";
					cout<<endl;
				}
					
				Sleep(2);
			}
		}


		else
		{
			cout << "SerialPort is not opened !" << endl;
		}

		if ( val == 726)
		{
			break;
		}
	}
	

	obj.Close();
	
	return 0;
}