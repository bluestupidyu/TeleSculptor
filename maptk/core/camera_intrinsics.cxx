/*ckwg +5
 * Copyright 2013 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#include "camera_intrinsics.h"

namespace maptk
{


/// Constructor - from a calibration matrix
/// \note ignores values below the diagonal
template <typename T>
camera_intrinsics_<T>
::camera_intrinsics_(const matrix_<3,3,T>& K)
: focal_length_(K(0,0)),
  principal_point_(K(0,2), K(1,2)),
  aspect_ratio_(K(0,0)/K(1,1))
{
}


/// Convert to a 3x3 calibration matrix
template <typename T>
camera_intrinsics_<T>
::operator matrix_<3,3,T>() const
{
  matrix_<3,3,T> K;
  K(0,0) = focal_length_;
  K(0,1) = skew_;
  K(0,2) = principal_point_.x();
  K(1,1) = focal_length_ / aspect_ratio_;
  K(1,2) = principal_point_.y();
  K(2,2) = T(1);
  K(1,0) = K(2,0) = K(2,1) = T(0);
  return K;
}


/// output stream operator for a camera intrinsics
template <typename T>
std::ostream&  operator<<(std::ostream& s, const camera_intrinsics_<T>& k)
{
  // TODO: implement me
  return s;
}


/// input stream operator for a camera intrinsics
template <typename T>
std::istream&  operator>>(std::istream& s, camera_intrinsics_<T>& k)
{
  // TODO: implement me
  return s;
}


#define INSTANTIATE_CAMERA_INTRINSICS(T) \
template class camera_intrinsics_<T>; \
template std::ostream&  operator<<(std::ostream& s, const camera_intrinsics_<T>& k); \
template std::istream&  operator>>(std::istream& s, camera_intrinsics_<T>& k)

INSTANTIATE_CAMERA_INTRINSICS(double);
INSTANTIATE_CAMERA_INTRINSICS(float);

#undef INSTANTIATE_CAMERA_INTRINSICS
} // end namespace maptk
