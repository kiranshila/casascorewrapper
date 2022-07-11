# casacorewrapper

This library provides a shared library to act as a wrapper around [casacore](https://github.com/casacore/casacore) for easy interop in
Julia with CasaCore.jl.

The original wrapper code is by Michael Eastwood
[here](https://github.com/mweastwood/CasaCore.jl), where this release has been
modified to work with BinaryBuilder, alleviating the constraint that CasaCore.jl
users needed a working C++ compiler. Additionally, there are slight
modifications to allow compat with casacore v3.5.0.

In the future, this should be replaced with a CxxWrap.jl-based wrapper as to more 
closely match the casacore-python Boost::Python interface.