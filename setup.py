#!/usr/bin/env python

from distutils.core  import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext
from numpy import get_include
import os.path

BUILD_BASE = os.path.join(
        os.path.expanduser('~'),
        "build")

setup(ext_modules=[Extension(
    "LDC", ['LDC.pyx', 'src/LimbDarkeningParser.cpp', 'src/Utilities.cpp'],
    language="c++",
    include_dirs=[
        'include',
        os.path.join(BUILD_BASE, "include"),
        get_include(),
        ],
    libraries=['sqlitepp', 'sqlite3'],
    library_dirs=[os.path.join(BUILD_BASE, 'lib'), ],), ],
    cmdclass={'build_ext': build_ext, }
    )
