project('lolibc', 'c')

lolibc_c_args = ['-D__dead=']

lolibc_includes = include_directories('include')

liblolibc = static_library('lolibc',
                           'strlcat.c', 'strlcpy.c', 'strtonum.c', 'reallocarray.c', 'vis.c', 'unvis.c',
                           c_args: lolibc_c_args,
                           include_directories: lolibc_includes)
