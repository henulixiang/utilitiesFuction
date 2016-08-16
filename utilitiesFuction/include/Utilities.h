#ifndef UTILITIESFUNCITON_UTILITIES_H_
#define UTILITIESFUNCITON_UTILITIES_H_

#include <string>
#include <iconv.h>

class Utilities
{
public:
	//���ر���ʱ�䣬ʱ���ʽ��
	static std::string CurrentTimeString();
	//��time_formate��ʽ���ر���ʱ��
	static std::string CurrentTimeString(const char *time_formate);
	static void LogInfo(const std::string & message);
	static void LogWarning(const std::string & message);
	static void LogError(const std::string & message);
	//��gbk�ַ���ת��utf8������ַ���
	//input��gbk�����ַ���
	//output��utf8�����ַ���
	//convert_result��ת����������ڴ�ӡ������Ϣ
	//return��0���ɹ������㣺ʧ��
	static int GbkToUtf8(std::string & input, std::string & output, std::string & convert_result);
	//��utf8�����ַ���ת��gbk������ַ���
	//input��utf8�����ַ���
	//output��gbk�����ַ���
	//convert_result��ת����������ڴ�ӡ������Ϣ
	//return��0���ɹ������㣺ʧ��
	static int Utf8ToGbk(std::string & input, std::string & output, std::string & convert_result);
	Utilities();
	~Utilities();
private:

	static int EncodingConvert(std::string & input, std::string & output, std::string & convert_result, iconv_t conv);
};

#endif // UTILITIESFUNCITON_UTILITIES_H_



