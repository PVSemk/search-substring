#include "pybind11/pybind11.h"
#include "pybind11/stl.h"
#include "../cpp/include/substring_search"

namespace py = pybind11;

PYBIND11_MODULE(substring_search, m){
    m.doc() = "Substring Search Library";
    m.def("brute_force", &bruteForceSearch, "Brute Force approach", py::arg("text"), py::arg("pattern"));
    m.def("karp_rabin", &searchKarpRabin, "Karp Rabin algorithm", py::arg("text"), py::arg("pattern"), py::arg("prime_number"));
    m.def("knuth_morris_pratt", &searchKMP, "Knuth Morris Pratt algorithm", py::arg("text"), py::arg("pattern"));

}

