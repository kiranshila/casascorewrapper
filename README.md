# casacorewrapper

This library provides a shared library to act as a wrapper around
[casacore](https://github.com/casacore/casacore) to provide for easy interop in
Julia with CasaCore.jl.

The original wrapper code is from Michael Eastwood
[here](https://github.com/mweastwood/CasaCore.jl), where this release has been
modified to work with BinaryBuilder, alleviating the constraint that CasaCore.jl
users needed a working C++ compiler. Additionally, there are slight
modifications to allow compat with casacore v3.4.0.