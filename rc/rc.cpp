// Copyright (c) 2022 Kiran Shila
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

#include <casacore/casa/System/Casarc.h>
using namespace casacore;

// We are going to vendor the measures data in a "nice" way, 
// so we need to be able to dynamically set the rc path to point
// to the directory that we'll provide

extern "C" {
void set_casarc_path(char *path) {
    Casarc::setDefaultPath(path);
}
}
