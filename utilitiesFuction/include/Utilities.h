#ifndef UTILITIESFUNCITON_UTILITIES_H_
#define UTILITIESFUNCITON_UTILITIES_H_

#include <string>
#include <iconv.h>

class Utilities
{
public:
	static int GBK2UTF(std::string & strSrc, std::string & strDst, std::string & strRes);
	static int UTF2GBK(std::string & strSrc, std::string & strDst, std::string & strRes);
	Utilities();
	~Utilities();
private:
	static int encoding_convert(std::string &strSrc, std::string &strDst, std::string &strResult, iconv_t conv);
};

#endif // !1



