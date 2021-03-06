#pragma once
/*
* Copyright 2016 Huy Cuong Nguyen
* Copyright 2016 ZXing authors
* Copyright 2006 Jeremias Maerki
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#include <string>
#include <vector>

namespace ZXing {

enum class CharacterSet;

namespace Pdf417 {

enum class Compaction;

/**
* PDF417 high-level encoder following the algorithm described in ISO/IEC 15438:2001(E) in
* annex P.
*/
class HighLevelEncoder
{
public:
	static void EncodeHighLevel(const std::wstring& msg, Compaction compaction, CharacterSet encoding, std::vector<int>& highLevel);
};

} // Pdf417
} // ZXing
