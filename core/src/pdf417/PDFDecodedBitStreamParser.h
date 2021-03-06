#pragma once
/*
* Copyright 2016 Nu-book Inc.
* Copyright 2016 ZXing authors
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

#include <vector>

namespace ZXing {

enum class DecodeStatus;
class DecoderResult;

namespace Pdf417 {

/**
* <p>This class contains the methods for decoding the PDF417 codewords.</p>
*
* @author SITA Lab (kevin.osullivan@sita.aero)
* @author Guenther Grau
*/
class DecodedBitStreamParser
{
public:
	static DecodeStatus Decode(const std::vector<int>& codewords, int ecLevel, DecoderResult& result);
};

} // Pdf417
} // ZXing
