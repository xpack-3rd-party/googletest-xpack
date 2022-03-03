# -----------------------------------------------------------------------------
#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus/)
# Copyright (c) 2022 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# This file is intended to be consumed by applications with:
#
# `subdir('xpacks/xpack-3rd-party-googletest')`
#
# The result is a library that can be refered as:
#
# ```
#  c_args: xpack_3rd_party_googletest_dependency_c_args,
#  cpp_args: xpack_3rd_party_googletest_dependency_cpp_args,
#  dependencies: [ xpack-3rd-party-googletest_dependency ],
#  link_with: [ xpack_3rd_party_googletest_static ],
# ```

# Note: the meson configuration is provided only as a proof of concept,
# for production it might need some refinements.

# -----------------------------------------------------------------------------

message('Processing xPack @xpack-3rd-party/googletest...')

xpack_common_args = []
xpack_c_args = []
xpack_cpp_args = []
xpack_include_directories = []
xpack_sources = []
xpack_compile_definitions = []

xpack_common_args += [
  '-Wno-padded',
  '-Wno-undef',
  '-Wno-missing-noreturn',
  '-Wno-switch-enum',
  '-Wno-switch-default',
  '-Wno-null-dereference',

  '-Wno-psabi',
]

if c_compiler.get_id() == 'gcc'
  xpack_common_args += [
    '-Wno-missing-attributes',
    '-Wno-aggregate-return',
    '-Wno-conversion',
    '-Wno-suggest-final-methods',
    '-Wno-suggest-final-types',
    '-Wno-sign-conversion',
    '-Wno-missing-declarations',
  ]
elif c_compiler.get_id().contains('clang')
  xpack_common_args += [
    '-Wno-c++98-compat',
    '-Wno-c++98-compat-pedantic',
    '-Wno-weak-vtables',
    '-Wno-unused-member-function',
    '-Wno-global-constructors',
    '-Wno-exit-time-destructors',
    '-Wno-covered-switch-default',
    '-Wno-used-but-marked-unused',
    '-Wno-extra-semi-stmt',
    '-Wno-disabled-macro-expansion',
    '-Wno-comma',
    '-Wno-missing-prototypes',
  ]
endif

xpack_cpp_args += [
  '-Wno-zero-as-null-pointer-constant',
  '-Wno-suggest-override',
  '-Wno-ctor-dtor-privacy',
]

if c_compiler.get_id() == 'gcc'
  xpack_cpp_args += [
    '-Wno-useless-cast',
    '-Wno-redundant-tags'
  ]
endif

# Google Test.
xpack_include_directories += [
  'googletest/include',
  'googletest',
]

xpack_sources += [
  'googletest/src/gtest-all.cc',
]

# Google Mock.
xpack_include_directories += [
  'googlemock/include',
  'googlemock',
]

xpack_sources += [
  'googlemock/src/gmock-all.cc',
]

# https://mesonbuild.com/Reference-manual_functions.html#static_library
xpack_3rd_party_googletest_static = static_library(
  'xpack_3rd_party_googletest',

  include_directories: include_directories(xpack_include_directories),
  sources: files(xpack_sources),
  c_args: xpack_common_args + xpack_c_args + xpack_compile_definitions,
  cpp_args: xpack_common_args + xpack_cpp_args + xpack_compile_definitions,
)

foreach name : xpack_include_directories
  message('+ -I ' + name)
endforeach
foreach name : xpack_sources + xpack_common_args + xpack_c_args + xpack_cpp_args
  message('+ ' + name)
endforeach
message('> xpack_3rd_party_googletest_static')

# -----------------------------------------------------------------------------

xpack_include_directories = []
xpack_sources = []

# Google Test.
xpack_include_directories += [
  'googletest/include',
]

# Google Mock.
xpack_include_directories += [
  'googlemock/include',
]

# https://mesonbuild.com/Reference-manual_functions.html#declare_dependency
xpack_3rd_party_googletest_dependency = declare_dependency(
  include_directories: include_directories(xpack_include_directories),
  compile_args: xpack_common_args
)

# Dependencies cannot store language specific definitions, the only
# way is to pass them via global variables. All applications including
# this dependency must also consider them.
xpack_3rd_party_googletest_dependency_c_args = xpack_c_args
xpack_3rd_party_googletest_dependency_cpp_args = xpack_cpp_args

foreach name : xpack_include_directories
  message('+ -I ' + name)
endforeach
foreach name : xpack_sources + xpack_common_args
  message('+ ' + name)
endforeach
message('> xpack_3rd_party_googletest_dependency')

# -----------------------------------------------------------------------------
