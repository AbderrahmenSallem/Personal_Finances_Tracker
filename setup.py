from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import os
import pybind11

# Absolute paths
this_dir = os.path.abspath(os.path.dirname(__file__))

include_dirs = [
    pybind11.get_include(),
    os.path.join(this_dir, "FinanceManagementLibrary")
]

library_dirs = [
    os.path.join(this_dir, "Release")
]

extra_objects = [
    os.path.join(this_dir, "./x64/Release", "FinanceManagementLibrary.lib")
]

ext_modules = [
    Extension(
        "finance_module",                         # this becomes finance_module.pyd
        ["./FinanceManagementLibrary/bindings.cpp"],
        include_dirs=include_dirs,
        library_dirs=library_dirs,
        extra_objects=extra_objects,
        libraries=["./x64/Release/FinanceManagementLibrary"],  # .lib file name without extension
        language="c++",
    ),
]

setup(
    name="finance_module",
    version="0.1",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
)
