#include <pybind11/pybind11.h>

int64_t collatz(int64_t n) {
    if (n % 2 == 0)
        return n / 2;
    else
        return 3 * n + 1;
}

namespace py = pybind11;

PYBIND11_PLUGIN(pybind11_benchmark) {
    py::module m("pybind11_benchmark");

    m.def("collatz", &collatz,
          "Run one iteration of the mapping underlying the Collatz cojecture");

#ifdef VERSION_INFO
    m.attr("__version__") = py::str(VERSION_INFO);
#else
    m.attr("__version__") = py::str("dev");
#endif

    return m.ptr();
}
