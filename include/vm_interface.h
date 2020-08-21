/*
* Copyright (c) 2020, The Linux Foundation. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted
* provided that the following conditions are met:
*    * Redistributions of source code must retain the above copyright notice, this list of
*      conditions and the following disclaimer.
*    * Redistributions in binary form must reproduce the above copyright notice, this list of
*      conditions and the following disclaimer in the documentation and/or other materials provided
*      with the distribution.
*    * Neither the name of The Linux Foundation nor the names of its contributors may be used to
*      endorse or promote products derived from this software without specific prior written
*      permission.
*
* THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
* OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef __VM_INTERFACE_H__
#define __VM_INTERFACE_H__

#define SDM_COMP_SERVICE_ID 5010
#define SDM_COMP_SERVICE_VERSION 1
#define SDM_COMP_SERVICE_INSTANCE 1

enum CommandId {
  kCmdExportDemuraBuffers = 0,
  kCmdMax,
};

typedef struct {
  int cfg_mem_hdl = -1;
  int hfc_mem_hdl = -1;
} DemuraMemHandle;

typedef struct {
  int32_t id = -1;
} CommandHeader;

typedef struct {
  int32_t id = -1;
  int32_t status = -1;
} ResponseHeader;

// Command and Response structure definitions to start TUI session
typedef struct {
  union {
    DemuraMemHandle demura_mem_handle;
    uint32_t reserve[128] = { 0 };
  };
} CmdExportDemuraBuffer;

typedef struct {
  union {
    uint32_t reserve[128] = { 0 };
  };
} RspExportDemuraBuffer;

struct Command : CommandHeader {
  Command() {}
  union {
    CmdExportDemuraBuffer cmd_export_demura_buf;
  };
};

struct Response : ResponseHeader {
  Response() {}
  union {
    RspExportDemuraBuffer rsp_export_demura_buf;
  };
};

#endif // __VM_INTERFACE_H__
