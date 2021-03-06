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

#include "vm/analyser.hpp"
#include "vm/generator.hpp"
#include "vm/parser.hpp"

namespace fetch {
namespace vm {

class Compiler
{
public:
  Compiler(Module *module = nullptr)
    : analyser_(module)
  {}
  ~Compiler()
  {}
  bool Compile(const std::string &source, const std::string &name, Script &script,
               std::vector<std::string> &errors);

private:
  Parser    parser_;
  Analyser  analyser_;
  Generator generator_;
};

}  // namespace vm
}  // namespace fetch
