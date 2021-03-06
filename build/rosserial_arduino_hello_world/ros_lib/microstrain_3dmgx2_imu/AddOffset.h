#ifndef _ROS_SERVICE_AddOffset_h
#define _ROS_SERVICE_AddOffset_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace microstrain_3dmgx2_imu
{

static const char ADDOFFSET[] = "microstrain_3dmgx2_imu/AddOffset";

  class AddOffsetRequest : public ros::Msg
  {
    public:
      float add_offset;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->add_offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->add_offset));
     return offset;
    }

    const char * getType(){ return ADDOFFSET; };
    const char * getMD5(){ return "10fe27c5d4591264b9d05acc7497a18a"; };

  };

  class AddOffsetResponse : public ros::Msg
  {
    public:
      float total_offset;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->total_offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->total_offset));
     return offset;
    }

    const char * getType(){ return ADDOFFSET; };
    const char * getMD5(){ return "5dea42ce4656fada4736ce3508b56aca"; };

  };

  class AddOffset {
    public:
    typedef AddOffsetRequest Request;
    typedef AddOffsetResponse Response;
  };

}
#endif
