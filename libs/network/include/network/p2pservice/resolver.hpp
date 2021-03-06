#pragma once
//------------------------------------------------------------------------------
//
//   Copyright 2018 Fetch.AI Limited
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
//
//------------------------------------------------------------------------------

#include "network/muddle/packet.hpp"
#include "network/p2pservice/state_machine.hpp"

namespace fetch {
namespace p2p {

class IdentityCache;

class Resolver
{
public:
  using Address = muddle::Packet::Address;

  enum class State
  {
    RESOLVE_ADDRESS,
    LOOKUP_MANIFEST,
    COMPLETE
  };

  // Construction / Destruction
  Resolver(IdentityCache &cache);
  Resolver(Resolver const &) = delete;
  Resolver(Resolver &&)      = delete;
  ~Resolver()                = default;

  void Resolve(Address const &address);

  // Operators
  Resolver &operator=(Resolver const &) = delete;
  Resolver &operator=(Resolver &&) = delete;

private:
  IdentityCache &cache_;
};

}  // namespace p2p
}  // namespace fetch
