//
// Copyright (C) 2019 Linkworld Open Team
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
// along with this program.  If not, see <https: //www.gnu.org/licenses/>.

#ifndef STREAM_H_
#define STREAM_H_

#include <memory>
#include "./fsm/fsm.h"

namespace moss {

enum Directional { kBidirectional = 0, kUnidirectional = 1 };
enum ConnectionType { kClient = 0, kServer = 1 };
typedef ConnectionType Initializer;
typedef uint64_t streamID_t;

class Stream {
 public:
  Stream(streamID_t id, Initializer initer, Directional direct)
      : id_(id), initer_(initer), direct_(direct), sendSide_(0), recvSide_(0) {}
#ifdef __MOSS_TEST
 public:
#else
 private:
#endif
  streamID_t id_;
  Initializer initer_;
  Directional direct_;
  FSM sendSide_;
  FSM recvSide_;
};

}  // namespace moss

#endif  // STREAM_H_