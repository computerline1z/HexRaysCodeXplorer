/*	Copyright (c) 2013-2016
REhints <info@rehints.com>
All rights reserved.

==============================================================================

This file is part of HexRaysCodeXplorer

HexRaysCodeXplorer is free software: you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see
<http://www.gnu.org/licenses/>.

==============================================================================
*/

/// This file fix some missing function in 1.6 version support for ida 6.6 sdk

#ifndef _FIX1_6_HPP
#define _FIX1_6_HPP
#include <ida.hpp>
#include <idp.hpp>
#include <bytes.hpp>
#include <xref.hpp>
#include <name.hpp>
#include <funcs.hpp>
#include <segment.hpp>
#include <struct.hpp>
#include <loader.hpp>
#include <search.hpp>
#include <pro.h>
#include <string.h>
#include <stdarg.h>
#include <tchar.h>

#if IDA_SDK_VERSION <= 660
inline void f_get_ea_name(qstring* name, ea_t addr) {
	char buff[MAXSTR];
	get_name(BADADDR, addr, buff, (MAXSTR - 1));
	*name = qstring(buff);
}

inline qstring f_get_short_name(ea_t addr) {
	char buff[MAXSTR];
	get_short_name(BADADDR, addr, buff, (MAXSTR - 1));
	return qstring(buff);
}

inline int f_get_func_name2(qstring* name, ea_t addr) {
	char buff[MAXSTR];
	get_func_name(addr, buff, (MAXSTR - 1));
	*name = qstring(buff);
	if (qstring(buff).length() > 0) return qstring(buff).length();
	return 0;
}

inline qstring f_get_struc_name(tid_t struct_tyle_id) {
	char buff[MAXSTR];
	get_struc_name(struct_tyle_id, buff, (MAXSTR - 1));
	return qstring(buff);
}

inline qstring f_get_member_name2(tid_t mid) {
	char buff[MAXSTR];
	get_member_name(mid, buff, (MAXSTR - 1));
	return qstring(buff);
}
#endif
#endif
