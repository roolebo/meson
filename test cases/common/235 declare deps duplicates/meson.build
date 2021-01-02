project('A chain of wholly linked static libraries', 'c')
# The full dependency chains is:
# prog -> b (static lib) -> a (static lib) -> header only lib
ssmod = import('sourceset')
config = {}

# Mimic an external dependency
subdir('include')
header_dep = declare_dependency(compile_args: '-I' + dep_dir)

a_ss = ssmod.source_set()
subdir('subsystem-a')
a_ss = a_ss.apply(config)

liba = static_library('a', a_ss.sources(),
                      dependencies: a_ss.dependencies())
a = declare_dependency(link_whole: liba,
                       include_directories: a_inc,
                       dependencies: a_ss.dependencies())


b_ss = ssmod.source_set()
subdir('subsystem-b')
b_ss = b_ss.apply(config)

libb = static_library('b', b_ss.sources(),
                      dependencies: b_ss.dependencies())
b = declare_dependency(link_whole: libb,
                       include_directories: b_inc,
                       dependencies: b_ss.dependencies())

executable('prog', sources: files('prog.c'), dependencies: b)
