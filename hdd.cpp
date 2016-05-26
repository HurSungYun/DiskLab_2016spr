//------------------------------------------------------------------------------
/// @brief rotating disk-based storage devices (HDD)
/// @author Bernhard Egger <bernhard@csap.snu.ac.kr>
/// @section changelog Change Log
/// 2016/05/22 Bernhard Egger created
///
/// @section license_section License
/// Copyright (c) 2016, Bernhard Egger
/// All rights reserved.
///
/// Redistribution and use in source and binary forms,  with or without modifi-
/// cation, are permitted provided that the following conditions are met:
///
/// - Redistributions of source code must retain the above copyright notice,
///   this list of conditions and the following disclaimer.
/// - Redistributions in binary form must reproduce the above copyright notice,
///   this list of conditions and the following disclaimer in the documentation
///   and/or other materials provided with the distribution.
///
/// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
/// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,  BUT NOT LIMITED TO,  THE
/// IMPLIED WARRANTIES OF MERCHANTABILITY  AND FITNESS FOR A PARTICULAR PURPOSE
/// ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER  OR CONTRIBUTORS BE
/// LIABLE FOR ANY DIRECT,  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSE-
/// QUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  SUBSTITUTE
/// GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
/// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  CONTRACT, STRICT
/// LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY WAY
/// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
/// DAMAGE.
//------------------------------------------------------------------------------

#include <cassert>
#include <limits>
#include <cmath>
#include <cstdlib>

#include <iostream>
#include <iomanip>

#include "hdd.h"
using namespace std;

//------------------------------------------------------------------------------
// HDD
//
HDD::HDD(uint32 surfaces, uint32 tracks_per_surface,
         uint32 sectors_innermost_track, uint32 sectors_outermost_track,
         uint32 rpm, uint32 sector_size,
         double seek_overhead, double seek_per_track,
         bool verbose)
  : _surfaces(surfaces), _rpm(rpm), _sector_size(sector_size),
    _seek_overhead(seek_overhead), _seek_per_track(seek_per_track),
    _verbose(verbose), _sectors_innermost_track(sectors_innermost_track), _sectors_outermost_track(sectors_outermost_track),
    _tracks_per_surface(tracks_per_surface)

{
  // TODO

  uint64 sectors_total = 0;
  for(uint32 i = 0; i < tracks_per_surface; i++){
    sectors_total += sectors_in_track(i);
  }
  sectors_total *= surfaces;

  double capacity = sectors_total * sector_size / 1000000000.0;

  _head_pos = 0;

  //
  // print info
  //
  cout.precision(3);
  cout << "HDD: " << endl
       << "  surfaces:                  " << _surfaces << endl
       << "  tracks/surface:            " << tracks_per_surface << endl
       << "  sect on innermost track:   " << sectors_innermost_track << endl
       << "  sect on outermost track:   " << sectors_outermost_track << endl
       << "  rpm:                       " << rpm << endl
       << "  sector size:               " << _sector_size << endl
       << "  number of sectors total:   " << sectors_total << endl
       << "  capacity (GB):             " << setprecision(3) << fixed << capacity << endl
       << endl;
}

HDD::~HDD(void)
{
  // TODO
}

double HDD::read(double ts, uint64 address, uint64 size)
{
  // TODO
  return ts;
}

double HDD::write(double ts, uint64 address, uint64 size)
{
  // TODO
  return ts;
}

double HDD::seek_time(uint32 from_track, uint32 to_track)
{
  // TODO

  if(from_track - to_track < 0)
    return ( _seek_per_track * (from_track - to_track) ) + _seek_overhead;

  return ( _seek_per_track * (to_track - from_track) ) + _seek_overhead;
}

double HDD::wait_time(void)
{
  // TODO
  return 30.0 / _rpm;
}

double HDD::read_time(uint64 sectors)
{
  // TODO
  return 60.0 / _rpm * sectors / sectors_in_track(_head_pos);
}

double HDD::write_time(uint64 sectors)
{
  // TODO
  return 0.0;
}

bool HDD::decode(uint64 address, HDD_Position *pos)
{
  // TODO
  return false;
}

int HDD::sectors_in_track(uint32 sector_index)
{
  return _sectors_innermost_track + (_sectors_outermost_track - _sectors_innermost_track) * sector_index / ( _tracks_per_surface - 1);
}
