#include <iostream>
#include "include/Utilities.h"
int main()
{
	std::string conv_result = "";

	std::string line_utf8 = "";
	std::string line_gbk = "ÀîÏëÄãºÃ";
	int code = 0;
	//int code = Utilities::UTF2GBK(line_utf8, line_gbk, conv_result);
	//if (code != 0)
	//{
	//	//Utilities::log_error("utf8-->gbk:" + conv_result);
	//	//continue;
	//}
	code = Utilities::GbkToUtf8(line_gbk, line_utf8, conv_result);
	if (0 != code)
	{
		std::cout << "a" << std::endl;
	}
	std::cout << "line_utf8:" << line_utf8 << std::endl;
	Utilities::Utf8ToGbk(line_utf8, line_gbk, conv_result);
	std::cout << "line_gbk:" << line_gbk << std::endl;
	Utilities::LogError("lixiang is a good persion");
	return 0;
}