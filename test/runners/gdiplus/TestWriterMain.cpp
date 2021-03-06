/*
* Copyright 2016 Nu-book Inc.
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

#include <iostream>
#include "qrcode/QRWriter.h"
#include "qrcode/QRErrorCorrectionLevel.h"
#include "BitMatrix.h"
#include "CharacterSet.h"

#include <sstream>

using namespace ZXing;

//static std::wstring LoadSample()

int main(int argc, char** argv)
{
	auto text = L"http://www.google.com/";
	QRCode::Writer writer;
	writer.setErrorCorrectionLevel(QRCode::ErrorCorrectionLevel::Medium);
	BitMatrix result;
	writer.encode(text, 99, 99, result);
	std::ostringstream buffer;
	result.writePBM(buffer);
}
