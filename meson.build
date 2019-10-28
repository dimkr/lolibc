project('lolibc', 'c')

lolibc_c_args = []

lolibc_includes = include_directories('include')

cc = meson.get_compiler('c')

if cc.has_header('sys/auxv.h')
	lolibc_c_args += ['-DHAVE_SYS_AUXV_H']
endif

liblolibc = static_library('lolibc',
                           'strlcat.c', 'strlcpy.c', 'strtonum.c', 'reallocarray.c', 'vis.c', 'unvis.c',
                           c_args: lolibc_c_args,
                           include_directories: lolibc_includes)
