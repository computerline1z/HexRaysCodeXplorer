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

#include "Common.h"
#include "Rtti.h"
#include "Debug.h"

//---------------------------------------------------------------------------
// RTTI code parsing 
// (simple code init in v1.1 will be redevelop in the following versions)
//---------------------------------------------------------------------------

qvector <qstring> rtti_list;
qvector <ea_t> rtti_addr;

// Find RTTI objects by signature
ea_t find_RTTI(ea_t start_ea, ea_t end_ea)
{
	// "2E 3F 41 56" == .?AV
	return find_binary(start_ea, end_ea, "2E 3F 41 56", getDefaultRadix(), SEARCH_DOWN);
}


// Demangle C++ class name
char* get_demangle_name(ea_t class_addr)
{
	char buf_name[MAXSTR];
	int name_size = get_max_ascii_length(class_addr, ASCSTR_TERMCHR, true);
	get_ascii_contents(class_addr, name_size, ASCSTR_TERMCHR, buf_name, sizeof(buf_name));
	return qstrdup(buf_name);
}



void process_rtti()
{
	rtti_addr.clear();
	rtti_list.clear();
	ea_t start = getnseg(0)->startEA;

	while (TRUE)
	{
		ea_t rt = find_RTTI(start, inf.maxEA);
		start = rt + 4;

		if (rt == BADADDR)
			break;

		char* name = get_demangle_name(rt);

		ea_t rtd = rt - 8;

		rtti_addr.push_back(rtd);

		qstring tmp;
#ifndef __EA64__
		tmp.cat_sprnt(" 0x%x:  %s", rtd, name);
#else
		tmp.cat_sprnt(_T(" 0x%I64X:  %s"), rtd, name);
#endif

		rtti_list.push_back(tmp);
	}
}





