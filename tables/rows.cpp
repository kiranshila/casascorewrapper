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

extern "C" {
uint num_rows(Table *t) { return t->nrow(); }

void add_rows(Table *t, uint number) {
  t->addRow(number, true); // always initialize the new rows
}

void remove_rows(Table *t, uint *row_numbers, size_t length) {
  // New interface is to pass in const RowNumbers&, which can come from vectors
  std::vector<rownr_t> rows(row_numbers, row_numbers + length);
  t->removeRow(rows);
}
}