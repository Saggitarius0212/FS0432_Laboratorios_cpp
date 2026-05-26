from setuptools import setup, Extension
import pybind11

ext_modules = [
	Extension(
	"lorenz_methods",
	sources = ["bindings.cpp", "lorenz_methods.cpp"],
	include_dirs = [pybind11.get_include()],
	language = "c++",
	extra_compile_args = ["-std=c++11"],
	)
]

setup(
	name = "lorenz_methods",
	version = "0.1",
	ext_modules = ext_modules,
)
