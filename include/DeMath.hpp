/**
* @file DeMath.hpp
* @author Hudson Schumaker
* @brief Defines and implements the DeMath class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
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
*/
#pragma once
#include "Pch.hpp"

/**
* @class DeMath
* @brief A utility class for mathematical operations.
* This class provides static methods for various mathematical operations such as square root calculation and angle conversion.
*/
class DeMath final {
public:
    /**
    * @brief Calculates the distance between two points.
    * @param x1 The x-coordinate of the first point.
    * @param y1 The y-coordinate of the first point.
    * @param x2 The x-coordinate of the second point.
    * @param y2 The y-coordinate of the second point.
    * @return The distance between the two points.
    */
    inline static float distanceBetweenPoints(float x1, float y1, float x2, float y2) {
        // using the euclidean distance formula
        return std::sqrtf((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }

    /**
    * @brief Normalize thr angle.
    * @param angle The angle.
    * @return The normalized angle.
    */
    inline static float normalizeAngle(float angle) {
        angle = std::remainder(angle, Defs::TWO_PI);
        if (angle < 0) {
            angle = Defs::TWO_PI + angle;
        }
        return angle;
    }

    /**
    * @brief Converts an angle from degrees to radians.
    * @param angle The angle in degrees.
    * @return The angle in radians.
    */
    inline static float deg2Rad(float angle) {
        return angle * Defs::DIV_PI_180;
    }

    /**
    * @brief Converts an angle from radians to degrees.
    * @param angle The angle in radians.
    * @return The angle in degrees.
    */
    inline static float rad2Deg(float angle) {
        return angle * Defs::DIV_180_PI;
    }
};
