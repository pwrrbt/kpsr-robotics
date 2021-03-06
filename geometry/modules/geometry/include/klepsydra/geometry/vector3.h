/****************************************************************************
*
*                           Klepsydra Core Modules
*              Copyright (C) 2019-2020  Klepsydra Technologies GmbH
*                            All Rights Reserved.
*
*  This file is subject to the terms and conditions defined in
*  file 'LICENSE.md', which is part of this source code package.
*
*  NOTICE:  All information contained herein is, and remains the property of Klepsydra
*  Technologies GmbH and its suppliers, if any. The intellectual and technical concepts
*  contained herein are proprietary to Klepsydra Technologies GmbH and its suppliers and
*  may be covered by Swiss and Foreign Patents, patents in process, and are protected by
*  trade secret or copyright law. Dissemination of this information or reproduction of
*  this material is strictly forbidden unless prior written permission is obtained from
*  Klepsydra Technologies GmbH.
*
*****************************************************************************/

#ifndef KPSR_GEOMETRY_VECTOR3_H_
#define KPSR_GEOMETRY_VECTOR3_H_

namespace kpsr {
namespace geometry {
// Klepsydra generated event class.
class Vector3 {
public:
   // Default constructor.
   Vector3() {}

   // Main constructor.
   Vector3(
      double x,
      double y,
      double z)
      : x(x)
      , y(y)
      , z(z)
   {}

   // Clone constructor. Needed by klepsydra core APIs.
   Vector3(const Vector3 * that)
      : x(that->x)
      , y(that->y)
      , z(that->z)
   {}

   // Clone method. Needed by klepsydra core APIs.
   void clone(const Vector3 * that) {
      this->x = that->x;
      this->y = that->y;
      this->z = that->z;
   }

   // List of fields.
   double x;
   double y;
   double z;
};
}
}
#endif
