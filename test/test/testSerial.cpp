#include "stdafx.h"
#include <iostream>
using namespace std;
#include "MySerialPort.h"

//int main(int argc,char *argv[])
//{
//	jeff_class::CMySerialPort obj;
//	
//	if (false == obj.Open(3,9600))
//	{
//		cout << "open SerialPort is failed !" << endl;
//	}
//	
//	int val = 0;
//
//	while (true)
//	{
//		cin>>val;
//		cin.get();
//
//		if (obj.IsOpened())
//		{
//			obj.SendData((char*)&val,sizeof(val));
//		}
//		else
//		{
//			cout << "SerialPort is not opened !" << endl;
//		}
//
//		if ( val == 726)
//		{
//			break;
//		}
//	}
//	
//
//	obj.Close();
//	
//	return 0;
//}