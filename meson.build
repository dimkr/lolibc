project('lolibc', 'c')

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

liblolibc = static_library('lolibc',
                           lolibc_srcs,
                           c_args: lolibc_c_args,
                           include_directories: lolibc_includes)
