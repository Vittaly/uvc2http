/*******************************************************************************
#                                                                              #
# This file is part of uvc2http.                                               #
#                                                                              #
# Copyright (C) 2015 Oleg Efremov                                              #
#                                                                              #
# Uvc_streamer is free software; you can redistribute it and/or modify         #
# it under the terms of the GNU General Public License as published by         #
# the Free Software Foundation; version 2 of the License.                      #
#                                                                              #
# This program is distributed in the hope that it will be useful,              #
# but WITHOUT ANY WARRANTY; without even the implied warranty of               #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                #
# GNU General Public License for more details.                                 #
#                                                                              #
# You should have received a copy of the GNU General Public License            #
# along with this program; if not, write to the Free Software                  #
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA    #
#                                                                              #
*******************************************************************************/

#ifndef MJPEGUTILS_H
#define MJPEGUTILS_H

#include <memory>
#include <vector>

#include "UvcGrabber.h"
#include "Buffer.h"

struct VideoFrame;

struct MjpegFrame {
  const void* Header;
  uint32_t HeaderSize;
  
  const void* HaffmanTable;
  uint32_t HaffmanTableSize;

  const void* Data;
  uint32_t DataSize;
  
  const VideoFrame* SourceBuffer;
};

std::unique_ptr<MjpegFrame> CreateMjpegFrame(const VideoFrame* videoBuffer);

std::vector<Buffer> CreateMjpegFrameBufferSet(const VideoFrame* videoBuffer);


#endif // MJPEGUTILS_H