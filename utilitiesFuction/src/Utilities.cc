#include "../include/Utilities.h"
#include <algorithm>
#include <time.h>
#include <cstring>
#include <string>
#include <errno.h>

#define G_MAX_CONVERT_LEN 102400


int Utilities::GBK2UTF(std::string & strSrc, std::string & strDst, std::string & strRes)
{
	iconv_t conv_gbk_2_utf = iconv_open("UTF-8", "GBK");
	int code = encoding_convert(strSrc, strDst, strRes, conv_gbk_2_utf);
	return code;
}

int Utilities::UTF2GBK(std::string & strSrc, std::string & strDst, std::string & strRes)
{
	iconv_t conv_utf_2_gbk = iconv_open("GBK", "UTF-8");
	int code = encoding_convert(strSrc, strDst, strRes, conv_utf_2_gbk);
	return code;
}

Utilities::Utilities()
{
}


Utilities::~Utilities()
{
}

int Utilities::encoding_convert(std::string & strSrc, std::string & strDst, std::string & strResult, iconv_t conv)
{
	char strOutput[G_MAX_CONVERT_LEN];
	memset(strOutput, 0, sizeof(strOutput));
	//iconv_t conv_utf_2_gbk = iconv_open("GBK", "UTF-8");
	size_t iSrcLen = strSrc.size();
	size_t iDstLen = G_MAX_CONVERT_LEN;
	if (iSrcLen > G_MAX_CONVERT_LEN)
		iSrcLen = G_MAX_CONVERT_LEN;

	char *inBuf = const_cast<char *>(strSrc.c_str());
	//*(inBuf+strSrc.size()) = 0;
	char *outBuf = strOutput;
	int iRet = iconv(conv, &inBuf, &iSrcLen, &outBuf, &iDstLen);
	if (-1 == iRet)
	{
		strResult = "<Err>, convert failed, str:";
		strResult += strSrc;
		strResult += ", strerr:";
		strResult += strerror(errno);
		return -1;
	}
	iRet = iconv_close(conv);
	if (-1 == iRet)
	{
		strResult = "<Err>, iconv_close failed, strerr:";
		strResult += strerror(errno);
		return -2;

	}
	strDst = strOutput;
	return 0;
}
