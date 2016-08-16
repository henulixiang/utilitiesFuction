#ifndef UTILITIESFUNCITON_UTILITIES_H_
#define UTILITIESFUNCITON_UTILITIES_H_

#include <string>
#include <iconv.h>

class Utilities
{
public:
	//返回本地时间，时间格式：
	static std::string CurrentTimeString();
	//以time_formate格式返回本地时间
	static std::string CurrentTimeString(const char *time_formate);
	static void LogInfo(const std::string & message);
	static void LogWarning(const std::string & message);
	static void LogError(const std::string & message);
	//将gbk字符串转成utf8编码的字符串
	//input：gbk编码字符串
	//output：utf8编码字符串
	//convert_result：转换结果，用于打印错误信息
	//return：0：成功，非零：失败
	static int GbkToUtf8(std::string & input, std::string & output, std::string & convert_result);
	//将utf8编码字符串转成gbk编码的字符串
	//input：utf8编码字符串
	//output：gbk编码字符串
	//convert_result：转换结果，用于打印错误信息
	//return：0：成功，非零：失败
	static int Utf8ToGbk(std::string & input, std::string & output, std::string & convert_result);
	Utilities();
	~Utilities();
private:

	static int EncodingConvert(std::string & input, std::string & output, std::string & convert_result, iconv_t conv);
};

#endif // UTILITIESFUNCITON_UTILITIES_H_



