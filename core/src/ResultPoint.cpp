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

#include "ResultPoint.h"
#include <cmath>
#include <utility>

namespace ZXing {

  /**
  * @param pattern1 first pattern
  * @param pattern2 second pattern
  * @return distance between two points
  */
float 
ResultPoint::Distance(const ResultPoint& a, const ResultPoint& b)
{
	auto dx = a.x() - b.x();
	auto dy = a.y() - b.y();
	return std::sqrt(dx*dx + dy*dy);
}

float ResultPoint::Distance(float aX, float aY, float bX, float bY)
{
	float dx = aX - bX;
	float dy = aY - bY;
	return std::sqrt(dx * dx + dy * dy);
}

float ResultPoint::Distance(int aX, int aY, int bX, int bY)
{
	float dx = static_cast<float>(aX - bX);
	float dy = static_cast<float>(aY - bY);
	return std::sqrt(dx * dx + dy * dy);
}

} // ZXing
