#include <iostream>

#include <pybind11/embed.h>
namespace py = pybind11;
int main()
{
	py::scoped_interpreter guard{};
	py::module sys = py::module::import("sys");

	py::module calc = py::module::import("calc");
	py::object result = calc.attr("add")(1, 2);
	int n = result.cast <int>();
	py::print(n);
	return 0;
}
