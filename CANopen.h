#ifndef CAN_OPEN_H
#define CAN_OPEN_H

#include <initializer_list>
#include <FlexCAN.h>

// Primary Teesy <-> Secondary Teensy: status, warning, and error codes
constexpr char k_statusHeartbeat = 0x01;

class CANopen : public FlexCAN {
 public:
  CANopen(uint32_t id, uint32_t baud);
  virtual ~CANopen();

  void setFilters(std::initializer_list<uint32_t> filters);
  bool sendMessage(const CAN_message_t& msg);
  bool recvMessage(CAN_message_t& msg);
};

#endif // CAN_OPEN_H
