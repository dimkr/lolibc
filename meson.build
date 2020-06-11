project('lolibc', 'c', version: '6.7')

lolibc_srcs = ['strtonum.c', 'reallocarray.c', 'vis.c', 'unvis.c']

lolibc_c_args = []

lolibc_includes = include_directories('include')

cc = meson.get_compiler('c')

if cc.has_function('strlcpy', prefix: '#include <string.h>')
	lolibc_c_args += ['-DHAVE_STRLCPY']
else
	lolibc_srcs += ['strlcpy.c']
endif

if cc.has_function('strlcat', prefix: '#include <string.h>')
	lolibc_c_args += ['-DHAVE_STRLCAT']
else
	lolibc_srcs += ['strlcat.c']
endif

if cc.has_function('issetugid', prefix: '#include <unistd.h>')
	lolibc_c_args += ['-DHAVE_ISSETUGID']
else
	if cc.has_header('sys/auxv.h')
		lolibc_c_args += ['-DHAVE_SYS_AUXV_H']
	endif
endif

if cc.has_header('sys/cdefs.h')
	lolibc_c_args += ['-DHAVE_SYS_CDEFS_H']
endif

if cc.has_header_symbol('signal.h', 'sys_siglist')
	lolibc_c_args += ['-DHAVE_SYS_SIGLIST']
else
	lolibc_srcs += ['strsignals.c']
endif

if cc.has_header_symbol('signal.h', 'sys_signame')
	lolibc_c_args += ['-DHAVE_SYS_SIGNAME']
else
	sys_signame_h = custom_target('sys_signame_h',
	                              input: 'sys_signame.sh',
	                              output: 'sys_signame.h',
	                              command: ['@INPUT@', '@OUTPUT@'])
	lolibc_srcs += [sys_signame_h, 'sys_signame.c']
endif

liblolibc = static_library('lolibc',
                           lolibc_srcs,
                           c_args: lolibc_c_args,
                           include_directories: lolibc_includes)
