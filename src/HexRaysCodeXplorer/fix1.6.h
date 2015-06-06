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

#include <string.h>
#include <stdarg.h>
#include <tchar.h>


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

inline void f_get_func_name2(qstring* name, ea_t addr) {
	char buff[MAXSTR];
	get_func_name(addr, buff, (MAXSTR - 1));
	*name = qstring(buff);
}

inline qstring f_get_struc_name(tid_t struct_tyle_id) {
	char buff[MAXSTR];
	get_struc_name(struct_tyle_id, buff, (MAXSTR - 1));
	return qstring(buff);
}
#endif
