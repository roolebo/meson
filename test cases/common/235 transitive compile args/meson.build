project('Transitive flags', 'c')
ssmod = import('sourceset')
config = {}

foo = declare_dependency(compile_args: '-DFOO=BAR')

foobar_ss = ssmod.source_set()
subdir('foobar')
foobar_ss = foobar_ss.apply(config)
libfoobar = static_library('foobar', foobar_ss.sources(),
                           dependencies: [foobar_ss.dependencies()])
foobar = declare_dependency(link_whole: libfoobar)

executable('prog', sources: files('prog.c'), dependencies: foobar)
