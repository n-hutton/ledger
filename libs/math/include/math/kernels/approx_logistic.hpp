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

namespace fetch {
namespace kernels {

template <typename vector_register_type>
struct ApproxLogistic
{
  void operator()(vector_register_type const &x, vector_register_type &y) const
  {
    static const vector_register_type one(1);
    y = one + approx_exp(-x);
    y = one / y;
  }
};

}  // namespace kernels
}  // namespace fetch
