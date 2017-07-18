/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file : spline_1d_seg.cc
 * @brief: polynomial smoothing spline segment
 **/

#include "modules/planning/math/smoothing_spline/spline_1d_seg.h"

#include <sstream>

namespace apollo {
namespace planning {

Spline1dSeg::Spline1dSeg(const std::size_t order) {
  spline_func_ = PolynomialXd(order);
  derivative_.derived_from(spline_func_);
  second_order_derivative_.derived_from(derivative_);
  third_order_derivative_.derived_from(second_order_derivative_);
}

Spline1dSeg::Spline1dSeg(const std::vector<double>& params) {
  spline_func_ = PolynomialXd(params);
  derivative_.derived_from(spline_func_);
  second_order_derivative_.derived_from(derivative_);
  third_order_derivative_.derived_from(second_order_derivative_);
}

void Spline1dSeg::set_params(const std::vector<double>& params) {
  spline_func_ = PolynomialXd(params);
  derivative_.derived_from(spline_func_);
  second_order_derivative_.derived_from(derivative_);
  third_order_derivative_.derived_from(second_order_derivative_);
}

double Spline1dSeg::operator()(const double x) const { return spline_func_(x); }

double Spline1dSeg::derivative(const double x) const { return derivative_(x); }

double Spline1dSeg::second_order_derivative(const double x) const {
  return second_order_derivative_(x);
}

double Spline1dSeg::third_order_derivative(const double x) const {
  return third_order_derivative_(x);
}

const PolynomialXd& Spline1dSeg::spline_func() const { return spline_func_; }

const PolynomialXd& Spline1dSeg::derivative() const { return derivative_; }

const PolynomialXd& Spline1dSeg::second_order_derivative() const {
  return second_order_derivative_;
}

const PolynomialXd& Spline1dSeg::third_order_derivative() const {
  return third_order_derivative_;
}

}  // namespace planning
}  // namespace apollo
