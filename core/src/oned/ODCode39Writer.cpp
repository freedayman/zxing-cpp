/*
* Copyright 2016 Huy Cuong Nguyen
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

#include <string.h>

#include "oned/ODCode39Writer.h"
#include "oned/ODWriterHelper.h"
#include "ZXContainerAlgorithms.h"

#include <array>

namespace ZXing {
namespace OneD {

static const char ALPHABET_STRING[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ-. *$/+%";

/**
* These represent the encodings of characters, as patterns of wide and narrow bars.
* The 9 least-significant bits of each int correspond to the pattern of wide and narrow,
* with 1s representing "wide" and 0s representing narrow.
*/
static const int CHARACTER_ENCODINGS[] = {
	0x034, 0x121, 0x061, 0x160, 0x031, 0x130, 0x070, 0x025, 0x124, 0x064, // 0-9
	0x109, 0x049, 0x148, 0x019, 0x118, 0x058, 0x00D, 0x10C, 0x04C, 0x01C, // A-J
	0x103, 0x043, 0x142, 0x013, 0x112, 0x052, 0x007, 0x106, 0x046, 0x016, // K-T
	0x181, 0x0C1, 0x1C0, 0x091, 0x190, 0x0D0, 0x085, 0x184, 0x0C4, 0x094, // U-*
	0x0A8, 0x0A2, 0x08A, 0x02A // $-%
};

static_assert(Length(ALPHABET_STRING) - 1 == Length(CHARACTER_ENCODINGS), "table size mismatch");

static const int ASTERISK_ENCODING = CHARACTER_ENCODINGS[39];

static int IndexOf(const char* str, int c)
{
	auto s = strchr(str, c);
	return s != nullptr ? static_cast<int>(s - str) : -1;
}

static void ToIntArray(int a, std::array<int, 9>& toReturn) {
	for (int i = 0; i < 9; ++i) {
		toReturn[i] = (a & (1 << (8 - i))) == 0 ? 1 : 2;
	}
}

void
Code39Writer::encode(const std::wstring& contents, int width, int height, BitMatrix& output) const
{
	size_t length = contents.length();
	if (length == 0) {
		throw std::invalid_argument("Found empty contents");
	}
	if (length > 80) {
		throw std::invalid_argument("Requested contents should be less than 80 digits long");
	}

	std::array<int, 9> widths = {};
	size_t codeWidth = 24 + 1 + length;
	for (size_t i = 0; i < length; ++i) {
		int indexInString = IndexOf(ALPHABET_STRING, contents[i]);
		if (indexInString < 0) {
			throw std::invalid_argument("Bad contents");
		}
		ToIntArray(CHARACTER_ENCODINGS[indexInString], widths);
		codeWidth = Accumulate(widths, codeWidth);
	}

	std::vector<bool> result(codeWidth, false);
	ToIntArray(ASTERISK_ENCODING, widths);
	int pos = WriterHelper::AppendPattern(result, 0, widths, true);
	std::array<int, 1> narrowWhite = { 1 };
	pos += WriterHelper::AppendPattern(result, pos, narrowWhite, false);
	//append next character to byte matrix
	for (size_t i = 0; i < length; ++i) {
		int indexInString = IndexOf(ALPHABET_STRING, contents[i]);
		ToIntArray(CHARACTER_ENCODINGS[indexInString], widths);
		pos += WriterHelper::AppendPattern(result, pos, widths, true);
		pos += WriterHelper::AppendPattern(result, pos, narrowWhite, false);
	}
	ToIntArray(ASTERISK_ENCODING, widths);
	WriterHelper::AppendPattern(result, pos, widths, true);
	WriterHelper::RenderResult(result, width, height, _sidesMargin >= 0 ? _sidesMargin : 10, output);
}


} // OneD
} // ZXing
