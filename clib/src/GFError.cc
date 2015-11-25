// GFError.cc

// This file is part of bes, A C++ back-end server implementation framework
// for the OPeNDAP Data Access Protocol.

// Copyright (c) 2015 OPeNDAP, Inc.
// Author: Nathan Potter <ndp@opendap.org>
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// You can contact OPeNDAP, Inc. at PO Box 112, Saunderstown, RI. 02874-0112.


#include "GFError.h"

#include <sstream>

/** @brief dumps information about this object
 *
 * Displays the pointer value of this instance along with the exception
 * message, the file from which the exception was generated, and the line
 * number in that file.
 *
 * @param strm C++ i/o stream to dump the information to
 */
void
GFError::dump( std::ostream &strm ) const
{
    std::stringstream s;
    string indent = "    ";

    s  << "GFError::dump - ("  << (void *)this << ")" << std::endl ;

    s << indent << "error message: " << _msg << std::endl ;
    s << indent << "error type: " << _type << std::endl ;
    s << indent << "error file: " << _file << std::endl ;
    s << indent << "error line: " << _line << std::endl ;

    strm << s.str();
}

