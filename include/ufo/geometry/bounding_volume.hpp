/*!
 * UFOMap: An Efficient Probabilistic 3D Mapping Framework That Embraces the Unknown
 *
 * @author Daniel Duberg (dduberg@kth.se)
 * @see https://github.com/UnknownFreeOccupied/ufomap
 * @version 1.0
 * @date 2022-05-13
 *
 * @copyright Copyright (c) 2022, Daniel Duberg, KTH Royal Institute of Technology
 *
 * BSD 3-Clause License
 *
 * Copyright (c) 2022, Daniel Duberg, KTH Royal Institute of Technology
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *     list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef UFO_GEOMETRY_BOUNDING_VOLUME_HPP
#define UFO_GEOMETRY_BOUNDING_VOLUME_HPP

// UFO
#include <ufo/geometry/aabb.hpp>
#include <ufo/geometry/aabc.hpp>
#include <ufo/geometry/capsule.hpp>
#include <ufo/geometry/cone.hpp>
#include <ufo/geometry/cylinder.hpp>
#include <ufo/geometry/ellipsoid.hpp>
#include <ufo/geometry/frustum.hpp>
#include <ufo/geometry/line.hpp>
#include <ufo/geometry/line_segment.hpp>
#include <ufo/geometry/obb.hpp>
#include <ufo/geometry/plane.hpp>
#include <ufo/geometry/point.hpp>
#include <ufo/geometry/ray.hpp>
#include <ufo/geometry/rectangle.hpp>
#include <ufo/geometry/sphere.hpp>
#include <ufo/geometry/triangle.hpp>

// STL
#include <variant>
#include <vector>

namespace ufo
{
using BoundingVolume = std::variant<AABB, AABC, Frustum, LineSegment, OBB, Plane, Point,
                                    Ray, Sphere, Triangle>;

using BoundingVolumes = std::vector<BoundingVolume>;
}  // namespace ufo

#endif  // UFO_GEOMETRY_BOUNDING_VOLUME_HPP