// Copyright (c) 2015-2017 Michael Eastwood
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "util.hpp"

template <typename T> T getCell_scalar(Table *t, char const *name, uint row) {
  ScalarColumn<T> column(*t, name);
  return column(row);
}

template <typename T>
void putCell_scalar(Table *t, char const *name, uint row, T input) {
  ScalarColumn<T> column(*t, name);
  column.put(row, input);
}

template <typename T, typename R>
R *getCell_array(Table *t, char const *name, uint row) {
  ArrayColumn<T> column(*t, name);
  Array<T> array = column(row);
  return output_array(array);
}

template <typename T> T *getCell_array(Table *t, char const *name, uint row) {
  return getCell_array<T, T>(t, name, row);
}

template <typename T, typename R>
void putCell_array(Table *t, char const *name, uint row, R *input,
                   int const *dims, int ndim) {
  ArrayColumn<T> column(*t, name);
  auto array = input_array(input, dims, ndim);
  column.put(row, *array);
}

template <typename T>
void putCell_array(Table *t, char const *name, uint row, T *input,
                   int const *dims, int ndim) {
  putCell_array<T, T>(t, name, row, input, dims, ndim);
}

extern "C" {
bool get_cell_scalar_boolean(Table *t, char *name, uint row) {
  return getCell_scalar<Bool>(t, name, row);
}
int get_cell_scalar_int(Table *t, char *name, uint row) {
  return getCell_scalar<Int>(t, name, row);
}
float get_cell_scalar_float(Table *t, char *name, uint row) {
  return getCell_scalar<Float>(t, name, row);
}
double get_cell_scalar_double(Table *t, char *name, uint row) {
  return getCell_scalar<Double>(t, name, row);
}
// std::complex is layout-compatible with C complex and therefore Julia's
// complex
float _Complex get_cell_scalar_complex(Table *t, char *name, uint row) {
  return to_c_cmplx(getCell_scalar<Complex>(t, name, row));
}
double _Complex get_cell_scalar_double_complex(Table *t, char *name, uint row) {
  return to_c_double_cmplx(getCell_scalar<DComplex>(t, name, row));
}
char *get_cell_scalar_string(Table *t, char *name, uint row) {
  ScalarColumn<String> column(*t, name);
  return output_string(column(row));
}

void put_cell_scalar_boolean(Table *t, char *name, uint row, bool input) {
  putCell_scalar(t, name, row, input);
}
void put_cell_scalar_int(Table *t, char *name, uint row, int input) {
  putCell_scalar(t, name, row, input);
}
void put_cell_scalar_float(Table *t, char *name, uint row, float input) {
  putCell_scalar(t, name, row, input);
}
void put_cell_scalar_double(Table *t, char *name, uint row, double input) {
  putCell_scalar(t, name, row, input);
}
void put_cell_scalar_complex(Table *t, char *name, uint row,
                             float _Complex input) {
  putCell_scalar(t, name, row, from_c_cmplx(input));
}
void put_cell_scalar_double_complex(Table *t, char *name, uint row,
                                    double _Complex input) {
  putCell_scalar(t, name, row, from_c_double_cmplx(input));
}
void put_cell_scalar_string(Table *t, char *name, uint row, char *input) {
  putCell_scalar(t, name, row, String(input));
}

bool *get_cell_array_boolean(Table *t, char *name, uint row) {
  return getCell_array<Bool>(t, name, row);
}
int *get_cell_array_int(Table *t, char *name, uint row) {
  return getCell_array<Int>(t, name, row);
}
float *get_cell_array_float(Table *t, char *name, uint row) {
  return getCell_array<Float>(t, name, row);
}
double *get_cell_array_double(Table *t, char *name, uint row) {
  return getCell_array<Double>(t, name, row);
}
float _Complex *get_cell_array_complex(Table *t, char *name, uint row) {
  return to_c_cmplx_arr(getCell_array<Complex>(t, name, row));
}
double _Complex *get_cell_array_double_complex(Table *t, char *name, uint row) {
  return to_c_double_cmplx_arr(getCell_array<DComplex>(t, name, row));
}
char **get_cell_array_string(Table *t, char *name, uint row) {
  return getCell_array<String, char *>(t, name, row);
}

void put_cell_array_boolean(Table *t, char *name, uint row, bool *input,
                            int *dims, int ndim) {
  return putCell_array(t, name, row, input, dims, ndim);
}
void put_cell_array_int(Table *t, char *name, uint row, int *input, int *dims,
                        int ndim) {
  return putCell_array(t, name, row, input, dims, ndim);
}
void put_cell_array_float(Table *t, char *name, uint row, float *input,
                          int *dims, int ndim) {
  return putCell_array(t, name, row, input, dims, ndim);
}
void put_cell_array_double(Table *t, char *name, uint row, double *input,
                           int *dims, int ndim) {
  return putCell_array(t, name, row, input, dims, ndim);
}
void put_cell_array_complex(Table *t, char *name, uint row,
                            float _Complex *input, int *dims, int ndim) {
  return putCell_array(t, name, row, from_c_cmplx_arr(input), dims, ndim);
}
void put_cell_array_double_complex(Table *t, char *name, uint row,
                                   double _Complex *input, int *dims,
                                   int ndim) {
  return putCell_array(t, name, row, from_c_double_cmplx_arr(input), dims,
                       ndim);
}
void put_cell_array_string(Table *t, char *name, uint row, char **input,
                           int *dims, int ndim) {
  return putCell_array<String, char *>(t, name, row, input, dims, ndim);
}
}
