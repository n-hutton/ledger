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

#include "muddle_rpc.hpp"

#include <chrono>
#include <iostream>
#include <thread>

using std::this_thread::sleep_for;
using std::chrono::milliseconds;

using fetch::network::NetworkManager;
using fetch::network::Peer;
using fetch::muddle::Muddle;
using fetch::muddle::rpc::Client;
using fetch::service::Promise;

int main()
{
  using PromiseList = std::vector<Promise>;

  // create and setup the muddle
  NetworkManager nm(1);
  nm.Start();

  Muddle muddle{CreateKey(CLIENT_PRIVATE_KEY), nm};
  muddle.Start({9000}, {fetch::network::Uri{"tcp://127.0.0.1:8000"}});

  sleep_for(milliseconds{2000});
  FETCH_LOG_INFO("RpcClientMain", "============================");

  auto const server_key = fetch::byte_array::FromBase64(SERVER_PUBLIC_KEY);

  auto client = std::make_shared<Client>(muddle.AsEndpoint(), server_key, 1, 1);

  using Clock = std::chrono::high_resolution_clock;

  PromiseList promises;
  promises.reserve(5000);

  auto const start = Clock::now();

  for (uint64_t i = 0; i < 5000; ++i)
  {
    promises.push_back(client->Call(1, 1, i, i));
  }

  for (auto &prom : promises)
  {
    prom->Wait();
    // FETCH_LOG_INFO("RpcClientMain", "The result is: ", prom->As<uint64_t>());
  }

  auto const end   = Clock::now();
  auto const delta = end - start;

  std::cout << "Time to run was: " << std::chrono::duration_cast<milliseconds>(delta).count()
            << std::endl;

  return 0;
}
