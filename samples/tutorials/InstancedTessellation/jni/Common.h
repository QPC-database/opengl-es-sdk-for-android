/* Copyright (c) 2014-2017, ARM Limited and Contributors
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge,
 * to any person obtaining a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef COMMON_H
#define COMMON_H

#include <android/log.h>
#include <cstdio>
#include <cstdlib>
#include <GLES3/gl3.h>

#include <cmath>

    #ifndef M_PI
        /** \brief The value of pi approximation. */
        #define M_PI 3.14159265358979323846f
    #endif /* M_PI */

    #define LOG_TAG "libNative"
    #define LOGD(...) __android_log_print(ANDROID_LOG_DEBBUG, LOG_TAG, __VA_ARGS__)
    #define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,  LOG_TAG, __VA_ARGS__)
    #define LOGI(...) __android_log_print(ANDROID_LOG_INFO,   LOG_TAG, __VA_ARGS__)
    #define ASSERT(x, s)                                                    \
        if (!(x))                                                           \
        {                                                                   \
            LOGE("Assertion failed at %s:%i\n%s\n", __FILE__, __LINE__, s); \
            exit(1);                                                        \
        }

    #define GL_CHECK(x)                                                                              \
        x;                                                                                           \
        {                                                                                            \
            GLenum glError = glGetError();                                                           \
            if(glError != GL_NO_ERROR) {                                                             \
                LOGE("glGetError() = %i (0x%.8x) at %s:%i\n", glError, glError, __FILE__, __LINE__); \
                exit(1);                                                                             \
            }                                                                                        \
        }

    /**
     * \brief Convert an angle in degrees to radians.
     *
     * \param degrees The angle (in degrees) to convert to radians.
     *
     * \return As per description.
     */
    inline float degreesToRadians(float degrees)
    {
        return M_PI * degrees / 180.0f;
    }

    /**
     * \brief Get the sign of a number.
     * \param[in] f Value to check the sign of.
     * \return -1.0 if the number's sign is minus, 1.0 if the number's sign is plus and 0.0 if the number's sign is indefinite.
     */
    inline float signum(float f)
    {
        if (f > 0.0f)
        {
            return  1.0f;
        }

        if (f < 0.0f)
        {
            return -1.0f;
        }

        return 0.0f;
    }

#endif /* COMMON_H */