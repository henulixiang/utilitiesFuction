#include "../include/Utilities.h"
#include <time.h>
#include <cstring>
#include <errno.h>
#include <iostream>
#include <string>
#include <algorithm>

//编码转换时，字符串的最大长度
const int kMaxConvertLen = 102400;


std::string Utilities::CurrentTimeString()
{
	return CurrentTimeString("%Y-%m-%d.%X");
}

std::string Utilities::CurrentTimeString(const char * time_formate)
{
	time_t now = time(0);
	struct tm * now_struct = localtime(&now);
	char buf[128];
	strftime(buf, sizeof(buf), time_formate, now_struct);
	return buf;
}

void Utilities::LogInfo(const std::string & message)
{
	std::string now = CurrentTimeString();
	std::cout << now << "\tINFO:" << message << std::endl;
}

void Utilities::LogWarning(const std::string & message)
{
	std::string now = CurrentTimeString();
	std::cout << now << "\tWARNING:" << message << std::endl;
}

void Utilities::LogError(const std::string & message)
{
	std::string now = CurrentTimeString();
	std::cout << now << "\tERROR:" << message << std::endl;
}

int Utilities::GbkToUtf8(std::string & input, std::string & output, std::string & convert_result)
{
	iconv_t conv_gbk_2_utf = iconv_open("UTF-8", "GBK");
	int code = EncodingConvert(input, output, convert_result, conv_gbk_2_utf);
	return code;
}

int Utilities::Utf8ToGbk(std::string & input, std::string & output, std::string & convert_result)
{
	iconv_t conv_utf_2_gbk = iconv_open("GBK", "UTF-8");
	int code = EncodingConvert(input, output, convert_result, conv_utf_2_gbk);
	return code;
}

Utilities::Utilities()
{
}


Utilities::~Utilities()
{
}
//编码之间相互转换函数
//convert_result：转换结果，用于打印错误信息
//conv：iconv_open（）的返回值
//return：0：成功，非零：失败
int Utilities::EncodingConvert(std::string & input, std::string & output, std::string & convert_result, iconv_t conv)
{
	char output_arr[kMaxConvertLen];
	memset(output_arr, 0, sizeof(output_arr));

	size_t input_len = input.size();
	size_t output_len = kMaxConvertLen;
	if (input_len > kMaxConvertLen)
		input_len = kMaxConvertLen;

	char *input_buf = const_cast<char *>(input.c_str());

	char *output_buf = output_arr;
	int iRet = iconv(conv, &input_buf, &input_len, &output_buf, &output_len);
	if (-1 == iRet)
	{
		convert_result = "<Err>, convert failed, str:";
		convert_result += input;
		convert_result += ", strerr:";
		convert_result += strerror(errno);
		return -1;
	}
	iRet = iconv_close(conv);
	if (-1 == iRet)
	{
		convert_result = "<Err>, iconv_close failed, strerr:";
		convert_result += strerror(errno);
		return -2;

	}
	output = output_arr;
	return 0;
}
