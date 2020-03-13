#include <iostream>
#include <fstream>
#include <sstream>
#include <locale>
#include <codecvt>
#include "lex_parse.h"
int main(int argc, char const *argv[])
{
    if(argc < 3)
    {
        std::wcout << L"Usage: " << argv[0] << L" <infile> <outfile>\n";
        return 1;
    }
    // read file
    std::ifstream in_stream;
    in_stream.open(argv[1]);
    // convert stream into string
    if (in_stream.fail()) {
		std::wstringstream ss;
		std::wcerr << L"Fail to load \"" << argv[1] << L"\"." << std::endl;
		return 1;
	}
	// UTF-8 decode
	std::istreambuf_iterator<char> begin(in_stream), end;
	std::wstring_convert<std::codecvt_utf8<wchar_t>> cvt;
	std::wstring str;
	try {
		std::string bytes(begin, end);
		str = cvt.from_bytes(bytes);
	}
	catch (std::range_error re) {
		std::wcerr << L"Can only open UTF-8 file!" << std::endl;
		return 1;
	}
    // parse
    std::wostringstream wos;

    auto &&scanned = scanner(str);
   
	parse_fromlex(wos, std::begin(scanned), std::end(scanned));
    // output to file
	std::ofstream f(argv[2]);
	
	f << "<!DOCTYPE><html><head><meta charset=\"utf-8\"/></head><body>";
	f << cvt.to_bytes(wos.str());
	// add mathjax
	f << "<script type=\"text/x-mathjax-config\">MathJax.Hub.Config({TeX:{equationNumbers:{autoNumber:\"AMS\"}},tex2jax:{inlineMath:[['$','$'],['\\\\(','\\\\)']]}});</script><script type=\"text/javascript\" src=\"https://cdn.bootcss.com/mathjax/2.7.5/MathJax.js?config=default\"></script>";
	// add suffix
	f << "</body></html>";
	f.close();
	return 0;
}
