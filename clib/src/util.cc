#include "config_gridfields.h"


#include <string>
#include <iostream>
#include <sstream>
#include "expr.h"
#include "gridfield.h"
#include "tuple.h"
#include "fparser.hh"
#include "GFError.h"
extern "C" {
#include <stdio.h>
#include <stdarg.h>
}

using namespace std;

namespace GF {

string tab(int indent)
{
	string s;
	for (int i = 0; i < indent; i++) {
		s += " ";
	}
	return s;
}

void split(const string &text, const string separators, vector<string> &words)
{
	int n = text.length();
	int start, stop;

	start = text.find_first_not_of(separators);
	while ((start >= 0) && (start < n)) {
		stop = text.find_first_of(separators, start);
		if ((stop < 0) || (stop > n)) stop = n;
		words.push_back(text.substr(start, stop - start));
		start = text.find_first_not_of(separators, stop + 1);
	}
}


std::string myFormatter(const char *fmt, va_list vl){

    stringstream formattedString;
    int i;
    bool isFormatSymbol = false;


    // Step through the list.
    for( i = 0; fmt[i] != '\0'; ++i ) {

       if(isFormatSymbol){

           switch( fmt[i] ) {   // Type to expect.
           case 'i':
           case 'd':
              {
                 int i = va_arg( vl, int );
                 formattedString << i;
                 break;
              }

              case 'f':
              {
                  double f = va_arg( vl, double );
                  formattedString << f;
                  break;
              }

              case 'c':
              {
                  char c = va_arg( vl, int );
                  formattedString << c;
                  break;
              }

              case 's':
              {
                  char *s = va_arg( vl, char * );
                  formattedString << s;
                  break;
              }

              default:
              {
                  break;
              }
           }


           isFormatSymbol = false;
      }
       else if ( fmt[i] == '%' ) {   // Oooh! A format symbol.
           isFormatSymbol = true;
       }
       else {
           formattedString << fmt[i];
       }
    }

    formattedString << endl;

    return formattedString.str();

}




void Fatal(const char *fmt, ...)
{
    va_list vl;
    va_start(vl,fmt);
    string errmsg = "libgridfields: " + myFormatter(fmt,vl);
    va_end( vl );

	GFError gfError(errmsg,GF_INTERNAL_ERROR, "",0);

	throw gfError;

}

void Warning(const char *fmt, ...)
{
#ifndef NDEBUG
    va_list vl;
    va_start(vl,fmt);
    string errmsg = "libgridfields: " + myFormatter(fmt,vl);
    va_end( vl );

	cerr << "Warning: " << errmsg;
#endif
}

bool same(const string &r, const string &s)
{
	return (remove_whitespace(r) == remove_whitespace(s));
}

string remove_whitespace(const string &text)
{
	stringstream ss(text);
	string buf, out;
	while (ss >> buf)
		out += buf;
	return out;
}

} // namespace GF

