/*
 * Copyright (c) 2024-2025, NVIDIA CORPORATION.  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * SPDX-FileCopyrightText: Copyright (c) 2024-2025, NVIDIA CORPORATION.
 * SPDX-License-Identifier: Apache-2.0
 */
#include "xrmg.hpp"

#include "App.hpp"

#ifndef SAMPLE_VERSION
#define SAMPLE_VERSION "unknown"
#endif

int main(int p_argc, char **p_argv) {
#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
#endif
  std::string buildInfo = "custom build, based on unknown commit";
#ifdef SAMPLE_COMMIT_HASH
  if (SAMPLE_HAS_UNCOMMITTED_CHANGES) {
    buildInfo = "custom build, based on commit " SAMPLE_COMMIT_HASH;
  } else {
    buildInfo = "commit " SAMPLE_COMMIT_HASH;
  }
#endif
  XRMG_INFO("Sample     │ NVIDIA DesignWorks: " SAMPLE_NAME);
  XRMG_INFO("Version    │ " SAMPLE_VERSION);
  XRMG_INFO("Build info │ {}", buildInfo);
  XRMG_INFO("");
  return xrmg::App({p_argv, p_argv + p_argc}).run();
}