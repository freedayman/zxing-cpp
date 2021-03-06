#pragma once
/*
* Copyright 2016 Huy Cuong Nguyen
* Copyright 2006-2007 Jeremias Maerki.
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
namespace DataMatrix {

enum class SymbolShape;

/**
* DataMatrix ECC 200 data encoder following the algorithm described in ISO/IEC 16022:200(E) in
* annex S.
*/
class HighLevelEncoder
{
public:
	static void Encode(const std::wstring& msg, SymbolShape shape, int minWdith, int minHeight, int maxWidth, int maxHeight, std::vector<int>& output);
};

} // DataMatrix
} // ZXing
