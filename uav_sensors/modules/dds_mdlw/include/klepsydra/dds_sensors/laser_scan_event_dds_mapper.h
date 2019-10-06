/****************************************************************************
*
*                           Klepsydra Core Modules
*              Copyright (C) 2019-2020  Klepsydra Technologies GmbH
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*****************************************************************************/

#ifndef LASER_SCAN_EVENT_DDS_MAPPER_H
#define LASER_SCAN_EVENT_DDS_MAPPER_H

#include <klepsydra/core/environment.h>
#include <klepsydra/serialization/mapper.h>

#include <klepsydra/sensors/laser_scan_event.h>
#include <laser_scan_event.hpp>

namespace kpsr {
template<>
/**
 * @brief The Mapper<kpsr::sensors::LaserScanEvent, kpsr_dds_sensors::LaserScanEvent> class
 *
 * @copyright Klepsydra Technologies 2019-2020.
 *
 * @version 2.1.0
 *
 * @ingroup kpsr-sensors-application
 *
 */
class Mapper<kpsr::sensors::LaserScanEvent, kpsr_dds_sensors::LaserScanEvent>
{
public:

   void fromMiddleware(const kpsr_dds_sensors::LaserScanEvent & message, kpsr::sensors::LaserScanEvent& event) {
       event.frameId = message.frameId();
       event.seq = message.seq();
       event.timestamp = message.timestamp();

       event.angle_min = message.angle_min();
       event.angle_max = message.angle_max();
       event.angle_increment = message.angle_increment();
       event.time_increment = message.time_increment();
       event.scan_time = message.scan_time();
       event.range_min = message.range_min();
       event.range_max = message.range_max();
       event.ranges.resize(message.ranges().size());

       std::transform(message.ranges().begin(), message.ranges().end(), event.ranges.begin(),
                      [](const double eventItem) {
           return eventItem;
       });

       event.intensities.resize(message.intensities().size());
       std::transform(message.intensities().begin(), message.intensities().end(), event.intensities.begin(),
                      [](const double eventItem) {
           return eventItem;
       });
    }

   void toMiddleware(const kpsr::sensors::LaserScanEvent & event, kpsr_dds_sensors::LaserScanEvent& message) {
       message.seq(event.seq);
       message.timestamp(event.timestamp);
       message.frameId(event.frameId);

       message.angle_min(event.angle_min);
       message.angle_max(event.angle_max);
       message.angle_increment(event.angle_increment);
       message.time_increment(event.time_increment);
       message.scan_time(event.scan_time);
       message.range_min(event.range_min);
       message.range_max(event.range_max);
       message.ranges(event.ranges);

       message.ranges().resize(event.ranges.size());
       std::transform(event.ranges.begin(), event.ranges.end(), message.ranges().begin(),
                      [&](double eventData) {
           return eventData;
       });

       message.intensities().resize(event.intensities.size());
       std::transform(event.intensities.begin(), event.intensities.end(), message.intensities().begin(),
                      [&](double eventData) {
           return eventData;
       });
   }
};
}
#endif // LASER_SCAN_EVENT_DDS_MAPPER_H
